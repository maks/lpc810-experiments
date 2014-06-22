2013-Jul-24: Lars Ole Belhage, belhage@midibel.com

This is the first of a series of experiments with the LPC810 and the gnu/linux toolchain

The first example is very (much too) simple - no crt0 and no libraries - just to show how simple it can be done!

I've used the LPC810-miniboard, an USB-to-serial cable (the FTDI TTL-232R-3V3 cable) and Fedora18

Included is also a small python script (again very simple) to flash the LPC810 (flushmagic ;) )

Steps:
  download the gcc-arm tools (I used: https://launchpad.net/gcc-arm-embedded/4.7/4.7-2013-q2-update/+download/gcc-arm-none-eabi-4_7-2013q2-20130614-linux.tar.bz2)
  unpack it (I used: tar xfj in my home-dir)
  run make in the blink0 dir
  connect the usb-cable (you will get a /dev/ttyUSBxx) serial device
    (make shure you have access-rights to the ttyUSB - on fedora: add group "dialout" to your user: usermod -G dialout 'you')
  flash the LCP810 (flushmagic.py /dev/ttyUSB0 blink0.bin)
   (remember to bring the '810 in ISP mode - on minboard: press and hold ISP-button while pressing RESET-button)
   (for fedora18 you need to install the pyserial.noarch package)
  have fun ;)

