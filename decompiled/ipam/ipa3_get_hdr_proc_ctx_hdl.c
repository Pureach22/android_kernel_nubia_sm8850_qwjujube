__int64 __fastcall ipa3_get_hdr_proc_ctx_hdl(__int64 a1)
{
  __int64 hdr; // x0
  __int64 v3; // x8
  unsigned int v4; // w19
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0

  if ( a1 )
  {
    mutex_lock(ipa3_ctx + 29472);
    *(_BYTE *)(a1 + 31) = 0;
    hdr = _ipa_find_hdr((const char *)a1);
    if ( hdr && (v3 = *(_QWORD *)(hdr + 320)) != 0 )
    {
      v4 = 0;
      *(_DWORD *)(a1 + 32) = *(_DWORD *)(v3 + 76);
    }
    else
    {
      v4 = -1;
    }
    mutex_unlock(ipa3_ctx + 29472);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_get_hdr_proc_ctx_hdl__rs, "ipa3_get_hdr_proc_ctx_hdl") )
      printk(&unk_3FB3F2, "ipa3_get_hdr_proc_ctx_hdl");
    v5 = ipa3_ctx;
    if ( !ipa3_ctx )
      return (unsigned int)-22;
    v6 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d bad parm\n", "ipa3_get_hdr_proc_ctx_hdl", 1566);
      v5 = ipa3_ctx;
    }
    v7 = *(_QWORD *)(v5 + 34160);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d bad parm\n", "ipa3_get_hdr_proc_ctx_hdl", 1566);
      return (unsigned int)-22;
    }
    else
    {
      return (unsigned int)-22;
    }
  }
  return v4;
}
