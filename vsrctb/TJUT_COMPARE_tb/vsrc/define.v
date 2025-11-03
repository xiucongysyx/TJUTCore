// command
`define PC_WIDTH        32
`define INST_WIDTH      32
`define DATA_WIDTH      8
`define ADDER_WIDTH     5

// EX
`define ALUOP_WIDTH     7
`define BRAOP_WIDTH     4
`define LOGOP_WIDTH     3
`define EXCTRL_OTHER    5
`define EXCTRL_WIDTH    `LOGOP_WIDTH + `ALUOP_WIDTH + `EXCTRL_OTHER + `BRAOP_WIDTH

// IF
`define IFCTRL_OTHER    1
`define IFCTRL_WIDTH    `IFCTRL_OTHER

// WB
`define WBCTRL_OTHER    5
`define WBCTRL_WIDTH    `WBCTRL_OTHER

// MC
`define WMASK_WIDTH     3
`define RMASK_WIDTH     3
`define MCCTRL_OTHER    3
`define MCCTRL_WIDTH    `WMASK_WIDTH + `RMASK_WIDTH + `MCCTRL_OTHER

// COMPARE 
`define COM_RESULT      2

// SHIFT
`define SHIFT_WIDTH     6

