__int64 __fastcall ucfg_dp_get_dev_stats(__int64 a1)
{
  __int64 context; // x0
  __int64 intf_by_netdev; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  context = dp_get_context();
  intf_by_netdev = dp_get_intf_by_netdev(context, a1);
  if ( intf_by_netdev )
    return intf_by_netdev + 2888;
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: DP interface not found dev: %s",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "ucfg_dp_get_dev_stats",
    a1 + 296);
  return 0;
}
