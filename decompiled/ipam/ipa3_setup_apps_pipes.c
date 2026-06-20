__int64 __fastcall ipa3_setup_apps_pipes(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x8
  __int64 v9; // x0
  unsigned int v10; // w0
  _QWORD *v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 (*v16)(void); // x8
  __int64 v17; // x0
  _QWORD *v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 (__fastcall *v21)(_QWORD); // x8
  __int64 v22; // x0
  _QWORD *v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 (__fastcall *v26)(_QWORD); // x8
  __int64 v27; // x0
  _QWORD *v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 (__fastcall *v31)(_QWORD); // x8
  __int64 v32; // x0
  _QWORD *v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 (__fastcall *v36)(_QWORD); // x8
  __int64 v37; // x0
  _QWORD *v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 (__fastcall *v41)(_QWORD); // x8
  __int64 is_ep_support_flt; // x0
  __int64 v43; // x8
  __int64 v44; // x0
  unsigned int v45; // w19
  __int64 v46; // x8
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x1
  __int64 v50; // x2
  __int64 v51; // x3
  __int64 v52; // x4
  __int64 v53; // x5
  __int64 v54; // x6
  __int64 v55; // x7
  __int64 v56; // x8
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  _QWORD *v60; // x9
  _DWORD *v61; // x9
  unsigned int v62; // w19
  unsigned int v63; // w10
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x19
  __int64 v67; // x0
  __int64 v68; // x20
  char ep_mapping; // w0
  int v70; // w8
  __int64 v71; // x8
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x8
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x1
  unsigned int v78; // w9
  __int64 v79; // x8
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 result; // x0
  __int64 v83; // x8
  __int64 v84; // x0
  __int64 v85; // x0
  __int64 v86; // x0
  __int64 v87; // x8
  __int64 v88; // x0
  __int64 v89; // x0
  __int64 v90; // x8
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 v93; // x8
  __int64 v94; // x0
  __int64 v95; // x0
  __int64 v96; // x8
  __int64 v97; // x0
  __int64 v98; // x0
  unsigned int v99; // w19
  __int64 v100; // x8
  __int64 v101; // x0
  __int64 v102; // x0
  __int64 v103; // x8
  __int64 v104; // x0
  __int64 v105; // x0
  __int64 v106; // x8
  __int64 v107; // x0
  __int64 v108; // x0
  __int64 v109; // x8
  __int64 v110; // x0
  __int64 v111; // x0
  __int64 v112; // x8
  __int64 v113; // x0
  __int64 v114; // x0
  unsigned int *v115; // x8
  __int64 v116; // x0
  __int64 v117; // x8
  __int64 v118; // x0
  __int64 v119; // x0
  __int64 v120; // x8
  __int64 v121; // x0
  __int64 v122; // x0
  __int64 v123; // x8
  __int64 v124; // x0
  __int64 v125; // x0
  __int64 v126; // [xsp+0h] [xbp-120h] BYREF
  __int64 v127; // [xsp+8h] [xbp-118h]
  __int64 v128; // [xsp+10h] [xbp-110h]
  __int64 v129; // [xsp+18h] [xbp-108h]
  __int64 v130; // [xsp+20h] [xbp-100h]
  __int64 v131; // [xsp+28h] [xbp-F8h]
  __int64 v132; // [xsp+30h] [xbp-F0h]
  __int64 v133; // [xsp+38h] [xbp-E8h]
  __int64 v134; // [xsp+40h] [xbp-E0h]
  __int64 v135; // [xsp+48h] [xbp-D8h]
  __int64 v136; // [xsp+50h] [xbp-D0h]
  __int64 v137; // [xsp+58h] [xbp-C8h]
  __int64 v138; // [xsp+60h] [xbp-C0h]
  __int64 v139; // [xsp+68h] [xbp-B8h]
  __int64 v140; // [xsp+70h] [xbp-B0h]
  __int64 v141; // [xsp+78h] [xbp-A8h]
  __int64 v142; // [xsp+80h] [xbp-A0h]
  __int64 v143; // [xsp+88h] [xbp-98h]
  __int64 v144; // [xsp+90h] [xbp-90h]
  __int64 v145; // [xsp+98h] [xbp-88h]
  __int64 v146; // [xsp+A0h] [xbp-80h]
  __int64 v147; // [xsp+A8h] [xbp-78h]
  __int64 v148; // [xsp+B0h] [xbp-70h]
  __int64 v149; // [xsp+B8h] [xbp-68h]
  __int64 v150; // [xsp+C0h] [xbp-60h]
  __int64 v151; // [xsp+C8h] [xbp-58h]
  __int64 (__fastcall *v152)(); // [xsp+D0h] [xbp-50h]
  __int64 v153; // [xsp+D8h] [xbp-48h]
  __int64 v154; // [xsp+E0h] [xbp-40h]
  __int64 v155; // [xsp+E8h] [xbp-38h]
  __int64 v156; // [xsp+F0h] [xbp-30h]
  __int64 v157; // [xsp+F8h] [xbp-28h]
  __int64 v158; // [xsp+100h] [xbp-20h] BYREF
  __int64 v159; // [xsp+108h] [xbp-18h]
  int v160; // [xsp+110h] [xbp-10h]
  int v161; // [xsp+114h] [xbp-Ch]
  __int64 v162; // [xsp+118h] [xbp-8h]

  v162 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = ipa3_ctx;
  v156 = 0;
  v157 = 0;
  v154 = 0;
  v155 = 0;
  v152 = nullptr;
  v153 = 0;
  v150 = 0;
  v151 = 0;
  v148 = 0;
  v149 = 0;
  v146 = 0;
  v147 = 0;
  v144 = 0;
  v145 = 0;
  v142 = 0;
  v143 = 0;
  v140 = 0;
  v141 = 0;
  v138 = 0;
  v139 = 0;
  v136 = 0;
  v137 = 0;
  v134 = 0;
  v135 = 0;
  v132 = 0;
  v133 = 0;
  v130 = 0;
  v131 = 0;
  v128 = 0;
  v129 = 0;
  v126 = 0;
  v127 = 0;
  if ( *(_BYTE *)(ipa3_ctx + 43309) == 1 )
  {
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d Allocating GSI physical channel 20\n", "ipa3_setup_apps_pipes", 6240);
        v8 = ipa3_ctx;
      }
      a1 = *(_QWORD *)(v8 + 34160);
      if ( a1 )
        a1 = ipc_log_string(a1, "ipa %s:%d Allocating GSI physical channel 20\n", "ipa3_setup_apps_pipes", 6240);
    }
    v10 = ipa_gsi_ch20_wa(
            a1,
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            v126,
            v127,
            v128,
            v129,
            v130,
            v131,
            v132,
            v133,
            v134,
            v135,
            v136,
            v137,
            v138,
            v139,
            v140,
            v141,
            v142,
            v143,
            v144,
            v145,
            v146,
            v147,
            v148,
            v149);
    if ( v10 )
    {
      v99 = v10;
      printk(&unk_3E05A6, "ipa3_setup_apps_pipes");
      v100 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_223;
      v101 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v101 )
      {
        ipc_log_string(v101, "ipa %s:%d ipa_gsi_ch20_wa failed %d\n", "ipa3_setup_apps_pipes", 6243, v99);
        v100 = ipa3_ctx;
      }
      v102 = *(_QWORD *)(v100 + 34160);
      if ( v102 )
      {
        ipc_log_string(v102, "ipa %s:%d ipa_gsi_ch20_wa failed %d\n", "ipa3_setup_apps_pipes", 6243, v99);
        result = v99;
      }
      else
      {
LABEL_223:
        result = v99;
      }
      goto LABEL_222;
    }
  }
  if ( (unsigned int)ipa3_alloc_common_event_ring() )
  {
    printk(&unk_3E05CD, "ipa3_setup_apps_pipes");
    v87 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v88 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v88 )
      {
        ipc_log_string(v88, "ipa %s:%d ipa3_alloc_common_event_ring failed.\n", "ipa3_setup_apps_pipes", 6250);
        v87 = ipa3_ctx;
      }
      v89 = *(_QWORD *)(v87 + 34160);
      if ( v89 )
        ipc_log_string(v89, "ipa %s:%d ipa3_alloc_common_event_ring failed.\n", "ipa3_setup_apps_pipes", 6250);
    }
    goto LABEL_221;
  }
  v149 = 0;
  v136 = 0;
  v150 = 0x80000000024LL;
  v151 = 0;
  v156 = 0;
  v157 = 0;
  v137 = 0x2100000003LL;
  v138 = 0;
  v154 = 0;
  v155 = 0;
  v152 = nullptr;
  v153 = 0;
  v147 = 0;
  v148 = 0;
  v145 = 0;
  v146 = 0;
  v143 = 0;
  v144 = 0;
  v141 = 0;
  v142 = 0;
  v139 = 0;
  v140 = 0;
  v134 = 0;
  v135 = 0;
  v132 = 0;
  v133 = 0;
  v130 = 0;
  v131 = 0;
  v128 = 0;
  v129 = 0;
  v126 = 0;
  v127 = 0;
  if ( (unsigned int)ipa_setup_sys_pipe(&v126, ipa3_ctx + 32036) )
  {
    printk(&unk_3A2B39, "ipa3_setup_apps_pipes");
    v90 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v91 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v91 )
      {
        ipc_log_string(v91, "ipa %s:%d :setup sys pipe (APPS_CMD_PROD) failed.\n", "ipa3_setup_apps_pipes", 6262);
        v90 = ipa3_ctx;
      }
      v92 = *(_QWORD *)(v90 + 34160);
      if ( v92 )
        ipc_log_string(v92, "ipa %s:%d :setup sys pipe (APPS_CMD_PROD) failed.\n", "ipa3_setup_apps_pipes", 6262);
    }
    goto LABEL_221;
  }
  v11 = (_QWORD *)ipa3_ctx;
  if ( ipa3_ctx )
  {
    v12 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d Apps to IPA cmd pipe is connected\n", "ipa3_setup_apps_pipes", 6266);
      v11 = (_QWORD *)ipa3_ctx;
    }
    v13 = v11[4270];
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d Apps to IPA cmd pipe is connected\n", "ipa3_setup_apps_pipes", 6266);
      v11 = (_QWORD *)ipa3_ctx;
    }
    if ( v11 )
    {
      v14 = v11[4269];
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d Will initialize SRAM\n", "ipa3_setup_apps_pipes", 6268);
        v11 = (_QWORD *)ipa3_ctx;
      }
      v15 = v11[4270];
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d Will initialize SRAM\n", "ipa3_setup_apps_pipes", 6268);
        v11 = (_QWORD *)ipa3_ctx;
      }
    }
  }
  v16 = *(__int64 (**)(void))(v11[4272] + 56LL);
  if ( *((_DWORD *)v16 - 1) != 1874538549 )
    __break(0x8228u);
  v17 = v16();
  v18 = (_QWORD *)ipa3_ctx;
  if ( ipa3_ctx )
  {
    v19 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v19 )
    {
      ipc_log_string(v19, "ipa %s:%d SRAM initialized\n", "ipa3_setup_apps_pipes", 6270);
      v18 = (_QWORD *)ipa3_ctx;
    }
    v17 = v18[4270];
    if ( v17 )
    {
      v17 = ipc_log_string(v17, "ipa %s:%d SRAM initialized\n", "ipa3_setup_apps_pipes", 6270);
      v18 = (_QWORD *)ipa3_ctx;
    }
    if ( v18 )
    {
      v20 = v18[4269];
      if ( v20 )
      {
        ipc_log_string(v20, "ipa %s:%d Will initialize HDR\n", "ipa3_setup_apps_pipes", 6272);
        v18 = (_QWORD *)ipa3_ctx;
      }
      v17 = v18[4270];
      if ( v17 )
      {
        v17 = ipc_log_string(v17, "ipa %s:%d Will initialize HDR\n", "ipa3_setup_apps_pipes", 6272);
        v18 = (_QWORD *)ipa3_ctx;
      }
    }
  }
  v21 = *(__int64 (__fastcall **)(_QWORD))(v18[4272] + 64LL);
  if ( *((_DWORD *)v21 - 1) != 1874538549 )
    __break(0x8228u);
  v22 = v21(v17);
  v23 = (_QWORD *)ipa3_ctx;
  if ( ipa3_ctx )
  {
    v24 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v24 )
    {
      ipc_log_string(v24, "ipa %s:%d HDR initialized\n", "ipa3_setup_apps_pipes", 6274);
      v23 = (_QWORD *)ipa3_ctx;
    }
    v22 = v23[4270];
    if ( v22 )
    {
      v22 = ipc_log_string(v22, "ipa %s:%d HDR initialized\n", "ipa3_setup_apps_pipes", 6274);
      v23 = (_QWORD *)ipa3_ctx;
    }
    if ( v23 )
    {
      v25 = v23[4269];
      if ( v25 )
      {
        ipc_log_string(v25, "ipa %s:%d Will initialize V4 RT\n", "ipa3_setup_apps_pipes", 6276);
        v23 = (_QWORD *)ipa3_ctx;
      }
      v22 = v23[4270];
      if ( v22 )
      {
        v22 = ipc_log_string(v22, "ipa %s:%d Will initialize V4 RT\n", "ipa3_setup_apps_pipes", 6276);
        v23 = (_QWORD *)ipa3_ctx;
      }
    }
  }
  v26 = *(__int64 (__fastcall **)(_QWORD))(v23[4272] + 72LL);
  if ( *((_DWORD *)v26 - 1) != 1874538549 )
    __break(0x8228u);
  v27 = v26(v22);
  v28 = (_QWORD *)ipa3_ctx;
  if ( ipa3_ctx )
  {
    v29 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v29 )
    {
      ipc_log_string(v29, "ipa %s:%d V4 RT initialized\n", "ipa3_setup_apps_pipes", 6278);
      v28 = (_QWORD *)ipa3_ctx;
    }
    v27 = v28[4270];
    if ( v27 )
    {
      v27 = ipc_log_string(v27, "ipa %s:%d V4 RT initialized\n", "ipa3_setup_apps_pipes", 6278);
      v28 = (_QWORD *)ipa3_ctx;
    }
    if ( v28 )
    {
      v30 = v28[4269];
      if ( v30 )
      {
        ipc_log_string(v30, "ipa %s:%d Will initialize V6 RT\n", "ipa3_setup_apps_pipes", 6280);
        v28 = (_QWORD *)ipa3_ctx;
      }
      v27 = v28[4270];
      if ( v27 )
      {
        v27 = ipc_log_string(v27, "ipa %s:%d Will initialize V6 RT\n", "ipa3_setup_apps_pipes", 6280);
        v28 = (_QWORD *)ipa3_ctx;
      }
    }
  }
  v31 = *(__int64 (__fastcall **)(_QWORD))(v28[4272] + 80LL);
  if ( *((_DWORD *)v31 - 1) != 1874538549 )
    __break(0x8228u);
  v32 = v31(v27);
  v33 = (_QWORD *)ipa3_ctx;
  if ( ipa3_ctx )
  {
    v34 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v34 )
    {
      ipc_log_string(v34, "ipa %s:%d V6 RT initialized\n", "ipa3_setup_apps_pipes", 6282);
      v33 = (_QWORD *)ipa3_ctx;
    }
    v32 = v33[4270];
    if ( v32 )
    {
      v32 = ipc_log_string(v32, "ipa %s:%d V6 RT initialized\n", "ipa3_setup_apps_pipes", 6282);
      v33 = (_QWORD *)ipa3_ctx;
    }
    if ( v33 )
    {
      v35 = v33[4269];
      if ( v35 )
      {
        ipc_log_string(v35, "ipa %s:%d Will initialize V4 FLT\n", "ipa3_setup_apps_pipes", 6284);
        v33 = (_QWORD *)ipa3_ctx;
      }
      v32 = v33[4270];
      if ( v32 )
      {
        v32 = ipc_log_string(v32, "ipa %s:%d Will initialize V4 FLT\n", "ipa3_setup_apps_pipes", 6284);
        v33 = (_QWORD *)ipa3_ctx;
      }
    }
  }
  v36 = *(__int64 (__fastcall **)(_QWORD))(v33[4272] + 88LL);
  if ( *((_DWORD *)v36 - 1) != 1874538549 )
    __break(0x8228u);
  v37 = v36(v32);
  v38 = (_QWORD *)ipa3_ctx;
  if ( ipa3_ctx )
  {
    v39 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v39 )
    {
      ipc_log_string(v39, "ipa %s:%d V4 FLT initialized\n", "ipa3_setup_apps_pipes", 6286);
      v38 = (_QWORD *)ipa3_ctx;
    }
    v37 = v38[4270];
    if ( v37 )
    {
      v37 = ipc_log_string(v37, "ipa %s:%d V4 FLT initialized\n", "ipa3_setup_apps_pipes", 6286);
      v38 = (_QWORD *)ipa3_ctx;
    }
    if ( v38 )
    {
      v40 = v38[4269];
      if ( v40 )
      {
        ipc_log_string(v40, "ipa %s:%d Will initialize V6 FLT\n", "ipa3_setup_apps_pipes", 6288);
        v38 = (_QWORD *)ipa3_ctx;
      }
      v37 = v38[4270];
      if ( v37 )
      {
        v37 = ipc_log_string(v37, "ipa %s:%d Will initialize V6 FLT\n", "ipa3_setup_apps_pipes", 6288);
        v38 = (_QWORD *)ipa3_ctx;
      }
    }
  }
  v41 = *(__int64 (__fastcall **)(_QWORD))(v38[4272] + 96LL);
  if ( *((_DWORD *)v41 - 1) != 1874538549 )
    __break(0x8228u);
  is_ep_support_flt = v41(v37);
  v43 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v44 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v44 )
    {
      ipc_log_string(v44, "ipa %s:%d V6 FLT initialized\n", "ipa3_setup_apps_pipes", 6290);
      v43 = ipa3_ctx;
    }
    is_ep_support_flt = *(_QWORD *)(v43 + 34160);
    if ( is_ep_support_flt )
    {
      is_ep_support_flt = ipc_log_string(
                            is_ep_support_flt,
                            "ipa %s:%d V6 FLT initialized\n",
                            "ipa3_setup_apps_pipes",
                            6290);
      v43 = ipa3_ctx;
    }
  }
  if ( (*(_BYTE *)(v43 + 32270) & 1) != 0 )
  {
LABEL_125:
    if ( (((__int64 (__fastcall *)(__int64))lan_coal_enabled)(is_ep_support_flt) & 1) == 0 )
    {
      v160 = 0;
      v158 = 0;
      v159 = 0;
      v65 = _kmalloc_cache_noprof(scnprintf, 3520, 312);
      v66 = v65;
      if ( v65 )
      {
        *(_WORD *)v65 = 257;
        strcpy((char *)(v65 + 4), "ipa_lan_hdr");
        *(_BYTE *)(v65 + 291) = 2;
        if ( (unsigned int)ipa_add_hdr(v65) )
        {
          printk(&unk_3BA92E, "ipa3_setup_exception_path");
          v103 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v104 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v104 )
            {
              ipc_log_string(v104, "ipa %s:%d fail to add exception hdr\n", "ipa3_setup_exception_path", 4554);
              v103 = ipa3_ctx;
            }
            v105 = *(_QWORD *)(v103 + 34160);
            if ( v105 )
              ipc_log_string(v105, "ipa %s:%d fail to add exception hdr\n", "ipa3_setup_exception_path", 4554);
          }
        }
        else if ( *(_DWORD *)(v66 + 304) )
        {
          printk(&unk_3BA92E, "ipa3_setup_exception_path");
          v106 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v107 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v107 )
            {
              ipc_log_string(v107, "ipa %s:%d fail to add exception hdr\n", "ipa3_setup_exception_path", 4560);
              v106 = ipa3_ctx;
            }
            v108 = *(_QWORD *)(v106 + 34160);
            if ( v108 )
              ipc_log_string(v108, "ipa %s:%d fail to add exception hdr\n", "ipa3_setup_exception_path", 4560);
          }
        }
        else
        {
          v67 = ipa3_id_find(*(unsigned int *)(v66 + 300));
          if ( v67 )
          {
            v68 = v67;
            *(_DWORD *)(ipa3_ctx + 30384) = *(_DWORD *)(v66 + 300);
            HIDWORD(v158) = ipa_get_ep_mapping(33);
            ep_mapping = ipa_get_ep_mapping(33);
            v70 = *(unsigned __int8 *)(v68 + 350);
            LOBYTE(v160) = ep_mapping;
            v161 = 1;
            LODWORD(v159) = v70 ^ 1;
            if ( !(unsigned int)ipa3_cfg_route(&v158) )
            {
              kfree(v66);
              goto LABEL_132;
            }
            printk(&unk_3BA92E, "ipa3_setup_exception_path");
            v109 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v110 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v110 )
              {
                ipc_log_string(v110, "ipa %s:%d fail to add exception hdr\n", "ipa3_setup_exception_path", 4582);
                v109 = ipa3_ctx;
              }
              v111 = *(_QWORD *)(v109 + 34160);
              if ( v111 )
                ipc_log_string(v111, "ipa %s:%d fail to add exception hdr\n", "ipa3_setup_exception_path", 4582);
            }
          }
          else
          {
            printk(&unk_3F197F, "ipa3_setup_exception_path");
            v123 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v124 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v124 )
              {
                ipc_log_string(
                  v124,
                  "ipa %s:%d fail to find internal hdr structure\n",
                  "ipa3_setup_exception_path",
                  4567);
                v123 = ipa3_ctx;
              }
              v125 = *(_QWORD *)(v123 + 34160);
              if ( v125 )
                ipc_log_string(
                  v125,
                  "ipa %s:%d fail to find internal hdr structure\n",
                  "ipa3_setup_exception_path",
                  4567);
            }
          }
        }
        kfree(v66);
      }
      printk(&unk_3E8E3F, "ipa3_setup_apps_pipes");
      v112 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v113 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v113 )
        {
          ipc_log_string(v113, "ipa %s:%d :fail to setup excp path\n", "ipa3_setup_apps_pipes", 6308);
          v112 = ipa3_ctx;
        }
        v114 = *(_QWORD *)(v112 + 34160);
        if ( v114 )
          ipc_log_string(v114, "ipa %s:%d :fail to setup excp path\n", "ipa3_setup_apps_pipes", 6308);
      }
      goto LABEL_214;
    }
LABEL_132:
    v71 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v72 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v72 )
      {
        ipc_log_string(v72, "ipa %s:%d Exception path was successfully set", "ipa3_setup_apps_pipes", 6312);
        v71 = ipa3_ctx;
      }
      v73 = *(_QWORD *)(v71 + 34160);
      if ( v73 )
        ipc_log_string(v73, "ipa %s:%d Exception path was successfully set", "ipa3_setup_apps_pipes", 6312);
    }
    if ( (unsigned int)ipa3_setup_dflt_rt_tables() )
    {
      printk(&unk_3F4988, "ipa3_setup_apps_pipes");
      v93 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v94 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v94 )
        {
          ipc_log_string(v94, "ipa %s:%d :fail to setup dflt routes\n", "ipa3_setup_apps_pipes", 6315);
          v93 = ipa3_ctx;
        }
        v95 = *(_QWORD *)(v93 + 34160);
        if ( v95 )
          ipc_log_string(v95, "ipa %s:%d :fail to setup dflt routes\n", "ipa3_setup_apps_pipes", 6315);
      }
      goto LABEL_214;
    }
    v74 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v75 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v75 )
      {
        ipc_log_string(v75, "ipa %s:%d default routing was set\n", "ipa3_setup_apps_pipes", 6319);
        v74 = ipa3_ctx;
      }
      v76 = *(_QWORD *)(v74 + 34160);
      if ( v76 )
      {
        ipc_log_string(v76, "ipa %s:%d default routing was set\n", "ipa3_setup_apps_pipes", 6319);
        v74 = ipa3_ctx;
      }
    }
    v77 = v74 + 32040;
    v78 = *(_DWORD *)(v74 + 32240);
    *(_DWORD *)(v74 + 32040) = 0;
    if ( v78 >= 0x18 && *(_BYTE *)(v74 + 32269) == 1 )
    {
      v151 = 0;
      v156 = 0;
      v157 = 0;
      v150 = 0x8000000007FLL;
      v154 = 0;
      v155 = 0;
      v148 = 0;
      v149 = 0;
      v146 = 0;
      v147 = 0;
      v144 = 0;
      v145 = 0;
      v142 = 0;
      v143 = 0;
      v140 = 0;
      v141 = 0;
      v138 = 0;
      v139 = 0;
      v136 = 0;
      v137 = 0;
      v134 = 0;
      v135 = 0;
      v132 = 0;
      v133 = 0;
      v130 = 0;
      v131 = 0;
      v128 = 0;
      v129 = 0;
      v126 = 0;
      v127 = 0;
      v153 = 0;
      v152 = ipa3_lan_coal_rx_cb;
      if ( *(_BYTE *)(v74 + 45390) == 1 )
        v154 = v74 + 48128;
      HIDWORD(v133) = 0;
      LOWORD(v134) = 1;
      LOBYTE(v133) = 0;
      v132 = 2;
      LODWORD(v145) = 0;
      *(_DWORD *)(v74 + 32048) = 0;
      if ( (unsigned int)ipa_setup_sys_pipe(&v126, v77) )
      {
        printk(&unk_3B46BB, "ipa3_setup_apps_pipes");
        v79 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v80 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v80 )
          {
            ipc_log_string(v80, "ipa %s:%d :setup sys pipe (LAN_COAL_CONS) failed.\n", "ipa3_setup_apps_pipes", 6352);
            v79 = ipa3_ctx;
          }
          v81 = *(_QWORD *)(v79 + 34160);
          if ( v81 )
            ipc_log_string(v81, "ipa %s:%d :setup sys pipe (LAN_COAL_CONS) failed.\n", "ipa3_setup_apps_pipes", 6352);
        }
        goto LABEL_214;
      }
    }
    else
    {
      v151 = 0;
      v156 = 0;
      v157 = 0;
      v150 = 0x80000000021LL;
      v154 = 0;
      v155 = 0;
      v148 = 0;
      v149 = 0;
      v146 = 0;
      v147 = 0;
      v144 = 0;
      v145 = 0;
      v142 = 0;
      v143 = 0;
      v140 = 0;
      v141 = 0;
      v138 = 0;
      v139 = 0;
      v136 = 0;
      v137 = 0;
      v134 = 0;
      v135 = 0;
      v132 = 0;
      v133 = 0;
      v130 = 0;
      v131 = 0;
      v128 = 0;
      v129 = 0;
      v126 = 0;
      v127 = 0;
      v153 = 0;
      v152 = ipa3_lan_rx_cb;
      if ( *(_BYTE *)(v74 + 45390) == 1 )
        v154 = v74 + 48128;
      HIDWORD(v127) = 2;
      LOWORD(v134) = 1;
      HIDWORD(v133) = 0;
      LOBYTE(v133) = 0;
      v132 = 2;
      LODWORD(v145) = 0;
      *(_DWORD *)(v74 + 32048) = 0;
      if ( (unsigned int)ipa_setup_sys_pipe(&v126, v77) )
      {
        printk(&unk_3DACA3, "ipa3_setup_apps_pipes");
        v96 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v97 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v97 )
          {
            ipc_log_string(v97, "ipa %s:%d :setup sys pipe (LAN_CONS) failed.\n", "ipa3_setup_apps_pipes", 6386);
            v96 = ipa3_ctx;
          }
          v98 = *(_QWORD *)(v96 + 34160);
          if ( v98 )
            ipc_log_string(v98, "ipa %s:%d :setup sys pipe (LAN_CONS) failed.\n", "ipa3_setup_apps_pipes", 6386);
        }
        goto LABEL_214;
      }
    }
    if ( (*(_BYTE *)(ipa3_ctx + 32260) & 1) != 0 )
    {
      result = 0;
    }
    else
    {
      v156 = 0;
      v157 = 0;
      v154 = 0;
      v155 = 0;
      v153 = 0;
      v151 = 0;
      v148 = 0;
      v149 = 0;
      v146 = 0;
      v147 = 0;
      v144 = 0;
      v145 = 0;
      v142 = 0;
      v143 = 0;
      v140 = 0;
      v141 = 0;
      v138 = 0;
      v139 = 0;
      v136 = 0;
      v137 = 0;
      v134 = 0;
      v135 = 0;
      v132 = 0;
      v133 = 0;
      v130 = 0;
      v131 = 0;
      v128 = 0;
      v129 = 0;
      v126 = 0;
      v127 = 0;
      v152 = nullptr;
      v150 = 0x100000000020LL;
      if ( *(_BYTE *)(ipa3_ctx + 51097) == 1 )
      {
        BYTE4(v148) = 1;
        HIDWORD(v127) = 22;
        LOBYTE(v136) = 1;
        LODWORD(v145) = 1;
        HIDWORD(v136) = 8;
      }
      result = ipa_setup_sys_pipe(&v126, ipa3_ctx + 32044);
      if ( (_DWORD)result )
      {
        printk(&unk_3DDC6B, "ipa3_setup_apps_pipes");
        v83 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v84 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v84 )
          {
            ipc_log_string(v84, "ipa %s:%d :setup sys pipe (LAN_PROD) failed.\n", "ipa3_setup_apps_pipes", 6409);
            v83 = ipa3_ctx;
          }
          v85 = *(_QWORD *)(v83 + 34160);
          if ( v85 )
          {
            ipc_log_string(v85, "ipa %s:%d :setup sys pipe (LAN_PROD) failed.\n", "ipa3_setup_apps_pipes", 6409);
            v83 = ipa3_ctx;
          }
        }
        v86 = *(unsigned int *)(v83 + 32040);
        if ( (_DWORD)v86 )
          ipa_teardown_sys_pipe(
            v86,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v126,
            v127,
            v128,
            v129,
            v130,
            v131,
            v132,
            v133,
            v134,
            v135,
            v136,
            v137,
            v138,
            v139,
            v140,
            v141,
            v142,
            v143,
            v144,
            v145,
            v146,
            v147,
            v148,
            v149);
        goto LABEL_214;
      }
    }
    goto LABEL_222;
  }
  *(_DWORD *)((char *)&v158 + 3) = 0;
  LODWORD(v158) = 0;
  if ( *(_DWORD *)(v43 + 34308) )
  {
    v45 = 0;
    do
    {
      is_ep_support_flt = ipa_is_ep_support_flt(v45);
      if ( (is_ep_support_flt & 1) != 0 )
      {
        is_ep_support_flt = ipa_is_modem_pipe(v45);
        if ( (is_ep_support_flt & 1) == 0 )
        {
          is_ep_support_flt = ipa3_set_flt_tuple_mask(v45, &v158);
          if ( (_DWORD)is_ep_support_flt )
          {
            printk(&unk_3D20B9, "ipa3_setup_flt_hash_tuple");
            v46 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v47 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v47 )
              {
                ipc_log_string(
                  v47,
                  "ipa %s:%d failed to setup pipe %d flt tuple\n",
                  "ipa3_setup_flt_hash_tuple",
                  6197,
                  v45);
                v46 = ipa3_ctx;
              }
              v48 = *(_QWORD *)(v46 + 34160);
              if ( v48 )
                ipc_log_string(
                  v48,
                  "ipa %s:%d failed to setup pipe %d flt tuple\n",
                  "ipa3_setup_flt_hash_tuple",
                  6197,
                  v45);
            }
            printk(&unk_3A6163, "ipa3_setup_apps_pipes");
            v56 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v57 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v57 )
              {
                ipc_log_string(v57, "ipa %s:%d :fail to configure flt hash tuple\n", "ipa3_setup_apps_pipes", 6294);
                v56 = ipa3_ctx;
              }
              v58 = *(_QWORD *)(v56 + 34160);
              if ( v58 )
                ipc_log_string(v58, "ipa %s:%d :fail to configure flt hash tuple\n", "ipa3_setup_apps_pipes", 6294);
            }
            goto LABEL_214;
          }
        }
      }
      v43 = ipa3_ctx;
      ++v45;
    }
    while ( v45 < *(_DWORD *)(ipa3_ctx + 34308) );
  }
  if ( v43 )
  {
    v59 = *(_QWORD *)(v43 + 34152);
    if ( v59 )
    {
      ipc_log_string(v59, "ipa %s:%d flt hash tuple is configured\n", "ipa3_setup_apps_pipes", 6298);
      v43 = ipa3_ctx;
    }
    is_ep_support_flt = *(_QWORD *)(v43 + 34160);
    if ( is_ep_support_flt )
    {
      is_ep_support_flt = ipc_log_string(
                            is_ep_support_flt,
                            "ipa %s:%d flt hash tuple is configured\n",
                            "ipa3_setup_apps_pipes",
                            6298);
      v43 = ipa3_ctx;
    }
  }
  *(_DWORD *)((char *)&v158 + 3) = 0;
  v60 = *(_QWORD **)(v43 + 34176);
  LODWORD(v158) = 0;
  v61 = (_DWORD *)*v60;
  if ( !(v61[13] | v61[24]) )
  {
LABEL_120:
    if ( v43 )
    {
      v64 = *(_QWORD *)(v43 + 34152);
      if ( v64 )
      {
        ipc_log_string(v64, "ipa %s:%d rt hash tuple is configured\n", "ipa3_setup_apps_pipes", 6305);
        v43 = ipa3_ctx;
      }
      is_ep_support_flt = *(_QWORD *)(v43 + 34160);
      if ( is_ep_support_flt )
        is_ep_support_flt = ipc_log_string(
                              is_ep_support_flt,
                              "ipa %s:%d rt hash tuple is configured\n",
                              "ipa3_setup_apps_pipes",
                              6305);
    }
    goto LABEL_125;
  }
  v62 = 0;
  while ( 1 )
  {
    if ( v62 >= v61[14] && v62 <= v61[15] || v62 >= v61[25] && v62 <= v61[26] )
      goto LABEL_111;
    is_ep_support_flt = ipa3_set_rt_tuple_mask(v62, &v158);
    if ( (_DWORD)is_ep_support_flt )
      break;
    v43 = ipa3_ctx;
LABEL_111:
    ++v62;
    v61 = **(_DWORD ***)(v43 + 34176);
    v63 = v61[24];
    if ( v63 <= v61[13] )
      v63 = v61[13];
    if ( v62 >= v63 )
      goto LABEL_120;
  }
  printk(&unk_3D7EAA, "ipa3_setup_rt_hash_tuple");
  v117 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v118 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v118 )
    {
      ipc_log_string(v118, "ipa %s:%d failed to setup tbl %d rt tuple\n", "ipa3_setup_rt_hash_tuple", 6226, v62);
      v117 = ipa3_ctx;
    }
    v119 = *(_QWORD *)(v117 + 34160);
    if ( v119 )
      ipc_log_string(v119, "ipa %s:%d failed to setup tbl %d rt tuple\n", "ipa3_setup_rt_hash_tuple", 6226, v62);
  }
  printk(&unk_3F7382, "ipa3_setup_apps_pipes");
  v120 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v121 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v121 )
    {
      ipc_log_string(v121, "ipa %s:%d :fail to configure rt hash tuple\n", "ipa3_setup_apps_pipes", 6301);
      v120 = ipa3_ctx;
    }
    v122 = *(_QWORD *)(v120 + 34160);
    if ( v122 )
      ipc_log_string(v122, "ipa %s:%d :fail to configure rt hash tuple\n", "ipa3_setup_apps_pipes", 6301);
  }
LABEL_214:
  v115 = (unsigned int *)ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 30392) )
  {
    _ipa3_del_rt_rule();
    v115 = (unsigned int *)ipa3_ctx;
  }
  if ( v115[7597] )
  {
    _ipa3_del_rt_rule();
    v115 = (unsigned int *)ipa3_ctx;
  }
  v116 = v115[7596];
  if ( (_DWORD)v116 )
  {
    _ipa3_del_hdr(v116, 0);
    v115 = (unsigned int *)ipa3_ctx;
  }
  ipa_teardown_sys_pipe(
    v115[8009],
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v126,
    v127,
    v128,
    v129,
    v130,
    v131,
    v132,
    v133,
    v134,
    v135,
    v136,
    v137,
    v138,
    v139,
    v140,
    v141,
    v142,
    v143,
    v144,
    v145,
    v146,
    v147,
    v148,
    v149);
LABEL_221:
  result = 0xFFFFFFFFLL;
LABEL_222:
  _ReadStatusReg(SP_EL0);
  return result;
}
