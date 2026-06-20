__int64 __fastcall ipa_get_hdr(__int64 a1)
{
  __int64 hdr; // x0
  unsigned int v3; // w19
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0

  if ( a1 )
  {
    mutex_lock(ipa3_ctx + 29472);
    *(_BYTE *)(a1 + 31) = 0;
    hdr = _ipa_find_hdr(a1);
    if ( hdr )
    {
      v3 = 0;
      *(_DWORD *)(a1 + 32) = *(_DWORD *)(hdr + 340);
    }
    else
    {
      v3 = -1;
    }
    mutex_unlock(ipa3_ctx + 29472);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa_get_hdr__rs, "ipa_get_hdr") )
      printk(&unk_3FB3F2, "ipa_get_hdr");
    v4 = ipa3_ctx;
    if ( !ipa3_ctx )
      return (unsigned int)-22;
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d bad parm\n", "ipa_get_hdr", 1501);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d bad parm\n", "ipa_get_hdr", 1501);
      return (unsigned int)-22;
    }
    else
    {
      return (unsigned int)-22;
    }
  }
  return v3;
}
