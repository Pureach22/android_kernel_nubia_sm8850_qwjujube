__int64 __fastcall wlan_ipa_cleanup(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x0
  __int64 v4; // x1
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x0
  __int64 v14; // x8
  unsigned int (*v15)(void); // x8
  __int64 v16; // x0
  __int64 v17; // x8
  void (*v18)(void); // x8
  __int64 v19; // x0
  __int64 v20; // x8
  void (*v21)(void); // x8
  __int64 v22; // x1
  __int64 v23; // x1
  __int64 v24; // x1
  __int64 v25; // x1
  __int64 v26; // x1
  _BYTE *v27; // x8
  unsigned int v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  if ( (ipa_cb_is_ready() & 1) == 0 )
    return 0;
  v3 = qdf_event_destroy(a1 + 7392, v2);
  if ( a1 && (**(_DWORD **)(a1 + 1464) & 0x20) == 0 )
  {
    if ( *(_BYTE *)(a1 + 12) )
      *(_BYTE *)(a1 + 12) = 0;
    if ( *(_BYTE *)(a1 + 276) )
      *(_BYTE *)(a1 + 276) = 0;
    if ( *(_BYTE *)(a1 + 540) )
      *(_BYTE *)(a1 + 540) = 0;
    if ( *(_BYTE *)(a1 + 804) )
      *(_BYTE *)(a1 + 804) = 0;
  }
  if ( *(_BYTE *)(a1 + 6984) == 1 )
    v3 = qdf_event_destroy(a1 + 8072, v4);
  if ( *(_BYTE *)(a1 + 7437) == 1 && (wlan_ipa_config_is_opt_wifi_dp_enabled(v3) & 1) != 0 )
  {
    qdf_rtpm_deregister(3u);
    _qdf_wake_lock_destroy(a1 + 0x2000);
    qdf_runtime_lock_deinit((__int64 *)(a1 + 8432));
  }
  v13 = *(_QWORD *)(a1 + 1456);
  if ( v13 && *(_QWORD *)v13 && (v14 = *(_QWORD *)(*(_QWORD *)v13 + 152LL)) != 0 )
  {
    v15 = *(unsigned int (**)(void))(v14 + 216);
    if ( !v15 )
      goto LABEL_24;
    if ( *((_DWORD *)v15 - 1) != 639071501 )
      __break(0x8228u);
    if ( !v15() )
    {
LABEL_24:
      if ( *(_BYTE *)(a1 + 7440) != 1 )
        goto LABEL_44;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v5, v6, v7, v8, v9, v10, v11, v12, "cdp_ipa_get_smmu_mapped");
  }
  v16 = *(_QWORD *)(a1 + 1456);
  if ( v16 && *(_QWORD *)v16 && (v17 = *(_QWORD *)(*(_QWORD *)v16 + 152LL)) != 0 )
  {
    v18 = *(void (**)(void))(v17 + 208);
    if ( v18 )
    {
      if ( *((_DWORD *)v18 - 1) != -1710392634 )
        __break(0x8228u);
      v18();
    }
    v19 = *(_QWORD *)(a1 + 1456);
    if ( !v19 )
      goto LABEL_43;
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v5, v6, v7, v8, v9, v10, v11, v12, "cdp_ipa_set_smmu_mapped");
    v19 = *(_QWORD *)(a1 + 1456);
    if ( !v19 )
      goto LABEL_43;
  }
  if ( *(_QWORD *)v19 )
  {
    v20 = *(_QWORD *)(*(_QWORD *)v19 + 152LL);
    if ( v20 )
    {
      v21 = *(void (**)(void))(v20 + 200);
      if ( v21 )
      {
        if ( *((_DWORD *)v21 - 1) != -712716066 )
          __break(0x8228u);
        v21();
      }
      goto LABEL_44;
    }
  }
LABEL_43:
  qdf_trace_msg(0x45u, 1u, "%s invalid instance", v5, v6, v7, v8, v9, v10, v11, v12, "cdp_ipa_rx_buf_smmu_pool_mapping");
LABEL_44:
  if ( *(_BYTE *)(a1 + 7440) == 1 && *(_BYTE *)(a1 + 7465) == 1 )
  {
    *(_BYTE *)(a1 + 7466) = 1;
    wlan_ipa_ctrl_flt_db_deinit(a1, 0xCDu);
  }
  qdf_event_destroy(a1 + 7800, v4);
  qdf_event_destroy(a1 + 7904, v22);
  qdf_event_destroy(a1 + 8008, v23);
  qdf_event_destroy(a1 + 8152, v24);
  qdf_event_destroy(a1 + 8112, v25);
  qdf_event_destroy(a1 + 7472, v26);
  v27 = *(_BYTE **)(a1 + 1464);
  *(_BYTE *)(a1 + 7513) = 0;
  if ( (*v27 & 0x40) != 0 )
  {
    if ( a1 )
    {
      if ( *(_BYTE *)(a1 + 12) )
        *(_BYTE *)(a1 + 12) = 0;
      if ( *(_BYTE *)(a1 + 276) )
        *(_BYTE *)(a1 + 276) = 0;
      if ( *(_BYTE *)(a1 + 540) )
        *(_BYTE *)(a1 + 540) = 0;
      if ( *(_BYTE *)(a1 + 804) )
        *(_BYTE *)(a1 + 804) = 0;
    }
    if ( *(_BYTE *)(a1 + 6984) == 1 )
      cancel_work_sync(a1 + 7304);
  }
  wlan_ipa_flush(a1);
  cancel_work_sync(a1 + 3312);
  if ( (**(_BYTE **)(a1 + 1464) & 0x20) != 0 )
  {
    v28 = ipa_wdi_cleanup_per_inst(*(unsigned int *)(a1 + 7460));
    if ( v28 )
      qdf_trace_msg(
        0x61u,
        4u,
        "%s: ipa_wdi_cleanup failed ret=%d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "wlan_ipa_wdi_cleanup",
        v28);
    qdf_mutex_destroy(a1 + 4040);
    qdf_mutex_destroy(a1 + 7224);
    if ( *(_DWORD *)(a1 + 4032) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "qdf_list_destroy");
  }
  gp_ipa = 0;
  *(_BYTE *)(a1 + 7457) = 0;
  return 0;
}
