__int64 __fastcall ipa3_commit_rt(unsigned int a1)
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0
  unsigned int (__fastcall *v6)(_QWORD); // x8
  unsigned int v7; // w19

  if ( a1 < 2 )
  {
    if ( (unsigned int)ipa3_commit_flt(a1) )
    {
      return 0xFFFFFFFFLL;
    }
    else
    {
      mutex_lock(ipa3_ctx + 29472);
      v6 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 120LL);
      if ( *((_DWORD *)v6 - 1) != 1856640366 )
        __break(0x8228u);
      if ( v6(a1) )
        v7 = -1;
      else
        v7 = 0;
      mutex_unlock(ipa3_ctx + 29472);
      return v7;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_commit_rt__rs, "ipa3_commit_rt") )
      printk(&unk_3C3EF1, "ipa3_commit_rt");
    v1 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v2 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v2 )
      {
        ipc_log_string(v2, "ipa %s:%d bad param\n", "ipa3_commit_rt", 1905);
        v1 = ipa3_ctx;
      }
      v3 = *(_QWORD *)(v1 + 34160);
      if ( v3 )
        ipc_log_string(v3, "ipa %s:%d bad param\n", "ipa3_commit_rt", 1905);
    }
    return 4294967274LL;
  }
}
