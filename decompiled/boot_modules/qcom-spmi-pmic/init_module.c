__int64 init_module()
{
  return _spmi_driver_register(&pmic_spmi_driver, &_this_module);
}
