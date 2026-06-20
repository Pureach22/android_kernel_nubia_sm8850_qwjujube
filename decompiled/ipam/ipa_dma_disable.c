__int64 __fastcall ipa_dma_disable(__int64 a1)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w20
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 ipc_logbuf; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0

  _ReadStatusReg(SP_EL0);
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(a1);
  if ( ipc_logbuf_low )
  {
    v2 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v2, "ipa_dma %s:%d ENTRY\n", "ipa_dma_disable", 471);
  }
  if ( ipa3_dma_ctx && *(_DWORD *)ipa_dma_init_refcnt_ctrl )
  {
    mutex_lock(ipa3_dma_ctx + 72);
    v3 = raw_spin_lock_irqsave(ipa3_dma_ctx + 120);
    v4 = v3;
    if ( *(_DWORD *)ipa3_dma_ctx < 2u )
    {
      if ( *(_DWORD *)ipa3_dma_ctx )
      {
        v10 = ipa3_dma_work_pending(v3);
        if ( (v10 & 1) == 0 )
        {
          *(_DWORD *)ipa3_dma_ctx = 0;
          v11 = ipa3_get_ipc_logbuf_low(v10);
          if ( v11 )
          {
            v12 = ipa3_get_ipc_logbuf_low(v11);
            ipc_log_string(v12, "ipa_dma %s:%d EXIT\n", "ipa_dma_disable", 499);
          }
          raw_spin_unlock_irqrestore(ipa3_dma_ctx + 120, v4);
          ipa3_dec_client_disable_clks();
          v9 = 0;
          goto LABEL_17;
        }
        v24 = printk(&unk_3D26D2, "ipa_dma_disable");
        ipc_logbuf = ipa3_get_ipc_logbuf(v24);
        if ( ipc_logbuf )
        {
          v26 = ipa3_get_ipc_logbuf(ipc_logbuf);
          ipc_logbuf = ipc_log_string(
                         v26,
                         "ipa_dma %s:%d There is pending work, can't disable.\n",
                         "ipa_dma_disable",
                         493);
        }
        v27 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
        if ( v27 )
        {
          v28 = ipa3_get_ipc_logbuf_low(v27);
          ipc_log_string(v28, "ipa_dma %s:%d There is pending work, can't disable.\n", "ipa_dma_disable", 493);
        }
        v9 = -14;
      }
      else
      {
        v19 = printk(&unk_3A9A05, "ipa_dma_disable");
        v20 = ipa3_get_ipc_logbuf(v19);
        if ( v20 )
        {
          v21 = ipa3_get_ipc_logbuf(v20);
          v20 = ipc_log_string(v21, "ipa_dma %s:%d Already disabled\n", "ipa_dma_disable", 487);
        }
        v22 = ipa3_get_ipc_logbuf_low(v20);
        if ( v22 )
        {
          v23 = ipa3_get_ipc_logbuf_low(v22);
          ipc_log_string(v23, "ipa_dma %s:%d Already disabled\n", "ipa_dma_disable", 487);
        }
        v9 = -1;
      }
    }
    else
    {
      v5 = ipa3_get_ipc_logbuf(v3);
      if ( v5 )
      {
        v6 = ipa3_get_ipc_logbuf(v5);
        v5 = ipc_log_string(
               v6,
               "ipa_dma %s:%d Multiple enablement done. refcnt=%d\n",
               "ipa_dma_disable",
               481,
               *(_DWORD *)ipa3_dma_ctx);
      }
      v7 = ipa3_get_ipc_logbuf_low(v5);
      if ( v7 )
      {
        v8 = ipa3_get_ipc_logbuf_low(v7);
        ipc_log_string(
          v8,
          "ipa_dma %s:%d Multiple enablement done. refcnt=%d\n",
          "ipa_dma_disable",
          481,
          *(_DWORD *)ipa3_dma_ctx);
      }
      v9 = 0;
      --*(_DWORD *)ipa3_dma_ctx;
    }
    raw_spin_unlock_irqrestore(ipa3_dma_ctx + 120, v4);
LABEL_17:
    mutex_unlock(ipa3_dma_ctx + 72);
    goto LABEL_18;
  }
  v14 = printk(&unk_3DB262, "ipa_dma_disable");
  v15 = ipa3_get_ipc_logbuf(v14);
  if ( v15 )
  {
    v16 = ipa3_get_ipc_logbuf(v15);
    v15 = ipc_log_string(v16, "ipa_dma %s:%d IPADMA isn't initialized, can't disable\n", "ipa_dma_disable", 474);
  }
  v17 = ipa3_get_ipc_logbuf_low(v15);
  if ( v17 )
  {
    v18 = ipa3_get_ipc_logbuf_low(v17);
    ipc_log_string(v18, "ipa_dma %s:%d IPADMA isn't initialized, can't disable\n", "ipa_dma_disable", 474);
  }
  v9 = -22;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v9;
}
