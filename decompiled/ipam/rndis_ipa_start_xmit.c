__int64 __fastcall rndis_ipa_start_xmit(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  int v3; // w21
  __int64 v5; // x20
  __int64 v6; // x8
  long double v7; // q0
  __int64 v8; // x8
  unsigned int v9; // w20
  __int64 v10; // x0
  unsigned int v11; // w4
  int v12; // w8
  int v13; // w8
  unsigned __int16 *v14; // x0
  __int64 v15; // x9
  __int64 v16; // x10
  __int16 v17; // w8
  __int64 v18; // x8
  int v19; // w0
  const char *v20; // x4
  int v22; // w8
  unsigned __int16 *v23; // x0
  int v24; // w21
  long double v25; // q0
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned __int64 v34; // x9
  unsigned __int64 v37; // x9
  unsigned int v40; // w9

  v2 = *(_QWORD *)(a2 + 24);
  v3 = *(_DWORD *)(a1 + 112);
  v5 = a1;
  if ( *(_QWORD *)(v2 + 328) != jiffies )
  {
    *(_QWORD *)(v2 + 328) = jiffies;
    v2 = *(_QWORD *)(a2 + 24);
  }
  if ( (*(_QWORD *)(v2 + 336) & 1) != 0 )
  {
    if ( (unsigned int)__ratelimit(&rndis_ipa_start_xmit__rs, "rndis_ipa_start_xmit") )
    {
      _ReadStatusReg(SP_EL0);
      printk(&unk_3F6D52, "rndis_ipa_start_xmit");
      v26 = ipa_rndis_logbuf;
      if ( !ipa_rndis_logbuf )
        goto LABEL_26;
    }
    else
    {
      v26 = ipa_rndis_logbuf;
      if ( !ipa_rndis_logbuf )
        goto LABEL_26;
    }
    v7 = ipc_log_string(v26, "RNDIS_IPA %s:%d interface queue is stopped\n", "rndis_ipa_start_xmit", 1025);
    goto LABEL_26;
  }
  if ( *(_BYTE *)(a2 + 2704) == 1 )
    rndis_ipa_dump_skb(a1);
  if ( *(_DWORD *)(a2 + 2760) != 4 )
  {
    if ( (unsigned int)__ratelimit(&rndis_ipa_start_xmit__rs_125, "rndis_ipa_start_xmit") )
    {
      _ReadStatusReg(SP_EL0);
      printk(&unk_3D796A, "rndis_ipa_start_xmit");
      v27 = ipa_rndis_logbuf;
      if ( ipa_rndis_logbuf )
        goto LABEL_53;
    }
    else
    {
      v27 = ipa_rndis_logbuf;
      if ( ipa_rndis_logbuf )
      {
LABEL_53:
        ipc_log_string(v27, "RNDIS_IPA %s:%d Missing pipe connected and/or iface up\n", "rndis_ipa_start_xmit", 1033);
        return 16;
      }
    }
    return 16;
  }
  v6 = *(_QWORD *)(v5 + 16);
  if ( *(_BYTE *)(v6 + 2696) == 1
    && (*(_WORD *)(v5 + 180) != 8
     || (*(_BYTE *)(v6 + 2713) & 1) != 0
     || *(_BYTE *)(*(_QWORD *)(v5 + 216) + *(unsigned __int16 *)(v5 + 184) + 9LL) != 1) )
  {
    dev_kfree_skb_any_reason(v5, 2);
    if ( ipa_rndis_logbuf )
      v7 = ipc_log_string(
             ipa_rndis_logbuf,
             "RNDIS_IPA %s:%d packet got filtered out on Tx path\n",
             "rndis_ipa_start_xmit",
             1039);
    v9 = 0;
    ++*(_DWORD *)(a2 + 2700);
    if ( !*(_DWORD *)(a2 + 2744) )
      goto LABEL_34;
    goto LABEL_35;
  }
  if ( !(unsigned int)ipa_pm_activate(*(_DWORD *)(a2 + 2892)) )
  {
    v11 = *(_DWORD *)(a2 + 2748);
    if ( *(_DWORD *)(a2 + 2744) >= v11 )
    {
      if ( ipa_rndis_logbuf )
        v7 = ipc_log_string(
               ipa_rndis_logbuf,
               "RNDIS_IPA %s:%d Outstanding high boundary reached (%d)\n",
               "rndis_ipa_start_xmit",
               1055,
               v11);
      v18 = *(_QWORD *)(a2 + 24);
      *(_QWORD *)(v18 + 328) = jiffies;
      __dmb(0xBu);
      _X8 = (unsigned __int64 *)(v18 + 336);
      __asm { PRFM            #0x11, [X8] }
      do
        v37 = __ldxr(_X8);
      while ( __stxr(v37 | 1, _X8) );
      if ( ipa_rndis_logbuf )
        v7 = ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d send  queue was stopped\n", "rndis_ipa_start_xmit", 1057);
      goto LABEL_26;
    }
    if ( *(_BYTE *)(a2 + 2912) == 1 && (*(_DWORD *)(a2 + 185) & 0x2001D00) != 0 )
    {
      v12 = *(unsigned __int16 *)(v5 + 180);
      if ( v12 == 56710 )
      {
        v22 = *(unsigned __int8 *)(*(_QWORD *)(v5 + 216) + *(unsigned __int16 *)(v5 + 184) + 6LL);
        if ( v22 != 17 && v22 != 6 )
          goto LABEL_29;
        v23 = qmap_encapsulate_skb((unsigned __int16 *)v5, (unsigned __int64 *)&qmap_template_hdr);
        v15 = *((_QWORD *)v23 + 27);
        v5 = (__int64)v23;
        v16 = *((unsigned int *)v23 + 53);
        v17 = *(_WORD *)(a2 + 56) - 60;
      }
      else
      {
        if ( v12 != 8 )
          goto LABEL_29;
        v13 = *(unsigned __int8 *)(*(_QWORD *)(v5 + 216) + *(unsigned __int16 *)(v5 + 184) + 9LL);
        if ( v13 != 17 && v13 != 6 )
          goto LABEL_29;
        v14 = qmap_encapsulate_skb((unsigned __int16 *)v5, (unsigned __int64 *)&qmap_template_hdr);
        v15 = *((_QWORD *)v14 + 27);
        v5 = (__int64)v14;
        v16 = *((unsigned int *)v14 + 53);
        v17 = *(_WORD *)(a2 + 56) - 40;
      }
      *(_WORD *)(v15 + v16 + 4) = v17;
    }
    else
    {
      v5 = rndis_encapsulate_skb(v5, a2 + 2688);
    }
LABEL_29:
    if ( v3 == *(_DWORD *)(v5 + 112) )
    {
      *(_WORD *)(*(_QWORD *)(v5 + 216) + *(unsigned int *)(v5 + 212) + 4LL) = 0;
      v5 = rndis_encapsulate_skb(v5, a2 + 2688);
    }
    v19 = ipa_tx_dp(0x13u, v5, nullptr);
    if ( !v19 )
    {
      _X8 = (unsigned int *)(a2 + 2744);
      __asm { PRFM            #0x11, [X8] }
      do
        v40 = __ldxr(_X8);
      while ( __stxr(v40 + 1, _X8) );
      v9 = 0;
      if ( !*(_DWORD *)(a2 + 2744) )
LABEL_34:
        ((void (__fastcall *)(_QWORD, long double))ipa_pm_deferred_deactivate)(*(unsigned int *)(a2 + 2892), v7);
LABEL_35:
      v10 = ipa_rndis_logbuf;
      if ( !ipa_rndis_logbuf )
        return v9;
      goto LABEL_36;
    }
    _ReadStatusReg(SP_EL0);
    v24 = v19;
    printk(&unk_3C8E80, "rndis_ipa_start_xmit");
    if ( ipa_rndis_logbuf )
      v25 = ipc_log_string(
              ipa_rndis_logbuf,
              "RNDIS_IPA %s:%d ipa transmit failed (%d)\n",
              "rndis_ipa_start_xmit",
              1100,
              v24);
    rndis_ipa_xmit_error(v5, v25);
LABEL_26:
    v9 = 16;
    if ( *(_DWORD *)(a2 + 2744) )
      goto LABEL_35;
    goto LABEL_34;
  }
  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d Failed activate PM client\n", "rndis_ipa_start_xmit", 1047);
  v8 = *(_QWORD *)(a2 + 24);
  *(_QWORD *)(v8 + 328) = jiffies;
  __dmb(0xBu);
  _X8 = (unsigned __int64 *)(v8 + 336);
  __asm { PRFM            #0x11, [X8] }
  do
    v34 = __ldxr(_X8);
  while ( __stxr(v34 | 1, _X8) );
  v9 = 16;
  v10 = ipa_rndis_logbuf;
  if ( ipa_rndis_logbuf )
  {
LABEL_36:
    if ( v9 )
      v20 = "FAIL";
    else
      v20 = "OK";
    ipc_log_string(v10, "RNDIS_IPA %s:%d packet Tx done - %s\n", "rndis_ipa_start_xmit", 1118, v20);
  }
  return v9;
}
