__int64 ipa_tlpd_stats_init()
{
  unsigned int v0; // w22
  unsigned __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 ipc_logbuf; // x0
  __int64 v9; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int v17; // w19
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 result; // x0
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

  device = 0;
  if ( (unsigned int)alloc_chrdev_region(&device, 0, 1, "ipa_lnx_stats_ioctl") )
  {
    v7 = printk(&unk_3B2C62, "ipa_tlpd_stats_ioctl_init");
    ipc_logbuf = ipa3_get_ipc_logbuf(v7);
    if ( ipc_logbuf )
    {
      v9 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(v9, "ipa-lnx-stats %s:%d :device_alloc err.\n", "ipa_tlpd_stats_ioctl_init", 1884);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v11 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v11, "ipa-lnx-stats %s:%d :device_alloc err.\n", "ipa_tlpd_stats_ioctl_init", 1884);
    }
    goto LABEL_32;
  }
  v0 = device;
  v1 = class_create("ipa_lnx_stats_ioctl");
  class = v1;
  if ( v1 >= 0xFFFFFFFFFFFFF001LL )
  {
    v2 = printk(&unk_3C158D, "ipa_tlpd_stats_ioctl_init");
    v3 = ipa3_get_ipc_logbuf(v2);
    if ( v3 )
    {
      v4 = ipa3_get_ipc_logbuf(v3);
      v3 = ipc_log_string(v4, "ipa-lnx-stats %s:%d :class_create err.\n", "ipa_tlpd_stats_ioctl_init", 1892);
    }
    v5 = ipa3_get_ipc_logbuf_low(v3);
    if ( v5 )
    {
      v6 = ipa3_get_ipc_logbuf_low(v5);
      ipc_log_string(v6, "ipa-lnx-stats %s:%d :class_create err.\n", "ipa_tlpd_stats_ioctl_init", 1892);
    }
    goto LABEL_31;
  }
  if ( (unsigned __int64)device_create(v1, 0, (unsigned int)device, 0, "ipa_lnx_stats_ioctl") >= 0xFFFFFFFFFFFFF001LL )
  {
    v12 = printk(&unk_3CA31D, "ipa_tlpd_stats_ioctl_init");
    v13 = ipa3_get_ipc_logbuf(v12);
    if ( v13 )
    {
      v14 = ipa3_get_ipc_logbuf(v13);
      v13 = ipc_log_string(v14, "ipa-lnx-stats %s:%d :device_create err.\n", "ipa_tlpd_stats_ioctl_init", 1899);
    }
    v15 = ipa3_get_ipc_logbuf_low(v13);
    if ( v15 )
    {
      v16 = ipa3_get_ipc_logbuf_low(v15);
      ipc_log_string(v16, "ipa-lnx-stats %s:%d :device_create err.\n", "ipa_tlpd_stats_ioctl_init", 1899);
    }
LABEL_30:
    class_destroy(class);
LABEL_31:
    unregister_chrdev_region((unsigned int)device, 1);
LABEL_32:
    v33 = printk(&unk_3E4282, "ipa_tlpd_stats_init");
    v34 = ipa3_get_ipc_logbuf(v33);
    if ( v34 )
    {
      v35 = ipa3_get_ipc_logbuf(v34);
      v34 = ipc_log_string(
              v35,
              "ipa-lnx-stats %s:%d IPA_LNX_STATS_IOCTL init failure = %d\n",
              "ipa_tlpd_stats_init",
              1930,
              -19);
    }
    v36 = ipa3_get_ipc_logbuf_low(v34);
    if ( v36 )
    {
      v37 = ipa3_get_ipc_logbuf_low(v36);
      ipc_log_string(
        v37,
        "ipa-lnx-stats %s:%d IPA_LNX_STATS_IOCTL init failure = %d\n",
        "ipa_tlpd_stats_init",
        1930,
        -19);
    }
    return 0xFFFFFFFFLL;
  }
  cdev_init(&ipa_lnx_stats_ioctl_cdev, &ipa_stats_fops);
  if ( (unsigned int)cdev_add(&ipa_lnx_stats_ioctl_cdev, (unsigned int)device, 1) )
  {
    v28 = printk(&unk_3FE80D, "ipa_tlpd_stats_ioctl_init");
    v29 = ipa3_get_ipc_logbuf(v28);
    if ( v29 )
    {
      v30 = ipa3_get_ipc_logbuf(v29);
      v29 = ipc_log_string(v30, "ipa-lnx-stats %s:%d :cdev_add err.\n", "ipa_tlpd_stats_ioctl_init", 1906);
    }
    v31 = ipa3_get_ipc_logbuf_low(v29);
    if ( v31 )
    {
      v32 = ipa3_get_ipc_logbuf_low(v31);
      ipc_log_string(v32, "ipa-lnx-stats %s:%d :cdev_add err.\n", "ipa_tlpd_stats_ioctl_init", 1906);
    }
    device_destroy(class, (unsigned int)device);
    goto LABEL_30;
  }
  v17 = v0 >> 20;
  v18 = printk(&unk_3D8D0E, "ipa_tlpd_stats_ioctl_init");
  v19 = ipa3_get_ipc_logbuf(v18);
  if ( v19 )
  {
    v20 = ipa3_get_ipc_logbuf(v19);
    v19 = ipc_log_string(
            v20,
            "ipa-lnx-stats %s:%d IPA %s major(%d) initial ok :>>>>\n",
            "ipa_tlpd_stats_ioctl_init",
            1911,
            "ipa_lnx_stats_ioctl",
            v17);
  }
  v21 = ipa3_get_ipc_logbuf_low(v19);
  if ( v21 )
  {
    v22 = ipa3_get_ipc_logbuf_low(v21);
    ipc_log_string(
      v22,
      "ipa-lnx-stats %s:%d IPA %s major(%d) initial ok :>>>>\n",
      "ipa_tlpd_stats_ioctl_init",
      1911,
      "ipa_lnx_stats_ioctl",
      v17);
  }
  memset(&poll_pack_and_cred_info, 0, 0xA78u);
  memset(ipa_lnx_agent_ctx, 0, 0x22Cu);
  v23 = printk(&unk_3DBD88, "ipa_tlpd_stats_init");
  v24 = ipa3_get_ipc_logbuf(v23);
  if ( v24 )
  {
    v25 = ipa3_get_ipc_logbuf(v24);
    v24 = ipc_log_string(v25, "ipa-lnx-stats %s:%d IPA_LNX_STATS_IOCTL init success\n", "ipa_tlpd_stats_init", 1935);
  }
  result = ipa3_get_ipc_logbuf_low(v24);
  if ( result )
  {
    v27 = ipa3_get_ipc_logbuf_low(result);
    ipc_log_string(v27, "ipa-lnx-stats %s:%d IPA_LNX_STATS_IOCTL init success\n", "ipa_tlpd_stats_init", 1935);
    return 0;
  }
  return result;
}
