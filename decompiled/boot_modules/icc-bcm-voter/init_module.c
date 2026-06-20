__int64 init_module()
{
  return _platform_driver_register(qcom_icc_bcm_voter_driver, &_this_module);
}
