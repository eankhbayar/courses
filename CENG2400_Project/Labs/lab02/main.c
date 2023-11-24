
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"

uint8_t ui8PinData=2;
int32_t ButtonState = 0;
int32_t timer = 2000000;
int32_t Switch2State = 0;
int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

    // direct register
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;

    // Read the state of SW1 from PF4
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0);
    // Since the button needs some sort of pull-up, we set pin4 as weak pull-up (WPU)
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);



    while(1)
    {
        ButtonState = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4);
        Switch2State = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);
        if(Switch2State == GPIO_PIN_0){
            timer = 2000000;
        }else{
            timer = 1000000;
        }
        if (ButtonState == GPIO_PIN_4) {
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 2);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x00);
        }
        else {
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, ui8PinData);
            SysCtlDelay(timer);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x00);
            SysCtlDelay(timer);
            if(ui8PinData==8) {ui8PinData=2;} else {ui8PinData=ui8PinData*2;}
//            if(ui8PinData == 14) {ui8PinData = 0;} else {ui8PinData = 14;}
        }
    }
}
