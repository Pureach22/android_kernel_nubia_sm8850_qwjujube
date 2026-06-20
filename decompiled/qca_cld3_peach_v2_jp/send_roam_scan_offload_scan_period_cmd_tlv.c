__int64 __fastcall send_roam_scan_offload_scan_period_cmd_tlv(__int64 a1, _DWORD *a2)
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
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 result; // x0
  unsigned int v32; // w20

  v4 = wmi_buf_alloc_fl(a1, 0x24u, "send_roam_scan_offload_scan_period_cmd_tlv", 0x16Du);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 7405600;
  v13[1] = *a2;
  v13[2] = a2[2];
  v13[3] = a2[3];
  v13[4] = a2[4];
  v13[5] = a2[5];
  v13[7] = 1000 * a2[6];
  v13[8] = a2[7];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: roam_scan_period=%d, roam_scan_age=%d, full_scan_period= %u, roam periodic scan interval= %u",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_roam_scan_offload_scan_period_cmd_tlv");
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: inactiviy time:%d inactive cnt:%d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "send_roam_scan_offload_scan_period_cmd_tlv",
    (unsigned int)v13[4],
    (unsigned int)v13[5]);
  wmi_mtrace(0xB003u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x24u,
             0xB003u,
             "send_roam_scan_offload_scan_period_cmd_tlv",
             0x193u,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30);
  if ( (_DWORD)result )
  {
    v32 = result;
    wmi_buf_free();
    return v32;
  }
  return result;
}
