__int64 __fastcall ipa_host_ramdump_dev_release(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0

  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d free host ramdump device\n", "ipa_host_ramdump_dev_release", 30);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d free host ramdump device\n", "ipa_host_ramdump_dev_release", 30);
  }
  return kfree(a1);
}
