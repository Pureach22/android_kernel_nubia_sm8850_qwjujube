__int64 __fastcall wcd_usbss_set_ovp_threshold(int a1)
{
  __int64 result; // x0
  __int64 v3; // [xsp+8h] [xbp-28h] BYREF
  __int64 v4; // [xsp+10h] [xbp-20h] BYREF
  __int64 v5; // [xsp+18h] [xbp-18h] BYREF
  __int64 v6; // [xsp+20h] [xbp-10h]
  __int64 v7; // [xsp+28h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 30;
  v6 = 33;
  v3 = 0x7F00000063LL;
  v4 = 0x7700000063LL;
  if ( a1 == 4 )
    wcd_usbss_register_update(&v4, 1, 1);
  wcd_usbss_register_update(&v5, 0, 2);
  HIDWORD(v5) = HIDWORD(v5) & 0xFFFFFFF1 | (2 * a1);
  HIDWORD(v6) = HIDWORD(v6) & 0xFFFFFFF1 | (2 * a1);
  result = wcd_usbss_register_update(&v5, 1, 2);
  if ( a1 == 6 )
    result = wcd_usbss_register_update(&v3, 1, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
