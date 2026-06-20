// Alternative name is 'cleanup_module'
__int64 rmnet_shs_module_exit()
{
  unregister_netdevice_notifier(&rmnet_shs_dev_notifier);
  rmnet_shs_wq_mem_deinit();
  rmnet_shs_wq_genl_deinit();
  return printk(&unk_15A49);
}
