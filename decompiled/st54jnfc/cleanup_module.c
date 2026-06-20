__int64 __fastcall cleanup_module(__int64 a1, __int64 a2)
{
  printk(&unk_8B2F, a2);
  return i2c_del_driver(&st21nfc_driver);
}
