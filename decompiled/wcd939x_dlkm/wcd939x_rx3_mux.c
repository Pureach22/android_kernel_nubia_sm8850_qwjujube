__int64 __fastcall wcd939x_rx3_mux(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x0

  v3 = *(_QWORD *)(a1 + 40) - 208LL;
  if ( a3 == 8 )
  {
    wcd939x_rx_clk_disable(v3);
  }
  else if ( a3 == 1 )
  {
    wcd939x_rx_clk_enable(v3);
  }
  return 0;
}
