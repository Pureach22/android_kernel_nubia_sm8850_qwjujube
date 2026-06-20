__int64 cleanup_module()
{
  unregister_rpmsg_driver(&pmic_glink_rpmsg_driver);
  return platform_driver_unregister(pmic_glink_driver);
}
