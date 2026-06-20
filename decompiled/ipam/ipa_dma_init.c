__int64 __fastcall ipa_dma_init(__int64 a1)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 ipc_logbuf; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  unsigned int v8; // w20
  __int64 v9; // x19
  __int64 args; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  int v13; // w23
  int v14; // w20
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  unsigned __int64 dir; // x0
  unsigned __int64 file; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x1
  __int64 v61; // x2
  __int64 v62; // x3
  __int64 v63; // x4
  __int64 v64; // x5
  __int64 v65; // x6
  __int64 v66; // x7
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x1
  __int64 v73; // x2
  __int64 v74; // x3
  __int64 v75; // x4
  __int64 v76; // x5
  __int64 v77; // x6
  __int64 v78; // x7
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x0
  __int64 v84; // x1
  __int64 v85; // x2
  __int64 v86; // x3
  __int64 v87; // x4
  __int64 v88; // x5
  __int64 v89; // x6
  __int64 v90; // x7
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 v93; // x0
  __int64 v94; // x0
  __int64 v95; // x0
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 v98; // x0
  __int64 v99; // x0
  __int64 v100; // x0
  __int64 v101; // x8
  __int64 v102; // x0
  __int64 v103; // x0
  __int64 v105; // [xsp+8h] [xbp-128h] BYREF
  __int64 v106; // [xsp+10h] [xbp-120h]
  __int64 v107; // [xsp+18h] [xbp-118h]
  __int64 v108; // [xsp+20h] [xbp-110h]
  __int64 v109; // [xsp+28h] [xbp-108h]
  __int64 v110; // [xsp+30h] [xbp-100h]
  __int64 v111; // [xsp+38h] [xbp-F8h]
  __int64 v112; // [xsp+40h] [xbp-F0h]
  __int64 v113; // [xsp+48h] [xbp-E8h]
  __int64 v114; // [xsp+50h] [xbp-E0h]
  __int64 v115; // [xsp+58h] [xbp-D8h]
  __int64 v116; // [xsp+60h] [xbp-D0h]
  __int64 v117; // [xsp+68h] [xbp-C8h]
  __int64 v118; // [xsp+70h] [xbp-C0h]
  __int64 v119; // [xsp+78h] [xbp-B8h]
  __int64 v120; // [xsp+80h] [xbp-B0h]
  __int64 v121; // [xsp+88h] [xbp-A8h]
  __int64 v122; // [xsp+90h] [xbp-A0h]
  __int64 v123; // [xsp+98h] [xbp-98h]
  __int64 v124; // [xsp+A0h] [xbp-90h]
  __int64 v125; // [xsp+A8h] [xbp-88h]
  __int64 v126; // [xsp+B0h] [xbp-80h]
  __int64 v127; // [xsp+B8h] [xbp-78h]
  __int64 v128; // [xsp+C0h] [xbp-70h]
  __int64 v129; // [xsp+C8h] [xbp-68h]
  __int64 v130; // [xsp+D0h] [xbp-60h]
  __int64 (__fastcall *v131)(); // [xsp+D8h] [xbp-58h]
  __int64 v132; // [xsp+E0h] [xbp-50h]
  __int64 v133; // [xsp+E8h] [xbp-48h]
  __int64 v134; // [xsp+F0h] [xbp-40h]
  __int64 v135; // [xsp+F8h] [xbp-38h]
  __int64 v136; // [xsp+100h] [xbp-30h]
  _QWORD v137[5]; // [xsp+108h] [xbp-28h] BYREF

  v137[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v135 = 0;
  v136 = 0;
  v133 = 0;
  v134 = 0;
  v131 = nullptr;
  v132 = 0;
  v129 = 0;
  v130 = 0;
  v127 = 0;
  v128 = 0;
  v125 = 0;
  v126 = 0;
  v123 = 0;
  v124 = 0;
  v121 = 0;
  v122 = 0;
  v119 = 0;
  v120 = 0;
  v117 = 0;
  v118 = 0;
  v115 = 0;
  v116 = 0;
  v113 = 0;
  v114 = 0;
  v111 = 0;
  v112 = 0;
  v109 = 0;
  v110 = 0;
  v107 = 0;
  v108 = 0;
  v105 = 0;
  v106 = 0;
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(a1);
  if ( ipc_logbuf_low )
  {
    v2 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v2, "ipa_dma %s:%d ENTRY\n", "ipa_dma_init", 206);
  }
  if ( ipa_dma_init_refcnt_ctrl )
  {
    v3 = mutex_lock(ipa_dma_init_refcnt_ctrl + 8);
    if ( *(_DWORD *)ipa_dma_init_refcnt_ctrl )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf(v3);
      if ( ipc_logbuf )
      {
        v5 = ipa3_get_ipc_logbuf(ipc_logbuf);
        ipc_logbuf = ipc_log_string(
                       v5,
                       "ipa_dma %s:%d Already initialized refcnt=%d\n",
                       "ipa_dma_init",
                       216,
                       *(_DWORD *)ipa_dma_init_refcnt_ctrl);
      }
      v6 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
      if ( v6 )
      {
        v7 = ipa3_get_ipc_logbuf_low(v6);
        ipc_log_string(
          v7,
          "ipa_dma %s:%d Already initialized refcnt=%d\n",
          "ipa_dma_init",
          216,
          *(_DWORD *)ipa_dma_init_refcnt_ctrl);
      }
      if ( ipa3_dma_ctx )
      {
        v8 = 0;
        ++*(_DWORD *)ipa_dma_init_refcnt_ctrl;
LABEL_102:
        mutex_unlock(ipa_dma_init_refcnt_ctrl + 8);
        goto LABEL_103;
      }
      v33 = printk(&unk_3F4E0F, "ipa_dma_init");
      v34 = ipa3_get_ipc_logbuf(v33);
      if ( v34 )
      {
        v35 = ipa3_get_ipc_logbuf(v34);
        v34 = ipc_log_string(
                v35,
                "ipa_dma %s:%d Context missing. refcnt=%d\n",
                "ipa_dma_init",
                219,
                *(_DWORD *)ipa_dma_init_refcnt_ctrl);
      }
      v36 = ipa3_get_ipc_logbuf_low(v34);
      if ( v36 )
      {
        v37 = ipa3_get_ipc_logbuf_low(v36);
        ipc_log_string(
          v37,
          "ipa_dma %s:%d Context missing. refcnt=%d\n",
          "ipa_dma_init",
          219,
          *(_DWORD *)ipa_dma_init_refcnt_ctrl);
        v8 = -14;
        goto LABEL_102;
      }
LABEL_51:
      v8 = -14;
      goto LABEL_102;
    }
    if ( ipa3_dma_ctx )
    {
      v38 = printk(&unk_3FB10B, "ipa_dma_init");
      v39 = ipa3_get_ipc_logbuf(v38);
      if ( v39 )
      {
        v40 = ipa3_get_ipc_logbuf(v39);
        v39 = ipc_log_string(v40, "ipa_dma %s:%d Context already exist\n", "ipa_dma_init", 228);
      }
      v41 = ipa3_get_ipc_logbuf_low(v39);
      if ( v41 )
      {
        v42 = ipa3_get_ipc_logbuf_low(v41);
        ipc_log_string(v42, "ipa_dma %s:%d Context already exist\n", "ipa_dma_init", 228);
        v8 = -14;
        goto LABEL_102;
      }
      goto LABEL_51;
    }
    if ( (ipa_is_ready(v3) & 1) == 0 )
    {
      v43 = printk(&unk_3F4E3B, "ipa_dma_init");
      v44 = ipa3_get_ipc_logbuf(v43);
      if ( v44 )
      {
        v45 = ipa3_get_ipc_logbuf(v44);
        v44 = ipc_log_string(v45, "ipa_dma %s:%d IPA is not ready yet\n", "ipa_dma_init", 234);
      }
      v46 = ipa3_get_ipc_logbuf_low(v44);
      if ( v46 )
      {
        v47 = ipa3_get_ipc_logbuf_low(v46);
        ipc_log_string(v47, "ipa_dma %s:%d IPA is not ready yet\n", "ipa_dma_init", 234);
      }
      v8 = -22;
      goto LABEL_102;
    }
    v9 = _kmalloc_cache_noprof(scnprintf, 3520, 296);
    if ( !v9 )
    {
      v8 = -12;
      goto LABEL_102;
    }
    memset(v137, 0, 32);
    args = _kmem_cache_create_args("IPA DMA XFER WRAPPER", 88, v137, 0);
    *(_QWORD *)(v9 + 8) = args;
    if ( !args )
    {
      printk(&unk_3CF747, "ipa_dma_init");
      v48 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_94;
      v49 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v49 )
      {
        ipc_log_string(v49, "ipa %s:%d :failed to create ipa dma xfer wrapper cache.\n", "ipa_dma_init", 250);
        v48 = ipa3_ctx;
      }
      v50 = *(_QWORD *)(v48 + 34160);
      if ( v50 )
      {
        ipc_log_string(v50, "ipa %s:%d :failed to create ipa dma xfer wrapper cache.\n", "ipa_dma_init", 250);
        v8 = -12;
      }
      else
      {
LABEL_94:
        v8 = -12;
      }
      goto LABEL_83;
    }
    _mutex_init(v9 + 72, "&ipa_dma_ctx_t->enable_lock", &ipa_dma_init___key);
    *(_DWORD *)(v9 + 64) = 0;
    _mutex_init(v9 + 16, "&ipa_dma_ctx_t->sync_lock", &ipa_dma_init___key_22);
    *(_DWORD *)(v9 + 120) = 0;
    *(_DWORD *)(v9 + 128) = 0;
    _init_swait_queue_head(v9 + 136, "&x->wait", &init_completion___key_0);
    *(_DWORD *)v9 = 0;
    *(_BYTE *)(v9 + 4) = 0;
    *(_DWORD *)(v9 + 180) = 0;
    *(_DWORD *)(v9 + 176) = 0;
    *(_DWORD *)(v9 + 184) = 0;
    *(_DWORD *)(v9 + 192) = 0;
    *(_DWORD *)(v9 + 188) = 0;
    *(_DWORD *)(v9 + 196) = 0;
    if ( (unsigned int)ipa_get_hw_type() == 12 )
    {
      v11 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34216), 32, v9 + 208, 3264, 0);
      *(_QWORD *)(v9 + 200) = v11;
      if ( !v11 )
      {
        printk(&unk_3E623D, "ipa_dma_init");
        v101 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_100;
        v102 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v102 )
        {
          ipc_log_string(v102, "ipa %s:%d DMA alloc fail %d bytes for prefetch WA\n", "ipa_dma_init", 287, 8);
          v101 = ipa3_ctx;
        }
        v103 = *(_QWORD *)(v101 + 34160);
        if ( v103 )
        {
          ipc_log_string(v103, "ipa %s:%d DMA alloc fail %d bytes for prefetch WA\n", "ipa_dma_init", 287, 8);
          v8 = -12;
        }
        else
        {
LABEL_100:
          v8 = -12;
        }
LABEL_82:
        kmem_cache_destroy(*(_QWORD *)(v9 + 8));
LABEL_83:
        kfree(v9);
        ipa3_dma_ctx = 0;
        goto LABEL_102;
      }
      v12 = *(_QWORD *)(v9 + 208);
      v13 = 4096;
      v14 = 65520;
      *(_QWORD *)(v9 + 224) = v11 + 8;
      *(_QWORD *)(v9 + 232) = v12 + 8;
      *(_QWORD *)(v9 + 248) = v11 + 16;
      *(_QWORD *)(v9 + 256) = v12 + 16;
      *(_QWORD *)(v9 + 272) = v11 + 24;
      *(_QWORD *)(v9 + 280) = v12 + 24;
    }
    else
    {
      v13 = 2048;
      v14 = 32760;
    }
    v130 = 0;
    LODWORD(v129) = 44;
    HIDWORD(v129) = v13;
    v135 = 0;
    v136 = 0;
    v133 = 0;
    v134 = 0;
    v131 = nullptr;
    v132 = 0;
    v127 = 0;
    v128 = 0;
    v125 = 0;
    v126 = 0;
    v123 = 0;
    v124 = 0;
    v121 = 0;
    v122 = 0;
    v119 = 0;
    v120 = 0;
    v117 = 0;
    v118 = 0;
    v115 = 0;
    v113 = 0;
    v114 = 0;
    v111 = 0;
    v112 = 0;
    v109 = 0;
    v110 = 0;
    v107 = 0;
    v108 = 0;
    v105 = 0;
    v106 = 0;
    v116 = 0x2D00000003LL;
    if ( (unsigned int)ipa_setup_sys_pipe(&v105, v9 + 160) )
    {
      v51 = printk(&unk_3E93BA, "ipa_dma_init");
      v52 = ipa3_get_ipc_logbuf(v51);
      if ( v52 )
      {
        v53 = ipa3_get_ipc_logbuf(v52);
        v52 = ipc_log_string(v53, "ipa_dma %s:%d :setup sync prod pipe failed\n", "ipa_dma_init", 321);
      }
      v54 = ipa3_get_ipc_logbuf_low(v52);
      if ( v54 )
      {
        v55 = ipa3_get_ipc_logbuf_low(v54);
        ipc_log_string(v55, "ipa_dma %s:%d :setup sync prod pipe failed\n", "ipa_dma_init", 321);
      }
    }
    else
    {
      v135 = 0;
      v136 = 0;
      v133 = 0;
      v134 = 0;
      v127 = 0;
      v128 = 0;
      v125 = 0;
      v126 = 0;
      v123 = 0;
      v124 = 0;
      v121 = 0;
      v122 = 0;
      v119 = 0;
      v120 = 0;
      v117 = 0;
      v118 = 0;
      v115 = 0;
      v116 = 0;
      v113 = 0;
      v114 = 0;
      v111 = 0;
      v112 = 0;
      v109 = 0;
      v110 = 0;
      v107 = 0;
      v108 = 0;
      v105 = 0;
      v106 = 0;
      LODWORD(v129) = 45;
      HIDWORD(v129) = v13;
      v130 = 0;
      v131 = nullptr;
      v132 = 0;
      v15 = ipa_setup_sys_pipe(&v105, v9 + 168);
      if ( (_DWORD)v15 )
      {
        v56 = printk(&unk_3B7D7F, "ipa_dma_init");
        v57 = ipa3_get_ipc_logbuf(v56);
        if ( v57 )
        {
          v58 = ipa3_get_ipc_logbuf(v57);
          v57 = ipc_log_string(v58, "ipa_dma %s:%d :setup sync cons pipe failed.\n", "ipa_dma_init", 336);
        }
        v59 = ipa3_get_ipc_logbuf_low(v57);
        if ( v59 )
        {
          v67 = ipa3_get_ipc_logbuf_low(v59);
          ipc_log_string(v67, "ipa_dma %s:%d :setup sync cons pipe failed.\n", "ipa_dma_init", 336);
        }
      }
      else
      {
        v16 = ipa3_get_ipc_logbuf(v15);
        if ( v16 )
        {
          v17 = ipa3_get_ipc_logbuf(v16);
          v16 = ipc_log_string(v17, "ipa_dma %s:%d SYNC MEMCPY pipes are connected\n", "ipa_dma_init", 341);
        }
        v18 = ipa3_get_ipc_logbuf_low(v16);
        if ( v18 )
        {
          v19 = ipa3_get_ipc_logbuf_low(v18);
          ipc_log_string(v19, "ipa_dma %s:%d SYNC MEMCPY pipes are connected\n", "ipa_dma_init", 341);
        }
        v128 = 0;
        LODWORD(v129) = 46;
        HIDWORD(v129) = v14;
        v135 = 0;
        v136 = 0;
        v133 = 0;
        v134 = 0;
        v130 = 0;
        v126 = 0;
        v127 = 0;
        v124 = 0;
        v125 = 0;
        v122 = 0;
        v123 = 0;
        v120 = 0;
        v121 = 0;
        v118 = 0;
        v119 = 0;
        v115 = 0;
        v113 = 0;
        v114 = 0;
        v111 = 0;
        v112 = 0;
        v109 = 0;
        v110 = 0;
        v107 = 0;
        v108 = 0;
        v105 = 0;
        v106 = 0;
        v116 = 0x2F00000003LL;
        v117 = 0;
        v131 = nullptr;
        v132 = 0;
        if ( (unsigned int)ipa_setup_sys_pipe(&v105, v9 + 164) )
        {
          v68 = printk(&unk_3BDC03, "ipa_dma_init");
          v69 = ipa3_get_ipc_logbuf(v68);
          if ( v69 )
          {
            v70 = ipa3_get_ipc_logbuf(v69);
            v69 = ipc_log_string(v70, "ipa_dma %s:%d :setup async prod pipe failed.\n", "ipa_dma_init", 353);
          }
          v71 = ipa3_get_ipc_logbuf_low(v69);
          if ( v71 )
          {
            v79 = ipa3_get_ipc_logbuf_low(v71);
            ipc_log_string(v79, "ipa_dma %s:%d :setup async prod pipe failed.\n", "ipa_dma_init", 353);
          }
        }
        else
        {
          v130 = 0;
          LODWORD(v129) = 47;
          HIDWORD(v129) = v14;
          v135 = 0;
          v136 = 0;
          v134 = 0;
          v132 = 0;
          v127 = 0;
          v128 = 0;
          v125 = 0;
          v126 = 0;
          v123 = 0;
          v124 = 0;
          v121 = 0;
          v122 = 0;
          v119 = 0;
          v120 = 0;
          v117 = 0;
          v118 = 0;
          v115 = 0;
          v116 = 0;
          v113 = 0;
          v114 = 0;
          v111 = 0;
          v112 = 0;
          v109 = 0;
          v110 = 0;
          v107 = 0;
          v108 = 0;
          v105 = 0;
          v106 = 0;
          v133 = 0;
          v131 = ipa3_dma_async_memcpy_notify_cb;
          if ( !(unsigned int)ipa_setup_sys_pipe(&v105, v9 + 172) )
          {
            dir = debugfs_create_dir("ipa_dma", 0);
            dent_0 = dir;
            if ( dir >= 0xFFFFFFFFFFFFF001LL )
            {
              v92 = printk(&unk_3FDC4E, "ipa3_dma_debugfs_init");
              v93 = ipa3_get_ipc_logbuf(v92);
              if ( v93 )
              {
                v94 = ipa3_get_ipc_logbuf(v93);
                v93 = ipc_log_string(
                        v94,
                        "ipa_dma %s:%d fail to create folder ipa_dma\n",
                        "ipa3_dma_debugfs_init",
                        1229);
              }
              file = ipa3_get_ipc_logbuf_low(v93);
              if ( file )
              {
                v95 = ipa3_get_ipc_logbuf_low(file);
                file = ipc_log_string(
                         v95,
                         "ipa_dma %s:%d fail to create folder ipa_dma\n",
                         "ipa3_dma_debugfs_init",
                         1229);
              }
            }
            else
            {
              file = debugfs_create_file("info", 438, dir, 0, &ipa3_ipadma_stats_ops);
              dfile_info = file;
              if ( !file || file >= 0xFFFFFFFFFFFFF001LL )
              {
                v96 = printk(&unk_3F4F10, "ipa3_dma_debugfs_init");
                v97 = ipa3_get_ipc_logbuf(v96);
                if ( v97 )
                {
                  v98 = ipa3_get_ipc_logbuf(v97);
                  v97 = ipc_log_string(v98, "ipa_dma %s:%d fail to create file stats\n", "ipa3_dma_debugfs_init", 1237);
                }
                v99 = ipa3_get_ipc_logbuf_low(v97);
                if ( v99 )
                {
                  v100 = ipa3_get_ipc_logbuf_low(v99);
                  ipc_log_string(v100, "ipa_dma %s:%d fail to create file stats\n", "ipa3_dma_debugfs_init", 1237);
                }
                file = debugfs_remove(dent_0);
              }
            }
            ipa3_dma_ctx = v9;
            *(_DWORD *)ipa_dma_init_refcnt_ctrl = 1;
            v22 = ipa3_get_ipc_logbuf(file);
            if ( v22 )
            {
              v23 = ipa3_get_ipc_logbuf(v22);
              v22 = ipc_log_string(v23, "ipa_dma %s:%d ASYNC MEMCPY pipes are connected\n", "ipa_dma_init", 375);
            }
            v24 = ipa3_get_ipc_logbuf_low(v22);
            if ( v24 )
            {
              v25 = ipa3_get_ipc_logbuf_low(v24);
              v24 = ipc_log_string(v25, "ipa_dma %s:%d ASYNC MEMCPY pipes are connected\n", "ipa_dma_init", 375);
            }
            v26 = ipa3_get_ipc_logbuf_low(v24);
            if ( v26 )
            {
              v27 = ipa3_get_ipc_logbuf_low(v26);
              ipc_log_string(v27, "ipa_dma %s:%d EXIT\n", "ipa_dma_init", 377);
            }
            v8 = 0;
            goto LABEL_102;
          }
          v80 = printk(&unk_3F4E61, "ipa_dma_init");
          v81 = ipa3_get_ipc_logbuf(v80);
          if ( v81 )
          {
            v82 = ipa3_get_ipc_logbuf(v81);
            v81 = ipc_log_string(v82, "ipa_dma %s:%d :setup async cons pipe failed.\n", "ipa_dma_init", 368);
          }
          v83 = ipa3_get_ipc_logbuf_low(v81);
          if ( v83 )
          {
            v91 = ipa3_get_ipc_logbuf_low(v83);
            ipc_log_string(v91, "ipa_dma %s:%d :setup async cons pipe failed.\n", "ipa_dma_init", 368);
          }
          ipa_teardown_sys_pipe(*(unsigned int *)(v9 + 164), v84, v85, v86, v87, v88, v89, v90);
        }
        ipa_teardown_sys_pipe(*(unsigned int *)(v9 + 168), v72, v73, v74, v75, v76, v77, v78);
      }
      ipa_teardown_sys_pipe(*(unsigned int *)(v9 + 160), v60, v61, v62, v63, v64, v65, v66);
    }
    dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), 32, *(_QWORD *)(v9 + 200), *(_QWORD *)(v9 + 208), 0);
    v8 = -1;
    goto LABEL_82;
  }
  v28 = printk(&unk_3BDBAD, "ipa_dma_init");
  v29 = ipa3_get_ipc_logbuf(v28);
  if ( v29 )
  {
    v30 = ipa3_get_ipc_logbuf(v29);
    v29 = ipc_log_string(v30, "ipa_dma %s:%d Setup isn't done yet!\n", "ipa_dma_init", 209);
  }
  v31 = ipa3_get_ipc_logbuf_low(v29);
  if ( v31 )
  {
    v32 = ipa3_get_ipc_logbuf_low(v31);
    ipc_log_string(v32, "ipa_dma %s:%d Setup isn't done yet!\n", "ipa_dma_init", 209);
  }
  v8 = -22;
LABEL_103:
  _ReadStatusReg(SP_EL0);
  return v8;
}
