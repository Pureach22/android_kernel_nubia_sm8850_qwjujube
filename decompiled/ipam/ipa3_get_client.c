__int64 __fastcall ipa3_get_client(unsigned int a1)
{
  unsigned int v1; // w9
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0

  if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x14u )
    v1 = 31;
  else
    v1 = 36;
  if ( (a1 & 0x80000000) == 0 && v1 > a1 )
    return *(unsigned int *)(ipa3_ctx + 8LL * a1 + 43348);
  printk(&unk_3C1A24, "ipa3_get_client");
  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d Bad pipe index! pipe_idx =%d\n", "ipa3_get_client", 8550, a1);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d Bad pipe index! pipe_idx =%d\n", "ipa3_get_client", 8550, a1);
  }
  return 3;
}
