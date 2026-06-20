__int64 ipa3_get_max_pdn()
{
  __int64 v0; // x8
  unsigned __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x0
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  ipahal_nat_entry_size(2, v5);
  v0 = ipa3_ctx;
  v1 = (unsigned __int64)*(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 292LL) / v5[0];
  if ( ipa3_ctx )
  {
    v2 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d IPA offload max_pdn = %d\n", "ipa3_get_max_pdn", 14182, v1);
      v0 = ipa3_ctx;
    }
    v3 = *(_QWORD *)(v0 + 34160);
    if ( v3 )
      ipc_log_string(v3, "ipa %s:%d IPA offload max_pdn = %d\n", "ipa3_get_max_pdn", 14182, v1);
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v1;
}
