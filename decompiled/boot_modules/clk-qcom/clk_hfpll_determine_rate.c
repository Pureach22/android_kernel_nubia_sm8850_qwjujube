__int64 __fastcall clk_hfpll_determine_rate(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  unsigned __int64 v3; // x10
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x10
  __int64 result; // x0
  unsigned __int64 v7; // x11
  unsigned __int64 v8; // x8

  v2 = *(_QWORD *)(a1 - 16);
  v3 = *(_QWORD *)(a2 + 8);
  v4 = *(_QWORD *)(v2 + 72);
  if ( v3 < v4 )
  {
    v4 = *(_QWORD *)(v2 + 64);
    if ( v3 > v4 )
      v4 = *(_QWORD *)(a2 + 8);
  }
  v5 = *(_QWORD *)(a2 + 32);
  *(_QWORD *)(a2 + 8) = v4;
  result = 0;
  v7 = (v5 + v4 - 1) / v5 * v5;
  if ( v7 <= *(_QWORD *)(v2 + 72) )
    v8 = 0;
  else
    v8 = v5;
  *(_QWORD *)(a2 + 8) = v7 - v8;
  return result;
}
