__int64 cleanup_module()
{
  __int64 v0; // x20
  __int64 v1; // x0

  v0 = drv;
  qcom_unregister_ssr_notifier(*(_QWORD *)(drv + 8), drv + 16);
  v1 = drv;
  *(_QWORD *)(v0 + 8) = 0;
  return kfree(v1);
}
