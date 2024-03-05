#include "i2c.h"

#include <stdint.h>
#include <stdio.h>


status_t I2C_sendByte(uint8_t byte)
{
    // 1- Write byte in the data register
    // 2- Wait until the transmission is complete and exit with timeout error if maximum timeout reached
    // 3- Checking sending status and receving ACK/NACK with same timeout mechanisim
    // 4- Send stop bit
    // 5- Return status
}

status_t i2c_write(
    uint8_t bus_address,
    uint8_t register_address,
    uint16_t length,
    uint8_t *buffer)
{
    status_t ret = STATUS_ERROR;
    
    printf("write [%d] bytes to bus [%d] for register [%d]\n\t", length, bus_address, register_address);

    for (size_t i = 0; i < length; ++i)
    {
        printf("%p", buffer);
    }
    printf("\n");

    // 1-Enable & Check (if Bus is not Busy) && (no active session Flag)
    // 2-If bus is busy , wait and retry or timeout and return maximum conditions reached
   
    // *---------------- START Signal----------------*/
    // 3-send I2c start singal 

    // *----------------  Send SLA + W ----------------*/
    // 4-Check Send salve address 
    I2C_sendByte(bus_address);

    // *----------------  Send SLA Register ----------------*/
    // 5-Send salve address register
    I2C_sendByte(register_address);

    // *----------------  Write Byte by byte ----------------*/
    // 6-Send byte using I2C_sendByte() API
    for (size_t i = 0; i < length; ++i)
    {
        ret = I2C_sendByte(buffer[i]);
        if (ret != STATUS_OK)
            return ret;
    }

    // 7-Clear Bus
    return STATUS_OK;
}


status_t I2C_readByte(uint8_t byte)
{
    // 1- Check flag and read byte from data register
    // 2- Wait for 1 byte timing if no data recevied and timeout reached return time out error
    // 3- Return status
}

status_t i2c_read(
    uint8_t bus_address,
    uint8_t register_address,
    uint16_t length,
    uint8_t *buffer)
{
    status_t ret = STATUS_ERROR;

    printf(
        "read [%d] bytes from bus [%d] for register [%d]\n",
        length,
        bus_address,
        register_address);

    /* Setting the output to some arbitrary value */
    for (size_t i = 0; i < length; ++i)
    {
        buffer[i] = 0xff;
    }

    // 1-Enable & Check (if Bus is not Busy) && (no active session Flag)
    // 2-If bus is busy , wait and retry or timeout and return maximum conditions reached
    
    // *---------------- START Signal----------------*/
    // 3-Send I2c start singal 

    // *---------------- START Signal----------------*/
    // 3-send I2c start singal 

    // *----------------  Send SLA + R ----------------*/
    // 4-Send salve address + Read
    I2C_sendByte(bus_address);

    // *----------------  Send SLA Register ----------------*/
    // 5-Send salve address register
    I2C_sendByte(register_address);

    // *----------------  Read Byte by byte ----------------*/
    // 6-Recevie byte byte and send ACK
    for (size_t i = 0; i < length; ++i)
    {
    ret = I2C_RecevieByte(buffer[i]);
       if(  ret != STATUS_OK)
       return ret;
    //Send ACK
    }
    // 5-Clear Bus
    return STATUS_OK;

    return STATUS_OK;
}








