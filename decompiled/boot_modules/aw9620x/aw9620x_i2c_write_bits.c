__int64 __fastcall aw9620x_i2c_write_bits(__int64 a1, unsigned __int16 a2, int a3, unsigned int a4)
{
  __int64 result; // x0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  aw9620x_i2c_read(a1, a2, &v9);
  result = aw9620x_i2c_write(a1, a2, v9 & a3 | a4);
  _ReadStatusReg(SP_EL0);
  return result;
}
