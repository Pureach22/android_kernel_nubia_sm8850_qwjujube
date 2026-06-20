__int64 __fastcall rmnet_ipa3_enable_per_client_stats(char *a1)
{
  _BYTE *v2; // x19
  unsigned __int16 *v3; // x21
  char v4; // w8
  unsigned int v5; // w0
  unsigned int v7; // w20
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0

  v2 = (_BYTE *)_kmalloc_cache_noprof(sg_next, 3520, 1);
  if ( v2 )
  {
    v3 = (unsigned __int16 *)_kmalloc_cache_noprof(sg_next, 3520, 4);
    if ( v3 )
    {
      v4 = *a1;
      *(_DWORD *)v3 = 0;
      *v2 = v4;
      v5 = ipa3_qmi_enable_per_client_stats((__int64)v2, v3);
      if ( v5 )
      {
        v7 = v5;
        printk(&unk_3BC394, "rmnet_ipa3_enable_per_client_stats");
        if ( ipa3_get_ipc_logbuf() )
        {
          ipc_logbuf = ipa3_get_ipc_logbuf();
          ipc_log_string(
            ipc_logbuf,
            "ipa-wan %s:%d can't enable per client stats\n",
            "rmnet_ipa3_enable_per_client_stats",
            6248);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipa-wan %s:%d can't enable per client stats\n",
            "rmnet_ipa3_enable_per_client_stats",
            6248);
        }
        kfree(v2);
        kfree(v3);
        return v7;
      }
      else
      {
        kfree(v2);
        kfree(v3);
        return 0;
      }
    }
    else
    {
      printk(&unk_3F91BF, "rmnet_ipa3_enable_per_client_stats");
      if ( ipa3_get_ipc_logbuf() )
      {
        v12 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v12,
          "ipa-wan %s:%d Can't allocate memory for stats message\n",
          "rmnet_ipa3_enable_per_client_stats",
          6232);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v13 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v13,
          "ipa-wan %s:%d Can't allocate memory for stats message\n",
          "rmnet_ipa3_enable_per_client_stats",
          6232);
      }
      kfree(v2);
      return 4294967284LL;
    }
  }
  else
  {
    printk(&unk_3F91BF, "rmnet_ipa3_enable_per_client_stats");
    if ( ipa3_get_ipc_logbuf() )
    {
      v10 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v10,
        "ipa-wan %s:%d Can't allocate memory for stats message\n",
        "rmnet_ipa3_enable_per_client_stats",
        6225);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v11 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v11,
        "ipa-wan %s:%d Can't allocate memory for stats message\n",
        "rmnet_ipa3_enable_per_client_stats",
        6225);
    }
    return 4294967284LL;
  }
}
