__int64 __fastcall ipa3_get_hdr_proc_ctx_offset(__int64 a1, unsigned int *a2)
{
  __int64 hdr; // x0
  __int64 v5; // x8
  __int64 v6; // x8
  unsigned int v7; // w19
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0

  if ( a1 && a2 )
  {
    mutex_lock(ipa3_ctx + 29472);
    *(_BYTE *)(a1 + 31) = 0;
    hdr = _ipa_find_hdr((const char *)a1);
    if ( hdr && (v5 = *(_QWORD *)(hdr + 320)) != 0 && (v6 = *(_QWORD *)(v5 + 56)) != 0 )
    {
      v7 = 0;
      *a2 = (unsigned int)(*(_DWORD *)(ipa3_ctx + 29176) + *(_DWORD *)(v6 + 16)) >> 5;
    }
    else
    {
      v7 = -1;
    }
    mutex_unlock(ipa3_ctx + 29472);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_get_hdr_proc_ctx_offset__rs, "ipa3_get_hdr_proc_ctx_offset") )
      printk(&unk_3FB3F2, "ipa3_get_hdr_proc_ctx_offset");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d bad parm\n", "ipa3_get_hdr_proc_ctx_offset", 1602);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(v10, "ipa %s:%d bad parm\n", "ipa3_get_hdr_proc_ctx_offset", 1602);
    }
    return (unsigned int)-22;
  }
  return v7;
}
