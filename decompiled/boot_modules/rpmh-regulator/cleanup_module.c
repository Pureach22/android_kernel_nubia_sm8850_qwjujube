__int64 cleanup_module()
{
  if ( rpmh_reg_ipc_log )
    ipc_log_context_destroy();
  return platform_driver_unregister(&rpmh_regulator_driver);
}
