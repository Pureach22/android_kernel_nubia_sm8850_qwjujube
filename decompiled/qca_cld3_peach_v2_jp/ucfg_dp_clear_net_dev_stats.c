char *__fastcall ucfg_dp_clear_net_dev_stats(__int64 a1)
{
  char *result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  __int64 v20; // x20

  result = (char *)dp_get_context();
  if ( result )
  {
    result = (char *)dp_get_intf_by_netdev((__int64)result, a1);
    if ( result )
    {
      return (char *)qdf_mem_set(result + 2888, 0xB8u, 0);
    }
    else
    {
      v20 = jiffies;
      if ( ucfg_dp_clear_net_dev_stats___last_ticks_45 - jiffies + 125 < 0 )
      {
        result = (char *)qdf_trace_msg(
                           0x45u,
                           2u,
                           "%s: DP interface not found",
                           v11,
                           v12,
                           v13,
                           v14,
                           v15,
                           v16,
                           v17,
                           v18,
                           "ucfg_dp_clear_net_dev_stats");
        ucfg_dp_clear_net_dev_stats___last_ticks_45 = v20;
      }
    }
  }
  else
  {
    v19 = jiffies;
    if ( ucfg_dp_clear_net_dev_stats___last_ticks - jiffies + 125 < 0 )
    {
      result = (char *)qdf_trace_msg(
                         0x45u,
                         2u,
                         "%s: DP context not found",
                         v3,
                         v4,
                         v5,
                         v6,
                         v7,
                         v8,
                         v9,
                         v10,
                         "ucfg_dp_clear_net_dev_stats");
      ucfg_dp_clear_net_dev_stats___last_ticks = v19;
    }
  }
  return result;
}
