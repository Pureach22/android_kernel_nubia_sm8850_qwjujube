__int64 cleanup_module()
{
  platform_driver_unregister(pmic_ecid_driver);
  ida_destroy(&pmic_ecid_dev_ida);
  return class_unregister(&pmic_ecid_class);
}
