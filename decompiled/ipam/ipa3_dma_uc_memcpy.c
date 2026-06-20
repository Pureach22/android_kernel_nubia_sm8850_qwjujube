__int64 __fastcall ipa3_dma_uc_memcpy(unsigned __int64 a1, unsigned __int64 a2, unsigned int a3)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x0
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x10
  __int64 v10; // x0
  __int64 v11; // x20
  __int64 v12; // x0
  unsigned int v13; // w19
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 ipc_logbuf; // x0
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
  unsigned int v47; // w9
  unsigned int v50; // w10
  unsigned int v53; // w9

  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(a1);
  if ( ipc_logbuf_low )
  {
    v7 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v7, "ipa_dma %s:%d ENTRY\n", "ipa3_dma_uc_memcpy", 971);
  }
  if ( ipa3_dma_ctx )
  {
    if ( a2 <= a1 )
      v8 = a1;
    else
      v8 = a2;
    if ( a2 >= a1 )
      v9 = a1;
    else
      v9 = a2;
    if ( v8 - v9 < (int)a3 )
    {
      v22 = printk(&unk_3CF782, "ipa3_dma_uc_memcpy");
      ipc_logbuf = ipa3_get_ipc_logbuf(v22);
      if ( ipc_logbuf )
      {
        v24 = ipa3_get_ipc_logbuf(ipc_logbuf);
        ipc_logbuf = ipc_log_string(
                       v24,
                       "ipa_dma %s:%d invalid addresses - overlapping buffers\n",
                       "ipa3_dma_uc_memcpy",
                       977);
      }
      v25 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
      if ( v25 )
      {
        v26 = ipa3_get_ipc_logbuf_low(v25);
        ipc_log_string(v26, "ipa_dma %s:%d invalid addresses - overlapping buffers\n", "ipa3_dma_uc_memcpy", 977);
        return (unsigned int)-22;
      }
    }
    else
    {
      if ( a3 - 0x10000 > 0xFFFF0000 )
      {
        v10 = raw_spin_lock_irqsave(ipa3_dma_ctx + 120);
        v11 = v10;
        if ( *(_DWORD *)ipa3_dma_ctx )
        {
          _X8 = (unsigned int *)(ipa3_dma_ctx + 184);
          __asm { PRFM            #0x11, [X8] }
          do
            v47 = __ldxr(_X8);
          while ( __stxr(v47 + 1, _X8) );
          raw_spin_unlock_irqrestore(ipa3_dma_ctx + 120, v10);
          v12 = ipa3_uc_memcpy(a1, a2, a3);
          v13 = v12;
          if ( (_DWORD)v12 )
          {
            v37 = printk(&unk_3F7CBD, "ipa3_dma_uc_memcpy");
            v38 = ipa3_get_ipc_logbuf(v37);
            if ( v38 )
            {
              v39 = ipa3_get_ipc_logbuf(v38);
              v38 = ipc_log_string(v39, "ipa_dma %s:%d ipa3_uc_memcpy failed %d\n", "ipa3_dma_uc_memcpy", 996, v13);
            }
            v12 = ipa3_get_ipc_logbuf_low(v38);
            if ( v12 )
            {
              v40 = ipa3_get_ipc_logbuf_low(v12);
              v12 = ipc_log_string(v40, "ipa_dma %s:%d ipa3_uc_memcpy failed %d\n", "ipa3_dma_uc_memcpy", 996, v13);
            }
          }
          else
          {
            _X8 = (unsigned int *)(ipa3_dma_ctx + 196);
            __asm { PRFM            #0x11, [X8] }
            do
              v53 = __ldxr(_X8);
            while ( __stxr(v53 + 1, _X8) );
          }
          _X8 = (unsigned int *)(ipa3_dma_ctx + 184);
          __asm { PRFM            #0x11, [X8] }
          do
            v50 = __ldxr(_X8);
          while ( __stxr(v50 - 1, _X8) );
          if ( *(_BYTE *)(ipa3_dma_ctx + 4) == 1 )
          {
            v12 = ipa3_dma_work_pending(v12);
            if ( (v12 & 1) == 0 )
              v12 = complete(ipa3_dma_ctx + 128);
          }
          v14 = ipa3_get_ipc_logbuf_low(v12);
          if ( v14 )
          {
            v15 = ipa3_get_ipc_logbuf_low(v14);
            ipc_log_string(v15, "ipa_dma %s:%d EXIT\n", "ipa3_dma_uc_memcpy", 1006);
          }
        }
        else
        {
          v32 = printk(&unk_3F4EBC, "ipa3_dma_uc_memcpy");
          v33 = ipa3_get_ipc_logbuf(v32);
          if ( v33 )
          {
            v34 = ipa3_get_ipc_logbuf(v33);
            v33 = ipc_log_string(v34, "ipa_dma %s:%d can't memcpy, IPADMA isn't enabled\n", "ipa3_dma_uc_memcpy", 987);
          }
          v35 = ipa3_get_ipc_logbuf_low(v33);
          if ( v35 )
          {
            v36 = ipa3_get_ipc_logbuf_low(v35);
            ipc_log_string(v36, "ipa_dma %s:%d can't memcpy, IPADMA isn't enabled\n", "ipa3_dma_uc_memcpy", 987);
          }
          raw_spin_unlock_irqrestore(ipa3_dma_ctx + 120, v11);
          return (unsigned int)-1;
        }
        return v13;
      }
      v27 = printk(&unk_3F7C64, "ipa3_dma_uc_memcpy");
      v28 = ipa3_get_ipc_logbuf(v27);
      if ( v28 )
      {
        v29 = ipa3_get_ipc_logbuf(v28);
        v28 = ipc_log_string(v29, "ipa_dma %s:%d invalid len, %d\n", "ipa3_dma_uc_memcpy", 981, a3);
      }
      v30 = ipa3_get_ipc_logbuf_low(v28);
      if ( v30 )
      {
        v31 = ipa3_get_ipc_logbuf_low(v30);
        ipc_log_string(v31, "ipa_dma %s:%d invalid len, %d\n", "ipa3_dma_uc_memcpy", 981, a3);
        return (unsigned int)-22;
      }
    }
    return (unsigned int)-22;
  }
  v17 = printk(&unk_3C6AD0, "ipa3_dma_uc_memcpy");
  v18 = ipa3_get_ipc_logbuf(v17);
  if ( v18 )
  {
    v19 = ipa3_get_ipc_logbuf(v18);
    v18 = ipc_log_string(v19, "ipa_dma %s:%d IPADMA isn't initialized, can't memcpy\n", "ipa3_dma_uc_memcpy", 973);
  }
  v20 = ipa3_get_ipc_logbuf_low(v18);
  if ( v20 )
  {
    v21 = ipa3_get_ipc_logbuf_low(v20);
    ipc_log_string(v21, "ipa_dma %s:%d IPADMA isn't initialized, can't memcpy\n", "ipa3_dma_uc_memcpy", 973);
  }
  return (unsigned int)-1;
}
