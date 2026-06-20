__int64 __fastcall md_unregister_memory_dump(__int64 a1)
{
  _ReadStatusReg(SP_EL0);
  md_get_region();
  printk(&unk_112FAE, a1);
  _ReadStatusReg(SP_EL0);
  return 0;
}
