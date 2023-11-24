#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"

int delay=500000;
int color=GPIO_PIN_1;

void GPIO_PORtF_Handler(void);
void Timer0IntHandler(void);

int main(void)
{
    uint32_t ui32Period;

    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4) ;       // PF4 input
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
    GPIOIntEnable(GPIO_PORTF_BASE, GPIO_INT_PIN_4) ;          // interrupt enable
    GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_FALLING_EDGE) ; // low level interrupt
    GPIOIntRegister(GPIO_PORTF_BASE, GPIO_PORtF_Handler) ;     // dynamic isr registering

    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);

    ui32Period = (SysCtlClockGet()*2); // make sure the timer timeout every 2 seconds
    TimerLoadSet(TIMER0_BASE, TIMER_A, ui32Period - 1);

    IntEnable(INT_TIMER0A);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    IntMasterEnable();

    TimerEnable(TIMER0_BASE, TIMER_A);

    while(1)
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2|GPIO_PIN_1|GPIO_PIN_3, color) ;
        SysCtlDelay(delay);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2|GPIO_PIN_1|GPIO_PIN_3, 0) ;
        SysCtlDelay(delay);
    }
}


void GPIO_PORtF_Handler(void) {
    GPIOIntClear(GPIO_PORTF_BASE, GPIO_INT_PIN_4) ;
    if (delay==2000000)
    {
        delay=500000;
        return;
    }
    else
    {
        delay=delay*2;
        return;
    }
}

void Timer0IntHandler(void)
{
//    // Clear the timer interrupt
//    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
//
//    // Read the current state of the GPIO pin and
//    // write back the opposite state
//
//    if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_2))
//    {
//        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
//    }else{
//        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 4);
//    }
    // Clear the timer interrupt
        TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

        if(color == 2){
            color *= 4;
            return;
        }
        if(color == 8){
            color /= 2;
            return;
        }
        if(color == 4){
            color /= 2;
            return;
        }

}
