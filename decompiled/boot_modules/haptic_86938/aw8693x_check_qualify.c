__int64 __fastcall aw8693x_check_qualify(__int64 a1)
{
  __int64 result; // x0
  _BYTE v2[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2[0] = 0;
  i2c_r_bytes(a1, 100, v2, 1);
  if ( (v2[0] & 0x80000000) != 0 )
  {
    printk(&unk_15488, "haptic_hv", 313, "aw8693x_check_qualify");
    result = 0;
  }
  else
  {
    printk(&unk_1649B, "haptic_hv", 310, "aw8693x_check_qualify");
    result = 4294967262LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
