__int64 __fastcall vi530x_write_reg_offset(__int64 a1, char a2, char a3, char a4)
{
  __int64 result; // x0
  _BYTE v5[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = a4;
  result = vi530x_i2c_write(a1, a3 + a2, v5, 1u);
  _ReadStatusReg(SP_EL0);
  return result;
}
