__int64 __fastcall wlan_cp_stats_pdev_obj_create_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x19
  __int64 v20; // x0
  __int64 comp_private_obj; // x0
  __int64 v22; // x21
  unsigned int (__fastcall *v23)(_QWORD); // x8
  unsigned int v24; // w20
  unsigned int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x22
  __int64 v35; // x0
  __int64 v36; // x24
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  _DWORD *v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  const char *v54; // x2
  unsigned int v55; // w1
  void (__fastcall *v56)(_QWORD); // x8
  _BYTE v58[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v59; // [xsp+8h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: PDEV is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_cp_stats_pdev_obj_create_handler");
    v24 = 4;
    goto LABEL_37;
  }
  v10 = _qdf_mem_malloc(0x28u, "wlan_cp_stats_pdev_obj_create_handler", 366);
  if ( !v10 )
  {
    v24 = 2;
    goto LABEL_37;
  }
  v19 = (_QWORD *)v10;
  v20 = *(_QWORD *)(a1 + 80);
  if ( !v20 || (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v20, 0x1Bu)) == 0 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: cp_stats context is NULL!",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_cp_stats_pdev_obj_create_handler");
    v24 = 4;
LABEL_36:
    _qdf_mem_free((__int64)v19);
    goto LABEL_37;
  }
  *v19 = a1;
  v22 = comp_private_obj;
  v23 = *(unsigned int (__fastcall **)(_QWORD))(comp_private_obj + 96);
  if ( v23 )
  {
    if ( *((_DWORD *)v23 - 1) != 747383827 )
      __break(0x8228u);
    if ( v23(v19) )
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: Failed to initialize pdev handlers",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wlan_cp_stats_pdev_obj_create_handler");
      v24 = 16;
      goto LABEL_32;
    }
  }
  v25 = wlan_objmgr_pdev_component_obj_attach(a1, 0x1Bu, (__int64)v19, 0, v11, v12, v13, v14, v15, v16, v17, v18);
  v34 = *(_QWORD *)(a1 + 80);
  v24 = v25;
  v58[0] = 0;
  if ( !v34 )
  {
    v54 = "%s: PSOC is NULL";
LABEL_27:
    v55 = 2;
LABEL_30:
    qdf_trace_msg(0x62u, v55, v54, v26, v27, v28, v29, v30, v31, v32, v33, "wlan_cp_stats_enable_init_cstats");
    goto LABEL_31;
  }
  if ( !wlan_objmgr_psoc_get_comp_private_obj(v34, 0x1Bu) )
  {
    v54 = "%s: CP Stats Context is NULL";
    goto LABEL_27;
  }
  target_if_cp_stats_is_service_cstats_enabled(v34, v58, v26, v27, v28, v29, v30, v31, v32, v33);
  if ( v58[0] != 1 )
    goto LABEL_29;
  v35 = wlan_objmgr_psoc_get_comp_private_obj(v34, 0x1Bu);
  if ( !v35 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: CP Stats Context is NULL",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_cp_stats_get_chipset_stats_enable");
    goto LABEL_29;
  }
  if ( (*(_BYTE *)(v35 + 32) & 1) == 0 )
  {
LABEL_29:
    v54 = "%s: Chipset Stats is disabled";
    v55 = 8;
    goto LABEL_30;
  }
  v36 = *(_QWORD *)(v34 + 2128);
  if ( !v36 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: tx_ops is NULL",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "target_if_cp_stats_get_tx_ops");
    v54 = "%s: could not get tx_ops";
    goto LABEL_27;
  }
  if ( !*(_QWORD *)(v36 + 336) )
  {
    v54 = "%s: could not get send_cstats_enable";
    goto LABEL_27;
  }
  if ( (unsigned int)qdf_reg_qmi_indication(v26, v27, v28, v29, v30, v31, v32, v33) )
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: cstats QMI evt handler registration failed",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "wlan_cp_stats_cstats_register_qmi_event_handler");
  v45 = *(_DWORD **)(v36 + 336);
  if ( *(v45 - 1) != -138336238 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _QWORD))v45)(v34, 1, 0);
LABEL_31:
  qdf_trace_msg(
    0x62u,
    8u,
    "%s: pdev cp stats object attached",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    "wlan_cp_stats_pdev_obj_create_handler");
  if ( v24 )
  {
LABEL_32:
    v56 = *(void (__fastcall **)(_QWORD))(v22 + 104);
    if ( v56 )
    {
      if ( *((_DWORD *)v56 - 1) != 747383827 )
        __break(0x8228u);
      v56(v19);
    }
    goto LABEL_36;
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return v24;
}
