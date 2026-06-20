__int64 __fastcall send_peer_flush_tids_cmd_tlv(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _DWORD *v15; // x23
  __int64 v16; // x19
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  v6 = wmi_buf_alloc_fl(a1, 0x14u, "send_peer_flush_tids_cmd_tlv", 0x61Du);
  if ( !v6 )
    return 2;
  v15 = *(_DWORD **)(v6 + 224);
  v16 = v6;
  *v15 = 6488080;
  v15[2] = *(_DWORD *)a2;
  v15[3] = *((unsigned __int16 *)a2 + 2);
  v15[4] = *(_DWORD *)a3;
  v15[1] = *(unsigned __int8 *)(a3 + 4);
  if ( a2 )
  {
    v17 = *a2;
    v18 = a2[1];
    v19 = a2[2];
    v20 = a2[5];
  }
  else
  {
    v19 = 0;
    v17 = 0;
    v18 = 0;
    v20 = 0;
  }
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: peer_addr %02x:%02x:%02x:**:**:%02x vdev_id %d and peer bitmap %d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "send_peer_flush_tids_cmd_tlv",
    v17,
    v18,
    v19,
    v20,
    *(unsigned __int8 *)(a3 + 4),
    *(_DWORD *)a3);
  qdf_mtrace(49, 100, 0x303u, v15[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v16,
             0x14u,
             0x6003u,
             "send_peer_flush_tids_cmd_tlv",
             0x62Du,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send flush tid command",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "send_peer_flush_tids_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
