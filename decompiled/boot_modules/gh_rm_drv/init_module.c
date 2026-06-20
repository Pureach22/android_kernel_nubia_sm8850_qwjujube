__int64 init_module()
{
  return _auxiliary_driver_register(gh_rm_driver, &_this_module, "gh_rm_drv");
}
