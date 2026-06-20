__int64 sub_17122C()
{
  __asm { PRFM            #0x1F, [X10,#0x7D0] }
  return ipa_usb_xdci_suspend();
}
