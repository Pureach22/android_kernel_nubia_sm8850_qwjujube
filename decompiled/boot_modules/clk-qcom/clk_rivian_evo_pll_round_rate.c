unsigned __int64 __fastcall clk_rivian_evo_pll_round_rate(__int64 a1, unsigned __int64 a2, _QWORD *a3)
{
  unsigned __int64 v3; // x10
  unsigned __int64 *v4; // x8
  unsigned __int64 *v5; // x9
  unsigned __int64 *v6; // x10
  unsigned __int64 result; // x0
  unsigned __int64 v8; // x8

  v3 = (unsigned int)*a3;
  if ( a2 % v3 )
    a2 = 1000 * (((unsigned __int64)(unsigned int)(a2 / v3) * *a3 + 999) / 0x3E8);
  v4 = *(unsigned __int64 **)(a1 - 24);
  if ( !v4 )
    return a2;
  v5 = &v4[3 * *(_QWORD *)(a1 - 16)];
  if ( v4 < v5 )
  {
    v6 = *(unsigned __int64 **)(a1 - 24);
    while ( *v6 > a2 || v6[1] < a2 )
    {
      v6 += 3;
      if ( v6 >= v5 )
        goto LABEL_12;
    }
    if ( v6 )
      return a2;
  }
LABEL_12:
  result = *(v5 - 2);
  if ( a2 < result )
  {
    v8 = *v4;
    if ( a2 <= v8 )
      return v8;
    else
      return a2;
  }
  return result;
}
