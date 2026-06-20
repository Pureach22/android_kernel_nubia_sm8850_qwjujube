__int64 __fastcall ipa3_pull_msg(unsigned __int16 *a1, const void *a2, __int64 a3)
{
  __int64 v6; // x8
  _QWORD *v7; // x9
  _DWORD *v8; // x8
  unsigned int v9; // w0
  unsigned int v10; // w19
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0

  if ( a1 && a2 && a3 )
  {
    mutex_lock(ipa3_ctx + 32104);
    v6 = ipa3_ctx;
    v7 = *(_QWORD **)(ipa3_ctx + 32088);
    if ( v7 == (_QWORD *)(ipa3_ctx + 32088) )
    {
LABEL_20:
      v10 = -22;
    }
    else
    {
      while ( *((unsigned __int16 *)v7 - 7) != a1[1] || *((unsigned __int8 *)v7 - 16) != *(unsigned __int8 *)a1 )
      {
        v7 = (_QWORD *)*v7;
        if ( v7 == (_QWORD *)(ipa3_ctx + 32088) )
          goto LABEL_20;
      }
      v8 = (_DWORD *)*(v7 - 1);
      if ( *(v8 - 1) != -1378032659 )
        __break(0x8228u);
      v9 = ((__int64 (__fastcall *)(const void *, _QWORD))v8)(a2, (unsigned int)a3);
      v6 = ipa3_ctx;
      v10 = v9;
    }
    mutex_unlock(v6 + 32104);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_pull_msg__rs, "ipa3_pull_msg") )
      printk(&unk_3C7023, "ipa3_pull_msg");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d invalid param name=%pK buff=%pK count=%zu\n", "ipa3_pull_msg", 817, a1, a2, a3);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
        ipc_log_string(v13, "ipa %s:%d invalid param name=%pK buff=%pK count=%zu\n", "ipa3_pull_msg", 817, a1, a2, a3);
    }
    return (unsigned int)-22;
  }
  return v10;
}
