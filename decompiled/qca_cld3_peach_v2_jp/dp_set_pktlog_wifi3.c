__int64 __fastcall dp_set_pktlog_wifi3(unsigned __int8 *a1, int a2, char a3)
{
  int num_mac_rings; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x20
  __int64 v16; // x8
  __int64 v17; // x25
  __int64 v18; // x24
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
  char v35; // w22
  __int64 v36; // x1
  int v37; // w9
  char v38; // w8
  int v39; // w22
  __int64 v40; // x2
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  void (__fastcall *v57)(_QWORD); // x8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  int v75; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v76; // [xsp+8h] [xbp-8h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  num_mac_rings = wlan_cfg_get_num_mac_rings(*((_QWORD *)a1 + 36));
  v15 = *((_QWORD *)a1 + 1);
  v75 = num_mac_rings;
  if ( !v15 )
    goto LABEL_62;
  v16 = *(_QWORD *)(v15 + 20056);
  if ( !v16 )
    goto LABEL_62;
  v17 = *(_QWORD *)(v16 + 416);
  if ( !v17 )
    goto LABEL_62;
  v18 = *((_QWORD *)a1 + 11945);
  dp_update_num_mac_rings_for_dbs(v15, &v75, v7, v8, v9, v10, v11, v12, v13, v14);
  qdf_trace_msg(
    0x3Fu,
    8u,
    "%s: Max_mac_rings %d ",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "dp_set_pktlog_wifi3",
    (unsigned int)v75);
  if ( (a3 & 1) == 0 )
  {
    if ( a2 > 266 )
    {
      if ( a2 != 267 )
      {
        if ( a2 == 292 )
          *(_BYTE *)(v18 + 39098) = 0;
        goto LABEL_62;
      }
    }
    else if ( a2 != 265 )
    {
      if ( a2 != 266 || v75 < 1 )
        goto LABEL_62;
      v35 = 0;
      while ( 1 )
      {
        if ( v35 && *a1 )
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: Both mac_id and pdev_id cannot be non zero",
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            "dp_get_mac_id_for_pdev");
        v37 = *(unsigned __int8 *)(v18 + 37256);
        v38 = *(_BYTE *)(v18 + 39099);
        *(_BYTE *)(v18 + 39156) = 0;
        if ( v37 )
        {
          if ( (v38 & 1) == 0 && !*(_DWORD *)(v18 + 39100) )
          {
            v36 = 20071;
            goto LABEL_16;
          }
        }
        else if ( (v38 & 1) == 0 && !*(_DWORD *)(v18 + 39100) )
        {
          v36 = 0;
          goto LABEL_16;
        }
        v36 = 28671;
LABEL_16:
        ((void (__fastcall *)(unsigned __int8 *, __int64))dp_h2t_cfg_stats_msg_send)(a1, v36);
        if ( v75 <= (unsigned __int8)++v35 )
          goto LABEL_62;
      }
    }
    if ( !*(_QWORD *)(v18 + 16) && *(_BYTE *)(v18 + 39097) )
    {
      *(_BYTE *)(v18 + 39097) = 0;
      dp_mon_filter_reset_rx_pkt_log_full(a1);
      if ( (unsigned int)dp_mon_filter_update(a1)
        || (dp_mon_filter_reset_rx_pkt_log_lite(a1), (unsigned int)dp_mon_filter_update(a1)) )
      {
        qdf_trace_msg(
          0x89u,
          2u,
          "%s: %pK: Pktlog filters reset failed",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "dp_set_pktlog_wifi3",
          v15);
      }
      else
      {
        dp_monitor_reap_timer_stop(v15, 0);
      }
    }
    goto LABEL_62;
  }
  if ( a2 > 266 )
  {
    if ( a2 == 267 )
    {
      if ( *(_QWORD *)(v18 + 16) || *(_BYTE *)(v18 + 39097) == 2 )
        goto LABEL_62;
      *(_BYTE *)(v18 + 39097) = 2;
      dp_mon_filter_setup_rx_pkt_log_lite(a1);
      if ( (unsigned int)dp_mon_filter_update(a1) )
      {
        qdf_trace_msg(
          0x89u,
          2u,
          "%s: %pK: Pktlog lite filters set failed",
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          "dp_set_pktlog_wifi3",
          v15);
        dp_mon_filter_reset_rx_pkt_log_lite(a1);
        *(_BYTE *)(v18 + 39097) = 0;
        goto LABEL_62;
      }
    }
    else
    {
      if ( a2 != 292 )
      {
        if ( a2 == 295 )
          qdf_trace_msg(
            0x89u,
            2u,
            "%s: Hybrid mode is supported only on beryllium",
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            "dp_set_hybrid_pktlog_enable");
        goto LABEL_62;
      }
      if ( *(_QWORD *)(v18 + 16) || (*(_BYTE *)(v18 + 39098) & 1) != 0 )
        goto LABEL_62;
      *(_BYTE *)(v18 + 39098) = 1;
      *(_BYTE *)v18 = 1;
      v57 = *(void (__fastcall **)(_QWORD))(v17 + 464);
      if ( v57 )
      {
        if ( *((_DWORD *)v57 - 1) != -1116635294 )
          __break(0x8228u);
        v57(a1);
      }
      qdf_trace_msg(
        0x38u,
        4u,
        "%s: Non mon mode: Enable destination ring",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "dp_set_pktlog_wifi3");
      dp_mon_filter_setup_rx_pkt_log_cbf(a1);
      if ( (unsigned int)dp_mon_filter_update(a1) )
      {
        qdf_trace_msg(
          0x92u,
          2u,
          "%s: Pktlog set CBF filters failed",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "dp_set_pktlog_wifi3");
        dp_mon_filter_reset_rx_pktlog_cbf(a1);
        *(_BYTE *)(v18 + 39097) = 0;
        *(_BYTE *)v18 = 0;
        goto LABEL_62;
      }
    }
LABEL_60:
    dp_monitor_reap_timer_start(v15, 0);
    goto LABEL_62;
  }
  if ( a2 == 265 )
  {
    if ( *(_QWORD *)(v18 + 16) || *(_BYTE *)(v18 + 39097) == 1 )
      goto LABEL_62;
    *(_BYTE *)(v18 + 39097) = 1;
    dp_mon_filter_setup_rx_pkt_log_full(a1);
    if ( (unsigned int)dp_mon_filter_update(a1) )
    {
      qdf_trace_msg(
        0x89u,
        2u,
        "%s: %pK: Pktlog full filters set failed",
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        "dp_set_pktlog_wifi3",
        v15);
      dp_mon_filter_reset_rx_pkt_log_full(a1);
      *(_BYTE *)(v18 + 39097) = 0;
      goto LABEL_62;
    }
    goto LABEL_60;
  }
  if ( a2 == 266 && v75 >= 1 )
  {
    v39 = 0;
    do
    {
      if ( (_BYTE)v39 && *a1 )
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Both mac_id and pdev_id cannot be non zero",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "dp_get_mac_id_for_pdev");
        v40 = 0;
      }
      else
      {
        v40 = (unsigned int)*a1 + v39;
      }
      *(_BYTE *)(v18 + 39156) = 1;
      ((void (__fastcall *)(unsigned __int8 *, __int64, __int64))dp_h2t_cfg_stats_msg_send)(a1, 0x3FFF, v40);
      ++v39;
    }
    while ( v75 > (unsigned __int8)v39 );
  }
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return 0;
}
