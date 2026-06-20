__int64 __fastcall ipa_reset_drop_stats(unsigned int a1)
{
  _BYTE *v1; // x8
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w19
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0

  v1 = *(_BYTE **)(ipa3_ctx + 43800);
  if ( !v1 || *v1 != 1 )
    return 0;
  if ( a1 >= 0x86 )
  {
    printk(&unk_3AFAF2, "ipa_reset_drop_stats");
    v4 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967274LL;
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d invalid client %d\n", "ipa_reset_drop_stats", 2286, a1);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d invalid client %d\n", "ipa_reset_drop_stats", 2286, a1);
      return 4294967274LL;
    }
    else
    {
      return 4294967274LL;
    }
  }
  else
  {
    result = ipa_get_drop_stats(nullptr);
    if ( (_DWORD)result )
    {
      v7 = result;
      printk(&unk_3D2D23, "ipa_reset_drop_stats");
      v8 = ipa3_ctx;
      if ( !ipa3_ctx )
        return v7;
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d ipa_get_drop_stats failed %d\n", "ipa_reset_drop_stats", 2293, v7);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d ipa_get_drop_stats failed %d\n", "ipa_reset_drop_stats", 2293, v7);
        return v7;
      }
      else
      {
        return v7;
      }
    }
    else
    {
      *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 43800) + 8LL * a1 + 63904) = 0;
    }
  }
  return result;
}
