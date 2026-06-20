__int64 __fastcall aw8693x_set_wav_seq(__int64 a1, int a2, char a3)
{
  __int64 result; // x0
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = a3;
  result = i2c_w_bytes(a1, (unsigned int)(a2 + 10), v4, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
