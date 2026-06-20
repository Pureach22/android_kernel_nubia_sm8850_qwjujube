__int64 cleanup_module()
{
  printk(&unk_9DD2, "qbt_handler_exit");
  return platform_driver_unregister(qbt_plat_driver);
}
