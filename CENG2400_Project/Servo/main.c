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

int initial_state = 0;

// xxx yyy zzz

// x is the pitch angle
// y is the roll angle
// z is the yaw angle
volatile uint32_t x_val = 83;
volatile uint32_t y_val = 83;
volatile uint32_t z_val = 83;

void init_servo(volatile uint32_t ui8Adjust_horizontal, volatile uint32_t ui8Adjust_vertical){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    GPIOPinConfigure(GPIO_PD0_M1PWM0);
    GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN |
            PWM_GEN_MODE_NO_SYNC);

    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, 40000);

    // Enable PWM1 to generate PWM signals
    // Enable GPIOD to output signals to servo
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    GPIOPinConfigure(GPIO_PD1_M1PWM1);
    GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_1);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN |
            PWM_GEN_MODE_NO_SYNC);

    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, 40000);


    ui32PWMClock = SysCtlClockGet()/64;
    ui32Load = (ui32PWMClock / PWM_FREQUENCY) - 1;
    PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, ui32Load);

    PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, ui32Load);
    
    // set the servo's initial position
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust_horizontal * ui32Load/1000);
    PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);
    PWMGenEnable(PWM1_BASE, PWM_GEN_0);

    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, ui8Adjust_vertical * ui32Load/1000);
    PWMOutputState(PWM1_BASE, PWM_OUT_1_BIT, true);
    PWMGenEnable(PWM1_BASE, PWM_GEN_0);
}

void init_uart(){
    // enable UART5 and GPIOE
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART5);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);

    // Configure board PE4 for RX
    // configure board PE5 for TX
    GPIOPinConfigure(GPIO_PE4_U5RX);
    GPIOPinConfigure(GPIO_PE5_U5TX);
    // set PORTE pin4 and pin5 as UART type
    GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);

    // set UART base addr., system clock, baud rate
    // used to communicate with HC-05
    UARTConfigSetExpClk(UART5_BASE, SysCtlClockGet(), 38400,
        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
    
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2|GPIO_PIN_1|GPIO_PIN_3, 2) ;

    // set interrupt for receiving and showing values
    IntMasterEnable();
    IntEnable(INT_UART5);
    UARTIntEnable(UART5_BASE, UART_INT_RX | UART_INT_RT);
}

int main()
{
    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
    SysCtlPWMClockSet(SYSCTL_PWMDIV_64);

    //ui8Adjust is used to contol the servo angle.
    //We initialize ui8Adjust to 83 to make sure the servo is at the center position.
    volatile uint32_t ui32Load;
    volatile uint32_t ui32PWMClock;
    volatile uint32_t ui8Adjust_horizontal, ui8Adjust_vertical;
    ui8Adjust_horizontal = 83;
    ui8Adjust_vertical = 83;

    if(initial_state == 0){
        init_servo(ui8Adjust_horizontal, ui8Adjust_vertical);
        initial_state = 1;
    }

    init_uart();


    // Enable GPIOF to use buttons
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    
    // set GPIOs for buttons
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR)  |= 0x01;
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
    GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_DIR_MODE_IN);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    
    /**
     *  PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,
        PWMGenPeriodGet(PWM1_BASE, PWM_GEN_0) / divfact);


        PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);
        PWMGenEnable(PWM1_BASE, PWM_GEN_0);
     */

    while(1)
    {

        // move the servo to the value
        if(ui8Adjust_horizontal < x_val){
            ui8Adjust_horizontal++;

            if(ui8Adjust_horizontal > 141) // set the working zone
            {
                ui8Adjust_horizontal = 141;
            }
            PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust_horizontal * ui32Load/1000);
            PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, ui8Adjust_horizontal * ui32Load/1000);
        }
        else if(ui8Adjust_horizontal > x_val){
            ui8Adjust_horizontal--;

            if(ui8Adjust_horizontal < 26) // set the working zone from -90 to 90
            {
                ui8Adjust_horizontal = 26;
            }
            PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust_horizontal * ui32Load/1000);
            PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, ui8Adjust_horizontal * ui32Load/1000);
        }

        if(ui8Adjust_vertical < y_val){
            ui8Adjust_vertical++;

            if(ui8Adjust_vertical > 141) // set the working zone
            {
                ui8Adjust_vertical = 141;
            }
            PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust_vertical * ui32Load/1000);
            PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, ui8Adjust_vertical * ui32Load/1000);
        }
        else if(ui8Adjust_vertical > y_val){
            ui8Adjust_vertical--;

            if(ui8Adjust_vertical < 26) // set the working zone from -90 to 90
            {
                ui8Adjust_vertical = 26;
            }
            PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, ui8Adjust_vertical * ui32Load/1000);
            PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, ui8Adjust_vertical * ui32Load/1000);
        }

       // since the main controlling function is implemented in while loop
       // we need to use delay function to control the rotating speed of the servo.
       SysCtlDelay(100000);
    }
}

//check whether there are any items in the FIFO of UART5.
//get characters from UART5 that communicates with bluetooth.
//format the received data and change the servo angle.
// R xxx yyy zzz x
void UART5IntHandler(void)
{
    uint32_t ui32Status;

    ui32Status = UARTIntStatus(UART5_BASE, true); //get interrupt status

    UARTIntClear(UART5_BASE, ui32Status); //clear the asserted interrupts

    while(UARTCharsAvail(UART5_BASE)) //loop while there are chars
    {
        char c = UARTCharGet(UART5_BASE);
        if(c == 'R'){
            char x[3], y[3], z[3];
            int i = 0;
            int space_count = 0;
            char temp = UARTCharGet(UART5_BASE);
            while(temp != 'x'){
                if(temp == ' '){
                    space_count++;
                    i = 0;
                }
                else{
                    if(space_count == 0){
                        x[i] = temp;
                    }
                    else if(space_count == 1){
                        y[i] = temp;
                    }
                    else if(space_count == 2){
                        z[i] = temp;
                    }
                    i++;
                }
                temp = UARTCharGet(UART5_BASE);
                SysCtlDelay(SysCtlClockGet() / (1000 * 3)); //delay some time
            }
            x_val = atoi(x);
            y_val = atoi(y);
            z_val = atoi(z);
        }
        // UARTCharPut(UART0_BASE, UARTCharGet(UART5_BASE)); //echo character
    }
}