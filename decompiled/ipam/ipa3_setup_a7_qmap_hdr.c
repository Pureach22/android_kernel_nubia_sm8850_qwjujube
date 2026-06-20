__int64 ipa3_setup_a7_qmap_hdr()
{
  __int64 v0; // x0
  __int64 v1; // x19
  char v2; // w8
  __int64 v3; // x9
  unsigned int v4; // w20
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x0
  __int64 v8; // x0

  v0 = _kmalloc_cache_noprof(scnprintf, 3520, 312);
  v1 = v0;
  if ( !v0 )
    return (unsigned int)-12;
  *(_WORD *)v0 = 257;
  *(_DWORD *)(v0 + 304) = 11738;
  strcpy((char *)(v0 + 4), "ipa_qmap_hdr");
  if ( (int)ipa3_ctx_get_type(0) >= 17 && *(_BYTE *)(rmnet_ipa3_ctx + 1984) == 1 )
  {
    v2 = 0;
    *(_BYTE *)(v1 + 291) = 8;
    *(_WORD *)(v1 + 40) = -32764;
    v3 = 43;
    *(_DWORD *)(v1 + 36) = 64;
    *(_BYTE *)(v1 + 42) = 0;
  }
  else
  {
    v2 = 4;
    v3 = 291;
  }
  *(_BYTE *)(v1 + v3) = v2;
  if ( (unsigned int)ipa_add_hdr(v1) )
  {
    printk(&unk_3FC61D, "ipa3_setup_a7_qmap_hdr");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa-wan %s:%d fail to add IPA_A7_QMAP hdr\n", "ipa3_setup_a7_qmap_hdr", 293);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d fail to add IPA_A7_QMAP hdr\n", "ipa3_setup_a7_qmap_hdr", 293);
    }
    goto LABEL_18;
  }
  if ( *(_DWORD *)(v1 + 304) )
  {
    printk(&unk_3FC61D, "ipa3_setup_a7_qmap_hdr");
    if ( ipa3_get_ipc_logbuf() )
    {
      v7 = ipa3_get_ipc_logbuf();
      ipc_log_string(v7, "ipa-wan %s:%d fail to add IPA_A7_QMAP hdr\n", "ipa3_setup_a7_qmap_hdr", 299);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v8 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v8, "ipa-wan %s:%d fail to add IPA_A7_QMAP hdr\n", "ipa3_setup_a7_qmap_hdr", 299);
    }
LABEL_18:
    v4 = -1;
    goto LABEL_9;
  }
  v4 = 0;
  *(_DWORD *)(rmnet_ipa3_ctx + 520) = *(_DWORD *)(v1 + 300);
LABEL_9:
  kfree(v1);
  return v4;
}
