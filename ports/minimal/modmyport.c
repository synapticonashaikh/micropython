#include "py/runtime.h"
#include <stdio.h>
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "STdriver.h"


extern uint8_t uiVAlue;

STATIC mp_obj_t myport_info(void) 
{

    mp_printf(&mp_plat_print, "info about my port0=%d\n",uiVAlue);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(myport_info_obj, myport_info);


STATIC const mp_rom_map_elem_t myport_module_globals_table[] = 
{
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_myport) },
    { MP_ROM_QSTR(MP_QSTR_info), MP_ROM_PTR(&myport_info_obj) },
};
STATIC MP_DEFINE_CONST_DICT(myport_module_globals, myport_module_globals_table);

const mp_obj_module_t myport_module = 
{
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&myport_module_globals,
};
MP_REGISTER_MODULE(MP_QSTR_myport, myport_module);

//#######################################################################################

STATIC mp_obj_t board_clockinfo(void) 
{
    //char str[40];
    char buffer [150]= {'\0'}; 

    RCCClocksTypeDef RCC_Clocks		;
	RCCGetClocksFreq(&RCC_Clocks)	;
	// sprintf(str,"ALL CLOCK SET TO =\n\r"); strcat(buffer, str);
	// sprintf(str,"SYSCLK=%lu "  ,	 RCC_Clocks.SYSCLK_Frequency); strcat(buffer, str);
	// sprintf(str,"HCLK=%lu\n\r" ,	 RCC_Clocks.HCLK_Frequency  ); strcat(buffer, str);
	// sprintf(str,"PCLK1=%lu\t"  ,	 RCC_Clocks.PCLK1_Frequency ); strcat(buffer, str);
	// sprintf(str,"PCLK2=%lu\n\r",	 RCC_Clocks.PCLK2_Frequency ); strcat(buffer, str);
	// sprintf(str,"PLL CLOCK SOURCE=%lu\n\r",(_RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC) >> 22); strcat(buffer, str);
	// sprintf(str,"MAIN CLOCK SOUCE=%d\n\r", RCCGetSYSCLKSource());  strcat(buffer, str);		

    mp_printf(&mp_plat_print, buffer);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(board_clockinfo_obj, board_clockinfo);


STATIC const mp_rom_map_elem_t board_module_globals_table[] = 
{
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_board) },
    { MP_ROM_QSTR(MP_QSTR_clockinfo), MP_ROM_PTR(&board_clockinfo_obj) },
};
STATIC MP_DEFINE_CONST_DICT(board_module_globals, board_module_globals_table);

const mp_obj_module_t board_module = 
{
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&board_module_globals,
};
MP_REGISTER_MODULE(MP_QSTR_board, board_module);