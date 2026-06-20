__int64 __fastcall send_peer_rate_report_cmd_tlv(__int64 a1, _DWORD *a2)
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
  _DWORD *v13; // x8
  __int64 v14; // x19
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  unsigned int v27; // w20
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x80u, "send_peer_rate_report_cmd_tlv", 0x1758u);
  if ( !v4 )
    return 16;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 26280060;
  v13[1] = *a2;
  v13[2] = a2[1];
  v15 = (unsigned int)v13[1];
  v16 = (unsigned int)v13[2];
  v13[3] = a2[2];
  v17 = (unsigned int)v13[3];
  v13[4] = a2[3];
  v13[6] = a2[5];
  v13[5] = a2[4];
  v13[7] = a2[6];
  v13[8] = a2[7];
  v13[9] = a2[8];
  v13[10] = a2[9];
  v13[11] = a2[10];
  v13[13] = a2[12];
  v13[12] = a2[11];
  v13[14] = a2[13];
  v13[15] = a2[14];
  v13[16] = a2[15];
  v13[17] = a2[16];
  v13[18] = a2[17];
  v13[20] = a2[19];
  v13[19] = a2[18];
  v13[21] = a2[20];
  v13[22] = a2[21];
  v13[23] = a2[22];
  v13[24] = a2[23];
  v13[25] = a2[24];
  v13[27] = a2[26];
  v13[26] = a2[25];
  v13[28] = a2[27];
  v13[29] = a2[28];
  v13[30] = a2[29];
  v13[31] = a2[30];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: enable %d backoff_time %d period %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_peer_rate_report_cmd_tlv",
    v15,
    v16,
    v17);
  qdf_mtrace(49, 100, 0x30Bu, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x80u,
             0x600Bu,
             "send_peer_rate_report_cmd_tlv",
             0x177Cu,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25);
  if ( (_DWORD)result )
  {
    v27 = result;
    wmi_buf_free();
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send peer_set_report_cond command",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "send_peer_rate_report_cmd_tlv");
    return v27;
  }
  return result;
}
