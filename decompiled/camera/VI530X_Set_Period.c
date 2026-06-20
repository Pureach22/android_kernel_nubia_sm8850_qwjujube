__int64 __fastcall VI530X_Set_Period(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int16 v5; // [xsp+0h] [xbp-10h] BYREF
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  v5 = 0;
  vi530x_write_reg_offset(a1, 12, 0, 0);
  if ( a2 )
  {
    vi530x_write_reg_offset(a1, 12, 1, 3);
    vi530x_write_reg_offset(a1, 12, 2, 20);
    vi530x_write_byte(a1, 10, 9);
    _const_udelay((const char *)0x147AEB8);
    vi530x_read_multibytes(a1, 12, &v6, 3);
    v5 = (0x3B9ACA00 / a2 - 1463 * v6 / 0xAu - 5200000) / 0xD48;
  }
  else
  {
    vi530x_write_reg_offset(a1, 12, 1, 2);
    vi530x_write_reg_offset(a1, 12, 2, 23);
    vi530x_write_byte(a1, 10, 9);
    _const_udelay((const char *)0x147AEB8);
    vi530x_read_multibytes(a1, 12, &v5, 2);
  }
  vi530x_write_reg_offset(a1, 12, 0, 1);
  vi530x_write_reg_offset(a1, 12, 1, 2);
  vi530x_write_reg_offset(a1, 12, 2, 23);
  vi530x_write_reg_offset(a1, 12, 3, (unsigned __int8)v5);
  vi530x_write_reg_offset(a1, 12, 4, HIBYTE(v5));
  vi530x_write_byte(a1, 10, 9);
  result = _const_udelay((const char *)0x147AEB8);
  _ReadStatusReg(SP_EL0);
  return result;
}
