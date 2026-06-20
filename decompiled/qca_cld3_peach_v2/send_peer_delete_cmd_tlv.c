__int64 __fastcall send_peer_delete_cmd_tlv(__int64 a1, unsigned __int8 *a2, unsigned __int8 *a3)
{
  int v6; // w21
  __int64 v7; // x0
  _DWORD *v8; // x24
  __int64 v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x7
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  v6 = peer_delete_mlo_params_size(a3);
  v7 = wmi_buf_alloc_fl(a1, v6 + 16, "send_peer_delete_cmd_tlv", 0x76Cu);
  if ( !v7 )
    return 2;
  v8 = *(_DWORD **)(v7 + 224);
  v9 = v7;
  *v8 = 6422540;
  v8[2] = *(_DWORD *)a2;
  v8[3] = *((unsigned __int16 *)a2 + 2);
  v8[1] = *a3;
  peer_delete_add_mlo_params(v8 + 4, a3);
  if ( a2 )
  {
    v18 = *a2;
    v19 = a2[1];
    v20 = a2[2];
    v21 = a2[5];
  }
  else
  {
    v20 = 0;
    v18 = 0;
    v19 = 0;
    v21 = 0;
  }
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: peer_addr %02x:%02x:%02x:**:**:%02x vdev_id %d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "send_peer_delete_cmd_tlv",
    v18,
    v19,
    v20,
    v21,
    *a3);
  qdf_mtrace(49, 100, 0x302u, v8[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v9,
             v6 + 16,
             0x6002u,
             "send_peer_delete_cmd_tlv",
             0x77Du,
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
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send peer delete command",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "send_peer_delete_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
