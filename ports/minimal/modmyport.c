#include "py/runtime.h"
#include <stdio.h>
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "STdriver.h"
#include <stdarg.h>
#include <stddef.h>

//#######################################################################################
STATIC mp_obj_t myport_info(void) 
{

    mp_printf(&mp_plat_print, "info about my import=100\n");
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
    char buffer [150]= {'\0'}; 
    sprintf(buffer,"this is just for test\n\r");    /*this is working*/    
    //sprintf(buffer,"this is just for test=%d\n\r",a); /*this is not working*/
    mp_printf(&mp_plat_print, buffer);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(board_clockinfo_obj, board_clockinfo);

STATIC mp_obj_t board_healthinfo(void) 
{
   return MP_OBJ_NEW_SMALL_INT(100);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(board_healthinfo_obj, board_healthinfo);


STATIC mp_obj_t board_add(mp_obj_t a, mp_obj_t b) 
{
   mp_printf(&mp_plat_print, "Addition of %d and %d is %d\n\r",
   MP_OBJ_SMALL_INT_VALUE(a), MP_OBJ_SMALL_INT_VALUE(b), 
   MP_OBJ_SMALL_INT_VALUE(a)+ MP_OBJ_SMALL_INT_VALUE(b)); 

   return MP_OBJ_NEW_SMALL_INT(MP_OBJ_SMALL_INT_VALUE(a)+ MP_OBJ_SMALL_INT_VALUE(b));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(board_add_obj, board_add);


STATIC const mp_rom_map_elem_t board_module_globals_table[] = 
{
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_board) },
    { MP_ROM_QSTR(MP_QSTR_clockinfo), MP_ROM_PTR(&board_clockinfo_obj) },
    { MP_ROM_QSTR(MP_QSTR_healthinfo), MP_ROM_PTR(&board_healthinfo_obj) },
    { MP_ROM_QSTR(MP_QSTR_add), MP_ROM_PTR(&board_add_obj) },

};
STATIC MP_DEFINE_CONST_DICT(board_module_globals, board_module_globals_table);

const mp_obj_module_t board_module = 
{
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&board_module_globals,
};
MP_REGISTER_MODULE(MP_QSTR_board, board_module);