__int64 __fastcall VI530X_Read_FW_Version(__int64 a1)
{
  __int64 result; // x0
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  vi530x_write_reg_offset(a1, 12, 0, 6);
  vi530x_write_byte(a1, 10, 9);
  _const_udelay((const char *)0x147AEB8);
  vi530x_read_multibytes(a1, 12, &v3, 4);
  result = printk(&unk_417FA1);
  _ReadStatusReg(SP_EL0);
  return result;
}
