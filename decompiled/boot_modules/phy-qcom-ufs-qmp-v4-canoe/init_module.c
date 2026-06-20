__int64 init_module()
{
  return _platform_driver_register(&ufs_qcom_phy_qmp_v4_driver, &_this_module);
}
