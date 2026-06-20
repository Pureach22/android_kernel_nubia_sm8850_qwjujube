__int64 __fastcall sub_17005C(__int64 a1, int a2)
{
  if ( (a2 & 0x80000) != 0 )
    JUMPOUT(0x169FC8);
  return hif_bus_get_device_handle();
}
