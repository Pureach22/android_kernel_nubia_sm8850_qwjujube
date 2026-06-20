__int64 __fastcall ipa3_conn_wigig_client_i(__int64 a1, int *a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  char *v15; // x20
  unsigned int v16; // w27
  char v17; // w25
  __int64 *v18; // x28
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 result; // x0
  __int64 v24; // x8
  unsigned int v25; // w20
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned int ep_mapping; // w23
  __int64 max_num_pipes; // x0
  __int64 v30; // x1
  __int64 v31; // x25
  _DWORD *v32; // x25
  int v33; // t1
  __int64 v34; // x0
  __int64 v35; // x26
  unsigned int v36; // w0
  long double v37; // q0
  long double v38; // q1
  long double v39; // q2
  long double v40; // q3
  float v41; // s4
  unsigned int *v42; // x20
  __int64 *v43; // x8
  __int64 v44; // x21
  unsigned int v45; // w20
  long double v46; // q0
  long double v47; // q1
  long double v48; // q2
  long double v49; // q3
  float v50; // s4
  unsigned int v51; // w0
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x0
  int v55; // w19
  __int64 v56; // x8
  __int64 v57; // x0
  __int64 v58; // x8
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x8
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x8
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x8
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x8
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x8
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x8
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x8
  __int64 v83; // x0
  __int64 v84; // x0
  int v85; // w19
  __int64 v86; // x8
  __int64 v87; // x0
  __int64 v88; // x0
  int *v89; // [xsp+8h] [xbp-108h]
  char v90; // [xsp+14h] [xbp-FCh]
  char v91; // [xsp+18h] [xbp-F8h]
  char v92; // [xsp+1Ch] [xbp-F4h]
  int v93; // [xsp+3Ch] [xbp-D4h] BYREF
  __int64 v94; // [xsp+40h] [xbp-D0h] BYREF
  __int64 v95; // [xsp+48h] [xbp-C8h]
  __int64 v96; // [xsp+50h] [xbp-C0h]
  __int64 v97; // [xsp+58h] [xbp-B8h]
  __int64 v98; // [xsp+60h] [xbp-B0h]
  __int64 v99; // [xsp+68h] [xbp-A8h]
  __int64 v100; // [xsp+70h] [xbp-A0h]
  __int64 v101; // [xsp+78h] [xbp-98h]
  __int64 v102; // [xsp+80h] [xbp-90h]
  __int64 v103; // [xsp+88h] [xbp-88h]
  __int64 v104; // [xsp+90h] [xbp-80h]
  __int64 v105; // [xsp+98h] [xbp-78h]
  __int64 v106; // [xsp+A0h] [xbp-70h]
  __int64 v107; // [xsp+A8h] [xbp-68h]
  __int64 v108; // [xsp+B0h] [xbp-60h]
  __int64 v109; // [xsp+B8h] [xbp-58h]
  __int64 v110; // [xsp+C0h] [xbp-50h]
  __int64 v111; // [xsp+C8h] [xbp-48h]
  __int64 v112; // [xsp+D0h] [xbp-40h]
  __int64 v113; // [xsp+D8h] [xbp-38h]
  __int64 v114; // [xsp+E0h] [xbp-30h]
  __int64 v115; // [xsp+E8h] [xbp-28h]
  __int64 v116; // [xsp+F0h] [xbp-20h]
  __int64 v117; // [xsp+F8h] [xbp-18h]
  __int64 v118; // [xsp+100h] [xbp-10h]

  v118 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = ipa3_ctx;
  v116 = 0;
  v117 = 0;
  v114 = 0;
  v115 = 0;
  v112 = 0;
  v113 = 0;
  v110 = 0;
  v111 = 0;
  v108 = 0;
  v109 = 0;
  v106 = 0;
  v107 = 0;
  v104 = 0;
  v105 = 0;
  v102 = 0;
  v103 = 0;
  v100 = 0;
  v101 = 0;
  v98 = 0;
  v99 = 0;
  v96 = 0;
  v97 = 0;
  v94 = 0;
  v95 = 0;
  v93 = 0;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d \n", "ipa3_conn_wigig_client_i", 1182);
      v8 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v8 + 34160);
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d \n", "ipa3_conn_wigig_client_i", 1182);
      v8 = ipa3_ctx;
    }
    if ( (*(_BYTE *)(v8 + 43314) & 1) != 0 )
    {
      if ( v8 )
      {
        v11 = *(_QWORD *)(v8 + 34152);
        if ( v11 )
        {
          ipc_log_string(
            v11,
            "ipa %s:%d desc_ring_base_pa %pa desc_ring_size %d status_ring_base_pa %pa status_ring_size %d",
            "ipa3_conn_wigig_client_i",
            1233,
            (const void *)a1,
            *(unsigned __int16 *)(a1 + 8),
            (const void *)(a1 + 32),
            *(unsigned __int16 *)(a1 + 40));
          v8 = ipa3_ctx;
        }
        v12 = *(_QWORD *)(v8 + 34160);
        if ( v12 )
        {
          ipc_log_string(
            v12,
            "ipa %s:%d desc_ring_base_pa %pa desc_ring_size %d status_ring_base_pa %pa status_ring_size %d",
            "ipa3_conn_wigig_client_i",
            1233,
            (const void *)a1,
            *(unsigned __int16 *)(a1 + 8),
            (const void *)(a1 + 32),
            *(unsigned __int16 *)(a1 + 40));
          v8 = ipa3_ctx;
        }
        if ( v8 )
        {
          v13 = *(_QWORD *)(v8 + 34152);
          if ( v13 )
          {
            ipc_log_string(v13, "ipa %s:%d data_buffer_size %d", "ipa3_conn_wigig_client_i", 1234, *(_DWORD *)(a1 + 64));
            v8 = ipa3_ctx;
          }
          v14 = *(_QWORD *)(v8 + 34160);
          if ( v14 )
            ipc_log_string(v14, "ipa %s:%d data_buffer_size %d", "ipa3_conn_wigig_client_i", 1234, *(_DWORD *)(a1 + 64));
        }
      }
LABEL_18:
      v15 = (char *)(a1 + 68);
      if ( !(unsigned int)ipa3_wigig_tx_bit_to_ep(*(unsigned __int8 *)(a1 + 68), &v93) )
      {
        v16 = *(_DWORD *)(a1 + 64);
        if ( v16 >= 0x10000 )
        {
          printk(&unk_3E7536, "ipa3_conn_wigig_client_i");
          v73 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v74 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v74 )
            {
              ipc_log_string(
                v74,
                "ipa %s:%d data_buffer_size is over the 16 bit limit (0x%X)\n",
                "ipa3_conn_wigig_client_i",
                1244,
                *(_DWORD *)(a1 + 64));
              v73 = ipa3_ctx;
            }
            v75 = *(_QWORD *)(v73 + 34160);
            if ( v75 )
            {
              ipc_log_string(
                v75,
                "ipa %s:%d data_buffer_size is over the 16 bit limit (0x%X)\n",
                "ipa3_conn_wigig_client_i",
                1244,
                *(unsigned int *)(a1 + 64));
              goto LABEL_108;
            }
          }
          goto LABEL_120;
        }
        if ( ((*(_QWORD *)(a1 + 56) ^ *(_QWORD *)(a1 + 48)) & 0xFF00000000LL) == 0 )
        {
          v17 = 0;
          v18 = (__int64 *)a1;
          v92 = 1;
          a1 = 0;
          goto LABEL_37;
        }
        printk(&unk_3FEF20, "ipa3_conn_wigig_client_i");
        v79 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_120;
        v80 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v80 )
        {
          ipc_log_string(
            v80,
            "ipa %s:%d status ring HWHEAD and HWTAIL differ in 8 MSbs head 0x%llX tail 0x%llX\n",
            "ipa3_conn_wigig_client_i",
            1255,
            *(_QWORD *)(a1 + 48),
            *(_QWORD *)(a1 + 56));
          v79 = ipa3_ctx;
        }
        v81 = *(_QWORD *)(v79 + 34160);
        if ( !v81 )
          goto LABEL_120;
        ipc_log_string(
          v81,
          "ipa %s:%d status ring HWHEAD and HWTAIL differ in 8 MSbs head 0x%llX tail 0x%llX\n",
          "ipa3_conn_wigig_client_i",
          1255,
          *(_QWORD *)(a1 + 48),
          *(_QWORD *)(a1 + 56));
LABEL_119:
        result = 4294967282LL;
        goto LABEL_121;
      }
LABEL_33:
      result = 4294967274LL;
LABEL_121:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    if ( v8 )
    {
      v19 = *(_QWORD *)(v8 + 34152);
      if ( v19 )
      {
        ipc_log_string(
          v19,
          "ipa %s:%d desc_ring_base_iova 0x%llX desc_ring_size %d status_ring_base_iova 0x%llX status_ring_size %d",
          "ipa3_conn_wigig_client_i",
          1193,
          *(_QWORD *)(a1 + 16),
          *(unsigned __int16 *)(a1 + 24),
          *(_QWORD *)(a1 + 64),
          *(unsigned __int16 *)(a1 + 72));
        v8 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v8 + 34160);
      if ( v20 )
      {
        ipc_log_string(
          v20,
          "ipa %s:%d desc_ring_base_iova 0x%llX desc_ring_size %d status_ring_base_iova 0x%llX status_ring_size %d",
          "ipa3_conn_wigig_client_i",
          1193,
          *(_QWORD *)(a1 + 16),
          *(unsigned __int16 *)(a1 + 24),
          *(_QWORD *)(a1 + 64),
          *(unsigned __int16 *)(a1 + 72));
        v8 = ipa3_ctx;
      }
      if ( v8 )
      {
        v21 = *(_QWORD *)(v8 + 34152);
        if ( v21 )
        {
          ipc_log_string(
            v21,
            "ipa %s:%d num buffers %d, data buffer size %d\n",
            "ipa3_conn_wigig_client_i",
            1196,
            *(_DWORD *)(a1 + 112),
            *(_DWORD *)(a1 + 116));
          v8 = ipa3_ctx;
        }
        v22 = *(_QWORD *)(v8 + 34160);
        if ( v22 )
          ipc_log_string(
            v22,
            "ipa %s:%d num buffers %d, data buffer size %d\n",
            "ipa3_conn_wigig_client_i",
            1196,
            *(_DWORD *)(a1 + 112),
            *(_DWORD *)(a1 + 116));
      }
    }
  }
  else if ( (byte_A932 & 1) != 0 )
  {
    goto LABEL_18;
  }
  v15 = (char *)(a1 + 120);
  if ( (unsigned int)ipa3_wigig_tx_bit_to_ep(*(unsigned __int8 *)(a1 + 120), &v93) )
    goto LABEL_33;
  v16 = *(_DWORD *)(a1 + 116);
  if ( v16 >= 0x10000 )
  {
    printk(&unk_3E7536, "ipa3_conn_wigig_client_i");
    v76 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v77 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v77 )
      {
        ipc_log_string(
          v77,
          "ipa %s:%d data_buffer_size is over the 16 bit limit (0x%X)\n",
          "ipa3_conn_wigig_client_i",
          1205,
          *(_DWORD *)(a1 + 116));
        v76 = ipa3_ctx;
      }
      v78 = *(_QWORD *)(v76 + 34160);
      if ( v78 )
      {
        ipc_log_string(
          v78,
          "ipa %s:%d data_buffer_size is over the 16 bit limit (0x%X)\n",
          "ipa3_conn_wigig_client_i",
          1205,
          *(unsigned int *)(a1 + 116));
        goto LABEL_108;
      }
    }
    goto LABEL_120;
  }
  if ( ((*(_QWORD *)(a1 + 88) ^ *(_QWORD *)(a1 + 80)) & 0xFF00000000LL) != 0 )
  {
    printk(&unk_3FEF20, "ipa3_conn_wigig_client_i");
    v82 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_120;
    v83 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v83 )
    {
      ipc_log_string(
        v83,
        "ipa %s:%d status ring HWHEAD and HWTAIL differ in 8 MSbs head 0x%llX tail 0x%llX\n",
        "ipa3_conn_wigig_client_i",
        1216,
        *(_QWORD *)(a1 + 80),
        *(_QWORD *)(a1 + 88));
      v82 = ipa3_ctx;
    }
    v84 = *(_QWORD *)(v82 + 34160);
    if ( !v84 )
      goto LABEL_120;
    ipc_log_string(
      v84,
      "ipa %s:%d status ring HWHEAD and HWTAIL differ in 8 MSbs head 0x%llX tail 0x%llX\n",
      "ipa3_conn_wigig_client_i",
      1216,
      *(_QWORD *)(a1 + 80),
      *(_QWORD *)(a1 + 88));
    goto LABEL_119;
  }
  v18 = nullptr;
  v17 = 1;
  v92 = 0;
LABEL_37:
  v24 = ipa3_ctx;
  v90 = *v15;
  if ( ipa3_ctx )
  {
    v25 = v93;
    v26 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v26 )
    {
      ipc_log_string(v26, "ipa %s:%d client type is %d\n", "ipa3_conn_wigig_client_i", 1265, v93);
      v24 = ipa3_ctx;
    }
    v27 = *(_QWORD *)(v24 + 34160);
    if ( v27 )
      ipc_log_string(v27, "ipa %s:%d client type is %d\n", "ipa3_conn_wigig_client_i", 1265, v25);
  }
  else
  {
    v25 = v93;
  }
  ep_mapping = ipa_get_ep_mapping(v25);
  if ( ep_mapping == -1 || (max_num_pipes = ipa3_get_max_num_pipes(), ep_mapping >= (unsigned int)max_num_pipes) )
  {
    printk(&unk_3CD9BE, "ipa3_conn_wigig_client_i");
    v52 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v53 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v53 )
      {
        ipc_log_string(v53, "ipa %s:%d fail to get ep (%d) %d.\n", "ipa3_conn_wigig_client_i", 1271, v25, ep_mapping);
        v52 = ipa3_ctx;
      }
      v54 = *(_QWORD *)(v52 + 34160);
      if ( v54 )
      {
        ipc_log_string(v54, "ipa %s:%d fail to get ep (%d) %d.\n", "ipa3_conn_wigig_client_i", 1271, v25, ep_mapping);
        result = 4294967282LL;
        goto LABEL_121;
      }
    }
    goto LABEL_120;
  }
  v91 = v17;
  if ( ep_mapping <= 0x24 )
  {
    v31 = ipa3_ctx + 480LL * ep_mapping;
    v33 = *(_DWORD *)(v31 + 168);
    v32 = (_DWORD *)(v31 + 168);
    if ( v33 )
    {
      printk(&unk_3B202E, "ipa3_conn_wigig_client_i");
      v58 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_120;
      v59 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v59 )
      {
        ipc_log_string(v59, "ipa %s:%d EP %d already allocated.\n", "ipa3_conn_wigig_client_i", 1277, ep_mapping);
        v58 = ipa3_ctx;
      }
      v60 = *(_QWORD *)(v58 + 34160);
      if ( !v60 )
        goto LABEL_120;
      ipc_log_string(v60, "ipa %s:%d EP %d already allocated.\n", "ipa3_conn_wigig_client_i", 1277, ep_mapping);
    }
    else
    {
      if ( !v32[113] )
      {
        v89 = a2;
        v34 = ((__int64 (__fastcall *)(_QWORD))ipa_get_gsi_ep_info)(v25);
        if ( v34 )
        {
          v35 = v34;
          memset(v32, 0, 0x1D8u);
          ipa3_inc_client_enable_clks();
          *v32 = 1;
          v32[1] = v25;
          v36 = ipa3_disable_data_path(ep_mapping);
          if ( v36 )
          {
            v45 = v36;
            printk(&unk_3EF093, "ipa3_conn_wigig_client_i");
            v67 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v68 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v68 )
              {
                ipc_log_string(
                  v68,
                  "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
                  "ipa3_conn_wigig_client_i",
                  1303,
                  v45,
                  ep_mapping);
                v67 = ipa3_ctx;
              }
              v69 = *(_QWORD *)(v67 + 34160);
              if ( v69 )
                ipc_log_string(
                  v69,
                  "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
                  "ipa3_conn_wigig_client_i",
                  1303,
                  v45,
                  ep_mapping);
            }
            goto LABEL_61;
          }
          *((_QWORD *)v32 + 46) = a4;
          *((_QWORD *)v32 + 47) = a3;
          v95 = 0xE00000000LL;
          v94 = 2;
          v116 = 0;
          v117 = 0;
          v106 = 0x400000001LL;
          v114 = 0;
          v115 = 0;
          v112 = 0;
          v113 = 0;
          v111 = 0;
          v109 = 0;
          v104 = 0;
          v105 = 0;
          v102 = 256;
          v103 = 0;
          v100 = 0;
          v101 = 0;
          v98 = 0;
          v99 = 0;
          v96 = 0;
          v97 = 0;
          v110 = 0;
          v108 = 0x100000001LL;
          v107 = (unsigned __int16)v16 / 0x3E8u;
          if ( (unsigned int)ipa3_cfg_ep(ep_mapping, (__int64)&v94) )
          {
            printk(&unk_3BB0CE, "ipa3_conn_wigig_client_i");
            v70 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v71 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v71 )
              {
                ipc_log_string(v71, "ipa %s:%d fail to setup rx pipe cfg\n", "ipa3_conn_wigig_client_i", 1327);
                v70 = ipa3_ctx;
              }
              v72 = *(_QWORD *)(v70 + 34160);
              if ( v72 )
              {
                ipc_log_string(v72, "ipa %s:%d fail to setup rx pipe cfg\n", "ipa3_conn_wigig_client_i", 1327);
                v45 = -14;
                goto LABEL_61;
              }
            }
          }
          else
          {
            if ( (v92 & 1) != 0 )
            {
              v42 = (unsigned int *)(v18 + 8);
              v43 = v18 + 2;
LABEL_55:
              v44 = *v43;
              v45 = ipa3_wigig_config_gsi(0, v91, v18, v42, v35, (__int64)v32);
              if ( v45 )
              {
                if ( !a1 )
                  goto LABEL_61;
              }
              else
              {
                v51 = ipa3_wigig_config_uc(1, 0, v90, *(_DWORD *)(v35 + 4), v44);
                if ( !v51 )
                {
                  v55 = v93;
                  *v89 = v93;
                  v32[113] |= 1u;
                  ipa3_dec_client_disable_clks();
                  v56 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v57 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v57 )
                    {
                      ipc_log_string(
                        v57,
                        "ipa %s:%d wigig client %d (ep %d) connected successfully\n",
                        "ipa3_conn_wigig_client_i",
                        1377,
                        v55,
                        ep_mapping);
                      v56 = ipa3_ctx;
                    }
                    result = *(_QWORD *)(v56 + 34160);
                    if ( result )
                    {
                      ipc_log_string(
                        result,
                        "ipa %s:%d wigig client %d (ep %d) connected successfully\n",
                        "ipa3_conn_wigig_client_i",
                        1377,
                        v55,
                        ep_mapping);
                      result = 0;
                    }
                  }
                  else
                  {
                    result = 0;
                  }
                  goto LABEL_121;
                }
                v45 = v51;
                ((void (__fastcall *)(_QWORD))ipa3_release_gsi_channel)(ep_mapping);
                if ( !a1 )
                  goto LABEL_61;
              }
              ipa3_wigig_smmu_map_channel(0, a1, a1 + 96, 0, v46, v47, v48, v49, v50);
LABEL_61:
              *v32 = 0;
              ipa3_dec_client_disable_clks();
              result = v45;
              goto LABEL_121;
            }
            v42 = (unsigned int *)(a1 + 96);
            if ( !(unsigned int)ipa3_wigig_smmu_map_channel(0, a1, a1 + 96, 1u, v37, v38, v39, v40, v41) )
            {
              v43 = (__int64 *)(a1 + 32);
              v18 = (__int64 *)a1;
              goto LABEL_55;
            }
            v85 = v93;
            printk(&unk_3FEF74, "ipa3_conn_wigig_client_i");
            v86 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v87 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v87 )
              {
                ipc_log_string(
                  v87,
                  "ipa %s:%d failed to setup tx pipe smmu map client %d (ep %d)\n",
                  "ipa3_conn_wigig_client_i",
                  1340,
                  v85,
                  ep_mapping);
                v86 = ipa3_ctx;
              }
              v88 = *(_QWORD *)(v86 + 34160);
              if ( v88 )
                ipc_log_string(
                  v88,
                  "ipa %s:%d failed to setup tx pipe smmu map client %d (ep %d)\n",
                  "ipa3_conn_wigig_client_i",
                  1340,
                  v85,
                  ep_mapping);
            }
          }
          v45 = -14;
          goto LABEL_61;
        }
        printk(&unk_3CC819, "ipa3_conn_wigig_client_i");
        v64 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v65 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v65 )
          {
            ipc_log_string(
              v65,
              "ipa %s:%d Failed getting GSI EP info for client=%d\n",
              "ipa3_conn_wigig_client_i",
              1290,
              v25);
            v64 = ipa3_ctx;
          }
          v66 = *(_QWORD *)(v64 + 34160);
          if ( v66 )
          {
            ipc_log_string(
              v66,
              "ipa %s:%d Failed getting GSI EP info for client=%d\n",
              "ipa3_conn_wigig_client_i",
              1290,
              v25);
            goto LABEL_108;
          }
        }
LABEL_120:
        result = 4294967282LL;
        goto LABEL_121;
      }
      printk(&unk_3D6A26, "ipa3_conn_wigig_client_i");
      v61 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_120;
      v62 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v62 )
      {
        ipc_log_string(v62, "ipa %s:%d WIGIG channel bad state 0x%X\n", "ipa3_conn_wigig_client_i", 1283, v32[113]);
        v61 = ipa3_ctx;
      }
      v63 = *(_QWORD *)(v61 + 34160);
      if ( !v63 )
        goto LABEL_120;
      ipc_log_string(
        v63,
        "ipa %s:%d WIGIG channel bad state 0x%X\n",
        "ipa3_conn_wigig_client_i",
        1283,
        (unsigned int)v32[113]);
    }
LABEL_108:
    result = 4294967282LL;
    goto LABEL_121;
  }
  __break(0x5512u);
  return ipa3_wigig_tx_bit_to_ep(max_num_pipes, v30);
}
