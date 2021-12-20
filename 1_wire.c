#include "1_wire.h"


/**
 * @brief Set UART baud rate depending on timings required
 * @param handle - UART handle
 * @param speed - 0 for slow baud, 1 for fast baud
 */
void uart_set_baud(int *handle, uint32_t speed)
{
    if ( speed == 0 )
    {
        // Set given uart to set/reset baud rate
        int baud = UART_SET_RESET_BAUD;

    }
    else if ( speed == 1 )
    {
        // Set given uart to read/write baud rate
        int baud = UART_READ_WRITE_BAUD; 
    }
}



/**
 * Read 1 bit on 1-wire bus
 * @return Bit read
 */
unsigned char read_bit_1w()
{
    unsigned char data;
    _1W_TRIS=0;
    _1W_LAT=0;
    __delay_us(6);
    _1W_LAT=1;
    _1W_TRIS=1;
    __delay_us(9);
    data=_1W_PIN;
    __delay_us(55);
    return data;
}

/**
 * Write logic 0 to bus
 */
void write_0_1w()
{
    _1W_TRIS=0; //Configure pin as output
    _1W_LAT=0;
    __delay_us(60);
    _1W_LAT=1;
    //_1W_TRIS=1; //Free bus
    __delay_us(10);
}

/**
 * Write logic 1 to bus
 */
void write_1_1w()
{
    _1W_TRIS=0;
    _1W_LAT=0;
    __delay_us(6);
    _1W_LAT=1;
    //_1W_TRIS=1;
    __delay_us(64);
}

/**
 * Write start pulse to bus and wait for slave response
 * Baud rate of 9600 is used 
 * @return 0 if slave presence is confirmed, 1 if no slave response
 */
unsigned char reset_1w()
{
    unsigned char presence;
    _1W_TRIS=0;
    _1W_LAT=0;
    __delay_us(480);
    _1W_LAT=1;
    _1W_TRIS=1; //Configure pin as input and free bus
    __delay_us(100);
    presence=_1W_PIN;
    __delay_us(410);
    //_1W_TRIS=0; //Configure pin as output
    return presence;
}

/**
 * Write a byte to the bus
 * @param data - Data to be sent on bus
 */
void write_byte_1w(unsigned char data)
{
    unsigned char i=0;
    for(i=0;i<8;i++)
    {
        if(i>0)
            data>>=1;
    if(data & 1)
        write_1_1w();
    else
        write_0_1w();
    }
}
/**
 * Read requested number of bytes on bus
 * @param nBytes - Number of bytes to be read
 * @param dst - Pointer to where data should be written
 */
void read_n_bytes_1w(unsigned char nBytes, unsigned char* dst)
{
    unsigned char read=0,i=0,j=0;

    for(i=0;i<nBytes;i++)
    {
        for(j=0;j<8;j++)
        {
            read+=read_bit_1w()<<j;
        }
        *dst=read;
        dst++;
        read=0;
    }
}
