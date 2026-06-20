__int64 __fastcall dp_soc_attach_target_wifi3(_QWORD *a1)
{
  _QWORD *v2; // x25
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned __int8 *v12; // x20
  int num_mac_rings; // w21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x2
  __int64 v23; // x2
  __int64 (__fastcall *v24)(_QWORD); // x8
  __int64 v25; // x0
  char v26; // w0
  __int64 v27; // x4
  unsigned int v28; // w23
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x22
  __int64 v38; // x21
  __int64 v39; // x27
  int v40; // w23
  unsigned int v41; // w28
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w26
  __int64 v51; // x2
  __int64 v52; // x8
  __int64 v53; // x24
  _DWORD *v54; // x8
  unsigned int v55; // w0
  _DWORD *v56; // x8
  unsigned int v57; // w23
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x8
  __int64 v67; // x8
  void (__fastcall *v68)(_QWORD); // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x8
  const char *v78; // x2
  const char *v79; // x2
  __int64 v80; // x8
  void (__fastcall *v81)(_QWORD); // x8
  __int64 (__fastcall *v82)(_QWORD); // x8
  unsigned int v83; // w0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  const char *v92; // x2
  __int64 v93; // x0
  __int64 v94; // x1
  _DWORD *v95; // x8
  __int64 v96; // x8
  void (*v97)(void); // x8
  __int64 v98; // x8
  void (*v99)(void); // x9
  __int64 (*v100)(void); // x8
  __int64 v102; // [xsp+8h] [xbp-28h] BYREF
  __int64 v103; // [xsp+10h] [xbp-20h] BYREF
  __int64 v104; // [xsp+18h] [xbp-18h] BYREF
  _QWORD *v105; // [xsp+20h] [xbp-10h]
  __int64 v106; // [xsp+28h] [xbp-8h]

  v2 = a1 + 2048;
  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[6];
  v104 = 0;
  v105 = nullptr;
  v102 = 0;
  v103 = 0;
  htt_soc_attach_target(v3);
  v12 = (unsigned __int8 *)a1[9];
  if ( v12 )
  {
    num_mac_rings = wlan_cfg_get_num_mac_rings(*((_QWORD *)v12 + 36));
    if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(a1[5]) && *(_BYTE *)(a1[9] + 1LL) )
LABEL_88:
      __break(0x5512u);
    v22 = a1[10];
    if ( v22 )
      htt_srng_setup(a1[6], 0, v22, 14);
    v23 = a1[2311];
    if ( v23 )
      htt_srng_setup(a1[6], 0, v23, 14);
    v24 = *(__int64 (__fastcall **)(_QWORD))(a1[1] + 40LL);
    if ( v24 )
    {
      v25 = a1[2];
      if ( *((_DWORD *)v24 - 1) != -1548408 )
        __break(0x8228u);
      v26 = v24(v25);
      v27 = v26 & 1;
      v28 = (v26 & 1) != 0 ? num_mac_rings : 1;
    }
    else
    {
      v27 = 0;
      v28 = 1;
    }
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: dbs_enable %d, max_mac_rings %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "dp_update_num_mac_rings_for_dbs",
      v27,
      v28);
    dp_local_pkt_capture_tx_config(v12);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: pdev_id %d max_mac_rings %d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "dp_rxdma_ring_config",
      *v12,
      v28);
    if ( (int)v28 >= 1 )
    {
      v37 = 0;
      v38 = v28;
      v39 = 112;
      do
      {
        v40 = *v12;
        if ( v37 && *v12 )
        {
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: Both mac_id and pdev_id cannot be non zero",
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            "dp_get_mac_id_for_pdev");
          v40 = *v12;
          v41 = 0;
        }
        else
        {
          v41 = v37 + v40;
        }
        if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(a1[5]) )
        {
          if ( v40 )
            goto LABEL_88;
          v50 = *(unsigned __int8 *)(a1[9] + 1LL);
        }
        else if ( v37 && v40 )
        {
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: Both mac_id and pdev_id cannot be non zero",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "dp_get_lmac_id_for_pdev_id");
          v50 = 0;
        }
        else
        {
          v50 = v37 + v40;
        }
        qdf_trace_msg(0x45u, 5u, "%s: mac_id %d", v42, v43, v44, v45, v46, v47, v48, v49, "dp_rxdma_ring_config", v41);
        if ( v37 == 2 )
          goto LABEL_88;
        v51 = *(_QWORD *)&v12[v39];
        if ( v51 )
          htt_srng_setup(a1[6], v41, v51, 14);
        if ( (v2[460] & 1) == 0 )
          dp_htt_setup_rxdma_err_dst_ring(a1, v41, v50);
        v52 = a1[2507];
        if ( v52 )
        {
          v53 = *(_QWORD *)(v52 + 416);
          if ( !v53 )
          {
            qdf_trace_msg(
              0x92u,
              2u,
              "%s: monitor_ops is NULL",
              v4,
              v5,
              v6,
              v7,
              v8,
              v9,
              v10,
              v11,
              "dp_monitor_htt_srng_setup");
            v57 = 16;
LABEL_72:
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: Failed to send htt monitor messages to target",
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              "dp_rxdma_ring_config");
            v92 = "%s: Failed to send htt srng setup messages to target";
LABEL_73:
            qdf_trace_msg(0x45u, 2u, v92, v84, v85, v86, v87, v88, v89, v90, v91, "dp_soc_attach_target_wifi3");
            goto LABEL_87;
          }
          v54 = *(_DWORD **)(v53 + 208);
          if ( v54 )
          {
            if ( *(v54 - 1) != -421235120 )
              __break(0x8228u);
            v55 = ((__int64 (__fastcall *)(_QWORD *, unsigned __int8 *, _QWORD, _QWORD))v54)(a1, v12, v50, v41);
            if ( v55 )
              goto LABEL_45;
          }
          v56 = *(_DWORD **)(v53 + 216);
          if ( v56 )
          {
            if ( *(v56 - 1) != -421235120 )
              __break(0x8228u);
            v55 = ((__int64 (__fastcall *)(_QWORD *, unsigned __int8 *, _QWORD, _QWORD))v56)(a1, v12, v50, v41);
            if ( v55 )
            {
LABEL_45:
              v57 = v55;
              qdf_trace_msg(
                0x92u,
                2u,
                "%s: error: %d",
                v4,
                v5,
                v6,
                v7,
                v8,
                v9,
                v10,
                v11,
                "dp_monitor_htt_srng_setup",
                v55);
              goto LABEL_72;
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x92u,
            8u,
            "%s: monitor soc is NULL",
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            "dp_monitor_htt_srng_setup");
        }
        ++v37;
        v39 += 80;
      }
      while ( v38 != v37 );
    }
  }
  v66 = a1[2507];
  if ( v66 )
  {
    v67 = *(_QWORD *)(v66 + 416);
    if ( v67 )
    {
      v68 = *(void (__fastcall **)(_QWORD))(v67 + 520);
      if ( v68 )
      {
        if ( *((_DWORD *)v68 - 1) != -1093861181 )
          __break(0x8228u);
        v68(a1);
        v77 = a1[2507];
        if ( !v77 )
          goto LABEL_52;
        goto LABEL_56;
      }
    }
    v79 = "%s: callback not registered";
  }
  else
  {
    v79 = "%s: monitor soc is NULL";
  }
  qdf_trace_msg(0x92u, 8u, v79, v4, v5, v6, v7, v8, v9, v10, v11, "dp_monitor_reap_timer_init");
  v77 = a1[2507];
  if ( !v77 )
  {
LABEL_52:
    v78 = "%s: monitor soc is NULL";
    goto LABEL_62;
  }
LABEL_56:
  v80 = *(_QWORD *)(v77 + 416);
  if ( v80 )
  {
    v81 = *(void (__fastcall **)(_QWORD))(v80 + 488);
    if ( v81 )
    {
      if ( *((_DWORD *)v81 - 1) != -1093861181 )
        __break(0x8228u);
      v81(a1);
      goto LABEL_63;
    }
  }
  v78 = "%s: callback not registered";
LABEL_62:
  qdf_trace_msg(0x92u, 8u, v78, v69, v70, v71, v72, v73, v74, v75, v76, "dp_monitor_vdev_timer_init");
LABEL_63:
  v82 = (__int64 (__fastcall *)(_QWORD))a1[157];
  if ( *((_DWORD *)v82 - 1) != -1941278151 )
    __break(0x8228u);
  v83 = v82(a1);
  if ( v83 )
  {
    v57 = v83;
    v92 = "%s: Failed to send htt ring config message to target";
    goto LABEL_73;
  }
  qdf_mem_set(a1 + 1664, 0x1078u, 0);
  hif_rtpm_register(4u, 0);
  hif_rtpm_register(5u, 0);
  *((_DWORD *)v2 + 886) = 0;
  a1[2240] = htt_t2h_stats_handler;
  a1[2236] = 0xFFFFFFFE00000LL;
  a1[2241] = a1;
  a1[2237] = a1 + 2237;
  a1[2238] = a1 + 2237;
  v93 = a1[5];
  v94 = a1[2];
  a1[2239] = _qdf_defer_func;
  wlan_cfg_soc_update_tgt_params(v93, v94);
  qdf_mem_set(&v102, 0x20u, 0);
  if ( (wlan_cfg_is_rx_hash_enabled(a1[5]) & 1) != 0 )
  {
    v95 = (_DWORD *)a1[161];
    if ( *(v95 - 1) != 1077837737 )
      __break(0x8228u);
    LOBYTE(v102) = (((__int64 (__fastcall *)(_QWORD *, char *, __int64 *, char *))v95)(
                      a1,
                      (char *)&v102 + 4,
                      &v103,
                      (char *)&v103 + 4)
                  & 1) != 0;
  }
  dp_reo_frag_dst_set(a1, &v104);
  if ( (unsigned int)wlan_cfg_get_dp_soc_nss_cfg(a1[5]) )
    BYTE1(v104) = 5;
  v96 = *(_QWORD *)(a1[141] + 74392LL);
  v105 = a1 + 2512;
  v97 = *(void (**)(void))(v96 + 32);
  if ( *((_DWORD *)v97 - 1) != -903505142 )
    __break(0x8228u);
  v97();
  v98 = *(_QWORD *)(a1[141] + 74392LL);
  v99 = *(void (**)(void))(v98 + 56);
  if ( v99 )
  {
    if ( *((_DWORD *)v99 - 1) != 251140989 )
      __break(0x8229u);
    v99();
    v98 = *(_QWORD *)(a1[141] + 74392LL);
  }
  v100 = *(__int64 (**)(void))(v98 + 64);
  if ( v100 )
  {
    if ( *((_DWORD *)v100 - 1) != -2091637267 )
      __break(0x8228u);
    LOBYTE(v100) = v100() & 1;
  }
  v57 = 0;
  *((_BYTE *)v2 + 3656) = v2[457] & 0xFE | (unsigned __int8)v100;
LABEL_87:
  _ReadStatusReg(SP_EL0);
  return v57;
}
