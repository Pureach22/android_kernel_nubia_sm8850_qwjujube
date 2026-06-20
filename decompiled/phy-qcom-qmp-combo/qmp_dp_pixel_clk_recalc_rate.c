__int64 __fastcall qmp_dp_pixel_clk_recalc_rate(__int64 a1)
{
  int v1; // w8

  v1 = *(_DWORD *)(a1 - 124);
  if ( v1 > 5399 )
  {
    if ( v1 != 5400 && v1 != 8100 )
      return 0;
    return 1350000000;
  }
  if ( v1 != 1620 )
  {
    if ( v1 != 2700 )
      return 0;
    return 1350000000;
  }
  return 810000000;
}
