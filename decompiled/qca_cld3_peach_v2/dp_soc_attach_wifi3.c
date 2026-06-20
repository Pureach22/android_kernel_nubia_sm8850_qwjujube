__int64 *__fastcall dp_soc_attach_wifi3(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *v10; // x25
  unsigned int v11; // w23
  unsigned int v14; // w21
  char v15; // w24
  __int64 v16; // x26
  __int64 v17; // x27
  size_t soc_context_size; // x0
  __int64 *v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  __int64 v29; // x8
  _QWORD *v30; // x0
  __int64 v31; // x8
  void (__fastcall *v32)(char *, __int64 *); // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  __int64 (__fastcall *v42)(_QWORD); // x9
  __int64 v43; // x0
  char v44; // w0
  int v45; // w8
  char v46; // w9
  bool v47; // zf
  char v48; // w8
  char v49; // w9
  int v50; // w8
  __int64 v51; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  void (__fastcall *v60)(_QWORD); // x8
  __int64 v61; // x0
  __int64 v62; // x1
  void (__fastcall *v63)(_QWORD); // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  unsigned int (__fastcall *v88)(__int64 *, __int64); // x8
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  void (__fastcall *v137)(_QWORD); // x8
  unsigned int v139; // w20
  unsigned int v140; // w21
  unsigned int v141; // w0
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7

  v10 = *(_QWORD **)a2;
  if ( !*(_QWORD *)a2 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: HIF handle is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "dp_soc_attach");
    return nullptr;
  }
  v11 = *(unsigned __int16 *)(a2 + 32);
  v14 = 0;
  v15 = 1;
  if ( v11 <= 0xABBF )
  {
    if ( v11 - 4352 <= 0x12 )
    {
      if ( ((1 << v11) & 0x74680) != 0 )
        goto LABEL_9;
      if ( ((1 << v11) & 0x3B) != 0 )
        goto LABEL_18;
    }
    if ( v11 - 43536 >= 2 && v11 != 264 )
    {
LABEL_17:
      v15 = 0;
      v14 = 0xFFFF;
    }
  }
  else
  {
    if ( *(unsigned __int16 *)(a2 + 32) > 0xFFF5u )
    {
      if ( ((1 << (v11 + 10)) & 0x3F4) != 0 )
        goto LABEL_18;
      goto LABEL_9;
    }
    if ( v11 - 43968 >= 4 )
    {
      if ( v11 != 45054 )
      {
        if ( v11 == 49136 )
        {
          v14 = 2;
          goto LABEL_18;
        }
        goto LABEL_17;
      }
LABEL_9:
      v14 = 1;
    }
  }
LABEL_18:
  v16 = *(_QWORD *)(a2 + 16);
  v17 = *(_QWORD *)(a2 + 24);
  soc_context_size = dp_get_soc_context_size();
  v19 = (__int64 *)_qdf_mem_malloc(soc_context_size, "dp_soc_attach", 15397);
  if ( v19 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: soc memory allocated %pK",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "dp_soc_attach",
      v19);
    v19[8] = (__int64)v10;
    v28 = v10[320];
    v19[141] = v28;
    if ( v28 )
    {
      v19[2509] = v10[502];
      v29 = v10[503];
      *((_DWORD *)v19 + 476) = v11;
      *((_BYTE *)v19 + 20268) = -1;
      v19[2510] = v29;
      v19[2511] = v29;
      v30 = (_QWORD *)_qdf_mem_malloc(0xB8u, "dp_soc_attach", 15416);
      *v19 = (__int64)v30;
      if ( v30 )
      {
        *v30 = &dp_ops_cmn;
        *(_QWORD *)(*v19 + 8) = &dp_ops_ctrl;
        *(_QWORD *)(*v19 + 16) = &dp_ops_me;
        *(_QWORD *)(*v19 + 32) = &dp_ops_host_stats;
        *(_QWORD *)(*v19 + 40) = &dp_ops_wds;
        *(_QWORD *)(*v19 + 48) = &dp_ops_raw;
        *(_QWORD *)(*v19 + 64) = &dp_ops_misc;
        *(_QWORD *)(*v19 + 80) = &dp_ops_ocb;
        *(_QWORD *)(*v19 + 72) = dp_ops_peer;
        *(_QWORD *)(*v19 + 88) = &dp_ops_mob_stats;
        *(_QWORD *)(*v19 + 104) = &dp_ops_cfg;
        *(_QWORD *)(*v19 + 112) = dp_ops_flowctl;
        *(_QWORD *)(*v19 + 120) = &dp_ops_l_flowctl;
        *(_QWORD *)(*v19 + 128) = &dp_ops_throttle;
        *(_QWORD *)(*v19 + 152) = dp_ops_ipa;
        *(_QWORD *)(*v19 + 136) = dp_ops_bus;
        *(_QWORD *)(*v19 + 168) = dp_ops_cfr;
        v19[1] = v17;
        v19[2] = a1;
        v31 = v19[141];
        v19[3] = v16;
        *((_BYTE *)v19 + 1122) = 2;
        v32 = *(void (__fastcall **)(char *, __int64 *))(*(_QWORD *)(v31 + 74392) + 1216LL);
        if ( *((_DWORD *)v32 - 1) != -98416908 )
          __break(0x8228u);
        v32((char *)v19 + 1138, v19 + 142);
        v41 = v19[141];
        v42 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v41 + 74392) + 1672LL);
        if ( v42 )
        {
          v43 = *(unsigned __int8 *)(a2 + 48);
          if ( *((_DWORD *)v42 - 1) != 2116364946 )
            __break(0x8229u);
          v44 = v42(v43);
          v41 = v19[141];
        }
        else
        {
          v44 = 1;
        }
        *((_BYTE *)v19 + 20128) = v44;
        v45 = *(unsigned __int8 *)(v41 + 74540);
        v46 = *((_BYTE *)v19 + 20096);
        *((_WORD *)v19 + 10032) = v14;
        v47 = v45 == 0;
        v48 = v46 & 0xFD;
        if ( v47 )
          v49 = 0;
        else
          v49 = 2;
        *((_BYTE *)v19 + 20096) = v48 | v49;
        if ( (v15 & 1) != 0 )
        {
          v50 = dword_B28CF0[(__int16)v14];
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: unknown arch_id 0x%x",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "dp_get_link_desc_id_start",
            v14);
          v50 = 0x8000;
        }
        *((_DWORD *)v19 + 5017) = v50;
        dp_configure_arch_ops((__int64)v19);
        *((_BYTE *)v19 + 18784) = 0;
        v19[2349] = 0;
        v19[2350] = 0;
        *((_DWORD *)v19 + 4702) = 0;
        wlan_set_srng_cfg(v19 + 2343);
        v51 = wlan_cfg_soc_attach(v19[2]);
        v19[5] = v51;
        if ( v51 )
        {
          v60 = *(void (__fastcall **)(_QWORD))(v19[1] + 280);
          if ( v60 )
          {
            v61 = v19[2];
            if ( *((_DWORD *)v60 - 1) != 1603432812 )
              __break(0x8228u);
            v60(v61);
            v62 = v19[5];
          }
          else
          {
            v62 = v51;
          }
          *((_DWORD *)v19 + 5626) = 0;
          v19[2814] = 0;
          ((void (__fastcall *)(const char *, __int64, __int64))qdf_ssr_driver_dump_register_region)(
            "wlan_cfg_ctx",
            v62,
            840);
          v63 = (void (__fastcall *)(_QWORD))v19[158];
          if ( *((_DWORD *)v63 - 1) != -1093861181 )
            __break(0x8228u);
          v63(v19);
          ((void (__fastcall *)(const char *, __int64, __int64))qdf_ssr_driver_dump_register_region)(
            "tcl_wbm_map_array",
            v19[5] + 776,
            4);
          if ( (unsigned int)((__int64 (__fastcall *)(__int64 *, __int64))dp_hw_link_desc_pool_banks_alloc)(
                               v19,
                               0xFFFFFFFFLL) )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: failed to allocate link desc pool banks",
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              v70,
              v71,
              "dp_soc_attach");
          }
          else
          {
            if ( (unsigned int)dp_hw_link_desc_ring_alloc(v19) )
            {
              qdf_trace_msg(
                0x45u,
                2u,
                "%s: failed to allocate link_desc_ring",
                v80,
                v81,
                v82,
                v83,
                v84,
                v85,
                v86,
                v87,
                "dp_soc_attach");
            }
            else
            {
              v88 = (unsigned int (__fastcall *)(__int64 *, __int64))v19[143];
              if ( *((_DWORD *)v88 - 1) != -109292952 )
                __break(0x8228u);
              if ( v88(v19, a2) )
              {
                qdf_trace_msg(
                  0x45u,
                  2u,
                  "%s: unable to do target specific attach",
                  v89,
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  v95,
                  v96,
                  "dp_soc_attach");
              }
              else
              {
                if ( (unsigned int)dp_soc_srng_alloc(v19) )
                {
                  qdf_trace_msg(
                    0x45u,
                    2u,
                    "%s: failed to allocate soc srng rings",
                    v97,
                    v98,
                    v99,
                    v100,
                    v101,
                    v102,
                    v103,
                    v104,
                    "dp_soc_attach");
                }
                else
                {
                  if ( (unsigned int)dp_soc_tx_desc_sw_pools_alloc(v19) )
                  {
                    qdf_trace_msg(
                      0x45u,
                      2u,
                      "%s: dp_soc_tx_desc_sw_pools_alloc failed",
                      v105,
                      v106,
                      v107,
                      v108,
                      v109,
                      v110,
                      v111,
                      v112,
                      "dp_soc_attach");
                  }
                  else
                  {
                    if ( (unsigned int)dp_mon_soc_attach(v19) )
                    {
                      qdf_trace_msg(
                        0x45u,
                        2u,
                        "%s: failed to attach monitor",
                        v113,
                        v114,
                        v115,
                        v116,
                        v117,
                        v118,
                        v119,
                        v120,
                        "dp_soc_attach");
                    }
                    else
                    {
                      if ( (unsigned int)dp_sysfs_initialize_stats(v19) )
                      {
                        qdf_trace_msg(
                          0x45u,
                          2u,
                          "%s: failed to initialize dp stats sysfs file",
                          v121,
                          v122,
                          v123,
                          v124,
                          v125,
                          v126,
                          v127,
                          v128,
                          "dp_soc_attach");
                        dp_sysfs_deinitialize_stats(v19);
                      }
                      wlan_dp_lapb_flow_attach(v19);
                      if ( !(unsigned int)dp_setup_ipa_rx_refill_buf_ring(v19) )
                      {
                        ((void (__fastcall *)(__int64 *))dp_soc_swlm_attach)(v19);
                        dp_soc_set_interrupt_mode((__int64)v19);
                        dp_soc_set_def_pdev(v19);
                        dp_soc_set_qref_debug_list(v19);
                        ((void (__fastcall *)(const char *, __int64 *, __int64))qdf_ssr_driver_dump_register_region)(
                          "dp_soc",
                          v19,
                          22528);
                        v139 = qdf_dma_mem_stats_read();
                        v140 = qdf_heap_mem_stats_read();
                        v141 = qdf_skb_total_mem_stats_read();
                        qdf_trace_msg(
                          0x45u,
                          5u,
                          "%s: Mem stats: DMA = %u HEAP = %u SKB = %u",
                          v142,
                          v143,
                          v144,
                          v145,
                          v146,
                          v147,
                          v148,
                          v149,
                          "dp_soc_attach",
                          v139,
                          v140,
                          v141);
                        return v19;
                      }
                      qdf_trace_msg(
                        0x7Cu,
                        2u,
                        "%s: %pK: dp_srng_alloc failed rxrefill2 ring",
                        v129,
                        v130,
                        v131,
                        v132,
                        v133,
                        v134,
                        v135,
                        v136,
                        "dp_soc_attach",
                        v19);
                      dp_mon_soc_detach(v19);
                    }
                    ((void (__fastcall *)(__int64 *))dp_soc_tx_desc_sw_pools_free)(v19);
                  }
                  ((void (__fastcall *)(__int64 *))dp_soc_srng_free)(v19);
                }
                v137 = (void (__fastcall *)(_QWORD))v19[144];
                if ( *((_DWORD *)v137 - 1) != -1941278151 )
                  __break(0x8228u);
                v137(v19);
              }
              dp_hw_link_desc_ring_free(v19);
            }
            v72 = ((double (__fastcall *)(__int64 *, __int64))dp_hw_link_desc_pool_banks_free)(v19, 0xFFFFFFFFLL);
          }
          wlan_minidump_remove(v72, v73, v74, v75, v76, v77, v78, v79, v19[5], 840, v19[2]);
          wlan_cfg_soc_detach(v19[5]);
        }
        else
        {
          qdf_trace_msg(0x45u, 2u, "%s: wlan_cfg_ctx failed", v52, v53, v54, v55, v56, v57, v58, v59, "dp_soc_attach");
        }
        _qdf_mem_free(*v19);
      }
    }
    _qdf_mem_free((__int64)v19);
    return nullptr;
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: DP SOC memory allocation failed",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "dp_soc_attach");
  return v19;
}
