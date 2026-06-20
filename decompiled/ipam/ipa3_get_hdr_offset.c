__int64 __fastcall ipa3_get_hdr_offset(__int64 a1, _DWORD *a2)
{
  __int64 hdr; // x0
  __int64 v5; // x8
  unsigned int v6; // w19
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0

  if ( a1 && a2 )
  {
    mutex_lock(ipa3_ctx + 29472);
    *(_BYTE *)(a1 + 31) = 0;
    hdr = _ipa_find_hdr((const char *)a1);
    if ( hdr && (v5 = *(_QWORD *)(hdr + 328)) != 0 )
    {
      v6 = 0;
      *a2 = *(_DWORD *)(v5 + 16);
    }
    else
    {
      v6 = -1;
    }
    mutex_unlock(ipa3_ctx + 29472);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_get_hdr_offset__rs, "ipa3_get_hdr_offset") )
      printk(&unk_3FB3F2, "ipa3_get_hdr_offset");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d bad parm\n", "ipa3_get_hdr_offset", 1533);
        v7 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v7 + 34160);
      if ( v9 )
        ipc_log_string(v9, "ipa %s:%d bad parm\n", "ipa3_get_hdr_offset", 1533);
    }
    return (unsigned int)-22;
  }
  return v6;
}
