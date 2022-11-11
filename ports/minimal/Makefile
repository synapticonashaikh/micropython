#include the python envirmental variables
include ../../py/mkenv.mk

#to build for either STM board or Linux env
CROSS = 0

#enable disable float functionality
ENABLE_DISABLE_FLOAT = 1

# qstr definitions (must come before including py.mk)
QSTR_DEFS = qstrdefsport.h

# MicroPython feature configurations
MICROPY_ROM_TEXT_COMPRESSION ?= 1

# include py core make definitions
include $(TOP)/py/py.mk


ifeq ($(CROSS), 1)
CROSS_COMPILE ?= arm-none-eabi-
endif

INC += -I.
INC += -I$(TOP)
INC += -I$(BUILD)

#if the CROSS = 1 build add the compilation and linking flag
ifeq ($(CROSS), 1)
DFU = $(TOP)/tools/dfu.py
PYDFU = $(TOP)/tools/pydfu.py
#check and add the float related functionality
ifeq ($(ENABLE_DISABLE_FLOAT), 1)
#add the ARM core flags
$(warning Compliation Flag, float is enabled)
CFLAGS_CORTEX_M4 = -mthumb -mtune=cortex-m4 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=soft -fsingle-precision-constant -Wdouble-promotion -Wfloat-conversion
CFLAGS += -DMICROPY_FLOAT_IMPL=MICROPY_FLOAT_IMPL_FLOAT
CFLAGS += $(INC) -Wall -Werror -std=c99 -nostdlib -Wpointer-arith  $(CFLAGS_CORTEX_M4) $(COPT)
else
$(warning Compliation Flag, float is disabled)
CFLAGS_CORTEX_M4 = -mthumb -mtune=cortex-m4 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=soft -fsingle-precision-constant -Wdouble-promotion -Wfloat-conversion
CFLAGS += $(INC) -Wall -Werror -std=c99 -nostdlib -Wpointer-arith  $(CFLAGS_CORTEX_M4) $(COPT)
endif
LDFLAGS += -nostdlib -T stm32f405.ld -Map=$@.map --cref --gc-sections
else
#compiler for linux enviroment 
LD = gcc
CFLAGS += $(INC) -Wall -Werror -Wdouble-promotion -Wfloat-conversion -std=c99 $(COPT)
LDFLAGS += -Wl,-Map=$@.map,--cref -Wl,--gc-sections
endif

CSUPEROPT = -Os # save some code space

# Tune for Debugging or Optimization
CFLAGS += -g  # always include debug info in the ELF
ifeq ($(DEBUG), 1)
CFLAGS += -O0
else
CFLAGS += -Os -DNDEBUG
CFLAGS += -fdata-sections -ffunction-sections
endif

# Flags for optional C++ source code
CXXFLAGS += $(filter-out -std=c99,$(CFLAGS))

$(info FinalCFLAGS is $(CFLAGS)) 

ifeq ($(ENABLE_DISABLE_FLOAT), 1)
LIBS += "$(shell $(CC) $(CFLAGS) -print-libgcc-file-name)"
#adding the python library
SRC_LIB += $(addprefix lib/,\
        libm/math.c \
        libm/fmodf.c \
        libm/nearbyintf.c \
        libm/ef_sqrt.c \
        libm/kf_rem_pio2.c \
        libm/kf_sin.c \
        libm/kf_cos.c \
        libm/kf_tan.c \
        libm/ef_rem_pio2.c \
        libm/sf_sin.c \
        libm/sf_cos.c \
        libm/sf_tan.c \
        libm/sf_frexp.c \
        libm/sf_modf.c \
        libm/sf_ldexp.c \
        libm/asinfacosf.c \
        libm/acoshf.c \
        libm/asinhf.c \
        libm/atanf.c \
        libm/atan2f.c \
        libm/atanhf.c \
        libm/log1pf.c \
        libm/sf_erf.c \
        libm/erf_lgamma.c \
        libm/wf_lgamma.c \
        libm/wf_tgamma.c \
        libm/roundf.c \
	)
LIBM_O = $(addprefix $(BUILD)/, $(SRC_LIB:.c=.o))
else
LIBS = 
endif

$(info LIBS is $(LIBS)) 


SRC_C = \
	main.c \
	uart_core.c \
	STdriver.c \
	modmyport.c \
	shared/libc/printf.c \
	shared/readline/readline.c \
	shared/runtime/pyexec.c \
	shared/runtime/stdout_helpers.c \
	$(BUILD)/_frozen_mpy.c \

ifeq ($(CROSS), 1)
SRC_C += shared/libc/string0.c
endif

SRC_QSTR += shared/readline/readline.c shared/runtime/pyexec.c
SRC_QSTR += modmyport.c


OBJ += $(PY_CORE_O)
ifeq ($(ENABLE_DISABLE_FLOAT), 1)
OBJ += $(LIBM_O)
endif
OBJ += $(addprefix $(BUILD)/, $(SRC_C:.c=.o))
OBJ += $(addprefix $(BUILD)/, $(SRC_CXX:.cpp=.o))


ifeq ($(CROSS), 1)
all: $(BUILD)/firmware.dfu
else
all: $(BUILD)/firmware.elf
endif

$(BUILD)/_frozen_mpy.c: $(TOP)/tests/frozen/frozentest.mpy $(BUILD)/genhdr/qstrdefs.generated.h
	$(ECHO) "MISC freezing bytecode"
	$(Q)$(TOP)/tools/mpy-tool.py -f -q $(BUILD)/genhdr/qstrdefs.preprocessed.h -mlongint-impl=none $< > $@

$(BUILD)/firmware.elf: $(OBJ)
	$(ECHO) "LINK $@"
	$(Q)$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
	$(Q)$(SIZE) $@

$(BUILD)/firmware.bin: $(BUILD)/firmware.elf
	$(Q)$(OBJCOPY) -O binary -j .isr_vector -j .text -j .data $^ $(BUILD)/firmware.bin

$(BUILD)/firmware.dfu: $(BUILD)/firmware.bin
	$(ECHO) "Create $@"
	$(Q)$(PYTHON) $(DFU) -b 0x08000000:$(BUILD)/firmware.bin $@

deploy: $(BUILD)/firmware.dfu
	$(ECHO) "Writing $< to the board"
	$(Q)$(PYTHON) $(PYDFU) -u $<

# Run emulation build on a POSIX system with suitable terminal settings
run:
	@saved_=`stty -g`; \
	  stty raw opost -echo; \
	  $(BUILD)/firmware.elf; \
	  echo "Exit status: $$?"; \
	  stty $$saved_

test: $(BUILD)/firmware.elf
	$(Q)/bin/echo -e "print('hello world!', list(x+1 for x in range(10)), end='eol\\\\n')\\r\\n\\x04" | $(BUILD)/firmware.elf | tail -n2 | grep "^hello world! \\[1, 2, 3, 4, 5, 6, 7, 8, 9, 10\\]eol"

include $(TOP)/py/mkrules.mk
