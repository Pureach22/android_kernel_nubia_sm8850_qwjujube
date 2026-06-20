void __fastcall rndis_ipa_pm_cb(__int64 a1, int a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  unsigned __int64 v13; // x10

  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_pm_cb", 1971);
  if ( a2 )
  {
    if ( (unsigned int)__ratelimit(&rndis_ipa_pm_cb__rs, "rndis_ipa_pm_cb") )
    {
      _ReadStatusReg(SP_EL0);
      printk(&unk_3F14EF, "rndis_ipa_pm_cb");
      v4 = ipa_rndis_logbuf;
      if ( !ipa_rndis_logbuf )
        goto LABEL_7;
    }
    else
    {
      v4 = ipa_rndis_logbuf;
      if ( !ipa_rndis_logbuf )
      {
LABEL_7:
        __break(0x800u);
        return;
      }
    }
    ipc_log_string(v4, "RNDIS_IPA %s:%d unexpected event %d\n", "rndis_ipa_pm_cb", 1974, a2);
    goto LABEL_7;
  }
  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d Resource Granted\n", "rndis_ipa_pm_cb", 1978);
  v5 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  if ( (*(_QWORD *)(v5 + 336) & 1) == 0 )
  {
    if ( !ipa_rndis_logbuf )
      return;
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d queue already awake\n", "rndis_ipa_pm_cb", 1984);
    v6 = ipa_rndis_logbuf;
    if ( !ipa_rndis_logbuf )
      return;
LABEL_17:
    ipc_log_string(v6, "RNDIS_IPA %s:%d end\n", "rndis_ipa_pm_cb", 1987);
    return;
  }
  if ( ipa_rndis_logbuf )
  {
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d starting queue\n", "rndis_ipa_pm_cb", 1981);
    v5 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  }
  _X8 = (unsigned __int64 *)(v5 + 336);
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 & 0xFFFFFFFFFFFFFFFELL, _X8) );
  v6 = ipa_rndis_logbuf;
  if ( ipa_rndis_logbuf )
    goto LABEL_17;
}
