__int64 __fastcall ipa3_time_gran_usec_step(unsigned int a1)
{
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x0

  if ( a1 < 8 )
    return dword_4017F8[a1];
  v3 = printk(&unk_3BC015, "ipa3_time_gran_usec_step");
  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d Invalid granularity time unit %d\n", "ipa3_time_gran_usec_step", 9526, a1);
      v4 = ipa3_ctx;
    }
    v3 = *(_QWORD *)(v4 + 34160);
    if ( v3 )
      v3 = ipc_log_string(v3, "ipa %s:%d Invalid granularity time unit %d\n", "ipa3_time_gran_usec_step", 9526, a1);
  }
  ((void (__fastcall *)(__int64))ipa_assert)(v3);
  return 100;
}
