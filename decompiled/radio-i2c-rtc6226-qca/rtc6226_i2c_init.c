__int64 rtc6226_i2c_init()
{
  return i2c_register_driver(&_this_module, &rtc6226_i2c_driver);
}
