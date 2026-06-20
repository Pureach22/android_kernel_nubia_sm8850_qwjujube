__int64 cleanup_module()
{
  __int64 v0; // x0
  __int64 result; // x0

  platform_driver_unregister(&ipa_plat_drv);
  v0 = *(_QWORD *)(ipa3_ctx + 43800);
  if ( v0 )
  {
    kfree(v0);
    *(_QWORD *)(ipa3_ctx + 43800) = 0;
  }
  unregister_pm_notifier(&ipa_pm_notifier);
  ipa_ssr_driver_dump_deinit();
  result = kfree(ipa3_ctx);
  ipa3_ctx = 0;
  return result;
}
