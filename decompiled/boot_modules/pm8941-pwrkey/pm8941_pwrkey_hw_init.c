__int64 __fastcall pm8941_pwrkey_hw_init(__int64 *a1)
{
  unsigned int *v1; // x8
  unsigned int v3; // w8
  int v4; // w10
  __int64 v5; // x0
  __int64 v6; // x2
  unsigned int updated; // w0
  __int64 v8; // x2
  __int64 v9; // x3
  unsigned int v10; // w8
  __int64 result; // x0
  __int64 v12; // x0
  unsigned int v13; // w19
  __int64 v14; // x8

  v1 = (unsigned int *)a1[12];
  if ( *((_BYTE *)v1 + 9) == 1 )
  {
    v3 = *((_DWORD *)a1 + 11);
    v4 = *((_DWORD *)a1 + 3);
    v5 = a1[3];
    if ( v3 <= 3 )
      v6 = 7;
    else
      v6 = 15;
    updated = regmap_update_bits_base(v5, (unsigned int)(v4 + 113), v6, 0, 0, 0, 0);
    if ( updated )
    {
      v14 = *a1;
      v13 = updated;
      dev_err(v14, "failed to set debounce config: %d\n", updated);
      return v13;
    }
    v1 = (unsigned int *)a1[12];
  }
  v8 = *v1;
  if ( !(_DWORD)v8 )
    return 0;
  if ( *((_BYTE *)a1 + 93) )
    v9 = (unsigned int)v8;
  else
    v9 = 0;
  v10 = regmap_update_bits_base(a1[3], (unsigned int)(*((_DWORD *)a1 + 3) + 112), v8, v9, 0, 0, 0);
  result = 0;
  if ( v10 )
  {
    v12 = *a1;
    v13 = v10;
    dev_err(v12, "failed to set pull-up config: %d\n", v10);
    return v13;
  }
  return result;
}
