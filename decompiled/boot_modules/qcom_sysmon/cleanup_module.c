__int64 cleanup_module()
{
  return unregister_rpmsg_driver(&sysmon_driver);
}
