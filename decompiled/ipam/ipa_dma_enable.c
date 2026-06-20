__int64 __fastcall ipa_dma_enable(__int64 a1)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 ipc_logbuf; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0

  _ReadStatusReg(SP_EL0);
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(a1);
  if ( ipc_logbuf_low )
  {
    v2 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v2, "ipa_dma %s:%d ENTRY\n", "ipa_dma_enable", 412);
  }
  if ( ipa3_dma_ctx && *(_DWORD *)ipa_dma_init_refcnt_ctrl )
  {
    mutex_lock(ipa3_dma_ctx + 72);
    if ( *(_DWORD *)ipa3_dma_ctx )
    {
      v12 = printk(&unk_3F4E91, "ipa_dma_enable");
      ipc_logbuf = ipa3_get_ipc_logbuf(v12);
      if ( ipc_logbuf )
      {
        v14 = ipa3_get_ipc_logbuf(ipc_logbuf);
        ipc_logbuf = ipc_log_string(
                       v14,
                       "ipa_dma %s:%d Already enabled refcnt=%d\n",
                       "ipa_dma_enable",
                       421,
                       *(_DWORD *)ipa3_dma_ctx);
      }
      v15 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
      if ( v15 )
      {
        v16 = ipa3_get_ipc_logbuf_low(v15);
        ipc_log_string(v16, "ipa_dma %s:%d Already enabled refcnt=%d\n", "ipa_dma_enable", 421, *(_DWORD *)ipa3_dma_ctx);
      }
      v17 = ipa3_dma_ctx;
      ++*(_DWORD *)ipa3_dma_ctx;
      mutex_unlock(v17 + 72);
      goto LABEL_8;
    }
    ipa3_inc_client_enable_clks();
    v3 = ipa3_dma_ctx;
    *(_DWORD *)ipa3_dma_ctx = 1;
    v4 = mutex_unlock(v3 + 72);
    result = ipa3_get_ipc_logbuf_low(v4);
    if ( result )
    {
      v6 = ipa3_get_ipc_logbuf_low(result);
      ipc_log_string(v6, "ipa_dma %s:%d EXIT\n", "ipa_dma_enable", 430);
LABEL_8:
      result = 0;
    }
  }
  else
  {
    v7 = printk(&unk_3CC55E, "ipa_dma_enable");
    v8 = ipa3_get_ipc_logbuf(v7);
    if ( v8 )
    {
      v9 = ipa3_get_ipc_logbuf(v8);
      v8 = ipc_log_string(v9, "ipa_dma %s:%d IPADMA isn't initialized, can't enable\n", "ipa_dma_enable", 415);
    }
    v10 = ipa3_get_ipc_logbuf_low(v8);
    if ( v10 )
    {
      v11 = ipa3_get_ipc_logbuf_low(v10);
      ipc_log_string(v11, "ipa_dma %s:%d IPADMA isn't initialized, can't enable\n", "ipa_dma_enable", 415);
    }
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
