__int64 init_module()
{
  __int64 v0; // x2
  unsigned int v1; // w19

  printk(&unk_26ECC, "aw882xx_i2c_init", "v2.0.1");
  v1 = i2c_register_driver(&_this_module, &aw882xx_i2c_driver);
  if ( v1 )
    printk(&unk_255DC, "aw882xx_i2c_init", v0);
  return v1;
}
