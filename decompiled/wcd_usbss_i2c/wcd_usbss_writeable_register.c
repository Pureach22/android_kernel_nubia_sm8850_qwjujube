__int64 __fastcall wcd_usbss_writeable_register(__int64 a1, unsigned int a2)
{
  if ( !a2 )
    return 0;
  if ( a2 >= 0x4EC )
  {
    __break(0x5512u);
    JUMPOUT(0xFFFFFFFFFF174EA8LL);
  }
  return (wcd_usbss_reg_access[a2] >> 1) & 1;
}
