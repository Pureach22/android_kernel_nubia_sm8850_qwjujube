__int64 __fastcall ipa3_commit_flt(unsigned int a1)
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0
  unsigned int v4; // w19
  unsigned int (__fastcall *v6)(_QWORD); // x8

  if ( a1 < 2 )
  {
    mutex_lock(ipa3_ctx + 29472);
    v6 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 112LL);
    if ( *((_DWORD *)v6 - 1) != 1856640366 )
      __break(0x8228u);
    if ( v6(a1) )
      v4 = -1;
    else
      v4 = 0;
    mutex_unlock(ipa3_ctx + 29472);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_commit_flt__rs, "ipa3_commit_flt") )
      printk(&unk_3C3EF1, "ipa3_commit_flt");
    v1 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v2 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v2 )
      {
        ipc_log_string(v2, "ipa %s:%d bad param\n", "ipa3_commit_flt", 1860);
        v1 = ipa3_ctx;
      }
      v3 = *(_QWORD *)(v1 + 34160);
      if ( v3 )
        ipc_log_string(v3, "ipa %s:%d bad param\n", "ipa3_commit_flt", 1860);
    }
    return (unsigned int)-22;
  }
  return v4;
}
