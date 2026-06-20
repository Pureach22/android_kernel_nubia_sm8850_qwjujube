__int64 cleanup_module()
{
  return i2c_del_driver(&aw22xxx_i2c_driver);
}
