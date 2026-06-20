__int64 __fastcall pmic_gpio_write(__int64 *a1, unsigned __int16 *a2, int a3, unsigned int a4)
{
  __int64 result; // x0
  __int64 v7; // x8
  unsigned int v8; // w20

  result = regmap_write(a1[1], (unsigned int)*a2 + a3, a4);
  if ( (result & 0x80000000) != 0 )
  {
    v7 = *a1;
    v8 = result;
    dev_err(v7, "write 0x%x failed\n", a3);
    return v8;
  }
  return result;
}
