__int64 init_module()
{
  unsigned int v0; // w0
  unsigned int v1; // w19

  v0 = uart_register_driver(&eud_uart_driver);
  if ( v0 )
  {
    v1 = v0;
    printk(&unk_7899, "msm_eud_init");
  }
  else
  {
    v1 = _platform_driver_register(msm_eud_driver, &_this_module);
    if ( v1 )
    {
      printk(&unk_792D, "msm_eud_init");
      uart_unregister_driver(&eud_uart_driver);
    }
  }
  return v1;
}
