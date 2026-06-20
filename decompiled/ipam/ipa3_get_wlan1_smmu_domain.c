__int64 ipa3_get_wlan1_smmu_domain()
{
  __int64 result; // x0
  __int64 v1; // x8
  __int64 v2; // x0

  if ( byte_1F7880 == 1 )
    return qword_1F7890;
  printk(&unk_3C309A, "ipa3_get_smmu_domain_by_type");
  v1 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 0;
  v2 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v2 )
  {
    ipc_log_string(v2, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 2);
    v1 = ipa3_ctx;
  }
  result = *(_QWORD *)(v1 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d cb_type(%d) not valid\n", "ipa3_get_smmu_domain_by_type", 942, 2);
    return 0;
  }
  return result;
}
