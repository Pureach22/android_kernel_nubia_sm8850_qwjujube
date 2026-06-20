__int64 __fastcall init_module(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x1
  __int64 v4; // x2
  unsigned int v5; // w19

  printk(&unk_809D, "v0.1", a3);
  v5 = i2c_register_driver(&_this_module, &awp1921_i2c_driver);
  if ( v5 )
    printk(&unk_8770, v3, v4);
  return v5;
}
