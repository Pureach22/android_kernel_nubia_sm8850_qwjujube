__int64 init_module()
{
  return _platform_driver_register(spmi_pmic_arb_driver, &_this_module);
}
