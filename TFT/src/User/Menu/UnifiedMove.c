#include "UnifiedMove.h"
#include "includes.h"

//1 title, ITEM_PER_PAGE items(icon + label)
const MENUITEMS UnifiedMoveItems = {
// title
LABEL_UNIFIEDMOVE,
// icon                       label
 {{ICON_HOME,                 LABEL_HOME},
  {ICON_MOVE,                 LABEL_MOVE},
  {ICON_LEVELING,             LABEL_ABL},
  {ICON_MANUAL_LEVEL,         LABEL_LEVELING},
  {ICON_X_HOME,               LABEL_X_HOME},
  {ICON_Y_HOME,               LABEL_Y_HOME},
  {ICON_Z_HOME,               LABEL_Z_HOME},
  {ICON_BACK,                 LABEL_BACK},}
};

void menuUnifiedMove(void)
{
  KEY_VALUES key_num = KEY_IDLE;	
  menuDrawPage(&UnifiedMoveItems,false);
  while(infoMenu.menu[infoMenu.cur] == menuUnifiedMove)
  {
    key_num = menuKeyGetValue();
    switch(key_num)
    {
      case KEY_ICON_0: storeCmd("G28\n");   break;
      case KEY_ICON_1: infoMenu.menu[++infoMenu.cur] = menuMove; break;
      case KEY_ICON_2: infoMenu.menu[++infoMenu.cur] = menuAutoLeveling; break;
      case KEY_ICON_3: infoMenu.menu[++infoMenu.cur] = menuManualLeveling; break;
      case KEY_ICON_4: storeCmd("G28 X\n"); break;
      case KEY_ICON_5: storeCmd("G28 Y\n"); break;
      case KEY_ICON_6: storeCmd("G28 Z\n"); break;
      case KEY_ICON_7: infoMenu.cur--; break;
      default: break;            
    }
    loopProcess();
  }
}

