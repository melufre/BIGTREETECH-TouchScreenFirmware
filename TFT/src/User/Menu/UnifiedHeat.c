#include "UnifiedHeat.h"
#include "includes.h"

//1 title, ITEM_PER_PAGE items(icon + label)
const MENUITEMS UnifiedHeatItems = {
// title
lABEL_UNIFIEDHEAT,
// icon                       label
 {{ICON_HEAT,                 LABEL_PREHEAT},
  {ICON_HEAT,                 LABEL_HEAT},
  {ICON_FAN,                  LABEL_FAN},
  {ICON_COOLDOWN,             LABEL_COOLDOWN},
  {ICON_PREHEAT_PLA,          LABEL_PREHEAT_PLA},
  {ICON_PREHEAT_PETG,         LABEL_PREHEAT_PETG},
  {ICON_PREHEAT_ABS,          LABEL_PREHEAT_ABS},
  {ICON_BACK,                 LABEL_BACK},}
};

const u16   preheat_bed_temp2[] = PREHEAT_BED;
const u16   preheat_hotend_temp2[] = PREHEAT_HOTEND;

void menuUnifiedHeat(void)
{
  KEY_VALUES key_num = KEY_IDLE;	
  menuDrawPage(&UnifiedHeatItems,false);
  while(infoMenu.menu[infoMenu.cur] == menuUnifiedHeat)
  {
    key_num = menuKeyGetValue();
    switch(key_num)
    {
      case KEY_ICON_0: infoMenu.menu[++infoMenu.cur] = menuPreheat;   break;
      case KEY_ICON_1: infoMenu.menu[++infoMenu.cur] = menuHeat;    break;
      case KEY_ICON_2: infoMenu.menu[++infoMenu.cur] = menuFan;    break;
      case KEY_ICON_3:
        for(TOOL i = BED; i < HEATER_NUM; i++)
        {
          heatSetTargetTemp(i, 0);
        }
        break;
      case KEY_ICON_4: 
            heatSetTargetTemp(BED, preheat_bed_temp2[0]);
            heatSetTargetTemp(heatGetCurrentToolNozzle(), preheat_hotend_temp2[0]);
            break;
      case KEY_ICON_5: 
            heatSetTargetTemp(BED, preheat_bed_temp2[1]);
            heatSetTargetTemp(heatGetCurrentToolNozzle(), preheat_hotend_temp2[1]);
            break;
      case KEY_ICON_6: 
            heatSetTargetTemp(BED, preheat_bed_temp2[2]);
            heatSetTargetTemp(heatGetCurrentToolNozzle(), preheat_hotend_temp2[2]);
            break;
      case KEY_ICON_7: infoMenu.cur--;      break;
      default:break;            
    }
    loopProcess();
  }
}

