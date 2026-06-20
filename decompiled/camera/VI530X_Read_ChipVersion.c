__int64 __fastcall VI530X_Read_ChipVersion(__int64 a1)
{
  __int64 result; // x0
  __int16 v2; // [xsp+4h] [xbp-Ch] BYREF
  char v3; // [xsp+6h] [xbp-Ah]
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  v2 = 0;
  vi530x_read_multibytes(a1, 44, &v2, 3);
  result = printk(&unk_3F42A3);
  _ReadStatusReg(SP_EL0);
  return result;
}
