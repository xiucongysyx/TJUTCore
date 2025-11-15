# Top module 
TOP_NAME				:= TJUT_TOP

IMAGE 					?= $(TJUTCORE_HOME)/bin/add-riscv32e-npc

# path of the verilog file
V_PATH					:= $(TJUTCORE_HOME)/vsrc

# 编译器是Verilator
VERILATOR 				:= CC=$(VCC) CXX=$(VCXX) verilator
GTKWAVE					:= gtkwave
VCC 					:= ccache gcc
VCXX					:= ccache g++

# gdb
GDB 					:= gdb

# .c文件和.v文件
VSRCS 					+= $(shell find $(TJUTCORE_HOME)/vsrc -name "*.v")
CSRCS 					+= $(shell find $(TJUTCORE_HOME)/csrc -name "*.c" -or -name "*.cc")

# 头文件地址
INC_PATH 				+= $(TJUTCORE_HOME)/include
INC_PATH 				+= $(OBJ_DIR)
INCFLAGS 				:= $(addprefix -I, $(INC_PATH))

# 动态链接库
VLDFLAGS 				+= -lreadline
VLDFLAGS 				+= $(shell llvm-config --libs)
VLDFLAGS 				+= -ldl
VLDFLAGS 				+= -lSDL2

# build地址
BUILD_DIR 		  		:= $(TJUTCORE_HOME)/build
OBJ_DIR 				:= $(BUILD_DIR)/obj_dir

# 编译时C参数
VCFLAGS 					+= $(INCFLAGS) -g
VCFLAGS 					+= -O3
VCFLAGS 					+= $(filter-out -D__STDC_FORMAT_MACROS, $(shell llvm-config --cxxflags)) -fPIE
#CFLAGS 					+= -fuse-ld=mold

# verilator参数
VERILATOR_FLAGS += -I$(V_PATH)
VERILATOR_FLAGS += --top-module $(TOP_NAME)
VERILATOR_FLAGS += --trace --cc --exe --build 
VERILATOR_FLAGS += --Wall
VERILATOR_FLAGS += --Mdir $(OBJ_DIR)
VERILATOR_FLAGS += --timescale "1ns/1ps"

# 运行时参数和img文件
# NPC_FLAGS   		+= -b
NPC_FLAGS 			+= -l $(shell dirname $(IMAGE).bin)/npc-log.txt 
# NPC_FLAGS 		+= -e $(addsuffix .elf,$(basename $(IMAGE))) 
NPC_IMAGE 			+= $(IMAGE).bin

# 可执行文件地址
NPC_BIN 			:= $(OBJ_DIR)/V$(TOP_NAME)
NPC_EXEC 			:= $(NPC_BIN) $(NPC_FLAGS) $(NPC_IMAGE)

#静默输出
export MAKEFLAGS 	+= --no-print-directory --silent
Q					:= @ 				
.SILENT:


# Extract compiler and options from menuconfig
# include rules for menuconfig
include $(TJUTCORE_HOME)/scripts/config.mk

# compile
compile: $(CSRCS) $(VSRCS)
	$(Q)echo "# Building tpc [riscv32-tpc]"
	$(Q)$(shell mkdir -p $(OBJ_DIR))
	$(Q)$(VERILATOR) $(VERILATOR_FLAGS) $(CSRCS) $(VSRCS) \
	$(addprefix -CFLAGS , $(VCFLAGS)) $(addprefix -LDFLAGS , $(VLDFLAGS))

# run
run: compile
	$(Q)$(NPC_EXEC)

# gdb
gdb: $(COMPILE)
	$(Q) $(GDB) -s $(NPC_BIN) --args $(NPC_EXEC) -c core.1215191

# wave
wave: 
	$(GTKWAVE) ./build/npc_wave.vcd &

.PHONY: run gdb wave compile
