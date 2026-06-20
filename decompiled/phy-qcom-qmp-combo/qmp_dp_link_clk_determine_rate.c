__int64 __fastcall qmp_dp_link_clk_determine_rate(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 result; // x0

  v2 = *(_QWORD *)(a2 + 8);
  result = 0;
  if ( v2 <= 539999999 )
  {
    if ( v2 == 162000000 || v2 == 270000000 )
      return result;
    return 4294967274LL;
  }
  if ( v2 != 540000000 && v2 != 810000000 )
    return 4294967274LL;
  return result;
}
