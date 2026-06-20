__int64 __fastcall ipa_mhi_init(_DWORD *a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x10
  __int64 v23; // x11
  __int64 v24; // x8
  __int64 v25; // x9
  __int64 v26; // x0
  unsigned int v27; // w0
  int v28; // w0
  unsigned int v29; // w0
  unsigned int v30; // w0
  unsigned int v31; // w0
  unsigned int v32; // w0
  __int64 v33; // x0
  __int64 v34; // x0
  unsigned __int64 dir; // x0
  unsigned __int64 file; // x0
  unsigned __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 result; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  unsigned int v51; // w19
  __int64 v52; // x0
  __int64 v53; // x0
  int v54; // w19
  __int64 v55; // x0
  __int64 v56; // x0
  unsigned int v57; // w19
  __int64 v58; // x0
  long double v59; // q0
  __int64 v60; // x0
  unsigned int v61; // w19
  __int64 v62; // x0
  __int64 v63; // x0
  unsigned int v64; // w19
  __int64 v65; // x0
  __int64 v66; // x0
  unsigned int v67; // w19
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
  const char *v79; // [xsp+8h] [xbp-28h] BYREF
  __int64 (__fastcall *v80)(); // [xsp+10h] [xbp-20h]
  __int64 v81; // [xsp+18h] [xbp-18h]
  __int64 v82; // [xsp+20h] [xbp-10h]
  __int64 v83; // [xsp+28h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_init", 2276);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_init", 2276);
  }
  if ( !a1 )
  {
    printk(&unk_3CE387, "ipa_mhi_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      v43 = ipa3_get_ipc_logbuf();
      ipc_log_string(v43, "ipa_mhi_client %s:%d null args\n", "ipa_mhi_init", 2279);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v44 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v44, "ipa_mhi_client %s:%d null args\n", "ipa_mhi_init", 2279);
LABEL_73:
      result = 4294967274LL;
      goto LABEL_133;
    }
LABEL_79:
    result = 4294967274LL;
    goto LABEL_133;
  }
  if ( !*((_QWORD *)a1 + 4) )
  {
    printk(&unk_3AE255, "ipa_mhi_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      v45 = ipa3_get_ipc_logbuf();
      ipc_log_string(v45, "ipa_mhi_client %s:%d null notify function\n", "ipa_mhi_init", 2284);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v46 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v46, "ipa_mhi_client %s:%d null notify function\n", "ipa_mhi_init", 2284);
      goto LABEL_73;
    }
    goto LABEL_79;
  }
  if ( !ipa_mhi_client_ctx )
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      v4 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v4,
        "ipa_mhi_client %s:%d notify = %pS priv = %pK\n",
        "ipa_mhi_init",
        2293,
        *((const void **)a1 + 4),
        *((const void **)a1 + 5));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v5 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v5,
        "ipa_mhi_client %s:%d notify = %pS priv = %pK\n",
        "ipa_mhi_init",
        2293,
        *((const void **)a1 + 4),
        *((const void **)a1 + 5));
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v6 = ipa3_get_ipc_logbuf();
      ipc_log_string(v6, "ipa_mhi_client %s:%d msi: addr_lo = 0x%x addr_hi = 0x%x\n", "ipa_mhi_init", 2295, *a1, a1[1]);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v7 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v7, "ipa_mhi_client %s:%d msi: addr_lo = 0x%x addr_hi = 0x%x\n", "ipa_mhi_init", 2295, *a1, a1[1]);
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v8 = ipa3_get_ipc_logbuf();
      ipc_log_string(v8, "ipa_mhi_client %s:%d msi: data = 0x%x mask = 0x%x\n", "ipa_mhi_init", 2297, a1[2], a1[3]);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v9, "ipa_mhi_client %s:%d msi: data = 0x%x mask = 0x%x\n", "ipa_mhi_init", 2297, a1[2], a1[3]);
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v10 = ipa3_get_ipc_logbuf();
      ipc_log_string(v10, "ipa_mhi_client %s:%d mmio_addr = 0x%x\n", "ipa_mhi_init", 2298, a1[4]);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v11 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v11, "ipa_mhi_client %s:%d mmio_addr = 0x%x\n", "ipa_mhi_init", 2298, a1[4]);
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v12 = ipa3_get_ipc_logbuf();
      ipc_log_string(v12, "ipa_mhi_client %s:%d first_ch_idx = 0x%x\n", "ipa_mhi_init", 2299, a1[5]);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v13 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v13, "ipa_mhi_client %s:%d first_ch_idx = 0x%x\n", "ipa_mhi_init", 2299, a1[5]);
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v14 = ipa3_get_ipc_logbuf();
      ipc_log_string(v14, "ipa_mhi_client %s:%d first_er_idx = 0x%x\n", "ipa_mhi_init", 2300, a1[6]);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v15 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v15, "ipa_mhi_client %s:%d first_er_idx = 0x%x\n", "ipa_mhi_init", 2300, a1[6]);
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v16 = ipa3_get_ipc_logbuf();
      ipc_log_string(v16, "ipa_mhi_client %s:%d assert_bit40=%d\n", "ipa_mhi_init", 2301, *((unsigned __int8 *)a1 + 28));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v17 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v17, "ipa_mhi_client %s:%d assert_bit40=%d\n", "ipa_mhi_init", 2301, *((unsigned __int8 *)a1 + 28));
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v18 = ipa3_get_ipc_logbuf();
      ipc_log_string(v18, "ipa_mhi_client %s:%d test_mode=%d\n", "ipa_mhi_init", 2302, *((unsigned __int8 *)a1 + 48));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v19 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v19, "ipa_mhi_client %s:%d test_mode=%d\n", "ipa_mhi_init", 2302, *((unsigned __int8 *)a1 + 48));
    }
    v20 = _kmalloc_cache_noprof(__ratelimit, 3520, 1320);
    ipa_mhi_client_ctx = v20;
    if ( !v20 )
    {
      result = 4294967282LL;
      goto LABEL_133;
    }
    v21 = *(_QWORD *)a1;
    v22 = *((_QWORD *)a1 + 1);
    v23 = *((_QWORD *)a1 + 2);
    *(_DWORD *)(v20 + 1316) = 0;
    *(_QWORD *)(v20 + 1244) = v21;
    *(_QWORD *)(v20 + 1252) = v22;
    *(_QWORD *)(v20 + 1260) = v23;
    v24 = *((_QWORD *)a1 + 4);
    v25 = *((_QWORD *)a1 + 5);
    *(_QWORD *)v20 = 0;
    *(_QWORD *)(v20 + 8) = v24;
    LODWORD(v24) = a1[6];
    *(_QWORD *)(v20 + 16) = v25;
    LOBYTE(v25) = *((_BYTE *)a1 + 28);
    *(_DWORD *)(v20 + 1268) = v24;
    *(_QWORD *)(v20 + 1296) = 0x100000000LL;
    LOBYTE(v24) = *((_BYTE *)a1 + 48);
    *(_BYTE *)(v20 + 1304) = v25;
    *(_BYTE *)(v20 + 1305) = v24;
    v26 = alloc_workqueue("%s", (const char *)0x6000A);
    *(_QWORD *)(ipa_mhi_client_ctx + 32) = v26;
    if ( v26 )
    {
      v27 = ipa_dma_init(v26);
      if ( v27 )
      {
        v51 = v27;
        printk(&unk_3D7043, "ipa_mhi_init");
        if ( ipa3_get_ipc_logbuf() )
        {
          v52 = ipa3_get_ipc_logbuf();
          ipc_log_string(v52, "ipa_mhi_client %s:%d failed to init ipa dma %d\n", "ipa_mhi_init", 2334, v51);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v53 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v53, "ipa_mhi_client %s:%d failed to init ipa dma %d\n", "ipa_mhi_init", 2334, v51);
        }
      }
      else
      {
        v81 = 0;
        v82 = 0;
        v79 = "MHI";
        v80 = ipa_mhi_pm_cb;
        v28 = ipa_pm_register((__int64)&v79, (unsigned int *)(ipa_mhi_client_ctx + 1308));
        if ( v28 )
        {
          v54 = v28;
          printk(&unk_3FF7DD, "ipa_mhi_register_pm");
          if ( ipa3_get_ipc_logbuf() )
          {
            v55 = ipa3_get_ipc_logbuf();
            ipc_log_string(v55, "ipa_mhi_client %s:%d fail to register with PM %d\n", "ipa_mhi_register_pm", 2215, v54);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v56 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v56, "ipa_mhi_client %s:%d fail to register with PM %d\n", "ipa_mhi_register_pm", 2215, v54);
          }
        }
        else
        {
          v29 = ipa_pm_associate_ipa_cons_to_client(*(_DWORD *)(ipa_mhi_client_ctx + 1308), 0x2Bu);
          if ( v29 )
          {
            v57 = v29;
            printk(&unk_3BF5FC, "ipa_mhi_register_pm");
            if ( ipa3_get_ipc_logbuf() )
            {
              v58 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v58,
                "ipa_mhi_client %s:%d fail to associate cons with PM %d\n",
                "ipa_mhi_register_pm",
                2222,
                v57);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v60 = ipa3_get_ipc_logbuf_low();
              v59 = ipc_log_string(
                      v60,
                      "ipa_mhi_client %s:%d fail to associate cons with PM %d\n",
                      "ipa_mhi_register_pm",
                      2222,
                      v57);
            }
          }
          else
          {
            v30 = ipa_pm_associate_ipa_cons_to_client(*(_DWORD *)(ipa_mhi_client_ctx + 1308), 0x6Fu);
            if ( v30 )
            {
              v61 = v30;
              printk(&unk_3C59B2, "ipa_mhi_register_pm");
              if ( ipa3_get_ipc_logbuf() )
              {
                v62 = ipa3_get_ipc_logbuf();
                ipc_log_string(
                  v62,
                  "ipa_mhi_client %s:%d fail to associate low_lat_cons with PM %d\n",
                  "ipa_mhi_register_pm",
                  2229,
                  v61);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v63 = ipa3_get_ipc_logbuf_low();
                v59 = ipc_log_string(
                        v63,
                        "ipa_mhi_client %s:%d fail to associate low_lat_cons with PM %d\n",
                        "ipa_mhi_register_pm",
                        2229,
                        v61);
              }
            }
            else
            {
              v31 = ((__int64 (__fastcall *)(_QWORD, __int64))ipa_pm_set_throughput)(
                      *(unsigned int *)(ipa_mhi_client_ctx + 1308),
                      1000);
              if ( v31 )
              {
                v64 = v31;
                printk(&unk_3CB010, "ipa_mhi_register_pm");
                if ( ipa3_get_ipc_logbuf() )
                {
                  v65 = ipa3_get_ipc_logbuf();
                  ipc_log_string(
                    v65,
                    "ipa_mhi_client %s:%d fail to set perf profile to PM %d\n",
                    "ipa_mhi_register_pm",
                    2235,
                    v64);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v66 = ipa3_get_ipc_logbuf_low();
                  v59 = ipc_log_string(
                          v66,
                          "ipa_mhi_client %s:%d fail to set perf profile to PM %d\n",
                          "ipa_mhi_register_pm",
                          2235,
                          v64);
                }
              }
              else
              {
                v79 = "MODEM (MHI)";
                v81 = 0;
                v82 = 0x100000002LL;
                v80 = nullptr;
                v32 = ipa_pm_register((__int64)&v79, (unsigned int *)(ipa_mhi_client_ctx + 1312));
                if ( !v32 )
                {
                  ((void (__fastcall *)(__int64))ipa_mhi_set_state)(1);
                  ipa3_register_client_callback((__int64)ipa_mhi_set_lock_unlock, 0, 0x2Au);
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v33 = ipa3_get_ipc_logbuf();
                    ipc_log_string(v33, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_debugfs_init", 450);
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v34 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(v34, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_debugfs_init", 450);
                  }
                  dir = debugfs_create_dir("ipa_mhi", 0);
                  dent_2 = dir;
                  if ( dir >= 0xFFFFFFFFFFFFF001LL )
                  {
                    printk(&unk_3D9E90, "ipa_mhi_debugfs_init");
                    if ( ipa3_get_ipc_logbuf() )
                    {
                      v73 = ipa3_get_ipc_logbuf();
                      ipc_log_string(
                        v73,
                        "ipa_mhi_client %s:%d fail to create folder ipa_mhi\n",
                        "ipa_mhi_debugfs_init",
                        454);
                    }
                    if ( ipa3_get_ipc_logbuf_low() )
                    {
                      v74 = ipa3_get_ipc_logbuf_low();
                      ipc_log_string(
                        v74,
                        "ipa_mhi_client %s:%d fail to create folder ipa_mhi\n",
                        "ipa_mhi_debugfs_init",
                        454);
                    }
                    goto LABEL_61;
                  }
                  file = debugfs_create_file("stats", 292, dir, 0, &ipa_mhi_stats_ops);
                  if ( file && file < 0xFFFFFFFFFFFFF001LL )
                  {
                    debugfs_create_u32("use_ipadma", 436, dent_2, ipa_mhi_client_ctx + 1300);
                    v37 = debugfs_create_file(
                            "dump_host_channel_ctx_array",
                            292,
                            dent_2,
                            0,
                            &ipa_mhi_dump_host_ch_ctx_ops);
                    if ( v37 && v37 < 0xFFFFFFFFFFFFF001LL )
                    {
                      if ( ipa3_get_ipc_logbuf() )
                      {
                        v38 = ipa3_get_ipc_logbuf();
                        ipc_log_string(v38, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_debugfs_init", 475);
                      }
                      if ( ipa3_get_ipc_logbuf_low() )
                      {
                        v39 = ipa3_get_ipc_logbuf_low();
                        ipc_log_string(v39, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_debugfs_init", 475);
                      }
                      goto LABEL_61;
                    }
                    printk(&unk_3FCB02, "ipa_mhi_debugfs_init");
                    if ( ipa3_get_ipc_logbuf() )
                    {
                      v77 = ipa3_get_ipc_logbuf();
                      ipc_log_string(
                        v77,
                        "ipa_mhi_client %s:%d fail to create file dump_host_channel_ctx_arr\n",
                        "ipa_mhi_debugfs_init",
                        471);
                    }
                    if ( ipa3_get_ipc_logbuf_low() )
                    {
                      v78 = ipa3_get_ipc_logbuf_low();
                      ipc_log_string(
                        v78,
                        "ipa_mhi_client %s:%d fail to create file dump_host_channel_ctx_arr\n",
                        "ipa_mhi_debugfs_init",
                        471);
                    }
                  }
                  else
                  {
                    printk(&unk_3B988D, "ipa_mhi_debugfs_init");
                    if ( ipa3_get_ipc_logbuf() )
                    {
                      v75 = ipa3_get_ipc_logbuf();
                      ipc_log_string(
                        v75,
                        "ipa_mhi_client %s:%d fail to create file stats\n",
                        "ipa_mhi_debugfs_init",
                        461);
                    }
                    if ( ipa3_get_ipc_logbuf_low() )
                    {
                      v76 = ipa3_get_ipc_logbuf_low();
                      ipc_log_string(
                        v76,
                        "ipa_mhi_client %s:%d fail to create file stats\n",
                        "ipa_mhi_debugfs_init",
                        461);
                    }
                  }
                  debugfs_remove(dent_2);
LABEL_61:
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v40 = ipa3_get_ipc_logbuf();
                    ipc_log_string(v40, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_init", 2353);
                  }
                  result = ipa3_get_ipc_logbuf_low();
                  if ( result )
                  {
                    v42 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(v42, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_init", 2353);
                    result = 0;
                  }
                  goto LABEL_133;
                }
                v67 = v32;
                printk(&unk_3FF7DD, "ipa_mhi_register_pm");
                if ( ipa3_get_ipc_logbuf() )
                {
                  v68 = ipa3_get_ipc_logbuf();
                  ipc_log_string(
                    v68,
                    "ipa_mhi_client %s:%d fail to register with PM %d\n",
                    "ipa_mhi_register_pm",
                    2246,
                    v67);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v69 = ipa3_get_ipc_logbuf_low();
                  v59 = ipc_log_string(
                          v69,
                          "ipa_mhi_client %s:%d fail to register with PM %d\n",
                          "ipa_mhi_register_pm",
                          2246,
                          v67);
                }
              }
            }
          }
          ((void (__fastcall *)(_QWORD, long double))ipa_pm_deregister)(
            *(unsigned int *)(ipa_mhi_client_ctx + 1308),
            v59);
          *(_DWORD *)(ipa_mhi_client_ctx + 1308) = -1;
        }
        printk(&unk_3E2420, "ipa_mhi_init");
        if ( ipa3_get_ipc_logbuf() )
        {
          v70 = ipa3_get_ipc_logbuf();
          ipc_log_string(v70, "ipa_mhi_client %s:%d failed to create PM resources\n", "ipa_mhi_init", 2340);
        }
        v71 = ipa3_get_ipc_logbuf_low();
        if ( v71 )
        {
          v72 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v72, "ipa_mhi_client %s:%d failed to create PM resources\n", "ipa_mhi_init", 2340);
        }
        ipa_dma_destroy(v71);
        v51 = -14;
      }
      destroy_workqueue(*(_QWORD *)(ipa_mhi_client_ctx + 32));
    }
    else
    {
      printk(&unk_3D9C68, "ipa_mhi_init");
      if ( ipa3_get_ipc_logbuf() )
      {
        v49 = ipa3_get_ipc_logbuf();
        ipc_log_string(v49, "ipa_mhi_client %s:%d failed to create workqueue\n", "ipa_mhi_init", 2327);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v50 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v50, "ipa_mhi_client %s:%d failed to create workqueue\n", "ipa_mhi_init", 2327);
      }
      v51 = -14;
    }
    kfree(ipa_mhi_client_ctx);
    ipa_mhi_client_ctx = 0;
    result = v51;
    goto LABEL_133;
  }
  printk(&unk_3BC8D2, "ipa_mhi_init");
  if ( ipa3_get_ipc_logbuf() )
  {
    v47 = ipa3_get_ipc_logbuf();
    ipc_log_string(v47, "ipa_mhi_client %s:%d already initialized\n", "ipa_mhi_init", 2289);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v48 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v48, "ipa_mhi_client %s:%d already initialized\n", "ipa_mhi_init", 2289);
  }
  result = 0xFFFFFFFFLL;
LABEL_133:
  _ReadStatusReg(SP_EL0);
  return result;
}
