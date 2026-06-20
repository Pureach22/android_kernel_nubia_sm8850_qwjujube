__int64 __fastcall rndis_ipa_stop(__int64 a1)
{
  __int64 v2; // x20
  int state; // w0
  __int64 result; // x0
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 v7; // x8
  const char *v8; // x4
  unsigned __int64 v15; // x9

  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_stop", 1321);
  v2 = raw_spin_lock_irqsave(a1 + 2888);
  state = rndis_ipa_next_state(*(_DWORD *)(a1 + 2760), 3);
  if ( state == 5 )
  {
    raw_spin_unlock_irqrestore(a1 + 2888, v2);
    if ( ipa_rndis_logbuf )
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d can't do network interface down without up\n",
        "rndis_ipa_stop",
        1328);
    return 0xFFFFFFFFLL;
  }
  else
  {
    *(_DWORD *)(a1 + 2760) = state;
    raw_spin_unlock_irqrestore(a1 + 2888, v2);
    v6 = *(_QWORD *)(a1 + 24);
    *(_QWORD *)(v6 + 328) = jiffies;
    __dmb(0xBu);
    _X8 = (unsigned __int64 *)(v6 + 336);
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 | 1, _X8) );
    printk(&unk_3EE1E4, v5);
    result = ipa_rndis_logbuf;
    if ( ipa_rndis_logbuf )
    {
      v7 = *(unsigned int *)(a1 + 2760);
      v8 = (unsigned int)v7 > 4 ? "Not supported" : off_1F6620[v7];
      ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d Driver state: %s\n", "rndis_ipa_stop", 1339, v8);
      result = ipa_rndis_logbuf;
      if ( ipa_rndis_logbuf )
      {
        ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d end\n", "rndis_ipa_stop", 1341);
        return 0;
      }
    }
  }
  return result;
}
