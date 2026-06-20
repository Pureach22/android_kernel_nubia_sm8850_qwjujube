__int64 ipa_init_flt_rt_stats()
{
  _BYTE *v0; // x9
  __int64 v1; // x8
  int v2; // w27
  int v3; // w21
  unsigned __int16 *init_pyld; // x0
  __int64 v5; // x20
  unsigned __int16 *v6; // x28
  unsigned __int16 *v7; // x22
  const char **v8; // x21
  char v9; // w0
  __int64 v10; // x0
  __int64 v11; // x20
  __int64 v12; // x26
  unsigned int v13; // w21
  __int64 result; // x0
  int v15; // w22
  int v16; // w23
  int v17; // w24
  int v18; // w8
  _WORD *v19; // x0
  _QWORD *v20; // x8
  __int16 v21; // w9
  _WORD *v22; // x0
  _QWORD *v23; // x8
  _WORD *v24; // x23
  __int64 v25; // x10
  __int16 v26; // w9
  _WORD *v27; // x0
  _QWORD *v28; // x8
  _WORD *v29; // x24
  __int16 v30; // w9
  _WORD *v31; // x0
  _QWORD *v32; // x8
  __int64 v33; // x11
  _WORD *v34; // x26
  __int16 v35; // w9
  int v36; // w9
  _WORD *v37; // x0
  _QWORD *v38; // x8
  _WORD *v39; // x27
  __int16 v40; // w9
  unsigned int v41; // w25
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v53; // x0
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
  char v69; // w19
  const char *v70; // x0
  const char *v71; // x2
  __int64 v72; // x8
  __int64 v73; // x0
  __int64 v74; // x0
  int v75; // [xsp+Ch] [xbp-324h]
  _WORD *v76; // [xsp+10h] [xbp-320h]
  __int64 v77; // [xsp+18h] [xbp-318h]
  __int64 v78; // [xsp+28h] [xbp-308h]
  __int64 v79; // [xsp+30h] [xbp-300h] BYREF
  __int64 v80; // [xsp+38h] [xbp-2F8h] BYREF
  __int64 v81; // [xsp+40h] [xbp-2F0h]
  int v82; // [xsp+48h] [xbp-2E8h]
  __int64 v83; // [xsp+50h] [xbp-2E0h] BYREF
  __int64 v84; // [xsp+58h] [xbp-2D8h]
  int v85; // [xsp+60h] [xbp-2D0h]
  __int64 v86; // [xsp+68h] [xbp-2C8h] BYREF
  __int64 v87; // [xsp+70h] [xbp-2C0h]
  int v88; // [xsp+78h] [xbp-2B8h]
  __int64 v89; // [xsp+80h] [xbp-2B0h] BYREF
  __int64 v90; // [xsp+88h] [xbp-2A8h]
  int v91; // [xsp+90h] [xbp-2A0h]
  __int64 v92; // [xsp+98h] [xbp-298h] BYREF
  __int64 v93; // [xsp+A0h] [xbp-290h]
  __int64 v94; // [xsp+A8h] [xbp-288h]
  _QWORD s[80]; // [xsp+B0h] [xbp-280h] BYREF

  s[78] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v93 = 0;
  v94 = 0;
  v92 = 0;
  v91 = 0;
  v89 = 0;
  v90 = 0;
  v88 = 0;
  v86 = 0;
  v87 = 0;
  v85 = 0;
  v83 = 0;
  v84 = 0;
  v82 = 0;
  v80 = 0;
  v81 = 0;
  v79 = 0;
  memset(s, 0, 0x270u);
  v0 = *(_BYTE **)(ipa3_ctx + 43800);
  if ( v0 && *v0 == 1 )
  {
    v1 = **(_QWORD **)(ipa3_ctx + 34176);
    v2 = *(_DWORD *)(v1 + 320);
    v3 = *(_DWORD *)(v1 + 324);
    init_pyld = (unsigned __int16 *)ipahal_stats_generate_init_pyld(2, 32, 0);
    if ( init_pyld )
    {
      v5 = *init_pyld;
      v6 = init_pyld;
      if ( v3 < (int)v5 )
      {
        printk(&unk_3D2C66, "ipa_init_flt_rt_stats");
        v45 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v46 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v46 )
          {
            ipc_log_string(
              v46,
              "ipa %s:%d SRAM partition too small: %d needed %d\n",
              "ipa_init_flt_rt_stats",
              1447,
              v3,
              *v6);
            v45 = ipa3_ctx;
          }
          v47 = *(_QWORD *)(v45 + 34160);
          if ( v47 )
          {
            ipc_log_string(
              v47,
              "ipa %s:%d SRAM partition too small: %d needed %d\n",
              "ipa_init_flt_rt_stats",
              1447,
              v3,
              *v6);
            v41 = -1;
            goto LABEL_29;
          }
        }
LABEL_99:
        v41 = -1;
        goto LABEL_29;
      }
      v7 = init_pyld + 2;
      v8 = *(const char ***)(ipa3_ctx + 34216);
      v9 = is_vmalloc_addr(init_pyld + 2);
      if ( (v9 & 1) != 0 && (dma_map_single_attrs___already_done_0 & 1) == 0 )
      {
        v69 = v9;
        dma_map_single_attrs___already_done_0 = 1;
        v70 = (const char *)dev_driver_string(v8);
        v71 = v8[14];
        if ( !v71 )
          v71 = *v8;
        _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v70, v71);
        __break(0x800u);
        if ( (v69 & 1) == 0 )
        {
LABEL_8:
          v10 = dma_map_page_attrs(
                  v8,
                  ((unsigned __int64)(((__int64)((_QWORD)v7 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                  (unsigned __int16)v7 & 0xFFF,
                  v5,
                  1,
                  0);
          if ( v10 != -1 )
          {
            v11 = v10;
            v78 = v10;
            if ( (unsigned int)ipa_get_ep_mapping(95) == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
            {
              v12 = 0;
              v13 = 0;
            }
            else
            {
              ipa_close_coal_frame(&v79);
              v12 = v79;
              if ( !v79 )
              {
                printk(&unk_3AEDE8, "ipa_init_flt_rt_stats");
                v66 = ipa3_ctx;
                if ( !ipa3_ctx )
                  goto LABEL_90;
                v67 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v67 )
                {
                  ipc_log_string(v67, "ipa %s:%d failed to construct coal close IC\n", "ipa_init_flt_rt_stats", 1467);
                  v66 = ipa3_ctx;
                }
                v68 = *(_QWORD *)(v66 + 34160);
                if ( v68 )
                {
                  ipc_log_string(v68, "ipa %s:%d failed to construct coal close IC\n", "ipa_init_flt_rt_stats", 1467);
                  v41 = -12;
                }
                else
                {
LABEL_90:
                  v41 = -12;
                }
                goto LABEL_28;
              }
              ipa3_init_imm_cmd_desc(s, v79);
              v13 = 1;
            }
            v15 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(107, 0, 0);
            v16 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(108, 0, 0);
            v17 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(109, 0, 0);
            v75 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(110, 0, 0);
            v18 = *(unsigned __int16 *)(ipa3_ctx + 29522);
            BYTE4(v90) = 0;
            v91 = 2;
            LODWORD(v89) = v15;
            HIDWORD(v89) = v2 + v18;
            LODWORD(v90) = -1;
            v19 = (_WORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(7, &v89, 0);
            if ( v19 )
            {
              v77 = v12;
              v20 = &s[13 * v13];
              v76 = v19;
              *((_WORD *)v20 + 18) = v19[1];
              v20[1] = v19 + 2;
              v21 = *v19;
              *(_DWORD *)v20 = 3;
              BYTE4(v87) = 0;
              *((_WORD *)v20 + 17) = v21;
              v88 = 2;
              LODWORD(v20) = *(unsigned __int16 *)(ipa3_ctx + 29522);
              LODWORD(v87) = -1;
              LODWORD(v86) = v16;
              HIDWORD(v86) = v2 + (_DWORD)v20;
              v22 = (_WORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(7, &v86, 0);
              if ( v22 )
              {
                v23 = &s[13 * v13 + 13];
                v24 = v22;
                *((_WORD *)v23 + 18) = v22[1];
                v23[1] = v22 + 2;
                v25 = ipa3_ctx;
                v26 = *v22;
                *(_DWORD *)v23 = 3;
                BYTE4(v84) = 0;
                *((_WORD *)v23 + 17) = v26;
                LODWORD(v23) = *(unsigned __int16 *)(v25 + 29522);
                v85 = 2;
                LODWORD(v84) = -1;
                LODWORD(v83) = v17;
                HIDWORD(v83) = v2 + (_DWORD)v23;
                v27 = (_WORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                                 7,
                                 &v83,
                                 0);
                if ( v27 )
                {
                  v28 = &s[13 * (v13 | 2)];
                  v29 = v27;
                  *((_WORD *)v28 + 18) = v27[1];
                  v28[1] = v27 + 2;
                  v30 = *v27;
                  *(_DWORD *)v28 = 3;
                  BYTE4(v81) = 0;
                  *((_WORD *)v28 + 17) = v30;
                  v82 = 2;
                  LODWORD(v28) = *(unsigned __int16 *)(ipa3_ctx + 29522);
                  LODWORD(v81) = -1;
                  LODWORD(v80) = v75;
                  HIDWORD(v80) = v2 + (_DWORD)v28;
                  v31 = (_WORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                                   7,
                                   &v80,
                                   0);
                  if ( v31 )
                  {
                    v32 = &s[13 * v13 + 39];
                    v33 = ipa3_ctx;
                    v34 = v31;
                    *((_WORD *)v32 + 18) = v31[1];
                    v32[1] = v31 + 2;
                    v35 = *v31;
                    *(_DWORD *)v32 = 3;
                    v11 = v78;
                    *(_WORD *)((char *)&v94 + 1) = 0;
                    *((_WORD *)v32 + 17) = v35;
                    HIDWORD(v94) = 2;
                    LODWORD(v32) = *(unsigned __int16 *)(v33 + 29522);
                    v36 = *v6;
                    v92 = v78;
                    LODWORD(v93) = v36;
                    HIDWORD(v93) = v2 + (_DWORD)v32;
                    v37 = (_WORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                                     11,
                                     &v92,
                                     0);
                    if ( v37 )
                    {
                      v38 = &s[13 * (v13 | 4)];
                      v39 = v37;
                      *((_WORD *)v38 + 18) = v37[1];
                      v38[1] = v37 + 2;
                      v40 = *v37;
                      *(_DWORD *)v38 = 3;
                      *((_WORD *)v38 + 17) = v40;
                      v41 = ((__int64 (__fastcall *)(_QWORD, _QWORD *))ipa3_send_cmd)(v13 + 5, s);
                      if ( v41 )
                      {
                        printk(&unk_3B18DA, "ipa_init_flt_rt_stats");
                        v63 = ipa3_ctx;
                        if ( ipa3_ctx )
                        {
                          v64 = *(_QWORD *)(ipa3_ctx + 34152);
                          if ( v64 )
                          {
                            ipc_log_string(
                              v64,
                              "ipa %s:%d failed to send immediate command (error %d)\n",
                              "ipa_init_flt_rt_stats",
                              1583,
                              v41);
                            v63 = ipa3_ctx;
                          }
                          v65 = *(_QWORD *)(v63 + 34160);
                          if ( v65 )
                            ipc_log_string(
                              v65,
                              "ipa %s:%d failed to send immediate command (error %d)\n",
                              "ipa_init_flt_rt_stats",
                              1583,
                              v41);
                        }
                      }
                      kfree(v39);
                    }
                    else
                    {
                      printk(&unk_3A8EB0, "ipa_init_flt_rt_stats");
                      v60 = ipa3_ctx;
                      if ( !ipa3_ctx )
                        goto LABEL_76;
                      v61 = *(_QWORD *)(ipa3_ctx + 34152);
                      if ( v61 )
                      {
                        ipc_log_string(
                          v61,
                          "ipa %s:%d failed to construct dma_shared_mem imm cmd\n",
                          "ipa_init_flt_rt_stats",
                          1571);
                        v60 = ipa3_ctx;
                      }
                      v62 = *(_QWORD *)(v60 + 34160);
                      if ( v62 )
                      {
                        ipc_log_string(
                          v62,
                          "ipa %s:%d failed to construct dma_shared_mem imm cmd\n",
                          "ipa_init_flt_rt_stats",
                          1571);
                        v41 = -12;
                      }
                      else
                      {
LABEL_76:
                        v41 = -12;
                      }
                    }
                    kfree(v34);
                    v12 = v77;
                  }
                  else
                  {
                    printk(&unk_3E98FD, "ipa_init_flt_rt_stats");
                    v57 = ipa3_ctx;
                    v11 = v78;
                    if ( ipa3_ctx )
                    {
                      v58 = *(_QWORD *)(ipa3_ctx + 34152);
                      if ( v58 )
                      {
                        ipc_log_string(
                          v58,
                          "ipa %s:%d failed to construct register_write imm cmd\n",
                          "ipa_init_flt_rt_stats",
                          1551);
                        v57 = ipa3_ctx;
                      }
                      v59 = *(_QWORD *)(v57 + 34160);
                      if ( v59 )
                        ipc_log_string(
                          v59,
                          "ipa %s:%d failed to construct register_write imm cmd\n",
                          "ipa_init_flt_rt_stats",
                          1551);
                      v41 = -12;
                    }
                    else
                    {
                      v41 = -12;
                    }
                  }
                  kfree(v29);
                }
                else
                {
                  printk(&unk_3E98FD, "ipa_init_flt_rt_stats");
                  v54 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v55 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v55 )
                    {
                      ipc_log_string(
                        v55,
                        "ipa %s:%d failed to construct register_write imm cmd\n",
                        "ipa_init_flt_rt_stats",
                        1531);
                      v54 = ipa3_ctx;
                    }
                    v11 = v78;
                    v56 = *(_QWORD *)(v54 + 34160);
                    if ( v56 )
                      ipc_log_string(
                        v56,
                        "ipa %s:%d failed to construct register_write imm cmd\n",
                        "ipa_init_flt_rt_stats",
                        1531);
                    v41 = -12;
                  }
                  else
                  {
                    v11 = v78;
                    v41 = -12;
                  }
                }
                kfree(v24);
              }
              else
              {
                printk(&unk_3E98FD, "ipa_init_flt_rt_stats");
                v51 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v11 = v78;
                  v52 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v52 )
                  {
                    ipc_log_string(
                      v52,
                      "ipa %s:%d failed to construct register_write imm cmd\n",
                      "ipa_init_flt_rt_stats",
                      1511);
                    v51 = ipa3_ctx;
                  }
                  v53 = *(_QWORD *)(v51 + 34160);
                  if ( v53 )
                    ipc_log_string(
                      v53,
                      "ipa %s:%d failed to construct register_write imm cmd\n",
                      "ipa_init_flt_rt_stats",
                      1511);
                  v41 = -12;
                }
                else
                {
                  v11 = v78;
                  v41 = -12;
                }
              }
              kfree(v76);
            }
            else
            {
              printk(&unk_3E98FD, "ipa_init_flt_rt_stats");
              v48 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v49 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v49 )
                {
                  ipc_log_string(
                    v49,
                    "ipa %s:%d failed to construct register_write imm cmd\n",
                    "ipa_init_flt_rt_stats",
                    1491);
                  v48 = ipa3_ctx;
                }
                v11 = v78;
                v50 = *(_QWORD *)(v48 + 34160);
                if ( v50 )
                  ipc_log_string(
                    v50,
                    "ipa %s:%d failed to construct register_write imm cmd\n",
                    "ipa_init_flt_rt_stats",
                    1491);
                v41 = -12;
              }
              else
              {
                v11 = v78;
                v41 = -12;
              }
            }
            if ( v12 )
              kfree(v12);
LABEL_28:
            dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), v11, *v6, 1, 0);
LABEL_29:
            kfree(v6);
            result = v41;
            goto LABEL_30;
          }
        }
      }
      else if ( (v9 & 1) == 0 )
      {
        goto LABEL_8;
      }
      printk(&unk_3B50B5, "ipa_init_flt_rt_stats");
      v72 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v73 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v73 )
        {
          ipc_log_string(v73, "ipa %s:%d failed to DMA map\n", "ipa_init_flt_rt_stats", 1457);
          v72 = ipa3_ctx;
        }
        v74 = *(_QWORD *)(v72 + 34160);
        if ( v74 )
          ipc_log_string(v74, "ipa %s:%d failed to DMA map\n", "ipa_init_flt_rt_stats", 1457);
      }
      goto LABEL_99;
    }
    printk(&unk_3C0EC2, "ipa_init_flt_rt_stats");
    v42 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_70;
    v43 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v43 )
    {
      ipc_log_string(v43, "ipa %s:%d failed to generate pyld\n", "ipa_init_flt_rt_stats", 1441);
      v42 = ipa3_ctx;
    }
    v44 = *(_QWORD *)(v42 + 34160);
    if ( v44 )
    {
      ipc_log_string(v44, "ipa %s:%d failed to generate pyld\n", "ipa_init_flt_rt_stats", 1441);
      result = 0xFFFFFFFFLL;
    }
    else
    {
LABEL_70:
      result = 0xFFFFFFFFLL;
    }
  }
  else
  {
    result = 0;
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
