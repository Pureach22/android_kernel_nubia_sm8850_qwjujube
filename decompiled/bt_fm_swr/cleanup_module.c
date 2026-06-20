__int64 cleanup_module()
{
  printk(&unk_7767, "btfm_swr_exit");
  return swr_driver_unregister(&btfm_swr_driver);
}
