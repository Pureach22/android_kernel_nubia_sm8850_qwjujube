__int64 __fastcall ipa3_get_smmu_domain_by_type(unsigned int a1)
{
  char *v1; // x8
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0

  if ( a1 <= 6 )
  {
    v1 = &smmu_cb[56 * a1];
    if ( *v1 == 1 )
      return *((_QWORD *)v1 + 2);
  }
  printk(&unk_3C309A, "ipa3_get_smmu_domain_by_type");
  v4 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 0;
  v5 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v5 )
  {
    ipc_log_string(v5, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, a1);
    v4 = ipa3_ctx;
  }
  result = *(_QWORD *)(v4 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, a1);
    return 0;
  }
  return result;
}
