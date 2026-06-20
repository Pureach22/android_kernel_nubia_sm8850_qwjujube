unsigned __int64 __fastcall clk_alpha_pll_round_rate(__int64 a1, unsigned __int64 a2, _QWORD *a3)
{
  unsigned __int64 v3; // x10
  char v4; // w12
  unsigned __int64 *v5; // x8
  unsigned __int64 *v6; // x9
  unsigned __int64 *v7; // x10
  unsigned __int64 result; // x0
  unsigned __int64 v9; // x8

  v3 = (unsigned int)*a3;
  if ( a2 % v3 )
  {
    v4 = 16;
    if ( *(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 4LL) - *(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL) == 4 )
      v4 = 32;
    a2 = 1000
       * (((((unsigned __int64)(unsigned int)(((a2 % v3) << v4) / v3) * *a3) >> v4) + (unsigned int)(a2 / v3) * *a3 + 999)
        / 0x3E8);
  }
  v5 = *(unsigned __int64 **)(a1 - 24);
  if ( !v5 )
    return a2;
  v6 = &v5[3 * *(_QWORD *)(a1 - 16)];
  if ( v5 < v6 )
  {
    v7 = *(unsigned __int64 **)(a1 - 24);
    while ( *v7 > a2 || v7[1] < a2 )
    {
      v7 += 3;
      if ( v7 >= v6 )
        goto LABEL_14;
    }
    if ( v7 )
      return a2;
  }
LABEL_14:
  result = *(v6 - 2);
  if ( a2 < result )
  {
    v9 = *v5;
    if ( a2 <= v9 )
      return v9;
    else
      return a2;
  }
  return result;
}
