__int64 ipa3_wwan_init()
{
  _DWORD *v0; // x0
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 v3; // x20
  unsigned __int64 dir; // x0
  __int64 v5; // x1
  _QWORD *v6; // x20
  unsigned __int64 file; // x0
  unsigned __int64 v8; // x0
  unsigned int v9; // w19
  __int64 v10; // x0
  __int64 v11; // x0
  char v12; // w9
  unsigned __int64 v13; // x0
  int v14; // w20
  __int64 ipc_logbuf; // x0
  long double v16; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned __int64 v21; // x0
  _QWORD *v22; // x8
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0

  if ( ipa3_ctx )
  {
    v0 = (_DWORD *)_kmalloc_cache_noprof(dma_alloc_attrs, 3520, 2112);
    rmnet_ipa3_ctx = (__int64)v0;
    if ( !v0 )
      return (unsigned int)-12;
    v0[263] = 0;
    v0[264] = 0;
    v0[512] = 0;
    _mutex_init(v0 + 272, "&rmnet_ipa3_ctx->pipe_handle_guard", &ipa3_wwan_init___key);
    _mutex_init(rmnet_ipa3_ctx + 1136, "&rmnet_ipa3_ctx->add_mux_channel_lock", &ipa3_wwan_init___key_165);
    _mutex_init(rmnet_ipa3_ctx + 1200, "&rmnet_ipa3_ctx->per_client_stats_guard", &ipa3_wwan_init___key_167);
    _mutex_init(rmnet_ipa3_ctx + 2064, "&rmnet_ipa3_ctx->ioctl_guard", &ipa3_wwan_init___key_169);
    _mutex_init(rmnet_ipa3_ctx + 2000, "&rmnet_ipa3_ctx->clock_vote.mutex", &ipa3_wwan_init___key_171);
    prod_pipes_setup_complete = 0;
    egress_ioctl_v2_data = 0;
    qword_2017A8 = 0;
    ingress_ioctl_v2_data = 0;
    qword_2017B8 = 0;
    cons_pipes_setup_complete = 0;
    egress_param = 0;
    qword_2017C8 = 0;
    qword_2017D0 = 0;
    qword_2017D8 = 0;
    qword_2017E0 = 0;
    qword_2017E8 = 0;
    qword_2017F0 = 0;
    qword_2017F8 = 0;
    qword_201800 = 0;
    qword_201808 = 0;
    qword_201810 = 0;
    qword_201818 = 0;
    v1 = rmnet_ipa3_ctx;
    qword_2018B0 = 0;
    qword_2018B8 = 0;
    qword_2018A0 = 0;
    qword_2018A8 = 0;
    qword_201890 = 0;
    qword_201898 = 0;
    qword_201880 = 0;
    qword_201888 = 0;
    qword_201870 = 0;
    qword_201878 = 0;
    qword_201860 = 0;
    qword_201868 = 0;
    qword_201850 = 0;
    qword_201858 = 0;
    qword_201840 = 0;
    qword_201848 = 0;
    qword_201830 = 0;
    qword_201838 = 0;
    ingress_param = 0;
    qword_201828 = 0;
    *(_BYTE *)(rmnet_ipa3_ctx + 1266) = -1;
    *(_BYTE *)(v1 + 1274) = -1;
    *(_BYTE *)(v1 + 1282) = -1;
    *(_BYTE *)(v1 + 1290) = -1;
    *(_BYTE *)(v1 + 1298) = -1;
    *(_BYTE *)(v1 + 1306) = -1;
    *(_BYTE *)(v1 + 1314) = -1;
    *(_BYTE *)(v1 + 1322) = -1;
    *(_BYTE *)(v1 + 1330) = -1;
    *(_BYTE *)(v1 + 1338) = -1;
    *(_BYTE *)(v1 + 1346) = -1;
    *(_BYTE *)(v1 + 1354) = -1;
    *(_BYTE *)(v1 + 1362) = -1;
    *(_BYTE *)(v1 + 1370) = -1;
    *(_BYTE *)(v1 + 1378) = -1;
    *(_BYTE *)(v1 + 1386) = -1;
    *(_DWORD *)(v1 + 1420) = -1;
    *(_BYTE *)(v1 + 1438) = -1;
    *(_BYTE *)(v1 + 1446) = -1;
    *(_BYTE *)(v1 + 1454) = -1;
    *(_BYTE *)(v1 + 1462) = -1;
    *(_BYTE *)(v1 + 1470) = -1;
    *(_BYTE *)(v1 + 1478) = -1;
    *(_BYTE *)(v1 + 1486) = -1;
    *(_BYTE *)(v1 + 1494) = -1;
    *(_BYTE *)(v1 + 1502) = -1;
    *(_BYTE *)(v1 + 1510) = -1;
    *(_BYTE *)(v1 + 1518) = -1;
    *(_BYTE *)(v1 + 1526) = -1;
    *(_BYTE *)(v1 + 1534) = -1;
    *(_BYTE *)(v1 + 1542) = -1;
    *(_BYTE *)(v1 + 1550) = -1;
    *(_BYTE *)(v1 + 1558) = -1;
    *(_DWORD *)(v1 + 1592) = -1;
    *(_BYTE *)(v1 + 1610) = -1;
    *(_BYTE *)(v1 + 1618) = -1;
    *(_BYTE *)(v1 + 1626) = -1;
    *(_BYTE *)(v1 + 1634) = -1;
    *(_BYTE *)(v1 + 1642) = -1;
    *(_BYTE *)(v1 + 1650) = -1;
    *(_BYTE *)(v1 + 1658) = -1;
    *(_BYTE *)(v1 + 1666) = -1;
    *(_BYTE *)(v1 + 1674) = -1;
    *(_BYTE *)(v1 + 1682) = -1;
    *(_BYTE *)(v1 + 1690) = -1;
    *(_BYTE *)(v1 + 1698) = -1;
    *(_BYTE *)(v1 + 1706) = -1;
    *(_BYTE *)(v1 + 1714) = -1;
    *(_BYTE *)(v1 + 1722) = -1;
    *(_BYTE *)(v1 + 1730) = -1;
    *(_DWORD *)(v1 + 1764) = -1;
    *(_BYTE *)(v1 + 1782) = -1;
    *(_BYTE *)(v1 + 1790) = -1;
    *(_BYTE *)(v1 + 1798) = -1;
    *(_BYTE *)(v1 + 1806) = -1;
    *(_BYTE *)(v1 + 1814) = -1;
    *(_BYTE *)(v1 + 1822) = -1;
    *(_BYTE *)(v1 + 1830) = -1;
    *(_BYTE *)(v1 + 1838) = -1;
    *(_BYTE *)(v1 + 1846) = -1;
    *(_BYTE *)(v1 + 1854) = -1;
    *(_BYTE *)(v1 + 1862) = -1;
    *(_BYTE *)(v1 + 1870) = -1;
    *(_BYTE *)(v1 + 1878) = -1;
    *(_BYTE *)(v1 + 1886) = -1;
    *(_BYTE *)(v1 + 1894) = -1;
    *(_BYTE *)(v1 + 1902) = -1;
    v2 = rmnet_ipa3_ctx;
    *(_DWORD *)(v1 + 1248) = -1;
    *(_QWORD *)(v2 + 1080) = -1;
    ipa3_qmi_init();
    v3 = rmnet_ipa3_ctx;
    *(_QWORD *)(rmnet_ipa3_ctx + 1936) = 0x12000000100LL;
    *(_DWORD *)(v3 + 1944) = 128;
    dir = debugfs_create_dir("rmnet_ipa", 0);
    *(_QWORD *)(v3 + 1952) = dir;
    if ( dir >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_3ED4CC, v5);
    }
    else
    {
      v6 = (_QWORD *)(v3 + 1952);
      file = debugfs_create_file("mtu", 144, dir, 0, &unk_1E4788);
      if ( file && file < 0xFFFFFFFFFFFFF001LL )
      {
        debugfs_create_u32("outstanding_high", 436, *v6, rmnet_ipa3_ctx + 1936);
        debugfs_create_u32("outstanding_high_ctl", 436, *v6, rmnet_ipa3_ctx + 1940);
        debugfs_create_u32("outstanding_low", 436, *v6, rmnet_ipa3_ctx + 1944);
      }
      else
      {
        printk(&unk_3E09D4, "rmnet_ipa_debugfs_init");
        v24 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v25 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v25 )
          {
            ipc_log_string(
              v25,
              "ipa %s:%d fail to create file for debug_fs %s\n",
              "rmnet_ipa_debugfs_init",
              6578,
              "mtu");
            v24 = ipa3_ctx;
          }
          v26 = *(_QWORD *)(v24 + 34160);
          if ( v26 )
            ipc_log_string(
              v26,
              "ipa %s:%d fail to create file for debug_fs %s\n",
              "rmnet_ipa_debugfs_init",
              6578,
              "mtu");
        }
        debugfs_remove(*v6);
        v6[2] = 0;
        v6[3] = 0;
        *v6 = 0;
        v6[1] = 0;
      }
    }
    v8 = qcom_register_ssr_notifier("mpss", &ipa3_lcl_mdm_ssr_notifier);
    v9 = v8;
    if ( v8 <= 0xFFFFFFFFFFFFF000LL )
    {
      v12 = *(_BYTE *)(rmnet_ipa3_ctx + 1992);
      *(_QWORD *)(rmnet_ipa3_ctx + 1064) = v8;
      if ( (v12 & 1) == 0 )
        return 0;
      goto LABEL_19;
    }
    if ( (*(_BYTE *)(rmnet_ipa3_ctx + 1992) & 1) != 0 )
    {
      if ( !*(_BYTE *)(rmnet_ipa3_ctx + 1992) )
        return 0;
LABEL_19:
      v13 = qcom_register_ssr_notifier("esoc0", &ipa3_rmt_mdm_ssr_notifier);
      v14 = v13;
      if ( v13 < 0xFFFFFFFFFFFFF001LL )
      {
        v9 = 0;
        *(_QWORD *)(rmnet_ipa3_ctx + 1072) = v13;
        return v9;
      }
      if ( (unsigned int)__ratelimit(&ipa3_wwan_init__rs_178, "ipa3_wwan_init") )
      {
        printk(&unk_3B6267, "ipa3_wwan_init");
        if ( !ipa3_get_ipc_logbuf() )
          goto LABEL_23;
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_23:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          v16 = ipc_log_string(
                  ipc_logbuf_low,
                  "ipa-wan %s:%d remote modem ssr register fail rc=%d\n",
                  "ipa3_wwan_init",
                  6851,
                  v14);
        }
        v18 = *(_QWORD *)(rmnet_ipa3_ctx + 1064);
        if ( v18 )
        {
          qcom_unregister_ssr_notifier(v18, &ipa3_lcl_mdm_ssr_notifier, v16);
          *(_QWORD *)(rmnet_ipa3_ctx + 1064) = 0;
        }
        v9 = v14;
LABEL_34:
        v21 = *(_QWORD *)(rmnet_ipa3_ctx + 1952);
        if ( v21 <= 0xFFFFFFFFFFFFF000LL )
        {
          debugfs_remove(v21);
          v22 = (_QWORD *)rmnet_ipa3_ctx;
          *(_QWORD *)(rmnet_ipa3_ctx + 1952) = 0;
          v22[245] = 0;
          v22[246] = 0;
          v22[247] = 0;
        }
        return v9;
      }
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa-wan %s:%d remote modem ssr register fail rc=%d\n", "ipa3_wwan_init", 6851, v14);
      goto LABEL_23;
    }
    if ( (unsigned int)__ratelimit(&ipa3_wwan_init__rs_174, "ipa3_wwan_init") )
    {
      printk(&unk_3E77C8, "ipa3_wwan_init");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_32:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v20 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v20, "ipa-wan %s:%d local modem ssr register fail rc=%d\n", "ipa3_wwan_init", 6835, v9);
        }
        goto LABEL_34;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_32;
    }
    v19 = ipa3_get_ipc_logbuf();
    ipc_log_string(v19, "ipa-wan %s:%d local modem ssr register fail rc=%d\n", "ipa3_wwan_init", 6835, v9);
    goto LABEL_32;
  }
  if ( (unsigned int)__ratelimit(&ipa3_wwan_init__rs, "ipa3_wwan_init") )
  {
    printk(&unk_3BC3C3, "ipa3_wwan_init");
    if ( !ipa3_get_ipc_logbuf() )
      goto LABEL_14;
    goto LABEL_13;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
LABEL_13:
    v10 = ipa3_get_ipc_logbuf();
    ipc_log_string(v10, "ipa-wan %s:%d ipa3_ctx was not initialized\n", "ipa3_wwan_init", 6779);
  }
LABEL_14:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v11 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v11, "ipa-wan %s:%d ipa3_ctx was not initialized\n", "ipa3_wwan_init", 6779);
  }
  return (unsigned int)-22;
}
