__int64 ipa3_cfg_filter()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0

  if ( (unsigned int)__ratelimit(&ipa3_cfg_filter__rs, "ipa3_cfg_filter") )
    printk(&unk_3DF014, "ipa3_cfg_filter");
  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d Filter disable is not supported!\n", "ipa3_cfg_filter", 7992);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d Filter disable is not supported!\n", "ipa3_cfg_filter", 7992);
  }
  return 0xFFFFFFFFLL;
}
