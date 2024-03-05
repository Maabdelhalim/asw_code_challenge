# AAC-Clydespace Avionics Software Challenge
You are given the LIS3MDLTR 3-Axis Magnetometer sensor. The data sheet is
located at `doc/lism3mdl.pdf`

## Task Description
You must use the C API defined in `i2c.h` to operate on an I2C bus.

We provide example stub implementations of this API in `i2c.c`. You are free to
extend the provided stub functions for the API.

Please write a device driver that implements the following API:
- Get the full-scale configuration
- Get and set the output data rate
- Enable or disable the interrupt pin
- Read the output data of a specified axis

## Development
You are provided this minimal repository, `aac-code-challenge`, please perform
your work on branch `<candidate_name>`

Documentation can be found in `aac-code-challenge/doc`

Once complete, please repackage and email back this repo to your interviewers

## Scope
You shouldn't need to spend more than a couple of hours on the task.

This is not a closed book assessment.

## Extra Thoughts
If you have time, answer the following questions:
- What changes you would make to this interfaces for use in an RTOS
environment?
    - Handling System Tasks According to the Following:
        - Create two tasks one for sensor communication and the 2nd task for measurement processing where the two tasks will have-inter task communication.
        - Communication task will be invoked by interrupt context when new generation occurs, then after communication task finishes, will invoke metering task to process readings.
        - Use circular queue per every magnetometer instance to handled processing multiple readings if continuous mode is configured assuming data reading rate is higher than processing rate.
        - Measurement data shall be protected during reading or writing by critical sections using semaphores or mutex.


- How might the I2C API be improved
    - I- Add Bus Busy Error handling that may occurs if there are multi master multi-slave when two masters are trying to hold the bus at the same time or when another master is busy communicating with a salve

    - II- Add Timeout Error handling because of the following reasons might occur:
        - 1-	clock stretching due to salve that device holding the SCL line low to pause bus communication to allow more time to handle data or prepare a response for the master device
        - 2-	In the case of multi master multi-slave, bits arbitration takes place on the bus that might delays repones from master

    - II- Avoid I2C Addresss conflict between two lis3mdl sensors:
        - To avoid I2C addresses conflict between two lis3mdl magnetometer sensors, we can change configurations of SDO/SA1 pin high and low to have difference I2C read and write addresses as explained in the datasheet [Table 10. SAD+read/write patterns] page 12.

