__int64 __fastcall send_roam_scan_offload_rssi_change_cmd_tlv(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x22
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  unsigned int v24; // w20

  v4 = wmi_buf_alloc_fl(a1, 0x14u, "send_roam_scan_offload_rssi_change_cmd_tlv", 0x1738u);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 7471120;
  v13[1] = *a2;
  v13[2] = a2[3];
  v13[3] = a2[1];
  v13[4] = a2[2];
  qdf_trace_msg(
    0x31u,
    8u,
    "RSO_CFG: vdev %d rssi_change_thresh:%d bcn_rssi_weight:%d hirssi_delay_btw_scans:%d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12);
  wmi_mtrace(0xB004u, v13[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x14u,
             0xB004u,
             "send_roam_scan_offload_rssi_change_cmd_tlv",
             0x1753u,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22);
  if ( (_DWORD)result )
  {
    v24 = result;
    wmi_buf_free();
    return v24;
  }
  return result;
}
