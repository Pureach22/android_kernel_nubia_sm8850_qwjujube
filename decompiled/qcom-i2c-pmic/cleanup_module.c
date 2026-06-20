__int64 cleanup_module()
{
  return i2c_del_driver(&i2c_pmic_driver);
}
