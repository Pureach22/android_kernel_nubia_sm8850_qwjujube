__int64 __fastcall ipa3_conn_wigig_rx_pipe_i(__int64 a1, _DWORD *a2, _QWORD *a3)
{
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int ep_mapping; // w20
  __int64 v10; // x22
  _QWORD *v11; // x22
  int v12; // t1
  __int64 v13; // x0
  __int64 v14; // x23
  int v15; // w0
  int v16; // w28
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  const void *v22; // x24
  __int64 v23; // x26
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x24
  __int64 v29; // x25
  __int64 *v30; // x8
  __int64 v31; // x26
  unsigned int v32; // w24
  unsigned int v33; // w0
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  const char *v38; // x1
  __int64 v39; // x3
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x4
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x0
  __int64 v52; // x0
  int v53; // w21
  __int64 v54; // x8
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x8
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x8
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x8
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x8
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x8
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x8
  __int64 v73; // x0
  __int64 v74; // x0
  _DWORD *v75; // [xsp+0h] [xbp-F0h]
  __int64 v76; // [xsp+20h] [xbp-D0h] BYREF
  __int64 v77; // [xsp+28h] [xbp-C8h]
  __int64 v78; // [xsp+30h] [xbp-C0h]
  __int64 v79; // [xsp+38h] [xbp-B8h]
  __int64 v80; // [xsp+40h] [xbp-B0h]
  __int64 v81; // [xsp+48h] [xbp-A8h]
  __int64 v82; // [xsp+50h] [xbp-A0h]
  __int64 v83; // [xsp+58h] [xbp-98h]
  __int64 v84; // [xsp+60h] [xbp-90h]
  __int64 v85; // [xsp+68h] [xbp-88h]
  __int64 v86; // [xsp+70h] [xbp-80h]
  __int64 v87; // [xsp+78h] [xbp-78h]
  __int64 v88; // [xsp+80h] [xbp-70h]
  __int64 v89; // [xsp+88h] [xbp-68h]
  __int64 v90; // [xsp+90h] [xbp-60h]
  __int64 v91; // [xsp+98h] [xbp-58h]
  __int64 v92; // [xsp+A0h] [xbp-50h]
  __int64 v93; // [xsp+A8h] [xbp-48h]
  __int64 v94; // [xsp+B0h] [xbp-40h]
  __int64 v95; // [xsp+B8h] [xbp-38h]
  __int64 v96; // [xsp+C0h] [xbp-30h]
  __int64 v97; // [xsp+C8h] [xbp-28h]
  __int64 v98; // [xsp+D0h] [xbp-20h]
  __int64 v99; // [xsp+D8h] [xbp-18h]
  __int64 v100; // [xsp+E0h] [xbp-10h]

  v100 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = ipa3_ctx;
  v98 = 0;
  v99 = 0;
  v96 = 0;
  v97 = 0;
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v86 = 0;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  v76 = 0;
  v77 = 0;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d \n", "ipa3_conn_wigig_rx_pipe_i", 969);
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d \n", "ipa3_conn_wigig_rx_pipe_i", 969);
  }
  *a3 = wigig_dent;
  ep_mapping = ipa_get_ep_mapping(86);
  if ( ep_mapping == -1 || ep_mapping >= (unsigned int)ipa3_get_max_num_pipes() )
  {
    printk(&unk_3D69EE, "ipa3_conn_wigig_rx_pipe_i");
    v35 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_81;
    v36 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v36 )
    {
      ipc_log_string(
        v36,
        "ipa %s:%d fail to get ep (IPA_CLIENT_WIGIG_PROD) %d.\n",
        "ipa3_conn_wigig_rx_pipe_i",
        977,
        ep_mapping);
      v35 = ipa3_ctx;
    }
    v37 = *(_QWORD *)(v35 + 34160);
    if ( !v37 )
      goto LABEL_81;
    v38 = "ipa %s:%d fail to get ep (IPA_CLIENT_WIGIG_PROD) %d.\n";
    v39 = 977;
    goto LABEL_74;
  }
  if ( ep_mapping < 0x25 )
  {
    v10 = ipa3_ctx + 480LL * ep_mapping;
    v12 = *(_DWORD *)(v10 + 168);
    v11 = (_QWORD *)(v10 + 168);
    if ( !v12 )
    {
      if ( !*((_DWORD *)v11 + 113) )
      {
        v13 = ((__int64 (__fastcall *)(__int64))ipa_get_gsi_ep_info)(86);
        if ( !v13 )
        {
          printk(&unk_3CC819, "ipa3_conn_wigig_rx_pipe_i");
          v50 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_98;
          v51 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v51 )
          {
            ipc_log_string(
              v51,
              "ipa %s:%d Failed getting GSI EP info for client=%d\n",
              "ipa3_conn_wigig_rx_pipe_i",
              996,
              86);
            v50 = ipa3_ctx;
          }
          v52 = *(_QWORD *)(v50 + 34160);
          if ( v52 )
          {
            ipc_log_string(
              v52,
              "ipa %s:%d Failed getting GSI EP info for client=%d\n",
              "ipa3_conn_wigig_rx_pipe_i",
              996,
              86);
            v32 = -1;
          }
          else
          {
LABEL_98:
            v32 = -1;
          }
          goto LABEL_52;
        }
        v14 = v13;
        memset(v11, 0, 0x1D8u);
        ipa3_inc_client_enable_clks();
        *v11 = 0x5600000001LL;
        v15 = ipa3_disable_data_path(ep_mapping);
        if ( v15 )
        {
          v53 = v15;
          printk(&unk_3EF093, "ipa3_conn_wigig_rx_pipe_i");
          v54 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v55 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v55 )
            {
              ipc_log_string(
                v55,
                "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
                "ipa3_conn_wigig_rx_pipe_i",
                1010,
                v53,
                ep_mapping);
              v54 = ipa3_ctx;
            }
            v56 = *(_QWORD *)(v54 + 34160);
            if ( v56 )
              ipc_log_string(
                v56,
                "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
                "ipa3_conn_wigig_rx_pipe_i",
                1010,
                v53,
                ep_mapping);
          }
        }
        else
        {
          v16 = *(unsigned __int8 *)(ipa3_ctx + 43314);
          v11[47] = *(_QWORD *)a1;
          v11[46] = *(_QWORD *)(a1 + 8);
          v17 = ipa3_ctx;
          if ( (v16 & 1) != 0 )
          {
            if ( ipa3_ctx )
            {
              v18 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v18 )
              {
                ipc_log_string(
                  v18,
                  "ipa %s:%d desc_ring_base_pa %pa desc_ring_size %d status_ring_base_pa %pa status_ring_size %d",
                  "ipa3_conn_wigig_rx_pipe_i",
                  1060,
                  (const void *)(a1 + 16),
                  *(unsigned __int16 *)(a1 + 24),
                  (const void *)(a1 + 48),
                  *(unsigned __int16 *)(a1 + 56));
                v17 = ipa3_ctx;
              }
              v19 = *(_QWORD *)(v17 + 34160);
              if ( v19 )
              {
                ipc_log_string(
                  v19,
                  "ipa %s:%d desc_ring_base_pa %pa desc_ring_size %d status_ring_base_pa %pa status_ring_size %d",
                  "ipa3_conn_wigig_rx_pipe_i",
                  1060,
                  (const void *)(a1 + 16),
                  *(unsigned __int16 *)(a1 + 24),
                  (const void *)(a1 + 48),
                  *(unsigned __int16 *)(a1 + 56));
                v17 = ipa3_ctx;
              }
              if ( v17 )
              {
                v20 = *(_QWORD *)(v17 + 34152);
                if ( v20 )
                {
                  ipc_log_string(
                    v20,
                    "ipa %s:%d data_buffer_base_pa %pa data_buffer_size %d",
                    "ipa3_conn_wigig_rx_pipe_i",
                    1063,
                    (const void *)(a1 + 80),
                    *(_DWORD *)(a1 + 88));
                  v17 = ipa3_ctx;
                }
                v21 = *(_QWORD *)(v17 + 34160);
                if ( v21 )
                  ipc_log_string(
                    v21,
                    "ipa %s:%d data_buffer_base_pa %pa data_buffer_size %d",
                    "ipa3_conn_wigig_rx_pipe_i",
                    1063,
                    (const void *)(a1 + 80),
                    *(_DWORD *)(a1 + 88));
              }
            }
            v22 = (const void *)(a1 + 80);
            if ( *(_QWORD *)(a1 + 80) >> 40 )
            {
              printk(&unk_3BC17D, "ipa3_conn_wigig_rx_pipe_i");
              v60 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v61 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v61 )
                {
                  ipc_log_string(
                    v61,
                    "ipa %s:%d data_buffers_base_address_msb is over the 8 bit limit (0x%pa)\n",
                    "ipa3_conn_wigig_rx_pipe_i",
                    1069,
                    v22);
                  v60 = ipa3_ctx;
                }
                v62 = *(_QWORD *)(v60 + 34160);
                if ( v62 )
                  ipc_log_string(
                    v62,
                    "ipa %s:%d data_buffers_base_address_msb is over the 8 bit limit (0x%pa)\n",
                    "ipa3_conn_wigig_rx_pipe_i",
                    1069,
                    v22);
              }
            }
            else
            {
              if ( *(_DWORD *)(a1 + 88) < 0x10000u )
              {
                v75 = a2;
                v23 = a1;
                a1 = 0;
                goto LABEL_40;
              }
              printk(&unk_3E7536, "ipa3_conn_wigig_rx_pipe_i");
              v66 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v67 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v67 )
                {
                  ipc_log_string(
                    v67,
                    "ipa %s:%d data_buffer_size is over the 16 bit limit (0x%X)\n",
                    "ipa3_conn_wigig_rx_pipe_i",
                    1076,
                    *(_DWORD *)(a1 + 88));
                  v66 = ipa3_ctx;
                }
                v68 = *(_QWORD *)(v66 + 34160);
                if ( v68 )
                  ipc_log_string(
                    v68,
                    "ipa %s:%d data_buffer_size is over the 16 bit limit (0x%X)\n",
                    "ipa3_conn_wigig_rx_pipe_i",
                    1076,
                    *(_DWORD *)(a1 + 88));
              }
            }
          }
          else
          {
            if ( ipa3_ctx )
            {
              v24 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v24 )
              {
                ipc_log_string(
                  v24,
                  "ipa %s:%d desc_ring_base_iova 0x%llX desc_ring_size %d status_ring_base_iova 0x%llX status_ring_size %d",
                  "ipa3_conn_wigig_rx_pipe_i",
                  1029,
                  *(_QWORD *)(a1 + 32),
                  *(unsigned __int16 *)(a1 + 40),
                  *(_QWORD *)(a1 + 80),
                  *(unsigned __int16 *)(a1 + 88));
                v17 = ipa3_ctx;
              }
              v25 = *(_QWORD *)(v17 + 34160);
              if ( v25 )
              {
                ipc_log_string(
                  v25,
                  "ipa %s:%d desc_ring_base_iova 0x%llX desc_ring_size %d status_ring_base_iova 0x%llX status_ring_size %d",
                  "ipa3_conn_wigig_rx_pipe_i",
                  1029,
                  *(_QWORD *)(a1 + 32),
                  *(unsigned __int16 *)(a1 + 40),
                  *(_QWORD *)(a1 + 80),
                  *(unsigned __int16 *)(a1 + 88));
                v17 = ipa3_ctx;
              }
              if ( v17 )
              {
                v26 = *(_QWORD *)(v17 + 34152);
                if ( v26 )
                {
                  ipc_log_string(
                    v26,
                    "ipa %s:%d data_buffer_base_iova 0x%llX data_buffer_size %d",
                    "ipa3_conn_wigig_rx_pipe_i",
                    1032,
                    *(_QWORD *)(a1 + 128),
                    *(_DWORD *)(a1 + 136));
                  v17 = ipa3_ctx;
                }
                v27 = *(_QWORD *)(v17 + 34160);
                if ( v27 )
                  ipc_log_string(
                    v27,
                    "ipa %s:%d data_buffer_base_iova 0x%llX data_buffer_size %d",
                    "ipa3_conn_wigig_rx_pipe_i",
                    1032,
                    *(_QWORD *)(a1 + 128),
                    *(_DWORD *)(a1 + 136));
              }
            }
            if ( *(_QWORD *)(a1 + 128) >> 40 )
            {
              printk(&unk_3D92D5, "ipa3_conn_wigig_rx_pipe_i");
              v63 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v64 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v64 )
                {
                  ipc_log_string(
                    v64,
                    "ipa %s:%d data_buffers_base_address_msb is over the 8 bit limit (0x%llX)\n",
                    "ipa3_conn_wigig_rx_pipe_i",
                    1039,
                    *(_QWORD *)(a1 + 128));
                  v63 = ipa3_ctx;
                }
                v65 = *(_QWORD *)(v63 + 34160);
                if ( v65 )
                  ipc_log_string(
                    v65,
                    "ipa %s:%d data_buffers_base_address_msb is over the 8 bit limit (0x%llX)\n",
                    "ipa3_conn_wigig_rx_pipe_i",
                    1039,
                    *(_QWORD *)(a1 + 128));
              }
            }
            else
            {
              if ( *(_DWORD *)(a1 + 136) < 0x10000u )
              {
                v75 = a2;
                v23 = 0;
LABEL_40:
                v98 = 0;
                v99 = 0;
                v96 = 0;
                v97 = 0;
                v94 = 0;
                v95 = 0;
                v92 = 0;
                v93 = 0;
                v90 = 0;
                v91 = 0;
                v88 = 0;
                v89 = 0;
                v86 = 0;
                v87 = 0;
                v84 = 256;
                v85 = 0;
                v82 = 0;
                v83 = 0;
                v80 = 0;
                v81 = 0x100000000LL;
                v78 = 0;
                v79 = 0;
                v77 = 0xE00000000LL;
                v76 = 1;
                if ( (unsigned int)ipa3_cfg_ep(ep_mapping, (__int64)&v76) )
                {
                  printk(&unk_3BB0CE, "ipa3_conn_wigig_rx_pipe_i");
                  v57 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v58 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v58 )
                    {
                      ipc_log_string(v58, "ipa %s:%d fail to setup rx pipe cfg\n", "ipa3_conn_wigig_rx_pipe_i", 1095);
                      v57 = ipa3_ctx;
                    }
                    v59 = *(_QWORD *)(v57 + 34160);
                    if ( v59 )
                      ipc_log_string(v59, "ipa %s:%d fail to setup rx pipe cfg\n", "ipa3_conn_wigig_rx_pipe_i", 1095);
                  }
                }
                else
                {
                  if ( (v16 & 1) != 0 )
                  {
                    v28 = v23 + 16;
                    v29 = v23 + 80;
                    v30 = (__int64 *)(v23 + 64);
LABEL_45:
                    v31 = *v30;
                    v32 = ipa3_wigig_config_gsi(1, v16 ^ 1u, v28, v29, v14, v11);
                    if ( v32 )
                    {
                      if ( !a1 )
                        goto LABEL_51;
                    }
                    else
                    {
                      v33 = ipa3_wigig_config_uc(1, 1, 0, *(unsigned int *)(v14 + 4), v31);
                      if ( !v33 )
                      {
                        ipa3_install_dflt_flt_rules(ep_mapping);
                        *v75 = 86;
                        *((_DWORD *)v11 + 113) |= 1u;
                        ipa3_dec_client_disable_clks();
                        v40 = ipa3_ctx;
                        if ( !ipa3_ctx )
                          goto LABEL_68;
                        v41 = *(_QWORD *)(ipa3_ctx + 34152);
                        if ( v41 )
                        {
                          ipc_log_string(
                            v41,
                            "ipa %s:%d wigig rx pipe connected successfully\n",
                            "ipa3_conn_wigig_rx_pipe_i",
                            1144);
                          v40 = ipa3_ctx;
                        }
                        v42 = *(_QWORD *)(v40 + 34160);
                        if ( v42 )
                        {
                          ipc_log_string(
                            v42,
                            "ipa %s:%d wigig rx pipe connected successfully\n",
                            "ipa3_conn_wigig_rx_pipe_i",
                            1144);
                          v40 = ipa3_ctx;
                        }
                        if ( !v40 )
                          goto LABEL_68;
                        v43 = *(_QWORD *)(v40 + 34152);
                        if ( v43 )
                        {
                          ipc_log_string(v43, "ipa %s:%d exit\n", "ipa3_conn_wigig_rx_pipe_i", 1145);
                          v40 = ipa3_ctx;
                        }
                        v44 = *(_QWORD *)(v40 + 34160);
                        if ( v44 )
                        {
                          ipc_log_string(v44, "ipa %s:%d exit\n", "ipa3_conn_wigig_rx_pipe_i", 1145);
                          v32 = 0;
                        }
                        else
                        {
LABEL_68:
                          v32 = 0;
                        }
                        goto LABEL_52;
                      }
                      v32 = v33;
                      ((void (__fastcall *)(_QWORD))ipa3_release_gsi_channel)(ep_mapping);
                      if ( !a1 )
                        goto LABEL_51;
                    }
                    ipa3_wigig_smmu_map_channel(1, a1 + 16, a1 + 112, 0);
LABEL_51:
                    ipa3_dec_client_disable_clks();
LABEL_52:
                    _ReadStatusReg(SP_EL0);
                    return v32;
                  }
                  v28 = a1 + 16;
                  v29 = a1 + 112;
                  if ( !(unsigned int)ipa3_wigig_smmu_map_channel(1, a1 + 16, a1 + 112, 1) )
                  {
                    v30 = (__int64 *)(a1 + 96);
                    goto LABEL_45;
                  }
                  printk(&unk_3C506B, "ipa3_conn_wigig_rx_pipe_i");
                  v72 = ipa3_ctx;
                  if ( !ipa3_ctx )
                  {
                    v32 = -14;
                    goto LABEL_51;
                  }
                  v73 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v73 )
                  {
                    ipc_log_string(
                      v73,
                      "ipa %s:%d failed to setup rx pipe smmu map\n",
                      "ipa3_conn_wigig_rx_pipe_i",
                      1106);
                    v72 = ipa3_ctx;
                  }
                  v74 = *(_QWORD *)(v72 + 34160);
                  if ( v74 )
                    ipc_log_string(
                      v74,
                      "ipa %s:%d failed to setup rx pipe smmu map\n",
                      "ipa3_conn_wigig_rx_pipe_i",
                      1106);
                }
                v32 = -14;
                goto LABEL_51;
              }
              printk(&unk_3D9321, "ipa3_conn_wigig_rx_pipe_i");
              v69 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v70 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v70 )
                {
                  ipc_log_string(
                    v70,
                    "ipa %s:%d data_buffer_size is over the 16 bit limit (%d)\n",
                    "ipa3_conn_wigig_rx_pipe_i",
                    1046,
                    *(_DWORD *)(a1 + 136));
                  v69 = ipa3_ctx;
                }
                v71 = *(_QWORD *)(v69 + 34160);
                if ( v71 )
                  ipc_log_string(
                    v71,
                    "ipa %s:%d data_buffer_size is over the 16 bit limit (%d)\n",
                    "ipa3_conn_wigig_rx_pipe_i",
                    1046,
                    *(_DWORD *)(a1 + 136));
              }
            }
          }
        }
        ipa3_dec_client_disable_clks();
        v32 = -14;
        goto LABEL_52;
      }
      printk(&unk_3D6A26, "ipa3_conn_wigig_rx_pipe_i");
      v48 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v49 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v49 )
        {
          ipc_log_string(
            v49,
            "ipa %s:%d WIGIG channel bad state 0x%X\n",
            "ipa3_conn_wigig_rx_pipe_i",
            989,
            *((_DWORD *)v11 + 113));
          v48 = ipa3_ctx;
        }
        v37 = *(_QWORD *)(v48 + 34160);
        if ( v37 )
        {
          v47 = *((unsigned int *)v11 + 113);
          v38 = "ipa %s:%d WIGIG channel bad state 0x%X\n";
          v39 = 989;
          goto LABEL_80;
        }
      }
LABEL_81:
      v32 = -14;
      goto LABEL_52;
    }
    printk(&unk_3B202E, "ipa3_conn_wigig_rx_pipe_i");
    v45 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_81;
    v46 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v46 )
    {
      ipc_log_string(v46, "ipa %s:%d EP %d already allocated.\n", "ipa3_conn_wigig_rx_pipe_i", 983, ep_mapping);
      v45 = ipa3_ctx;
    }
    v37 = *(_QWORD *)(v45 + 34160);
    if ( !v37 )
      goto LABEL_81;
    v38 = "ipa %s:%d EP %d already allocated.\n";
    v39 = 983;
LABEL_74:
    v47 = ep_mapping;
LABEL_80:
    ipc_log_string(v37, v38, "ipa3_conn_wigig_rx_pipe_i", v39, v47);
    v32 = -14;
    goto LABEL_52;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))ipa3_wigig_smmu_map_channel)();
}
