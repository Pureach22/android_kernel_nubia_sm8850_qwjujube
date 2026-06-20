__int64 __fastcall ipa3_conn_wdi3_pipes(__int64 a1, _QWORD *a2, __int64 a3)
{
  unsigned int v6; // w23
  unsigned int v7; // w28
  unsigned int ep_mapping; // w24
  unsigned int v9; // w0
  unsigned int v10; // w25
  __int64 v11; // x9
  __int64 v12; // x27
  _DWORD *v13; // x26
  int v14; // w0
  __int64 v15; // x9
  _DWORD *v16; // x9
  int v17; // t1
  __int64 v18; // x8
  int v19; // w0
  char v20; // w0
  __int64 v21; // x3
  __int64 v22; // x4
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  int v29; // w0
  __int64 v30; // x3
  __int64 v31; // x4
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x2
  __int64 v41; // x1
  __int64 v42; // x8
  int v43; // w23
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x2
  __int64 v48; // x0
  __int64 v49; // x9
  int v50; // w23
  int v51; // w9
  int v52; // w8
  int v53; // w27
  __int64 v54; // x8
  __int64 v55; // x0
  __int64 v56; // x0
  unsigned int v57; // w23
  int v58; // w0
  __int64 v59; // x4
  __int64 v60; // x8
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x2
  __int64 v66; // x1
  __int64 v67; // x8
  int v68; // w19
  __int64 v69; // x8
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x8
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x8
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x8
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x8
  __int64 v84; // x0
  __int64 v85; // x0
  __int64 v86; // x8
  __int64 v87; // x0
  __int64 v88; // x0
  int v89; // w20
  __int64 v90; // x8
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 v93; // x8
  __int64 v94; // x0
  __int64 v95; // x0
  __int64 v96; // x8
  __int64 v97; // x0
  __int64 v98; // x0
  __int64 v99; // x8
  __int64 v100; // x0
  __int64 v101; // x0
  __int64 v102; // x8
  __int64 v103; // x0
  __int64 v104; // x0
  int v105; // w19
  __int64 v106; // x8
  __int64 v107; // x0
  __int64 v108; // x0
  __int64 v109; // x8
  __int64 v110; // x0
  __int64 v111; // x0
  __int64 v112; // x8
  __int64 v113; // x0
  __int64 v114; // x0
  __int64 v115; // x8
  __int64 v116; // x0
  __int64 v117; // x0
  int v119; // w19
  __int64 v120; // x8
  __int64 v121; // x0
  __int64 v122; // x0
  __int64 v123; // x8
  __int64 v124; // x0
  __int64 v125; // x0
  int v126; // w19
  __int64 v127; // x8
  __int64 v128; // x0
  __int64 v129; // x0
  __int64 v130; // x8
  __int64 v131; // x0
  __int64 v132; // x0
  __int64 v133; // x8
  __int64 v134; // x0
  __int64 v135; // x0
  __int64 v136; // x8
  __int64 v137; // x0
  __int64 v138; // x0
  unsigned int v139; // [xsp+8h] [xbp-58h]
  unsigned int v140; // [xsp+Ch] [xbp-54h]
  _DWORD *v141; // [xsp+10h] [xbp-50h]
  int v142; // [xsp+34h] [xbp-2Ch] BYREF
  __int64 v143; // [xsp+38h] [xbp-28h] BYREF
  __int64 v144; // [xsp+40h] [xbp-20h] BYREF
  __int64 v145; // [xsp+48h] [xbp-18h] BYREF
  __int64 v146; // [xsp+50h] [xbp-10h]
  __int64 v147; // [xsp+58h] [xbp-8h]

  v147 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v145 = 0;
  v146 = 0;
  v143 = 0;
  v144 = 0;
  v142 = 0;
  if ( (int)ipa_get_wdi_version() <= 1 )
  {
    printk(&unk_3F0090, "ipa3_conn_wdi3_pipes");
    v80 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v81 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v81 )
      {
        ipc_log_string(v81, "ipa %s:%d wdi3 over uc offload not supported", "ipa3_conn_wdi3_pipes", 664);
        v80 = ipa3_ctx;
      }
      v82 = *(_QWORD *)(v80 + 34160);
      if ( v82 )
        ipc_log_string(v82, "ipa %s:%d wdi3 over uc offload not supported", "ipa3_conn_wdi3_pipes", 664);
    }
    __break(0x800u);
    v57 = -14;
  }
  else
  {
    if ( a1 && a2 )
    {
      v6 = *(_DWORD *)(a1 + 1400);
      v7 = *(_DWORD *)(a1 + 984);
      ep_mapping = ipa_get_ep_mapping(v6);
      v9 = ipa_get_ep_mapping(v7);
      if ( ep_mapping == -1 || (v10 = v9, v9 == -1) )
      {
        printk(&unk_3F4B4C, "ipa3_conn_wdi3_pipes");
        v86 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_155;
        v87 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v87 )
        {
          ipc_log_string(v87, "ipa %s:%d fail to alloc EP.\n", "ipa3_conn_wdi3_pipes", 686);
          v86 = ipa3_ctx;
        }
        v88 = *(_QWORD *)(v86 + 34160);
        if ( !v88 )
          goto LABEL_155;
        ipc_log_string(v88, "ipa %s:%d fail to alloc EP.\n", "ipa3_conn_wdi3_pipes", 686);
      }
      else if ( ep_mapping >= (unsigned int)ipa3_get_max_num_pipes() || v10 >= (unsigned int)ipa3_get_max_num_pipes() )
      {
        printk(&unk_3C504D, "ipa3_conn_wdi3_pipes");
        v74 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_155;
        v75 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v75 )
        {
          ipc_log_string(v75, "ipa %s:%d ep out of range.\n", "ipa3_conn_wdi3_pipes", 691);
          v74 = ipa3_ctx;
        }
        v76 = *(_QWORD *)(v74 + 34160);
        if ( !v76 )
          goto LABEL_155;
        ipc_log_string(v76, "ipa %s:%d ep out of range.\n", "ipa3_conn_wdi3_pipes", 691);
      }
      else
      {
        if ( ep_mapping >= 0x25 || v10 > 0x24 )
          goto LABEL_235;
        v11 = ipa3_ctx + 168;
        v12 = ipa3_ctx + 168 + 480LL * ep_mapping;
        if ( !*(_DWORD *)v12 )
        {
          v13 = (_DWORD *)(v11 + 480LL * v10);
          if ( !*v13 )
          {
            memset((void *)(v11 + 480LL * ep_mapping), 0, 0x1D8u);
            memset(v13, 0, 0x1D8u);
            if ( *(_BYTE *)(a1 + 1624) != 1 || *(_BYTE *)(ipa3_ctx + 50152) != 1 )
            {
              v141 = nullptr;
              v139 = 0;
              v140 = -1;
              goto LABEL_20;
            }
            v139 = *(_DWORD *)(a1 + 1824);
            v14 = ipa_get_ep_mapping(v139);
            if ( v14 != -1 && v14 < 31 )
            {
              if ( (unsigned int)v14 <= 0x24 )
              {
                v15 = ipa3_ctx + 480LL * (unsigned int)v14;
                v17 = *(_DWORD *)(v15 + 168);
                v16 = (_DWORD *)(v15 + 168);
                if ( !v17 )
                {
                  v140 = v14;
                  v141 = v16;
                  memset(v16, 0, 0x1D8u);
LABEL_20:
                  ipa3_inc_client_enable_clks();
                  v18 = ipa3_ctx;
                  if ( a3 )
                  {
                    *(_QWORD *)(ipa3_ctx + 43176) = a3;
                  }
                  else if ( ipa3_ctx )
                  {
                    v72 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v72 )
                    {
                      ipc_log_string(v72, "ipa %s:%d wdi_notify is null\n", "ipa3_conn_wdi3_pipes", 733);
                      v18 = ipa3_ctx;
                    }
                    v73 = *(_QWORD *)(v18 + 34160);
                    if ( v73 )
                      ipc_log_string(v73, "ipa %s:%d wdi_notify is null\n", "ipa3_conn_wdi3_pipes", 733);
                  }
                  *(_DWORD *)v12 = 1;
                  *(_DWORD *)(v12 + 4) = v6;
                  v19 = ipa3_disable_data_path(ep_mapping);
                  if ( !v19 )
                  {
                    *(_QWORD *)(v12 + 376) = *(_QWORD *)a1;
                    *(_QWORD *)(v12 + 368) = *(_QWORD *)(a1 + 8);
                    memcpy((void *)(v12 + 144), (const void *)(a1 + 1208), 0xC0u);
                    if ( *(_BYTE *)(ipa3_ctx + 32267) == 1 )
                    {
                      *(_BYTE *)(v12 + 292) = 1;
                      *(_BYTE *)(v12 + 352) = 1;
                      v20 = ipa_get_ep_mapping(53);
                      *(_BYTE *)(v12 + 355) = 1;
                      *(_BYTE *)(v12 + 353) = v20;
                    }
                    if ( (unsigned int)ipa3_cfg_ep(ep_mapping, v12 + 144) )
                    {
                      printk(&unk_3BB0CE, "ipa3_conn_wdi3_pipes");
                      v93 = ipa3_ctx;
                      if ( ipa3_ctx )
                      {
                        v94 = *(_QWORD *)(ipa3_ctx + 34152);
                        if ( v94 )
                        {
                          ipc_log_string(v94, "ipa %s:%d fail to setup rx pipe cfg\n", "ipa3_conn_wdi3_pipes", 765);
                          v93 = ipa3_ctx;
                        }
                        v95 = *(_QWORD *)(v93 + 34160);
                        if ( !v95 )
                          goto LABEL_234;
                        ipc_log_string(v95, "ipa %s:%d fail to setup rx pipe cfg\n", "ipa3_conn_wdi3_pipes", 765);
                        goto LABEL_199;
                      }
                    }
                    else
                    {
                      if ( (unsigned int)ipa3_cfg_ep_status(ep_mapping, (unsigned __int8 *)(v12 + 352)) )
                      {
                        printk(&unk_3A6426, "ipa3_conn_wdi3_pipes");
                        v96 = ipa3_ctx;
                        if ( ipa3_ctx )
                        {
                          v97 = *(_QWORD *)(ipa3_ctx + 34152);
                          if ( v97 )
                          {
                            ipc_log_string(
                              v97,
                              "ipa %s:%d fail to configure status of EP.\n",
                              "ipa3_conn_wdi3_pipes",
                              771);
                            v96 = ipa3_ctx;
                          }
                          v98 = *(_QWORD *)(v96 + 34160);
                          if ( v98 )
                            ipc_log_string(
                              v98,
                              "ipa %s:%d fail to configure status of EP.\n",
                              "ipa3_conn_wdi3_pipes",
                              771);
                          goto LABEL_166;
                        }
                        goto LABEL_167;
                      }
                      if ( v6 == 12 )
                        v21 = 3;
                      else
                        v21 = 5;
                      if ( (unsigned int)ipa3_setup_wdi3_gsi_channel(
                                           *(unsigned __int8 *)(a1 + 16),
                                           a1 + 1208,
                                           a1 + 1208,
                                           v21,
                                           v12) )
                      {
                        printk(&unk_3E1BEE, "ipa3_conn_wdi3_pipes");
                        v99 = ipa3_ctx;
                        if ( ipa3_ctx )
                        {
                          v100 = *(_QWORD *)(ipa3_ctx + 34152);
                          if ( v100 )
                          {
                            ipc_log_string(
                              v100,
                              "ipa %s:%d fail to setup wdi3 gsi rx channel\n",
                              "ipa3_conn_wdi3_pipes",
                              782);
                            v99 = ipa3_ctx;
                          }
                          v101 = *(_QWORD *)(v99 + 34160);
                          if ( !v101 )
                            goto LABEL_234;
                          ipc_log_string(
                            v101,
                            "ipa %s:%d fail to setup wdi3 gsi rx channel\n",
                            "ipa3_conn_wdi3_pipes",
                            782);
                          goto LABEL_199;
                        }
                      }
                      else if ( (unsigned int)gsi_query_channel_db_addr(*(_QWORD *)(v12 + 8), (char *)&v144 + 4, &v144) )
                      {
                        printk(&unk_3C9AA8, "ipa3_conn_wdi3_pipes");
                        v102 = ipa3_ctx;
                        if ( ipa3_ctx )
                        {
                          v103 = *(_QWORD *)(ipa3_ctx + 34152);
                          if ( v103 )
                          {
                            ipc_log_string(
                              v103,
                              "ipa %s:%d failed to query gsi rx db addr\n",
                              "ipa3_conn_wdi3_pipes",
                              788);
                            v102 = ipa3_ctx;
                          }
                          v104 = *(_QWORD *)(v102 + 34160);
                          if ( !v104 )
                            goto LABEL_234;
                          ipc_log_string(
                            v104,
                            "ipa %s:%d failed to query gsi rx db addr\n",
                            "ipa3_conn_wdi3_pipes",
                            788);
                          goto LABEL_199;
                        }
                      }
                      else
                      {
                        v22 = HIDWORD(v144);
                        v23 = ipa3_ctx;
                        a2[1] = HIDWORD(v144);
                        if ( v23 )
                        {
                          v24 = *(_QWORD *)(v23 + 34152);
                          if ( v24 )
                          {
                            ipc_log_string(v24, "ipa %s:%d out->rx_uc_db_pa %llu\n", "ipa3_conn_wdi3_pipes", 794, v22);
                            v23 = ipa3_ctx;
                          }
                          v25 = *(_QWORD *)(v23 + 34160);
                          if ( v25 )
                            ipc_log_string(v25, "ipa %s:%d out->rx_uc_db_pa %llu\n", "ipa3_conn_wdi3_pipes", 794, a2[1]);
                        }
                        ipa3_install_dflt_flt_rules(ep_mapping);
                        v26 = ipa3_ctx;
                        if ( ipa3_ctx )
                        {
                          v27 = *(_QWORD *)(ipa3_ctx + 34152);
                          if ( v27 )
                          {
                            ipc_log_string(
                              v27,
                              "ipa %s:%d client %d (ep: %d) connected\n",
                              "ipa3_conn_wdi3_pipes",
                              798,
                              v6,
                              ep_mapping);
                            v26 = ipa3_ctx;
                          }
                          v28 = *(_QWORD *)(v26 + 34160);
                          if ( v28 )
                            ipc_log_string(
                              v28,
                              "ipa %s:%d client %d (ep: %d) connected\n",
                              "ipa3_conn_wdi3_pipes",
                              798,
                              v6,
                              ep_mapping);
                        }
                        *v13 = 1;
                        v13[1] = v7;
                        v29 = ipa3_disable_data_path(v10);
                        if ( v29 )
                        {
                          v105 = v29;
                          printk(&unk_3CA8D4, "ipa3_conn_wdi3_pipes");
                          v106 = ipa3_ctx;
                          if ( ipa3_ctx )
                          {
                            v107 = *(_QWORD *)(ipa3_ctx + 34152);
                            if ( v107 )
                            {
                              ipc_log_string(
                                v107,
                                "ipa %s:%d disable data path failed res=%d ep=%d.\n",
                                "ipa3_conn_wdi3_pipes",
                                806,
                                v105,
                                v10);
                              v106 = ipa3_ctx;
                            }
                            v108 = *(_QWORD *)(v106 + 34160);
                            if ( v108 )
                              ipc_log_string(
                                v108,
                                "ipa %s:%d disable data path failed res=%d ep=%d.\n",
                                "ipa3_conn_wdi3_pipes",
                                806,
                                v105,
                                v10);
                            v57 = -14;
                            goto LABEL_201;
                          }
                        }
                        else
                        {
                          memcpy(v13 + 36, (const void *)(a1 + 792), 0xC0u);
                          v13[62] = 2;
                          *((_QWORD *)v13 + 30) = 0x400000001LL;
                          *((_QWORD *)v13 + 32) = 0x100000001LL;
                          if ( (unsigned int)ipa3_cfg_ep(v10, (__int64)(v13 + 36)) )
                          {
                            printk(&unk_3D3BDA, "ipa3_conn_wdi3_pipes");
                            v109 = ipa3_ctx;
                            if ( ipa3_ctx )
                            {
                              v110 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v110 )
                              {
                                ipc_log_string(
                                  v110,
                                  "ipa %s:%d fail to setup tx pipe cfg\n",
                                  "ipa3_conn_wdi3_pipes",
                                  824);
                                v109 = ipa3_ctx;
                              }
                              v111 = *(_QWORD *)(v109 + 34160);
                              if ( !v111 )
                                goto LABEL_234;
                              ipc_log_string(v111, "ipa %s:%d fail to setup tx pipe cfg\n", "ipa3_conn_wdi3_pipes", 824);
                              goto LABEL_199;
                            }
                          }
                          else
                          {
                            if ( v7 == 13 )
                              v30 = 1;
                            else
                              v30 = 4;
                            if ( (unsigned int)ipa3_setup_wdi3_gsi_channel(
                                                 *(unsigned __int8 *)(a1 + 16),
                                                 a1 + 792,
                                                 a1 + 792,
                                                 v30,
                                                 v13) )
                            {
                              printk(&unk_3F00BF, "ipa3_conn_wdi3_pipes");
                              v112 = ipa3_ctx;
                              if ( ipa3_ctx )
                              {
                                v113 = *(_QWORD *)(ipa3_ctx + 34152);
                                if ( v113 )
                                {
                                  ipc_log_string(
                                    v113,
                                    "ipa %s:%d fail to setup wdi3 gsi tx channel\n",
                                    "ipa3_conn_wdi3_pipes",
                                    836);
                                  v112 = ipa3_ctx;
                                }
                                v114 = *(_QWORD *)(v112 + 34160);
                                if ( !v114 )
                                  goto LABEL_234;
                                ipc_log_string(
                                  v114,
                                  "ipa %s:%d fail to setup wdi3 gsi tx channel\n",
                                  "ipa3_conn_wdi3_pipes",
                                  836);
                                goto LABEL_199;
                              }
                            }
                            else
                            {
                              if ( !(unsigned int)gsi_query_channel_db_addr(
                                                    *((_QWORD *)v13 + 1),
                                                    (char *)&v144 + 4,
                                                    &v144) )
                              {
                                v31 = HIDWORD(v144);
                                *a2 = HIDWORD(v144);
                                v32 = ipa3_ctx;
                                if ( ipa3_ctx )
                                {
                                  v33 = *(_QWORD *)(ipa3_ctx + 34152);
                                  if ( v33 )
                                  {
                                    ipc_log_string(
                                      v33,
                                      "ipa %s:%d out->tx_uc_db_pa %llu\n",
                                      "ipa3_conn_wdi3_pipes",
                                      848,
                                      v31);
                                    v32 = ipa3_ctx;
                                  }
                                  v34 = *(_QWORD *)(v32 + 34160);
                                  if ( v34 )
                                  {
                                    ipc_log_string(
                                      v34,
                                      "ipa %s:%d out->tx_uc_db_pa %llu\n",
                                      "ipa3_conn_wdi3_pipes",
                                      848,
                                      *a2);
                                    v32 = ipa3_ctx;
                                  }
                                  if ( v32 )
                                  {
                                    v35 = *(_QWORD *)(v32 + 34152);
                                    if ( v35 )
                                    {
                                      ipc_log_string(
                                        v35,
                                        "ipa %s:%d client %d (ep: %d) connected\n",
                                        "ipa3_conn_wdi3_pipes",
                                        850,
                                        v7,
                                        v10);
                                      v32 = ipa3_ctx;
                                    }
                                    v36 = *(_QWORD *)(v32 + 34160);
                                    if ( v36 )
                                      ipc_log_string(
                                        v36,
                                        "ipa %s:%d client %d (ep: %d) connected\n",
                                        "ipa3_conn_wdi3_pipes",
                                        850,
                                        v7,
                                        v10);
                                  }
                                }
                                gsi_query_evt_ring_db_addr(*(_QWORD *)(v12 + 16), (char *)&v143 + 4, &v143);
                                v37 = ipa3_ctx;
                                if ( ipa3_ctx )
                                {
                                  v38 = *(_QWORD *)(ipa3_ctx + 34152);
                                  if ( v38 )
                                  {
                                    ipc_log_string(
                                      v38,
                                      "ipa %s:%d evt_ring_hdl %lu, db_addr_low %u db_addr_high %u\n",
                                      "ipa3_conn_wdi3_pipes",
                                      857,
                                      *(_QWORD *)(v12 + 16),
                                      HIDWORD(v143),
                                      v143);
                                    v37 = ipa3_ctx;
                                  }
                                  v39 = *(_QWORD *)(v37 + 34160);
                                  if ( v39 )
                                    ipc_log_string(
                                      v39,
                                      "ipa %s:%d evt_ring_hdl %lu, db_addr_low %u db_addr_high %u\n",
                                      "ipa3_conn_wdi3_pipes",
                                      857,
                                      *(_QWORD *)(v12 + 16),
                                      HIDWORD(v143),
                                      v143);
                                }
                                if ( arm64_use_ng_mappings )
                                  v40 = 0x68000000000F13LL;
                                else
                                  v40 = 0x68000000000713LL;
                                v41 = ioremap_prot(HIDWORD(v143), 4, v40);
                                v42 = 1448;
                                if ( *(_BYTE *)(a1 + 16) )
                                  v42 = 1464;
                                v43 = *(_DWORD *)(v12 + 32) + *(_DWORD *)(a1 + v42);
                                writel_0((unsigned int)(v43 + 8), v41);
                                v44 = ipa3_ctx;
                                if ( ipa3_ctx )
                                {
                                  v45 = *(_QWORD *)(ipa3_ctx + 34152);
                                  if ( v45 )
                                  {
                                    ipc_log_string(
                                      v45,
                                      "ipa %s:%d RX base_addr 0x%llx evt wp val: 0x%x\n",
                                      "ipa3_conn_wdi3_pipes",
                                      875,
                                      *(_QWORD *)(v12 + 32),
                                      v43 + 8);
                                    v44 = ipa3_ctx;
                                  }
                                  v46 = *(_QWORD *)(v44 + 34160);
                                  if ( v46 )
                                    ipc_log_string(
                                      v46,
                                      "ipa %s:%d RX base_addr 0x%llx evt wp val: 0x%x\n",
                                      "ipa3_conn_wdi3_pipes",
                                      875,
                                      *(_QWORD *)(v12 + 32),
                                      v43 + 8);
                                }
                                gsi_query_evt_ring_db_addr(*((_QWORD *)v13 + 2), (char *)&v143 + 4, &v143);
                                if ( arm64_use_ng_mappings )
                                  v47 = 0x68000000000F13LL;
                                else
                                  v47 = 0x68000000000713LL;
                                v48 = ioremap_prot(HIDWORD(v143), 4, v47);
                                v49 = 1032;
                                v50 = v13[8];
                                if ( *(_BYTE *)(a1 + 16) )
                                  v49 = 1048;
                                v51 = *(_DWORD *)(a1 + v49);
                                if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x12u )
                                  v52 = 16;
                                else
                                  v52 = 32;
                                v53 = v51 + v52;
                                writel_0((unsigned int)(v51 + v52 + v50), v48);
                                v54 = ipa3_ctx;
                                if ( ipa3_ctx )
                                {
                                  v55 = *(_QWORD *)(ipa3_ctx + 34152);
                                  if ( v55 )
                                  {
                                    ipc_log_string(
                                      v55,
                                      "ipa %s:%d db_addr %u  TX base_addr 0x%llx evt wp val: 0x%x\n",
                                      "ipa3_conn_wdi3_pipes",
                                      898,
                                      HIDWORD(v143),
                                      *((_QWORD *)v13 + 4),
                                      v53 + v50);
                                    v54 = ipa3_ctx;
                                  }
                                  v56 = *(_QWORD *)(v54 + 34160);
                                  if ( v56 )
                                  {
                                    ipc_log_string(
                                      v56,
                                      "ipa %s:%d db_addr %u  TX base_addr 0x%llx evt wp val: 0x%x\n",
                                      "ipa3_conn_wdi3_pipes",
                                      898,
                                      HIDWORD(v143),
                                      *((_QWORD *)v13 + 4),
                                      v53 + v50);
                                    v54 = ipa3_ctx;
                                  }
                                }
                                if ( *(_BYTE *)(v54 + 32267) == 1
                                  && (((__int64 (__fastcall *)(_QWORD))ipa_wdi_opt_dpath_ctrl_enabled)(0) & 1) != 0 )
                                {
                                  LODWORD(v145) = 1;
                                  HIDWORD(v145) = ep_mapping;
                                  v146 = v10;
                                  HIDWORD(v146) = ipa_get_ep_mapping(33);
                                  ipa3_handle_ipa_wlan_opt_dp_set_wlan_ctrl_ready_req((__int64)&v145, &v142);
                                  ipa3_install_dl_opt_wdi_dpath_flt_rules(ep_mapping, v142);
                                }
                                if ( *(_BYTE *)(a1 + 1624) == 1 )
                                {
                                  v57 = 0;
                                  if ( v140 == -1 || (*(_BYTE *)(ipa3_ctx + 50152) & 1) == 0 )
                                    goto LABEL_201;
                                  *v141 = 1;
                                  v141[1] = v139;
                                  v58 = ipa3_disable_data_path(v140);
                                  if ( v58 )
                                  {
                                    v126 = v58;
                                    printk(&unk_3CA8D4, "ipa3_conn_wdi3_pipes");
                                    v127 = ipa3_ctx;
                                    if ( ipa3_ctx )
                                    {
                                      v128 = *(_QWORD *)(ipa3_ctx + 34152);
                                      if ( v128 )
                                      {
                                        ipc_log_string(
                                          v128,
                                          "ipa %s:%d disable data path failed res=%d ep=%d.\n",
                                          "ipa3_conn_wdi3_pipes",
                                          925,
                                          v126,
                                          v140);
                                        v127 = ipa3_ctx;
                                      }
                                      v129 = *(_QWORD *)(v127 + 34160);
                                      if ( v129 )
                                      {
                                        ipc_log_string(
                                          v129,
                                          "ipa %s:%d disable data path failed res=%d ep=%d.\n",
                                          "ipa3_conn_wdi3_pipes",
                                          925,
                                          v126,
                                          v140);
                                        v57 = -14;
                                        goto LABEL_201;
                                      }
                                    }
                                    goto LABEL_234;
                                  }
                                  memcpy(v141 + 36, (const void *)(a1 + 1632), 0xC0u);
                                  v141[62] = 2;
                                  *((_QWORD *)v141 + 30) = 0x400000001LL;
                                  *((_QWORD *)v141 + 32) = 0x100000001LL;
                                  if ( (unsigned int)ipa3_cfg_ep(v140, (__int64)(v141 + 36)) )
                                  {
                                    printk(&unk_3D3BDA, "ipa3_conn_wdi3_pipes");
                                    v130 = ipa3_ctx;
                                    if ( !ipa3_ctx )
                                      goto LABEL_234;
                                    v131 = *(_QWORD *)(ipa3_ctx + 34152);
                                    if ( v131 )
                                    {
                                      ipc_log_string(
                                        v131,
                                        "ipa %s:%d fail to setup tx pipe cfg\n",
                                        "ipa3_conn_wdi3_pipes",
                                        943);
                                      v130 = ipa3_ctx;
                                    }
                                    v132 = *(_QWORD *)(v130 + 34160);
                                    if ( !v132 )
                                      goto LABEL_234;
                                    ipc_log_string(
                                      v132,
                                      "ipa %s:%d fail to setup tx pipe cfg\n",
                                      "ipa3_conn_wdi3_pipes",
                                      943);
                                  }
                                  else
                                  {
                                    if ( !(unsigned int)ipa3_setup_wdi3_gsi_channel(
                                                          *(unsigned __int8 *)(a1 + 16),
                                                          a1 + 1632,
                                                          a1 + 1632,
                                                          2,
                                                          v141) )
                                    {
                                      if ( !(unsigned int)gsi_query_channel_db_addr(
                                                            *((_QWORD *)v141 + 1),
                                                            (char *)&v144 + 4,
                                                            &v144) )
                                      {
                                        v59 = HIDWORD(v144);
                                        v60 = ipa3_ctx;
                                        a2[2] = HIDWORD(v144);
                                        if ( v60 )
                                        {
                                          v61 = *(_QWORD *)(v60 + 34152);
                                          if ( v61 )
                                          {
                                            ipc_log_string(
                                              v61,
                                              "ipa %s:%d out->tx1_uc_db_pa %llu\n",
                                              "ipa3_conn_wdi3_pipes",
                                              966,
                                              v59);
                                            v60 = ipa3_ctx;
                                          }
                                          v62 = *(_QWORD *)(v60 + 34160);
                                          if ( v62 )
                                          {
                                            ipc_log_string(
                                              v62,
                                              "ipa %s:%d out->tx1_uc_db_pa %llu\n",
                                              "ipa3_conn_wdi3_pipes",
                                              966,
                                              a2[2]);
                                            v60 = ipa3_ctx;
                                          }
                                          if ( v60 )
                                          {
                                            v63 = *(_QWORD *)(v60 + 34152);
                                            if ( v63 )
                                            {
                                              ipc_log_string(
                                                v63,
                                                "ipa %s:%d client %d (ep: %d) connected\n",
                                                "ipa3_conn_wdi3_pipes",
                                                968,
                                                v139,
                                                v140);
                                              v60 = ipa3_ctx;
                                            }
                                            v64 = *(_QWORD *)(v60 + 34160);
                                            if ( v64 )
                                              ipc_log_string(
                                                v64,
                                                "ipa %s:%d client %d (ep: %d) connected\n",
                                                "ipa3_conn_wdi3_pipes",
                                                968,
                                                v139,
                                                v140);
                                          }
                                        }
                                        gsi_query_evt_ring_db_addr(*((_QWORD *)v141 + 2), (char *)&v143 + 4, &v143);
                                        if ( arm64_use_ng_mappings )
                                          v65 = 0x68000000000F13LL;
                                        else
                                          v65 = 0x68000000000713LL;
                                        v66 = ioremap_prot(HIDWORD(v143), 4, v65);
                                        v67 = 1872;
                                        if ( *(_BYTE *)(a1 + 16) )
                                          v67 = 1888;
                                        v68 = v141[8] + *(_DWORD *)(a1 + v67);
                                        writel_0((unsigned int)(v68 + 16), v66);
                                        v69 = ipa3_ctx;
                                        if ( ipa3_ctx )
                                        {
                                          v70 = *(_QWORD *)(ipa3_ctx + 34152);
                                          if ( v70 )
                                          {
                                            ipc_log_string(
                                              v70,
                                              "ipa %s:%d db_addr %u  TX1 base_addr 0x%llx evt wp val: 0x%x\n",
                                              "ipa3_conn_wdi3_pipes",
                                              991,
                                              HIDWORD(v143),
                                              *((_QWORD *)v141 + 4),
                                              v68 + 16);
                                            v69 = ipa3_ctx;
                                          }
                                          v71 = *(_QWORD *)(v69 + 34160);
                                          if ( v71 )
                                            ipc_log_string(
                                              v71,
                                              "ipa %s:%d db_addr %u  TX1 base_addr 0x%llx evt wp val: 0x%x\n",
                                              "ipa3_conn_wdi3_pipes",
                                              991,
                                              HIDWORD(v143),
                                              *((_QWORD *)v141 + 4),
                                              v68 + 16);
                                        }
LABEL_166:
                                        v57 = 0;
LABEL_201:
                                        ipa3_dec_client_disable_clks();
                                        goto LABEL_202;
                                      }
                                      printk(&unk_3D9286, "ipa3_conn_wdi3_pipes");
                                      v136 = ipa3_ctx;
                                      if ( ipa3_ctx )
                                      {
                                        v137 = *(_QWORD *)(ipa3_ctx + 34152);
                                        if ( v137 )
                                        {
                                          ipc_log_string(
                                            v137,
                                            "ipa %s:%d failed to query gsi tx1 db addr\n",
                                            "ipa3_conn_wdi3_pipes",
                                            959);
                                          v136 = ipa3_ctx;
                                        }
                                        v138 = *(_QWORD *)(v136 + 34160);
                                        if ( v138 )
                                        {
                                          ipc_log_string(
                                            v138,
                                            "ipa %s:%d failed to query gsi tx1 db addr\n",
                                            "ipa3_conn_wdi3_pipes",
                                            959);
                                          goto LABEL_199;
                                        }
                                      }
LABEL_234:
                                      v57 = -14;
                                      goto LABEL_201;
                                    }
                                    printk(&unk_3F5FD9, "ipa3_conn_wdi3_pipes");
                                    v133 = ipa3_ctx;
                                    if ( !ipa3_ctx )
                                      goto LABEL_234;
                                    v134 = *(_QWORD *)(ipa3_ctx + 34152);
                                    if ( v134 )
                                    {
                                      ipc_log_string(
                                        v134,
                                        "ipa %s:%d fail to setup wdi3 gsi tx1 channel\n",
                                        "ipa3_conn_wdi3_pipes",
                                        952);
                                      v133 = ipa3_ctx;
                                    }
                                    v135 = *(_QWORD *)(v133 + 34160);
                                    if ( !v135 )
                                      goto LABEL_234;
                                    ipc_log_string(
                                      v135,
                                      "ipa %s:%d fail to setup wdi3 gsi tx1 channel\n",
                                      "ipa3_conn_wdi3_pipes",
                                      952);
                                  }
LABEL_199:
                                  v57 = -14;
                                  goto LABEL_201;
                                }
LABEL_167:
                                v57 = 0;
                                goto LABEL_201;
                              }
                              printk(&unk_3F00EE, "ipa3_conn_wdi3_pipes");
                              v115 = ipa3_ctx;
                              if ( ipa3_ctx )
                              {
                                v116 = *(_QWORD *)(ipa3_ctx + 34152);
                                if ( v116 )
                                {
                                  ipc_log_string(
                                    v116,
                                    "ipa %s:%d failed to query gsi tx db addr\n",
                                    "ipa3_conn_wdi3_pipes",
                                    842);
                                  v115 = ipa3_ctx;
                                }
                                v117 = *(_QWORD *)(v115 + 34160);
                                if ( !v117 )
                                  goto LABEL_234;
                                ipc_log_string(
                                  v117,
                                  "ipa %s:%d failed to query gsi tx db addr\n",
                                  "ipa3_conn_wdi3_pipes",
                                  842);
                                goto LABEL_199;
                              }
                            }
                          }
                        }
                      }
                    }
                    v57 = -14;
                    goto LABEL_201;
                  }
                  v89 = v19;
                  printk(&unk_3EF093, "ipa3_conn_wdi3_pipes");
                  v90 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v91 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v91 )
                    {
                      ipc_log_string(
                        v91,
                        "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
                        "ipa3_conn_wdi3_pipes",
                        742,
                        v89,
                        ep_mapping);
                      v90 = ipa3_ctx;
                    }
                    v92 = *(_QWORD *)(v90 + 34160);
                    if ( v92 )
                      ipc_log_string(
                        v92,
                        "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
                        "ipa3_conn_wdi3_pipes",
                        742,
                        v89,
                        ep_mapping);
                  }
                  ipa3_dec_client_disable_clks();
                  goto LABEL_155;
                }
                printk(&unk_3F4B6B, "ipa3_conn_wdi3_pipes");
                v123 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v124 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v124 )
                  {
                    ipc_log_string(v124, "ipa %s:%d EP already allocated.\n", "ipa3_conn_wdi3_pipes", 720);
                    v123 = ipa3_ctx;
                  }
                  v125 = *(_QWORD *)(v123 + 34160);
                  if ( v125 )
                  {
                    ipc_log_string(v125, "ipa %s:%d EP already allocated.\n", "ipa3_conn_wdi3_pipes", 720);
                    goto LABEL_148;
                  }
                }
LABEL_155:
                v57 = -14;
                goto LABEL_202;
              }
LABEL_235:
              __break(0x5512u);
            }
            v119 = v14;
            printk(&unk_3E749C, "ipa3_conn_wdi3_pipes");
            v120 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v121 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v121 )
              {
                ipc_log_string(
                  v121,
                  "ipa %s:%d fail to alloc ep2 tx clnt %d not supprtd %d",
                  "ipa3_conn_wdi3_pipes",
                  715,
                  v139,
                  v119);
                v120 = ipa3_ctx;
              }
              v122 = *(_QWORD *)(v120 + 34160);
              if ( v122 )
              {
                ipc_log_string(
                  v122,
                  "ipa %s:%d fail to alloc ep2 tx clnt %d not supprtd %d",
                  "ipa3_conn_wdi3_pipes",
                  715,
                  v139,
                  v119);
                v57 = -22;
                goto LABEL_202;
              }
            }
LABEL_208:
            v57 = -22;
            goto LABEL_202;
          }
        }
        printk(&unk_3F4B6B, "ipa3_conn_wdi3_pipes");
        v77 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_155;
        v78 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v78 )
        {
          ipc_log_string(v78, "ipa %s:%d EP already allocated.\n", "ipa3_conn_wdi3_pipes", 699);
          v77 = ipa3_ctx;
        }
        v79 = *(_QWORD *)(v77 + 34160);
        if ( !v79 )
          goto LABEL_155;
        ipc_log_string(v79, "ipa %s:%d EP already allocated.\n", "ipa3_conn_wdi3_pipes", 699);
      }
LABEL_148:
      v57 = -14;
      goto LABEL_202;
    }
    printk(&unk_3DB00B, "ipa3_conn_wdi3_pipes");
    v83 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_208;
    v84 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v84 )
    {
      ipc_log_string(v84, "ipa %s:%d invalid input\n", "ipa3_conn_wdi3_pipes", 670);
      v83 = ipa3_ctx;
    }
    v85 = *(_QWORD *)(v83 + 34160);
    if ( !v85 )
      goto LABEL_208;
    ipc_log_string(v85, "ipa %s:%d invalid input\n", "ipa3_conn_wdi3_pipes", 670);
    v57 = -22;
  }
LABEL_202:
  _ReadStatusReg(SP_EL0);
  return v57;
}
