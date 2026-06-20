__int64 init_module()
{
  unsigned int v0; // w19

  dword_14 = 1LL << -(char)__clz((unsigned int)_sw_hweight64(_cpu_possible_mask) - 1LL);
  v0 = stm_source_register_device(0);
  if ( v0 )
    printk(&unk_6220);
  return v0;
}
