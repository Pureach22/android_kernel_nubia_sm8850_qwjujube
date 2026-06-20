__int64 ipa3_commit_hdr()
{
  __int64 v1; // x0
  unsigned int (__fastcall *v2)(_QWORD); // x8
  unsigned int v3; // w19

  if ( (unsigned int)ipa3_commit_rt(0) || (unsigned int)ipa3_commit_rt(1) )
    return 0xFFFFFFFFLL;
  v1 = mutex_lock(ipa3_ctx + 29472);
  v2 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 128LL);
  if ( *((_DWORD *)v2 - 1) != 1874538549 )
    __break(0x8228u);
  if ( v2(v1) )
    v3 = -1;
  else
    v3 = 0;
  mutex_unlock(ipa3_ctx + 29472);
  return v3;
}
