long double ipa3_del_a7_qmap_hdr()
{
  __int64 v0; // x0
  __int64 v1; // x19
  __int64 v2; // x9
  __int64 v3; // x0
  __int64 v4; // x0
  long double result; // q0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v8; // x0
  __int64 v9; // x0

  v0 = _kmalloc_cache_noprof(kfree, 3520, 12);
  v1 = v0;
  if ( v0 )
  {
    v2 = rmnet_ipa3_ctx;
    *(_WORD *)v0 = 257;
    *(_DWORD *)(v0 + 4) = *(_DWORD *)(v2 + 520);
    if ( !(unsigned int)ipa_del_hdr((_BYTE *)v0) && !*(_DWORD *)(v1 + 8) )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(ipc_logbuf, "ipa-wan %s:%d hdrs deletion done\n", "ipa3_del_a7_qmap_hdr", 335);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d hdrs deletion done\n", "ipa3_del_a7_qmap_hdr", 335);
      }
      goto LABEL_9;
    }
    if ( (unsigned int)__ratelimit(&ipa3_del_a7_qmap_hdr__rs_431, "ipa3_del_a7_qmap_hdr") )
    {
      printk(&unk_3A4C5A, "ipa3_del_a7_qmap_hdr");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_7:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v4 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v4, "ipa-wan %s:%d ipa_del_hdr failed\n", "ipa3_del_a7_qmap_hdr", 333);
        }
LABEL_9:
        *(_DWORD *)(rmnet_ipa3_ctx + 520) = 0;
        kfree(v1);
        return result;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_7;
    }
    v3 = ipa3_get_ipc_logbuf();
    ipc_log_string(v3, "ipa-wan %s:%d ipa_del_hdr failed\n", "ipa3_del_a7_qmap_hdr", 333);
    goto LABEL_7;
  }
  if ( !(unsigned int)__ratelimit(&ipa3_del_a7_qmap_hdr__rs, "ipa3_del_a7_qmap_hdr") )
  {
    if ( !ipa3_get_ipc_logbuf() )
      goto LABEL_19;
    goto LABEL_18;
  }
  printk(&unk_3C8338, "ipa3_del_a7_qmap_hdr");
  if ( ipa3_get_ipc_logbuf() )
  {
LABEL_18:
    v8 = ipa3_get_ipc_logbuf();
    ipc_log_string(v8, "ipa-wan %s:%d fail to alloc exception hdr_del\n", "ipa3_del_a7_qmap_hdr", 322);
  }
LABEL_19:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v9 = ipa3_get_ipc_logbuf_low();
    return ipc_log_string(v9, "ipa-wan %s:%d fail to alloc exception hdr_del\n", "ipa3_del_a7_qmap_hdr", 322);
  }
  return result;
}
