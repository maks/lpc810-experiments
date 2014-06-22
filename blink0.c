/*
BLINK0:
  A minimal "Blinky" for NXP-LPC810 miniboard
  A single-file example using only out-of-the-box arm-gcc compiler and no crt0
  Using default reset state values for everything
  Pressing the ISP button will change blink rate
  WARN: due to missing crt0 - no init of data/bss (see blink1 ;) )
*/

typedef unsigned int volatile * vp;

void main()
{
  *(vp)0x4000c1c0 = 0xffffffbfUL;		// PINENABLE0 (disable SWclk/dio)
  *(vp)0xa0002000 |= (1 << 2);			// DIR0 (set pinio-2 to output)
  for (;;)
  {
    *(vp)0xa0002100 ^= (1 << 2);		// PIN0 - toggle LED

    // Some busy loop waiting...
    volatile long vaste = *(vp)0xa0002100 & (1 << 1) ? 250000 : 50000;	// PIN0 (fast blink when ISP pressed)
    while (vaste > 0) --vaste;
  }
}

typedef void (*irqhandler)();
extern void __StackTop();
__attribute__ ((section(".isr_vector")))
irqhandler irqhandlers[48] = {
  &__StackTop,	// Stack top defined by linker-script
  main,		// The reset handler
  0		// ... and 45 more blank interrupt handlers
};
