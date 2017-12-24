/* Definition for CPU ID */
#define XPAR_CPU_ID 0

/* Definitions for peripheral PS7_CORTEXA9_0 */
#define XPAR_PS7_CORTEXA9_0_CPU_CLK_FREQ_HZ 600000000


/******************************************************************/

/* Canonical definitions for peripheral PS7_CORTEXA9_0 */
#define XPAR_CPU_CORTEXA9_0_CPU_CLK_FREQ_HZ 600000000


/******************************************************************/

#include "xparameters_ps.h"

#define STDIN_BASEADDRESS 0xE0001000
#define STDOUT_BASEADDRESS 0xE0001000

/******************************************************************/

/* Definitions for driver CANPS */
#define XPAR_XCANPS_NUM_INSTANCES 2

/* Definitions for peripheral PS7_CAN_0 */
#define XPAR_PS7_CAN_0_DEVICE_ID 0
#define XPAR_PS7_CAN_0_BASEADDR 0xE0008000
#define XPAR_PS7_CAN_0_HIGHADDR 0xE0008FFF
#define XPAR_PS7_CAN_0_CAN_CLK_FREQ_HZ 100000000


/* Definitions for peripheral PS7_CAN_1 */
#define XPAR_PS7_CAN_1_DEVICE_ID 1
#define XPAR_PS7_CAN_1_BASEADDR 0xE0009000
#define XPAR_PS7_CAN_1_HIGHADDR 0xE0009FFF
#define XPAR_PS7_CAN_1_CAN_CLK_FREQ_HZ 100000000


/******************************************************************/

/* Canonical definitions for peripheral PS7_CAN_0 */
#define XPAR_XCANPS_0_DEVICE_ID XPAR_PS7_CAN_0_DEVICE_ID
#define XPAR_XCANPS_0_BASEADDR 0xE0008000
#define XPAR_XCANPS_0_HIGHADDR 0xE0008FFF
#define XPAR_XCANPS_0_CAN_CLK_FREQ_HZ 100000000

/* Canonical definitions for peripheral PS7_CAN_1 */
#define XPAR_XCANPS_1_DEVICE_ID XPAR_PS7_CAN_1_DEVICE_ID
#define XPAR_XCANPS_1_BASEADDR 0xE0009000
#define XPAR_XCANPS_1_HIGHADDR 0xE0009FFF
#define XPAR_XCANPS_1_CAN_CLK_FREQ_HZ 100000000


/******************************************************************/


/* Definitions for peripheral PS7_DDR_0 */
#define XPAR_PS7_DDR_0_S_AXI_BASEADDR 0x00100000
#define XPAR_PS7_DDR_0_S_AXI_HIGHADDR 0x3FFFFFFF


/******************************************************************/

/* Definitions for driver DEVCFG */
#define XPAR_XDCFG_NUM_INSTANCES 1

/* Definitions for peripheral PS7_DEV_CFG_0 */
#define XPAR_PS7_DEV_CFG_0_DEVICE_ID 0
#define XPAR_PS7_DEV_CFG_0_BASEADDR 0xF8007000
#define XPAR_PS7_DEV_CFG_0_HIGHADDR 0xF80070FF


/******************************************************************/

/* Canonical definitions for peripheral PS7_DEV_CFG_0 */
#define XPAR_XDCFG_0_DEVICE_ID XPAR_PS7_DEV_CFG_0_DEVICE_ID
#define XPAR_XDCFG_0_BASEADDR 0xF8007000
#define XPAR_XDCFG_0_HIGHADDR 0xF80070FF


/******************************************************************/

/* Definitions for driver DMAPS */
#define XPAR_XDMAPS_NUM_INSTANCES 2

/* Definitions for peripheral PS7_DMA_NS */
#define XPAR_PS7_DMA_NS_DEVICE_ID 0
#define XPAR_PS7_DMA_NS_BASEADDR 0xF8004000
#define XPAR_PS7_DMA_NS_HIGHADDR 0xF8004FFF


/* Definitions for peripheral PS7_DMA_S */
#define XPAR_PS7_DMA_S_DEVICE_ID 1
#define XPAR_PS7_DMA_S_BASEADDR 0xF8003000
#define XPAR_PS7_DMA_S_HIGHADDR 0xF8003FFF


/******************************************************************/

/* Canonical definitions for peripheral PS7_DMA_NS */
#define XPAR_XDMAPS_0_DEVICE_ID XPAR_PS7_DMA_NS_DEVICE_ID
#define XPAR_XDMAPS_0_BASEADDR 0xF8004000
#define XPAR_XDMAPS_0_HIGHADDR 0xF8004FFF

/* Canonical definitions for peripheral PS7_DMA_S */
#define XPAR_XDMAPS_1_DEVICE_ID XPAR_PS7_DMA_S_DEVICE_ID
#define XPAR_XDMAPS_1_BASEADDR 0xF8003000
#define XPAR_XDMAPS_1_HIGHADDR 0xF8003FFF


/******************************************************************/

/* Definitions for driver EMACPS */
#define XPAR_XEMACPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_ETHERNET_0 */
#define XPAR_PS7_ETHERNET_0_DEVICE_ID 0
#define XPAR_PS7_ETHERNET_0_BASEADDR 0xE000B000
#define XPAR_PS7_ETHERNET_0_HIGHADDR 0xE000BFFF
#define XPAR_PS7_ETHERNET_0_ENET_CLK_FREQ_HZ 125000000
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_1000MBPS_DIV0 8
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_1000MBPS_DIV1 1
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_100MBPS_DIV0 8
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_100MBPS_DIV1 5
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_10MBPS_DIV0 8
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_10MBPS_DIV1 50


/******************************************************************/

/* Canonical definitions for peripheral PS7_ETHERNET_0 */
#define XPAR_XEMACPS_0_DEVICE_ID XPAR_PS7_ETHERNET_0_DEVICE_ID
#define XPAR_XEMACPS_0_BASEADDR 0xE000B000
#define XPAR_XEMACPS_0_HIGHADDR 0xE000BFFF
#define XPAR_XEMACPS_0_ENET_CLK_FREQ_HZ 125000000
#define XPAR_XEMACPS_0_ENET_SLCR_1000Mbps_DIV0 8
#define XPAR_XEMACPS_0_ENET_SLCR_1000Mbps_DIV1 1
#define XPAR_XEMACPS_0_ENET_SLCR_100Mbps_DIV0 8
#define XPAR_XEMACPS_0_ENET_SLCR_100Mbps_DIV1 5
#define XPAR_XEMACPS_0_ENET_SLCR_10Mbps_DIV0 8
#define XPAR_XEMACPS_0_ENET_SLCR_10Mbps_DIV1 50


/******************************************************************/


/* Definitions for peripheral AXI_EMC_0 */
#define XPAR_AXI_EMC_0_NUM_BANKS_MEM 3


/******************************************************************/

/* Definitions for peripheral AXI_EMC_0 */
#define XPAR_AXI_EMC_0_S_AXI_MEM0_BASEADDR 0x88000000

/******************************************************************/

/* Canonical definitions for peripheral AXI_EMC_0 */
#define XPAR_EMC_0_NUM_BANKS_MEM 3
#define XPAR_EMC_0_S_AXI_MEM0_BASEADDR 0x88000000
#define XPAR_EMC_0_S_AXI_MEM0_HIGHADDR 0x8FFFFFFF
#define XPAR_EMC_0_S_AXI_MEM1_BASEADDR 0x90000000
#define XPAR_EMC_0_S_AXI_MEM1_HIGHADDR 0x97FFFFFF
#define XPAR_EMC_0_S_AXI_MEM2_BASEADDR 0x98000000
#define XPAR_EMC_0_S_AXI_MEM2_HIGHADDR 0x9FFFFFFF

#define XPAR_AXI_EMC

/******************************************************************/


/* Definitions for peripheral PS7_AFI_0 */
#define XPAR_PS7_AFI_0_S_AXI_BASEADDR 0xF8008000
#define XPAR_PS7_AFI_0_S_AXI_HIGHADDR 0xF8008FFF


/* Definitions for peripheral PS7_AFI_1 */
#define XPAR_PS7_AFI_1_S_AXI_BASEADDR 0xF8009000
#define XPAR_PS7_AFI_1_S_AXI_HIGHADDR 0xF8009FFF


/* Definitions for peripheral PS7_AFI_2 */
#define XPAR_PS7_AFI_2_S_AXI_BASEADDR 0xF800A000
#define XPAR_PS7_AFI_2_S_AXI_HIGHADDR 0xF800AFFF


/* Definitions for peripheral PS7_AFI_3 */
#define XPAR_PS7_AFI_3_S_AXI_BASEADDR 0xF800B000
#define XPAR_PS7_AFI_3_S_AXI_HIGHADDR 0xF800BFFF


/* Definitions for peripheral PS7_DDRC_0 */
#define XPAR_PS7_DDRC_0_S_AXI_BASEADDR 0xF8006000
#define XPAR_PS7_DDRC_0_S_AXI_HIGHADDR 0xF8006FFF


/* Definitions for peripheral PS7_GLOBALTIMER_0 */
#define XPAR_PS7_GLOBALTIMER_0_S_AXI_BASEADDR 0xF8F00200
#define XPAR_PS7_GLOBALTIMER_0_S_AXI_HIGHADDR 0xF8F002FF


/* Definitions for peripheral PS7_GPV_0 */
#define XPAR_PS7_GPV_0_S_AXI_BASEADDR 0xF8900000
#define XPAR_PS7_GPV_0_S_AXI_HIGHADDR 0xF89FFFFF


/* Definitions for peripheral PS7_INTC_DIST_0 */
#define XPAR_PS7_INTC_DIST_0_S_AXI_BASEADDR 0xF8F01000
#define XPAR_PS7_INTC_DIST_0_S_AXI_HIGHADDR 0xF8F01FFF


/* Definitions for peripheral PS7_IOP_BUS_CONFIG_0 */
#define XPAR_PS7_IOP_BUS_CONFIG_0_S_AXI_BASEADDR 0xE0200000
#define XPAR_PS7_IOP_BUS_CONFIG_0_S_AXI_HIGHADDR 0xE0200FFF


/* Definitions for peripheral PS7_L2CACHEC_0 */
#define XPAR_PS7_L2CACHEC_0_S_AXI_BASEADDR 0xF8F02000
#define XPAR_PS7_L2CACHEC_0_S_AXI_HIGHADDR 0xF8F02FFF


/* Definitions for peripheral PS7_OCMC_0 */
#define XPAR_PS7_OCMC_0_S_AXI_BASEADDR 0xF800C000
#define XPAR_PS7_OCMC_0_S_AXI_HIGHADDR 0xF800CFFF


/* Definitions for peripheral PS7_PL310_0 */
#define XPAR_PS7_PL310_0_S_AXI_BASEADDR 0xF8F02000
#define XPAR_PS7_PL310_0_S_AXI_HIGHADDR 0xF8F02FFF


/* Definitions for peripheral PS7_PMU_0 */
#define XPAR_PS7_PMU_0_S_AXI_BASEADDR 0xF8891000
#define XPAR_PS7_PMU_0_S_AXI_HIGHADDR 0xF8891FFF
#define XPAR_PS7_PMU_0_PMU1_S_AXI_BASEADDR 0xF8893000
#define XPAR_PS7_PMU_0_PMU1_S_AXI_HIGHADDR 0xF8893FFF


/* Definitions for peripheral PS7_QSPI_LINEAR_0 */
#define XPAR_PS7_QSPI_LINEAR_0_S_AXI_BASEADDR 0xFC000000
#define XPAR_PS7_QSPI_LINEAR_0_S_AXI_HIGHADDR 0xFCFFFFFF


/* Definitions for peripheral PS7_RAM_0 */
#define XPAR_PS7_RAM_0_S_AXI_BASEADDR 0x00000000
#define XPAR_PS7_RAM_0_S_AXI_HIGHADDR 0x0003FFFF


/* Definitions for peripheral PS7_RAM_1 */
#define XPAR_PS7_RAM_1_S_AXI_BASEADDR 0xFFFC0000
#define XPAR_PS7_RAM_1_S_AXI_HIGHADDR 0xFFFFFFFF


/* Definitions for peripheral PS7_SCUC_0 */
#define XPAR_PS7_SCUC_0_S_AXI_BASEADDR 0xF8F00000
#define XPAR_PS7_SCUC_0_S_AXI_HIGHADDR 0xF8F000FC


/* Definitions for peripheral PS7_SLCR_0 */
#define XPAR_PS7_SLCR_0_S_AXI_BASEADDR 0xF8000000
#define XPAR_PS7_SLCR_0_S_AXI_HIGHADDR 0xF8000FFF


/******************************************************************/

/* Definitions for driver GPIO */
#define XPAR_XGPIO_NUM_INSTANCES 9

/* Definitions for peripheral AXI_GPIO_CFG_EN */
#define XPAR_AXI_GPIO_CFG_EN_BASEADDR 0x41210000
#define XPAR_AXI_GPIO_CFG_EN_HIGHADDR 0x4121FFFF
#define XPAR_AXI_GPIO_CFG_EN_DEVICE_ID 0
#define XPAR_AXI_GPIO_CFG_EN_INTERRUPT_PRESENT 0
#define XPAR_AXI_GPIO_CFG_EN_IS_DUAL 0


/* Definitions for peripheral AXI_GPIO_DONE */
#define XPAR_AXI_GPIO_DONE_BASEADDR 0x41200000
#define XPAR_AXI_GPIO_DONE_HIGHADDR 0x4120FFFF
#define XPAR_AXI_GPIO_DONE_DEVICE_ID 1
#define XPAR_AXI_GPIO_DONE_INTERRUPT_PRESENT 0
#define XPAR_AXI_GPIO_DONE_IS_DUAL 0


/* Definitions for peripheral AXI_GPIO_FRM_V7 */
#define XPAR_AXI_GPIO_FRM_V7_BASEADDR 0x41240000
#define XPAR_AXI_GPIO_FRM_V7_HIGHADDR 0x4124FFFF
#define XPAR_AXI_GPIO_FRM_V7_DEVICE_ID 2
#define XPAR_AXI_GPIO_FRM_V7_INTERRUPT_PRESENT 0
#define XPAR_AXI_GPIO_FRM_V7_IS_DUAL 0


/* Definitions for peripheral AXI_GPIO_GA */
#define XPAR_AXI_GPIO_GA_BASEADDR 0x41230000
#define XPAR_AXI_GPIO_GA_HIGHADDR 0x4123FFFF
#define XPAR_AXI_GPIO_GA_DEVICE_ID 3
#define XPAR_AXI_GPIO_GA_INTERRUPT_PRESENT 0
#define XPAR_AXI_GPIO_GA_IS_DUAL 0


/* Definitions for peripheral AXI_GPIO_RST_B */
#define XPAR_AXI_GPIO_RST_B_BASEADDR 0x41220000
#define XPAR_AXI_GPIO_RST_B_HIGHADDR 0x4122FFFF
#define XPAR_AXI_GPIO_RST_B_DEVICE_ID 4
#define XPAR_AXI_GPIO_RST_B_INTERRUPT_PRESENT 0
#define XPAR_AXI_GPIO_RST_B_IS_DUAL 0


/* Definitions for peripheral AXI_GPIO_TO_V7_0 */
#define XPAR_AXI_GPIO_TO_V7_0_BASEADDR 0x41250000
#define XPAR_AXI_GPIO_TO_V7_0_HIGHADDR 0x4125FFFF
#define XPAR_AXI_GPIO_TO_V7_0_DEVICE_ID 5
#define XPAR_AXI_GPIO_TO_V7_0_INTERRUPT_PRESENT 0
#define XPAR_AXI_GPIO_TO_V7_0_IS_DUAL 0


/* Definitions for peripheral AXI_GPIO_TO_V7_1 */
#define XPAR_AXI_GPIO_TO_V7_1_BASEADDR 0x41260000
#define XPAR_AXI_GPIO_TO_V7_1_HIGHADDR 0x4126FFFF
#define XPAR_AXI_GPIO_TO_V7_1_DEVICE_ID 6
#define XPAR_AXI_GPIO_TO_V7_1_INTERRUPT_PRESENT 0
#define XPAR_AXI_GPIO_TO_V7_1_IS_DUAL 0


/* Definitions for peripheral AXI_GPIO_TO_V7_2 */
#define XPAR_AXI_GPIO_TO_V7_2_BASEADDR 0x41270000
#define XPAR_AXI_GPIO_TO_V7_2_HIGHADDR 0x4127FFFF
#define XPAR_AXI_GPIO_TO_V7_2_DEVICE_ID 7
#define XPAR_AXI_GPIO_TO_V7_2_INTERRUPT_PRESENT 0
#define XPAR_AXI_GPIO_TO_V7_2_IS_DUAL 0


/* Definitions for peripheral AXI_GPIO_TO_V7_3 */
#define XPAR_AXI_GPIO_TO_V7_3_BASEADDR 0x41280000
#define XPAR_AXI_GPIO_TO_V7_3_HIGHADDR 0x4128FFFF
#define XPAR_AXI_GPIO_TO_V7_3_DEVICE_ID 8
#define XPAR_AXI_GPIO_TO_V7_3_INTERRUPT_PRESENT 0
#define XPAR_AXI_GPIO_TO_V7_3_IS_DUAL 0


/******************************************************************/

/* Canonical definitions for peripheral AXI_GPIO_CFG_EN */
#define XPAR_GPIO_0_BASEADDR 0x41210000
#define XPAR_GPIO_0_HIGHADDR 0x4121FFFF
#define XPAR_GPIO_0_DEVICE_ID XPAR_AXI_GPIO_CFG_EN_DEVICE_ID
#define XPAR_GPIO_0_INTERRUPT_PRESENT 0
#define XPAR_GPIO_0_IS_DUAL 0

/* Canonical definitions for peripheral AXI_GPIO_DONE */
#define XPAR_GPIO_1_BASEADDR 0x41200000
#define XPAR_GPIO_1_HIGHADDR 0x4120FFFF
#define XPAR_GPIO_1_DEVICE_ID XPAR_AXI_GPIO_DONE_DEVICE_ID
#define XPAR_GPIO_1_INTERRUPT_PRESENT 0
#define XPAR_GPIO_1_IS_DUAL 0

/* Canonical definitions for peripheral AXI_GPIO_FRM_V7 */
#define XPAR_GPIO_2_BASEADDR 0x41240000
#define XPAR_GPIO_2_HIGHADDR 0x4124FFFF
#define XPAR_GPIO_2_DEVICE_ID XPAR_AXI_GPIO_FRM_V7_DEVICE_ID
#define XPAR_GPIO_2_INTERRUPT_PRESENT 0
#define XPAR_GPIO_2_IS_DUAL 0

/* Canonical definitions for peripheral AXI_GPIO_GA */
#define XPAR_GPIO_3_BASEADDR 0x41230000
#define XPAR_GPIO_3_HIGHADDR 0x4123FFFF
#define XPAR_GPIO_3_DEVICE_ID XPAR_AXI_GPIO_GA_DEVICE_ID
#define XPAR_GPIO_3_INTERRUPT_PRESENT 0
#define XPAR_GPIO_3_IS_DUAL 0

/* Canonical definitions for peripheral AXI_GPIO_RST_B */
#define XPAR_GPIO_4_BASEADDR 0x41220000
#define XPAR_GPIO_4_HIGHADDR 0x4122FFFF
#define XPAR_GPIO_4_DEVICE_ID XPAR_AXI_GPIO_RST_B_DEVICE_ID
#define XPAR_GPIO_4_INTERRUPT_PRESENT 0
#define XPAR_GPIO_4_IS_DUAL 0

/* Canonical definitions for peripheral AXI_GPIO_TO_V7_0 */
#define XPAR_GPIO_5_BASEADDR 0x41250000
#define XPAR_GPIO_5_HIGHADDR 0x4125FFFF
#define XPAR_GPIO_5_DEVICE_ID XPAR_AXI_GPIO_TO_V7_0_DEVICE_ID
#define XPAR_GPIO_5_INTERRUPT_PRESENT 0
#define XPAR_GPIO_5_IS_DUAL 0

/* Canonical definitions for peripheral AXI_GPIO_TO_V7_1 */
#define XPAR_GPIO_6_BASEADDR 0x41260000
#define XPAR_GPIO_6_HIGHADDR 0x4126FFFF
#define XPAR_GPIO_6_DEVICE_ID XPAR_AXI_GPIO_TO_V7_1_DEVICE_ID
#define XPAR_GPIO_6_INTERRUPT_PRESENT 0
#define XPAR_GPIO_6_IS_DUAL 0

/* Canonical definitions for peripheral AXI_GPIO_TO_V7_2 */
#define XPAR_GPIO_7_BASEADDR 0x41270000
#define XPAR_GPIO_7_HIGHADDR 0x4127FFFF
#define XPAR_GPIO_7_DEVICE_ID XPAR_AXI_GPIO_TO_V7_2_DEVICE_ID
#define XPAR_GPIO_7_INTERRUPT_PRESENT 0
#define XPAR_GPIO_7_IS_DUAL 0

/* Canonical definitions for peripheral AXI_GPIO_TO_V7_3 */
#define XPAR_GPIO_8_BASEADDR 0x41280000
#define XPAR_GPIO_8_HIGHADDR 0x4128FFFF
#define XPAR_GPIO_8_DEVICE_ID XPAR_AXI_GPIO_TO_V7_3_DEVICE_ID
#define XPAR_GPIO_8_INTERRUPT_PRESENT 0
#define XPAR_GPIO_8_IS_DUAL 0


/******************************************************************/

/* Definitions for driver GPIOPS */
#define XPAR_XGPIOPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_GPIO_0 */
#define XPAR_PS7_GPIO_0_DEVICE_ID 0
#define XPAR_PS7_GPIO_0_BASEADDR 0xE000A000
#define XPAR_PS7_GPIO_0_HIGHADDR 0xE000AFFF


/******************************************************************/

/* Canonical definitions for peripheral PS7_GPIO_0 */
#define XPAR_XGPIOPS_0_DEVICE_ID XPAR_PS7_GPIO_0_DEVICE_ID
#define XPAR_XGPIOPS_0_BASEADDR 0xE000A000
#define XPAR_XGPIOPS_0_HIGHADDR 0xE000AFFF


/******************************************************************/

/* Definitions for driver IICPS */
#define XPAR_XIICPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_I2C_0 */
#define XPAR_PS7_I2C_0_DEVICE_ID 0
#define XPAR_PS7_I2C_0_BASEADDR 0xE0004000
#define XPAR_PS7_I2C_0_HIGHADDR 0xE0004FFF
#define XPAR_PS7_I2C_0_I2C_CLK_FREQ_HZ 100000000


/******************************************************************/

/* Canonical definitions for peripheral PS7_I2C_0 */
#define XPAR_XIICPS_0_DEVICE_ID XPAR_PS7_I2C_0_DEVICE_ID
#define XPAR_XIICPS_0_BASEADDR 0xE0004000
#define XPAR_XIICPS_0_HIGHADDR 0xE0004FFF
#define XPAR_XIICPS_0_I2C_CLK_FREQ_HZ 100000000


/******************************************************************/

/* Definitions for driver LLFIFO */
#define XPAR_XLLFIFO_NUM_INSTANCES 4

/* Definitions for peripheral V7_CFG_FIFO0 */
#define XPAR_V7_CFG_FIFO0_DEVICE_ID 0
#define XPAR_V7_CFG_FIFO0_BASEADDR 0x43C10000
#define XPAR_V7_CFG_FIFO0_HIGHADDR 0x43C1FFFF
#define XPAR_V7_CFG_FIFO0_AXI4_BASEADDR 0x80001000
#define XPAR_V7_CFG_FIFO0_AXI4_HIGHADDR 0x80002FFF
#define XPAR_V7_CFG_FIFO0_DATA_INTERFACE_TYPE 0


/* Definitions for peripheral V7_CFG_FIFO1 */
#define XPAR_V7_CFG_FIFO1_DEVICE_ID 1
#define XPAR_V7_CFG_FIFO1_BASEADDR 0x43C20000
#define XPAR_V7_CFG_FIFO1_HIGHADDR 0x43C2FFFF
#define XPAR_V7_CFG_FIFO1_AXI4_BASEADDR 0x80001000
#define XPAR_V7_CFG_FIFO1_AXI4_HIGHADDR 0x80002FFF
#define XPAR_V7_CFG_FIFO1_DATA_INTERFACE_TYPE 0


/* Definitions for peripheral V7_CFG_FIFO2 */
#define XPAR_V7_CFG_FIFO2_DEVICE_ID 2
#define XPAR_V7_CFG_FIFO2_BASEADDR 0x43C30000
#define XPAR_V7_CFG_FIFO2_HIGHADDR 0x43C3FFFF
#define XPAR_V7_CFG_FIFO2_AXI4_BASEADDR 0x80001000
#define XPAR_V7_CFG_FIFO2_AXI4_HIGHADDR 0x80002FFF
#define XPAR_V7_CFG_FIFO2_DATA_INTERFACE_TYPE 0


/* Definitions for peripheral V7_CFG_FIFO3 */
#define XPAR_V7_CFG_FIFO3_DEVICE_ID 3
#define XPAR_V7_CFG_FIFO3_BASEADDR 0x43C40000
#define XPAR_V7_CFG_FIFO3_HIGHADDR 0x43C4FFFF
#define XPAR_V7_CFG_FIFO3_AXI4_BASEADDR 0x80001000
#define XPAR_V7_CFG_FIFO3_AXI4_HIGHADDR 0x80002FFF
#define XPAR_V7_CFG_FIFO3_DATA_INTERFACE_TYPE 0


/******************************************************************/

/* Canonical definitions for peripheral V7_CFG_FIFO0 */
#define XPAR_AXI_FIFO_0_DEVICE_ID XPAR_V7_CFG_FIFO0_DEVICE_ID
#define XPAR_AXI_FIFO_0_BASEADDR 0x43C10000
#define XPAR_AXI_FIFO_0_HIGHADDR 0x43C1FFFF
#define XPAR_AXI_FIFO_0_AXI4_BASEADDR 0x80001000
#define XPAR_AXI_FIFO_0_AXI4_HIGHADDR 0x80002FFF
#define XPAR_AXI_FIFO_0_DATA_INTERFACE_TYPE 0

/* Canonical definitions for peripheral V7_CFG_FIFO1 */
#define XPAR_AXI_FIFO_1_DEVICE_ID XPAR_V7_CFG_FIFO1_DEVICE_ID
#define XPAR_AXI_FIFO_1_BASEADDR 0x43C20000
#define XPAR_AXI_FIFO_1_HIGHADDR 0x43C2FFFF
#define XPAR_AXI_FIFO_1_AXI4_BASEADDR 0x80001000
#define XPAR_AXI_FIFO_1_AXI4_HIGHADDR 0x80002FFF
#define XPAR_AXI_FIFO_1_DATA_INTERFACE_TYPE 0

/* Canonical definitions for peripheral V7_CFG_FIFO2 */
#define XPAR_AXI_FIFO_2_DEVICE_ID XPAR_V7_CFG_FIFO2_DEVICE_ID
#define XPAR_AXI_FIFO_2_BASEADDR 0x43C30000
#define XPAR_AXI_FIFO_2_HIGHADDR 0x43C3FFFF
#define XPAR_AXI_FIFO_2_AXI4_BASEADDR 0x80001000
#define XPAR_AXI_FIFO_2_AXI4_HIGHADDR 0x80002FFF
#define XPAR_AXI_FIFO_2_DATA_INTERFACE_TYPE 0

/* Canonical definitions for peripheral V7_CFG_FIFO3 */
#define XPAR_AXI_FIFO_3_DEVICE_ID XPAR_V7_CFG_FIFO3_DEVICE_ID
#define XPAR_AXI_FIFO_3_BASEADDR 0x43C40000
#define XPAR_AXI_FIFO_3_HIGHADDR 0x43C4FFFF
#define XPAR_AXI_FIFO_3_AXI4_BASEADDR 0x80001000
#define XPAR_AXI_FIFO_3_AXI4_HIGHADDR 0x80002FFF
#define XPAR_AXI_FIFO_3_DATA_INTERFACE_TYPE 0


/******************************************************************/

/* Definitions for driver QSPIPS */
#define XPAR_XQSPIPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_QSPI_0 */
#define XPAR_PS7_QSPI_0_DEVICE_ID 0
#define XPAR_PS7_QSPI_0_BASEADDR 0xE000D000
#define XPAR_PS7_QSPI_0_HIGHADDR 0xE000DFFF
#define XPAR_PS7_QSPI_0_QSPI_CLK_FREQ_HZ 200000000
#define XPAR_PS7_QSPI_0_QSPI_MODE 0


/******************************************************************/

/* Canonical definitions for peripheral PS7_QSPI_0 */
#define XPAR_XQSPIPS_0_DEVICE_ID XPAR_PS7_QSPI_0_DEVICE_ID
#define XPAR_XQSPIPS_0_BASEADDR 0xE000D000
#define XPAR_XQSPIPS_0_HIGHADDR 0xE000DFFF
#define XPAR_XQSPIPS_0_QSPI_CLK_FREQ_HZ 200000000
#define XPAR_XQSPIPS_0_QSPI_MODE 0


/******************************************************************/

/* Definitions for driver SCUGIC */
#define XPAR_XSCUGIC_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SCUGIC_0 */
#define XPAR_PS7_SCUGIC_0_DEVICE_ID 0
#define XPAR_PS7_SCUGIC_0_BASEADDR 0xF8F00100
#define XPAR_PS7_SCUGIC_0_HIGHADDR 0xF8F001FF
#define XPAR_PS7_SCUGIC_0_DIST_BASEADDR 0xF8F01000


/******************************************************************/

/* Canonical definitions for peripheral PS7_SCUGIC_0 */
#define XPAR_SCUGIC_0_DEVICE_ID 0
#define XPAR_SCUGIC_0_CPU_BASEADDR 0xF8F00100
#define XPAR_SCUGIC_0_CPU_HIGHADDR 0xF8F001FF
#define XPAR_SCUGIC_0_DIST_BASEADDR 0xF8F01000


/******************************************************************/

/* Definitions for driver SCUTIMER */
#define XPAR_XSCUTIMER_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SCUTIMER_0 */
#define XPAR_PS7_SCUTIMER_0_DEVICE_ID 0
#define XPAR_PS7_SCUTIMER_0_BASEADDR 0xF8F00600
#define XPAR_PS7_SCUTIMER_0_HIGHADDR 0xF8F0061F


/******************************************************************/

/* Canonical definitions for peripheral PS7_SCUTIMER_0 */
#define XPAR_XSCUTIMER_0_DEVICE_ID XPAR_PS7_SCUTIMER_0_DEVICE_ID
#define XPAR_XSCUTIMER_0_BASEADDR 0xF8F00600
#define XPAR_XSCUTIMER_0_HIGHADDR 0xF8F0061F


/******************************************************************/

/* Definitions for driver SCUWDT */
#define XPAR_XSCUWDT_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SCUWDT_0 */
#define XPAR_PS7_SCUWDT_0_DEVICE_ID 0
#define XPAR_PS7_SCUWDT_0_BASEADDR 0xF8F00620
#define XPAR_PS7_SCUWDT_0_HIGHADDR 0xF8F006FF


/******************************************************************/

/* Canonical definitions for peripheral PS7_SCUWDT_0 */
#define XPAR_SCUWDT_0_DEVICE_ID XPAR_PS7_SCUWDT_0_DEVICE_ID
#define XPAR_SCUWDT_0_BASEADDR 0xF8F00620
#define XPAR_SCUWDT_0_HIGHADDR 0xF8F006FF


/******************************************************************/

/* Definitions for driver SYSMON */
#define XPAR_XSYSMON_NUM_INSTANCES 1

/* Definitions for peripheral XADC_WIZ_0 */
#define XPAR_XADC_WIZ_0_IP_TYPE 0
#define XPAR_XADC_WIZ_0_DEVICE_ID 0
#define XPAR_XADC_WIZ_0_BASEADDR 0x43C00000
#define XPAR_XADC_WIZ_0_HIGHADDR 0x43C0FFFF
#define XPAR_XADC_WIZ_0_INCLUDE_INTR 1


/******************************************************************/

/* Canonical definitions for peripheral XADC_WIZ_0 */
#define XPAR_SYSMON_0_IP_TYPE 0
#define XPAR_SYSMON_0_DEVICE_ID XPAR_XADC_WIZ_0_DEVICE_ID
#define XPAR_SYSMON_0_BASEADDR 0x43C00000
#define XPAR_SYSMON_0_HIGHADDR 0x43C0FFFF
#define XPAR_SYSMON_0_INCLUDE_INTR 1


/******************************************************************/

/* Definitions for driver UARTLITE */
#define XPAR_XUARTLITE_NUM_INSTANCES 4

/* Definitions for peripheral AXI_UARTLITE_0 */
#define XPAR_AXI_UARTLITE_0_BASEADDR 0x42C00000
#define XPAR_AXI_UARTLITE_0_HIGHADDR 0x42C0FFFF
#define XPAR_AXI_UARTLITE_0_DEVICE_ID 0
#define XPAR_AXI_UARTLITE_0_BAUDRATE 9600
#define XPAR_AXI_UARTLITE_0_USE_PARITY 0
#define XPAR_AXI_UARTLITE_0_ODD_PARITY 0
#define XPAR_AXI_UARTLITE_0_DATA_BITS 8


/* Definitions for peripheral AXI_UARTLITE_1 */
#define XPAR_AXI_UARTLITE_1_BASEADDR 0x42C10000
#define XPAR_AXI_UARTLITE_1_HIGHADDR 0x42C1FFFF
#define XPAR_AXI_UARTLITE_1_DEVICE_ID 1
#define XPAR_AXI_UARTLITE_1_BAUDRATE 9600
#define XPAR_AXI_UARTLITE_1_USE_PARITY 0
#define XPAR_AXI_UARTLITE_1_ODD_PARITY 0
#define XPAR_AXI_UARTLITE_1_DATA_BITS 8


/* Definitions for peripheral AXI_UARTLITE_2 */
#define XPAR_AXI_UARTLITE_2_BASEADDR 0x42C20000
#define XPAR_AXI_UARTLITE_2_HIGHADDR 0x42C2FFFF
#define XPAR_AXI_UARTLITE_2_DEVICE_ID 2
#define XPAR_AXI_UARTLITE_2_BAUDRATE 9600
#define XPAR_AXI_UARTLITE_2_USE_PARITY 0
#define XPAR_AXI_UARTLITE_2_ODD_PARITY 0
#define XPAR_AXI_UARTLITE_2_DATA_BITS 8


/* Definitions for peripheral AXI_UARTLITE_3 */
#define XPAR_AXI_UARTLITE_3_BASEADDR 0x42C30000
#define XPAR_AXI_UARTLITE_3_HIGHADDR 0x42C3FFFF
#define XPAR_AXI_UARTLITE_3_DEVICE_ID 3
#define XPAR_AXI_UARTLITE_3_BAUDRATE 9600
#define XPAR_AXI_UARTLITE_3_USE_PARITY 0
#define XPAR_AXI_UARTLITE_3_ODD_PARITY 0
#define XPAR_AXI_UARTLITE_3_DATA_BITS 8


/******************************************************************/

/* Canonical definitions for peripheral AXI_UARTLITE_0 */
#define XPAR_UARTLITE_0_DEVICE_ID XPAR_AXI_UARTLITE_0_DEVICE_ID
#define XPAR_UARTLITE_0_BASEADDR 0x42C00000
#define XPAR_UARTLITE_0_HIGHADDR 0x42C0FFFF
#define XPAR_UARTLITE_0_BAUDRATE 9600
#define XPAR_UARTLITE_0_USE_PARITY 0
#define XPAR_UARTLITE_0_ODD_PARITY 0
#define XPAR_UARTLITE_0_DATA_BITS 8

/* Canonical definitions for peripheral AXI_UARTLITE_1 */
#define XPAR_UARTLITE_1_DEVICE_ID XPAR_AXI_UARTLITE_1_DEVICE_ID
#define XPAR_UARTLITE_1_BASEADDR 0x42C10000
#define XPAR_UARTLITE_1_HIGHADDR 0x42C1FFFF
#define XPAR_UARTLITE_1_BAUDRATE 9600
#define XPAR_UARTLITE_1_USE_PARITY 0
#define XPAR_UARTLITE_1_ODD_PARITY 0
#define XPAR_UARTLITE_1_DATA_BITS 8

/* Canonical definitions for peripheral AXI_UARTLITE_2 */
#define XPAR_UARTLITE_2_DEVICE_ID XPAR_AXI_UARTLITE_2_DEVICE_ID
#define XPAR_UARTLITE_2_BASEADDR 0x42C20000
#define XPAR_UARTLITE_2_HIGHADDR 0x42C2FFFF
#define XPAR_UARTLITE_2_BAUDRATE 9600
#define XPAR_UARTLITE_2_USE_PARITY 0
#define XPAR_UARTLITE_2_ODD_PARITY 0
#define XPAR_UARTLITE_2_DATA_BITS 8

/* Canonical definitions for peripheral AXI_UARTLITE_3 */
#define XPAR_UARTLITE_3_DEVICE_ID XPAR_AXI_UARTLITE_3_DEVICE_ID
#define XPAR_UARTLITE_3_BASEADDR 0x42C30000
#define XPAR_UARTLITE_3_HIGHADDR 0x42C3FFFF
#define XPAR_UARTLITE_3_BAUDRATE 9600
#define XPAR_UARTLITE_3_USE_PARITY 0
#define XPAR_UARTLITE_3_ODD_PARITY 0
#define XPAR_UARTLITE_3_DATA_BITS 8


/******************************************************************/

/* Definitions for driver UARTPS */
#define XPAR_XUARTPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_UART_1 */
#define XPAR_PS7_UART_1_DEVICE_ID 0
#define XPAR_PS7_UART_1_BASEADDR 0xE0001000
#define XPAR_PS7_UART_1_HIGHADDR 0xE0001FFF
#define XPAR_PS7_UART_1_UART_CLK_FREQ_HZ 100000000
#define XPAR_PS7_UART_1_HAS_MODEM 0


/******************************************************************/

/* Canonical definitions for peripheral PS7_UART_1 */
#define XPAR_XUARTPS_0_DEVICE_ID XPAR_PS7_UART_1_DEVICE_ID
#define XPAR_XUARTPS_0_BASEADDR 0xE0001000
#define XPAR_XUARTPS_0_HIGHADDR 0xE0001FFF
#define XPAR_XUARTPS_0_UART_CLK_FREQ_HZ 100000000
#define XPAR_XUARTPS_0_HAS_MODEM 0


/******************************************************************/

/* Definitions for driver XADCPS */
#define XPAR_XADCPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_XADC_0 */
#define XPAR_PS7_XADC_0_DEVICE_ID 0
#define XPAR_PS7_XADC_0_BASEADDR 0xF8007100
#define XPAR_PS7_XADC_0_HIGHADDR 0xF8007120


/******************************************************************/

/* Canonical definitions for peripheral PS7_XADC_0 */
#define XPAR_XADCPS_0_DEVICE_ID XPAR_PS7_XADC_0_DEVICE_ID
#define XPAR_XADCPS_0_BASEADDR 0xF8007100
#define XPAR_XADCPS_0_HIGHADDR 0xF8007120


/******************************************************************/

/* Xilinx FAT File System Library (XilFFs) User Settings */
