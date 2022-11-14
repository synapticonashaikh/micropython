#include "py/runtime.h"
#include <stdio.h>
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include <stdarg.h>
#include <stddef.h>
#include "mpconfigboard_common.h"

//#######################################################################################
STATIC mp_obj_t myport_info(void) 
{

   // mp_printf(&mp_plat_print,"HEAP START = %p \t HEAP END =%p \n\r",MICROPY_HEAP_START,MICROPY_HEAP_END);

    mp_printf(&mp_plat_print,"HEAP START =");
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
