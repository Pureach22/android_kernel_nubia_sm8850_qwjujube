__int64 init_module()
{
  return _platform_driver_register(qcom_slim_ngd_ctrl_driver, &_this_module);
}
