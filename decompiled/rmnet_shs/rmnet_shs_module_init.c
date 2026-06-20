// Alternative name is 'init_module'
__int64 rmnet_shs_module_init()
{
  printk(&unk_15A27);
  rmnet_shs_wq_genl_init();
  rmnet_shs_wq_mem_init();
  return register_netdevice_notifier(&rmnet_shs_dev_notifier);
}
