__int64 __fastcall ipa_init_teth_stats(_DWORD *a1)
{
  _BYTE *v2; // x8
  __int64 v3; // x19
  unsigned int v4; // w20
  _DWORD *v5; // x21
  int v7; // w22
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 result; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x20
  __int64 v16; // x8
  __int64 v17; // x20
  unsigned __int16 *init_pyld; // x0
  __int64 v19; // x20
  unsigned __int16 *v20; // x19
  unsigned __int16 *v21; // x22
  const char **v22; // x21
  char v23; // w0
  int ep_mapping; // w0
  __int64 v25; // x8
  unsigned int v26; // w24
  unsigned int reg_nk_offset; // w0
  __int16 *v28; // x22
  _QWORD *v29; // x8
  __int64 v30; // x10
  __int16 v31; // w9
  unsigned int v32; // w0
  _WORD *v33; // x0
  _QWORD *v34; // x8
  _WORD *v35; // x23
  unsigned int v36; // w24
  __int16 v37; // w9
  unsigned int v38; // w0
  __int16 *v39; // x0
  _QWORD *v40; // x8
  __int16 v41; // w9
  __int64 v42; // x2
  _WORD *v43; // x0
  _QWORD *v44; // x8
  _WORD *v45; // x25
  __int16 v46; // w9
  _WORD *v47; // x0
  _QWORD *v48; // x8
  _WORD *v49; // x26
  __int16 v50; // w9
  unsigned int v51; // w24
  __int64 v52; // x0
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x8
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x8
  __int64 v60; // x0
  __int64 v61; // x8
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
  __int64 v75; // x8
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x8
  __int64 v79; // x0
  __int64 v80; // x0
  char v81; // w24
  const char *v82; // x0
  const char *v83; // x2
  __int64 v84; // x8
  __int64 v85; // x0
  __int64 v86; // x0
  __int64 v87; // [xsp+8h] [xbp-278h]
  __int64 v88; // [xsp+10h] [xbp-270h]
  __int64 v89; // [xsp+18h] [xbp-268h] BYREF
  unsigned __int64 v90; // [xsp+20h] [xbp-260h] BYREF
  __int64 v91; // [xsp+28h] [xbp-258h]
  int v92; // [xsp+30h] [xbp-250h]
  __int64 v93; // [xsp+38h] [xbp-248h] BYREF
  __int64 v94; // [xsp+40h] [xbp-240h]
  int v95; // [xsp+48h] [xbp-238h]
  __int64 v96; // [xsp+50h] [xbp-230h] BYREF
  __int64 v97; // [xsp+58h] [xbp-228h]
  __int64 v98; // [xsp+60h] [xbp-220h]
  _QWORD s[67]; // [xsp+68h] [xbp-218h] BYREF

  s[65] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v97 = 0;
  v98 = 0;
  v96 = 0;
  v95 = 0;
  v93 = 0;
  v94 = 0;
  v92 = 0;
  v90 = 0;
  v91 = 0;
  v89 = 0;
  memset(s, 0, 0x208u);
  v2 = *(_BYTE **)(ipa3_ctx + 43800);
  if ( v2 && *v2 == 1 )
  {
    if ( a1 && (*a1 || a1[1]) )
    {
      v3 = 0;
      v4 = 0;
      v5 = a1 + 3;
      do
      {
        if ( (v3 & 0x1F) == 0 && v3 != 0 )
          ++v4;
        if ( v4 > 1 )
          __break(0x5512u);
        v7 = a1[v4];
        if ( ((unsigned int)ipahal_get_ep_bit((unsigned int)v3) & v7) != 0 && !*(_QWORD *)(v5 - 1) )
        {
          printk(&unk_3E66D2, "ipa_init_teth_stats");
          v8 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v9 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v9 )
            {
              ipc_log_string(v9, "ipa %s:%d prod %d doesn't have cons\n", "ipa_init_teth_stats", 904, v3);
              v8 = ipa3_ctx;
            }
            v10 = *(_QWORD *)(v8 + 34160);
            if ( v10 )
            {
              ipc_log_string(v10, "ipa %s:%d prod %d doesn't have cons\n", "ipa_init_teth_stats", 904, v3);
              result = 4294967274LL;
              goto LABEL_107;
            }
          }
          goto LABEL_62;
        }
        ++v3;
        v5 += 2;
      }
      while ( v3 != 36 );
      v12 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v13 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v13 )
        {
          ipc_log_string(v13, "ipa %s:%d prod_mask=[0x%x][0x%x]\n", "ipa_init_teth_stats", 911, *a1, a1[1]);
          v12 = ipa3_ctx;
        }
        v14 = *(_QWORD *)(v12 + 34160);
        if ( v14 )
        {
          ipc_log_string(v14, "ipa %s:%d prod_mask=[0x%x][0x%x]\n", "ipa_init_teth_stats", 911, *a1, a1[1]);
          v12 = ipa3_ctx;
        }
      }
      memset((void *)(*(_QWORD *)(v12 + 43800) + 880LL), 0, 0x128u);
      v15 = -31104;
      do
      {
        memset((void *)(*(_QWORD *)(ipa3_ctx + 43800) + v15 + 32280), 0, 0x360u);
        memset((void *)(*(_QWORD *)(ipa3_ctx + 43800) + v15 + 63384), 0, 0x360u);
        v15 += 864;
      }
      while ( v15 );
      v16 = ipa3_ctx;
      *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43800) + 880LL) = *a1;
      *(_DWORD *)(*(_QWORD *)(v16 + 43800) + 884LL) = a1[1];
      v17 = ipa3_ctx;
      memcpy((void *)(*(_QWORD *)(ipa3_ctx + 43800) + 888LL), a1 + 2, 0x120u);
      init_pyld = (unsigned __int16 *)ipahal_stats_generate_init_pyld(1, *(_QWORD *)(v17 + 43800) + 880LL, 0);
      if ( init_pyld )
      {
        v19 = *init_pyld;
        v20 = init_pyld;
        if ( *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 316LL) < (unsigned int)v19 )
        {
          printk(&unk_3D2C66, "ipa_init_teth_stats");
          v59 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_122;
          v60 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v60 )
          {
            ipc_log_string(
              v60,
              "ipa %s:%d SRAM partition too small: %d needed %d\n",
              "ipa_init_teth_stats",
              938,
              *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 316LL),
              *v20);
            v59 = ipa3_ctx;
          }
          v61 = v59 + 0x8000;
          v62 = *(_QWORD *)(v61 + 1392);
          if ( !v62 )
            goto LABEL_122;
          ipc_log_string(
            v62,
            "ipa %s:%d SRAM partition too small: %d needed %d\n",
            "ipa_init_teth_stats",
            938,
            *(_DWORD *)(**(_QWORD **)(v61 + 1408) + 316LL),
            *v20);
          v51 = -1;
LABEL_106:
          kfree(v20);
          result = v51;
          goto LABEL_107;
        }
        v21 = init_pyld + 2;
        v22 = *(const char ***)(ipa3_ctx + 34216);
        v23 = is_vmalloc_addr(init_pyld + 2);
        if ( (v23 & 1) == 0 || (dma_map_single_attrs___already_done_0 & 1) != 0 )
        {
          if ( (v23 & 1) == 0 )
            goto LABEL_34;
LABEL_117:
          printk(&unk_3B50B5, "ipa_init_teth_stats");
          v84 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v85 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v85 )
            {
              ipc_log_string(v85, "ipa %s:%d failed to DMA map\n", "ipa_init_teth_stats", 948);
              v84 = ipa3_ctx;
            }
            v86 = *(_QWORD *)(v84 + 34160);
            if ( v86 )
              ipc_log_string(v86, "ipa %s:%d failed to DMA map\n", "ipa_init_teth_stats", 948);
          }
LABEL_122:
          v51 = -1;
          goto LABEL_106;
        }
        v81 = v23;
        dma_map_single_attrs___already_done_0 = 1;
        v82 = (const char *)dev_driver_string(v22);
        v83 = v22[14];
        if ( !v83 )
          v83 = *v22;
        _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v82, v83);
        __break(0x800u);
        if ( (v81 & 1) != 0 )
          goto LABEL_117;
LABEL_34:
        v88 = dma_map_page_attrs(
                v22,
                ((unsigned __int64)(((__int64)((_QWORD)v21 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                (unsigned __int16)v21 & 0xFFF,
                v19,
                1,
                0);
        if ( v88 == -1 )
          goto LABEL_117;
        ep_mapping = ipa_get_ep_mapping(95);
        v25 = ipa3_ctx;
        if ( ep_mapping == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
        {
          v87 = 0;
          v26 = 0;
          goto LABEL_40;
        }
        ipa_close_coal_frame(&v89);
        if ( !v89 )
        {
          printk(&unk_3AEDE8, "ipa_init_teth_stats");
          v78 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_113;
          v79 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v79 )
          {
            ipc_log_string(v79, "ipa %s:%d failed to construct coal close IC\n", "ipa_init_teth_stats", 958);
            v78 = ipa3_ctx;
          }
          v80 = *(_QWORD *)(v78 + 34160);
          if ( v80 )
          {
            ipc_log_string(v80, "ipa %s:%d failed to construct coal close IC\n", "ipa_init_teth_stats", 958);
            v51 = -12;
          }
          else
          {
LABEL_113:
            v51 = -12;
          }
          goto LABEL_105;
        }
        v87 = v89;
        ipa3_init_imm_cmd_desc(s, v89);
        v25 = ipa3_ctx;
        v26 = 1;
LABEL_40:
        BYTE4(v91) = 0;
        v92 = 2;
        LODWORD(v91) = -1;
        if ( *(_DWORD *)(v25 + 32240) >= 0x15u )
        {
          reg_nk_offset = ipahal_get_reg_nk_offset(138, *(unsigned int *)(v25 + 43304), 0);
          v90 = __PAIR64__(*a1, reg_nk_offset);
          v28 = (__int16 *)((__int64 (__fastcall *)(__int64, unsigned __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                             7,
                             &v90,
                             0);
          if ( v28 )
          {
            v29 = &s[13 * v26];
            *((_WORD *)v29 + 18) = v28[1];
            v29[1] = v28 + 2;
            v30 = ipa3_ctx;
            v31 = *v28;
            *(_DWORD *)v29 = 3;
            *((_WORD *)v29 + 17) = v31;
            v32 = ipahal_get_reg_nk_offset(138, *(unsigned int *)(v30 + 43304), 1);
            v90 = __PAIR64__(a1[1], v32);
            v33 = (_WORD *)((__int64 (__fastcall *)(__int64, unsigned __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                             7,
                             &v90,
                             0);
            if ( v33 )
            {
              v34 = &s[13 * v26];
              v35 = v33;
              v36 = v26 | 2;
              *((_WORD *)v34 + 70) = v33[1];
              v34[14] = v33 + 2;
              v37 = *v33;
              *((_DWORD *)v34 + 26) = 3;
              *((_WORD *)v34 + 69) = v37;
              goto LABEL_47;
            }
          }
          printk(&unk_3E98FD, "ipa_init_teth_stats");
          v63 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v64 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v64 )
            {
              ipc_log_string(v64, "ipa %s:%d failed to construct register_write imm cmd\n", "ipa_init_teth_stats", 981);
              v63 = ipa3_ctx;
            }
            v65 = *(_QWORD *)(v63 + 34160);
            if ( v65 )
              ipc_log_string(v65, "ipa %s:%d failed to construct register_write imm cmd\n", "ipa_init_teth_stats", 981);
          }
          if ( v28 )
            kfree(v28);
        }
        else
        {
          v38 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(
                  106,
                  0,
                  *(unsigned int *)(v25 + 43304));
          v90 = __PAIR64__(*a1, v38);
          v39 = (__int16 *)((__int64 (__fastcall *)(__int64, unsigned __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                             7,
                             &v90,
                             0);
          if ( v39 )
          {
            v40 = &s[13 * v26];
            v28 = v39;
            v35 = nullptr;
            v36 = v26 + 1;
            *((_WORD *)v40 + 18) = v39[1];
            v40[1] = v39 + 2;
            v41 = *v39;
            *(_DWORD *)v40 = 3;
            *((_WORD *)v40 + 17) = v41;
LABEL_47:
            BYTE4(v94) = 0;
            v42 = *(unsigned int *)(ipa3_ctx + 43304);
            v95 = 2;
            LODWORD(v93) = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))ipahal_get_reg_mn_ofst)(105, 0, v42);
            HIDWORD(v93) = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 312LL)
                         + *(unsigned __int16 *)(ipa3_ctx + 29522);
            LODWORD(v94) = -1;
            v43 = (_WORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(7, &v93, 0);
            if ( v43 )
            {
              v44 = &s[13 * v36];
              v45 = v43;
              *((_WORD *)v44 + 18) = v43[1];
              v44[1] = v43 + 2;
              v46 = *v43;
              *(_DWORD *)v44 = 3;
              *(_WORD *)((char *)&v98 + 1) = 0;
              HIDWORD(v98) = 2;
              *((_WORD *)v44 + 17) = v46;
              LODWORD(v97) = *v20;
              v96 = v88;
              HIDWORD(v97) = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 312LL)
                           + *(unsigned __int16 *)(ipa3_ctx + 29522);
              v47 = (_WORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v96, 0);
              if ( v47 )
              {
                v48 = &s[13 * v36 + 13];
                v49 = v47;
                *((_WORD *)v48 + 18) = v47[1];
                v48[1] = v47 + 2;
                v50 = *v47;
                *(_DWORD *)v48 = 3;
                *((_WORD *)v48 + 17) = v50;
                v51 = ((__int64 (__fastcall *)(_QWORD, _QWORD *))ipa3_send_cmd)(v36 + 2, s);
                if ( v51 )
                {
                  printk(&unk_3B18DA, "ipa_init_teth_stats");
                  v72 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v73 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v73 )
                    {
                      ipc_log_string(
                        v73,
                        "ipa %s:%d failed to send immediate command (error %d)\n",
                        "ipa_init_teth_stats",
                        1059,
                        v51);
                      v72 = ipa3_ctx;
                    }
                    v74 = *(_QWORD *)(v72 + 34160);
                    if ( v74 )
                      ipc_log_string(
                        v74,
                        "ipa %s:%d failed to send immediate command (error %d)\n",
                        "ipa_init_teth_stats",
                        1059,
                        v51);
                  }
                }
                kfree(v49);
              }
              else
              {
                printk(&unk_3A8EB0, "ipa_init_teth_stats");
                v69 = ipa3_ctx;
                if ( !ipa3_ctx )
                  goto LABEL_97;
                v70 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v70 )
                {
                  ipc_log_string(
                    v70,
                    "ipa %s:%d failed to construct dma_shared_mem imm cmd\n",
                    "ipa_init_teth_stats",
                    1047);
                  v69 = ipa3_ctx;
                }
                v71 = *(_QWORD *)(v69 + 34160);
                if ( v71 )
                {
                  ipc_log_string(
                    v71,
                    "ipa %s:%d failed to construct dma_shared_mem imm cmd\n",
                    "ipa_init_teth_stats",
                    1047);
                  v51 = -12;
                }
                else
                {
LABEL_97:
                  v51 = -12;
                }
              }
              kfree(v45);
            }
            else
            {
              printk(&unk_3E98FD, "ipa_init_teth_stats");
              v66 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_96;
              v67 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v67 )
              {
                ipc_log_string(
                  v67,
                  "ipa %s:%d failed to construct register_write imm cmd\n",
                  "ipa_init_teth_stats",
                  1027);
                v66 = ipa3_ctx;
              }
              v68 = *(_QWORD *)(v66 + 34160);
              if ( v68 )
              {
                ipc_log_string(
                  v68,
                  "ipa %s:%d failed to construct register_write imm cmd\n",
                  "ipa_init_teth_stats",
                  1027);
                v51 = -12;
              }
              else
              {
LABEL_96:
                v51 = -12;
              }
            }
            kfree(v28);
            if ( v35 )
            {
              kfree(v35);
              v52 = v89;
              if ( !v89 )
                goto LABEL_105;
            }
            else
            {
              v52 = v87;
              if ( !v87 )
                goto LABEL_105;
            }
LABEL_104:
            kfree(v52);
LABEL_105:
            dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), v88, *v20, 1, 0);
            goto LABEL_106;
          }
          printk(&unk_3E98FD, "ipa_init_teth_stats");
          v75 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v76 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v76 )
            {
              ipc_log_string(v76, "ipa %s:%d failed to construct register_write imm cmd\n", "ipa_init_teth_stats", 1006);
              v75 = ipa3_ctx;
            }
            v77 = *(_QWORD *)(v75 + 34160);
            if ( v77 )
              ipc_log_string(v77, "ipa %s:%d failed to construct register_write imm cmd\n", "ipa_init_teth_stats", 1006);
          }
        }
        v52 = v87;
        v51 = -12;
        if ( v87 )
          goto LABEL_104;
        goto LABEL_105;
      }
      printk(&unk_3C0EC2, "ipa_init_teth_stats");
      v56 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_95;
      v57 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v57 )
      {
        ipc_log_string(v57, "ipa %s:%d failed to generate pyld\n", "ipa_init_teth_stats", 932);
        v56 = ipa3_ctx;
      }
      v58 = *(_QWORD *)(v56 + 34160);
      if ( v58 )
      {
        ipc_log_string(v58, "ipa %s:%d failed to generate pyld\n", "ipa_init_teth_stats", 932);
        result = 0xFFFFFFFFLL;
      }
      else
      {
LABEL_95:
        result = 0xFFFFFFFFLL;
      }
    }
    else
    {
      printk(&unk_3B50D4, "ipa_init_teth_stats");
      v53 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_62;
      v54 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v54 )
      {
        ipc_log_string(v54, "ipa %s:%d invalid params\n", "ipa_init_teth_stats", 887);
        v53 = ipa3_ctx;
      }
      v55 = *(_QWORD *)(v53 + 34160);
      if ( v55 )
      {
        ipc_log_string(v55, "ipa %s:%d invalid params\n", "ipa_init_teth_stats", 887);
        result = 4294967274LL;
      }
      else
      {
LABEL_62:
        result = 4294967274LL;
      }
    }
  }
  else
  {
    result = 0;
  }
LABEL_107:
  _ReadStatusReg(SP_EL0);
  return result;
}
