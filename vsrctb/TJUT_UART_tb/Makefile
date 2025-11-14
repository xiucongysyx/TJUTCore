TOPNAME = TJUT_UART_CTRL
LOGNAME = UART

GTKWAVE = gtkwave
VERILATOR = verilator

VERILATOR_ARGUMENTS += --cc --build
VERILATOR_ARGUMENTS += --Wall 
VERILATOR_ARGUMENTS += --exe
VERILATOR_ARGUMENTS += --trace
VERILATOR_ARGUMENTS += -I./vsrc

VERILATOR_TOP += --top-module $(TOPNAME) 

VERILATOR_INPUT += ./vsrc/*.v
VERILATOR_INPUT += ./csrc/*.cpp

OBJ_DIR = ./obj_dir
$(shell mkdir -p $(OBJ_DIR))

all:ver

ver:
	@echo
	@echo "----------Switch Exercise----------"
	@echo
	@echo "----------Verilator Compile--------"
	$(VERILATOR) $(VERILATOR_TOP) $(VERILATOR_ARGUMENTS) $(VERILATOR_INPUT)
	@echo
	@echo "----------Generating Wavefrom------"
	@rm -rf logs
	obj_dir/V$(TOPNAME) +trace > obj_dir/$(LOGNAME).log
	@echo
	@echo "----------Done---------------------"
	@echo "You can make GTKwave to see the wavefroms." 

wave:
	@echo "Opening dump.vcd"
	$(GTKWAVE) $(TOPNAME).vcd

test:
	@echo "TOPNAME: $(TOPNAME)"
	@echo "INPUT: $(VERILATOR_INPUT)"
	@echo "VERILATOR_CFLAGS: $(VERILATOR_ARGUMENTS)"
clean:
	rm -rf $(BUILD_DIR) obj_dir

.PHONY: default all clean run
