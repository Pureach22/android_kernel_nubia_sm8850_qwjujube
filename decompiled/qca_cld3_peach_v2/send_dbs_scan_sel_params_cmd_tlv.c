__int64 __fastcall send_dbs_scan_sel_params_cmd_tlv(__int64 a1, _DWORD *a2)
{
  int v4; // w22
  __int64 v5; // x0
  _DWORD *v6; // x8
  __int64 v7; // x19
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v4 = 16 * *a2;
  v5 = wmi_buf_alloc_fl(a1, v4 + 16, "send_dbs_scan_sel_params_cmd_tlv", 0x916u);
  if ( !v5 )
    return 2;
  v6 = *(_DWORD **)(v5 + 224);
  v7 = v5;
  *v6 = 42467336;
  v6[1] = *a2;
  v6[2] = a2[1];
  v6[3] = (16 * (*a2 & 0xFFF)) | 0x120000;
  if ( !*a2 )
    goto LABEL_10;
  v6[4] = 42532876;
  v6[5] = a2[2];
  v6[6] = a2[9];
  v6[7] = a2[16];
  if ( *a2 <= 1u )
    goto LABEL_10;
  v6[8] = 42532876;
  v6[9] = a2[3];
  v6[10] = a2[10];
  v6[11] = a2[17];
  if ( *a2 < 3u )
    goto LABEL_10;
  v6[12] = 42532876;
  v6[13] = a2[4];
  v6[14] = a2[11];
  v6[15] = a2[18];
  if ( *a2 < 4u )
    goto LABEL_10;
  v6[16] = 42532876;
  v6[17] = a2[5];
  v6[18] = a2[12];
  v6[19] = a2[19];
  if ( *a2 < 5u )
    goto LABEL_10;
  v6[20] = 42532876;
  v6[21] = a2[6];
  v6[22] = a2[13];
  v6[23] = a2[20];
  if ( *a2 < 6u )
    goto LABEL_10;
  v6[24] = 42532876;
  v6[25] = a2[7];
  v6[26] = a2[14];
  v6[27] = a2[21];
  if ( *a2 < 7u )
    goto LABEL_10;
  v6[28] = 42532876;
  v6[29] = a2[8];
  v6[30] = a2[15];
  v6[31] = a2[22];
  if ( *a2 > 7u )
  {
    v6[32] = 42532876;
    __break(0x5512u);
    return send_set_arp_stats_req_cmd_tlv();
  }
  else
  {
LABEL_10:
    wmi_mtrace(0x3008u, 0xFFu, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v7,
               v4 + 16,
               0x3008u,
               "send_dbs_scan_sel_params_cmd_tlv",
               0x937u,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send dbs scan selection cmd err=%d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "send_dbs_scan_sel_params_cmd_tlv",
        (unsigned int)result);
      wmi_buf_free();
      return 16;
    }
  }
  return result;
}
