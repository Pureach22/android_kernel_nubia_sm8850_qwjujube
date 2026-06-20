__int64 __fastcall aw8693x_get_first_wave_addr(__int64 a1, _WORD *a2)
{
  __int64 result; // x0
  _WORD v4[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v4, 0, 3);
  result = i2c_r_bytes(a1, 66, v4, 3);
  *a2 = *(_WORD *)((char *)v4 + 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
