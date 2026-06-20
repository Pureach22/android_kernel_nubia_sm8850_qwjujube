__int64 __fastcall send_process_ll_stats_set_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x22
  __int64 v6; // x19
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
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

  v4 = wmi_buf_alloc_fl(a1, 0xCu, "send_process_ll_stats_set_cmd_tlv", 0x1D63u);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  qdf_mem_set(v5, 0xCu, 0);
  *v5 = 18612232;
  v5[1] = *(_DWORD *)(a2 + 4);
  v5[2] = *(_DWORD *)(a2 + 8);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: LINK_LAYER_STATS - Start/Set Params MPDU Size Thresh : %d Aggressive Gather: %d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "send_process_ll_stats_set_cmd_tlv");
  qdf_mtrace(49, 100, 0xB05u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v6,
             0xCu,
             0x16005u,
             "send_process_ll_stats_set_cmd_tlv",
             0x1D7Bu,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send set link stats request",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "send_process_ll_stats_set_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
