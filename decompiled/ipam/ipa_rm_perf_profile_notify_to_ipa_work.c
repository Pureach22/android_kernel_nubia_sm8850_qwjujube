__int64 __fastcall ipa_rm_perf_profile_notify_to_ipa_work(__int64 a1)
{
  long double v2; // q0
  __int64 ipc_logbuf_low; // x0
  int v4; // w0
  __int64 v5; // x0
  int v7; // w20
  __int64 ipc_logbuf; // x0
  __int64 v9; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v2 = ipc_log_string(
           ipc_logbuf_low,
           "ipa_rm %s:%d calling to IPA driver. voltage %d bandwidth %d\n",
           "ipa_rm_perf_profile_notify_to_ipa_work",
           627,
           *(_DWORD *)(a1 + 32),
           *(_DWORD *)(a1 + 36));
  }
  v4 = ((__int64 (__fastcall *)(_QWORD, _QWORD, long double))ipa3_set_required_perf_profile)(
         *(unsigned int *)(a1 + 32),
         *(unsigned int *)(a1 + 36),
         v2);
  if ( v4 )
  {
    v7 = v4;
    printk(&unk_3EB666, "ipa_rm_perf_profile_notify_to_ipa_work");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_rm %s:%d ipa3_set_required_perf_profile failed %d\n",
        "ipa_rm_perf_profile_notify_to_ipa_work",
        632,
        v7);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v9,
        "ipa_rm %s:%d ipa3_set_required_perf_profile failed %d\n",
        "ipa_rm_perf_profile_notify_to_ipa_work",
        632,
        v7);
    }
  }
  else if ( ipa3_get_ipc_logbuf_low() )
  {
    v5 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v5, "ipa_rm %s:%d IPA driver notified\n", "ipa_rm_perf_profile_notify_to_ipa_work", 636);
  }
  return kfree(a1);
}
