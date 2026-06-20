__int64 cleanup_module()
{
  return i2c_del_driver(&aw_i2c_driver);
}
