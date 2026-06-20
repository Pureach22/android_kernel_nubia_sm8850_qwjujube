__int64 __fastcall qmp_dp_link_clk_recalc_rate(__int64 a1)
{
  int v1; // w8
  __int64 result; // x0

  v1 = *(_DWORD *)(a1 - 100);
  result = 0;
  if ( v1 <= 5399 )
  {
    if ( v1 != 1620 && v1 != 2700 )
      return result;
    return 100000LL * (unsigned int)v1;
  }
  if ( v1 == 8100 || v1 == 5400 )
    return 100000LL * (unsigned int)v1;
  return result;
}
