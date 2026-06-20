__int64 cleanup_module()
{
  return platform_driver_unregister(&ufs_qcom_phy_qrbtc_sdm845_driver);
}
