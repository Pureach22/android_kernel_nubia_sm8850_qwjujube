__int64 ipa3_get_smem_restr_bytes()
{
  __int64 result; // x0
  __int64 v1; // x8
  __int64 v2; // x0

  if ( ipa3_ctx )
    return *(unsigned __int16 *)(ipa3_ctx + 29522);
  printk(&unk_3FECEB, "ipa3_get_smem_restr_bytes");
  v1 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 0;
  v2 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v2 )
  {
    ipc_log_string(v2, "ipa %s:%d IPA Driver not initialized\n", "ipa3_get_smem_restr_bytes", 11558);
    v1 = ipa3_ctx;
  }
  result = *(_QWORD *)(v1 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d IPA Driver not initialized\n", "ipa3_get_smem_restr_bytes", 11558);
    return 0;
  }
  return result;
}
