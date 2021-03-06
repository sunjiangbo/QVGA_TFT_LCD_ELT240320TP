/* Defines the base address of the memories and peripherals */
#include "inc/hw_memmap.h"

/* Defines the common types and macros */
#include "inc/hw_types.h"

#include "inc/hw_timer.h"

#include "inc/hw_ints.h"

/* Defines and Macros for GPIO API */
#include "driverlib/gpio.h"

/* Prototypes for the system control driver */
#include "driverlib/sysctl.h"

/* ADC headers for using the ADC driver functions. */
#include "driverlib/adc.h"

/* Defines and Macros for the UART. */
#include "driverlib/uart.h"

/* Prototypes for the NVIC Interrupt Controller Driver. */
#include "driverlib/interrupt.h"

/* Prototypes for the UART console functions. */
#include "utils/uartstdio.h"

#include "IQmath/IQmathLib.h"

#include "driverlib/timer.h"

#include "driverlib/ELT240320TP.h"




void InitConsole(void)
{
	/* Enable GPIO port A which is used for UART0 pins.*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    /* Make the UART pins be peripheral controlled.*/
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    /* Initialize the UART for console I/O.*/
    UARTStdioInit(0);
}

const unsigned short smile[] =
{
	0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xF7FF,
	0x9EDE,0x869D,0x9EDE,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,
	0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,
	0xDFBF,0x6EFF,0x7F7F,0x5F9F,0x679F,0x575F,0x773F,0x6EBE,
	0xDF9F,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,
	0xFFFF,0xFFFF,0x76DE,0x97BF,0x679F,0x679F,0x679F,0x5F9F,
	0x679F,0x4F3F,0x4F3F,0x875F,0xAF1E,0xFFFF,0xFFFF,0xFFFF,
	0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x773F,0x679F,0x679F,0x679F,
	0x679F,0x679F,0x679F,0x5F9F,0x5F9F,0x4F3F,0x3EBF,0x3EBF,
	0x5E3D,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x6EFF,0x679F,
	0x5F9F,0x5F9F,0x5F9F,0x5F9F,0x679F,0x679F,0x679F,0x5F9F,
	0x4F3F,0x4F3F,0x3EBF,0x3EBF,0xA6DE,0xFFFF,0xFFFF,0xFFFF,
	0xDFBF,0x979F,0x679F,0x5F9F,0x032F,0x032F,0x5F9F,0x679F,
	0x679F,0x679F,0x5F9F,0x032F,0x032F,0x3EBF,0x46FF,0x6EBE,
	0xD75E,0xFFFF,0xFFFF,0x6EFF,0x679F,0x679F,0x032F,0x5F9F,
	0x5F9F,0x032F,0x679F,0x679F,0x679F,0x032F,0x5F9F,0x4F3F,
	0x032F,0x3EBF,0x3EBF,0x459B,0xFFFF,0xFFFF,0x875F,0x679F,
	0x679F,0x032F,0x5F9F,0x5F9F,0x032F,0x679F,0x679F,0x5F9F,
	0x032F,0x5F9F,0x4F3F,0x032F,0x3EBF,0x3EBF,0x5E3D,0xFFFF,
	0x9EFE,0x577F,0x679F,0x0476,0x5F9F,0x5F9F,0x5F9F,0x5F9F,
	0x679F,0x5F9F,0x5F9F,0x5F9F,0x5F9F,0x5F9F,0x5F9F,0x0476,
	0x365F,0x361E,0x8DD9,0x869D,0x577F,0x0476,0x679F,0x5F9F,
	0x5F9F,0x5F9F,0x5F9F,0x5F9F,0x5F9F,0x577F,0x5F9F,0x4F3F,
	0x4F3F,0x3EBF,0x3EBF,0x0476,0x361E,0x759A,0x9EDE,0x575F,
	0x577F,0x5F9F,0x0476,0x0476,0x2D7B,0x2D7B,0x361E,0x361E,
	0x361E,0x2D7B,0x2D7B,0x0476,0x0476,0x365F,0x365F,0x2DDD,
	0x8DD9,0xD77F,0x3EBF,0x577F,0x0476,0xFFFF,0xFFFF,0xEF7D,
	0xEF7D,0xE71C,0xE71C,0xE71C,0xEF7D,0xEF7D,0xFFFF,0xEF7D,
	0x0476,0x361E,0x2D7B,0xD71D,0xFFFF,0x76BF,0x0476,0xFFFF,
	0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xEF7D,0xEF7D,0xEF7D,0xFFFF,
	0xFFFF,0xFFFF,0xEF7D,0xEF7D,0x0476,0x4539,0xFFFF,0xFFFF,
	0xD77E,0x0476,0xFFFF,0xFFFF,0xFFFF,0xC618,0xFFFF,0xFFFF,
	0xC618,0xFFFF,0xFFFF,0xC618,0xFFFF,0xEF7D,0xEF7D,0x0476,
	0xA63A,0xFFFF,0xFFFF,0xFFFF,0x0476,0xFFFF,0xFFFF,0xC618,
	0xC618,0xC618,0xC618,0xC618,0xC618,0xC618,0xC618,0xC618,
	0xEF7D,0xEF7D,0x4CD8,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,
	0x0476,0xFFFF,0xFFFF,0xC618,0xFFFF,0xFFFF,0xC618,0xFFFF,
	0xFFFF,0xC618,0xEF7D,0xEF7D,0x4539,0xF7DF,0xFFFF,0xFFFF,
	0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x0476,0xFFFF,0xFFFF,0xFFFF,
	0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xEF7D,0xEF7D,0x4CD8,0xF7DF,
	0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,
	0x0476,0x0476,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x4539,
	0xA63A,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,
	0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0x0476,0x0476,0x0476,
	0x0476,0x0476,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,
	0xFFFF};



int main(void)
{
	/* FIFO Buffer */
	unsigned long temp[1];

	/*Set the clocking to directly run from the crystal at 50MHz*/
	SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);

	/*Enable ADC Peripheral*/
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);


	/* Set the clock for the GPIO Port A,B,C,D */
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

	/* Set the type of the GPIO Pin */
	GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5);
	GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
	GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_4);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0);

	TSLCDRst();
    TSLCDInit();

    setBitBL;

	TSLCDFillRect(0,TS_SIZE_X-1,0,TS_SIZE_Y-1,TS_COL_YELLOW,TS_MODE_NORMAL);
    TSLCDFillRect(0,TS_SIZE_X-1,120,160,TS_COL_RED,TS_MODE_NORMAL);
    TSLCDFillRect(0,TS_SIZE_X-1,80,120,TS_COL_PURPLE,TS_MODE_NORMAL);

    TSLCDSetFontColor(TS_COL_GREEN);
	TSLCDPrintStr(6,0,"                CEDT, NSIT      ",TS_MODE_NORMAL);
	TSLCDPrintStr(8,0,"              Stellaris Guru     ",TS_MODE_NORMAL);
	TSLCDShowPic(147,165,208,226,smile,TS_MODE_FULL);

 	while(1)

    {

    }
}
