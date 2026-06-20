__int64 __fastcall ipa3_nat_ipv6ct_open(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0

  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d \n", "ipa3_nat_ipv6ct_open", 118);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d \n", "ipa3_nat_ipv6ct_open", 118);
      v4 = ipa3_ctx;
    }
    *(_QWORD *)(a2 + 32) = *(_QWORD *)(a1 + 656) - 80LL;
    if ( v4 )
    {
      v7 = *(_QWORD *)(v4 + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d return\n", "ipa3_nat_ipv6ct_open", 122);
        v4 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v4 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d return\n", "ipa3_nat_ipv6ct_open", 122);
    }
  }
  else
  {
    *(_QWORD *)(a2 + 32) = *(_QWORD *)(a1 + 656) - 80LL;
  }
  return 0;
}
