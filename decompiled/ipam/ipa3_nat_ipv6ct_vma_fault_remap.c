__int64 __fastcall ipa3_nat_ipv6ct_vma_fault_remap(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0

  *(_QWORD *)(a1 + 80) = 0;
  v1 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v2 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d \n", "ipa3_nat_ipv6ct_vma_fault_remap", 69);
      v1 = ipa3_ctx;
    }
    v3 = *(_QWORD *)(v1 + 34160);
    if ( v3 )
      ipc_log_string(v3, "ipa %s:%d \n", "ipa3_nat_ipv6ct_vma_fault_remap", 69);
  }
  return 2;
}
