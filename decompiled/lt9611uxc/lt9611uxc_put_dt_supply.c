__int64 __fastcall lt9611uxc_put_dt_supply(__int64 result, __int64 a2)
{
  __int64 v3; // x8
  int v4; // w9
  __int64 v5; // x9
  __int64 v6; // x21
  __int64 *v7; // x20
  bool v8; // cc

  if ( !result )
    return printk(&unk_B2B3, "lt9611uxc_put_dt_supply");
  v3 = *(_QWORD *)(a2 + 3152);
  if ( v3 )
  {
    v4 = *(_DWORD *)(a2 + 3148);
    if ( v4 )
    {
      v5 = (unsigned int)(v4 - 1);
      if ( (int)v5 < 0 )
      {
LABEL_11:
        *(_QWORD *)(a2 + 3152) = 0;
        goto LABEL_12;
      }
      v6 = v5 + 1;
      v7 = (__int64 *)(v3 + 72LL * (unsigned int)v5);
      do
      {
        result = *v7;
        if ( *v7 )
        {
          regulator_set_voltage(result, 0, *((unsigned int *)v7 + 11));
          result = regulator_put(*v7);
          *v7 = 0;
        }
        v8 = v6-- <= 1;
        v7 -= 9;
      }
      while ( !v8 );
      v3 = *(_QWORD *)(a2 + 3152);
    }
  }
  if ( v3 )
    goto LABEL_11;
LABEL_12:
  *(_DWORD *)(a2 + 3148) = 0;
  return result;
}
