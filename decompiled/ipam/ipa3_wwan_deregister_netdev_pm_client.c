__int64 ipa3_wwan_deregister_netdev_pm_client()
{
  ((void (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(rmnet_ipa3_ctx + 1184));
  return ((__int64 (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(rmnet_ipa3_ctx + 1184));
}
