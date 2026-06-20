__int64 init_module()
{
  return _register_rpmsg_driver(&sysmon_driver, &_this_module);
}
