__int64 __fastcall qcusb_emu_phy_remove(__int64 a1)
{
  return usb_remove_phy(*(_QWORD *)(a1 + 168));
}
