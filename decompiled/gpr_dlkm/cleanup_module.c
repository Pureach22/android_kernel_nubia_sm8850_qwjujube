__int64 cleanup_module()
{
  bus_unregister(&gprbus);
  return unregister_rpmsg_driver(&gpr_driver);
}
