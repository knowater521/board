__author__ = 'Administrator'
import usb
import usb.core
import struct
import binascii
dev=usb.core.find()
cfg = dev.get_active_configuration()
intf = cfg[(0,0)]
interface = 0
epout_IN = usb.util.find_descriptor(
    cfg[(0,0)],
    # match the first in endpoint
    custom_match = \
    lambda e: \
        usb.util.endpoint_direction(e.bEndpointAddress) == \
        usb.util.ENDPOINT_IN)
epout_OUT = usb.util.find_descriptor(
    cfg[(0,0)],
    # match the first OUT endpoint
    custom_match = \
    lambda e: \
        usb.util.endpoint_direction(e.bEndpointAddress) == \
        usb.util.ENDPOINT_OUT)
s=0x0201
k=struct.pack("l",s)
epout_OUT.write(k)
