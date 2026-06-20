__int64 _ipa_commit_hdr_v3_0()
{
  __int64 *v0; // x23
  __int64 v1; // x27
  char v2; // w8
  __int64 v3; // x9
  char v4; // w24
  __int64 v5; // x11
  unsigned int v6; // w19
  unsigned int v7; // w4
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 *v13; // x25
  __int64 v14; // x0
  __int64 v15; // x8
  int ep_mapping; // w0
  __int64 v17; // x8
  unsigned int v18; // w22
  __int64 v19; // x20
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  const char *v23; // x19
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x22
  __int64 v28; // x24
  __int64 v29; // x21
  unsigned int v30; // w19
  unsigned int v31; // w8
  int ep_reg_offset; // w0
  __int64 v33; // x0
  __int64 v34; // x10
  __int64 v35; // x0
  __int64 v36; // x0
  int v37; // w4
  unsigned int v38; // w9
  __int64 v39; // x0
  __int64 v40; // x23
  __int64 v41; // x20
  __int64 v42; // x28
  _QWORD *v43; // x9
  unsigned int v44; // w0
  __int64 v45; // x8
  unsigned int v46; // w10
  unsigned int v47; // w10
  __int64 v48; // x8
  __int64 v49; // x9
  _DWORD *v50; // x9
  unsigned int v51; // w23
  int v52; // w9
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  unsigned int v56; // w23
  unsigned int v57; // w0
  int v58; // w0
  __int64 v59; // x8
  __int64 v60; // x3
  __int64 v61; // x11
  int v62; // w9
  __int64 v63; // x10
  unsigned int v64; // w23
  int v65; // w19
  __int64 v66; // x2
  __int64 v67; // x0
  __int64 v68; // x3
  __int64 v69; // x10
  __int64 v70; // x11
  __int64 v71; // x8
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x8
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x0
  const char *v79; // x20
  __int64 v80; // x8
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x8
  __int64 v84; // x0
  __int64 v85; // x0
  __int64 v86; // x8
  __int64 v87; // x0
  __int64 v88; // x0
  __int64 v89; // x8
  __int64 v90; // x0
  __int64 v91; // x0
  __int64 v92; // x8
  __int64 v93; // x0
  __int64 v94; // x0
  __int64 v95; // x8
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 v99; // x8
  __int64 v100; // x0
  __int64 v101; // x0
  __int64 v102; // x8
  __int64 v103; // x0
  __int64 v104; // x0
  __int64 v105; // x8
  __int64 v106; // x0
  __int64 v107; // x0
  unsigned int v108; // [xsp+1Ch] [xbp-294h]
  unsigned __int64 v109; // [xsp+20h] [xbp-290h]
  unsigned int v110; // [xsp+28h] [xbp-288h]
  __int64 v111; // [xsp+40h] [xbp-270h]
  __int64 v112; // [xsp+48h] [xbp-268h] BYREF
  __int128 v113; // [xsp+50h] [xbp-260h] BYREF
  int v114; // [xsp+60h] [xbp-250h]
  __int64 v115; // [xsp+68h] [xbp-248h] BYREF
  unsigned __int64 v116; // [xsp+70h] [xbp-240h] BYREF
  __int64 v117; // [xsp+78h] [xbp-238h]
  int v118; // [xsp+80h] [xbp-230h]
  unsigned __int64 v119; // [xsp+88h] [xbp-228h] BYREF
  __int64 v120; // [xsp+90h] [xbp-220h]
  __int64 v121; // [xsp+98h] [xbp-218h]
  __int64 v122; // [xsp+A0h] [xbp-210h] BYREF
  __int64 v123; // [xsp+A8h] [xbp-208h]
  __int64 v124; // [xsp+B0h] [xbp-200h]
  __int64 v125; // [xsp+B8h] [xbp-1F8h]
  __int64 v126; // [xsp+C0h] [xbp-1F0h] BYREF
  __int64 v127; // [xsp+C8h] [xbp-1E8h]
  __int64 v128; // [xsp+D0h] [xbp-1E0h] BYREF
  __int64 v129; // [xsp+D8h] [xbp-1D8h]
  __int64 v130; // [xsp+E0h] [xbp-1D0h]
  __int64 v131; // [xsp+E8h] [xbp-1C8h] BYREF
  __int64 v132; // [xsp+F0h] [xbp-1C0h]
  __int64 v133; // [xsp+F8h] [xbp-1B8h]
  _QWORD s[54]; // [xsp+100h] [xbp-1B0h] BYREF

  v0 = &v128;
  s[52] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v132 = 0;
  v133 = 0;
  v130 = 0;
  v131 = 0;
  v128 = 0;
  v129 = 0;
  v126 = 0;
  v127 = 0;
  v124 = 0;
  v125 = 0;
  v122 = 0;
  v123 = 0;
  v120 = 0;
  v121 = 0;
  v119 = 0;
  v118 = 0;
  v116 = 0;
  v117 = 0;
  v115 = 0;
  v114 = 0;
  v113 = 0u;
  v112 = 0;
  memset(s, 0, 416);
  v1 = 0;
  v2 = 1;
  do
  {
    v3 = ipa3_ctx;
    v4 = v2;
    v5 = 156;
    if ( (v2 & 1) != 0 )
      v5 = 152;
    v6 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + v5);
    if ( v6 )
    {
      if ( *(_DWORD *)(ipa3_ctx + 216 * v1 + 28868) )
        v7 = *(_DWORD *)(ipa3_ctx + 216 * v1 + 28868);
      else
        v7 = 8;
      *((_DWORD *)v0 + 4) = v7;
      if ( v3 )
      {
        v8 = *(_QWORD *)(v3 + 34160);
        if ( v8 )
        {
          ipc_log_string(v8, "ipa %s:%d tbl_sz=%d\n", "ipa3_generate_hdr_hw_tbl", 37, v7);
          v3 = ipa3_ctx;
          v7 = *((_DWORD *)v0 + 4);
        }
      }
      v9 = dma_alloc_attrs(*(_QWORD *)(v3 + 34216), v7, v0 + 1, 3264, 0);
      *v0 = v9;
      if ( !v9 )
      {
        v10 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34216), *((unsigned int *)v0 + 4), v0 + 1, 2080, 0);
        *v0 = v10;
        if ( !v10 )
        {
          printk(&unk_3B73AF, "ipa3_generate_hdr_hw_tbl");
          v105 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v106 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v106 )
            {
              ipc_log_string(
                v106,
                "ipa %s:%d fail to alloc DMA buff of size %d\n",
                "ipa3_generate_hdr_hw_tbl",
                47,
                *((_DWORD *)v0 + 4));
              v105 = ipa3_ctx;
            }
            v107 = *(_QWORD *)(v105 + 34160);
            if ( v107 )
              ipc_log_string(
                v107,
                "ipa %s:%d fail to alloc DMA buff of size %d\n",
                "ipa3_generate_hdr_hw_tbl",
                47,
                *((_DWORD *)v0 + 4));
          }
LABEL_33:
          if ( (v4 & 1) != 0 )
            v23 = "SRAM";
          else
            v23 = (const char *)&unk_3C9BE0;
          printk(&unk_3E0FC8, "__ipa_commit_hdr_v3_0");
          v24 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v25 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v25 )
            {
              ipc_log_string(v25, "ipa %s:%d fail to generate %s HDR HW TBL\n", "__ipa_commit_hdr_v3_0", 217, v23);
              v24 = ipa3_ctx;
            }
            v26 = *(_QWORD *)(v24 + 34160);
            if ( v26 )
              ipc_log_string(v26, "ipa %s:%d fail to generate %s HDR HW TBL\n", "__ipa_commit_hdr_v3_0", 217, v23);
          }
LABEL_41:
          v19 = 0;
LABEL_42:
          v27 = 0;
          v28 = 0;
          v29 = 0;
          goto LABEL_159;
        }
      }
      v11 = ipa3_ctx;
      v12 = ipa3_ctx + 216 * v1;
      v13 = *(__int64 **)(v12 + 28656);
      while ( v13 != (__int64 *)(v12 + 28656) )
      {
        if ( v11 )
        {
          v14 = *(_QWORD *)(v11 + 34160);
          if ( v14 )
            ipc_log_string(
              v14,
              "ipa %s:%d hdr of len %d ofst=%d\n",
              "ipa3_generate_hdr_hw_tbl",
              53,
              *((_DWORD *)v13 + 69),
              *(_DWORD *)(v13[41] + 16));
        }
        v15 = v13[41];
        if ( !v15 || *((_DWORD *)v13 + 69) >= 0x81u )
        {
          if ( (unsigned int)__ratelimit(&ipa3_generate_hdr_hw_tbl__rs, "ipa3_generate_hdr_hw_tbl") )
            printk(&unk_3ACC50, "ipa3_generate_hdr_hw_tbl");
          v20 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v21 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v21 )
            {
              ipc_log_string(v21, "ipa %s:%d Invalid hdr entry\n", "ipa3_generate_hdr_hw_tbl", 57);
              v20 = ipa3_ctx;
            }
            v22 = *(_QWORD *)(v20 + 34160);
            if ( v22 )
              ipc_log_string(v22, "ipa %s:%d Invalid hdr entry\n", "ipa3_generate_hdr_hw_tbl", 57);
          }
          goto LABEL_33;
        }
        ipahal_cp_hdr_to_hw_buff(*v0, *(unsigned int *)(v15 + 16), (char *)v13 + 20);
        v13 = (__int64 *)*v13;
        v11 = ipa3_ctx;
        v12 = ipa3_ctx + 216 * v1;
      }
      if ( *((_DWORD *)v0 + 4) > v6 )
      {
        if ( (v4 & 1) != 0 )
          v79 = "SRAM";
        else
          v79 = (const char *)&unk_3C9BE0;
        printk(&unk_3EF1B8, "__ipa_commit_hdr_v3_0");
        v80 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v81 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v81 )
          {
            ipc_log_string(
              v81,
              "ipa %s:%d %s HDR tbl too big needed %d avail %d\n",
              "__ipa_commit_hdr_v3_0",
              224,
              v79,
              *((_DWORD *)v0 + 4),
              v6);
            v80 = ipa3_ctx;
          }
          v82 = *(_QWORD *)(v80 + 34160);
          if ( v82 )
            ipc_log_string(
              v82,
              "ipa %s:%d %s HDR tbl too big needed %d avail %d\n",
              "__ipa_commit_hdr_v3_0",
              224,
              v79,
              *((_DWORD *)v0 + 4),
              v6);
        }
        v19 = 0;
        v29 = 0;
        goto LABEL_140;
      }
    }
    v0 = &v131;
    v2 = 0;
    v1 = 1;
  }
  while ( (v4 & 1) != 0 );
  ep_mapping = ipa_get_ep_mapping(95);
  v17 = ipa3_ctx;
  if ( ep_mapping == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
  {
    v18 = 0;
    v19 = 0;
  }
  else
  {
    v30 = ipa_get_ep_mapping(95);
    BYTE12(v113) = 0;
    v31 = *(_DWORD *)(ipa3_ctx + 32240);
    v114 = 0;
    if ( v31 > 0x14 )
      ep_reg_offset = ipahal_get_ep_reg_offset(133, v30);
    else
      ep_reg_offset = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(44, 0, 0);
    LODWORD(v113) = ep_reg_offset;
    ipahal_get_aggr_force_close_valmask(v30, &v112);
    *(_QWORD *)((char *)&v113 + 4) = v112;
    v33 = ((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v113, 0);
    if ( !v33 )
    {
      printk(&unk_3AEDE8, "__ipa_commit_hdr_v3_0");
      v102 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v103 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v103 )
        {
          ipc_log_string(v103, "ipa %s:%d failed to construct coal close IC\n", "__ipa_commit_hdr_v3_0", 252);
          v102 = ipa3_ctx;
        }
        v104 = *(_QWORD *)(v102 + 34160);
        if ( v104 )
          ipc_log_string(v104, "ipa %s:%d failed to construct coal close IC\n", "__ipa_commit_hdr_v3_0", 252);
      }
      goto LABEL_41;
    }
    v19 = v33;
    ipa3_init_imm_cmd_desc(s, v33);
    v17 = ipa3_ctx;
    v18 = 1;
  }
  v34 = *(_QWORD *)(v17 + 34176);
  if ( *(_DWORD *)(*(_QWORD *)v34 + 152LL) )
  {
    *(_WORD *)((char *)&v124 + 1) = 0;
    HIDWORD(v124) = 0;
    v122 = v129;
    LODWORD(v123) = v130;
    HIDWORD(v123) = *(_DWORD *)(*(_QWORD *)v34 + 148LL) + *(unsigned __int16 *)(v17 + 29522);
    v35 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v122, 0);
    if ( !v35 )
    {
      printk(&unk_3A5FC7, "__ipa_commit_hdr_v3_0");
      v83 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v84 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v84 )
        {
          ipc_log_string(v84, "ipa %s:%d fail construct dma_shared_mem cmd\n", "__ipa_commit_hdr_v3_0", 272);
          v83 = ipa3_ctx;
        }
        v85 = *(_QWORD *)(v83 + 34160);
        if ( v85 )
          ipc_log_string(v85, "ipa %s:%d fail construct dma_shared_mem cmd\n", "__ipa_commit_hdr_v3_0", 272);
      }
      goto LABEL_42;
    }
    v29 = v35;
    ipa3_init_imm_cmd_desc(&s[13 * v18], v35);
    v17 = ipa3_ctx;
    ++v18;
    if ( *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 156LL) )
      goto LABEL_51;
  }
  else
  {
    v29 = 0;
    if ( *(_DWORD *)(*(_QWORD *)v34 + 156LL) )
    {
LABEL_51:
      v115 = v132;
      v36 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(6, &v115, 0);
      if ( !v36 )
      {
        printk(&unk_3C9BE4, "__ipa_commit_hdr_v3_0");
        v86 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v87 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v87 )
          {
            ipc_log_string(v87, "ipa %s:%d fail construct hdr_init_system cmd\n", "__ipa_commit_hdr_v3_0", 290);
            v86 = ipa3_ctx;
          }
          v88 = *(_QWORD *)(v86 + 34160);
          if ( v88 )
            ipc_log_string(v88, "ipa %s:%d fail construct hdr_init_system cmd\n", "__ipa_commit_hdr_v3_0", 290);
        }
LABEL_140:
        if ( v131 )
          dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v133, v131, v132, 0);
        v27 = 0;
        v28 = 0;
        goto LABEL_159;
      }
      v28 = v36;
      ipa3_init_imm_cmd_desc(&s[13 * v18], v36);
      v17 = ipa3_ctx;
      ++v18;
      goto LABEL_55;
    }
  }
  v28 = 0;
LABEL_55:
  v37 = *(_DWORD *)(v17 + 29172);
  v111 = v19;
  v38 = v37 + 8;
  if ( !v37 )
    v38 = 12;
  LODWORD(v127) = v38;
  if ( v17 )
  {
    v39 = *(_QWORD *)(v17 + 34160);
    if ( v39 )
    {
      ipc_log_string(v39, "ipa %s:%d tbl_sz=%d\n", "ipa3_generate_hdr_proc_ctx_hw_tbl", 151, v37);
      v17 = ipa3_ctx;
      v38 = v127;
    }
  }
  v40 = dma_alloc_attrs(*(_QWORD *)(v17 + 34216), v38, &v126, 3264, 0);
  v125 = v40;
  if ( !v40 )
  {
    v40 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v127, &v126, 2080, 0);
    v125 = v40;
    if ( !v40 )
    {
      printk(&unk_3B73AF, "ipa3_generate_hdr_proc_ctx_hw_tbl");
      v99 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v100 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v100 )
        {
          ipc_log_string(
            v100,
            "ipa %s:%d fail to alloc DMA buff of size %d\n",
            "ipa3_generate_hdr_proc_ctx_hw_tbl",
            161,
            v127);
          v99 = ipa3_ctx;
        }
        v101 = *(_QWORD *)(v99 + 34160);
        if ( v101 )
          ipc_log_string(
            v101,
            "ipa %s:%d fail to alloc DMA buff of size %d\n",
            "ipa3_generate_hdr_proc_ctx_hw_tbl",
            161,
            v127);
      }
      goto LABEL_110;
    }
  }
  v108 = v18;
  v110 = v127 - 8;
  v41 = ((v126 + 7) & 0xFFFFFFFFFFFFFFF8LL) - v126;
  v109 = (v126 + 7) & 0xFFFFFFFFFFFFFFF8LL;
  memset((void *)(v40 + v41), 0, (unsigned int)(v127 - 8));
  ((void (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(
    64,
    0,
    *(unsigned __int16 *)(ipa3_ctx + 29522) >> 2);
  v42 = ipa3_ctx + 29088;
  while ( 1 )
  {
    v42 = *(_QWORD *)v42;
    v43 = (_QWORD *)(ipa3_ctx + 34160);
    if ( v42 == ipa3_ctx + 29088 )
    {
      v19 = v111;
      v50 = **(_DWORD ***)(ipa3_ctx + 34176);
      if ( *(_BYTE *)(ipa3_ctx + 30408) == 1 )
      {
        v51 = v50[43];
        if ( v110 > v51 )
        {
          printk(&unk_3CFCA4, "__ipa_commit_hdr_v3_0");
          v89 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v90 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v90 )
            {
              ipc_log_string(v90, "ipa %s:%d tbl too big needed %d avail %d\n", "__ipa_commit_hdr_v3_0", 316, v110, v51);
              v89 = ipa3_ctx;
            }
            v91 = *(_QWORD *)(v89 + 34160);
            if ( v91 )
              ipc_log_string(v91, "ipa %s:%d tbl too big needed %d avail %d\n", "__ipa_commit_hdr_v3_0", 316, v110, v51);
          }
          goto LABEL_158;
        }
        *(_WORD *)((char *)&v121 + 1) = 0;
        HIDWORD(v121) = 0;
        v52 = v50[42];
        v119 = v109;
        LODWORD(v120) = v110;
        HIDWORD(v120) = v52 + *(unsigned __int16 *)(ipa3_ctx + 29522);
        v27 = ((__int64 (__fastcall *)(__int64, unsigned __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v119, 0);
        if ( !v27 )
        {
          printk(&unk_3A5FC7, "__ipa_commit_hdr_v3_0");
          v53 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v54 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v54 )
            {
              ipc_log_string(v54, "ipa %s:%d fail construct dma_shared_mem cmd\n", "__ipa_commit_hdr_v3_0", 331);
              v53 = ipa3_ctx;
            }
            v55 = *(_QWORD *)(v53 + 34160);
            if ( v55 )
              ipc_log_string(v55, "ipa %s:%d fail construct dma_shared_mem cmd\n", "__ipa_commit_hdr_v3_0", 331);
          }
          goto LABEL_158;
        }
      }
      else
      {
        v56 = v50[44];
        if ( v110 > v56 )
        {
          printk(&unk_3CC9C2, "__ipa_commit_hdr_v3_0");
          v92 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v93 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v93 )
            {
              ipc_log_string(
                v93,
                "ipa %s:%d tbl too big, needed %d avail %d\n",
                "__ipa_commit_hdr_v3_0",
                340,
                v110,
                v56);
              v92 = ipa3_ctx;
            }
            v94 = *(_QWORD *)(v92 + 34160);
            if ( v94 )
              ipc_log_string(
                v94,
                "ipa %s:%d tbl too big, needed %d avail %d\n",
                "__ipa_commit_hdr_v3_0",
                340,
                v110,
                v56);
          }
          goto LABEL_158;
        }
        BYTE4(v117) = 0;
        v118 = 0;
        v57 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(71, 0, 0);
        LODWORD(v117) = -8;
        v116 = __PAIR64__(v109, v57);
        v27 = ((__int64 (__fastcall *)(__int64, unsigned __int64 *, _QWORD))ipahal_construct_imm_cmd)(7, &v116, 0);
        if ( !v27 )
        {
          printk(&unk_3C317D, "__ipa_commit_hdr_v3_0");
          v95 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v96 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v96 )
            {
              ipc_log_string(v96, "ipa %s:%d fail construct register_write cmd\n", "__ipa_commit_hdr_v3_0", 356);
              v95 = ipa3_ctx;
            }
            v97 = *(_QWORD *)(v95 + 34160);
            if ( v97 )
              ipc_log_string(v97, "ipa %s:%d fail construct register_write cmd\n", "__ipa_commit_hdr_v3_0", 356);
          }
          goto LABEL_158;
        }
      }
      ipa3_init_imm_cmd_desc(&s[13 * v108], v27);
      v58 = ((__int64 (__fastcall *)(_QWORD, _QWORD *))ipa3_send_cmd)(v108 + 1, s);
      if ( v58 )
      {
        v65 = v58;
        printk(&unk_3CB958, "__ipa_commit_hdr_v3_0");
        v59 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v77 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v77 )
          {
            ipc_log_string(v77, "ipa %s:%d fail to send immediate command\n", "__ipa_commit_hdr_v3_0", 366);
            v59 = ipa3_ctx;
          }
          v78 = *(_QWORD *)(v59 + 34160);
          if ( v78 )
          {
            ipc_log_string(v78, "ipa %s:%d fail to send immediate command\n", "__ipa_commit_hdr_v3_0", 366);
            v59 = ipa3_ctx;
          }
        }
        v66 = v131;
        v64 = -14;
      }
      else
      {
        v59 = ipa3_ctx;
        if ( v131 )
        {
          v60 = *(_QWORD *)(ipa3_ctx + 30424);
          if ( v60 )
          {
            dma_free_attrs(
              *(_QWORD *)(ipa3_ctx + 34216),
              *(unsigned int *)(ipa3_ctx + 30432),
              *(_QWORD *)(ipa3_ctx + 30416),
              v60,
              0);
            v59 = ipa3_ctx;
          }
          v61 = v132;
          v62 = *(unsigned __int8 *)(v59 + 30408);
          *(_QWORD *)(v59 + 30416) = v131;
          v63 = v133;
          *(_QWORD *)(v59 + 30424) = v61;
          *(_QWORD *)(v59 + 30432) = v63;
          if ( v62 == 1 )
          {
            v64 = 0;
LABEL_95:
            v67 = *(_QWORD *)(v59 + 34216);
LABEL_98:
            dma_free_attrs(v67, (unsigned int)v127, v125, v126, 0);
            goto LABEL_160;
          }
LABEL_99:
          v68 = *(_QWORD *)(v59 + 30448);
          if ( v68 )
          {
            dma_free_attrs(*(_QWORD *)(v59 + 34216), *(unsigned int *)(v59 + 30456), *(_QWORD *)(v59 + 30440), v68, 0);
            v59 = ipa3_ctx;
          }
          v69 = v126;
          v64 = 0;
          v70 = v127;
          *(_QWORD *)(v59 + 30440) = v125;
          *(_QWORD *)(v59 + 30448) = v69;
          *(_QWORD *)(v59 + 30456) = v70;
          goto LABEL_160;
        }
        v65 = 0;
        v66 = 0;
        v64 = 0;
      }
      dma_free_attrs(*(_QWORD *)(v59 + 34216), (unsigned int)v133, v66, v132, 0);
      v59 = ipa3_ctx;
      if ( (*(_BYTE *)(ipa3_ctx + 30408) & 1) != 0 )
        goto LABEL_95;
      if ( v65 )
      {
        v67 = *(_QWORD *)(ipa3_ctx + 34216);
        goto LABEL_98;
      }
      goto LABEL_99;
    }
    if ( ipa3_ctx && *v43 )
      ipc_log_string(
        *v43,
        "ipa %s:%d processing type %d ofst=%d\n",
        "ipa3_hdr_proc_ctx_to_hw_format",
        88,
        *(_DWORD *)(v42 + 20),
        *(_DWORD *)(*(_QWORD *)(v42 + 56) + 16LL));
    if ( *(_BYTE *)(v42 + 36) )
    {
      v44 = ipa_get_ep_mapping(*(unsigned int *)(v42 + 40));
      if ( (v44 & 0x80000000) == 0 )
      {
        if ( v44 >= 0x24 )
          __break(0x5512u);
        v45 = ipa3_ctx + 480LL * v44;
        v46 = *(_DWORD *)(v42 + 32) & 0xFFFFFDFF | ((*(_DWORD *)(v45 + 340) & 1) << 9);
        *(_DWORD *)(v42 + 32) = v46;
        v47 = v46 & 0xFFFF03FF | ((*(_DWORD *)(v45 + 344) & 0x3F) << 10);
        *(_DWORD *)(v42 + 32) = v47;
        *(_DWORD *)(v42 + 32) = v47 & 0xFFFEFFFF | (((*(unsigned __int8 *)(v45 + 377) ^ 1) & 1) << 16);
      }
    }
    v48 = *(_QWORD *)(v42 + 64);
    if ( !v48 )
      break;
    if ( !*(_QWORD *)(v48 + 328) )
      break;
    v49 = *(_QWORD *)(v42 + 56);
    if ( !v49 || *(_DWORD *)(v48 + 276) >= 0x81u )
      break;
    if ( (unsigned int)ipahal_cp_proc_ctx_to_hw_buff(
                         *(unsigned int *)(v42 + 20),
                         v40 + v41,
                         *(unsigned int *)(v49 + 16)) )
      goto LABEL_109;
  }
  if ( (unsigned int)__ratelimit(&ipa3_hdr_proc_ctx_to_hw_format__rs, "ipa3_hdr_proc_ctx_to_hw_format") )
    printk(&unk_3C9C14, "ipa3_hdr_proc_ctx_to_hw_format");
  v71 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v72 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v72 )
    {
      ipc_log_string(v72, "ipa %s:%d Found invalid hdr entry\n", "ipa3_hdr_proc_ctx_to_hw_format", 111);
      v71 = ipa3_ctx;
    }
    v73 = *(_QWORD *)(v71 + 34160);
    if ( v73 )
      ipc_log_string(v73, "ipa %s:%d Found invalid hdr entry\n", "ipa3_hdr_proc_ctx_to_hw_format", 111);
  }
LABEL_109:
  dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v127, v125, v126, 0);
  v19 = v111;
LABEL_110:
  printk(&unk_3C6E52, "__ipa_commit_hdr_v3_0");
  v74 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v75 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v75 )
    {
      ipc_log_string(v75, "ipa %s:%d fail to generate HDR PROC CTX HW TBL\n", "__ipa_commit_hdr_v3_0", 306);
      v74 = ipa3_ctx;
    }
    v76 = *(_QWORD *)(v74 + 34160);
    if ( v76 )
      ipc_log_string(v76, "ipa %s:%d fail to generate HDR PROC CTX HW TBL\n", "__ipa_commit_hdr_v3_0", 306);
  }
LABEL_158:
  v27 = 0;
LABEL_159:
  v64 = -14;
LABEL_160:
  if ( v128 )
    dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v130, v128, v129, 0);
  if ( v19 )
    kfree(v19);
  if ( v27 )
    kfree(v27);
  if ( v28 )
    kfree(v28);
  if ( v29 )
    kfree(v29);
  _ReadStatusReg(SP_EL0);
  return v64;
}
