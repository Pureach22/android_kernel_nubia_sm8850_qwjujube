__int64 cleanup_module()
{
  return platform_driver_unregister(&qmp_combo_driver);
}
