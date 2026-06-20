__int64 __fastcall clk_rcg_esc_determine_rate(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x20
  unsigned __int64 rate; // x0
  unsigned __int64 v5; // x9

  if ( !a2[1] )
    return 4294967274LL;
  v3 = 1LL << *(_BYTE *)(a1 - 32);
  rate = clk_hw_get_rate(a2[5]);
  v5 = rate / a2[1];
  if ( (int)v5 < 1 || (int)v5 > (int)v3 )
    return 4294967274LL;
  a2[4] = rate;
  a2[1] = rate / (v5 & 0x7FFFFFFF);
  return 0;
}
