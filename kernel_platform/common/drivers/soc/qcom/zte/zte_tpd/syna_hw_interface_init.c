__int64 __fastcall syna_hw_interface_init(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x2
  unsigned int v5; // w19
  void *v6; // x0
  struct platform_device *pdev;

  printk(unk_348D8, "syna_hw_interface_init", a3);
  pdev = platform_device_register_simple("syna_dev_platform", -1, NULL, 0);
  if ( IS_ERR(pdev) )
  {
    v5 = PTR_ERR(pdev);
    v6 = unk_336E1;
  }
  else
  {
    p_device = (__int64)pdev;
    v5 = _spi_register_driver(THIS_MODULE, &syna_spi_driver);
    if ( (v5 & 0x80000000) == 0 )
    {
      printk(unk_3C561, "syna_hw_interface_init", v4);
      buf_size = 0;
      rx_buf = 0;
      tx_buf = 0;
      return v5;
    }
    v6 = unk_32A1D;
  }
  printk(v6, "syna_hw_interface_init", v4);
  return v5;
}
