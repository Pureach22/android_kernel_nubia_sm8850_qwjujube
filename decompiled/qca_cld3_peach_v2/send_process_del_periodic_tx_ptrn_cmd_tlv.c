__int64 __fastcall send_process_del_periodic_tx_ptrn_cmd_tlv(__int64 a1, unsigned __int8 a2, unsigned __int8 a3)
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
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v6 = wmi_buf_alloc_fl(a1, 0xCu, "send_process_del_periodic_tx_ptrn_cmd_tlv", 0x7AFu);
  if ( !v6 )
    return 2;
  v15 = *(_DWORD **)(v6 + 224);
  v16 = v6;
  *v15 = 16777224;
  v15[1] = a2;
  v15[2] = a3;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Del ptrn id: %d vdev_id: %d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "send_process_del_periodic_tx_ptrn_cmd_tlv");
  wmi_mtrace(0x17003u, v15[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v16,
             0xCu,
             0x17003u,
             "send_process_del_periodic_tx_ptrn_cmd_tlv",
             0x7C3u,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send del pattern command",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "send_process_del_periodic_tx_ptrn_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
