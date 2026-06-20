__int64 __fastcall send_roam_scan_offload_rssi_thresh_cmd_tlv(__int64 a1, char *a2)
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
  _DWORD *v13; // x9
  __int64 v14; // x19
  int v15; // w8
  int v16; // w12
  int v17; // w12
  int v18; // w11
  int v19; // w11
  int v20; // w7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w20
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  v4 = wmi_buf_alloc_fl(a1, 0xA4u, "send_roam_scan_offload_rssi_thresh_cmd_tlv", 0xD0u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 7340064;
    v13[1] = (unsigned __int8)a2[24];
    v15 = *a2;
    v13[2] = v15;
    v13[3] = (unsigned __int8)a2[1];
    v13[4] = *((_DWORD *)a2 + 1);
    v13[5] = *((_DWORD *)a2 + 2);
    v13[6] = *((_DWORD *)a2 + 3);
    v13[7] = *((_DWORD *)a2 + 20);
    v13[8] = *((_DWORD *)a2 + 26);
    v13[9] = 1179688;
    v13[12] = *((_DWORD *)a2 + 7);
    if ( *((int *)a2 + 4) >= -96 )
      v13[11] = *((_DWORD *)a2 + 8);
    v13[13] = 1;
    v13[14] = (unsigned __int8)a2[36];
    v13[15] = 1;
    v13[16] = (unsigned __int8)a2[37];
    v13[17] = *((_DWORD *)a2 + 10);
    v13[18] = *((_DWORD *)a2 + 11);
    v16 = *((_DWORD *)a2 + 12);
    v13[10] = 25428004;
    v13[19] = v16;
    v13[20] = 1179660;
    v13[22] = *((_DWORD *)a2 + 14);
    v17 = *((_DWORD *)a2 + 15);
    v13[21] = 27983880;
    v13[23] = v17;
    v13[24] = 1179668;
    v13[26] = *((_DWORD *)a2 + 16);
    v13[27] = *((_DWORD *)a2 + 17);
    v13[29] = *((_DWORD *)a2 + 19);
    v18 = *((_DWORD *)a2 + 18);
    v13[25] = 29622288;
    v13[30] = 1179668;
    v13[28] = v18;
    v13[32] = a2[84];
    v13[33] = *((_DWORD *)a2 + 22);
    v13[34] = (unsigned __int8)a2[85];
    v13[35] = 0;
    v19 = (unsigned __int8)a2[85];
    v13[31] = 44171280;
    v13[35] = v19 != 0;
    v13[36] = 1179664;
    v13[38] = *((_DWORD *)a2 + 23);
    v13[39] = *((_DWORD *)a2 + 24);
    v20 = *((_DWORD *)a2 + 25);
    v13[37] = 61014028;
    v13[40] = v20;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev %d Data rssi threshold: %d, triggers: 0x%x, rx time: %d, rssi_thresh:%d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_roam_scan_offload_rssi_thresh_cmd_tlv",
      v15);
    wmi_mtrace(0xB002u, 0xFFu, 0);
    v29 = wmi_unified_cmd_send_fl(
            a1,
            v14,
            0xA4u,
            0xB002u,
            "send_roam_scan_offload_rssi_thresh_cmd_tlv",
            0x14Du,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28);
    if ( v29 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: cmd WMI_ROAM_SCAN_RSSI_THRESHOLD returned Error %d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "send_roam_scan_offload_rssi_thresh_cmd_tlv",
        v29);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v29;
}
