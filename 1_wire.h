
#ifndef _1_WIRE_H_
#define _1_WIRE_H_
//Incluye la librería del pic para asignar el pin al bus
//en este caso es el PIC24FJ64GA002 perompuede ser utilizado
//en otros PICs
#include <p24FJ64GA002.h>
#ifndef FCY
#define FCY 4000000UL
    #warning no se ha definido la frecuencia del oscilador
#endif
#include <libpic30.h>

// UART Configuration
#define UART_SET_RESET_BAUD 9600        // Low baud rate for set reset pulse
#define UART_READ_WRITE_BAUD 115200     // High baud rate for data transfer
#define T_REC_US 2                      // Used to set delay timer between transmitted bits. Min recommended is 1 no maximum

// 1-Wire UART Definitions
#define RESET_LOW 0xF0                  // Write low for >480us then high for >480us
#define READ_HIGH 0xFF                  // Master will read 0xFF if the slave sends high
#define READ_LOW_MAX 0xFE               // Master will read 0xFE down to 0x00 if the slave sends low
#define WRITE_HIGH 0xFF
#define WRITE_LOW 0x00

//define pin assignments
#define _1W_TRIS TRISBbits.TRISB15
#define _1W_PIN  PORTBbits.RB15
#define _1W_LAT  LATBbits.LATB15


unsigned char  read_bit_1w();
void write_1_1w();
void write_0_1w();
unsigned char reset_1w();
void write_byte_1w(unsigned char data);
void read_n_bytes_1w(unsigned char nBytes, unsigned char* dst);

#endif