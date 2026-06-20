__int64 __fastcall ipa3_tag_process(unsigned __int64 a1, unsigned int a2, __int64 a3)
{
  int v3; // w20
  __int64 v4; // x22
  unsigned __int64 v5; // x23
  unsigned __int64 v6; // x24
  __int64 v7; // x26
  _BYTE *v8; // x27
  unsigned int v9; // w28
  unsigned int v10; // w11
  unsigned int v11; // w12
  _BYTE *v12; // x10
  unsigned int v13; // w10
  unsigned int v14; // w9
  char *v15; // x19
  __int64 v16; // x8
  unsigned int v17; // w9
  unsigned int v18; // w10
  int ep_reg_offset; // w0
  char *v20; // x9
  unsigned int v21; // w0
  _WORD *v22; // x0
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x1
  _WORD *v25; // x0
  unsigned __int64 v26; // x8
  char *v27; // x9
  __int64 v28; // x8
  _BYTE *v29; // x9
  unsigned int v30; // w9
  unsigned int v31; // w8
  int v32; // w8
  _WORD *v33; // x0
  unsigned __int64 v34; // x8
  char *v35; // x9
  _WORD *v36; // x0
  unsigned __int64 v37; // x8
  char *v38; // x9
  signed int v39; // w24
  _DWORD *v40; // x0
  _DWORD *v41; // x23
  __int64 v42; // x0
  __int64 v43; // x25
  unsigned __int64 v44; // x9
  char *v45; // x8
  int v46; // w0
  unsigned int v47; // w26
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x8
  __int64 v52; // x9
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0
  unsigned int v58; // w21
  __int64 v59; // x8
  __int64 v60; // x0
  __int64 v61; // x0
  int v62; // w19
  __int64 v63; // x8
  __int64 v64; // x0
  __int64 v65; // x0
  _WORD *v66; // x0
  char *v67; // x9
  unsigned __int64 v68; // x8
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
  __int64 v81; // x8
  __int64 v82; // x0
  __int64 v83; // x0
  __int64 v84; // x8
  __int64 v85; // x0
  __int64 v86; // x0
  __int64 v87; // x8
  __int64 v88; // x0
  __int64 v89; // x0
  int v90; // w21
  __int64 v91; // x8
  __int64 v92; // x0
  __int64 v93; // x0
  __int64 v94; // x8
  __int64 v95; // x0
  __int64 v96; // x0
  __int64 v97; // x8
  __int64 v98; // x0
  __int64 v99; // x0
  int v100; // w24
  unsigned __int64 StatusReg; // x20
  __int64 v102; // x21
  __int64 v103; // x8
  __int64 v104; // x0
  __int64 v105; // x0
  __int64 v106; // x8
  __int64 v107; // x0
  __int64 v108; // x0
  int v109; // w8
  unsigned int v110; // w20
  __int64 v111; // x22
  void (__fastcall *v112)(__int64, __int64); // x8
  __int64 v113; // x0
  __int64 v114; // x1
  unsigned int v122; // w8
  unsigned int v123; // w8
  unsigned int v126; // w8
  unsigned int v127; // w8
  __int64 v128; // [xsp+18h] [xbp-68h]
  __int64 v129; // [xsp+20h] [xbp-60h]
  __int64 v130; // [xsp+28h] [xbp-58h] BYREF
  __int64 v131; // [xsp+30h] [xbp-50h]
  unsigned __int64 v132; // [xsp+38h] [xbp-48h] BYREF
  __int64 v133; // [xsp+40h] [xbp-40h]
  __int128 v134; // [xsp+48h] [xbp-38h] BYREF
  int v135; // [xsp+58h] [xbp-28h]
  __int64 v136; // [xsp+60h] [xbp-20h] BYREF
  __int64 v137; // [xsp+68h] [xbp-18h] BYREF
  int v138; // [xsp+74h] [xbp-Ch] BYREF
  __int64 v139; // [xsp+78h] [xbp-8h]

  v139 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v138 = 0;
  v136 = 0;
  v137 = 0;
  v135 = 0;
  v134 = 0u;
  v132 = 0;
  v133 = 0;
  v130 = 0;
  v131 = 0;
  v129 = 0;
  if ( *(unsigned __int8 *)(ipa3_ctx + 32244) >= 0x18uLL )
    goto LABEL_213;
  v8 = ipa3_ep_mapping;
  v7 = a3;
  v9 = a2;
  v5 = a1;
  if ( ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 4940] == 1 )
  {
    v10 = *(_DWORD *)&ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 4960];
    v3 = 4;
    if ( (v10 & 0x80000000) == 0 )
    {
      if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x14u )
        v11 = 31;
      else
        v11 = 36;
      if ( v10 >= v11 )
        v3 = 4;
      else
        v3 = 5;
    }
  }
  else
  {
    v3 = 4;
  }
  if ( (int)(37 - a2) < v3 )
  {
    v62 = 37 - v3;
    printk(&unk_3DC28A, "ipa3_tag_process");
    v63 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v64 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v64 )
      {
        ipc_log_string(
          v64,
          "ipa %s:%d up to %d descriptors are allowed (received %d)\n",
          "ipa3_tag_process",
          11086,
          v62,
          v9);
        v63 = ipa3_ctx;
      }
      v65 = *(_QWORD *)(v63 + 34160);
      if ( v65 )
      {
        ipc_log_string(
          v65,
          "ipa %s:%d up to %d descriptors are allowed (received %d)\n",
          "ipa3_tag_process",
          11086,
          v62,
          v9);
        v58 = -12;
        goto LABEL_246;
      }
    }
LABEL_222:
    v58 = -12;
    goto LABEL_246;
  }
  v12 = &ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244)];
  if ( v12[1872] != 1
    || (v13 = *((_DWORD *)v12 + 473), (v13 & 0x80000000) != 0)
    || (*(_DWORD *)(ipa3_ctx + 32240) <= 0x14u ? (v14 = 31) : (v14 = 36), v13 >= v14) )
  {
    printk(&unk_3DA941, "ipa3_tag_process");
    v59 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_132;
    v60 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v60 )
    {
      ipc_log_string(v60, "ipa %s:%d Client %u is not mapped\n", "ipa3_tag_process", 11093, 36);
      v59 = ipa3_ctx;
    }
    v61 = *(_QWORD *)(v59 + 34160);
    if ( v61 )
    {
      ipc_log_string(v61, "ipa %s:%d Client %u is not mapped\n", "ipa3_tag_process", 11093, 36);
      v58 = -14;
    }
    else
    {
LABEL_132:
      v58 = -14;
    }
    goto LABEL_246;
  }
  v4 = *(_QWORD *)(ipa3_ctx + 480LL * v13 + 640);
  v15 = (char *)_kmalloc_cache_noprof(dma_alloc_attrs, 3520, 3848);
  if ( !v15 )
  {
LABEL_217:
    printk(&unk_3CFD12, "ipa3_tag_process");
    v103 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v104 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v104 )
      {
        ipc_log_string(v104, "ipa %s:%d failed to allocate memory\n", "ipa3_tag_process", 11100);
        v103 = ipa3_ctx;
      }
      v105 = *(_QWORD *)(v103 + 34160);
      if ( v105 )
        ipc_log_string(v105, "ipa %s:%d failed to allocate memory\n", "ipa3_tag_process", 11100);
    }
    goto LABEL_222;
  }
  while ( 1 )
  {
    if ( !v5 )
    {
      printk(&unk_3E1AD8, "ipa3_tag_process");
      v69 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_165;
      v70 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v70 )
      {
        ipc_log_string(v70, "ipa %s:%d desc is NULL\n", "ipa3_tag_process", 11111);
        v69 = ipa3_ctx;
      }
      v71 = *(_QWORD *)(v69 + 34160);
      if ( v71 )
      {
        ipc_log_string(v71, "ipa %s:%d desc is NULL\n", "ipa3_tag_process", 11111);
        v58 = -14;
      }
      else
      {
LABEL_165:
        v58 = -14;
      }
      goto LABEL_245;
    }
    v6 = 104LL * (int)v9;
    if ( v6 >= 0xF09 )
      goto LABEL_214;
    memcpy(v15, (const void *)v5, 104LL * (int)v9);
    v16 = ipa3_ctx;
    if ( *(unsigned __int8 *)(ipa3_ctx + 32244) >= 0x18uLL )
      goto LABEL_213;
    v128 = v7;
    if ( v8[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 4940] != 1
      || (v5 = *(unsigned int *)&v8[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 4960], (v5 & 0x80000000) != 0) )
    {
      v7 = v9;
    }
    else
    {
      v17 = *(_DWORD *)(ipa3_ctx + 32240);
      v7 = v9;
      if ( v17 <= 0x14 )
        v18 = 31;
      else
        v18 = 36;
      if ( (unsigned int)v5 < v18 )
      {
        BYTE12(v134) = 0;
        v135 = *(unsigned __int8 *)(ipa3_ctx + 51242);
        if ( v17 > 0x14 )
          ep_reg_offset = ipahal_get_ep_reg_offset(133, (unsigned int)v5);
        else
          ep_reg_offset = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(44, 0, 0);
        LODWORD(v134) = ep_reg_offset;
        ipahal_get_aggr_force_close_valmask((unsigned int)v5, &v136);
        *(_QWORD *)((char *)&v134 + 4) = v136;
        v66 = (_WORD *)((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v134, 0);
        if ( !v66 )
        {
          printk(&unk_3AEDE8, "ipa3_tag_process");
          v97 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v98 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v98 )
            {
              ipc_log_string(v98, "ipa %s:%d failed to construct coal close IC\n", "ipa3_tag_process", 11138);
              v97 = ipa3_ctx;
            }
            v99 = *(_QWORD *)(v97 + 34160);
            if ( v99 )
              ipc_log_string(v99, "ipa %s:%d failed to construct coal close IC\n", "ipa3_tag_process", 11138);
          }
          v58 = -12;
          goto LABEL_245;
        }
        if ( v6 >= 0xEA1 )
          goto LABEL_215;
        v67 = &v15[104 * v9];
        v68 = 104LL * (int)v9;
        *((_QWORD *)v67 + 11) = 0;
        *((_QWORD *)v67 + 12) = 0;
        *((_QWORD *)v67 + 9) = 0;
        *((_QWORD *)v67 + 10) = 0;
        *((_QWORD *)v67 + 7) = 0;
        *((_QWORD *)v67 + 8) = 0;
        *((_QWORD *)v67 + 5) = 0;
        *((_QWORD *)v67 + 6) = 0;
        *((_QWORD *)v67 + 3) = 0;
        *((_QWORD *)v67 + 4) = 0;
        *((_QWORD *)v67 + 1) = 0;
        *((_QWORD *)v67 + 2) = 0;
        *(_QWORD *)v67 = 0;
        if ( v68 - 3813 < 0xFFFFFFFFFFFFF0F7LL )
          goto LABEL_247;
        *((_WORD *)v67 + 18) = v66[1];
        if ( v68 - 3841 < 0xFFFFFFFFFFFFF0F7LL )
          goto LABEL_247;
        *((_QWORD *)v67 + 1) = v66 + 2;
        if ( v68 - 3815 < 0xFFFFFFFFFFFFF0F7LL )
          goto LABEL_247;
        *((_WORD *)v67 + 17) = *v66;
        if ( v68 > 0xF08 )
          goto LABEL_247;
        if ( v9 == 37 )
          goto LABEL_247;
        *(_DWORD *)v67 = 3;
        if ( v68 > 0xEE0 )
          goto LABEL_247;
        *((_QWORD *)v67 + 5) = ipa3_tag_destroy_imm;
        if ( v68 > 0xED8 )
          goto LABEL_247;
        v7 = v9 + 1;
        *((_QWORD *)v67 + 6) = v66;
        v16 = ipa3_ctx;
      }
    }
    LODWORD(v20) = *(unsigned __int8 *)(v16 + 51242);
    if ( (_DWORD)v20 == 1 )
    {
      LODWORD(v131) = 4;
      v129 = dma_alloc_attrs(*(_QWORD *)(v16 + 34216), 4, &v130, 3264, 0);
      if ( !v129 )
        goto LABEL_202;
      v21 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(
              103,
              0,
              *(unsigned int *)(ipa3_ctx + 43304));
      LOBYTE(v133) = 0;
      v132 = __PAIR64__(v130, v21);
      HIDWORD(v133) = 0;
      v22 = (_WORD *)((__int64 (__fastcall *)(__int64, unsigned __int64 *, _QWORD))ipahal_construct_imm_cmd)(
                       8,
                       &v132,
                       0);
      if ( !v22 )
      {
        printk(&unk_3C4FA1, "ipa3_tag_process");
        v94 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v95 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v95 )
          {
            ipc_log_string(v95, "ipa %s:%d failed to construct DUMMY READ IC\n", "ipa3_tag_process", 11166);
            v94 = ipa3_ctx;
          }
          v96 = *(_QWORD *)(v94 + 34160);
          if ( v96 )
            ipc_log_string(v96, "ipa %s:%d failed to construct DUMMY READ IC\n", "ipa3_tag_process", 11166);
        }
        goto LABEL_202;
      }
      v23 = 104LL * (int)v7;
      if ( v23 <= 0xF08 )
        v24 = 3848 - v23;
      else
        v24 = 0;
      if ( v24 <= 0x67 )
        goto LABEL_216;
      v20 = &v15[104 * (int)v7];
      *((_QWORD *)v20 + 11) = 0;
      *((_QWORD *)v20 + 12) = 0;
      *((_QWORD *)v20 + 9) = 0;
      *((_QWORD *)v20 + 10) = 0;
      *((_QWORD *)v20 + 7) = 0;
      *((_QWORD *)v20 + 8) = 0;
      *((_QWORD *)v20 + 5) = 0;
      *((_QWORD *)v20 + 6) = 0;
      *((_QWORD *)v20 + 3) = 0;
      *((_QWORD *)v20 + 4) = 0;
      *((_QWORD *)v20 + 1) = 0;
      *((_QWORD *)v20 + 2) = 0;
      *(_QWORD *)v20 = 0;
      if ( v23 - 3813 < 0xFFFFFFFFFFFFF0F7LL )
        goto LABEL_247;
      *((_WORD *)v20 + 18) = v22[1];
      if ( v23 - 3841 < 0xFFFFFFFFFFFFF0F7LL )
        goto LABEL_247;
      *((_QWORD *)v20 + 1) = v22 + 2;
      if ( v23 - 3815 < 0xFFFFFFFFFFFFF0F7LL )
        goto LABEL_247;
      *((_WORD *)v20 + 17) = *v22;
      if ( v23 > 0xF08 )
        goto LABEL_247;
      if ( (_DWORD)v7 == 37 )
        goto LABEL_247;
      *(_DWORD *)v20 = 3;
      if ( v23 > 0xEE0 )
        goto LABEL_247;
      *((_QWORD *)v20 + 5) = ipa3_tag_destroy_imm;
      if ( v23 > 0xED8 )
        goto LABEL_247;
      *((_QWORD *)v20 + 6) = v22;
      v16 = ipa3_ctx;
      v7 = (unsigned int)(v7 + 1);
      LOBYTE(v20) = *(_BYTE *)(ipa3_ctx + 51242);
    }
    if ( ((unsigned __int8)v20 & 1) == 0 )
    {
      v25 = (_WORD *)ipahal_construct_nop_imm_cmd(0, 2, 0);
      if ( !v25 )
      {
        printk(&unk_3CCC37, "ipa3_tag_process");
        v87 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v88 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v88 )
          {
            ipc_log_string(v88, "ipa %s:%d failed to construct NOP imm cmd\n", "ipa3_tag_process", 11182);
            v87 = ipa3_ctx;
          }
          v89 = *(_QWORD *)(v87 + 34160);
          if ( v89 )
            ipc_log_string(v89, "ipa %s:%d failed to construct NOP imm cmd\n", "ipa3_tag_process", 11182);
        }
        goto LABEL_202;
      }
      v26 = 104LL * (int)v7;
      if ( v26 <= 0xF08 )
        v24 = 3848 - v26;
      else
        v24 = 0;
      if ( v24 <= 0x67 )
        goto LABEL_216;
      v27 = &v15[104 * (int)v7];
      *((_QWORD *)v27 + 11) = 0;
      *((_QWORD *)v27 + 12) = 0;
      *((_QWORD *)v27 + 9) = 0;
      *((_QWORD *)v27 + 10) = 0;
      *((_QWORD *)v27 + 7) = 0;
      *((_QWORD *)v27 + 8) = 0;
      *((_QWORD *)v27 + 5) = 0;
      *((_QWORD *)v27 + 6) = 0;
      *((_QWORD *)v27 + 3) = 0;
      *((_QWORD *)v27 + 4) = 0;
      *((_QWORD *)v27 + 1) = 0;
      *((_QWORD *)v27 + 2) = 0;
      *(_QWORD *)v27 = 0;
      if ( v26 - 3813 < 0xFFFFFFFFFFFFF0F7LL )
        goto LABEL_247;
      *((_WORD *)v27 + 18) = v25[1];
      if ( v26 - 3841 < 0xFFFFFFFFFFFFF0F7LL )
        goto LABEL_247;
      *((_QWORD *)v27 + 1) = v25 + 2;
      if ( v26 - 3815 < 0xFFFFFFFFFFFFF0F7LL )
        goto LABEL_247;
      *((_WORD *)v27 + 17) = *v25;
      if ( v26 > 0xF08 )
        goto LABEL_247;
      if ( (_DWORD)v7 == 37 )
        goto LABEL_247;
      *(_DWORD *)v27 = 3;
      if ( v26 > 0xEE0 )
        goto LABEL_247;
      *((_QWORD *)v27 + 5) = ipa3_tag_destroy_imm;
      if ( v26 > 0xED8 )
        goto LABEL_247;
      v7 = (unsigned int)(v7 + 1);
      *((_QWORD *)v27 + 6) = v25;
      v16 = ipa3_ctx;
    }
    v28 = v16 + 28672;
    if ( *(unsigned __int8 *)(v28 + 3572) >= 0x18uLL )
    {
LABEL_213:
      __break(0x5512u);
LABEL_214:
      _fortify_panic(17, 3848, v6);
LABEL_215:
      v24 = 3848 - v6;
      goto LABEL_216;
    }
    v29 = &v8[6968 * *(unsigned __int8 *)(v28 + 3572)];
    if ( v29[1716] != 1 || (v30 = *((_DWORD *)v29 + 434), (v30 & 0x80000000) != 0) )
    {
      v32 = -1;
    }
    else
    {
      if ( *(_DWORD *)(v28 + 3568) <= 0x14u )
        v31 = 31;
      else
        v31 = 36;
      if ( v30 >= v31 )
        v32 = -1;
      else
        v32 = v30;
    }
    v138 = v32;
    v33 = (_WORD *)((__int64 (__fastcall *)(__int64, int *, _QWORD))ipahal_construct_imm_cmd)(10, &v138, 0);
    if ( !v33 )
    {
      printk(&unk_3C1B99, "ipa3_tag_process");
      v72 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v73 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v73 )
        {
          ipc_log_string(v73, "ipa %s:%d failed to construct ip_packet_init imm cmd\n", "ipa3_tag_process", 11198);
          v72 = ipa3_ctx;
        }
        v74 = *(_QWORD *)(v72 + 34160);
        if ( v74 )
          ipc_log_string(v74, "ipa %s:%d failed to construct ip_packet_init imm cmd\n", "ipa3_tag_process", 11198);
      }
LABEL_202:
      v58 = -12;
      goto LABEL_230;
    }
    v34 = 104LL * (int)v7;
    if ( v34 <= 0xF08 )
      v24 = 3848 - v34;
    else
      v24 = 0;
    if ( v24 <= 0x67 )
      goto LABEL_216;
    v35 = &v15[104 * (int)v7];
    *((_QWORD *)v35 + 11) = 0;
    *((_QWORD *)v35 + 12) = 0;
    *((_QWORD *)v35 + 9) = 0;
    *((_QWORD *)v35 + 10) = 0;
    *((_QWORD *)v35 + 7) = 0;
    *((_QWORD *)v35 + 8) = 0;
    *((_QWORD *)v35 + 5) = 0;
    *((_QWORD *)v35 + 6) = 0;
    *((_QWORD *)v35 + 3) = 0;
    *((_QWORD *)v35 + 4) = 0;
    *((_QWORD *)v35 + 1) = 0;
    *((_QWORD *)v35 + 2) = 0;
    *(_QWORD *)v35 = 0;
    if ( v34 - 3813 < 0xFFFFFFFFFFFFF0F7LL )
      goto LABEL_247;
    *((_WORD *)v35 + 18) = v33[1];
    if ( v34 - 3841 < 0xFFFFFFFFFFFFF0F7LL )
      goto LABEL_247;
    *((_QWORD *)v35 + 1) = v33 + 2;
    if ( v34 - 3815 < 0xFFFFFFFFFFFFF0F7LL )
      goto LABEL_247;
    *((_WORD *)v35 + 17) = *v33;
    if ( v34 > 0xF08 )
      goto LABEL_247;
    if ( (_DWORD)v7 == 37 )
      goto LABEL_247;
    *(_DWORD *)v35 = 3;
    if ( v34 > 0xEE0 )
      goto LABEL_247;
    *((_QWORD *)v35 + 5) = ipa3_tag_destroy_imm;
    if ( v34 > 0xED8 )
      goto LABEL_247;
    *((_QWORD *)v35 + 6) = v33;
    v5 = (unsigned int)(v7 + 1);
    v137 = 1468208643;
    v36 = (_WORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(12, &v137, 0);
    if ( !v36 )
      break;
    v37 = 104LL * (int)v5;
    if ( v37 <= 0xF08 )
      v24 = 3848 - v37;
    else
      v24 = 0;
    if ( v24 > 0x67 )
    {
      v38 = &v15[104 * (int)v5];
      *((_QWORD *)v38 + 11) = 0;
      *((_QWORD *)v38 + 12) = 0;
      *((_QWORD *)v38 + 9) = 0;
      *((_QWORD *)v38 + 10) = 0;
      *((_QWORD *)v38 + 7) = 0;
      *((_QWORD *)v38 + 8) = 0;
      *((_QWORD *)v38 + 5) = 0;
      *((_QWORD *)v38 + 6) = 0;
      *((_QWORD *)v38 + 3) = 0;
      *((_QWORD *)v38 + 4) = 0;
      *((_QWORD *)v38 + 1) = 0;
      *((_QWORD *)v38 + 2) = 0;
      *(_QWORD *)v38 = 0;
      if ( v37 - 3813 < 0xFFFFFFFFFFFFF0F7LL )
        goto LABEL_247;
      *((_WORD *)v38 + 18) = v36[1];
      if ( v37 - 3841 < 0xFFFFFFFFFFFFF0F7LL )
        goto LABEL_247;
      *((_QWORD *)v38 + 1) = v36 + 2;
      if ( v37 - 3815 < 0xFFFFFFFFFFFFF0F7LL )
        goto LABEL_247;
      *((_WORD *)v38 + 17) = *v36;
      if ( v37 > 0xF08 )
        goto LABEL_247;
      if ( (_DWORD)v7 == 36 )
        goto LABEL_247;
      *(_DWORD *)v38 = 3;
      if ( v37 > 0xEE0 )
        goto LABEL_247;
      *((_QWORD *)v38 + 5) = ipa3_tag_destroy_imm;
      if ( v37 > 0xED8 )
        goto LABEL_247;
      v39 = v7 + 2;
      *((_QWORD *)v38 + 6) = v36;
      v40 = (_DWORD *)_kmalloc_cache_noprof(ipc_log_string, 3520, 40);
      v41 = v40;
      if ( v40 )
      {
        *v40 = 0;
        _init_swait_queue_head(v40 + 2, "&x->wait", &init_completion___key_4);
        v41[8] = 2;
        v42 = _alloc_skb(8, 3264, 0, 0xFFFFFFFFLL);
        if ( v42 )
        {
          v43 = v42;
          *(_QWORD *)skb_put(v42, 8) = v41;
          if ( v39 >= 37 )
          {
            printk(&unk_3B1937, "ipa3_tag_process");
            v81 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v82 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v82 )
              {
                ipc_log_string(v82, "ipa %s:%d number of commands is out of range\n", "ipa3_tag_process", 11243);
                v81 = ipa3_ctx;
              }
              v83 = *(_QWORD *)(v81 + 34160);
              if ( v83 )
                ipc_log_string(v83, "ipa %s:%d number of commands is out of range\n", "ipa3_tag_process", 11243);
            }
            v58 = -105;
          }
          else
          {
            if ( (unsigned __int64)(104LL * v39 - 3841) < 0xFFFFFFFFFFFFF0F7LL )
              goto LABEL_247;
            v44 = 104LL * v39;
            v45 = &v15[v44];
            *(_QWORD *)&v15[v44 + 8] = *(_QWORD *)(v43 + 224);
            if ( v44 - 3815 < 0xFFFFFFFFFFFFF0F7LL )
              goto LABEL_247;
            *((_WORD *)v45 + 17) = *(_DWORD *)(v43 + 112);
            if ( v44 > 0xF08 )
              goto LABEL_247;
            *(_DWORD *)v45 = 1;
            if ( v44 > 0xEE0 )
              goto LABEL_247;
            *((_QWORD *)v45 + 5) = ipa3_tag_free_skb;
            if ( v44 > 0xED8 )
              goto LABEL_247;
            v39 = v7 + 3;
            *((_QWORD *)v45 + 6) = v43;
            v46 = ipa3_send(v4, (int)v7 + 3, (__int64)v15);
            if ( !v46 )
            {
LABEL_112:
              kfree(v15);
              v51 = ipa3_ctx;
              v52 = ipa3_ctx + 31960;
              *(_BYTE *)(ipa3_ctx + 31960) = 0;
              if ( v51 )
              {
                v53 = *(_QWORD *)(v52 + 2192);
                if ( v53 )
                {
                  ipc_log_string(v53, "ipa %s:%d waiting for TAG response\n", "ipa3_tag_process", 11278);
                  v51 = ipa3_ctx;
                }
                v54 = *(_QWORD *)(v51 + 34160);
                if ( v54 )
                  ipc_log_string(v54, "ipa %s:%d waiting for TAG response\n", "ipa3_tag_process", 11278);
              }
              if ( (unsigned int)wait_for_completion_timeout(v41, v128) )
              {
                v55 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v56 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v56 )
                  {
                    ipc_log_string(v56, "ipa %s:%d TAG response arrived!\n", "ipa3_tag_process", 11293);
                    v55 = ipa3_ctx;
                  }
                  v57 = *(_QWORD *)(v55 + 34160);
                  if ( v57 )
                    ipc_log_string(v57, "ipa %s:%d TAG response arrived!\n", "ipa3_tag_process", 11293);
                }
                _X9 = v41 + 8;
                __asm { PRFM            #0x11, [X9] }
                do
                {
                  v122 = __ldxr(_X9);
                  v123 = v122 - 1;
                }
                while ( __stlxr(v123, _X9) );
                __dmb(0xBu);
                if ( !v123 )
                  kfree(v41);
                if ( v129 )
                  dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v131, v129, v130, 0);
                usleep_range_state(1000, 2000, 2);
                v58 = 0;
              }
              else
              {
                printk(&unk_3C7DF2, "ipa3_tag_process");
                v84 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v85 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v85 )
                  {
                    ipc_log_string(
                      v85,
                      "ipa %s:%d timeout (%lu msec) on waiting for TAG response\n",
                      "ipa3_tag_process",
                      11282,
                      v128);
                    v84 = ipa3_ctx;
                  }
                  v86 = *(_QWORD *)(v84 + 34160);
                  if ( v86 )
                    ipc_log_string(
                      v86,
                      "ipa %s:%d timeout (%lu msec) on waiting for TAG response\n",
                      "ipa3_tag_process",
                      11282,
                      v128);
                }
                __break(0x800u);
                _X9 = v41 + 8;
                __asm { PRFM            #0x11, [X9] }
                do
                {
                  v126 = __ldxr(_X9);
                  v127 = v126 - 1;
                }
                while ( __stlxr(v127, _X9) );
                __dmb(0xBu);
                if ( !v127 )
                  kfree(v41);
                if ( v129 )
                  dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v131, v129, v130, 0);
                v58 = -62;
              }
              goto LABEL_246;
            }
            v47 = 0;
            while ( v46 == -12 && v47 <= 9 )
            {
              v48 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v49 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v49 )
                {
                  ipc_log_string(
                    v49,
                    "ipa %s:%d failed to alloc memory retry cnt = %d\n",
                    "ipa3_tag_process",
                    11262,
                    v47);
                  v48 = ipa3_ctx;
                }
                v50 = *(_QWORD *)(v48 + 34160);
                if ( v50 )
                  ipc_log_string(
                    v50,
                    "ipa %s:%d failed to alloc memory retry cnt = %d\n",
                    "ipa3_tag_process",
                    11262,
                    v47);
              }
              ++v47;
              usleep_range_state(100000, 200000, 2);
              v46 = ipa3_send(v4, v39, (__int64)v15);
              if ( !v46 )
                goto LABEL_112;
            }
            v90 = v46;
            printk(&unk_3AD9CD, "ipa3_tag_process");
            v91 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v92 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v92 )
              {
                ipc_log_string(v92, "ipa %s:%d failed to send TAG packets %d\n", "ipa3_tag_process", 11270, v90);
                v91 = ipa3_ctx;
              }
              v93 = *(_QWORD *)(v91 + 34160);
              if ( v93 )
                ipc_log_string(v93, "ipa %s:%d failed to send TAG packets %d\n", "ipa3_tag_process", 11270, v90);
            }
            v58 = -12;
          }
          sk_skb_reason_drop(0, v43, 2);
        }
        else
        {
          printk(&unk_3CFD12, "ipa3_tag_process");
          v78 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_191;
          v79 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v79 )
          {
            ipc_log_string(v79, "ipa %s:%d failed to allocate memory\n", "ipa3_tag_process", 11235);
            v78 = ipa3_ctx;
          }
          v80 = *(_QWORD *)(v78 + 34160);
          if ( v80 )
          {
            ipc_log_string(v80, "ipa %s:%d failed to allocate memory\n", "ipa3_tag_process", 11235);
            v58 = -12;
          }
          else
          {
LABEL_191:
            v58 = -12;
          }
        }
        kfree(v41);
      }
      else
      {
        printk(&unk_3CF6DE, "ipa3_tag_process");
        v106 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v107 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v107 )
          {
            ipc_log_string(v107, "ipa %s:%d no mem\n", "ipa3_tag_process", 11223);
            v106 = ipa3_ctx;
          }
          v108 = *(_QWORD *)(v106 + 34160);
          if ( v108 )
            ipc_log_string(v108, "ipa %s:%d no mem\n", "ipa3_tag_process", 11223);
        }
        v58 = -12;
      }
      LODWORD(v7) = v39;
      goto LABEL_230;
    }
LABEL_216:
    _fortify_panic(15, v24, 104);
    v100 = v3;
    StatusReg = _ReadStatusReg(SP_EL0);
    v102 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ipa3_tag_process__alloc_tag;
    v15 = (char *)_kmalloc_cache_noprof(dma_alloc_attrs, 3520, 3848);
    *(_QWORD *)(StatusReg + 80) = v102;
    v3 = v100;
    if ( !v15 )
      goto LABEL_217;
  }
  printk(&unk_3A4719, "ipa3_tag_process");
  v75 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v76 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v76 )
    {
      ipc_log_string(v76, "ipa %s:%d failed to construct ip_packet_tag_status imm cmd\n", "ipa3_tag_process", 11212);
      v75 = ipa3_ctx;
    }
    v77 = *(_QWORD *)(v75 + 34160);
    if ( v77 )
      ipc_log_string(v77, "ipa %s:%d failed to construct ip_packet_tag_status imm cmd\n", "ipa3_tag_process", 11212);
  }
  v58 = -12;
  LODWORD(v7) = v7 + 1;
LABEL_230:
  if ( v3 >= (int)v7 )
    v109 = v7;
  else
    v109 = v3;
  v110 = v109 - v9;
  if ( v109 > (int)v9 )
  {
    v111 = 104LL * (int)v9;
    while ( (unsigned __int64)(v111 - 3808) >= 0xFFFFFFFFFFFFF0F8LL )
    {
      v112 = *(void (__fastcall **)(__int64, __int64))&v15[v111 + 40];
      if ( v112 )
      {
        if ( (unsigned __int64)(v111 - 3800) < 0xFFFFFFFFFFFFF0F8LL
          || (unsigned __int64)(v111 - 3792) < 0xFFFFFFFFFFFFF0F8LL )
        {
          break;
        }
        v113 = *(_QWORD *)&v15[v111 + 48];
        v114 = *(unsigned int *)&v15[v111 + 56];
        if ( *((_DWORD *)v112 - 1) != 1607364836 )
          __break(0x8228u);
        v112(v113, v114);
      }
      --v110;
      v111 += 104;
      if ( !v110 )
        goto LABEL_243;
    }
LABEL_247:
    __break(1u);
  }
LABEL_243:
  if ( v129 )
    dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v131, v129, v130, 0);
LABEL_245:
  kfree(v15);
LABEL_246:
  _ReadStatusReg(SP_EL0);
  return v58;
}
