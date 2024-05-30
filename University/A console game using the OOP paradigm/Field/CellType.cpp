#include "CellType.h"

bool CellTypeStone::SetPassable(){return false;}
bool CellTypeLand::SetPassable() {return true;}
bool CellTypeKey::SetPassable() {return true;}
bool CellTypeChest::SetPassable() {return true;}
bool CellTypeExit::SetPassable() {return true;}

char CellTypeStone::SetIcon() {return '#';}
char CellTypeLand::SetIcon() {return '.';}
char CellTypeKey::SetIcon() {return 'F';}
char CellTypeChest::SetIcon() {return '$';}
char CellTypeExit::SetIcon() {return 'E';}