__int64 cleanup_module()
{
  return scmi_driver_unregister(&scmi_clocks_driver);
}
