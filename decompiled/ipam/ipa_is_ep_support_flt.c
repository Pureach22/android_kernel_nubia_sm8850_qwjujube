__int64 __fastcall ipa_is_ep_support_flt(unsigned int a1)
{
  __int64 result; // x0
  __int64 v2; // x8
  __int64 v3; // x0

  if ( (a1 & 0x80000000) == 0 && *(_DWORD *)(ipa3_ctx + 34308) > a1 )
    return (*(_QWORD *)(ipa3_ctx + 17488) >> a1) & 1LL;
  printk(&unk_3E7136, "ipa_is_ep_support_flt");
  v2 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 0;
  v3 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v3 )
  {
    ipc_log_string(v3, "ipa %s:%d Bad pipe index!\n", "ipa_is_ep_support_flt", 8668);
    v2 = ipa3_ctx;
  }
  result = *(_QWORD *)(v2 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d Bad pipe index!\n", "ipa_is_ep_support_flt", 8668);
    return 0;
  }
  return result;
}
