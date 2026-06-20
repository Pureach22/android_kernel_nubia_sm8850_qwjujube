__int64 init_module()
{
  return i2c_register_driver(&_this_module, &wcd_usbss_i2c_driver);
}
