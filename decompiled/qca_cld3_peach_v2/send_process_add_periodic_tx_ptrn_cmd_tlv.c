__int64 __fastcall send_process_add_periodic_tx_ptrn_cmd_tlv(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  unsigned int v3; // w22
  int v7; // w25
  __int64 v8; // x0
  _DWORD *v9; // x26
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned __int64 v19; // x27
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 result; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  v3 = *(unsigned __int16 *)(a2 + 8);
  v7 = (v3 + 3) & 0x1FFFC;
  v8 = wmi_buf_alloc_fl(a1, v7 + 24, "send_process_add_periodic_tx_ptrn_cmd_tlv", 0x775u);
  if ( !v8 )
    return 2;
  v9 = *(_DWORD **)(v8 + 224);
  v10 = v8;
  *v9 = 16711696;
  v9[1] = a3;
  v9[2] = *(unsigned __int8 *)(a2 + 6);
  v9[3] = *(_DWORD *)(a2 + 12);
  v9[4] = *(unsigned __int16 *)(a2 + 8);
  v9[5] = ((_WORD)v3 + 3) & 0xFFFC | 0x110000;
  qdf_mem_copy(v9 + 6, (const void *)(a2 + 16), v3);
  if ( *(_WORD *)(a2 + 8) )
  {
    v19 = 0;
    do
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Add Ptrn: %02x",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "send_process_add_periodic_tx_ptrn_cmd_tlv",
        *((unsigned __int8 *)v9 + v19++ + 24));
    while ( v19 < *(unsigned __int16 *)(a2 + 8) );
  }
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Add ptrn id: %d vdev_id: %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "send_process_add_periodic_tx_ptrn_cmd_tlv",
    (unsigned int)v9[2],
    (unsigned int)v9[1]);
  wmi_mtrace(0x17002u, v9[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v10,
             v7 + 24,
             0x17002u,
             "send_process_add_periodic_tx_ptrn_cmd_tlv",
             0x795u,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to add pattern set state command",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "send_process_add_periodic_tx_ptrn_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
