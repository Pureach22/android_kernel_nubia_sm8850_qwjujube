__int64 __fastcall vi530x_write_byte(__int64 a1, __int64 a2, char a3)
{
  __int64 result; // x0
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = a3;
  result = vi530x_i2c_write(a1, a2, v4, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
