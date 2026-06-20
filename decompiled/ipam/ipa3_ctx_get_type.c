__int64 __fastcall ipa3_ctx_get_type(int a1)
{
  __int64 v1; // x9
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x0

  switch ( a1 )
  {
    case 2:
      v1 = 32248;
      return *(unsigned int *)(ipa3_ctx + v1);
    case 1:
      v1 = 32256;
      return *(unsigned int *)(ipa3_ctx + v1);
    case 0:
      v1 = 32240;
      return *(unsigned int *)(ipa3_ctx + v1);
  }
  printk(&unk_3D0904, "ipa3_ctx_get_type");
  v3 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 0;
  v4 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v4 )
  {
    ipc_log_string(v4, "ipa %s:%d cannot read ipa3_ctx types\n", "ipa3_ctx_get_type", 13859);
    v3 = ipa3_ctx;
  }
  result = *(_QWORD *)(v3 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d cannot read ipa3_ctx types\n", "ipa3_ctx_get_type", 13859);
    return 0;
  }
  return result;
}
