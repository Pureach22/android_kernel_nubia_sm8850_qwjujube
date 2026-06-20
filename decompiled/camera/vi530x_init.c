__int64 vi530x_init()
{
  return i2c_register_driver(&_this_module, &vi530x_driver);
}
