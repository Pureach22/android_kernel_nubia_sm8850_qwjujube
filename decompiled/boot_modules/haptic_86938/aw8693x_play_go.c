__int64 __fastcall aw8693x_play_go(__int64 a1, char a2)
{
  char v3; // w20
  __int64 result; // x0
  char v5[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
    v3 = 1;
  else
    v3 = 2;
  printk(&unk_14720, "haptic_hv", 471, "aw8693x_play_go");
  v5[0] = v3;
  result = i2c_w_bytes(a1, 9, v5, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
