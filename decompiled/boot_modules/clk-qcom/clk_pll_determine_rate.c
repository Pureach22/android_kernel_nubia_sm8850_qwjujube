__int64 __fastcall clk_pll_determine_rate(__int64 a1, __int64 a2)
{
  unsigned __int64 *v2; // x9
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // t1

  v2 = *(unsigned __int64 **)(a1 - 8);
  if ( !v2 )
    goto LABEL_7;
  v4 = *v2;
  if ( !*v2 )
    goto LABEL_7;
  while ( v4 < *(_QWORD *)(a2 + 8) )
  {
    v5 = v2[3];
    v2 += 3;
    v4 = v5;
    if ( !v5 )
      goto LABEL_7;
  }
  if ( !v2 )
LABEL_7:
    v4 = clk_pll_recalc_rate(a1, *(_QWORD *)(a2 + 32));
  *(_QWORD *)(a2 + 8) = v4;
  return 0;
}
