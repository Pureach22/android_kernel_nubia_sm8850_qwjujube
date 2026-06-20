__int64 cleanup_module()
{
  return i2c_del_driver(&aw9620x_i2c_driver);
}
