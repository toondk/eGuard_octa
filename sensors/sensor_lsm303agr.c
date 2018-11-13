//Include driver and driver parameters
#include "sensor_lsm303agr.h"

//initialize and enable device using the parameters in the header
int init_lsm303agr(LSM303AGR_t* dev)
{   
    int res = LSM303AGR_init(dev, &LSM303AGR_params[0]);
    res += LSM303AGR_enable(dev);
    res += LSM303AGR_enable_interrupt(dev);
    if (res == 0){
        puts("Initialized LSM303AGR\n");
    } else {
        puts("Initializing LSM303AGR FAILED");
    }
    return 0;
}

//Read the current state of the accelerometer
//check tests folder for use of the drivers! 
int read_lsm303agr(LSM303AGR_t* dev)
{
    LSM303AGR_3d_data_t acc_value;
    LSM303AGR_read_acc(dev, &acc_value);
    if (LSM303AGR_read_acc(dev, &acc_value) == 0) {
        printf("Accelerometer x: %i y: %i z: %i\n", 
        acc_value.x_axis,
        acc_value.y_axis,
        acc_value.z_axis);
    }
    else {
        puts("\nFailed reading accelerometer values\n");
    }

    LSM303AGR_3d_data_t mag_value;
    if (LSM303AGR_read_mag(dev, &mag_value) == 0) {
        printf("Magnetometer x: %i y: %i z: %i\n", mag_value.x_axis,
        mag_value.y_axis,
        mag_value.z_axis);
    }
    else {
        puts("\nFailed reading magnetometer values\n");
    }

    return 0;
}


void cb_lsm1(void *arg)
{
    if (arg != NULL) {
        //do something?
    }
    //int8_t value;
    //if(LSM303AGR_clear_int(&dev, &value) == 0){
    //    puts("Interrupt cleared");
    //}

    printf("Fall Detected INT1!\n");
}


void Configure_Interrupt_lsm303agr(void) {
    gpio_init_int(GPIO_PIN(PORT_B, 13),GPIO_IN,GPIO_RISING, cb_lsm1, (void*) 0); //INT_1 from lsm303agr
    gpio_irq_enable(GPIO_PIN(PORT_B, 13));
}


