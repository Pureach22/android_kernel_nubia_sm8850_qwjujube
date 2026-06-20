__int64 __fastcall aw8693x_rtp_get_fifo_aes(__int64 a1)
{
  _BYTE v2[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2[0] = 0;
  i2c_r_bytes(a1, 1, v2, 1);
  _ReadStatusReg(SP_EL0);
  return (v2[0] >> 4) & 1;
}
