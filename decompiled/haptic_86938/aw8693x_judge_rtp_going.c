__int64 __fastcall aw8693x_judge_rtp_going(__int64 a1)
{
  __int64 result; // x0
  _BYTE v2[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2[0] = 0;
  i2c_r_bytes(a1, 63, v2, 1);
  result = 0;
  if ( v2[0] == 8 )
  {
    printk(&unk_16350, "haptic_hv", 1022, "aw8693x_judge_rtp_going");
    result = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
