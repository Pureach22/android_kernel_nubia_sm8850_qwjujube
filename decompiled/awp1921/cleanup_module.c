__int64 cleanup_module()
{
  return i2c_del_driver(&awp1921_i2c_driver);
}
