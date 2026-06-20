__int64 cleanup_module()
{
  return platform_driver_unregister(&ufs_qcom_phy_qmp_v4_driver);
}
