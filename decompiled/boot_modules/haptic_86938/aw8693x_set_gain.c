__int64 __fastcall aw8693x_set_gain(__int64 a1, char a2)
{
  __int64 result; // x0
  _BYTE v3[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = a2;
  result = i2c_w_bytes(a1, 7, v3, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
