__int64 __fastcall dp_pdev_init_wifi3(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  unsigned __int8 *v4; // x19
  __int64 v6; // x21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  __int64 v16; // x23
  unsigned __int64 v17; // x4
  _DWORD *v18; // x9
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  unsigned __int8 *v29; // x23
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w0
  __int64 v39; // x0
  unsigned int v40; // w24
  __int64 v41; // x25
  __int64 v42; // x0
  unsigned int i; // w27
  int v44; // w25
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w28
  __int64 v54; // x25
  _DWORD *v55; // x8
  void (*v56)(void); // x8
  __int64 v57; // x23
  void (*v58)(void); // x8
  char dp_soc_nss_cfg; // w0
  char target_pdev_id; // w0
  __int64 v61; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  int num_tx_spl_desc; // w0
  int v71; // w8
  int v72; // w8
  __int64 v73; // x0
  int num_mac_rings; // w0
  int v75; // w21
  _DWORD *v76; // x8
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  _DWORD *v93; // x8
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x8
  __int64 v103; // x8
  unsigned int (__fastcall *v104)(_QWORD); // x8
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  char is_peer_link_stats_enabled; // w0
  unsigned __int8 v114; // w8
  char v115; // w9
  char v116; // w8
  int v117; // w8
  unsigned int v118; // w19
  unsigned int v119; // w20
  unsigned int v120; // w0
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  unsigned int (__fastcall *v130)(__int64, unsigned __int8 *, __int64, __int64, __int64); // x8
  unsigned int (__fastcall *v131)(__int64, unsigned __int8 *, __int64, __int64, __int64); // x8
  __int64 v132; // x0

  if ( a4 )
    goto LABEL_103;
  v4 = *(unsigned __int8 **)(a1 + 72);
  v6 = *(_QWORD *)(a1 + 40);
  *((_QWORD *)v4 + 1) = a1;
  *v4 = 0;
  v4[3] = 0;
  if ( (unsigned int)dp_wdi_event_attach(v4) )
  {
    qdf_trace_msg(0x3Fu, 2u, "dp_wdi_evet_attach failed", v7, v8, v9, v10, v11, v12, v13, v14);
    return 16;
  }
  v15 = *((_QWORD *)v4 + 1);
  v16 = *(_QWORD *)(v15 + 40);
  if ( (*(_BYTE *)(v15 + 20096) & 2) == 0 )
  {
    v17 = v4[1];
    if ( v17 >= 2 )
      goto LABEL_103;
    v18 = *(_DWORD **)(v15 + 1792);
    v19 = *((_QWORD *)v4 + 1);
    if ( *(v18 - 1) != -386661336 )
      __break(0x8229u);
    if ( ((unsigned int (__fastcall *)(__int64, __int64, __int64, _QWORD))v18)(
           v19,
           v15 + 80LL * (unsigned int)v17 + 80,
           14,
           0) )
    {
      v28 = "%s: %pK: dp_srng_init failed rx refill ring";
      v29 = v4;
LABEL_10:
      qdf_trace_msg(0x7Cu, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "dp_pdev_srng_init", v15);
      dp_pdev_srng_deinit(v29);
      qdf_trace_msg(
        0x7Cu,
        2u,
        "%s: %pK: Failed to initialize pdev srng rings",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "dp_pdev_init",
        a1);
LABEL_99:
      dp_wdi_event_detach(v4);
      return 16;
    }
  }
  v38 = wlan_cfg_per_pdev_lmac_ring(v16);
  v29 = v4;
  if ( v38 )
  {
    if ( (*(_BYTE *)(v15 + 20120) & 1) != 0 )
      goto LABEL_38;
  }
  else
  {
    v29 = *(unsigned __int8 **)(v15 + 72);
    if ( (*(_BYTE *)(v15 + 20120) & 1) != 0 )
      goto LABEL_38;
  }
  v39 = *(_QWORD *)(v15 + 40);
  if ( *(_BYTE *)(v39 + 804) )
  {
    v40 = *v29;
    if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(v39) )
    {
      if ( v40 )
        goto LABEL_103;
      v40 = *(unsigned __int8 *)(*(_QWORD *)(v15 + 72) + 1LL);
    }
    if ( v40 > 2 )
      goto LABEL_103;
    v41 = v15 + 320 + 80LL * v40;
    if ( !*(_QWORD *)v41 )
    {
      v93 = *(_DWORD **)(v15 + 1792);
      if ( *(v93 - 1) != -386661336 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, __int64, __int64, _QWORD, _QWORD))v93)(
             v15,
             v15 + 320 + 80LL * v40,
             15,
             0,
             v40) )
      {
LABEL_66:
        v28 = "%s: %pK:SRNG setup failed forrxdma_err_dst_ring";
        goto LABEL_10;
      }
      if ( v40 == 2 )
        goto LABEL_103;
      wlan_minidump_log(
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        *(_QWORD *)(v41 + 8),
        *(unsigned int *)(v41 + 40),
        *(_QWORD *)(v15 + 16));
    }
    v42 = *(_QWORD *)(v15 + 40);
    if ( *(unsigned __int8 *)(v42 + 804) >= 2u )
    {
      for ( i = 1; i < *(unsigned __int8 *)(v42 + 804); ++i )
      {
        v44 = *v29;
        if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(v42) )
        {
          if ( v44 )
            goto LABEL_103;
          v53 = *(unsigned __int8 *)(*(_QWORD *)(v15 + 72) + 1LL);
          if ( v53 > 2 )
            goto LABEL_103;
        }
        else if ( v44 )
        {
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: Both mac_id and pdev_id cannot be non zero",
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            "dp_get_lmac_id_for_pdev_id");
          v53 = 0;
        }
        else
        {
          v53 = i;
          if ( i > 2 )
            goto LABEL_103;
        }
        v54 = v15 + 320 + 80LL * v53;
        if ( !*(_QWORD *)v54 )
        {
          v55 = *(_DWORD **)(v15 + 1792);
          if ( *(v55 - 1) != -386661336 )
            __break(0x8228u);
          if ( ((unsigned int (__fastcall *)(__int64, __int64, __int64, _QWORD, _QWORD))v55)(
                 v15,
                 v15 + 320 + 80LL * v53,
                 15,
                 0,
                 v53) )
          {
            goto LABEL_66;
          }
          if ( v53 == 2 )
            goto LABEL_103;
          wlan_minidump_log(
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            *(_QWORD *)(v54 + 8),
            *(unsigned int *)(v54 + 40),
            *(_QWORD *)(v15 + 16));
        }
        v42 = *(_QWORD *)(v15 + 40);
      }
    }
  }
LABEL_38:
  if ( (wlan_cfg_is_ipa_enabled(*(_QWORD *)(a1 + 40)) & 1) != 0 )
  {
    v56 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1176LL);
    if ( *((_DWORD *)v56 - 1) != -682698834 )
      __break(0x8228u);
    v56();
    dp_ipa_hal_tx_init_alt_data_ring(a1);
  }
  dp_tx_init_cmd_credit_ring(a1);
  v57 = *((_QWORD *)v4 + 1);
  *((_DWORD *)v4 + 23599) = 0;
  *((_DWORD *)v4 + 23600) = 0;
  if ( (unsigned int)wlan_cfg_per_pdev_tx_ring(*(_QWORD *)(v57 + 40)) )
  {
    if ( *v4 >= 5uLL )
      goto LABEL_103;
    v58 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v57 + 1128) + 74392LL) + 1176LL);
    if ( *((_DWORD *)v58 - 1) != -682698834 )
      __break(0x8228u);
    v58();
  }
  dp_soc_nss_cfg = wlan_cfg_get_dp_soc_nss_cfg(v6);
  wlan_cfg_set_dp_pdev_nss_enabled(*((_QWORD *)v4 + 36), dp_soc_nss_cfg & 1);
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40)) )
    target_pdev_id = wlan_cfg_get_target_pdev_id(*(_QWORD *)(a1 + 40), *(unsigned __int8 *)(*(_QWORD *)(a1 + 72) + 1LL));
  else
    target_pdev_id = 1;
  v4[2] = target_pdev_id;
  if ( *(_BYTE *)(a1 + 18772) == 7 && v4[1] == 2 )
    v4[2] = 2;
  if ( (unsigned int)wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40)) )
  {
    dp_soc_reset_cpu_ring_map(a1);
    dp_soc_reset_intr_mask(a1);
  }
  wlan_cfg_get_dp_soc_dpdk_cfg(*(_QWORD *)(a1 + 16));
  *((_QWORD *)v4 + 37) = 0;
  *((_QWORD *)v4 + 38) = v4 + 296;
  *((_QWORD *)v4 + 34) = -1;
  *((_DWORD *)v4 + 78) = 0;
  *((_QWORD *)v4 + 40) = 0;
  *((_WORD *)v4 + 164) = 0;
  v4[96352] = 0;
  *((_DWORD *)v4 + 88) = 0;
  *((_QWORD *)v4 + 45) = 0;
  *((_DWORD *)v4 + 70) = -1;
  qdf_mem_set(v4 + 384, 0x16F38u, 0);
  dp_local_peer_id_pool_init(v4);
  dp_dscp_tid_map_setup(v4);
  dp_pcp_tid_map_setup(v4);
  dp_pdev_set_default_reo(v4);
  qdf_mem_set(v4 + 95968, 0x90u, 0);
  v61 = _qdf_nbuf_alloc(*(_QWORD *)(*((_QWORD *)v4 + 1) + 24LL), 144, 0, 4, 1, "dp_pdev_init", 16485);
  *((_QWORD *)v4 + 12014) = v61;
  if ( !v61 )
  {
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: Failed to allocate sojourn buf",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "dp_pdev_init",
      a1);
LABEL_98:
    dp_pdev_srng_deinit(v4);
    goto LABEL_99;
  }
  qdf_mem_set(*(void **)(v61 + 224), 0x90u, 0);
  qdf_event_create((_DWORD *)v4 + 24036);
  qdf_event_create((_DWORD *)v4 + 24046);
  qdf_event_create((_DWORD *)v4 + 24056);
  qdf_event_create((_DWORD *)v4 + 24068);
  *((_DWORD *)v4 + 24079) = wlan_cfg_get_max_tx_desc_pool(*(_QWORD *)(a1 + 40));
  num_tx_spl_desc = wlan_cfg_get_num_tx_spl_desc(*(_QWORD *)(a1 + 40));
  v71 = *((_DWORD *)v4 + 24079);
  *((_DWORD *)v4 + 24081) = num_tx_spl_desc;
  v72 = v71 - num_tx_spl_desc;
  v73 = *((_QWORD *)v4 + 36);
  *((_DWORD *)v4 + 24080) = v72;
  num_mac_rings = wlan_cfg_get_num_mac_rings(v73);
  if ( !*v4 )
  {
    v75 = num_mac_rings;
    if ( num_mac_rings >= 1 )
    {
      v76 = *(_DWORD **)(a1 + 1792);
      if ( *(v76 - 1) != -386661336 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, unsigned __int8 *, __int64, __int64, _QWORD))v76)(
             a1,
             v4 + 112,
             14,
             1,
             0) )
      {
        goto LABEL_61;
      }
      if ( v75 != 1 )
      {
        v130 = *(unsigned int (__fastcall **)(__int64, unsigned __int8 *, __int64, __int64, __int64))(a1 + 1792);
        if ( *((_DWORD *)v130 - 1) != -386661336 )
          __break(0x8228u);
        if ( v130(a1, v4 + 192, 14, 1, 1) )
          goto LABEL_61;
        if ( v75 == 2 )
          goto LABEL_68;
        v131 = *(unsigned int (__fastcall **)(__int64, unsigned __int8 *, __int64, __int64, __int64))(a1 + 1792);
        if ( *((_DWORD *)v131 - 1) != -386661336 )
          __break(0x8228u);
        if ( v131(a1, v4 + 272, 14, 1, 2) )
        {
LABEL_61:
          qdf_trace_msg(
            0x7Cu,
            2u,
            "%s: %pK: failed rx mac ring setup",
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            "dp_rxdma_ring_setup",
            a1);
          qdf_trace_msg(
            0x7Cu,
            2u,
            "%s: %pK: RXDMA ring config failed",
            v85,
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            "dp_pdev_init",
            a1);
          goto LABEL_96;
        }
        if ( v75 != 3 )
        {
LABEL_103:
          __break(0x5512u);
          return dp_set_vdev_dscp_tid_map_wifi3();
        }
      }
    }
  }
LABEL_68:
  if ( (unsigned int)dp_pdev_bkp_stats_attach((__int64)v4) )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: dp_pdev_bkp_stats_attach failed",
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      "dp_pdev_init");
    goto LABEL_96;
  }
  v102 = *(_QWORD *)(*((_QWORD *)v4 + 1) + 20112LL);
  if ( !v102 )
    goto LABEL_76;
  v103 = *(_QWORD *)(v102 + 416);
  if ( !v103 || (v104 = *(unsigned int (__fastcall **)(_QWORD))(v103 + 104)) == nullptr )
  {
    qdf_trace_msg(
      0x92u,
      8u,
      "%s: callback not registered",
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      "dp_monitor_pdev_init");
LABEL_95:
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: dp_monitor_pdev_init failed",
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      "dp_pdev_init",
      a1);
    dp_pdev_bkp_stats_detach((__int64)v4);
LABEL_96:
    dp_rxdma_ring_cleanup(a1, v4);
    v132 = *((_QWORD *)v4 + 12014);
    if ( v132 )
      _qdf_nbuf_free(v132);
    goto LABEL_98;
  }
  if ( *((_DWORD *)v104 - 1) != -1116635294 )
    __break(0x8228u);
  if ( v104(v4) )
    goto LABEL_95;
LABEL_76:
  wlan_ipa_logging_sock_init();
  ((void (__fastcall *)(unsigned __int8 *))dp_rx_pdev_desc_pool_init)(v4);
  dp_ipa_rx_desc_list_init(v4);
  ((void (__fastcall *)(unsigned __int8 *))dp_rx_pdev_buffers_alloc)(v4);
  if ( v4 )
  {
    qdf_mem_set(v4 + 92216, 0x7C8u, 0);
    *((_DWORD *)v4 + 24084) = 0;
  }
  is_peer_link_stats_enabled = wlan_cfg_is_peer_link_stats_enabled(*(_QWORD *)(*((_QWORD *)v4 + 1) + 40LL));
  v114 = v4[17];
  if ( (is_peer_link_stats_enabled & 1) != 0 )
    v115 = 2;
  else
    v115 = 0;
  *((_DWORD *)v4 + 5) = 4;
  v4[17] = v114 & 0xFD | v115;
  v116 = *(_BYTE *)(a1 + 13008);
  v4[24] = 0;
  if ( (v116 & 1) != 0 )
    v117 = 65540;
  else
    v117 = 4;
  *((_DWORD *)v4 + 5) = v117;
  v118 = qdf_dma_mem_stats_read();
  v119 = qdf_heap_mem_stats_read();
  v120 = qdf_skb_total_mem_stats_read();
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Mem stats: DMA = %u HEAP = %u SKB = %u",
    v121,
    v122,
    v123,
    v124,
    v125,
    v126,
    v127,
    v128,
    "dp_pdev_init",
    v118,
    v119,
    v120);
  return 0;
}
