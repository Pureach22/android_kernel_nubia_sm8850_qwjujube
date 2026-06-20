__int64 __fastcall ipa_init_drop_stats(int *a1)
{
  _BYTE *v1; // x19
  __int64 result; // x0
  __int64 v4; // x19
  int v5; // w5
  __int64 v6; // x8
  __int64 v7; // x0
  int v8; // w5
  _DWORD *v9; // x25
  __int64 v10; // x0
  unsigned __int16 *init_pyld; // x0
  __int64 v12; // x22
  unsigned __int16 *v13; // x20
  const char **v14; // x22
  __int64 v15; // x21
  char v16; // w0
  int ep_mapping; // w0
  __int64 v18; // x8
  __int64 v19; // x21
  unsigned int v20; // w26
  unsigned int v21; // w0
  __int16 *v22; // x0
  __int64 v23; // x8
  __int16 *v24; // x23
  _WORD *v25; // x24
  unsigned int v26; // w25
  __int16 v27; // w9
  unsigned int reg_nk_offset; // w0
  __int64 v29; // x8
  __int64 v30; // x10
  __int16 v31; // w9
  _WORD *v32; // x0
  __int64 v33; // x8
  __int16 v34; // w9
  __int64 v35; // x2
  _WORD *v36; // x0
  __int64 v37; // x8
  _WORD *v38; // x26
  __int16 v39; // w9
  _WORD *v40; // x0
  __int64 v41; // x8
  _WORD *v42; // x27
  __int16 v43; // w9
  unsigned int v44; // w25
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x8
  __int64 v49; // x0
  unsigned int v50; // w4
  __int64 v51; // x8
  __int64 v52; // x0
  unsigned int v53; // w4
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
  char v72; // w26
  const char *v73; // x0
  const char *v74; // x2
  __int64 v75; // x8
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x8
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // [xsp+10h] [xbp-4A0h]
  __int64 v82; // [xsp+18h] [xbp-498h] BYREF
  unsigned __int64 v83; // [xsp+20h] [xbp-490h] BYREF
  __int64 v84; // [xsp+28h] [xbp-488h]
  int v85; // [xsp+30h] [xbp-480h]
  __int64 v86; // [xsp+38h] [xbp-478h] BYREF
  __int64 v87; // [xsp+40h] [xbp-470h]
  int v88; // [xsp+48h] [xbp-468h]
  __int64 v89; // [xsp+50h] [xbp-460h] BYREF
  __int64 v90; // [xsp+58h] [xbp-458h]
  __int64 v91; // [xsp+60h] [xbp-450h]
  _DWORD s[270]; // [xsp+68h] [xbp-448h] BYREF
  __int64 v93; // [xsp+4A0h] [xbp-10h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v90 = 0;
  v91 = 0;
  v89 = 0;
  v1 = *(_BYTE **)(ipa3_ctx + 43800);
  v88 = 0;
  v86 = 0;
  v87 = 0;
  v85 = 0;
  v83 = 0;
  v84 = 0;
  v82 = 0;
  if ( v1 )
  {
    memset(s, 0, sizeof(s));
    result = 0;
    if ( *v1 == 1 )
    {
      if ( a1 )
      {
        v4 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 520);
        if ( v4 )
        {
          memset(&s[1], 0, 0x434u);
          v5 = *a1;
          v6 = ipa3_ctx;
          s[0] = *a1;
          if ( !ipa3_ctx )
          {
            v9 = a1 + 1;
            s[1] = a1[1];
            goto LABEL_15;
          }
          v7 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( v7 )
          {
            ipc_log_string(v7, "ipa %s:%d pipe_bitmask[%d]=0x%x\n", "ipa_init_drop_stats", 1977, 0, v5);
            v6 = ipa3_ctx;
            v9 = a1 + 1;
            v8 = a1[1];
            s[1] = v8;
            if ( !ipa3_ctx )
              goto LABEL_15;
          }
          else
          {
            v9 = a1 + 1;
            v8 = a1[1];
            s[1] = v8;
          }
          v10 = *(_QWORD *)(v6 + 34160);
          if ( v10 )
            ipc_log_string(v10, "ipa %s:%d pipe_bitmask[%d]=0x%x\n", "ipa_init_drop_stats", 1977, 1, v8);
LABEL_15:
          init_pyld = (unsigned __int16 *)ipahal_stats_generate_init_pyld(3, s, 0);
          if ( !init_pyld )
          {
            printk(&unk_3C0EC2, "ipa_init_drop_stats");
            v45 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_77;
            v46 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v46 )
            {
              ipc_log_string(v46, "ipa %s:%d failed to generate pyld\n", "ipa_init_drop_stats", 1983);
              v45 = ipa3_ctx;
            }
            v47 = *(_QWORD *)(v45 + 34160);
            if ( v47 )
            {
              ipc_log_string(v47, "ipa %s:%d failed to generate pyld\n", "ipa_init_drop_stats", 1983);
              v44 = -1;
            }
            else
            {
LABEL_77:
              v44 = -1;
            }
            goto LABEL_43;
          }
          v12 = ipa3_ctx;
          v13 = init_pyld;
          if ( *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 372LL) < (unsigned int)*init_pyld )
          {
            printk(&unk_3ACD78, "ipa_init_drop_stats");
            v48 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v49 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v49 )
              {
                v50 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 372LL);
                ipc_log_string(
                  v49,
                  "ipa %s:%d SRAM partition too small: %d bytes (%d pipes).Tried to add %d bytes (%d pipes).Please disabl"
                  "e some stats before adding new ones.\n",
                  "ipa_init_drop_stats",
                  1993,
                  v50,
                  v50 >> 3,
                  *v13,
                  *v13 >> 3);
                v48 = ipa3_ctx;
              }
              v51 = v48 + 0x8000;
              v52 = *(_QWORD *)(v51 + 1392);
              if ( v52 )
              {
                v53 = *(_DWORD *)(**(_QWORD **)(v51 + 1408) + 372LL);
                ipc_log_string(
                  v52,
                  "ipa %s:%d SRAM partition too small: %d bytes (%d pipes).Tried to add %d bytes (%d pipes).Please disabl"
                  "e some stats before adding new ones.\n",
                  "ipa_init_drop_stats",
                  1993,
                  v53,
                  v53 >> 3,
                  *v13,
                  *v13 >> 3);
                v44 = -1;
                goto LABEL_42;
              }
            }
LABEL_100:
            v44 = -1;
            goto LABEL_42;
          }
          memset((void *)(*(_QWORD *)(ipa3_ctx + 43800) + 63896LL), 0, 0x438u);
          memcpy((void *)(*(_QWORD *)(v12 + 43800) + 63896LL), s, 0x438u);
          v14 = *(const char ***)(v12 + 34216);
          v15 = *v13;
          v16 = is_vmalloc_addr(v13 + 2);
          if ( (v16 & 1) != 0 && (dma_map_single_attrs___already_done_0 & 1) == 0 )
          {
            v72 = v16;
            dma_map_single_attrs___already_done_0 = 1;
            v73 = (const char *)dev_driver_string(v14);
            v74 = v14[14];
            if ( !v74 )
              v74 = *v14;
            _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v73, v74);
            __break(0x800u);
            if ( (v72 & 1) == 0 )
            {
LABEL_20:
              v81 = dma_map_page_attrs(
                      v14,
                      ((unsigned __int64)(((__int64)((_QWORD)(v13 + 2) << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
                    - 0x140000000LL,
                      (unsigned __int64)(v13 + 2) & 0xFFF,
                      v15,
                      1,
                      0);
              if ( v81 != -1 )
              {
                ep_mapping = ipa_get_ep_mapping(95);
                v18 = ipa3_ctx;
                if ( ep_mapping == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
                {
                  v19 = 0;
                  v20 = 0;
                }
                else
                {
                  ipa_close_coal_frame(&v82);
                  v19 = v82;
                  if ( !v82 )
                  {
                    printk(&unk_3AEDE8, "ipa_init_drop_stats");
                    v69 = ipa3_ctx;
                    if ( !ipa3_ctx )
                      goto LABEL_91;
                    v70 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v70 )
                    {
                      ipc_log_string(v70, "ipa %s:%d failed to construct coal close IC\n", "ipa_init_drop_stats", 2017);
                      v69 = ipa3_ctx;
                    }
                    v71 = *(_QWORD *)(v69 + 34160);
                    if ( v71 )
                    {
                      ipc_log_string(v71, "ipa %s:%d failed to construct coal close IC\n", "ipa_init_drop_stats", 2017);
                      v44 = -12;
                    }
                    else
                    {
LABEL_91:
                      v44 = -12;
                    }
                    goto LABEL_41;
                  }
                  ipa3_init_imm_cmd_desc(v4, v82);
                  v18 = ipa3_ctx;
                  v20 = 1;
                }
                BYTE4(v84) = 0;
                v85 = 2;
                LODWORD(v84) = -1;
                if ( *(_DWORD *)(v18 + 32240) >= 0x15u )
                {
                  reg_nk_offset = ipahal_get_reg_nk_offset(139, *(unsigned int *)(v18 + 43304), 0);
                  v83 = __PAIR64__(*a1, reg_nk_offset);
                  v24 = (__int16 *)((__int64 (__fastcall *)(__int64, unsigned __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                                     7,
                                     &v83,
                                     0);
                  if ( v24 )
                  {
                    v29 = v4 + 104LL * v20;
                    *(_WORD *)(v29 + 36) = v24[1];
                    *(_QWORD *)(v29 + 8) = v24 + 2;
                    v30 = ipa3_ctx;
                    v31 = *v24;
                    *(_DWORD *)v29 = 3;
                    *(_WORD *)(v29 + 34) = v31;
                    LODWORD(v83) = ipahal_get_reg_nk_offset(139, *(unsigned int *)(v30 + 43304), 1);
                    HIDWORD(v83) = *v9;
                    v32 = (_WORD *)((__int64 (__fastcall *)(__int64, unsigned __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                                     7,
                                     &v83,
                                     0);
                    if ( v32 )
                    {
                      v33 = v4 + 104LL * v20;
                      v25 = v32;
                      v26 = v20 | 2;
                      *(_WORD *)(v33 + 140) = v32[1];
                      *(_QWORD *)(v33 + 112) = v32 + 2;
                      v34 = *v32;
                      *(_DWORD *)(v33 + 104) = 3;
                      *(_WORD *)(v33 + 138) = v34;
                      goto LABEL_32;
                    }
                  }
                  printk(&unk_3E98FD, "ipa_init_drop_stats");
                  v54 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v55 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v55 )
                    {
                      ipc_log_string(
                        v55,
                        "ipa %s:%d failed to construct register_write imm cmd\n",
                        "ipa_init_drop_stats",
                        2061);
                      v54 = ipa3_ctx;
                    }
                    v56 = *(_QWORD *)(v54 + 34160);
                    if ( v56 )
                      ipc_log_string(
                        v56,
                        "ipa %s:%d failed to construct register_write imm cmd\n",
                        "ipa_init_drop_stats",
                        2061);
                  }
                  if ( v24 )
                  {
                    kfree(v24);
                    v44 = -12;
                    goto LABEL_39;
                  }
                }
                else
                {
                  v21 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(
                          120,
                          0,
                          *(unsigned int *)(v18 + 43304));
                  v83 = __PAIR64__(*a1, v21);
                  v22 = (__int16 *)((__int64 (__fastcall *)(__int64, unsigned __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                                     7,
                                     &v83,
                                     0);
                  if ( v22 )
                  {
                    v23 = v4 + 104LL * v20;
                    v24 = v22;
                    v25 = nullptr;
                    v26 = v20 + 1;
                    *(_WORD *)(v23 + 36) = v22[1];
                    *(_QWORD *)(v23 + 8) = v22 + 2;
                    v27 = *v22;
                    *(_DWORD *)v23 = 3;
                    *(_WORD *)(v23 + 34) = v27;
LABEL_32:
                    BYTE4(v87) = 0;
                    v35 = *(unsigned int *)(ipa3_ctx + 43304);
                    v88 = 2;
                    LODWORD(v86) = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))ipahal_get_reg_mn_ofst)(
                                     119,
                                     0,
                                     v35);
                    HIDWORD(v86) = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 368LL)
                                 + *(unsigned __int16 *)(ipa3_ctx + 29522);
                    LODWORD(v87) = -1;
                    v36 = (_WORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                                     7,
                                     &v86,
                                     0);
                    if ( v36 )
                    {
                      v37 = v4 + 104LL * v26;
                      v38 = v36;
                      *(_WORD *)(v37 + 36) = v36[1];
                      *(_QWORD *)(v37 + 8) = v36 + 2;
                      v39 = *v36;
                      *(_DWORD *)v37 = 3;
                      *(_WORD *)((char *)&v91 + 1) = 0;
                      HIDWORD(v91) = 2;
                      *(_WORD *)(v37 + 34) = v39;
                      LODWORD(v90) = *v13;
                      v89 = v81;
                      HIDWORD(v90) = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 368LL)
                                   + *(unsigned __int16 *)(ipa3_ctx + 29522);
                      v40 = (_WORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                                       11,
                                       &v89,
                                       0);
                      if ( v40 )
                      {
                        v41 = v4 + 104LL * (v26 + 1);
                        v42 = v40;
                        *(_WORD *)(v41 + 36) = v40[1];
                        *(_QWORD *)(v41 + 8) = v40 + 2;
                        v43 = *v40;
                        *(_DWORD *)v41 = 3;
                        *(_WORD *)(v41 + 34) = v43;
                        v44 = ((__int64 (__fastcall *)(_QWORD, __int64))ipa3_send_cmd)(v26 + 2, v4);
                        if ( v44 )
                        {
                          printk(&unk_3B18DA, "ipa_init_drop_stats");
                          v63 = ipa3_ctx;
                          if ( ipa3_ctx )
                          {
                            v64 = *(_QWORD *)(ipa3_ctx + 34152);
                            if ( v64 )
                            {
                              ipc_log_string(
                                v64,
                                "ipa %s:%d failed to send immediate command (error %d)\n",
                                "ipa_init_drop_stats",
                                2118,
                                v44);
                              v63 = ipa3_ctx;
                            }
                            v65 = *(_QWORD *)(v63 + 34160);
                            if ( v65 )
                              ipc_log_string(
                                v65,
                                "ipa %s:%d failed to send immediate command (error %d)\n",
                                "ipa_init_drop_stats",
                                2118,
                                v44);
                          }
                        }
                        kfree(v42);
                      }
                      else
                      {
                        printk(&unk_3A8EB0, "ipa_init_drop_stats");
                        v60 = ipa3_ctx;
                        if ( !ipa3_ctx )
                          goto LABEL_79;
                        v61 = *(_QWORD *)(ipa3_ctx + 34152);
                        if ( v61 )
                        {
                          ipc_log_string(
                            v61,
                            "ipa %s:%d failed to construct dma_shared_mem imm cmd\n",
                            "ipa_init_drop_stats",
                            2106);
                          v60 = ipa3_ctx;
                        }
                        v62 = *(_QWORD *)(v60 + 34160);
                        if ( v62 )
                        {
                          ipc_log_string(
                            v62,
                            "ipa %s:%d failed to construct dma_shared_mem imm cmd\n",
                            "ipa_init_drop_stats",
                            2106);
                          v44 = -12;
                        }
                        else
                        {
LABEL_79:
                          v44 = -12;
                        }
                      }
                      kfree(v38);
                    }
                    else
                    {
                      printk(&unk_3E98FD, "ipa_init_drop_stats");
                      v57 = ipa3_ctx;
                      if ( !ipa3_ctx )
                        goto LABEL_78;
                      v58 = *(_QWORD *)(ipa3_ctx + 34152);
                      if ( v58 )
                      {
                        ipc_log_string(
                          v58,
                          "ipa %s:%d failed to construct register_write imm cmd\n",
                          "ipa_init_drop_stats",
                          2086);
                        v57 = ipa3_ctx;
                      }
                      v59 = *(_QWORD *)(v57 + 34160);
                      if ( v59 )
                      {
                        ipc_log_string(
                          v59,
                          "ipa %s:%d failed to construct register_write imm cmd\n",
                          "ipa_init_drop_stats",
                          2086);
                        v44 = -12;
                      }
                      else
                      {
LABEL_78:
                        v44 = -12;
                      }
                    }
                    kfree(v24);
                    if ( v25 )
                    {
                      kfree(v25);
                      v19 = v82;
                    }
                    goto LABEL_39;
                  }
                  printk(&unk_3E98FD, "ipa_init_drop_stats");
                  v66 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v67 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v67 )
                    {
                      ipc_log_string(
                        v67,
                        "ipa %s:%d failed to construct register_write imm cmd\n",
                        "ipa_init_drop_stats",
                        2038);
                      v66 = ipa3_ctx;
                    }
                    v68 = *(_QWORD *)(v66 + 34160);
                    if ( v68 )
                    {
                      ipc_log_string(
                        v68,
                        "ipa %s:%d failed to construct register_write imm cmd\n",
                        "ipa_init_drop_stats",
                        2038);
                      v44 = -12;
                      goto LABEL_39;
                    }
                  }
                }
                v44 = -12;
LABEL_39:
                if ( v19 )
                  kfree(v19);
LABEL_41:
                dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), v81, *v13, 1, 0);
LABEL_42:
                kfree(v13);
LABEL_43:
                kfree(v4);
                result = v44;
                goto LABEL_44;
              }
            }
          }
          else if ( (v16 & 1) == 0 )
          {
            goto LABEL_20;
          }
          printk(&unk_3B50B5, "ipa_init_drop_stats");
          v75 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v76 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v76 )
            {
              ipc_log_string(v76, "ipa %s:%d failed to DMA map\n", "ipa_init_drop_stats", 2007);
              v75 = ipa3_ctx;
            }
            v77 = *(_QWORD *)(v75 + 34160);
            if ( v77 )
              ipc_log_string(v77, "ipa %s:%d failed to DMA map\n", "ipa_init_drop_stats", 2007);
          }
          goto LABEL_100;
        }
        printk(&unk_3CFD12, "ipa_init_drop_stats");
        v78 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v79 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v79 )
          {
            ipc_log_string(v79, "ipa %s:%d failed to allocate memory\n", "ipa_init_drop_stats", 1969);
            v78 = ipa3_ctx;
          }
          v80 = *(_QWORD *)(v78 + 34160);
          if ( v80 )
            ipc_log_string(v80, "ipa %s:%d failed to allocate memory\n", "ipa_init_drop_stats", 1969);
        }
        result = 4294967284LL;
      }
      else
      {
        result = 0xFFFFFFFFLL;
      }
    }
  }
  else
  {
    result = 0;
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
