void __fastcall rndis_ipa_tx_complete_notify(unsigned int *a1, int a2, __int64 a3, long double a4)
{
  __int64 v7; // x8
  __int64 v8; // x0
  unsigned int v9; // w4
  __int64 v10; // x0
  const char *v11; // x4
  unsigned int v18; // w10

  if ( a1 )
  {
    if ( ipa_rndis_logbuf )
      a4 = ipc_log_string(
             ipa_rndis_logbuf,
             "RNDIS_IPA %s:%d Tx-complete, len=%d, skb->prot=%d, outstanding=%d\n",
             "rndis_ipa_tx_complete_notify",
             1156,
             *(_DWORD *)(a3 + 112),
             *(unsigned __int16 *)(a3 + 180),
             a1[14]);
    if ( a2 != 1 )
    {
      if ( (unsigned int)__ratelimit(&rndis_ipa_tx_complete_notify__rs, "rndis_ipa_tx_complete_notify") )
      {
        _ReadStatusReg(SP_EL0);
        printk(&unk_3A5DB8, "rndis_ipa_tx_complete_notify");
        v10 = ipa_rndis_logbuf;
        if ( !ipa_rndis_logbuf )
          return;
      }
      else
      {
        v10 = ipa_rndis_logbuf;
        if ( !ipa_rndis_logbuf )
          return;
      }
      ipc_log_string(v10, "RNDIS_IPA %s:%d unsupported event on TX call-back\n", "rndis_ipa_tx_complete_notify", 1159);
      return;
    }
    v7 = a1[18];
    if ( (_DWORD)v7 == 4 )
    {
      ++*(_QWORD *)(*(_QWORD *)a1 + 560LL);
      *(_QWORD *)(*(_QWORD *)a1 + 576LL) += *(unsigned int *)(a3 + 112);
      if ( (int)a1[14] >= 1 )
      {
        _X8 = a1 + 14;
        __asm { PRFM            #0x11, [X8] }
        do
          v18 = __ldxr(_X8);
        while ( __stxr(v18 - 1, _X8) );
      }
      v8 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
      if ( (*(_QWORD *)(v8 + 336) & 1) != 0 && (*(_QWORD *)(*(_QWORD *)a1 + 168LL) & 4) == 0 )
      {
        v9 = a1[16];
        if ( a1[14] < v9 )
        {
          if ( ipa_rndis_logbuf )
          {
            a4 = ipc_log_string(
                   ipa_rndis_logbuf,
                   "RNDIS_IPA %s:%d outstanding low boundary reached (%d)n",
                   "rndis_ipa_tx_complete_notify",
                   1182,
                   v9);
            v8 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
          }
          netif_tx_wake_queue(v8, a4);
          if ( ipa_rndis_logbuf )
            a4 = ipc_log_string(
                   ipa_rndis_logbuf,
                   "RNDIS_IPA %s:%d send queue was awaken\n",
                   "rndis_ipa_tx_complete_notify",
                   1184);
        }
      }
      if ( !a1[14] )
        ((void (__fastcall *)(_QWORD, long double))ipa_pm_deferred_deactivate)(a1[51], a4);
    }
    else if ( ipa_rndis_logbuf )
    {
      if ( (unsigned int)v7 > 3 )
        v11 = "Not supported";
      else
        v11 = off_1F65B0[v7];
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d dropping Tx-complete pkt, state=%s\n",
        "rndis_ipa_tx_complete_notify",
        1166,
        v11);
    }
    dev_kfree_skb_any_reason(a3, 2);
  }
  else
  {
    _ReadStatusReg(SP_EL0);
    printk(&unk_3E01BA, "rndis_ipa_tx_complete_notify");
    if ( ipa_rndis_logbuf )
      ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d null pointer #ptr\n", "rndis_ipa_tx_complete_notify", 1147);
  }
}
