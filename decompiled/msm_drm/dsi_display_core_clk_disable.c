__int64 __fastcall dsi_display_core_clk_disable(__int64 a1, int a2, unsigned int a3)
{
  __int64 v4; // x21
  int i; // w22
  __int64 *v7; // x0

  v4 = a3;
  if ( a2 )
  {
    for ( i = 0; i != a2; ++i )
    {
      if ( i != v4 )
      {
        v7 = (__int64 *)(a1 + 56LL * i);
        if ( v7 )
          dsi_core_clk_stop(v7);
      }
    }
  }
  return dsi_core_clk_stop((__int64 *)(a1 + 56LL * (unsigned int)v4));
}
