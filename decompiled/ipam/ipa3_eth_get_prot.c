__int64 __fastcall ipa3_eth_get_prot(__int64 a1, int *a2)
{
  __int64 v2; // x3
  __int64 result; // x0
  int v4; // w8
  int *v6; // x19
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0

  v2 = **(unsigned int **)(a1 + 160);
  if ( (unsigned int)v2 >= 6 )
  {
    v6 = a2;
    printk(&unk_3FB38D, "ipa3_eth_get_prot");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d invalid client type%d\n", "ipa3_eth_get_prot", 887, **(_DWORD **)(a1 + 160));
        v7 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v7 + 34160);
      if ( v9 )
        ipc_log_string(v9, "ipa %s:%d invalid client type%d\n", "ipa3_eth_get_prot", 887, **(_DWORD **)(a1 + 160));
    }
    result = 4294967282LL;
    v4 = 11;
    a2 = v6;
  }
  else
  {
    result = 0;
    v4 = dword_1B607C[v2];
  }
  *a2 = v4;
  return result;
}
