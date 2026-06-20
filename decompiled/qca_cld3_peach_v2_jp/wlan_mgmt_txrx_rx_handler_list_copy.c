__int64 __fastcall wlan_mgmt_txrx_rx_handler_list_copy(__int64 result, _QWORD *a2, __int64 a3)
{
  __int64 v4; // x20
  _QWORD *v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x20

  if ( result )
  {
    v4 = result;
    while ( 1 )
    {
      v6 = qdf_mem_malloc_atomic_fl(0x18u, (__int64)"wlan_mgmt_txrx_rx_handler_list_copy", 0x535u);
      if ( !v6 )
        break;
      *(_DWORD *)v6 = *(_DWORD *)v4;
      v6[1] = *(_QWORD *)(v4 + 8);
      v6[2] = 0;
      if ( *a2 )
      {
        *(_QWORD *)(*(_QWORD *)a3 + 16LL) = v6;
        v6 = *(_QWORD **)(*(_QWORD *)a3 + 16LL);
      }
      else
      {
        *a2 = v6;
      }
      *(_QWORD *)a3 = v6;
      v4 = *(_QWORD *)(v4 + 16);
      if ( !v4 )
        return 0;
    }
    v15 = jiffies;
    if ( wlan_mgmt_txrx_rx_handler_list_copy___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Bu,
        2u,
        "%s: Couldn't allocate memory for rx handler node",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "wlan_mgmt_txrx_rx_handler_list_copy");
      wlan_mgmt_txrx_rx_handler_list_copy___last_ticks = v15;
    }
    return 2;
  }
  return result;
}
