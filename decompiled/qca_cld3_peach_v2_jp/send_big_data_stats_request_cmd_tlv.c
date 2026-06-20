__int64 __fastcall send_big_data_stats_request_cmd_tlv(__int64 a1, __int64 a2)
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
  unsigned int v23; // w20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v4 = wmi_buf_alloc_fl(a1, 8u, "send_big_data_stats_request_cmd_tlv", 0x2F7u);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 57868292;
  v13[1] = *(unsigned __int8 *)(a2 + 4);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: STATS VDEV_ID:%d -->",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_big_data_stats_request_cmd_tlv");
  wmi_mtrace(0x502Au, v13[1], 0);
  v23 = wmi_unified_cmd_send_fl(
          a1,
          v14,
          8u,
          0x502Au,
          "send_big_data_stats_request_cmd_tlv",
          0x308u,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22);
  if ( v23 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send big data stats request to fw =%d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "send_big_data_stats_request_cmd_tlv",
      v23);
    wmi_buf_free();
  }
  return qdf_status_from_os_return(v23);
}
