__int64 __fastcall send_unified_ll_stats_get_sta_cmd_tlv(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x22
  __int64 v6; // x19
  unsigned int v7; // w8
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x6
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
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

  v4 = wmi_buf_alloc_fl(a1, 0x20u, "send_unified_ll_stats_get_sta_cmd_tlv", 0x1E25u);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 61079580;
  v7 = a2[2];
  v5[6] = 73999;
  v5[1] = v7;
  if ( (wlan_cp_stats_is_bcn_rssi_history_report_cfg_enable(**(_QWORD **)(a1 + 760)) & 1) != 0 )
    v5[6] |= 0x80000u;
  v8 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3664LL);
  if ( *((_DWORD *)v8 - 1) != -2112860426 )
    __break(0x8228u);
  v5[7] = v8(a1, 255);
  v9 = (unsigned int)v5[6];
  v5[2] = *((unsigned __int8 *)a2 + 4);
  v5[3] = *a2;
  v5[4] = a2[3];
  v5[5] = *((unsigned __int16 *)a2 + 8);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: UNIFIED_LINK_STATS_GET_STA - Get Request Params Request ID: %u Stats Type: %0x Stats Id: %u Vdev ID: %d Peer MAC"
    " Addr: %02x:%02x:%02x:**:**:%02x",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "send_unified_ll_stats_get_sta_cmd_tlv",
    *a2,
    a2[2],
    v9,
    *((unsigned __int8 *)a2 + 4),
    *((unsigned __int8 *)a2 + 12),
    *((unsigned __int8 *)a2 + 13),
    *((unsigned __int8 *)a2 + 14),
    *((unsigned __int8 *)a2 + 17));
  qdf_mtrace(49, 100, 0xB10u, *((_BYTE *)a2 + 4), 0);
  if ( (is_service_enabled_tlv(a1, 0x112u, v18, v19, v20, v21, v22, v23, v24, v25) & 1) != 0 )
  {
    result = wmi_unified_cmd_send_over_qmi(a1, v6, 32, 0x16010u);
    if ( !(_DWORD)result )
      return result;
LABEL_14:
    wmi_buf_free();
    return 16;
  }
  if ( (wmi_is_qmi_stats_enabled(a1) & 1) == 0
    || !wmi_is_target_suspended(a1)
    || (result = wmi_unified_cmd_send_over_qmi(a1, v6, 32, 0x16010u), (_DWORD)result) )
  {
    *(_DWORD *)(a1 + 888) = 0;
    result = wmi_unified_cmd_send_fl(
               a1,
               v6,
               0x20u,
               0x16010u,
               "wmi_unified_cmd_send_pm_chk",
               0x400u,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               v34);
    if ( (_DWORD)result )
      goto LABEL_14;
  }
  return result;
}
