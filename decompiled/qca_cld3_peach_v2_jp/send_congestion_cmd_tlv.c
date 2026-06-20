__int64 __fastcall send_congestion_cmd_tlv(__int64 a1, unsigned __int8 a2)
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
  __int64 v13; // x22
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
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x18u, "send_congestion_cmd_tlv", 0x1E7Fu);
  if ( v4 )
  {
    v13 = *(_QWORD *)(v4 + 224);
    v14 = v4;
    *(_QWORD *)v13 = 0x200008F0014LL;
    *(_DWORD *)(v13 + 8) = a2;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: STATS REQ VDEV_ID:%d stats_id %d -->",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_congestion_cmd_tlv");
    qdf_mtrace(49, 100, 0xB01u, *(_DWORD *)(v13 + 8), 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v14,
               0x18u,
               0x16001u,
               "send_congestion_cmd_tlv",
               0x1E91u,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22);
    if ( !(_DWORD)result )
      return result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_REQUEST_STATS_CMDID",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "send_congestion_cmd_tlv");
    wmi_buf_free();
  }
  return 16;
}
