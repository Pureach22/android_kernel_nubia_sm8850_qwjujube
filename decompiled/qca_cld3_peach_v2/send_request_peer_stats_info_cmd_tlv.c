__int64 __fastcall send_request_peer_stats_info_cmd_tlv(__int64 a1, int *a2)
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
  int v15; // w8
  int v16; // w9
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v35; // [xsp+0h] [xbp-20h]
  int v36; // [xsp+8h] [xbp-18h]
  int v37; // [xsp+10h] [xbp-10h]

  v4 = wmi_buf_alloc_fl(a1, 0x18u, "send_request_peer_stats_info_cmd_tlv", 0x115u);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 39452692;
  v15 = *a2;
  v13[1] = *a2;
  v13[2] = a2[1];
  v13[3] = a2[2];
  v13[4] = *((unsigned __int16 *)a2 + 6);
  v16 = a2[4];
  v13[5] = v16;
  v37 = v16;
  v36 = v15;
  v35 = *((unsigned __int8 *)a2 + 13);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: PEER STATS REQ VDEV_ID:%d PEER:%02x:%02x:%02x:**:**:%02x TYPE:%d RESET:%d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_request_peer_stats_info_cmd_tlv",
    v35,
    v36,
    v37);
  wmi_mtrace(0x1600Cu, v13[2], 0);
  v25 = wmi_unified_cmd_send_fl(
          a1,
          v14,
          0x18u,
          0x1600Cu,
          "send_request_peer_stats_info_cmd_tlv",
          0x12Au,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24);
  if ( v25 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send peer stats request to fw =%d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "send_request_peer_stats_info_cmd_tlv",
      v25);
    wmi_buf_free();
  }
  return qdf_status_from_os_return(v25);
}
