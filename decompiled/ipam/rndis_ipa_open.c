__int64 __fastcall rndis_ipa_open(__int64 a1)
{
  __int64 v2; // x20
  int state; // w0
  __int64 v4; // x0
  __int64 result; // x0
  int v6; // w22
  __int64 v7; // x1
  __int64 v8; // x8
  const char *v9; // x4

  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_open", 949);
  v2 = raw_spin_lock_irqsave(a1 + 2888);
  state = rndis_ipa_next_state(*(_DWORD *)(a1 + 2760), 2);
  if ( state == 5 )
  {
    raw_spin_unlock_irqrestore(a1 + 2888, v2);
    if ( (unsigned int)__ratelimit(&rndis_ipa_open__rs, "rndis_ipa_open") )
    {
      _ReadStatusReg(SP_EL0);
      printk(&unk_3AEC12, "rndis_ipa_open");
      v4 = ipa_rndis_logbuf;
      if ( !ipa_rndis_logbuf )
        return 0xFFFFFFFFLL;
    }
    else
    {
      v4 = ipa_rndis_logbuf;
      if ( !ipa_rndis_logbuf )
        return 0xFFFFFFFFLL;
    }
    ipc_log_string(v4, "RNDIS_IPA %s:%d can't bring driver up before initialize\n", "rndis_ipa_open", 958);
    return 0xFFFFFFFFLL;
  }
  v6 = state;
  *(_DWORD *)(a1 + 2760) = state;
  raw_spin_unlock_irqrestore(a1 + 2888, v2);
  if ( ipa_rndis_logbuf )
  {
    v8 = *(unsigned int *)(a1 + 2760);
    if ( (unsigned int)v8 > 4 )
      v9 = "Not supported";
    else
      v9 = off_1F6620[v8];
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d Driver state: %s\n", "rndis_ipa_open", 966, v9);
  }
  if ( v6 == 4 )
  {
    rndis_ipa_enable_data_path((_QWORD *)(a1 + 2688));
  }
  else if ( ipa_rndis_logbuf )
  {
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d queue shall be started after connect()\n", "rndis_ipa_open", 971);
  }
  printk(&unk_3E57E2, v7);
  result = ipa_rndis_logbuf;
  if ( ipa_rndis_logbuf )
  {
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d end\n", "rndis_ipa_open", 975);
    return 0;
  }
  return result;
}
