__int64 __fastcall ipa3_wwan_xmit(__int64 a1, __int64 a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  int v6; // w23
  __int64 v7; // x21
  __int64 v8; // x9
  __int64 v9; // x0
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  int v16; // w0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x9
  __int64 v21; // x0
  __int64 v22; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v24; // x0
  __int64 v25; // x0
  int v26; // w22
  __int64 v27; // x0
  __int64 v28; // x0
  unsigned __int64 v35; // x9
  unsigned __int64 v38; // x9
  unsigned __int64 v41; // x9
  unsigned int v44; // w9
  unsigned int v47; // w10
  unsigned int v48; // w19

  if ( *(_BYTE *)(rmnet_ipa3_ctx + 1992) == 1 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_wwan_xmit__rs, "ipa3_wwan_xmit") )
    {
      printk(&unk_3C5430, "ipa3_wwan_xmit");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_5:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d IPA embedded data on APQ platform\n", "ipa3_wwan_xmit", 3131);
        }
LABEL_12:
        dev_kfree_skb_any_reason(a1, 2);
        ++*(_QWORD *)(a2 + 608);
        return 0;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_5;
    }
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d IPA embedded data on APQ platform\n", "ipa3_wwan_xmit", 3131);
    goto LABEL_5;
  }
  if ( *(__int16 *)(a1 + 180) != -1792 )
  {
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v9,
        "ipa-wan %s:%d SW filtering out none QMAP packet received from %s",
        "ipa3_wwan_xmit",
        3140,
        _ReadStatusReg(SP_EL0) + 2320);
    }
    goto LABEL_12;
  }
  v6 = **(char **)(a1 + 224);
  v7 = raw_spin_lock_irqsave(a2 + 2888);
  v8 = *(_QWORD *)(a2 + 24);
  if ( *(_DWORD *)(rmnet_ipa3_ctx + 1988) )
  {
    *(_QWORD *)(v8 + 328) = jiffies;
    __dmb(0xBu);
    _X8 = (unsigned __int64 *)(v8 + 336);
    __asm { PRFM            #0x11, [X8] }
    do
      v35 = __ldxr(_X8);
    while ( __stxr(v35 | 1, _X8) );
LABEL_33:
    raw_spin_unlock_irqrestore(a2 + 2888, v7);
    return 16;
  }
  if ( (*(_QWORD *)(v8 + 336) & 1) != 0 )
  {
    if ( (v6 & 0x80000000) == 0 || *(_DWORD *)(a2 + 2880) >= *(_DWORD *)(rmnet_ipa3_ctx + 1940) )
    {
      printk(&unk_3B93BD, "ipa3_wwan_xmit");
      if ( ipa3_get_ipc_logbuf() )
      {
        v21 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v21,
          "ipa-wan %s:%d [%s]fatal: %s stopped\n",
          "ipa3_wwan_xmit",
          3171,
          (const char *)(a2 + 296),
          "ipa3_wwan_xmit");
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v22 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v22,
          "ipa-wan %s:%d [%s]fatal: %s stopped\n",
          "ipa3_wwan_xmit",
          3171,
          (const char *)(a2 + 296),
          "ipa3_wwan_xmit");
      }
      goto LABEL_33;
    }
    printk(&unk_3DF4A1, "ipa3_wwan_xmit");
    if ( ipa3_get_ipc_logbuf() )
    {
      v14 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v14,
        "ipa-wan %s:%d [%s]Queue stop, send ctrl pkts\n",
        "ipa3_wwan_xmit",
        3167,
        (const char *)(a2 + 296));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v15 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v15,
        "ipa-wan %s:%d [%s]Queue stop, send ctrl pkts\n",
        "ipa3_wwan_xmit",
        3167,
        (const char *)(a2 + 296));
    }
  }
  else if ( *(_DWORD *)(a2 + 2880) >= *(_DWORD *)(rmnet_ipa3_ctx + 1936) && (v6 & 0x80000000) == 0 )
  {
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v11 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v11,
        "ipa-wan %s:%d pending(%d)/(%d)- stop(%d)\n",
        "ipa3_wwan_xmit",
        3183,
        *(_DWORD *)(a2 + 2880),
        *(_DWORD *)(rmnet_ipa3_ctx + 1936),
        *(_QWORD *)(*(_QWORD *)(a2 + 24) + 336LL) & 1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v12 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v12, "ipa-wan %s:%d qmap_chk(%d)\n", "ipa3_wwan_xmit", 3184, 0);
    }
    v13 = *(_QWORD *)(a2 + 24);
    *(_QWORD *)(v13 + 328) = jiffies;
    __dmb(0xBu);
    _X8 = (unsigned __int64 *)(v13 + 336);
    __asm { PRFM            #0x11, [X8] }
    do
      v38 = __ldxr(_X8);
    while ( __stxr(v38 | 1, _X8) );
    goto LABEL_33;
  }
  if ( *(_DWORD *)(ipa3_ctx + 52488) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_3BF18A, "ipa3_wwan_xmit");
    if ( ipa3_get_ipc_logbuf() )
    {
      v24 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v24,
        "ipa-wan %s:%d User %s sent data in suspend mode.\n",
        "ipa3_wwan_xmit",
        3193,
        (const char *)(StatusReg + 2320));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v25 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v25,
        "ipa-wan %s:%d User %s sent data in suspend mode.\n",
        "ipa3_wwan_xmit",
        3193,
        (const char *)(StatusReg + 2320));
    }
  }
  ipa_pm_activate(*(_DWORD *)(rmnet_ipa3_ctx + 1188));
  v16 = ipa_pm_activate(*(_DWORD *)(rmnet_ipa3_ctx + 1184));
  if ( !v16 )
  {
    _X8 = (unsigned int *)(a2 + 2880);
    __asm { PRFM            #0x11, [X8] }
    do
      v44 = __ldxr(_X8);
    while ( __stxr(v44 + 1, _X8) );
    raw_spin_unlock_irqrestore(a2 + 2888, v7);
    result = ipa_tx_dp(0x22u, a1, nullptr);
    if ( !(_DWORD)result )
    {
      v20 = *(_QWORD *)(a2 + 576);
      ++*(_QWORD *)(a2 + 560);
      *(_QWORD *)(a2 + 576) = v20 + *(unsigned int *)(a1 + 112);
      goto LABEL_70;
    }
    _X8 = (unsigned int *)(a2 + 2880);
    __asm { PRFM            #0x11, [X8] }
    do
      v47 = __ldxr(_X8);
    while ( __stxr(v47 - 1, _X8) );
    if ( (_DWORD)result != -32 )
    {
      result = 16;
LABEL_70:
      if ( !*(_DWORD *)(a2 + 2880) )
      {
        v48 = result;
        ((void (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)(*(unsigned int *)(rmnet_ipa3_ctx + 1184));
        ((void (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)(*(unsigned int *)(rmnet_ipa3_ctx + 1188));
        return v48;
      }
      return result;
    }
    if ( (unsigned int)__ratelimit(&ipa3_wwan_xmit__rs_470, "ipa3_wwan_xmit") )
    {
      printk(&unk_3D3E06, "ipa3_wwan_xmit");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_41:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v19 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v19, "ipa-wan %s:%d [%s] fatal: pipe is not valid\n", "ipa3_wwan_xmit", 3232, a2 + 296);
        }
        goto LABEL_12;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_41;
    }
    v18 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v18,
      "ipa-wan %s:%d [%s] fatal: pipe is not valid\n",
      "ipa3_wwan_xmit",
      3232,
      (const char *)(a2 + 296));
    goto LABEL_41;
  }
  if ( v16 == -115 )
  {
    v17 = *(_QWORD *)(a2 + 24);
    *(_QWORD *)(v17 + 328) = jiffies;
    __dmb(0xBu);
    _X8 = (unsigned __int64 *)(v17 + 336);
    __asm { PRFM            #0x11, [X8] }
    do
      v41 = __ldxr(_X8);
    while ( __stxr(v41 | 1, _X8) );
    goto LABEL_33;
  }
  v26 = v16;
  printk(&unk_3DC920, "ipa3_wwan_xmit");
  if ( ipa3_get_ipc_logbuf() )
  {
    v27 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v27,
      "ipa-wan %s:%d [%s] fatal: ipa pm activate failed %d\n",
      "ipa3_wwan_xmit",
      3207,
      (const char *)(a2 + 296),
      v26);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v28 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v28,
      "ipa-wan %s:%d [%s] fatal: ipa pm activate failed %d\n",
      "ipa3_wwan_xmit",
      3207,
      (const char *)(a2 + 296),
      v26);
  }
  dev_kfree_skb_any_reason(a1, 2);
  ++*(_QWORD *)(a2 + 608);
  raw_spin_unlock_irqrestore(a2 + 2888, v7);
  return 0;
}
