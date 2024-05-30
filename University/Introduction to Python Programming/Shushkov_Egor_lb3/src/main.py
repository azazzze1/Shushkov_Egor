class HouseScheme:
    def __init__(self, rooms, area, bathroom):
        if area < 0 or not isinstance(bathroom, bool):
            raise ValueError("Invalid value")
        self.rooms = rooms
        self.area = area
        self.bathroom = bathroom


class CountryHouse(HouseScheme):
    def __init__(self, rooms, area, bathroom, floors, garden_area):
        super().__init__(rooms, area, bathroom)
        self.floors = floors
        self.garden_area = garden_area

    def __str__(self):
        return 'Country House: Количество жилых комнат {}, Жилая площадь {}, Совмещенный санузел {}, Количество этажей {}, Площадь участка {}.'.format(
            self.rooms, self.area, self.bathroom, self.floors, self.garden_area)

    def __eq__(self, other):
        if (self.area == other.area and self.garden_area == other.garden_area and abs(self.floors - other.floors) <= 1):
            return True


class Apartment(HouseScheme):
    def __init__(self, rooms, area, bathroom, floor, window):
        super().__init__(rooms, area, bathroom)
        if not floor in range(1, 16) or not window in "NSWE":
            raise ValueError("Invalid value")
        self.floor = floor
        self.window = window

    def __str__(self):
        return 'Apartment: Количество жилых комнат {}, Жилая площадь {}, Совмещенный санузел {}, Этаж {}, Окна выходят на {}.'.format(
            self.rooms, self.area, self.bathroom, self.floor, self.window)


class CountryHouseList(list):
    def __init__(self, name):
        self.name = name

    def append(self, p_object):
        if (isinstance(p_object, CountryHouse)):
            super().append(p_object)
        else:
            raise TypeError("Invalid type {}".format(type(p_object)))

    def total_square(self):
        return sum(p_object.area for p_object in self)


class ApartmentList(list):
    def __init__(self, name):
        self.name = name

    def extend(self, iterable):
        super().extend(list(filter(lambda i: isinstance(i, Apartment), iterable)))

    def floor_view(self, floors, directions):
        aparts = list(
            filter(lambda apart: apart.floor in range(floors[0], floors[1] + 1) and apart.window in directions, self))
        for i in aparts:
            print("{}: {}".format(i.window, i.floor))
