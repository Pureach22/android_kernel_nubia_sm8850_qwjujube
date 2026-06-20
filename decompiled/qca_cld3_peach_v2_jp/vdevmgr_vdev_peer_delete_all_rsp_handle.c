__int64 __fastcall vdevmgr_vdev_peer_delete_all_rsp_handle(__int64 a1, unsigned __int8 *a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  int v4; // w8
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w19
  __int64 rx_ops; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 (__fastcall *v25)(__int64, __int64); // x8
  __int64 v26; // x1

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 504) + 152LL);
  if ( !v2 )
    return 4294967292LL;
  v3 = *(_QWORD *)(v2 + 80);
  if ( !v3 )
    return 4294967292LL;
  v4 = *((_DWORD *)a2 + 1);
  if ( (v4 & 0x1000) != 0 )
  {
    rx_ops = wifi_pos_get_rx_ops(v3);
    if ( rx_ops && (v25 = *(__int64 (__fastcall **)(__int64, __int64))(rx_ops + 32)) != nullptr )
    {
      v26 = *a2;
      if ( *((_DWORD *)v25 - 1) != -132374536 )
        __break(0x8228u);
      return v25(v3, v26);
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: rx_ops is NULL",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "vdevmgr_vdev_peer_delete_all_rsp_handle");
      return 16;
    }
  }
  else if ( (v4 & 0x4000) != 0 )
  {
    return wlan_nan_handle_delete_all_pasn_peers(v3, *a2);
  }
  else
  {
    result = lim_process_mlm_del_all_sta_rsp();
    if ( (_DWORD)result )
    {
      v14 = result;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Failed to call lim_process_mlm_del_all_sta_rsp",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "vdevmgr_vdev_peer_delete_all_rsp_handle");
      return v14;
    }
  }
  return result;
}
