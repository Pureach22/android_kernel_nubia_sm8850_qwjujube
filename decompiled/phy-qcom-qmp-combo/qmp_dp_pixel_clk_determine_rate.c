__int64 __fastcall qmp_dp_pixel_clk_determine_rate(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a2 + 8);
  if ( v2 == 1350000000 || v2 == 810000000 )
    return 0;
  else
    return 4294967274LL;
}
