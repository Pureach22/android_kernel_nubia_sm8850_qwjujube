__int64 __fastcall ipclite_init_v0(__int64 a1)
{
  __int64 v2; // x20
  _QWORD *v3; // x0
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x4
  __int64 v7; // x5
  __int64 v8; // x6
  __int64 v9; // x7
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x7
  unsigned int id; // w22
  __int64 v16; // x0
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  char v23; // w8
  int v24; // w0
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 v27; // x4
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  int variable_u32_array; // w0
  __int64 v32; // x25
  __int64 v33; // x23
  __int64 v34; // x0
  int v35; // w8
  __int64 v36; // x0
  unsigned int v37; // w0
  const char *v38; // x0
  const char *v39; // x0
  __int64 next_available_child; // x0
  const void *v42; // x22
  _QWORD *v43; // x0
  _QWORD *v44; // x25
  const char **v45; // x8
  const char *v46; // x2
  __int64 v47; // x3
  __int64 v48; // x4
  __int64 v49; // x5
  __int64 v50; // x6
  __int64 v51; // x7
  __int64 *v52; // x8
  __int64 v53; // x2
  int v54; // w0
  __int64 v55; // x2
  __int64 v56; // x3
  __int64 v57; // x4
  __int64 v58; // x5
  __int64 v59; // x6
  __int64 v60; // x7
  int v61; // w27
  int v62; // w0
  __int64 v63; // x4
  __int64 v64; // x5
  __int64 v65; // x6
  __int64 v66; // x7
  __int64 v67; // x23
  __int64 v68; // x0
  __int64 v69; // x3
  __int64 v70; // x4
  __int64 v71; // x5
  __int64 v72; // x6
  __int64 v73; // x7
  unsigned __int64 v74; // x27
  __int64 v75; // x15
  __int64 v76; // x26
  __int64 v77; // x8
  _DWORD *v78; // x11
  _DWORD *v79; // x26
  __int64 v80; // x27
  __int64 v81; // x27
  __int64 v82; // x13
  bool v83; // zf
  __int64 v84; // x8
  __int64 v85; // x9
  int v86; // w8
  __int64 v87; // x9
  __int64 v88; // x10
  __int64 v89; // x8
  _DWORD *v90; // x9
  char *v91; // x12
  _DWORD *v92; // x8
  __int64 v93; // x12
  int v94; // w13
  __int64 v95; // x9
  __int64 v96; // x8
  __int64 v97; // x0
  __int64 v98; // x3
  __int64 v99; // x4
  __int64 v100; // x5
  __int64 v101; // x6
  __int64 v102; // x7
  const void *v103; // x27
  __int64 v104; // x2
  __int64 v105; // x3
  __int64 v106; // x4
  __int64 v107; // x5
  __int64 v108; // x6
  __int64 v109; // x7
  unsigned int v110; // w26
  _QWORD *v111; // x0
  _QWORD *v112; // x23
  const char **v113; // x8
  const char *v114; // x2
  __int64 v115; // x3
  __int64 v116; // x4
  __int64 v117; // x5
  __int64 v118; // x6
  __int64 v119; // x7
  __int64 *v120; // x8
  __int64 v121; // x2
  int v122; // w0
  __int64 v123; // x2
  __int64 v124; // x3
  __int64 v125; // x4
  __int64 v126; // x5
  __int64 v127; // x6
  __int64 v128; // x7
  int v129; // w0
  __int64 v130; // x2
  __int64 v131; // x3
  __int64 v132; // x4
  __int64 v133; // x5
  __int64 v134; // x6
  __int64 v135; // x7
  __int64 v136; // x4
  __int64 v137; // x26
  __int64 v138; // x0
  char v139; // w8
  char v140; // w8
  const char *v141; // x0
  char v142; // w8
  unsigned int v143; // w0
  __int64 v144; // x4
  __int64 v145; // x5
  __int64 v146; // x6
  __int64 v147; // x7
  unsigned int v148; // w8
  int v149; // w0
  __int64 v150; // x2
  __int64 v151; // x3
  __int64 v152; // x4
  __int64 v153; // x5
  __int64 v154; // x6
  __int64 v155; // x7
  __int64 v156; // x8
  __int64 v157; // x8
  __int64 v158; // x26
  __int64 v159; // x27
  unsigned int inited; // w0
  unsigned int v161; // w0
  unsigned __int64 StatusReg; // x21
  __int64 v163; // x22
  char v164; // [xsp+0h] [xbp-F0h]
  __int64 v165; // [xsp+18h] [xbp-D8h]
  __int64 v166; // [xsp+20h] [xbp-D0h]
  const void *v167; // [xsp+20h] [xbp-D0h]
  __int64 v168; // [xsp+20h] [xbp-D0h]
  unsigned int v169; // [xsp+2Ch] [xbp-C4h] BYREF
  __int64 v170; // [xsp+30h] [xbp-C0h] BYREF
  __int64 v171; // [xsp+38h] [xbp-B8h]
  __int64 v172; // [xsp+40h] [xbp-B0h]
  __int64 v173; // [xsp+48h] [xbp-A8h]
  __int64 v174; // [xsp+50h] [xbp-A0h]
  __int64 v175; // [xsp+58h] [xbp-98h]
  __int64 v176; // [xsp+60h] [xbp-90h]
  __int64 v177; // [xsp+68h] [xbp-88h]
  __int64 v178; // [xsp+70h] [xbp-80h]
  __int64 v179; // [xsp+78h] [xbp-78h]
  __int64 v180; // [xsp+80h] [xbp-70h]
  __int64 v181; // [xsp+88h] [xbp-68h]
  _QWORD v182[12]; // [xsp+90h] [xbp-60h] BYREF

  v182[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v3 = (_QWORD *)_kmalloc_cache_noprof(of_get_next_available_child, 3520, 6472);
  while ( 1 )
  {
    ipclite = (__int64)v3;
    if ( !v3 )
    {
      if ( (ipclite_debug_level & 1) != 0 )
      {
        if ( (ipclite_debug_control & 1) != 0 )
        {
          printk(&unk_1133F, "ipclite", "ipclite_init_v0");
          if ( (ipclite_debug_control & 4) == 0 )
            goto LABEL_46;
        }
        else if ( (ipclite_debug_control & 4) == 0 )
        {
          goto LABEL_46;
        }
        ipclite_inmem_log("APPS:%s:IPCLite Memory Allocation Failed\n", (__int64)"ERR", v4, v5, v6, v7, v8, v9, v164);
        id = -12;
        goto LABEL_78;
      }
LABEL_46:
      id = -12;
      goto LABEL_78;
    }
    *v3 = a1 + 16;
    id = of_hwspin_lock_get_id(v2, 0);
    if ( (id & 0x80000000) != 0 )
    {
      if ( id != -517 )
        dev_err(a1 + 16, "failed to retrieve hwlock\n");
      goto LABEL_77;
    }
    if ( (ipclite_debug_level & 0x10) != 0 )
    {
      if ( (ipclite_debug_control & 1) == 0 )
      {
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_8;
LABEL_7:
        ipclite_inmem_log(
          "APPS:%s:Hwlock id retrieved, hwlock_id=%d\n",
          (__int64)"LOW",
          id,
          v10,
          v11,
          v12,
          v13,
          v14,
          v164);
        goto LABEL_8;
      }
      printk(&unk_F0BE, "ipclite", "ipclite_init_v0");
      if ( (ipclite_debug_control & 4) != 0 )
        goto LABEL_7;
    }
LABEL_8:
    v16 = hwspin_lock_request_specific(id);
    v23 = ipclite_debug_level;
    *(_QWORD *)(ipclite + 6456) = v16;
    if ( !v16 )
    {
      if ( (v23 & 1) != 0 )
      {
        if ( (ipclite_debug_control & 1) != 0 )
        {
          printk(&unk_EDD0, "ipclite", "ipclite_init_v0");
          if ( (ipclite_debug_control & 4) == 0 )
            goto LABEL_52;
        }
        else if ( (ipclite_debug_control & 4) == 0 )
        {
          goto LABEL_52;
        }
        ipclite_inmem_log("APPS:%s:Failed to assign hwlock_id\n", (__int64)"ERR", v17, v18, v19, v20, v21, v22, v164);
        id = -6;
        goto LABEL_77;
      }
LABEL_52:
      id = -6;
LABEL_77:
      kfree(ipclite);
      ipclite = 0;
      goto LABEL_78;
    }
    if ( (v23 & 0x10) == 0 )
      goto LABEL_13;
    if ( (ipclite_debug_control & 1) == 0 )
    {
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_13;
LABEL_12:
      ipclite_inmem_log(
        "APPS:%s:Hwlock id assigned successfully, hwlock=%p\n",
        (__int64)"LOW",
        *(_QWORD *)(ipclite + 6456),
        v18,
        v19,
        v20,
        v21,
        v22,
        v164);
      goto LABEL_13;
    }
    printk(&unk_EBAC, "ipclite", "ipclite_init_v0");
    if ( (ipclite_debug_control & 4) != 0 )
      goto LABEL_12;
LABEL_13:
    _mutex_init(&ssr_mutex, "&ssr_mutex", &ipclite_init_v0___key);
    LODWORD(v170) = 0;
    LODWORD(v182[0]) = 0;
    v24 = of_property_read_variable_u32_array(v2, "feature_mask_low", &v170, 1, 0);
    if ( v24 < 0 )
    {
      id = v24 & (v24 >> 31);
      if ( (ipclite_debug_level & 1) == 0 )
        goto LABEL_62;
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_E89F, "ipclite", "ipclite_feature_setup");
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_62;
      }
      else if ( (ipclite_debug_control & 4) == 0 )
      {
        goto LABEL_62;
      }
      v39 = "APPS:%s:failed to parse feature_mask_low\n";
LABEL_61:
      ipclite_inmem_log(v39, (__int64)"ERR", v25, v26, v27, v28, v29, v30, v164);
      goto LABEL_62;
    }
    variable_u32_array = of_property_read_variable_u32_array(v2, "feature_mask_high", v182, 1, 0);
    if ( variable_u32_array < 0 )
    {
      id = variable_u32_array & (variable_u32_array >> 31);
      if ( (ipclite_debug_level & 1) == 0 )
        goto LABEL_62;
      if ( (ipclite_debug_control & 1) == 0 )
      {
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_62;
        goto LABEL_60;
      }
      printk(&unk_11165, "ipclite", "ipclite_feature_setup");
      if ( (ipclite_debug_control & 4) != 0 )
      {
LABEL_60:
        v39 = "APPS:%s:failed to parse feature_mask_high\n";
        goto LABEL_61;
      }
LABEL_62:
      if ( (ipclite_debug_level & 1) == 0 )
        goto LABEL_76;
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_10E44, "ipclite", "ipclite_init_v0");
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_76;
      }
      else if ( (ipclite_debug_control & 4) == 0 )
      {
        goto LABEL_76;
      }
      v38 = "APPS:%s:IPCLite Features Setup Failed\n";
      goto LABEL_75;
    }
    feature_mask = (unsigned int)v170 | ((unsigned __int64)LODWORD(v182[0]) << 32);
    if ( (v170 & 1) == 0 && (ipclite_debug_level & 4) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_11194, "ipclite", "ipclite_feature_setup");
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_20;
LABEL_19:
        ipclite_inmem_log(
          "APPS:%s:IPCLite Global Atomic Support Disabled\n",
          (__int64)"INFO",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v164);
        goto LABEL_20;
      }
      if ( (ipclite_debug_control & 4) != 0 )
        goto LABEL_19;
    }
LABEL_20:
    if ( (feature_mask & 2) == 0 && (ipclite_debug_level & 4) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_F851, "ipclite", "ipclite_feature_setup");
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_25;
LABEL_24:
        ipclite_inmem_log("APPS:%s:IPCLite Test Suite Disabled\n", (__int64)"INFO", v25, v26, v27, v28, v29, v30, v164);
        goto LABEL_25;
      }
      if ( (ipclite_debug_control & 4) != 0 )
        goto LABEL_24;
    }
LABEL_25:
    if ( (feature_mask & 4) == 0 && (ipclite_debug_level & 4) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_10006, "ipclite", "ipclite_feature_setup");
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_30;
LABEL_29:
        ipclite_inmem_log(
          "APPS:%s:IPCLite Atomic Support Disabled\n",
          (__int64)"INFO",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v164);
        goto LABEL_30;
      }
      if ( (ipclite_debug_control & 4) != 0 )
        goto LABEL_29;
    }
LABEL_30:
    v32 = ipclite;
    v180 = 0;
    v181 = 0;
    v178 = 0;
    v179 = 0;
    v176 = 0;
    v177 = 0;
    v174 = 0;
    v175 = 0;
    v172 = 0;
    v173 = 0;
    v170 = 0;
    v171 = 0;
    v33 = *(_QWORD *)ipclite;
    v34 = *(_QWORD *)(*(_QWORD *)ipclite + 744LL);
    memset(v182, 0, 80);
    if ( (unsigned int)_of_parse_phandle_with_args(v34, "memory-region", 0, 0, 0, v182) || !v182[0] )
    {
      if ( (ipclite_debug_level & 1) == 0 )
        goto LABEL_70;
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_F0ED, "ipclite", "map_ipcmem");
        if ( (ipclite_debug_control & 4) == 0 )
        {
LABEL_70:
          id = -22;
LABEL_71:
          if ( (ipclite_debug_level & 1) == 0 )
            goto LABEL_76;
          goto LABEL_72;
        }
      }
      else if ( (ipclite_debug_control & 4) == 0 )
      {
        goto LABEL_70;
      }
      ipclite_inmem_log(
        "APPS:%s:No %s specified\n",
        (__int64)"ERR",
        (__int64)"memory-region",
        v26,
        v27,
        v28,
        v29,
        v30,
        v164);
      goto LABEL_70;
    }
    id = of_address_to_resource(v182[0], 0, &v170);
    if ( id )
      goto LABEL_71;
    v35 = v171 - v170;
    *(_QWORD *)(v32 + 6392) = v170;
    *(_DWORD *)(v32 + 6408) = v35 + 1;
    v36 = devm_ioremap_wc(v33);
    *(_QWORD *)(v32 + 6400) = v36;
    if ( !v36 )
    {
      id = -12;
      if ( (ipclite_debug_level & 1) == 0 )
        goto LABEL_76;
LABEL_72:
      if ( (ipclite_debug_control & 1) == 0 )
      {
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_76;
LABEL_74:
        v38 = "APPS:%s:failed to map ipcmem\n";
LABEL_75:
        ipclite_inmem_log(v38, (__int64)"ERR", v25, v26, v27, v28, v29, v30, v164);
        goto LABEL_76;
      }
      printk(&unk_F62C, "ipclite", "ipclite_init_v0");
      if ( (ipclite_debug_control & 4) != 0 )
        goto LABEL_74;
LABEL_76:
      hwspin_lock_free(*(_QWORD *)(ipclite + 6456));
      goto LABEL_77;
    }
    if ( (ipclite_debug_level & 0x10) == 0 )
      goto LABEL_38;
    if ( (ipclite_debug_control & 1) == 0 )
    {
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_38;
LABEL_37:
      ipclite_inmem_log(
        "APPS:%s:aux_base = %llu, size=%d,virt_base=%p\n",
        (__int64)"LOW",
        *(_QWORD *)(v32 + 6392),
        *(unsigned int *)(v32 + 6408),
        *(_QWORD *)(v32 + 6400),
        v28,
        v29,
        v30,
        v164);
      goto LABEL_38;
    }
    printk(&unk_113F4, "ipclite", "map_ipcmem");
    if ( (ipclite_debug_control & 4) != 0 )
      goto LABEL_37;
LABEL_38:
    memset(*(void **)(ipclite + 6400), 0, *(unsigned int *)(ipclite + 6408));
    v37 = ipcmem_init(ipclite + 6344, v2);
    if ( v37 )
    {
      id = v37;
      if ( (ipclite_debug_level & 1) == 0 )
        goto LABEL_76;
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_FA01, "ipclite", "ipclite_init_v0");
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_76;
      }
      else if ( (ipclite_debug_control & 4) == 0 )
      {
        goto LABEL_76;
      }
      v38 = "APPS:%s:Failed to set up IPCMEM";
      goto LABEL_75;
    }
    next_available_child = of_get_next_available_child(v2, 0);
    if ( !next_available_child )
      break;
    v42 = (const void *)next_available_child;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v169 = 0;
      v43 = (_QWORD *)_kmalloc_cache_noprof(dev_err, 3520, 912);
      v44 = v43;
      if ( !v43 )
        goto LABEL_94;
      v45 = *(const char ***)(a1 + 112);
      v43[12] = a1 + 16;
      v43[93] = v42;
      v43[101] = ipclite_device_release;
      v46 = v45[14];
      if ( !v46 )
        v46 = *v45;
      dev_set_name(v43, "%s:%pOFn", v46, v42);
      if ( (ipclite_debug_level & 0x10) != 0 )
      {
        if ( (ipclite_debug_control & 1) != 0 )
        {
          printk(&unk_F164, "ipclite", "ipclite_channel_init");
          if ( (ipclite_debug_control & 4) == 0 )
            goto LABEL_104;
        }
        else if ( (ipclite_debug_control & 4) == 0 )
        {
          goto LABEL_104;
        }
        v52 = *(__int64 **)(a1 + 112);
        v53 = v52[14];
        if ( !v53 )
          v53 = *v52;
        ipclite_inmem_log("APPS:%s:Registering %s device\n", (__int64)"LOW", v53, v47, v48, v49, v50, v51, v164);
      }
LABEL_104:
      v54 = device_register(v44);
      if ( v54 )
      {
        v61 = v54;
        if ( (ipclite_debug_level & 1) == 0 )
          goto LABEL_93;
        if ( (ipclite_debug_control & 1) != 0 )
        {
          printk(&unk_F68A, "ipclite", "ipclite_channel_init");
          if ( (ipclite_debug_control & 4) == 0 )
          {
LABEL_93:
            put_device(v44);
            kfree(v44);
            if ( v61 == -517 )
              goto LABEL_297;
            goto LABEL_94;
          }
        }
        else if ( (ipclite_debug_control & 4) == 0 )
        {
          goto LABEL_93;
        }
        ipclite_inmem_log(
          "APPS:%s:failed to register IPCLite device\n",
          (__int64)"ERR",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v164);
        goto LABEL_93;
      }
      v62 = of_property_read_variable_u32_array(v44[93], "qcom,remote-pid", &v169, 1, 0);
      if ( v62 < 0 )
      {
        LODWORD(v74) = v62;
        dev_err(v44, "failed to parse qcom,remote-pid\n");
        goto LABEL_261;
      }
      if ( (ipclite_debug_level & 0x10) != 0 )
      {
        if ( (ipclite_debug_control & 1) != 0 )
        {
          printk(&unk_FA83, "ipclite", "ipclite_channel_init");
          if ( (ipclite_debug_control & 4) == 0 )
            goto LABEL_114;
LABEL_113:
          ipclite_inmem_log(
            "APPS:%s:remote_pid = %d, local_pid=%d\n",
            (__int64)"LOW",
            v169,
            0,
            v63,
            v64,
            v65,
            v66,
            v164);
          goto LABEL_114;
        }
        if ( (ipclite_debug_control & 4) != 0 )
          goto LABEL_113;
      }
LABEL_114:
      v67 = devm_kmalloc(v44, 72, 3520);
      v68 = devm_kmalloc(v44, 72, 3520);
      LODWORD(v74) = -12;
      if ( !v67 )
        goto LABEL_261;
      v75 = v68;
      if ( !v68 )
        goto LABEL_261;
      if ( (ipclite_debug_level & 0x10) != 0 )
      {
        if ( (ipclite_debug_control & 1) == 0 )
        {
          if ( (ipclite_debug_control & 4) == 0 )
            goto LABEL_120;
LABEL_119:
          v76 = v75;
          ipclite_inmem_log("APPS:%s:rx_fifo = %p, tx_fifo=%p\n", (__int64)"LOW", v67, v75, v70, v71, v72, v73, v164);
          v75 = v76;
          goto LABEL_120;
        }
        v158 = v68;
        printk(&unk_E75A, "ipclite", "ipclite_channel_init");
        v75 = v158;
        if ( (ipclite_debug_control & 4) != 0 )
          goto LABEL_119;
      }
LABEL_120:
      v77 = *(unsigned int *)(ipclite + 6424);
      if ( (_DWORD)v77 )
      {
        v78 = (_DWORD *)(*(_QWORD *)(ipclite + 6376) + 16LL);
        while ( *(v78 - 1) || *v78 != v169 )
        {
          --v77;
          v78 += 6;
          if ( !v77 )
            goto LABEL_126;
        }
        v79 = (_DWORD *)(*(_QWORD *)(ipclite + 6400) + (unsigned int)*(v78 - 4));
      }
      else
      {
LABEL_126:
        v79 = nullptr;
      }
      if ( (ipclite_debug_level & 0x10) != 0 )
      {
        if ( (ipclite_debug_control & 1) == 0 )
        {
          if ( (ipclite_debug_control & 4) == 0 )
            goto LABEL_131;
LABEL_130:
          v80 = v75;
          ipclite_inmem_log("APPS:%s:partition_hdr = %p\n", (__int64)"LOW", (__int64)v79, v69, v70, v71, v72, v73, v164);
          v75 = v80;
          goto LABEL_131;
        }
        v159 = v75;
        printk(&unk_1144E, "ipclite", "ipclite_channel_init");
        v75 = v159;
        if ( (ipclite_debug_control & 4) != 0 )
          goto LABEL_130;
      }
LABEL_131:
      if ( !v79 )
      {
        LODWORD(v74) = -12;
        goto LABEL_261;
      }
      v81 = (__int64)v79 + (unsigned int)v79[1];
      if ( (ipclite_debug_level & 0x10) != 0 )
      {
        if ( (ipclite_debug_control & 1) == 0 )
        {
          if ( (ipclite_debug_control & 4) == 0 )
            goto LABEL_136;
LABEL_135:
          v166 = v75;
          ipclite_inmem_log("APPS:%s:descs = %p\n", (__int64)"LOW", v81, v69, v70, v71, v72, v73, v164);
          v75 = v166;
          goto LABEL_136;
        }
        v168 = v75;
        printk(&unk_10B38, "ipclite", "ipclite_channel_init");
        v75 = v168;
        if ( (ipclite_debug_control & 4) != 0 )
          goto LABEL_135;
      }
LABEL_136:
      v82 = 4;
      v83 = v169 == 0;
      if ( v169 )
        v84 = 3;
      else
        v84 = 5;
      if ( v169 )
        v85 = 4;
      else
        v85 = 6;
      if ( v169 )
        v82 = 6;
      *(_QWORD *)(v75 + 24) = (char *)v79 + (unsigned int)v79[v84];
      v86 = v79[v85];
      if ( v83 )
        v87 = 3;
      else
        v87 = 5;
      v88 = v81 + 4;
      *(_DWORD *)v75 = v86;
      v89 = (unsigned int)v79[v87];
      v90 = (_DWORD *)(v81 + 8);
      v91 = (char *)v79 + v89;
      if ( v83 )
        v92 = (_DWORD *)v81;
      else
        v92 = (_DWORD *)(v81 + 8);
      if ( !v83 )
        v90 = (_DWORD *)v81;
      *(_QWORD *)(v67 + 24) = v91;
      if ( v83 )
        v93 = v81 + 4;
      else
        v93 = v81 + 12;
      if ( v83 )
        v88 = v81 + 12;
      v94 = v79[v82];
      *(_QWORD *)(v67 + 8) = v92;
      *(_QWORD *)(v67 + 16) = v93;
      *(_QWORD *)(v75 + 8) = v90;
      *(_QWORD *)(v75 + 16) = v88;
      *(_DWORD *)v67 = v94;
      if ( *v79 == 1 )
      {
        v92 = v90;
        *(_QWORD *)(v67 + 8) = v90;
        *(_QWORD *)(v67 + 16) = v88;
      }
      *(_QWORD *)(v67 + 32) = ipcmem_rx_avail;
      *(_QWORD *)(v67 + 40) = ipcmem_rx_peak;
      *(_QWORD *)(v67 + 48) = ipcmem_rx_advance;
      *(_QWORD *)(v75 + 32) = ipcmem_tx_avail;
      *(_QWORD *)(v75 + 56) = ipcmem_tx_write;
      *v92 = 0;
      **(_DWORD **)(v75 + 16) = 0;
      if ( v169 >= 9 )
        goto LABEL_317;
      v95 = ipclite + 8;
      *(_DWORD *)(ipclite + 8 + 704LL * v169) = v169;
      if ( v169 > 8 )
        goto LABEL_317;
      v96 = v95 + 704LL * v169;
      *(_QWORD *)(v96 + 8) = v75;
      *(_QWORD *)(v96 + 16) = v67;
      *(_QWORD *)(v96 + 688) = v79 + 7;
      *(_DWORD *)(v96 + 24) = 0;
      v97 = of_get_next_available_child(v44[93], 0);
      if ( !v97 )
        break;
      v103 = (const void *)v97;
      while ( 1 )
      {
        v110 = v169;
        if ( v169 > 9 )
          goto LABEL_317;
        LODWORD(v182[0]) = 0;
        LODWORD(v177) = 0;
        v172 = 0x7372657600007469LL;
        v173 = 0x65740000006E6F69LL;
        v175 = 7500659;
        v176 = 0x67756265640000LL;
        v174 = 29811;
        v171 = 0x6E692D6D656D0000LL;
        v165 = ipclite;
        v167 = v103;
        v170 = 6779757;
        v111 = (_QWORD *)_kmalloc_cache_noprof(dev_err, 3520, 912);
        v112 = v111;
        if ( !v111 )
        {
          LODWORD(v74) = -12;
          goto LABEL_257;
        }
        v113 = (const char **)v44[12];
        v111[12] = v44;
        v111[93] = v103;
        v111[101] = ipclite_device_release;
        v114 = v113[14];
        if ( !v114 )
          v114 = *v113;
        dev_set_name(v111, "%s:%pOFn", v114, v103);
        if ( (ipclite_debug_level & 0x10) != 0 )
        {
          if ( (ipclite_debug_control & 1) != 0 )
          {
            printk(&unk_F164, "ipclite", "ipclite_channel_irq_init");
            if ( (ipclite_debug_control & 4) == 0 )
              goto LABEL_176;
          }
          else if ( (ipclite_debug_control & 4) == 0 )
          {
            goto LABEL_176;
          }
          v120 = (__int64 *)v44[12];
          v121 = v120[14];
          if ( !v121 )
            v121 = *v120;
          ipclite_inmem_log("APPS:%s:Registering %s device\n", (__int64)"LOW", v121, v115, v116, v117, v118, v119, v164);
        }
LABEL_176:
        v122 = device_register(v112);
        if ( v122 )
        {
          LODWORD(v74) = v122;
          if ( (ipclite_debug_level & 1) != 0 )
          {
            if ( (ipclite_debug_control & 1) != 0 )
            {
              printk(&unk_10481, "ipclite", "ipclite_channel_irq_init");
              if ( (ipclite_debug_control & 4) == 0 )
                goto LABEL_240;
              goto LABEL_239;
            }
            if ( (ipclite_debug_control & 4) != 0 )
LABEL_239:
              ipclite_inmem_log(
                "APPS:%s:failed to register IPCLite child node\n",
                (__int64)"ERR",
                v123,
                v124,
                v125,
                v126,
                v127,
                v128,
                v164);
          }
LABEL_240:
          put_device(v112);
          goto LABEL_257;
        }
        v129 = of_property_read_variable_u32_array(v112[93], "index", v182, 1, 0);
        if ( v129 < 0 )
        {
          LODWORD(v74) = v129 & (v129 >> 31);
          if ( (ipclite_debug_level & 1) == 0 )
            goto LABEL_164;
          v142 = ipclite_debug_control;
          if ( (ipclite_debug_control & 1) != 0 )
          {
            printk(&unk_FD0C, "ipclite", "ipclite_channel_irq_init");
            v142 = ipclite_debug_control;
          }
          v141 = "APPS:%s:failed to parse index\n";
          if ( (v142 & 4) == 0 )
          {
LABEL_164:
            device_unregister(v112);
            if ( (_DWORD)v74 )
              goto LABEL_257;
            goto LABEL_165;
          }
LABEL_163:
          ipclite_inmem_log(v141, (__int64)"ERR", v130, v131, v132, v133, v134, v135, v164);
          goto LABEL_164;
        }
        v136 = LODWORD(v182[0]);
        if ( LODWORD(v182[0]) >= 7 )
          goto LABEL_317;
        v137 = v165 + 8 + 704LL * v110 + 104LL * LODWORD(v182[0]) + 32;
        if ( (ipclite_debug_level & 0x10) != 0 )
        {
          if ( (ipclite_debug_control & 1) == 0 )
          {
            if ( (ipclite_debug_control & 4) == 0 )
              goto LABEL_183;
LABEL_182:
            ipclite_inmem_log(
              "APPS:%s:irq_info[%d]=%p\n",
              (__int64)"LOW",
              LODWORD(v182[0]),
              v137,
              v136,
              v133,
              v134,
              v135,
              v164);
            goto LABEL_183;
          }
          printk(&unk_10B72, "ipclite", "ipclite_channel_irq_init");
          if ( (ipclite_debug_control & 4) != 0 )
            goto LABEL_182;
        }
LABEL_183:
        *(_QWORD *)v137 = v112;
        *(_BYTE *)(v137 + 24) = 1;
        v138 = mbox_request_channel(v137, 0);
        v139 = ipclite_debug_level;
        v74 = v138;
        *(_QWORD *)(v137 + 56) = v138;
        if ( (v139 & 0x10) == 0 )
          goto LABEL_187;
        if ( (ipclite_debug_control & 1) == 0 )
        {
          if ( (ipclite_debug_control & 4) == 0 )
            goto LABEL_187;
LABEL_186:
          ipclite_inmem_log(
            "APPS:%s:irq_info[%d].mbox_chan=%p\n",
            (__int64)"LOW",
            LODWORD(v182[0]),
            v74,
            v132,
            v133,
            v134,
            v135,
            v164);
          v74 = *(_QWORD *)(v137 + 56);
          goto LABEL_187;
        }
        printk(&unk_EE88, "ipclite", "ipclite_channel_irq_init");
        v74 = *(_QWORD *)(v137 + 56);
        if ( (ipclite_debug_control & 4) != 0 )
          goto LABEL_186;
LABEL_187:
        if ( v74 >= 0xFFFFFFFFFFFFF001LL )
        {
          if ( (_DWORD)v74 != -517 )
          {
            if ( (ipclite_debug_level & 1) == 0 )
              goto LABEL_164;
            v140 = ipclite_debug_control;
            if ( (ipclite_debug_control & 1) != 0 )
            {
              printk(&unk_10D09, "ipclite", "ipclite_channel_irq_init");
              v140 = ipclite_debug_control;
            }
            v141 = "APPS:%s:failed to acquire IPC channel\n";
            if ( (v140 & 4) == 0 )
              goto LABEL_164;
            goto LABEL_163;
          }
          if ( (ipclite_debug_level & 2) != 0 )
          {
            if ( (ipclite_debug_control & 1) != 0 )
            {
              printk(&unk_1017A, "ipclite", "ipclite_channel_irq_init");
              if ( (ipclite_debug_control & 4) == 0 )
                goto LABEL_251;
              goto LABEL_250;
            }
            if ( (ipclite_debug_control & 4) != 0 )
LABEL_250:
              ipclite_inmem_log(
                "APPS:%s:IPCC Probe Deferred\n",
                (__int64)"WARN",
                v130,
                v131,
                v132,
                v133,
                v134,
                v135,
                v164);
          }
LABEL_251:
          LODWORD(v74) = -517;
          goto LABEL_256;
        }
        if ( LODWORD(v182[0]) > 6 )
          goto LABEL_317;
        snprintf((char *)(v137 + 72), 0x20u, "ipclite-signal-%s", (const char *)&v170 + 10 * LODWORD(v182[0]));
        v143 = of_irq_get(v112[93], 0);
        *(_DWORD *)(v137 + 64) = v143;
        v148 = v143;
        if ( (ipclite_debug_level & 0x10) != 0 )
        {
          if ( (ipclite_debug_control & 1) == 0 )
          {
            if ( (ipclite_debug_control & 4) == 0 )
              goto LABEL_204;
LABEL_203:
            ipclite_inmem_log(
              "APPS:%s:irq[%d] = %d\n",
              (__int64)"LOW",
              LODWORD(v182[0]),
              v148,
              v144,
              v145,
              v146,
              v147,
              v164);
            v148 = *(_DWORD *)(v137 + 64);
            goto LABEL_204;
          }
          printk(&unk_FAAE, "ipclite", "ipclite_channel_irq_init");
          v148 = *(_DWORD *)(v137 + 64);
          if ( (ipclite_debug_control & 4) != 0 )
            goto LABEL_203;
        }
LABEL_204:
        *(_DWORD *)(v137 + 68) = v182[0];
        v149 = devm_request_threaded_irq(v112, v148, ipclite_intr, 0, 16512, v137 + 72, v137);
        if ( v149 )
          break;
        if ( (ipclite_debug_level & 0x10) != 0 )
        {
          if ( (ipclite_debug_control & 1) != 0 )
          {
            printk(&unk_10805, "ipclite", "ipclite_channel_irq_init");
            if ( (ipclite_debug_control & 4) == 0 )
              goto LABEL_165;
LABEL_208:
            ipclite_inmem_log(
              "APPS:%s:Interrupt init completed, ret = %d\n",
              (__int64)"LOW",
              0,
              v151,
              v152,
              v153,
              v154,
              v155,
              v164);
            goto LABEL_165;
          }
          if ( (ipclite_debug_control & 4) != 0 )
            goto LABEL_208;
        }
LABEL_165:
        v103 = (const void *)of_get_next_available_child(v44[93], v167);
        if ( !v103 )
          goto LABEL_221;
      }
      LODWORD(v74) = v149;
      if ( (ipclite_debug_level & 1) != 0 )
      {
        if ( (ipclite_debug_control & 1) != 0 )
        {
          printk(&unk_1003C, "ipclite", "ipclite_channel_irq_init");
          if ( (ipclite_debug_control & 4) != 0 )
LABEL_255:
            ipclite_inmem_log(
              "APPS:%s:failed to request IRQ\n",
              (__int64)"ERR",
              v150,
              v151,
              v152,
              v153,
              v154,
              v155,
              v164);
        }
        else if ( (ipclite_debug_control & 4) != 0 )
        {
          goto LABEL_255;
        }
      }
LABEL_256:
      device_unregister(v112);
LABEL_257:
      if ( (ipclite_debug_level & 1) == 0 )
        goto LABEL_261;
      if ( (ipclite_debug_control & 1) == 0 )
      {
        if ( (ipclite_debug_control & 4) == 0 )
          goto LABEL_261;
        goto LABEL_260;
      }
      printk(&unk_EC37, "ipclite", "ipclite_channel_init");
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_260:
        ipclite_inmem_log(
          "APPS:%s:irq setup for IPCLite channel failed\n",
          (__int64)"ERR",
          v104,
          v105,
          v106,
          v107,
          v108,
          v109,
          v164);
LABEL_261:
      if ( v169 > 8 )
        goto LABEL_317;
      *(_DWORD *)(ipclite + 704LL * v169 + 704) = 0;
      device_unregister(v44);
      if ( (_DWORD)v74 == -517 )
      {
LABEL_297:
        id = -517;
        goto LABEL_76;
      }
LABEL_94:
      v42 = (const void *)of_get_next_available_child(v2, v42);
      if ( !v42 )
        goto LABEL_276;
    }
LABEL_221:
    if ( v169 )
    {
      if ( v169 <= 8 )
      {
        v156 = ipclite + 8;
        **(_DWORD **)(ipclite + 8 + 704LL * v169 + 688) = 1;
        if ( v169 <= 8 )
        {
          *(_DWORD *)(v156 + 704LL * v169 + 696) = 1;
          goto LABEL_230;
        }
      }
    }
    else
    {
      v157 = ipclite;
      **(_DWORD **)(ipclite + 696) = 2;
      if ( v169 <= 8 )
      {
        *(_DWORD *)(v157 + 704LL * v169 + 704) = 2;
LABEL_230:
        if ( (ipclite_debug_level & 0x10) == 0 )
          goto LABEL_94;
        if ( (ipclite_debug_control & 1) != 0 )
        {
          printk(&unk_1010D, "ipclite", "ipclite_channel_init");
          if ( (ipclite_debug_control & 4) == 0 )
            goto LABEL_94;
        }
        else if ( (ipclite_debug_control & 4) == 0 )
        {
          goto LABEL_94;
        }
        ipclite_inmem_log(
          "APPS:%s:Channel init completed, ret = %d\n",
          (__int64)"LOW",
          0,
          v98,
          v99,
          v100,
          v101,
          v102,
          v164);
        goto LABEL_94;
      }
    }
LABEL_317:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v163 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v3 = (_QWORD *)_kmalloc_cache_noprof(of_get_next_available_child, 3520, 6472);
    *(_QWORD *)(StatusReg + 80) = v163;
  }
LABEL_276:
  inited = ipclite_init_signal_broadcast();
  if ( (inited & 0x80000000) != 0 )
  {
    id = inited;
    goto LABEL_76;
  }
  v161 = ipclite_debug_setup();
  if ( v161 )
  {
    id = v161;
    if ( (ipclite_debug_level & 1) == 0 )
      goto LABEL_76;
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_10C68, "ipclite", "ipclite_init_v0");
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_76;
    }
    else if ( (ipclite_debug_control & 4) == 0 )
    {
      goto LABEL_76;
    }
    v38 = "APPS:%s:IPCLite Debug Setup Failed\n";
    goto LABEL_75;
  }
  if ( (ipclite_debug_level & 4) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_10752, "ipclite", "ipclite_init_v0");
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_301:
        ipclite_inmem_log(
          "APPS:%s:IPCLite Version : %d.%d Feature Mask : 0x%llx\n",
          (__int64)"INFO",
          (unsigned int)major_ver,
          (unsigned int)minor_ver,
          feature_mask,
          v28,
          v29,
          v30,
          v164);
    }
    else if ( (ipclite_debug_control & 4) != 0 )
    {
      goto LABEL_301;
    }
  }
  if ( (ipclite_debug_level & 4) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_1078D, "ipclite", "ipclite_init_v0");
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_305:
        ipclite_inmem_log(
          "APPS:%s:IPCLite Probe Completed Successfully\n",
          (__int64)"INFO",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v164);
    }
    else if ( (ipclite_debug_control & 4) != 0 )
    {
      goto LABEL_305;
    }
  }
  id = 0;
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return id;
}
