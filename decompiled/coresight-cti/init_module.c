__int64 init_module()
{
  unsigned int v0; // w19

  v0 = _amba_driver_register(&cti_driver, &_this_module);
  if ( v0 )
    printk(&unk_C465);
  coresight_set_cti_ops(cti_assoc_ops);
  return v0;
}
