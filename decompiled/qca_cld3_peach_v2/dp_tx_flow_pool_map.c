__int64 __fastcall dp_tx_flow_pool_map(__int64 a1, char a2, unsigned int a3)
{
  _QWORD *v3; // x20
  unsigned int num_tx_desc; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  if ( a2 )
  {
    wlan_cfg_get_num_tx_desc(*(_QWORD *)(a1 + 40));
  }
  else
  {
    v3 = *(_QWORD **)(a1 + 72);
    num_tx_desc = wlan_cfg_get_num_tx_desc(*(_QWORD *)(a1 + 40));
    if ( v3 )
      return dp_tx_flow_pool_map_handler(v3, a3, 0, a3, num_tx_desc, v6, v7, v8, v9, v10, v11, v12, v13);
  }
  qdf_trace_msg(0x45u, 2u, "%s: pdev is NULL", v6, v7, v8, v9, v10, v11, v12, v13, "dp_tx_flow_pool_map");
  return 4;
}
