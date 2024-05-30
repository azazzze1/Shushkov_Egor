
#ifndef FIELD_VIEW_H
#define FIELD_VIEW_H
    
    #include "../Field/Field.h"

    class Field;

    class FieldView{
    public:
        FieldView(){}
        void DrawField(Field& field);
    };

#endif