/* ========================================
 *
 * Jay Lin
 * Copyright ALCH3MY, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF ALCH3MY.
 *
 * ========================================
*/
#include <project.h>
#include <math.h>
#include <resources.h>


int filter1_ready = 0;
int filter2_ready = 0;

//PID variables
unsigned long lastTime;
int Input, Output, Setpoint;
int errSum, lastErr;
int kp, ki, kd;
int timeChange = 25;


CY_ISR(filter_ready1_handler) 
{
    i2cbuf[0] = filtermem1[DECIMATION - 1] >> 8;
    i2cbuf[1] = filtermem1[DECIMATION - 1];
    //VDAC2_SetValue(filtermem1[DECIMATION - 1] >> 6);
    filter1_ready = 1;
}

CY_ISR(filter_ready2_handler) 
{
    i2cbuf[2] = filtermem2[DECIMATION - 1] >> 8;
    i2cbuf[3] = filtermem2[DECIMATION - 1];
    //VDAC4_SetValue(filtermem2[DECIMATION - 1] >> 6);
    filter2_ready = 1;
}

CY_ISR(spi_rx_handler)
{
    VDAC2_SetValue(spimem[0]);
    Setpoint = spimem[0] << 6;
}

void Compute()
{
    /*Compute all the working error variables*/
    int error = Setpoint - Input;
    errSum += (error * timeChange);
    int dErr = error - lastErr;

    /*Compute PID Output*/
    Output = kp * error + ki * errSum + kd * dErr;
    if (Output >= 8192+1024) Output = 8192+1024;
    if (Output <= 8192-1024) Output = 8192-1024;
}
  
void SetTunings(int Kp, int Ki, int Kd)
{
   kp = Kp;
   ki = Ki;
   kd = Kd;
}

void start_interrupts()
{
    isr_filter_ready1_StartEx(filter_ready1_handler);
    isr_filter_ready2_StartEx(filter_ready2_handler);
    isr_spi_rx_StartEx(spi_rx_handler);
    
    SPIS_EnableRxInt();
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    start_resources();
    start_DMAs();
    start_interrupts();
    
    SetTunings(32, 0, 32);
    
    for(;;)
    {
        if(filter1_ready){
            
            Input = filtermem1[0];
            Compute();
            
            VDAC1_SetValue(Output >> 6);
            VDAC4_SetValue(filtermem1[0] >> 6);
            
            filter1_ready = 0;
        }

    }
}

