__int64 init_module()
{
  printk(&unk_844A, "2.2.0.19");
  return i2c_register_driver(&_this_module, &st21nfc_driver);
}
