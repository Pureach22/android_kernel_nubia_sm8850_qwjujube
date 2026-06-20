__int64 init_module()
{
  return i2c_register_driver(&_this_module, &nb7vpq904m_driver);
}
