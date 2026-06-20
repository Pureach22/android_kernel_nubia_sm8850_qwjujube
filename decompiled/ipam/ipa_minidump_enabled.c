__int64 ipa_minidump_enabled()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  _DWORD *v3; // x0
  _DWORD *v4; // x19
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0

  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d Checking if minidump enabled\n", "ipa_minidump_enabled", 43);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d Checking if minidump enabled\n", "ipa_minidump_enabled", 43);
  }
  if ( (dump_enabled() & 1) == 0 )
  {
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d Dump not enabled\n", "ipa_minidump_enabled", 45);
        v9 = ipa3_ctx;
      }
      result = *(_QWORD *)(v9 + 34160);
      if ( !result )
        return result;
      ipc_log_string(result, "ipa %s:%d Dump not enabled\n", "ipa_minidump_enabled", 45);
    }
    return 0;
  }
  v3 = (_DWORD *)qcom_smem_get(0xFFFFFFFFLL, 602, 0);
  if ( (unsigned __int64)v3 <= 0xFFFFFFFFFFFFF000LL )
  {
    v4 = v3;
    if ( *v3 )
    {
      v5 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v6 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v6 )
        {
          ipc_log_string(
            v6,
            "ipa %s:%d baseptr: %llu, status: %d, enabled : %d, equal: %d\n",
            "ipa_minidump_enabled",
            69,
            *((_QWORD *)v4 + 17),
            (unsigned int)v4[28]);
          v5 = ipa3_ctx;
        }
        v7 = *(_QWORD *)(v5 + 34160);
        if ( v7 )
          ipc_log_string(
            v7,
            "ipa %s:%d baseptr: %llu, status: %d, enabled : %d, equal: %d\n",
            "ipa_minidump_enabled",
            69,
            *((_QWORD *)v4 + 17),
            (unsigned int)v4[28]);
      }
      if ( *((_QWORD *)v4 + 17) && v4[28] == 1 )
        return v4[29] == 1162756684;
      return 0;
    }
  }
  printk(&unk_3A6665, "ipa_minidump_enabled");
  v11 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 0;
  v12 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v12 )
  {
    ipc_log_string(v12, "ipa %s:%d Minidump TOC not found in SMEM\n", "ipa_minidump_enabled", 54);
    v11 = ipa3_ctx;
  }
  result = *(_QWORD *)(v11 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d Minidump TOC not found in SMEM\n", "ipa_minidump_enabled", 54);
    return 0;
  }
  return result;
}
