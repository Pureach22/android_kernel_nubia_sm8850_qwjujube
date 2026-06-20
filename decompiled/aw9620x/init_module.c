__int64 __fastcall init_module(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x3
  unsigned int v7; // w19

  printk(&unk_141FA, "v0.3.0", a3, a4);
  v7 = i2c_register_driver(&_this_module, &aw9620x_i2c_driver);
  if ( v7 )
    printk(&unk_13A20, v4, v5, v6);
  return v7;
}
