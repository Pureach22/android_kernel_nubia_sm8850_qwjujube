__int64 __fastcall pmic_gpio_read(__int64 *a1, unsigned __int16 *a2, int a3)
{
  int v5; // w8
  __int64 v6; // x0
  unsigned int v7; // w0
  __int64 result; // x0
  __int64 v9; // x8
  unsigned int v10; // w20
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a2;
  v6 = a1[1];
  v11 = 0;
  v7 = regmap_read(v6, (unsigned int)(v5 + a3), &v11);
  if ( (v7 & 0x80000000) != 0 )
  {
    v9 = *a1;
    v10 = v7;
    dev_err(v9, "read 0x%x failed\n", a3);
    result = v10;
  }
  else
  {
    result = v11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
