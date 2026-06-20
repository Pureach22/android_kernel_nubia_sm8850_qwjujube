__int64 __fastcall send_unified_ll_stats_get_sta_cmd_tlv(__int64 a1, unsigned int *a2)
{
  unsigned int v4; // w21
  __int64 v5; // x0
  __int64 v6; // x23
  __int64 v7; // x19
  unsigned int v8; // w8
  __int64 (__fastcall *v9)(__int64, __int64); // x8
  __int64 v10; // x6
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // [xsp+0h] [xbp-20h]

  if ( *((_BYTE *)a2 + 18) )
    v4 = 56;
  else
    v4 = 32;
  v5 = wmi_buf_alloc_fl(a1, v4, "send_unified_ll_stats_get_sta_cmd_tlv", 0x1E25u);
  if ( !v5 )
    return 2;
  v6 = *(_QWORD *)(v5 + 224);
  v7 = v5;
  *(_DWORD *)v6 = 61079580;
  v8 = a2[2];
  *(_DWORD *)(v6 + 24) = 73999;
  *(_DWORD *)(v6 + 4) = v8;
  if ( (wlan_cp_stats_is_bcn_rssi_history_report_cfg_enable(**(_QWORD **)(a1 + 760)) & 1) != 0 )
    *(_DWORD *)(v6 + 24) |= 0x80000u;
  v9 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3680LL);
  if ( *((_DWORD *)v9 - 1) != -2112860426 )
    __break(0x8228u);
  *(_DWORD *)(v6 + 28) = v9(a1, 255);
  v10 = *(unsigned int *)(v6 + 24);
  *(_DWORD *)(v6 + 8) = *((unsigned __int8 *)a2 + 4);
  *(_DWORD *)(v6 + 12) = *a2;
  *(_DWORD *)(v6 + 16) = a2[3];
  *(_DWORD *)(v6 + 20) = *((unsigned __int16 *)a2 + 8);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: UNIFIED_LINK_STATS_GET_STA - Get Request Params Request ID: %u Stats Type: %0x Stats Id: %u Vdev ID: %d Peer MAC"
    " Addr: %02x:%02x:%02x:**:**:%02x",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "send_unified_ll_stats_get_sta_cmd_tlv",
    *a2,
    a2[2],
    v10,
    *((unsigned __int8 *)a2 + 4),
    *((unsigned __int8 *)a2 + 12),
    *((unsigned __int8 *)a2 + 13),
    *((unsigned __int8 *)a2 + 14),
    *((unsigned __int8 *)a2 + 17));
  if ( *((_BYTE *)a2 + 18) == 1 )
  {
    *(_QWORD *)(v6 + 32) = 0x10000400120000LL;
    *(_DWORD *)(v6 + 40) = a2[5];
    *(_DWORD *)(v6 + 44) = 1245192;
    *(_DWORD *)(v6 + 48) = a2[6];
    *(_DWORD *)(v6 + 52) = *((unsigned __int16 *)a2 + 14);
    LODWORD(v44) = *((unsigned __int8 *)a2 + 29);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: MLO vdev_id_bitmap: 0x%x MLD MAC Addr: %02x:%02x:%02x:**:**:%02x",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wmi_update_tlv_headers_for_mlo_stats",
      a2[5],
      *((unsigned __int8 *)a2 + 24),
      *((unsigned __int8 *)a2 + 25),
      *((unsigned __int8 *)a2 + 26),
      v44);
  }
  qdf_mtrace(49, 100, 0xB10u, *((_BYTE *)a2 + 4), 0);
  if ( (is_service_enabled_tlv(a1, 0x112u, v27, v28, v29, v30, v31, v32, v33, v34) & 1) != 0 )
  {
    result = wmi_unified_cmd_send_over_qmi(a1, v7, v4, 0x16010u);
    if ( !(_DWORD)result )
      return result;
LABEL_19:
    wmi_buf_free();
    return 16;
  }
  if ( (wmi_is_qmi_stats_enabled(a1) & 1) == 0
    || !wmi_is_target_suspended(a1)
    || (result = wmi_unified_cmd_send_over_qmi(a1, v7, v4, 0x16010u), (_DWORD)result) )
  {
    *(_DWORD *)(a1 + 888) = 0;
    result = wmi_unified_cmd_send_fl(
               a1,
               v7,
               v4,
               0x16010u,
               "wmi_unified_cmd_send_pm_chk",
               0x400u,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               v43);
    if ( (_DWORD)result )
      goto LABEL_19;
  }
  return result;
}
