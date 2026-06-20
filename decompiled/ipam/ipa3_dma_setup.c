__int64 __fastcall ipa3_dma_setup(__int64 a1)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 ipc_logbuf; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0

  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(a1);
  if ( ipc_logbuf_low )
  {
    v2 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v2, "ipa_dma %s:%d ENTRY\n", "ipa3_dma_setup", 140);
  }
  if ( ipa_dma_init_refcnt_ctrl )
  {
    v7 = printk(&unk_3FB0E7, "ipa3_dma_setup");
    ipc_logbuf = ipa3_get_ipc_logbuf(v7);
    if ( ipc_logbuf )
    {
      v9 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(v9, "ipa_dma %s:%d Setup already done\n", "ipa3_dma_setup", 143);
    }
    v10 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( v10 )
    {
      v11 = ipa3_get_ipc_logbuf_low(v10);
      ipc_log_string(v11, "ipa_dma %s:%d Setup already done\n", "ipa3_dma_setup", 143);
    }
    return 4294967282LL;
  }
  else
  {
    v3 = _kmalloc_cache_noprof(ipc_log_string, 3520, 56);
    ipa_dma_init_refcnt_ctrl = v3;
    if ( v3 )
    {
      v4 = _mutex_init(v3 + 8, "&ipa_dma_init_refcnt_ctrl->lock", &ipa3_dma_setup___key);
      result = ipa3_get_ipc_logbuf_low(v4);
      if ( result )
      {
        v6 = ipa3_get_ipc_logbuf_low(result);
        ipc_log_string(v6, "ipa_dma %s:%d EXIT\n", "ipa3_dma_setup", 157);
        return 0;
      }
    }
    else
    {
      v12 = printk(&unk_3F1E65, "ipa3_dma_setup");
      v13 = ipa3_get_ipc_logbuf(v12);
      if ( v13 )
      {
        v14 = ipa3_get_ipc_logbuf(v13);
        v13 = ipc_log_string(v14, "ipa_dma %s:%d kzalloc error.\n", "ipa3_dma_setup", 151);
      }
      v15 = ipa3_get_ipc_logbuf_low(v13);
      if ( v15 )
      {
        v16 = ipa3_get_ipc_logbuf_low(v15);
        ipc_log_string(v16, "ipa_dma %s:%d kzalloc error.\n", "ipa3_dma_setup", 151);
      }
      return 4294967284LL;
    }
  }
  return result;
}
