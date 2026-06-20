__int64 __fastcall ipa_init_quota_stats(int *a1)
{
  __int64 v2; // x19
  _BYTE *v3; // x8
  int v4; // w5
  __int64 v5; // x0
  int v6; // w5
  __int64 v7; // x8
  __int64 v8; // x0
  unsigned __int16 *init_pyld; // x0
  unsigned __int16 *v10; // x19
  __int64 v11; // x20
  unsigned int v12; // w21
  unsigned __int16 *v13; // x22
  const char **v14; // x21
  char v15; // w0
  int ep_mapping; // w0
  __int64 v17; // x8
  unsigned int v18; // w24
  __int64 result; // x0
  unsigned int v20; // w0
  unsigned int v21; // w8
  __int16 *v22; // x0
  _QWORD *v23; // x8
  __int16 *v24; // x22
  _WORD *v25; // x23
  unsigned int v26; // w24
  __int16 v27; // w9
  _QWORD *v28; // x8
  int v29; // w10
  __int16 v30; // w9
  _WORD *v31; // x0
  _QWORD *v32; // x8
  __int16 v33; // w9
  __int64 v34; // x2
  _WORD *v35; // x0
  _QWORD *v36; // x8
  _WORD *v37; // x25
  __int16 v38; // w9
  _WORD *v39; // x0
  _QWORD *v40; // x8
  _WORD *v41; // x26
  __int16 v42; // w9
  unsigned int v43; // w24
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x0
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
  __int64 v64; // x8
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x8
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x8
  __int64 v71; // x0
  __int64 v72; // x0
  char v73; // w24
  const char *v74; // x0
  const char *v75; // x2
  __int64 v76; // x8
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // [xsp+8h] [xbp-278h]
  __int64 v80; // [xsp+10h] [xbp-270h]
  __int64 v81; // [xsp+18h] [xbp-268h] BYREF
  unsigned __int64 v82; // [xsp+20h] [xbp-260h] BYREF
  __int64 v83; // [xsp+28h] [xbp-258h]
  int v84; // [xsp+30h] [xbp-250h]
  __int64 v85; // [xsp+38h] [xbp-248h] BYREF
  __int64 v86; // [xsp+40h] [xbp-240h]
  int v87; // [xsp+48h] [xbp-238h]
  __int64 v88; // [xsp+50h] [xbp-230h] BYREF
  __int64 v89; // [xsp+58h] [xbp-228h]
  __int64 v90; // [xsp+60h] [xbp-220h]
  _QWORD s[67]; // [xsp+68h] [xbp-218h] BYREF

  s[65] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v89 = 0;
  v90 = 0;
  v88 = 0;
  v87 = 0;
  v85 = 0;
  v86 = 0;
  v84 = 0;
  v82 = 0;
  v83 = 0;
  v81 = 0;
  memset(s, 0, 0x208u);
  v2 = ipa3_ctx;
  v3 = *(_BYTE **)(ipa3_ctx + 43800);
  if ( v3 && *v3 == 1 )
  {
    if ( !a1 )
      goto LABEL_42;
    memset(v3 + 8, 0, 0x368u);
    v4 = *a1;
    *(_DWORD *)(*(_QWORD *)(v2 + 43800) + 8LL) = *a1;
    if ( v2 )
    {
      v5 = *(_QWORD *)(v2 + 34160);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d pipe_bitmask[%d]=0x%x\n", "ipa_init_quota_stats", 526, 0, v4);
        v2 = ipa3_ctx;
      }
    }
    v6 = a1[1];
    *(_DWORD *)(*(_QWORD *)(v2 + 43800) + 12LL) = v6;
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d pipe_bitmask[%d]=0x%x\n", "ipa_init_quota_stats", 526, 1, v6);
        v7 = ipa3_ctx;
      }
    }
    init_pyld = (unsigned __int16 *)ipahal_stats_generate_init_pyld(0, *(_QWORD *)(v7 + 43800) + 8LL, 0);
    if ( init_pyld )
    {
      v10 = init_pyld;
      if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x10u )
      {
        printk(&unk_3A6E1D, "ipa_validate_quota_stats_sram_size");
        v48 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_101;
        v49 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v49 )
        {
          ipc_log_string(
            v49,
            "ipa %s:%d Not supported ipa_ver=%d\n",
            "ipa_validate_quota_stats_sram_size",
            484,
            *(_DWORD *)(ipa3_ctx + 32240));
          v48 = ipa3_ctx;
        }
        v50 = v48 + 32240;
        v51 = *(_QWORD *)(v50 + 1920);
        if ( !v51 )
          goto LABEL_101;
        ipc_log_string(
          v51,
          "ipa %s:%d Not supported ipa_ver=%d\n",
          "ipa_validate_quota_stats_sram_size",
          484,
          *(_DWORD *)v50);
        v43 = -1;
      }
      else
      {
        v11 = *init_pyld;
        v12 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 308LL);
        if ( v12 >= (unsigned int)v11 )
        {
          v13 = init_pyld + 2;
          v14 = *(const char ***)(ipa3_ctx + 34216);
          v15 = is_vmalloc_addr(init_pyld + 2);
          if ( (v15 & 1) != 0 && (dma_map_single_attrs___already_done_0 & 1) == 0 )
          {
            v73 = v15;
            dma_map_single_attrs___already_done_0 = 1;
            v74 = (const char *)dev_driver_string(v14);
            v75 = v14[14];
            if ( !v75 )
              v75 = *v14;
            _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v74, v75);
            __break(0x800u);
            if ( (v73 & 1) == 0 )
            {
LABEL_16:
              v80 = dma_map_page_attrs(
                      v14,
                      ((unsigned __int64)(((__int64)((_QWORD)v13 << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
                    - 0x140000000LL,
                      (unsigned __int16)v13 & 0xFFF,
                      v11,
                      1,
                      0);
              if ( v80 != -1 )
              {
                ep_mapping = ipa_get_ep_mapping(95);
                v17 = ipa3_ctx;
                if ( ep_mapping == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
                {
                  v79 = 0;
                  v18 = 0;
                }
                else
                {
                  ipa_close_coal_frame(&v81);
                  if ( !v81 )
                  {
                    printk(&unk_3AEDE8, "ipa_init_quota_stats");
                    v70 = ipa3_ctx;
                    if ( !ipa3_ctx )
                      goto LABEL_92;
                    v71 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v71 )
                    {
                      ipc_log_string(v71, "ipa %s:%d failed to construct coal close IC\n", "ipa_init_quota_stats", 556);
                      v70 = ipa3_ctx;
                    }
                    v72 = *(_QWORD *)(v70 + 34160);
                    if ( v72 )
                    {
                      ipc_log_string(v72, "ipa %s:%d failed to construct coal close IC\n", "ipa_init_quota_stats", 556);
                      v43 = -12;
                    }
                    else
                    {
LABEL_92:
                      v43 = -12;
                    }
                    goto LABEL_84;
                  }
                  v79 = v81;
                  ipa3_init_imm_cmd_desc(s, v81);
                  v17 = ipa3_ctx;
                  v18 = 1;
                }
                BYTE4(v83) = 0;
                v84 = 2;
                if ( *(_DWORD *)(v17 + 32240) >= 0x15u )
                {
                  HIDWORD(v82) = *a1;
                  LODWORD(v83) = -1;
                  LODWORD(v82) = ipahal_get_reg_nk_offset(134, *(unsigned int *)(v17 + 43304), 0);
                  v24 = (__int16 *)((__int64 (__fastcall *)(__int64, unsigned __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                                     7,
                                     &v82,
                                     0);
                  if ( v24 )
                  {
                    v28 = &s[13 * v18];
                    *((_WORD *)v28 + 18) = v24[1];
                    v28[1] = v24 + 2;
                    v29 = a1[1];
                    v30 = *v24;
                    *(_DWORD *)v28 = 3;
                    HIDWORD(v82) = v29;
                    LODWORD(v83) = -1;
                    *((_WORD *)v28 + 17) = v30;
                    LODWORD(v82) = ipahal_get_reg_nk_offset(134, *(unsigned int *)(ipa3_ctx + 43304), 1);
                    v31 = (_WORD *)((__int64 (__fastcall *)(__int64, unsigned __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                                     7,
                                     &v82,
                                     0);
                    if ( v31 )
                    {
                      v32 = &s[13 * v18];
                      v25 = v31;
                      v26 = v18 | 2;
                      *((_WORD *)v32 + 70) = v31[1];
                      v32[14] = v31 + 2;
                      v33 = *v31;
                      *((_DWORD *)v32 + 26) = 3;
                      *((_WORD *)v32 + 69) = v33;
                      goto LABEL_29;
                    }
                  }
                  printk(&unk_3E98FD, "ipa_init_quota_stats");
                  v55 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v56 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v56 )
                    {
                      ipc_log_string(
                        v56,
                        "ipa %s:%d failed to construct register_write imm cmd\n",
                        "ipa_init_quota_stats",
                        600);
                      v55 = ipa3_ctx;
                    }
                    v57 = *(_QWORD *)(v55 + 34160);
                    if ( v57 )
                      ipc_log_string(
                        v57,
                        "ipa %s:%d failed to construct register_write imm cmd\n",
                        "ipa_init_quota_stats",
                        600);
                  }
                  if ( v24 )
                    kfree(v24);
                }
                else
                {
                  v20 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(
                          104,
                          0,
                          *(unsigned int *)(v17 + 43304));
                  v21 = *a1;
                  LODWORD(v83) = -1;
                  v82 = __PAIR64__(v21, v20);
                  v22 = (__int16 *)((__int64 (__fastcall *)(__int64, unsigned __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                                     7,
                                     &v82,
                                     0);
                  if ( v22 )
                  {
                    v23 = &s[13 * v18];
                    v24 = v22;
                    v25 = nullptr;
                    v26 = v18 + 1;
                    *((_WORD *)v23 + 18) = v22[1];
                    v23[1] = v22 + 2;
                    v27 = *v22;
                    *(_DWORD *)v23 = 3;
                    *((_WORD *)v23 + 17) = v27;
LABEL_29:
                    BYTE4(v86) = 0;
                    v34 = *(unsigned int *)(ipa3_ctx + 43304);
                    v87 = 2;
                    LODWORD(v85) = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))ipahal_get_reg_mn_ofst)(
                                     103,
                                     0,
                                     v34);
                    HIDWORD(v85) = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 304LL)
                                 + *(unsigned __int16 *)(ipa3_ctx + 29522);
                    LODWORD(v86) = -1;
                    v35 = (_WORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                                     7,
                                     &v85,
                                     0);
                    if ( v35 )
                    {
                      v36 = &s[13 * v26];
                      v37 = v35;
                      *((_WORD *)v36 + 18) = v35[1];
                      v36[1] = v35 + 2;
                      v38 = *v35;
                      *(_DWORD *)v36 = 3;
                      *(_WORD *)((char *)&v90 + 1) = 0;
                      HIDWORD(v90) = 2;
                      *((_WORD *)v36 + 17) = v38;
                      LODWORD(v89) = *v10;
                      v88 = v80;
                      HIDWORD(v89) = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 304LL)
                                   + *(unsigned __int16 *)(ipa3_ctx + 29522);
                      v39 = (_WORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                                       11,
                                       &v88,
                                       0);
                      if ( v39 )
                      {
                        v40 = &s[13 * v26 + 13];
                        v41 = v39;
                        *((_WORD *)v40 + 18) = v39[1];
                        v40[1] = v39 + 2;
                        v42 = *v39;
                        *(_DWORD *)v40 = 3;
                        *((_WORD *)v40 + 17) = v42;
                        v43 = ((__int64 (__fastcall *)(_QWORD, _QWORD *))ipa3_send_cmd)(v26 + 2, s);
                        if ( v43 )
                        {
                          printk(&unk_3B18DA, "ipa_init_quota_stats");
                          v64 = ipa3_ctx;
                          if ( ipa3_ctx )
                          {
                            v65 = *(_QWORD *)(ipa3_ctx + 34152);
                            if ( v65 )
                            {
                              ipc_log_string(
                                v65,
                                "ipa %s:%d failed to send immediate command (error %d)\n",
                                "ipa_init_quota_stats",
                                657,
                                v43);
                              v64 = ipa3_ctx;
                            }
                            v66 = *(_QWORD *)(v64 + 34160);
                            if ( v66 )
                              ipc_log_string(
                                v66,
                                "ipa %s:%d failed to send immediate command (error %d)\n",
                                "ipa_init_quota_stats",
                                657,
                                v43);
                          }
                        }
                        kfree(v41);
                      }
                      else
                      {
                        printk(&unk_3A8EB0, "ipa_init_quota_stats");
                        v61 = ipa3_ctx;
                        if ( !ipa3_ctx )
                          goto LABEL_76;
                        v62 = *(_QWORD *)(ipa3_ctx + 34152);
                        if ( v62 )
                        {
                          ipc_log_string(
                            v62,
                            "ipa %s:%d failed to construct dma_shared_mem imm cmd\n",
                            "ipa_init_quota_stats",
                            645);
                          v61 = ipa3_ctx;
                        }
                        v63 = *(_QWORD *)(v61 + 34160);
                        if ( v63 )
                        {
                          ipc_log_string(
                            v63,
                            "ipa %s:%d failed to construct dma_shared_mem imm cmd\n",
                            "ipa_init_quota_stats",
                            645);
                          v43 = -12;
                        }
                        else
                        {
LABEL_76:
                          v43 = -12;
                        }
                      }
                      kfree(v37);
                    }
                    else
                    {
                      printk(&unk_3E98FD, "ipa_init_quota_stats");
                      v58 = ipa3_ctx;
                      if ( !ipa3_ctx )
                        goto LABEL_75;
                      v59 = *(_QWORD *)(ipa3_ctx + 34152);
                      if ( v59 )
                      {
                        ipc_log_string(
                          v59,
                          "ipa %s:%d failed to construct register_write imm cmd\n",
                          "ipa_init_quota_stats",
                          625);
                        v58 = ipa3_ctx;
                      }
                      v60 = *(_QWORD *)(v58 + 34160);
                      if ( v60 )
                      {
                        ipc_log_string(
                          v60,
                          "ipa %s:%d failed to construct register_write imm cmd\n",
                          "ipa_init_quota_stats",
                          625);
                        v43 = -12;
                      }
                      else
                      {
LABEL_75:
                        v43 = -12;
                      }
                    }
                    kfree(v24);
                    if ( v25 )
                    {
                      kfree(v25);
                      v44 = v81;
                    }
                    else
                    {
                      v44 = v79;
                    }
                    goto LABEL_83;
                  }
                  printk(&unk_3E98FD, "ipa_init_quota_stats");
                  v67 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v68 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v68 )
                    {
                      ipc_log_string(
                        v68,
                        "ipa %s:%d failed to construct register_write imm cmd\n",
                        "ipa_init_quota_stats",
                        576);
                      v67 = ipa3_ctx;
                    }
                    v69 = *(_QWORD *)(v67 + 34160);
                    if ( v69 )
                      ipc_log_string(
                        v69,
                        "ipa %s:%d failed to construct register_write imm cmd\n",
                        "ipa_init_quota_stats",
                        576);
                  }
                }
                v44 = v79;
                v43 = -12;
LABEL_83:
                kfree(v44);
LABEL_84:
                dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), v80, *v10, 1, 0);
                goto LABEL_85;
              }
            }
          }
          else if ( (v15 & 1) == 0 )
          {
            goto LABEL_16;
          }
          printk(&unk_3B50B5, "ipa_init_quota_stats");
          v76 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v77 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v77 )
            {
              ipc_log_string(v77, "ipa %s:%d failed to DMA map\n", "ipa_init_quota_stats", 546);
              v76 = ipa3_ctx;
            }
            v78 = *(_QWORD *)(v76 + 34160);
            if ( v78 )
              ipc_log_string(v78, "ipa %s:%d failed to DMA map\n", "ipa_init_quota_stats", 546);
          }
LABEL_101:
          v43 = -1;
          goto LABEL_85;
        }
        printk(&unk_3B827C, "ipa_validate_quota_stats_sram_size");
        v52 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_101;
        v53 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v53 )
        {
          ipc_log_string(
            v53,
            "ipa %s:%d SRAM partition too small: %u needed %u\n",
            "ipa_validate_quota_stats_sram_size",
            491,
            v12,
            v11);
          v52 = ipa3_ctx;
        }
        v54 = *(_QWORD *)(v52 + 34160);
        if ( !v54 )
          goto LABEL_101;
        ipc_log_string(
          v54,
          "ipa %s:%d SRAM partition too small: %u needed %u\n",
          "ipa_validate_quota_stats_sram_size",
          491,
          v12,
          v11);
        v43 = -1;
      }
LABEL_85:
      kfree(v10);
      result = v43;
      goto LABEL_86;
    }
    printk(&unk_3C0EC2, "ipa_init_quota_stats");
    v45 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_42;
    v46 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v46 )
    {
      ipc_log_string(v46, "ipa %s:%d failed to generate pyld\n", "ipa_init_quota_stats", 532);
      v45 = ipa3_ctx;
    }
    v47 = *(_QWORD *)(v45 + 34160);
    if ( v47 )
    {
      ipc_log_string(v47, "ipa %s:%d failed to generate pyld\n", "ipa_init_quota_stats", 532);
      result = 0xFFFFFFFFLL;
    }
    else
    {
LABEL_42:
      result = 0xFFFFFFFFLL;
    }
  }
  else
  {
    result = 0;
  }
LABEL_86:
  _ReadStatusReg(SP_EL0);
  return result;
}
