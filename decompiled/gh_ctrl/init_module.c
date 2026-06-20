__int64 init_module()
{
  _ReadStatusReg(SP_EL0);
  __asm { HVC             #0x6000 }
  gunyah_api_0 = 0;
  gunyah_api_1 = 0;
  printk(&unk_6B6F);
  _ReadStatusReg(SP_EL0);
  return 0;
}
