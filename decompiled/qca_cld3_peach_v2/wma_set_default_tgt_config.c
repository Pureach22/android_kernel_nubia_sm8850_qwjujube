__int64 __fastcall wma_set_default_tgt_config(__int64 a1, int *a2, __int64 a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w8
  int v15; // w9
  int v16; // w9
  _DWORD *v17; // x22
  int max_peer_count; // w8
  __int64 values; // x0
  char v20; // w8
  int conparam; // w0
  __int64 ndp_max_sessions; // x0
  char is_enabled; // w0
  __int64 v24; // x0
  int v25; // w22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x0
  int v35; // w21
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 result; // x0

  qdf_mem_set(a2, 0x188u, 0);
  v14 = *(_DWORD *)(a3 + 124);
  *a2 = v14;
  if ( a1 )
  {
    v15 = *(unsigned __int8 *)(a1 + 3360);
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMA handle (via %s)",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "__wma_validate_handle",
      "wma_get_ini_handle");
    v14 = *a2;
    v15 = 1;
  }
  a2[1] = v15 + v14 + 2;
  a2[6] = 2 * (v15 + (unsigned __int8)v14) + 4;
  a2[3] = *(unsigned __int8 *)(a3 + 12) + 1;
  v16 = *(unsigned __int8 *)(a3 + 13);
  *((_QWORD *)a2 + 14) = 0x42000000003LL;
  v17 = a2 + 28;
  *(_QWORD *)(a2 + 19) = 0;
  *(_QWORD *)(a2 + 7) = 0x700000010LL;
  *(_QWORD *)(a2 + 23) = 0;
  *(_QWORD *)(a2 + 9) = 0x6400000007LL;
  *(_QWORD *)(a2 + 25) = 0;
  *(_QWORD *)(a2 + 11) = 0x6400000064LL;
  a2[27] = 0;
  *(_QWORD *)(a2 + 13) = 0x200000028LL;
  *(_QWORD *)(a2 + 15) = 0x400000008LL;
  *(_QWORD *)(a2 + 17) = 0x800000003LL;
  *(_QWORD *)(a2 + 21) = 0x40000000000LL;
  a2[4] = v16 + 1;
  a2[5] = 2;
  a2[30] = 10;
  a2[45] = 1;
  if ( (unsigned __int16)cfg_tdls_get_max_peer_count(*(_QWORD *)(a1 + 24)) <= 8u )
    max_peer_count = (unsigned __int16)cfg_tdls_get_max_peer_count(*(_QWORD *)(a1 + 24));
  else
    max_peer_count = 8;
  a2[46] = max_peer_count;
  a2[57] = 2;
  *(_QWORD *)(a2 + 47) = 0x2000000003LL;
  *(_QWORD *)(a2 + 49) = 0x600000000LL;
  a2[59] = 4;
  *(_QWORD *)(a2 + 51) = 0x100000000LL;
  *(_QWORD *)(a2 + 53) = 1;
  *(_QWORD *)(a2 + 55) = 0x200000001LL;
  a2[67] = 32;
  values = cfg_psoc_get_values(*(_QWORD *)(a1 + 24));
  v20 = *((_BYTE *)a2 + 168) | 6;
  a2[33] = *(unsigned __int8 *)(values + 2345);
  *((_BYTE *)a2 + 168) = v20;
  a2[81] = ucfg_pmo_get_sap_mode_bus_suspend(*(_QWORD *)(a1 + 24)) & 1;
  a2[82] = ucfg_pmo_get_go_mode_bus_suspend(*(_QWORD *)(a1 + 24)) & 1;
  a2[90] = policy_mgr_get_max_conc_cxns(*(_QWORD *)(a1 + 24));
  a2[91] = (unsigned __int8)wlan_mlme_get_sta_mlo_conn_max_num(*(_QWORD *)(a1 + 24));
  cfg_nan_get_max_ndi(*(_QWORD *)(a1 + 24), a2 + 79);
  a2[96] = *(_DWORD *)(cfg_psoc_get_values(*(_QWORD *)(a1 + 24)) + 10508);
  conparam = cds_get_conparam();
  if ( conparam == 4 )
  {
    v17 = a2 + 14;
    goto LABEL_11;
  }
  if ( conparam == 5 )
  {
    *(_QWORD *)(a2 + 3) = 0;
    *((_QWORD *)a2 + 8) = 0;
    a2[18] = 0;
    *(_QWORD *)(a2 + 47) = 1;
LABEL_11:
    *v17 = 0;
  }
  ndp_max_sessions = cfg_nan_get_ndp_max_sessions(*(_QWORD *)(a1 + 24), a2 + 78);
  is_enabled = ucfg_ipa_is_enabled(ndp_max_sessions);
  *((_BYTE *)a2 + 261) = 0;
  *((_BYTE *)a2 + 368) = 1;
  *((_BYTE *)a2 + 288) = (is_enabled & 1) == 0;
  *((_BYTE *)a2 + 377) = *(_BYTE *)(cfg_psoc_get_values(*(_QWORD *)(a1 + 24)) + 8652);
  v24 = cfg_psoc_get_values(*(_QWORD *)(a1 + 24));
  v25 = *(unsigned __int8 *)(v24 + 3992);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: SMEM mailbox feature cfg value: %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "wma_is_smem_mailbox_supported",
    *(unsigned __int8 *)(v24 + 3992));
  if ( v25 == 1 && *(_BYTE *)(cfg_psoc_get_values(*(_QWORD *)(a1 + 24)) + 3992) == 1 )
    *((_BYTE *)a2 + 373) = 1;
  v34 = cfg_psoc_get_values(*(_QWORD *)(a1 + 24));
  v35 = *(unsigned __int8 *)(v34 + 4000);
  result = qdf_trace_msg(
             0x36u,
             8u,
             "%s: EPM enable feature cfg value: %d",
             v36,
             v37,
             v38,
             v39,
             v40,
             v41,
             v42,
             v43,
             "wma_is_epm_supported_cfg",
             *(unsigned __int8 *)(v34 + 4000));
  if ( v35 == 1 )
    *((_BYTE *)a2 + 374) = 1;
  *((_BYTE *)a2 + 389) = *(_BYTE *)(a3 + 147);
  return result;
}
