#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"
#include "driverlib/uart.h"
#include "inc/hw_ints.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"

void delayMs(int n)
{
    int i,j;
    for(i = 0;i < n;i++)
        for(j = 0;j < 3180; j++)
            {}
}

int main(void)
{
    uint32_t ui32ADC0Value[4];
    volatile uint32_t ui32TempAvg;
    volatile uint32_t ui32TempValueC;
    volatile uint32_t ui32TempValueF;

    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    IntMasterEnable();
    IntEnable(INT_UART0);
    UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);

    ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);

    ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_TS);
    ADCSequenceStepConfigure(ADC0_BASE, 1, 1, ADC_CTL_TS);
    ADCSequenceStepConfigure(ADC0_BASE, 1, 2, ADC_CTL_TS);

    ADCSequenceStepConfigure(ADC0_BASE,1,3,ADC_CTL_TS|ADC_CTL_IE|ADC_CTL_END);

    ADCSequenceEnable(ADC0_BASE, 1);


    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);

    while(1)
    {

       ADCIntClear(ADC0_BASE, 1);

       ADCProcessorTrigger(ADC0_BASE, 1);

       while(!ADCIntStatus(ADC0_BASE, 1, false))
       {
       }

       ADCSequenceDataGet(ADC0_BASE, 1, ui32ADC0Value);
       ui32TempAvg = (ui32ADC0Value[0] + ui32ADC0Value[1] + ui32ADC0Value[2] + ui32ADC0Value[3] + 2)/4;

       ui32TempValueC = (1475 - ((2475 * ui32TempAvg)) / 4096)/10;
       ui32TempValueF = ((ui32TempValueC * 9) + 160) / 5;

       char TempAvg[5];
       char TempC[5];
       char TempF[5];

       uint32_t tmpAvg = ui32TempAvg;
       uint32_t tmpC = ui32TempValueC;
       uint32_t tmpF = ui32TempValueF;
       int size_avg = 0;
       int size_c = 0;
       int size_f = 0;
       while(tmpAvg > 0){
           size_avg++;
           tmpAvg /= 10;
       }
       while(tmpC > 0){
           size_c++;
           tmpC/=10;
       }
       while(tmpF > 0){
           size_f++;
           tmpF/=10;
       }

       int i;

       tmpAvg = ui32TempAvg;
       tmpC = ui32TempValueC;
       tmpF = ui32TempValueF;
       for(i=size_avg-1;i>=0;i--){
           TempAvg[i] = tmpAvg%10 + '0';
           tmpAvg /= 10;
       }
       for(i=size_c-1;i>=0;i--){
           TempC[i] = tmpC%10 + '0';
           tmpC /= 10;
       }
       for(i = size_f - 1;i>=0;i--){
           TempF[i] = tmpF%10 + '0';
           tmpF /= 10;
       }

       UARTCharPut(UART0_BASE, 'A');
       UARTCharPut(UART0_BASE, 'v');
       UARTCharPut(UART0_BASE, 'g');


       UARTCharPut(UART0_BASE, ' ');
       UARTCharPut(UART0_BASE, ':');
       for(i = 0;i<size_avg;i++){
           UARTCharPut(UART0_BASE, TempAvg[i]);
       }

       UARTCharPut(UART0_BASE, '|');
       UARTCharPut(UART0_BASE, 'C');
       UARTCharPut(UART0_BASE, ':');

       UARTCharPut(UART0_BASE, ' ');
       for(i=0;i<size_c;i++){
           UARTCharPut(UART0_BASE, TempC[i]);
       }

       UARTCharPut(UART0_BASE, '|');
       UARTCharPut(UART0_BASE, 'F');
       UARTCharPut(UART0_BASE, ':');
       UARTCharPut(UART0_BASE, ' ');
       for(i = 0 ;i<size_f;i++){
           UARTCharPut(UART0_BASE, TempF[i]);
       }
       UARTCharPut(UART0_BASE, '|');
       UARTCharPut(UART0_BASE, ' ');
       delayMs(1000);
    }
}

void UARTIntHandler(void){}
