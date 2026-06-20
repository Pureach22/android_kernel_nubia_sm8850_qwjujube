__int64 __fastcall i2c_pmic_suspend(__int64 a1)
{
  __int64 v1; // x26
  __int64 v3; // x27
  __int64 v4; // x28
  unsigned int v5; // w25
  __int64 v6; // x23
  unsigned int v7; // w0
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 152);
  if ( (*(_DWORD *)(v1 + 100) & 0x80000000) != 0 )
    return 0;
  if ( *(int *)(v1 + 96) < 1 )
    goto LABEL_12;
  v3 = 0;
  v4 = 0;
  do
  {
    v6 = *(_QWORD *)(v1 + 24) + v3;
    v7 = regmap_write(*(_QWORD *)(v1 + 8), *(unsigned __int16 *)(v6 + 8) | 0x16u, 255);
    if ( (v7 & 0x80000000) != 0 )
    {
      v5 = v7;
      if ( (unsigned int)__ratelimit(&i2c_pmic_suspend__rs, "i2c_pmic_suspend") )
        dev_err(a1, "Couldn't clear 0x%04x irqs rc=%d\n", *(unsigned __int16 *)(v6 + 8), v5);
    }
    else
    {
      v5 = regmap_write(*(_QWORD *)(v1 + 8), *(unsigned __int16 *)(v6 + 8) | 0x15u, *(unsigned __int8 *)(v6 + 20));
      if ( (v5 & 0x80000000) != 0 )
      {
        if ( (unsigned int)__ratelimit(&i2c_pmic_suspend__rs_42, "i2c_pmic_suspend") )
          dev_err(
            a1,
            "Couldn't enable 0x%04x wake irqs 0x%02x rc=%d\n",
            *(unsigned __int16 *)(v6 + 8),
            *(unsigned __int8 *)(v6 + 20),
            v5);
      }
    }
    ++v4;
    v3 += 72;
  }
  while ( v4 < *(int *)(v1 + 96) );
  result = v5;
  if ( !v5 )
  {
LABEL_12:
    mutex_lock(v1 + 40);
    *(_BYTE *)(v1 + 104) = 0;
    mutex_unlock(v1 + 40);
    return 0;
  }
  return result;
}
