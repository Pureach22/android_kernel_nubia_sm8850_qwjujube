__int64 init_module()
{
  rpmh_reg_ipc_log = ipc_log_context_create(10, "rpmh_regulator", 0);
  return _platform_driver_register(&rpmh_regulator_driver, &_this_module);
}
