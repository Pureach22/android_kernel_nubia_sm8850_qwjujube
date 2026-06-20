__int64 __fastcall send_process_ll_stats_clear_cmd_tlv(__int64 a1, __int64 a2)
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

  v4 = wmi_buf_alloc_fl(a1, 0x18u, "send_process_ll_stats_clear_cmd_tlv", 0x1D29u);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  qdf_mem_set(v5, 0x18u, 0);
  *v5 = 18677780;
  v5[2] = *(unsigned __int8 *)(a2 + 12);
  v5[1] = *(unsigned __int8 *)(a2 + 4);
  v5[3] = *(_DWORD *)(a2 + 8);
  v5[4] = *(_DWORD *)(a2 + 13);
  v5[5] = *(unsigned __int16 *)(a2 + 17);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: LINK_LAYER_STATS - Clear Request Params",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "send_process_ll_stats_clear_cmd_tlv");
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: StopReq: %d Vdev Id: %d Clear Stat Mask: %d Peer MAC Addr: %02x:%02x:%02x:**:**:%02x",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "send_process_ll_stats_clear_cmd_tlv",
    (unsigned int)v5[2],
    (unsigned int)v5[1],
    (unsigned int)v5[3],
    *(unsigned __int8 *)(a2 + 13),
    *(unsigned __int8 *)(a2 + 14),
    *(unsigned __int8 *)(a2 + 15),
    *(unsigned __int8 *)(a2 + 18));
  qdf_mtrace(49, 100, 0xB06u, v5[1], 0);
  if ( (unsigned int)wmi_unified_cmd_send_fl(
                       a1,
                       v6,
                       0x18u,
                       0x16006u,
                       "send_process_ll_stats_clear_cmd_tlv",
                       0x1D47u,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send clear link stats req",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "send_process_ll_stats_clear_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Clear Link Layer Stats request sent successfully",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "send_process_ll_stats_clear_cmd_tlv");
    return 0;
  }
}
