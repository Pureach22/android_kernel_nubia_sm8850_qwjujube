__int64 __fastcall ucfg_dp_config_direct_link(__int64 a1, char a2, char a3)
{
  __int64 context; // x0
  __int64 intf_by_netdev; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  context = dp_get_context();
  if ( !context )
    return 16;
  intf_by_netdev = dp_get_intf_by_netdev(context, a1);
  if ( intf_by_netdev )
    return dp_config_direct_link(intf_by_netdev, a2 & 1, a3 & 1, v8, v9, v10, v11, v12, v13, v14, v15);
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Unable to get DP interface",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "ucfg_dp_config_direct_link");
  return 4;
}
