__int64 __fastcall wlan_cp_stats_psoc_obj_create_handler(
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
  _QWORD *v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  int v20; // w8
  unsigned int v21; // w20
  unsigned int (*v23)(void); // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  void (__fastcall *v33)(_QWORD); // x8
  _QWORD *v34; // x0
  _QWORD *v35; // x21
  unsigned int (*v36)(void); // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  void (__fastcall *v54)(_QWORD); // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7

  if ( !a1 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: PSOC is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_cp_stats_psoc_obj_create_handler");
    return 4;
  }
  v10 = (_QWORD *)_qdf_mem_malloc(0xB8u, "wlan_cp_stats_psoc_obj_create_handler", 248);
  if ( !v10 )
    return 2;
  v10[2] = a1;
  v19 = (__int64)v10;
  v20 = *(_DWORD *)(a1 + 12);
  if ( v20 == 1 )
  {
    v23 = (unsigned int (*)(void))wlan_cp_stats_ctx_init_ol;
    v10[8] = wlan_cp_stats_ctx_init_ol;
    v10[9] = wlan_cp_stats_ctx_deinit_ol;
  }
  else
  {
    if ( v20 == 3 )
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: Failed to init cp stats ctx, bad device type",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wlan_cp_stats_psoc_obj_create_handler");
      v21 = 4;
      goto LABEL_14;
    }
    v23 = (unsigned int (*)(void))v10[8];
  }
  if ( *((_DWORD *)v23 - 1) != -709288359 )
    __break(0x8228u);
  if ( v23() )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: Failed to init global ctx call back handlers",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_cp_stats_psoc_obj_create_handler");
    v21 = 16;
  }
  else
  {
    v34 = (_QWORD *)_qdf_mem_malloc(0x48u, "wlan_cp_stats_psoc_obj_create_handler", 270);
    if ( v34 )
    {
      *v34 = a1;
      v35 = v34;
      v36 = *(unsigned int (**)(void))(v19 + 80);
      *(_QWORD *)(v19 + 24) = v34;
      if ( !v36 )
        goto LABEL_28;
      if ( *((_DWORD *)v36 - 1) != -1169049694 )
        __break(0x8228u);
      if ( v36() )
      {
        qdf_trace_msg(
          0x62u,
          2u,
          "%s: Failed to initialize psoc handlers",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "wlan_cp_stats_psoc_obj_create_handler");
        v45 = 16;
      }
      else
      {
LABEL_28:
        v45 = wlan_objmgr_psoc_component_obj_attach(a1, 0x1Bu, v19, 0);
        if ( !v45 )
        {
          wlan_cp_stats_init_cfg(a1, v19, v46, v47, v48, v49, v50, v51, v52, v53);
          *(_QWORD *)(v19 + 40) = *(unsigned int *)(cfg_psoc_get_values(a1) + 4012);
          *(_QWORD *)(v19 + 48) = *(unsigned int *)(cfg_psoc_get_values(a1) + 4012);
          wlan_cp_stats_cstats_init(a1);
          *(_BYTE *)(v19 + 56) = *(_BYTE *)(cfg_psoc_get_values(a1) + 1144);
          qdf_trace_msg(
            0x62u,
            8u,
            "%s: cp stats context attach at psoc",
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            "wlan_cp_stats_psoc_obj_create_handler");
          return 0;
        }
      }
      v54 = *(void (__fastcall **)(_QWORD))(v19 + 88);
      v21 = v45;
      if ( v54 )
      {
        if ( *((_DWORD *)v54 - 1) != -1169049694 )
          __break(0x8228u);
        v54(v35);
      }
    }
    else
    {
      v21 = 2;
    }
  }
LABEL_14:
  v32 = *(_QWORD *)(v19 + 24);
  if ( v32 )
  {
    _qdf_mem_free(v32);
    *(_QWORD *)(v19 + 24) = 0;
  }
  v33 = *(void (__fastcall **)(_QWORD))(v19 + 72);
  if ( v33 )
  {
    if ( *((_DWORD *)v33 - 1) != -709288359 )
      __break(0x8228u);
    v33(v19);
  }
  _qdf_mem_free(v19);
  return v21;
}
