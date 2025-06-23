#$(AM_HOME)/scripts/isa/riscv.mk
CROSS_COMPILE := riscv64-linux-gnu-
COMMON_CFLAGS := -fno-pic -march=rv64g -mcmodel=medany -mstrict-align
CFLAGS        += $(COMMON_CFLAGS) -static
ASFLAGS       += $(COMMON_CFLAGS) -O0
LDFLAGS       += -melf64lriscv

# overwrite ARCH_H defined in $(AM_HOME)/Makefile
ARCH_H := arch/riscv.h

#---------------------------------------------

#$(AM_HOME)/scripts/platform/npc.mk
AM_SRCS := $(TJUTCORE_HOME)/tests/compile/start.S \
           $(TJUTCORE_HOME)/tests/compile/trm.c \
           $(TJUTCORE_HOME)/tests/compile/ioe.c \
           $(TJUTCORE_HOME)/tests/compile/timer.c \
           $(TJUTCORE_HOME)/tests/compile/input.c \
           $(TJUTCORE_HOME)/tests/compile/gpu.c \
           $(TJUTCORE_HOME)/tests/compile/cte.c \
           $(TJUTCORE_HOME)/tests/compile/trap.S \
           $(TJUTCORE_HOME)/tests/compile/vme.c \
           $(TJUTCORE_HOME)/tests/compile/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(TJUTCORE_HOME)/scripts/linker.ld \
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
CFLAGS += -DMAINARGS=\"$(mainargs)\"
CFLAGS += -I$(TJUTCORE__HOME)/tests/compile/include

NPCFLAGS  += -l $(shell dirname $(IMAGE).elf)/npc-log.txt

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

#--------------------------------------------

COMMON_CFLAGS += -march=rv32e_zicsr -mabi=ilp32e  # overwrite
LDFLAGS       += -melf32lriscv                    # overwrite

AM_SRCS += $(TJUTCORE_HOME)/tests/compile/libgcc/div.S \
           $(TJUTCORE_HOME)/tests/compile/libgcc/muldi3.S \
           $(TJUTCORE_HOME)/tests/compile/libgcc/multi3.c \
           $(TJUTCORE_HOME)/tests/compile/libgcc/ashldi3.c \
           $(TJUTCORE_HOME)/tests/compile/libgcc/unused.c
