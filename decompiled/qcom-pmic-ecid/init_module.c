__int64 init_module()
{
  unsigned int v0; // w0
  unsigned int v1; // w19

  v0 = class_register(&pmic_ecid_class);
  if ( v0 )
  {
    v1 = v0;
    printk(&unk_672B, v0);
  }
  else
  {
    return (unsigned int)_platform_driver_register(pmic_ecid_driver, &_this_module);
  }
  return v1;
}
