// hardware connection:
// servo (lower) orange wire -> PD0
// servo (lower) red wire -> V Bus
// servo (lower) brown wire -> GND

// servo (upper) orange wire -> PD1 (recommended)
// servo (upper) red wire -> V Bus
// servo (upper) brown wire -> GND

// What you need to do:
// 2. try to control the servos with your computer
//    (you are recommended to use UART to communicate with PC and get values to control the servo.)
// 3. think about how to control two servos with the PWM (try to implement it). done

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/pwm.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"

#define PWM_FREQUENCY 55

int main()
{
    //ui8Adjust is used to contol the servo angle.
    //We initialize ui8Adjust to 83 to make sure the servo is at the center position.
    volatile uint32_t ui32Load;
    volatile uint32_t ui32PWMClock;
    volatile uint32_t ui8Adjust;
    ui8Adjust = 83;

    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
    SysCtlPWMClockSet(SYSCTL_PWMDIV_64);

    /**
     *
     */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    GPIOPinConfigure(GPIO_PD0_M1PWM0);
    GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN |
            PWM_GEN_MODE_NO_SYNC);

    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, 40000);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    GPIOPinConfigure(GPIO_PD1_M1PWM1);
    GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_1);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN |
            PWM_GEN_MODE_NO_SYNC);

    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, 40000);

    // Enable PWM1 to generate PWM signals
    // Enable GPIOD to output signals to servo
    // Enable GPIOF to use buttons
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // set GPIOs for buttons
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR)  |= 0x01;
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
    GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_DIR_MODE_IN);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);


    ui32PWMClock = SysCtlClockGet()/64;
    ui32Load = (ui32PWMClock / PWM_FREQUENCY) - 1;
    PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, ui32Load);

    PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, ui32Load);


    // set the servo's initial position
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load/1000);
    PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);
    PWMGenEnable(PWM1_BASE, PWM_GEN_0);
    /**
     *  PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,
        PWMGenPeriodGet(PWM1_BASE, PWM_GEN_0) / divfact);


        PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);
        PWMGenEnable(PWM1_BASE, PWM_GEN_0);
     */


    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, ui8Adjust * ui32Load/1000);
    PWMOutputState(PWM1_BASE, PWM_OUT_1_BIT, true);
    PWMGenEnable(PWM1_BASE, PWM_GEN_0);

    while(1)
    {
       // Check whether the button is pressed
       if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4)==0x00)
       {
           ui8Adjust--;
           if(ui8Adjust < 26) // set the working zone from -90 to 90
           {
               ui8Adjust = 26;
           }
           PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load/1000);
           PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, ui8Adjust * ui32Load/1000);
       }

       // Check whether the button is pressed
       if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)==0x00)
       {
           ui8Adjust++;
           if(ui8Adjust > 141) // set the working zone
           {
               ui8Adjust = 141;
           }
           PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust * ui32Load/1000);
           PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, ui8Adjust * ui32Load/1000);
       }

       // since the main controlling function is implemented in while loop
       // we need to use delay function to control the rotating speed of the servo.
       SysCtlDelay(100000);
    }

}