__int64 cleanup_module()
{
  return i2c_del_driver(&wcd_usbss_i2c_driver);
}
