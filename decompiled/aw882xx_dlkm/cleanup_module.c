__int64 cleanup_module()
{
  return i2c_del_driver(&aw882xx_i2c_driver);
}
