__int64 __fastcall dp_txrx_dump_stats(
        __int64 a1,
        unsigned __int16 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x9
  void (__fastcall *v14)(_QWORD); // x8
  unsigned __int64 StatusReg; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x22
  _QWORD *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  char v34; // w20
  void (__fastcall *v35)(_QWORD); // x8
  __int64 v36; // x8
  void (*v37)(void); // x8
  __int64 v38; // x22
  __int64 v39; // x22
  __int64 v40; // x22
  __int64 v41; // x22
  __int64 v42; // x22
  __int64 v43; // x9
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x89u, 2u, "%s: %pK: soc is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "dp_txrx_dump_stats", 0);
    return 4;
  }
  if ( a2 > 0xBu )
  {
    if ( a2 <= 0x1Bu )
    {
      if ( a2 == 12 )
      {
        hif_print_napi_stats(*(_QWORD *)(a1 + 64));
        return 0;
      }
      if ( a2 != 26 )
      {
        if ( a2 == 27 )
        {
          ((void (*)(void))dp_print_swlm_stats)();
          return 0;
        }
        return 4;
      }
      v35 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 352LL);
      if ( v35 )
      {
        if ( *((_DWORD *)v35 - 1) != 1800043527 )
          __break(0x8228u);
        v35(2);
        return 0;
      }
      return 0;
    }
    switch ( a2 )
    {
      case 0x1Cu:
        dp_pdev_print_tx_delay_stats(a1);
        return 0;
      case 0x1Du:
        wlan_dp_lapb_display_stats();
        return 0;
      case 0x1Eu:
        dp_print_txrx_soc_stats();
        return 0;
    }
    return 4;
  }
  if ( a2 <= 4u )
  {
    if ( a2 != 1 )
    {
      if ( a2 == 3 )
      {
        dp_print_tso_stats();
        return 0;
      }
      return 4;
    }
    dp_txrx_path_stats();
    dp_print_soc_interrupt_stats(a1);
    hal_dump_reg_write_stats(*(_QWORD *)(a1 + 1128));
    hal_dump_reg_write_srng_stats(*(_QWORD *)(a1 + 1128));
    dp_pdev_print_tx_delay_stats(a1);
    dp_dump_srng_high_wm_stats(a1, 8193);
    v13 = a1;
    v14 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 352LL);
    if ( v14 )
    {
      if ( *((_DWORD *)v14 - 1) != 1800043527 )
        __break(0x8228u);
      v14(0);
      v13 = a1;
    }
    if ( (wlan_cfg_get_dp_tx_page_pool_enabled(*(_QWORD *)(v13 + 40)) & 1) != 0 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 22448);
      }
      else
      {
        raw_spin_lock_bh(a1 + 22448);
        *(_QWORD *)(a1 + 22456) |= 1uLL;
      }
      v24 = *(_QWORD *)(a1 + 22400);
      v25 = (_QWORD *)a1;
      if ( v24 && *(_BYTE *)(v24 + 56) == 1 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Tx page pool stats:",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "dp_print_tx_page_pool_stats");
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: vdev id %d: success %llu failure %llu",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "dp_print_tx_page_pool_stats",
          0,
          *(_QWORD *)(v24 + 24),
          *(_QWORD *)(v24 + 32));
        v25 = (_QWORD *)a1;
        v34 = 1;
      }
      else
      {
        v34 = 0;
      }
      v38 = v25[2801];
      if ( v38 && *(_BYTE *)(v38 + 56) == 1 )
      {
        if ( (v34 & 1) == 0 )
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Tx page pool stats:",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "dp_print_tx_page_pool_stats");
        v34 = 1;
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: vdev id %d: success %llu failure %llu",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "dp_print_tx_page_pool_stats",
          1,
          *(_QWORD *)(v38 + 24),
          *(_QWORD *)(v38 + 32));
        v25 = (_QWORD *)a1;
      }
      v39 = v25[2802];
      if ( v39 && *(_BYTE *)(v39 + 56) == 1 )
      {
        if ( (v34 & 1) == 0 )
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Tx page pool stats:",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "dp_print_tx_page_pool_stats");
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: vdev id %d: success %llu failure %llu",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "dp_print_tx_page_pool_stats",
          2,
          *(_QWORD *)(v39 + 24),
          *(_QWORD *)(v39 + 32));
        v34 = 1;
        v25 = (_QWORD *)a1;
      }
      v40 = v25[2803];
      if ( v40 && *(_BYTE *)(v40 + 56) == 1 )
      {
        if ( (v34 & 1) == 0 )
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Tx page pool stats:",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "dp_print_tx_page_pool_stats");
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: vdev id %d: success %llu failure %llu",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "dp_print_tx_page_pool_stats",
          3,
          *(_QWORD *)(v40 + 24),
          *(_QWORD *)(v40 + 32));
        v34 = 1;
        v25 = (_QWORD *)a1;
      }
      v41 = v25[2804];
      if ( v41 && *(_BYTE *)(v41 + 56) == 1 )
      {
        if ( (v34 & 1) == 0 )
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Tx page pool stats:",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "dp_print_tx_page_pool_stats");
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: vdev id %d: success %llu failure %llu",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "dp_print_tx_page_pool_stats",
          4,
          *(_QWORD *)(v41 + 24),
          *(_QWORD *)(v41 + 32));
        v34 = 1;
        v25 = (_QWORD *)a1;
      }
      v42 = v25[2805];
      if ( v42 && *(_BYTE *)(v42 + 56) == 1 )
      {
        if ( (v34 & 1) == 0 )
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Tx page pool stats:",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "dp_print_tx_page_pool_stats");
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: vdev id %d: success %llu failure %llu",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "dp_print_tx_page_pool_stats",
          5,
          *(_QWORD *)(v42 + 24),
          *(_QWORD *)(v42 + 32));
        v25 = (_QWORD *)a1;
      }
      v43 = v25[2807];
      if ( (v43 & 1) != 0 )
      {
        v25[2807] = v43 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v25 + 2806);
      }
      else
      {
        raw_spin_unlock(v25 + 2806);
      }
    }
    if ( (wlan_cfg_get_dp_rx_buffer_recycle(*(_QWORD *)(a1 + 40)) & 1) == 0 )
      return 0;
    if ( *(_BYTE *)(a1 + 20664) == 1 )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Rx page pool stats:",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "dp_print_rx_page_pool_stats");
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Pool id %d: success: %llu failure %llu",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "dp_print_rx_page_pool_stats",
        0,
        *(_QWORD *)(a1 + 20672),
        *(_QWORD *)(a1 + 20680));
      if ( (*(_BYTE *)(a1 + 21208) & 1) == 0 )
      {
LABEL_84:
        if ( (*(_BYTE *)(a1 + 21752) & 1) == 0 )
        {
LABEL_90:
          if ( (*(_BYTE *)(a1 + 22296) & 1) == 0 )
            return 0;
LABEL_91:
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Pool id %d: success: %llu failure %llu",
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            "dp_print_rx_page_pool_stats",
            3,
            *(_QWORD *)(a1 + 22304),
            *(_QWORD *)(a1 + 22312));
          return 0;
        }
LABEL_89:
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Pool id %d: success: %llu failure %llu",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "dp_print_rx_page_pool_stats",
          2,
          *(_QWORD *)(a1 + 21760),
          *(_QWORD *)(a1 + 21768));
        goto LABEL_90;
      }
    }
    else
    {
      if ( *(_BYTE *)(a1 + 21208) != 1 )
      {
        if ( (*(_BYTE *)(a1 + 21752) & 1) == 0 )
        {
          if ( *(_BYTE *)(a1 + 22296) != 1 )
            return 0;
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Rx page pool stats:",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "dp_print_rx_page_pool_stats");
          goto LABEL_91;
        }
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Rx page pool stats:",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "dp_print_rx_page_pool_stats");
        goto LABEL_89;
      }
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Rx page pool stats:",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "dp_print_rx_page_pool_stats");
    }
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Pool id %d: success: %llu failure %llu",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      "dp_print_rx_page_pool_stats",
      1,
      *(_QWORD *)(a1 + 21216),
      *(_QWORD *)(a1 + 21224));
    goto LABEL_84;
  }
  if ( a2 != 5 )
  {
    if ( a2 == 6 )
      return 0;
    if ( a2 == 11 )
    {
      ((void (*)(void))dp_print_per_ring_stats)();
      return 0;
    }
    return 4;
  }
  if ( a3 != 1 )
  {
    dp_tx_dump_flow_pool_info_compact();
    return 0;
  }
  if ( !*(_QWORD *)a1 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: invalid instance", a4, a5, a6, a7, a8, a9, a10, a11, "cdp_dump_flow_pool_info");
    return 0;
  }
  v36 = *(_QWORD *)(*(_QWORD *)a1 + 112LL);
  if ( !v36 )
    return 0;
  v37 = *(void (**)(void))(v36 + 32);
  if ( !v37 )
    return 0;
  if ( *((_DWORD *)v37 - 1) != -1106481425 )
    __break(0x8228u);
  v37();
  return 0;
}
