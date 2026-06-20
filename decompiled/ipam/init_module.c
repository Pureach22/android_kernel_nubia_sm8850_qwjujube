__int64 init_module()
{
  __int64 v0; // x0
  __int64 v1; // x8

  v0 = _kmalloc_large_noprof(52544, 3520);
  ipa3_ctx = v0;
  if ( !v0 )
    return 4294967284LL;
  _mutex_init(v0 + 29472, "&ipa3_ctx->lock", &ipa_module_init___key);
  v1 = ipa3_ctx + 40960;
  *(_QWORD *)(ipa3_ctx + 43640) = ipa3_ctx + 43640;
  *(_QWORD *)(v1 + 2688) = v1 + 2680;
  register_pm_notifier(&ipa_pm_notifier);
  return _platform_driver_register(&ipa_plat_drv, &_this_module);
}
