__int64 __fastcall dp_mon_pdev_deinit(
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
  __int64 v9; // x8
  __int64 v10; // x8
  _QWORD *v11; // x22
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  void (__fastcall *v22)(_QWORD); // x8
  void (__fastcall *v23)(_QWORD); // x8
  __int64 v24; // x8
  __int64 v25; // x8
  void (__fastcall *v26)(_QWORD); // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v36; // x2
  void (__fastcall *v37)(_QWORD); // x8
  void (__fastcall *v38)(_QWORD); // x8
  void (__fastcall *v39)(_QWORD); // x8
  __int64 v40; // x8
  __int64 v41; // x8
  __int64 v42; // x24
  void (__fastcall *v43)(_QWORD); // x8
  void (__fastcall *v44)(_QWORD); // x8
  __int64 v45; // x0
  __int64 v46; // x23
  _QWORD *v47; // x8
  __int64 v48; // x24
  _QWORD *v49; // x9
  void (__fastcall *v50)(_QWORD); // x8
  __int64 v51; // x0

  v9 = *(_QWORD *)(a1 + 8);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 20112)) == 0 || (v11 = *(_QWORD **)(v10 + 416)) == nullptr )
  {
    qdf_trace_msg(0x92u, 2u, "%s: Monitor ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_pdev_deinit");
    return 16;
  }
  v13 = *(_QWORD *)(a1 + 96456);
  if ( *(_BYTE *)(v13 + 39272) == 1 )
  {
    dp_mon_filters_reset(a1);
    v22 = (void (__fastcall *)(_QWORD))v11[117];
    if ( v22 )
    {
      if ( *((_DWORD *)v22 - 1) != -1116635294 )
        __break(0x8228u);
      v22(a1);
    }
    v23 = (void (__fastcall *)(_QWORD))v11[119];
    if ( v23 )
    {
      if ( *((_DWORD *)v23 - 1) != -1116635294 )
        __break(0x8228u);
      v23(a1);
    }
    v24 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 20112LL);
    if ( v24 )
    {
      v25 = *(_QWORD *)(v24 + 416);
      if ( v25 )
      {
        v26 = *(void (__fastcall **)(_QWORD))(v25 + 320);
        if ( v26 )
        {
          if ( *((_DWORD *)v26 - 1) != -1557217772 )
            __break(0x8228u);
          v26(a1);
          goto LABEL_23;
        }
      }
      v36 = "%s: callback not registered";
    }
    else
    {
      v36 = "%s: monitor soc is NULL";
    }
    qdf_trace_msg(0x92u, 8u, v36, v14, v15, v16, v17, v18, v19, v20, v21, "dp_monitor_tx_ppdu_stats_detach");
LABEL_23:
    v37 = (void (__fastcall *)(_QWORD))v11[121];
    if ( v37 )
    {
      if ( *((_DWORD *)v37 - 1) != -1557217772 )
        __break(0x8228u);
      v37(a1);
    }
    v38 = (void (__fastcall *)(_QWORD))v11[95];
    if ( v38 )
    {
      if ( *((_DWORD *)v38 - 1) != -1557217772 )
        __break(0x8228u);
      v38(a1);
    }
    v39 = (void (__fastcall *)(_QWORD))v11[97];
    if ( v39 )
    {
      if ( *((_DWORD *)v39 - 1) != -1557217772 )
        __break(0x8228u);
      v39(a1);
    }
    v40 = *(_QWORD *)(a1 + 8);
    if ( v40 && (v41 = *(_QWORD *)(v40 + 20112)) != 0 && (v42 = *(_QWORD *)(v41 + 416)) != 0 )
    {
      v43 = *(void (__fastcall **)(_QWORD))(v42 + 736);
      if ( v43 )
      {
        if ( *((_DWORD *)v43 - 1) != -1557217772 )
          __break(0x8228u);
        v43(a1);
      }
      v44 = *(void (__fastcall **)(_QWORD))(v42 + 744);
      if ( v44 )
      {
        if ( *((_DWORD *)v44 - 1) != -1557217772 )
          __break(0x8228u);
        v44(a1);
      }
    }
    else
    {
      qdf_trace_msg(0x92u, 2u, "%s: mon_ops is NULL", v27, v28, v29, v30, v31, v32, v33, v34, "dp_mon_rings_deinit");
    }
    dp_htt_ppdu_stats_detach(a1);
    v45 = *(_QWORD *)(*(_QWORD *)(a1 + 96456) + 37240LL);
    if ( v45 )
    {
      v46 = *(_QWORD *)(a1 + 96456) + 37248LL;
      do
      {
        v48 = *(_QWORD *)(v45 + 32);
        v47 = *(_QWORD **)(v45 + 40);
        v49 = (_QWORD *)(v48 + 40);
        if ( !v48 )
          v49 = (_QWORD *)v46;
        *v49 = v47;
        *v47 = *(_QWORD *)(v45 + 32);
        *(_QWORD *)(v45 + 32) = 0;
        *(_QWORD *)(v45 + 40) = 0;
        _qdf_mem_free(v45);
        v45 = v48;
      }
      while ( v48 );
    }
    v50 = (void (__fastcall *)(_QWORD))v11[85];
    if ( v50 )
    {
      if ( *((_DWORD *)v50 - 1) != -1557217772 )
        __break(0x8228u);
      v50(a1);
    }
    if ( *(_QWORD *)(v13 + 37064) )
      dp_mon_filter_dealloc(v13);
    v51 = *(_QWORD *)(v13 + 39280);
    if ( v51 )
      _qdf_mem_free(v51);
    *(_BYTE *)(v13 + 39272) = 0;
    dp_mon_set_local_pkt_capture_running(v13, 0);
  }
  return 0;
}
