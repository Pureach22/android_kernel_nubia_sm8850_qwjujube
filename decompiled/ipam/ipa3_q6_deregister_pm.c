__int64 ipa3_q6_deregister_pm()
{
  ((void (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(rmnet_ipa3_ctx + 1188));
  return ((__int64 (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(rmnet_ipa3_ctx + 1188));
}
