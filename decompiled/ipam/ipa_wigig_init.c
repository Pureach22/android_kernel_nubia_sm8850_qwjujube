__int64 __fastcall ipa_wigig_init(_QWORD *a1, _BYTE *a2)
{
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  _QWORD *v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x8
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  const char *v16; // x4
  __int64 v17; // x0
  const char *v18; // x4
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // [xsp+10h] [xbp-20h] BYREF
  __int64 v26; // [xsp+18h] [xbp-18h]
  __int64 v27; // [xsp+20h] [xbp-10h]
  __int64 v28; // [xsp+28h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  v25 = 0;
  if ( !a1 || !a2 )
  {
    printk(&unk_3FCDD1, "ipa_wigig_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d invalid params in=%pK, out %pK\n", "ipa_wigig_init", 134, a1, a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d invalid params in=%pK, out %pK\n", "ipa_wigig_init", 134, a1, a2);
      result = 4294967274LL;
      goto LABEL_43;
    }
LABEL_41:
    result = 4294967274LL;
    goto LABEL_43;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v4 = ipa3_get_ipc_logbuf();
    ipc_log_string(v4, "ipa_wigig %s:%d \n", "ipa_wigig_init", 138);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v5 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v5, "ipa_wigig %s:%d \n", "ipa_wigig_init", 138);
  }
  if ( ipa_wigig_ctx )
  {
    printk(&unk_3B3A1C, "ipa_wigig_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      v23 = ipa3_get_ipc_logbuf();
      ipc_log_string(v23, "ipa_wigig %s:%d ipa_wigig_ctx was initialized before\n", "ipa_wigig_init", 140);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v24 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v24, "ipa_wigig %s:%d ipa_wigig_ctx was initialized before\n", "ipa_wigig_init", 140);
    }
    goto LABEL_41;
  }
  v6 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 936);
  ipa_wigig_ctx = v6;
  if ( v6 )
  {
    _mutex_init(v6 + 16, "&ipa_wigig_ctx->lock", &ipa_wigig_init___key);
    v7 = (_QWORD *)ipa_wigig_ctx;
    *(_QWORD *)ipa_wigig_ctx = ipa_wigig_ctx;
    v7[1] = v7;
    v7[10] = a1[1];
    v7[11] = a1[2];
    v7[12] = a1[3];
    v7[13] = a1[4];
    v7[9] = *a1;
    if ( ipa3_get_ipc_logbuf() )
    {
      v8 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v8,
        "ipa_wigig %s:%d periph_baddr_pa 0x%pa pseudo_cause_pa 0x%pa, int_gen_tx_pa 0x%pa, int_gen_rx_pa 0x%pa, dma_ep_misc_pa 0x%pa",
        "ipa_wigig_init",
        163,
        (const void *)(ipa_wigig_ctx + 72),
        (const void *)(ipa_wigig_ctx + 80),
        (const void *)(ipa_wigig_ctx + 88),
        (const void *)(ipa_wigig_ctx + 96),
        (const void *)(ipa_wigig_ctx + 104));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v9,
        "ipa_wigig %s:%d periph_baddr_pa 0x%pa pseudo_cause_pa 0x%pa, int_gen_tx_pa 0x%pa, int_gen_rx_pa 0x%pa, dma_ep_misc_pa 0x%pa",
        "ipa_wigig_init",
        163,
        (const void *)(ipa_wigig_ctx + 72),
        (const void *)(ipa_wigig_ctx + 80),
        (const void *)(ipa_wigig_ctx + 88),
        (const void *)(ipa_wigig_ctx + 96),
        (const void *)(ipa_wigig_ctx + 104));
    }
    v11 = a1[5];
    v10 = a1[6];
    v26 = a1[7];
    v27 = v11;
    if ( (unsigned int)ipa3_wigig_internal_init((__int64)&v25, v10, (_QWORD *)a2 + 1) )
    {
      kfree(ipa_wigig_ctx);
      ipa_wigig_ctx = 0;
      result = 4294967282LL;
    }
    else
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v13 = ipa3_get_ipc_logbuf();
        ipc_log_string(v13, "ipa_wigig %s:%d uc_db_pa 0x%pa\n", "ipa_wigig_init", 174, a2 + 8);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v14 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v14, "ipa_wigig %s:%d uc_db_pa 0x%pa\n", "ipa_wigig_init", 174, a2 + 8);
      }
      *a2 = v25;
      a2[16] = ipa_get_lan_rx_napi() & 1;
      if ( ipa3_get_ipc_logbuf() )
      {
        v15 = ipa3_get_ipc_logbuf();
        if ( a2[16] )
          v16 = "True";
        else
          v16 = "False";
        ipc_log_string(v15, "ipa_wigig %s:%d LAN RX NAPI enabled = %s\n", "ipa_wigig_init", 180, v16);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v17 = ipa3_get_ipc_logbuf_low();
        if ( a2[16] )
          v18 = "True";
        else
          v18 = "False";
        ipc_log_string(v17, "ipa_wigig %s:%d LAN RX NAPI enabled = %s\n", "ipa_wigig_init", 180, v18);
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v19 = ipa3_get_ipc_logbuf();
        ipc_log_string(v19, "ipa_wigig %s:%d exit\n", "ipa_wigig_init", 182);
      }
      result = ipa3_get_ipc_logbuf_low();
      if ( result )
      {
        v20 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v20, "ipa_wigig %s:%d exit\n", "ipa_wigig_init", 182);
        result = 0;
      }
    }
  }
  else
  {
    result = 4294967284LL;
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
