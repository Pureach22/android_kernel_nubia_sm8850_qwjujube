__int64 init_module()
{
  printk(&unk_7767, "btfm_swr_init");
  return swr_driver_register(&btfm_swr_driver);
}
