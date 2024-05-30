#ifndef CELLTYPE_H
#define CELLTYPE_H

class CellType{
public:
    CellType(){}
    virtual bool SetPassable() = 0;
    virtual char SetIcon() = 0;
    virtual ~CellType() = default;
};

class CellTypeStone : public CellType{
public:
    CellTypeStone(){}
    bool SetPassable() override;
    char SetIcon() override;
};

class  CellTypeLand : public  CellType{
public:
    CellTypeLand(){}
    bool SetPassable() override;
    char SetIcon() override;
};

class CellTypeKey : public CellType{
public:
    CellTypeKey(){}
    bool SetPassable() override;
    char SetIcon() override;
};

class CellTypeChest : public CellType{
public:
    CellTypeChest(){}
    bool SetPassable() override;
    char SetIcon() override;
};

class CellTypeExit : public CellType{
public:
    CellTypeExit(){}
    bool SetPassable() override;
    char SetIcon() override;
};




#endif
