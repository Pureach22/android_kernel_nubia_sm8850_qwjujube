__int64 ipa_opt_log_open()
{
  __int64 v0; // x8
  char v1; // w9
  unsigned int v2; // w19
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0

  mutex_lock(ipa3_opt_log_ctx + 224);
  v0 = ipa3_opt_log_ctx;
  v1 = *(_BYTE *)(ipa3_opt_log_ctx + 272);
  if ( (v1 & 1) != 0 )
  {
    v2 = 0;
    *(_DWORD *)(ipa3_opt_log_ctx + 284) = 0;
    *(_DWORD *)(v0 + 288) = 0;
    *(_QWORD *)(v0 + 276) = 0;
    *(_BYTE *)(v0 + 272) = v1 | 2;
  }
  else
  {
    printk(&unk_3C9E90, "ipa_opt_log_open");
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(
          v5,
          "ipa %s:%d Trying to open opt log char device before initializing it\n",
          "ipa_opt_log_open",
          91);
        v4 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v4 + 34160);
      if ( v6 )
        ipc_log_string(
          v6,
          "ipa %s:%d Trying to open opt log char device before initializing it\n",
          "ipa_opt_log_open",
          91);
    }
    v2 = -19;
  }
  mutex_unlock(ipa3_opt_log_ctx + 224);
  return v2;
}
