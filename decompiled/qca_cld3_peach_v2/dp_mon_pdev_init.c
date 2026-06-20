__int64 __fastcall dp_mon_pdev_init(
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
  __int64 v10; // x20
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x8
  _QWORD *v22; // x22
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int (__fastcall *v32)(_QWORD); // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v42; // x23
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int (__fastcall *v52)(_QWORD); // x8
  __int64 v53; // x8
  __int64 v54; // x8
  __int64 v55; // x23
  __int64 (__fastcall *v56)(_QWORD); // x8
  unsigned int v57; // w0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 (__fastcall *v66)(_QWORD); // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  void (__fastcall *v75)(_QWORD); // x8
  void (__fastcall *v76)(_QWORD); // x8
  void (__fastcall *v77)(_QWORD); // x8
  unsigned int (__fastcall *v78)(_QWORD); // x8
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  void (__fastcall *v87)(_QWORD); // x8
  void (__fastcall *v88)(_QWORD); // x8
  void (__fastcall *v89)(_QWORD); // x8

  if ( !a1 )
  {
    qdf_trace_msg(0x92u, 2u, "%s: pdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_pdev_init");
    return 16;
  }
  v10 = *(_QWORD *)(a1 + 96456);
  v11 = _qdf_mem_malloc(0x10u, "dp_mon_pdev_init", 6303);
  *(_QWORD *)(v10 + 39280) = v11;
  if ( !v11 )
  {
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: %pK: Memory allocation failed for invalid monitor peer",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "dp_mon_pdev_init",
      a1);
    return 2;
  }
  v20 = *(_QWORD *)(a1 + 8);
  if ( !v20 || (v21 = *(_QWORD *)(v20 + 20112)) == 0 || (v22 = *(_QWORD **)(v21 + 416)) == nullptr )
  {
    qdf_trace_msg(0x92u, 2u, "%s: Monitor ops is NULL", v12, v13, v14, v15, v16, v17, v18, v19, "dp_mon_pdev_init");
LABEL_14:
    _qdf_mem_free(*(_QWORD *)(v10 + 39280));
    return 16;
  }
  v23 = dp_mon_filter_alloc(v10);
  *(_QWORD *)(v10 + 37064) = v23;
  if ( !v23 )
  {
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: %pK: Memory allocation failed for monitor filter",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "dp_mon_pdev_init",
      a1);
    goto LABEL_14;
  }
  v32 = (unsigned int (__fastcall *)(_QWORD))v22[84];
  if ( v32 )
  {
    if ( *((_DWORD *)v32 - 1) != -1116635294 )
      __break(0x8228u);
    if ( v32(a1) )
    {
      qdf_trace_msg(
        0x92u,
        2u,
        "%s: %pK: Memory allocation failed for tx monitor filter",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "dp_mon_pdev_init",
        a1);
LABEL_48:
      dp_mon_filter_dealloc(v10);
      goto LABEL_14;
    }
  }
  *(_QWORD *)(v10 + 37240) = 0;
  *(_DWORD *)(v10 + 39160) = 0;
  *(_QWORD *)(v10 + 39168) = 0;
  *(_DWORD *)(v10 + 37224) = 0;
  *(_QWORD *)(v10 + 37232) = 0;
  *(_DWORD *)(v10 + 32) = 3;
  *(_DWORD *)(v10 + 18560) = 3;
  *(_QWORD *)(v10 + 37248) = v10 + 37240;
  *(_BYTE *)(v10 + 37218) = 0;
  *(_BYTE *)v10 = 0;
  if ( v10 )
  {
    *(_BYTE *)(v10 + 37072) = 3;
    *(_WORD *)(v10 + 37074) = -289;
    *(_QWORD *)(v10 + 37076) = -1;
    *(_WORD *)(v10 + 37084) = -1;
  }
  *(_QWORD *)(v10 + 39176) = 0;
  *(_QWORD *)(v10 + 39184) = v10 + 39176;
  *(_QWORD *)(v10 + 39192) = 0;
  *(_QWORD *)(v10 + 39200) = v10 + 39192;
  *(_QWORD *)(v10 + 39216) = 0;
  v42 = *(_QWORD *)(a1 + 96456);
  v43 = _qdf_mem_malloc(0x800u, "dp_htt_ppdu_stats_attach", 853);
  *(_QWORD *)(v42 + 39256) = v43;
  if ( !v43 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: ppdu_tlv_buf alloc fail",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "dp_htt_ppdu_stats_attach");
    goto LABEL_44;
  }
  v52 = (unsigned int (__fastcall *)(_QWORD))v22[120];
  if ( v52 )
  {
    if ( *((_DWORD *)v52 - 1) != -1116635294 )
      __break(0x8228u);
    if ( v52(a1) )
    {
      qdf_trace_msg(
        0x92u,
        2u,
        "%s: %pK: lite mon alloc failed",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "dp_mon_pdev_init",
        a1);
LABEL_43:
      dp_htt_ppdu_stats_detach(a1);
LABEL_44:
      v76 = (void (__fastcall *)(_QWORD))v22[85];
      if ( v76 )
      {
        if ( *((_DWORD *)v76 - 1) != -1557217772 )
          __break(0x8228u);
        v76(a1);
      }
      goto LABEL_48;
    }
  }
  v53 = *(_QWORD *)(a1 + 8);
  if ( !v53 || (v54 = *(_QWORD *)(v53 + 20112)) == 0 || (v55 = *(_QWORD *)(v54 + 416)) == 0 )
  {
    qdf_trace_msg(0x92u, 2u, "%s: mon_ops is NULL", v44, v45, v46, v47, v48, v49, v50, v51, "dp_mon_rings_init");
LABEL_39:
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: %pK: MONITOR rings setup failed",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "dp_mon_pdev_init",
      a1);
    v75 = (void (__fastcall *)(_QWORD))v22[121];
    if ( !v75 )
      goto LABEL_43;
LABEL_40:
    if ( *((_DWORD *)v75 - 1) != -1557217772 )
      __break(0x8228u);
    v75(a1);
    goto LABEL_43;
  }
  v56 = *(__int64 (__fastcall **)(_QWORD))(v55 + 720);
  if ( v56 )
  {
    if ( *((_DWORD *)v56 - 1) != -1116635294 )
      __break(0x8228u);
    v57 = v56(a1);
    if ( v57 )
      goto LABEL_36;
  }
  v66 = *(__int64 (__fastcall **)(_QWORD))(v55 + 728);
  if ( v66 )
  {
    if ( *((_DWORD *)v66 - 1) != -1116635294 )
      __break(0x8228u);
    v57 = v66(a1);
    if ( v57 )
    {
LABEL_36:
      qdf_trace_msg(0x92u, 2u, "%s: error: %d", v58, v59, v60, v61, v62, v63, v64, v65, "dp_mon_rings_init", v57);
      goto LABEL_39;
    }
  }
  v77 = (void (__fastcall *)(_QWORD))v22[96];
  if ( v77 )
  {
    if ( *((_DWORD *)v77 - 1) != -1557217772 )
      __break(0x8228u);
    v77(a1);
  }
  v78 = (unsigned int (__fastcall *)(_QWORD))v22[94];
  if ( v78 )
  {
    if ( *((_DWORD *)v78 - 1) != -1116635294 )
      __break(0x8228u);
    if ( v78(a1) )
    {
      qdf_trace_msg(
        0x92u,
        2u,
        "%s: %pK: rx mon buffers alloc failed",
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        "dp_mon_pdev_init",
        a1);
      v87 = (void (__fastcall *)(_QWORD))v22[97];
      if ( v87 )
      {
        if ( *((_DWORD *)v87 - 1) != -1557217772 )
          __break(0x8228u);
        v87(a1);
      }
      dp_mon_rings_deinit(a1);
      v75 = (void (__fastcall *)(_QWORD))v22[121];
      if ( !v75 )
        goto LABEL_43;
      goto LABEL_40;
    }
  }
  dp_monitor_tx_ppdu_stats_attach(a1);
  v88 = (void (__fastcall *)(_QWORD))v22[116];
  if ( v88 )
  {
    if ( *((_DWORD *)v88 - 1) != -1116635294 )
      __break(0x8228u);
    v88(a1);
  }
  v89 = (void (__fastcall *)(_QWORD))v22[118];
  if ( v89 )
  {
    if ( *((_DWORD *)v89 - 1) != -1116635294 )
      __break(0x8228u);
    v89(a1);
  }
  *(_BYTE *)(v10 + 39272) = 1;
  dp_mon_set_local_pkt_capture_running(v10, 0);
  dp_ch_band_lmac_id_mapping_init(a1);
  return 0;
}
