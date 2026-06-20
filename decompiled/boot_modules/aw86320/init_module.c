__int64 __fastcall init_module(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 v10; // x6
  unsigned int v11; // w19

  printk(&unk_A158, "aw86320", "aw_i2c_init", "V0.0.1", a5, a6, a7);
  v11 = i2c_register_driver(&_this_module, &aw_i2c_driver);
  if ( v11 )
    printk(&unk_A360, "aw86320", "aw_i2c_init", v7, v8, v9, v10);
  return v11;
}
