__int64 ipa_reset_all_quota_stats()
{
  _BYTE *v0; // x8
  unsigned int quota_stats; // w0
  unsigned int v3; // w19
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0

  v0 = *(_BYTE **)(ipa3_ctx + 43800);
  if ( !v0 || *v0 != 1 )
    return 0;
  quota_stats = ipa_get_quota_stats(nullptr);
  if ( !quota_stats )
  {
    memset((void *)(*(_QWORD *)(ipa3_ctx + 43800) + 16LL), 0, 0x360u);
    return 0;
  }
  v3 = quota_stats;
  printk(&unk_3F5469, "ipa_reset_all_quota_stats");
  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d ipa_get_quota_stats failed %d\n", "ipa_reset_all_quota_stats", 855, v3);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d ipa_get_quota_stats failed %d\n", "ipa_reset_all_quota_stats", 855, v3);
  }
  return v3;
}
