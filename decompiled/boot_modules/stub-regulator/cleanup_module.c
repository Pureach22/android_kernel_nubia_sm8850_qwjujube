__int64 cleanup_module()
{
  return platform_driver_unregister(&regulator_stub_driver);
}
