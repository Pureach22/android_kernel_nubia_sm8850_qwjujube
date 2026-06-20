__int64 __fastcall ipa_bridge_init(const char **a1, unsigned int *a2)
{
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 dir; // x0
  unsigned __int64 file; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x25
  const char *v16; // x22
  size_t v17; // x21
  const char *v18; // x23
  size_t v19; // x0
  const char *v20; // x22
  const char *v21; // x23
  const char *v22; // x22
  const char *v23; // x23
  const char *v24; // x22
  const char *v25; // x23
  const char *StatusReg; // x22
  const char *v27; // x23
  __int64 v28; // x9
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 result; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  const char *v40; // x22
  unsigned __int64 v41; // x2
  const char *v42; // x9
  const char *v43; // x8
  const char *v44; // x10
  const char *v45; // x9
  __int64 v46; // x20
  int v47; // w11
  char v48; // w12
  int v49; // w8
  __int16 v50; // w9
  int v51; // w9
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  int v56; // w10
  int v57; // w0
  __int64 v58; // x0
  __int64 v59; // x0
  int v60; // w0
  __int64 v61; // x8
  __int64 v62; // x9
  int v63; // w10
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x0
  int v84; // w20
  __int64 v85; // x0
  __int64 v86; // x0
  __int64 v87; // x0
  long double v88; // q0
  __int64 v89; // x0
  __int64 v90; // x0
  long double v91; // q0
  __int64 v92; // x0
  unsigned int v93; // w20
  __int64 v94; // x23
  __int64 (__fastcall *v95)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v96; // x8
  __int64 v97; // x0
  unsigned __int64 v98; // x23
  __int64 v99; // x25
  _QWORD v100[2]; // [xsp+0h] [xbp-300h] BYREF
  _QWORD v101[2]; // [xsp+10h] [xbp-2F0h] BYREF
  _DWORD v102[80]; // [xsp+20h] [xbp-2E0h] BYREF
  __int64 v103; // [xsp+160h] [xbp-1A0h]
  _QWORD s[51]; // [xsp+168h] [xbp-198h] BYREF

  s[50] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 || !a1[6] || !*a1 || !a1[2] || !a1[3] )
  {
    printk(&unk_3C24F1, "ipa_bridge_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_gsb %s:%d Invalid parameters\n", "ipa_bridge_init", 499);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_gsb %s:%d Invalid parameters\n", "ipa_bridge_init", 499);
    }
    result = 4294967274LL;
    goto LABEL_173;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v4 = ipa3_get_ipc_logbuf();
    ipc_log_string(v4, "ipa_gsb %s:%d netdev_name: %s\n", "ipa_bridge_init", 503, *a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v5 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v5, "ipa_gsb %s:%d netdev_name: %s\n", "ipa_bridge_init", 503, *a1);
  }
  if ( !ipa_gsb_ctx )
  {
    if ( (ipa_is_ready() & 1) != 0 )
    {
      v6 = _kmalloc_cache_noprof(scnprintf, 3520, 408);
      ipa_gsb_ctx = v6;
      if ( v6 )
      {
        _mutex_init(v6 + 16, "&ipa_gsb_ctx->lock", &ipa_gsb_driver_init___key);
        _mutex_init(ipa_gsb_ctx + 136, "&ipa_gsb_ctx->iface_lock[i]", &ipa_gsb_driver_init___key_73);
        v7 = ipa_gsb_ctx + 184;
        *(_DWORD *)(ipa_gsb_ctx + 376) = 0;
        _mutex_init(v7, "&ipa_gsb_ctx->iface_lock[i]", &ipa_gsb_driver_init___key_73);
        v8 = ipa_gsb_ctx + 232;
        *(_DWORD *)(ipa_gsb_ctx + 380) = 0;
        _mutex_init(v8, "&ipa_gsb_ctx->iface_lock[i]", &ipa_gsb_driver_init___key_73);
        v9 = ipa_gsb_ctx + 280;
        *(_DWORD *)(ipa_gsb_ctx + 384) = 0;
        _mutex_init(v9, "&ipa_gsb_ctx->iface_lock[i]", &ipa_gsb_driver_init___key_73);
        v10 = ipa_gsb_ctx + 328;
        *(_DWORD *)(ipa_gsb_ctx + 388) = 0;
        _mutex_init(v10, "&ipa_gsb_ctx->iface_lock[i]", &ipa_gsb_driver_init___key_73);
        *(_DWORD *)(ipa_gsb_ctx + 392) = 0;
        dir = debugfs_create_dir("ipa_gsb", 0);
        dent_1 = dir;
        if ( dir )
        {
          file = debugfs_create_file("stats", 292, dir, 0, &ipa_gsb_stats_ops);
          dfile_stats = file;
          if ( !file || file >= 0xFFFFFFFFFFFFF001LL )
          {
            printk(&unk_3B362B, "ipa_gsb_debugfs_init");
            if ( ipa3_get_ipc_logbuf() )
            {
              v82 = ipa3_get_ipc_logbuf();
              ipc_log_string(v82, "ipa_gsb %s:%d fail to create file stats\n", "ipa_gsb_debugfs_init", 232);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v83 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v83, "ipa_gsb %s:%d fail to create file stats\n", "ipa_gsb_debugfs_init", 232);
            }
            debugfs_remove(dent_1);
          }
        }
        else
        {
          printk(&unk_3C253B, "ipa_gsb_debugfs_init");
          if ( ipa3_get_ipc_logbuf() )
          {
            v80 = ipa3_get_ipc_logbuf();
            ipc_log_string(v80, "ipa_gsb %s:%d fail to create folder ipa_gsb\n", "ipa_gsb_debugfs_init", 224);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v81 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v81, "ipa_gsb %s:%d fail to create folder ipa_gsb\n", "ipa_gsb_debugfs_init", 224);
          }
        }
        *(_DWORD *)(ipa_gsb_ctx + 72) = *((_DWORD *)a1 + 10);
        if ( ipa3_get_ipc_logbuf() )
        {
          v13 = ipa3_get_ipc_logbuf();
          ipc_log_string(v13, "ipa_gsb %s:%d desc size: %d\n", "ipa_bridge_init", 513, *(_DWORD *)(ipa_gsb_ctx + 72));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v14 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v14, "ipa_gsb %s:%d desc size: %d\n", "ipa_bridge_init", 513, *(_DWORD *)(ipa_gsb_ctx + 72));
        }
        goto LABEL_21;
      }
    }
    else
    {
      printk(&unk_3C866E, "ipa_gsb_driver_init");
      if ( ipa3_get_ipc_logbuf() )
      {
        v76 = ipa3_get_ipc_logbuf();
        ipc_log_string(v76, "ipa_gsb %s:%d IPA is not ready\n", "ipa_gsb_driver_init", 261);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v77 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v77, "ipa_gsb %s:%d IPA is not ready\n", "ipa_gsb_driver_init", 261);
      }
    }
    printk(&unk_3CE27E, "ipa_bridge_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      v78 = ipa3_get_ipc_logbuf();
      ipc_log_string(v78, "ipa_gsb %s:%d fail to init ipa gsb driver\n", "ipa_bridge_init", 508);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v79 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v79, "ipa_gsb %s:%d fail to init ipa gsb driver\n", "ipa_bridge_init", 508);
    }
    result = 4294967282LL;
    goto LABEL_173;
  }
LABEL_21:
  mutex_lock(ipa_gsb_ctx + 16);
  v15 = ipa_gsb_ctx;
  if ( *((_DWORD *)a1 + 10) != *(_DWORD *)(ipa_gsb_ctx + 72) )
  {
    printk(&unk_3DCC38, "ipa_bridge_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      v34 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v34,
        "ipa_gsb %s:%d unmatch: orig desc size %d, new desc size %d\n",
        "ipa_bridge_init",
        521,
        *(_DWORD *)(ipa_gsb_ctx + 72),
        *((_DWORD *)a1 + 10));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v35 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v35,
        "ipa_gsb %s:%d unmatch: orig desc size %d, new desc size %d\n",
        "ipa_bridge_init",
        521,
        *(_DWORD *)(ipa_gsb_ctx + 72),
        *((_DWORD *)a1 + 10));
    }
    goto LABEL_114;
  }
  v16 = *(const char **)(ipa_gsb_ctx + 96);
  if ( v16 )
  {
    v17 = strnlen(*(const char **)(ipa_gsb_ctx + 96), 0x20u);
    if ( v17 >= 0x21 )
      goto LABEL_168;
    v18 = *a1;
    v19 = strnlen(*a1, 0x20u);
    if ( v19 == -1 )
      goto LABEL_167;
    if ( v17 == v19 && !strcmp(v16, v18) )
      goto LABEL_63;
  }
  v20 = *(const char **)(v15 + 104);
  if ( v20 )
  {
    v17 = strnlen(*(const char **)(v15 + 104), 0x20u);
    if ( v17 > 0x20 )
      goto LABEL_168;
    v21 = *a1;
    v19 = strnlen(*a1, 0x20u);
    if ( v19 == -1 )
      goto LABEL_167;
    if ( v17 == v19 && !strcmp(v20, v21) )
      goto LABEL_63;
  }
  v22 = *(const char **)(v15 + 112);
  if ( v22 )
  {
    v17 = strnlen(*(const char **)(v15 + 112), 0x20u);
    if ( v17 > 0x20 )
      goto LABEL_168;
    v23 = *a1;
    v19 = strnlen(*a1, 0x20u);
    if ( v19 == -1 )
      goto LABEL_167;
    if ( v17 == v19 && !strcmp(v22, v23) )
      goto LABEL_63;
  }
  v24 = *(const char **)(v15 + 120);
  if ( v24 )
  {
    v17 = strnlen(*(const char **)(v15 + 120), 0x20u);
    if ( v17 > 0x20 )
      goto LABEL_168;
    v25 = *a1;
    v19 = strnlen(*a1, 0x20u);
    if ( v19 == -1 )
      goto LABEL_167;
    if ( v17 == v19 && !strcmp(v24, v25) )
      goto LABEL_63;
  }
  StatusReg = *(const char **)(v15 + 128);
  if ( StatusReg )
  {
    v17 = strnlen(*(const char **)(v15 + 128), 0x20u);
    if ( v17 > 0x20 )
      goto LABEL_168;
    v27 = *a1;
    v19 = strnlen(*a1, 0x20u);
    if ( v19 == -1 )
      goto LABEL_167;
    if ( v17 == v19 && !strcmp(StatusReg, v27) )
    {
LABEL_63:
      printk(&unk_3A8136, "ipa_bridge_init");
      if ( ipa3_get_ipc_logbuf() )
      {
        v32 = ipa3_get_ipc_logbuf();
        ipc_log_string(v32, "ipa_gsb %s:%d intf was added before.\n", "ipa_bridge_init", 534);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v33 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v33, "ipa_gsb %s:%d intf was added before.\n", "ipa_bridge_init", 534);
      }
      goto LABEL_114;
    }
  }
  if ( *(_DWORD *)(v15 + 76) == 5 )
  {
    printk(&unk_3B35A2, "ipa_bridge_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      v66 = ipa3_get_ipc_logbuf();
      ipc_log_string(v66, "ipa_gsb %s:%d reached maximum supported interfaces", "ipa_bridge_init", 540);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v67 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v67, "ipa_gsb %s:%d reached maximum supported interfaces", "ipa_bridge_init", 540);
    }
LABEL_114:
    mutex_unlock(ipa_gsb_ctx + 16);
    result = 4294967282LL;
    goto LABEL_173;
  }
  if ( (*(_BYTE *)(v15 + 80) & 1) != 0 )
  {
    if ( *(_BYTE *)(v15 + 81) == 1 )
    {
      if ( *(_BYTE *)(v15 + 82) == 1 )
      {
        if ( *(_BYTE *)(v15 + 83) == 1 )
        {
          if ( *(_BYTE *)(v15 + 84) == 1 )
            goto LABEL_76;
          v28 = 4;
        }
        else
        {
          v28 = 3;
        }
      }
      else
      {
        v28 = 2;
      }
    }
    else
    {
      v28 = 1;
    }
  }
  else
  {
    v28 = 0;
  }
  *(_BYTE *)(v15 + 80 + v28) = 1;
  *a2 = v28;
  if ( ipa3_get_ipc_logbuf() )
  {
    v36 = ipa3_get_ipc_logbuf();
    ipc_log_string(v36, "ipa_gsb %s:%d iface hdl: %d\n", "ipa_bridge_init", 549, *a2);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v37 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v37, "ipa_gsb %s:%d iface hdl: %d\n", "ipa_bridge_init", 549, *a2);
  }
LABEL_76:
  if ( ipa3_get_ipc_logbuf() )
  {
    v38 = ipa3_get_ipc_logbuf();
    ipc_log_string(v38, "ipa_gsb %s:%d intf was not added before, proceed.\n", "ipa_bridge_init", 553);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v39 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v39, "ipa_gsb %s:%d intf was not added before, proceed.\n", "ipa_bridge_init", 553);
  }
  v17 = _kmalloc_cache_noprof(of_find_property, 3520, 112);
  if ( !v17 )
  {
LABEL_170:
    v93 = -12;
    goto LABEL_171;
  }
  while ( 1 )
  {
    v40 = *a1;
    v19 = strnlen(*a1, 0x20u);
    if ( v19 == -1 )
    {
LABEL_167:
      _fortify_panic(2, -1, v19 + 1);
LABEL_168:
      _fortify_panic(2, 32, v17 + 1);
      goto LABEL_169;
    }
    v41 = v19 == 32 ? 32LL : v19 + 1;
    if ( v41 < 0x21 )
      break;
LABEL_169:
    _fortify_panic(7, 32, v41);
    StatusReg = (const char *)_ReadStatusReg(SP_EL0);
    v94 = *((_QWORD *)StatusReg + 10);
    v95 = of_find_property;
    *((_QWORD *)StatusReg + 10) = &ipa_bridge_init__alloc_tag;
    v17 = _kmalloc_cache_noprof(v95, 3520, 112);
    *((_QWORD *)StatusReg + 10) = v94;
    if ( !v17 )
      goto LABEL_170;
  }
  sized_strscpy(v17, v40);
  v42 = a1[6];
  *(_DWORD *)(v17 + 32) = *((_DWORD *)a1 + 8);
  StatusReg = (const char *)(v17 + 32);
  v43 = a1[1];
  v44 = a1[2];
  *(_QWORD *)(v17 + 96) = v42;
  v45 = a1[3];
  *(_QWORD *)(v17 + 40) = v43;
  *(_QWORD *)(v17 + 48) = v44;
  LOBYTE(v43) = *a2;
  *(_QWORD *)(v17 + 56) = v45;
  LOWORD(v45) = *((_WORD *)a1 + 18);
  *(_BYTE *)(v17 + 106) = (_BYTE)v43;
  *(_WORD *)(v17 + 36) = (_WORD)v45;
  v46 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 620);
  if ( !v46 )
    goto LABEL_120;
LABEL_87:
  *(_WORD *)v46 = 512;
  snprintf((char *)(v46 + 4), 0x20u, "%s_ipv4", (const char *)v17);
  snprintf((char *)(v46 + 312), 0x20u, "%s_ipv6", (const char *)v17);
  v47 = *(_DWORD *)StatusReg;
  *(_BYTE *)(v46 + 291) = 60;
  v48 = *(_BYTE *)(v17 + 106);
  *(_DWORD *)(v46 + 88) = v47;
  LOWORD(v47) = *((_WORD *)StatusReg + 2);
  *(_BYTE *)(v46 + 599) = 60;
  v49 = *(_DWORD *)StatusReg;
  *(_DWORD *)(v46 + 292) = 1;
  *(_BYTE *)(v46 + 296) = 1;
  *(_BYTE *)(v46 + 308) = 1;
  *(_DWORD *)(v46 + 600) = 1;
  *(_BYTE *)(v46 + 604) = 1;
  *(_BYTE *)(v46 + 616) = 1;
  v50 = *((_WORD *)StatusReg + 2);
  *(_WORD *)(v46 + 92) = v47;
  *(_DWORD *)(v46 + 396) = v49;
  *(_WORD *)(v46 + 310) = 46;
  *(_BYTE *)(v46 + 36) = v48;
  *(_WORD *)(v46 + 94) = 8;
  *(_WORD *)(v46 + 618) = 46;
  *(_BYTE *)(v46 + 344) = v48;
  *(_WORD *)(v46 + 400) = v50;
  *(_WORD *)(v46 + 402) = -8826;
  if ( !(unsigned int)ipa_add_hdr(v46) )
  {
    v51 = *(_DWORD *)(v46 + 608);
    *(_DWORD *)(v17 + 88) = *(_DWORD *)(v46 + 300);
    *(_DWORD *)(v17 + 92) = v51;
    if ( ipa3_get_ipc_logbuf() )
    {
      v52 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v52,
        "ipa_gsb %s:%d added partial hdr hdl for ipv4: %d\n",
        "ipa_gsb_commit_partial_hdr",
        346,
        *(_DWORD *)(v17 + 88));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v53 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v53,
        "ipa_gsb %s:%d added partial hdr hdl for ipv4: %d\n",
        "ipa_gsb_commit_partial_hdr",
        346,
        *(_DWORD *)(v17 + 88));
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v54 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v54,
        "ipa_gsb %s:%d added partial hdr hdl for ipv6: %d\n",
        "ipa_gsb_commit_partial_hdr",
        348,
        *(_DWORD *)(v17 + 92));
    }
    StatusReg = (const char *)v102;
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v55 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v55,
        "ipa_gsb %s:%d added partial hdr hdl for ipv6: %d\n",
        "ipa_gsb_commit_partial_hdr",
        348,
        *(_DWORD *)(v17 + 92));
    }
    kfree(v46);
    v100[0] = 0;
    v101[0] = 2;
    v101[1] = s;
    memset(s, 0, 0x190u);
    HIDWORD(s[19]) = 39;
    HIDWORD(s[24]) = 1;
    snprintf((char *)&s[20] + 4, 0x20u, "%s_ipv4", (const char *)v17);
    LODWORD(s[25]) = 1;
    HIDWORD(s[44]) = 39;
    HIDWORD(s[49]) = 1;
    snprintf((char *)&s[45] + 4, 0x20u, "%s_ipv6", (const char *)v17);
    LODWORD(v100[0]) = 2;
    v100[1] = v102;
    memset(v102, 0, sizeof(v102));
    v56 = *(unsigned __int8 *)(v17 + 106);
    v102[1] = 0x4000;
    *(_QWORD *)&v102[41] = 0x400000000001LL;
    *(_QWORD *)&v102[39] = 0x100000026LL;
    v103 = 0x100000026LL;
    v102[7] = v56;
    v102[8] = 255;
    v102[48] = v56;
    v102[49] = 255;
    if ( (unsigned int)ipa_register_intf(v17, (__int64)v101, (__int64)v100) )
    {
      printk(&unk_3F085A, "ipa_gsb_reg_intf_props");
      if ( ipa3_get_ipc_logbuf() )
      {
        v72 = ipa3_get_ipc_logbuf();
        ipc_log_string(v72, "ipa_gsb %s:%d fail to add interface prop\n", "ipa_gsb_reg_intf_props", 423);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v73 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v73, "ipa_gsb %s:%d fail to add interface prop\n", "ipa_gsb_reg_intf_props", 423);
      }
      printk(&unk_3F079B, "ipa_bridge_init");
      if ( ipa3_get_ipc_logbuf() )
      {
        v74 = ipa3_get_ipc_logbuf();
        ipc_log_string(v74, "ipa_gsb %s:%d fail to register interface props\n", "ipa_bridge_init", 577);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v75 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v75, "ipa_gsb %s:%d fail to register interface props\n", "ipa_bridge_init", 577);
      }
    }
    else
    {
      if ( *(_DWORD *)(ipa_gsb_ctx + 76) )
        goto LABEL_104;
      s[0] = "ipa_gsb";
      s[1] = ipa_gsb_pm_cb;
      s[2] = 0;
      s[3] = 0;
      v57 = ipa_pm_register((__int64)s, (unsigned int *)(ipa_gsb_ctx + 396));
      if ( v57 )
      {
        v84 = v57;
        printk(&unk_3A5088, "ipa_gsb_register_pm");
        if ( ipa3_get_ipc_logbuf() )
        {
          v85 = ipa3_get_ipc_logbuf();
          ipc_log_string(v85, "ipa_gsb %s:%d fail to register with PM %d\n", "ipa_gsb_register_pm", 470, v84);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v86 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v86, "ipa_gsb %s:%d fail to register with PM %d\n", "ipa_gsb_register_pm", 470, v84);
        }
      }
      else
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v58 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v58,
            "ipa_gsb %s:%d ipa pm hdl: %d\n",
            "ipa_gsb_register_pm",
            473,
            *(_DWORD *)(ipa_gsb_ctx + 396));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v59 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v59,
            "ipa_gsb %s:%d ipa pm hdl: %d\n",
            "ipa_gsb_register_pm",
            473,
            *(_DWORD *)(ipa_gsb_ctx + 396));
        }
        v60 = ipa_pm_associate_ipa_cons_to_client(*(_DWORD *)(ipa_gsb_ctx + 396), 0x27u);
        if ( !v60 )
        {
LABEL_104:
          v61 = *a2;
          if ( (unsigned int)v61 > 4 )
            goto LABEL_174;
          v62 = ipa_gsb_ctx;
          v63 = *(_DWORD *)(ipa_gsb_ctx + 76);
          *(_QWORD *)(ipa_gsb_ctx + 8 * v61 + 96) = v17;
          *(_DWORD *)(v62 + 76) = v63 + 1;
          if ( ipa3_get_ipc_logbuf() )
          {
            v64 = ipa3_get_ipc_logbuf();
            ipc_log_string(v64, "ipa_gsb %s:%d num_iface %d\n", "ipa_bridge_init", 593, *(_DWORD *)(ipa_gsb_ctx + 76));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v65 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v65, "ipa_gsb %s:%d num_iface %d\n", "ipa_bridge_init", 593, *(_DWORD *)(ipa_gsb_ctx + 76));
          }
          mutex_unlock(ipa_gsb_ctx + 16);
          result = 0;
          goto LABEL_173;
        }
        v84 = v60;
        printk(&unk_3DCCB6, "ipa_gsb_register_pm");
        if ( ipa3_get_ipc_logbuf() )
        {
          v87 = ipa3_get_ipc_logbuf();
          ipc_log_string(v87, "ipa_gsb %s:%d fail to associate cons with PM %d\n", "ipa_gsb_register_pm", 478, v84);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v89 = ipa3_get_ipc_logbuf_low();
          v88 = ipc_log_string(
                  v89,
                  "ipa_gsb %s:%d fail to associate cons with PM %d\n",
                  "ipa_gsb_register_pm",
                  478,
                  v84);
        }
        ((void (__fastcall *)(_QWORD, long double))ipa_pm_deregister)(*(unsigned int *)(ipa_gsb_ctx + 396), v88);
        *(_DWORD *)(ipa_gsb_ctx + 396) = -1;
      }
      printk(&unk_3CAEEC, "ipa_bridge_init");
      if ( ipa3_get_ipc_logbuf() )
      {
        v90 = ipa3_get_ipc_logbuf();
        ipc_log_string(v90, "ipa_gsb %s:%d fail to register with IPA PM %d\n", "ipa_bridge_init", 585, v84);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v92 = ipa3_get_ipc_logbuf_low();
        v91 = ipc_log_string(v92, "ipa_gsb %s:%d fail to register with IPA PM %d\n", "ipa_bridge_init", 585, v84);
      }
      ipa_gsb_dereg_intf_props(v17, v91);
    }
    ipa_gsb_delete_partial_hdr(v17);
    goto LABEL_166;
  }
  printk(&unk_3EAAD6, "ipa_gsb_commit_partial_hdr");
  if ( ipa3_get_ipc_logbuf() )
  {
    v68 = ipa3_get_ipc_logbuf();
    ipc_log_string(v68, "ipa_gsb %s:%d fail to add partial headers\n", "ipa_gsb_commit_partial_hdr", 336);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v69 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v69, "ipa_gsb %s:%d fail to add partial headers\n", "ipa_gsb_commit_partial_hdr", 336);
  }
  kfree(v46);
  while ( 1 )
  {
LABEL_120:
    printk(&unk_3A503C, "ipa_bridge_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      v70 = ipa3_get_ipc_logbuf();
      ipc_log_string(v70, "ipa_gsb %s:%d fail to commit partial hdrs\n", "ipa_bridge_init", 571);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v71 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v71, "ipa_gsb %s:%d fail to commit partial hdrs\n", "ipa_bridge_init", 571);
    }
LABEL_166:
    kfree(v17);
    v93 = -14;
LABEL_171:
    v96 = *a2;
    if ( (unsigned int)v96 <= 4 )
      break;
LABEL_174:
    __break(0x5512u);
    v98 = _ReadStatusReg(SP_EL0);
    v99 = *(_QWORD *)(v98 + 80);
    *(_QWORD *)(v98 + 80) = &ipa_gsb_commit_partial_hdr__alloc_tag;
    v46 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 620);
    *(_QWORD *)(v98 + 80) = v99;
    if ( v46 )
      goto LABEL_87;
  }
  v97 = ipa_gsb_ctx + 16;
  *(_BYTE *)(ipa_gsb_ctx + v96 + 80) = 0;
  mutex_unlock(v97);
  result = v93;
LABEL_173:
  _ReadStatusReg(SP_EL0);
  return result;
}
