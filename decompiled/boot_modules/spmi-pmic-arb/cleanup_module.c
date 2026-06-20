__int64 cleanup_module()
{
  return platform_driver_unregister(spmi_pmic_arb_driver);
}
