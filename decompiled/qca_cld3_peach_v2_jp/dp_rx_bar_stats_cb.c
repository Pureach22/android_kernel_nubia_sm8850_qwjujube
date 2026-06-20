__int64 __fastcall dp_rx_bar_stats_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w1
  __int64 v16; // x20

  result = dp_check_pdev_exists(a1, a2);
  if ( (result & 1) != 0 )
  {
    if ( *(_DWORD *)(a1 + 56) )
    {
      v15 = *(_DWORD *)(a3 + 4);
      if ( v15 )
        result = DP_PRINT_STATS("REO stats failure %d", v15);
      else
        *(_DWORD *)(a2 + 6424) += *(unsigned __int8 *)(a3 + 84);
      *(_DWORD *)(a2 + 95024) = 1;
    }
  }
  else
  {
    v16 = jiffies;
    if ( dp_rx_bar_stats_cb___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x45u,
                 2u,
                 "%s: pdev doesn't exist",
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 "dp_rx_bar_stats_cb");
      dp_rx_bar_stats_cb___last_ticks = v16;
    }
  }
  return result;
}
