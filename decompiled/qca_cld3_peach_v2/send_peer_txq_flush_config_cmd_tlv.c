__int64 __fastcall send_peer_txq_flush_config_cmd_tlv(__int64 a1, unsigned __int8 *a2)
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
  int v17; // w8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x1Cu, "send_peer_txq_flush_config_cmd_tlv", 0x739u);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 71565336;
  v13[2] = *(_DWORD *)(a2 + 1);
  v13[3] = *(unsigned __int16 *)(a2 + 5);
  v13[4] = *((_DWORD *)a2 + 2);
  v13[1] = *a2;
  v15 = *((_DWORD *)a2 + 3);
  if ( v15 == 1 )
    v16 = 1;
  else
    v16 = 2;
  if ( v15 )
    v17 = v16;
  else
    v17 = 0;
  v13[5] = v17;
  if ( v17 == 2 )
  {
    wmi_buf_free();
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid policy",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "send_peer_txq_flush_config_cmd_tlv");
    return 4;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: peer_addr %02x:%02x:%02x:**:**:%02xvdev %d tid %x policy %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_peer_txq_flush_config_cmd_tlv",
      a2[1],
      a2[2],
      a2[3],
      a2[6],
      *a2,
      *((_DWORD *)a2 + 2),
      *((_DWORD *)a2 + 3));
    qdf_mtrace(49, 100, 0x323u, v13[1], 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v14,
               0x1Cu,
               0x6023u,
               "send_peer_txq_flush_config_cmd_tlv",
               0x751u,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               v34);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send flush policy command",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "send_peer_txq_flush_config_cmd_tlv");
      wmi_buf_free();
      return 16;
    }
  }
  return result;
}
