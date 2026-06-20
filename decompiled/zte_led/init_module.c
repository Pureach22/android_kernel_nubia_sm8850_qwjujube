__int64 init_module()
{
  __int64 v0; // x1
  __int64 v1; // x1
  unsigned int v2; // w19

  printk(&unk_12D81, "v1.1.3");
  msleep(500);
  printk(&unk_128DA, v0);
  v2 = i2c_register_driver(&_this_module, &aw22xxx_i2c_driver);
  if ( v2 )
    printk(&unk_13C3A, v1);
  return v2;
}
