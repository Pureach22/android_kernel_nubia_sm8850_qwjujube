__int64 ipa_get_teth_stats()
{
  _BYTE *v0; // x19
  _BYTE *v1; // x20
  unsigned int v2; // w0
  __int64 v3; // x0
  int ep_mapping; // w0
  __int64 v5; // x8
  unsigned int v6; // w21
  __int64 v7; // x0
  int v8; // w23
  unsigned int v9; // w0
  __int64 v10; // x25
  __int64 v11; // x8
  unsigned int v12; // w0
  __int64 v13; // x21
  unsigned int v14; // w22
  _BYTE *v15; // x28
  unsigned int i; // w19
  unsigned int v17; // w25
  unsigned int v18; // w0
  unsigned int v19; // w23
  unsigned int ep_reg_idx; // w27
  unsigned int v21; // w0
  unsigned int v22; // w26
  int v23; // w21
  signed int v24; // w27
  int v25; // w21
  __int64 v26; // x0
  unsigned __int64 v27; // x26
  __int64 v28; // x8
  unsigned __int64 v29; // x21
  _QWORD *v30; // x25
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x8
  __int64 v36; // x9
  int v37; // w10
  __int64 v38; // x11
  __int64 v39; // x12
  int v40; // w13
  __int64 v41; // x8
  __int64 v42; // x11
  int v43; // w9
  int v44; // w14
  unsigned int v45; // w19
  __int64 v46; // x8
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 result; // x0
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x8
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  int v66; // [xsp+4h] [xbp-26Ch]
  _BYTE *v67; // [xsp+8h] [xbp-268h]
  _BYTE *v68; // [xsp+10h] [xbp-260h]
  __int64 v69; // [xsp+18h] [xbp-258h]
  __int64 v70; // [xsp+20h] [xbp-250h]
  __int64 v71; // [xsp+28h] [xbp-248h] BYREF
  __int64 v72; // [xsp+30h] [xbp-240h]
  __int64 v73; // [xsp+38h] [xbp-238h] BYREF
  __int64 v74; // [xsp+40h] [xbp-230h]
  __int64 v75; // [xsp+48h] [xbp-228h]
  __int64 v76; // [xsp+50h] [xbp-220h] BYREF
  _QWORD v77[26]; // [xsp+58h] [xbp-218h] BYREF
  __int64 v78; // [xsp+128h] [xbp-148h] BYREF
  __int64 v79; // [xsp+130h] [xbp-140h]
  _BYTE dest[296]; // [xsp+138h] [xbp-138h] BYREF
  __int64 v81; // [xsp+260h] [xbp-10h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v0 = *(_BYTE **)(ipa3_ctx + 43800);
  if ( !v0 )
    goto LABEL_68;
  v71 = 0;
  v72 = 0;
  if ( *v0 != 1 || v0[64976] != 1 )
    goto LABEL_68;
  v1 = v0 + 880;
  memset(v77, 0, sizeof(v77));
  v78 = 0;
  v79 = 0;
  memcpy(dest, v0 + 880, sizeof(dest));
  v2 = ((__int64 (__fastcall *)(__int64, _BYTE *, __int64 *))ipahal_stats_get_offset)(1, dest, &v76);
  if ( v2 )
  {
    v45 = v2;
    printk(&unk_3F543B, "ipa_get_teth_stats");
    v46 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v47 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v47 )
      {
        ipc_log_string(v47, "ipa %s:%d failed to get offset from hal %d\n", "ipa_get_teth_stats", 1118, v45);
        v46 = ipa3_ctx;
      }
      v48 = *(_QWORD *)(v46 + 34160);
      if ( v48 )
        ipc_log_string(v48, "ipa %s:%d failed to get offset from hal %d\n", "ipa_get_teth_stats", 1118, v45);
    }
    goto LABEL_104;
  }
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v3 )
      ipc_log_string(v3, "ipa %s:%d offset = %d size = %d\n", "ipa_get_teth_stats", 1122, v76, WORD2(v76));
  }
  if ( !WORD2(v76) )
    goto LABEL_68;
  LODWORD(v72) = WORD2(v76);
  v70 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34216), WORD2(v76), &v71, 3264, 0);
  if ( v70 )
  {
    ep_mapping = ipa_get_ep_mapping(95);
    v5 = ipa3_ctx;
    if ( ep_mapping == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
    {
      v6 = 0;
    }
    else
    {
      ipa_close_coal_frame(&v78);
      if ( !v78 )
      {
        printk(&unk_3AEDE8, "ipa_get_teth_stats");
        v61 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v62 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v62 )
          {
            ipc_log_string(v62, "ipa %s:%d failed to construct coal close IC\n", "ipa_get_teth_stats", 1142);
            v61 = ipa3_ctx;
          }
          v63 = *(_QWORD *)(v61 + 34160);
          if ( v63 )
            ipc_log_string(v63, "ipa %s:%d failed to construct coal close IC\n", "ipa_get_teth_stats", 1142);
        }
        v45 = -12;
        goto LABEL_103;
      }
      ipa3_init_imm_cmd_desc(v77, v78);
      v5 = ipa3_ctx;
      v6 = 1;
    }
    BYTE2(v75) = 0;
    LOWORD(v75) = 257;
    HIDWORD(v75) = 0;
    LODWORD(v74) = v72;
    v73 = v71;
    HIDWORD(v74) = *(_DWORD *)(**(_QWORD **)(v5 + 34176) + 312LL) + *(unsigned __int16 *)(v5 + 29522) + (_DWORD)v76;
    v7 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v73, 0);
    *(&v78 + v6) = v7;
    if ( v7 )
    {
      ipa3_init_imm_cmd_desc(&v77[13 * v6], v7);
      v8 = v6 + 1;
      v9 = ((__int64 (__fastcall *)(_QWORD, _QWORD *))ipa3_send_cmd)(v6 + 1, v77);
      if ( v9 )
      {
        v45 = v9;
        printk(&unk_3B18DA, "ipa_get_teth_stats");
        v55 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v56 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v56 )
          {
            ipc_log_string(
              v56,
              "ipa %s:%d failed to send immediate command (error %d)\n",
              "ipa_get_teth_stats",
              1170,
              v45);
            v55 = ipa3_ctx;
          }
          v57 = *(_QWORD *)(v55 + 34160);
          if ( v57 )
            ipc_log_string(
              v57,
              "ipa %s:%d failed to send immediate command (error %d)\n",
              "ipa_get_teth_stats",
              1170,
              v45);
        }
      }
      else
      {
        v10 = vmalloc_noprof(41472);
        v11 = ipa3_ctx;
        if ( v10 )
        {
          v12 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))ipahal_parse_stats)(
                  1,
                  *(_QWORD *)(ipa3_ctx + 43800) + 880LL,
                  v70,
                  v10);
          if ( v12 )
          {
            v45 = v12;
            printk(&unk_3F81B0, "ipa_get_teth_stats");
            v58 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v59 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v59 )
              {
                ipc_log_string(v59, "ipa %s:%d failed to parse stats_all (error %d)\n", "ipa_get_teth_stats", 1184, v45);
                v58 = ipa3_ctx;
              }
              v60 = *(_QWORD *)(v58 + 34160);
              if ( v60 )
                ipc_log_string(v60, "ipa %s:%d failed to parse stats_all (error %d)\n", "ipa_get_teth_stats", 1184, v45);
            }
          }
          else
          {
            v66 = v6 + 1;
            v13 = -31104;
            v69 = v10;
            do
            {
              memset((void *)(*(_QWORD *)(ipa3_ctx + 43800) + v13 + 63384), 0, 0x360u);
              v13 += 864;
            }
            while ( v13 );
            v14 = 0;
            v15 = v0 + 888;
            v67 = v0 + 1176;
            v68 = v0 + 32280;
            do
            {
              for ( i = 0; i != 134; ++i )
              {
                v17 = ipa_get_ep_mapping(v14);
                v18 = ipa_get_ep_mapping(i);
                if ( v17 != -1 )
                {
                  v19 = v18;
                  if ( v17 < (unsigned int)ipa3_get_max_num_pipes()
                    && v19 != -1
                    && v19 < (unsigned int)ipa3_get_max_num_pipes() )
                  {
                    ep_reg_idx = ipahal_get_ep_reg_idx(v17);
                    v21 = ipahal_get_ep_reg_idx(v19);
                    if ( ep_reg_idx > 1 )
                      goto LABEL_93;
                    v22 = v21;
                    v23 = *(_DWORD *)&v1[4 * ep_reg_idx];
                    if ( ((unsigned int)ipahal_get_ep_bit(v17) & v23) != 0 )
                    {
                      if ( v17 > 0x23 || v22 > 1 )
                        goto LABEL_93;
                      v24 = v17;
                      v25 = *(_DWORD *)&v15[8 * v17 + 4 * v22];
                      if ( ((unsigned int)ipahal_get_ep_bit(v19) & v25) != 0 )
                      {
                        if ( ipa3_ctx )
                        {
                          v26 = *(_QWORD *)(ipa3_ctx + 34160);
                          if ( v26 )
                            ipc_log_string(v26, "ipa %s:%d prod %d cons %d\n", "ipa_get_teth_stats", 1221, v17, v19);
                        }
                        if ( v19 > 0x24 )
                        {
LABEL_93:
                          __break(0x5512u);
LABEL_94:
                          __break(1u);
                        }
                        v27 = 1152LL * (int)v17 + 32LL * (int)v19;
                        v28 = ipa3_ctx;
                        v29 = v27 >> 9;
                        v30 = (_QWORD *)(v27 + v69);
                        if ( ipa3_ctx )
                        {
                          v31 = *(_QWORD *)(ipa3_ctx + 34160);
                          if ( !v31 )
                            goto LABEL_42;
                          if ( v29 > 0x50 )
                            goto LABEL_94;
                          ipc_log_string(v31, "ipa %s:%d num_ipv4_bytes %lld\n", "ipa_get_teth_stats", 1224, *v30);
                          v28 = ipa3_ctx;
                          if ( ipa3_ctx )
                          {
LABEL_42:
                            v32 = *(_QWORD *)(v28 + 34160);
                            if ( !v32 )
                              goto LABEL_45;
                            if ( (v27 | 0x10) > 0xA200 )
                              goto LABEL_94;
                            ipc_log_string(v32, "ipa %s:%d num_ipv4_pkts %lld\n", "ipa_get_teth_stats", 1226, v30[2]);
                            v28 = ipa3_ctx;
                            if ( ipa3_ctx )
                            {
LABEL_45:
                              v33 = *(_QWORD *)(v28 + 34160);
                              if ( !v33 )
                                goto LABEL_48;
                              if ( (v27 | 0x18) > 0xA200 )
                                goto LABEL_94;
                              ipc_log_string(v33, "ipa %s:%d num_ipv6_pkts %lld\n", "ipa_get_teth_stats", 1228, v30[3]);
                              v28 = ipa3_ctx;
                              if ( ipa3_ctx )
                              {
LABEL_48:
                                v34 = *(_QWORD *)(v28 + 34160);
                                if ( v34 )
                                {
                                  if ( (v27 | 8) > 0xA200 )
                                    goto LABEL_94;
                                  ipc_log_string(
                                    v34,
                                    "ipa %s:%d num_ipv6_bytes %lld\n",
                                    "ipa_get_teth_stats",
                                    1230,
                                    v30[1]);
                                }
                              }
                            }
                          }
                        }
                        if ( v29 > 0x50 )
                          goto LABEL_94;
                        v35 = (__int64)&v68[864 * v24 + 24 * v19];
                        v36 = *v30;
                        *(_QWORD *)v35 = *v30;
                        if ( (v27 | 0x10) > 0xA200 )
                          goto LABEL_94;
                        v37 = *((_DWORD *)v30 + 4);
                        *(_DWORD *)(v35 + 16) = v37;
                        if ( (v27 | 8) > 0xA200 )
                          goto LABEL_94;
                        v38 = v30[1];
                        *(_QWORD *)(v35 + 8) = v38;
                        if ( (v27 | 0x18) > 0xA200 )
                          goto LABEL_94;
                        v39 = (__int64)&v67[864 * v24 + 24 * v19];
                        v40 = *((_DWORD *)v30 + 6);
                        *(_DWORD *)(v35 + 20) = v40;
                        v41 = *(_QWORD *)v39 + v36;
                        v42 = *(_QWORD *)(v39 + 8) + v38;
                        v43 = *(_DWORD *)(v39 + 16);
                        v44 = *(_DWORD *)(v39 + 20);
                        *(_QWORD *)v39 = v41;
                        *(_QWORD *)(v39 + 8) = v42;
                        *(_DWORD *)(v39 + 16) = v43 + v37;
                        *(_DWORD *)(v39 + 20) = v44 + v40;
                      }
                    }
                  }
                }
              }
              ++v14;
            }
            while ( v14 != 134 );
            v8 = v66;
            v10 = v69;
            v45 = 0;
          }
          vfree(v10);
        }
        else
        {
          if ( ipa3_ctx )
          {
            v64 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v64 )
            {
              ipc_log_string(v64, "ipa %s:%d failed to alloc memory\n", "ipa_get_teth_stats", 1176);
              v11 = ipa3_ctx;
            }
            v65 = *(_QWORD *)(v11 + 34160);
            if ( v65 )
              ipc_log_string(v65, "ipa %s:%d failed to alloc memory\n", "ipa_get_teth_stats", 1176);
          }
          v45 = -12;
        }
      }
    }
    else
    {
      printk(&unk_3A8EB0, "ipa_get_teth_stats");
      v52 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v53 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v53 )
        {
          ipc_log_string(v53, "ipa %s:%d failed to construct dma_shared_mem imm cmd\n", "ipa_get_teth_stats", 1161);
          v52 = ipa3_ctx;
        }
        v54 = *(_QWORD *)(v52 + 34160);
        if ( v54 )
          ipc_log_string(v54, "ipa %s:%d failed to construct dma_shared_mem imm cmd\n", "ipa_get_teth_stats", 1161);
      }
      v45 = -12;
      if ( !v6 )
        goto LABEL_103;
      v8 = 1;
    }
    kfree(v78);
    if ( v8 != 1 )
      kfree(v79);
LABEL_103:
    dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v72, v70, v71, 0);
LABEL_104:
    result = v45;
    goto LABEL_69;
  }
  printk(&unk_3DB7B7, "ipa_get_teth_stats");
  v49 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v50 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v50 )
    {
      ipc_log_string(v50, "ipa %s:%d fail to alloc DMA memory\n", "ipa_get_teth_stats", 1133);
      v49 = ipa3_ctx;
    }
    result = *(_QWORD *)(v49 + 34160);
    if ( result )
    {
      ipc_log_string(result, "ipa %s:%d fail to alloc DMA memory\n", "ipa_get_teth_stats", 1133);
      result = 0;
    }
  }
  else
  {
LABEL_68:
    result = 0;
  }
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
