// Tristan Caja 10/9/2020
#include <msp430g2553.h>

int counter = 0;

int main(void) {
    WDTCTL = WDTPW + WDTHOLD;

    P1DIR |= 0x07;
    P1OUT = 0x30;

    P1REN |= 0x30;

    P1IE |= 0x30;
    P1IES |= 0x30;

    P1IFG &= ~0x30;
    __bis_SR_register(LPM4_bits + GIE);

}

#pragma vector=PORT1_VECTOR
__interrupt void Port1() {
    if (counter % 3 == 0 || counter % 3 == 1) {
        P1OUT ^= BIT1;
        P1IFG &= ~0x30;
        counter++;
    }
    else {

        P1OUT ^= BIT2;
        P1IFG &= ~0x30;
        counter++;
    }
}