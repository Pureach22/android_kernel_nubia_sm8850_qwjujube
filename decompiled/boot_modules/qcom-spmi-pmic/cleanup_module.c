__int64 cleanup_module()
{
  return driver_unregister(&pmic_spmi_driver);
}
