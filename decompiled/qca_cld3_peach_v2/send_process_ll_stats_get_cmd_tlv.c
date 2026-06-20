__int64 __fastcall send_process_ll_stats_get_cmd_tlv(__int64 a1, __int64 a2)
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

  v4 = wmi_buf_alloc_fl(a1, 0x18u, "send_process_ll_stats_get_cmd_tlv", 0x1D97u);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  qdf_mem_set(v5, 0x18u, 0);
  *v5 = 18743316;
  v5[3] = *(_DWORD *)a2;
  v5[1] = *(_DWORD *)(a2 + 8);
  v5[2] = *(unsigned __int8 *)(a2 + 4);
  v5[4] = *(_DWORD *)(a2 + 12);
  v5[5] = *(unsigned __int16 *)(a2 + 16);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: LINK_LAYER_STATS - Get Request Params Request ID: %u Stats Type: %0x Vdev ID: %d Peer MAC Addr: %02x:%02x:%02x:**:**:%02x",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "send_process_ll_stats_get_cmd_tlv",
    *(unsigned __int8 *)(a2 + 13),
    *(unsigned __int8 *)(a2 + 14),
    *(unsigned __int8 *)(a2 + 17));
  qdf_mtrace(49, 100, 0xB04u, v5[2], 0);
  if ( (is_service_enabled_tlv(a1, 0x112u, v15, v16, v17, v18, v19, v20, v21, v22) & 1) != 0 )
  {
    result = wmi_unified_cmd_send_over_qmi(a1, v6, 24, 0x16004u);
    if ( !(_DWORD)result )
      return result;
LABEL_10:
    wmi_buf_free();
    return 16;
  }
  if ( (wmi_is_qmi_stats_enabled(a1) & 1) == 0
    || !wmi_is_target_suspended(a1)
    || (result = wmi_unified_cmd_send_over_qmi(a1, v6, 24, 0x16004u), (_DWORD)result) )
  {
    *(_DWORD *)(a1 + 888) = 0;
    result = wmi_unified_cmd_send_fl(
               a1,
               v6,
               0x18u,
               0x16004u,
               "wmi_unified_cmd_send_pm_chk",
               0x400u,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               v31);
    if ( (_DWORD)result )
      goto LABEL_10;
  }
  return result;
}
