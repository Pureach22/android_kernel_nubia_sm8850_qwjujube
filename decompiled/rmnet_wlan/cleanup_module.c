__int64 cleanup_module()
{
  printk(&unk_DC81, "rmnet_wlan_genl_exit");
  if ( (unsigned int)rmnet_wlan_connection_deinit() )
    printk(&unk_DE16, "rmnet_wlan_genl_exit");
  rmnet_wlan_deinit();
  if ( (unsigned int)genl_unregister_family(&rmnet_wlan_genl_family) )
    printk(&unk_DB2D, "rmnet_wlan_genl_exit");
  rmnet_wlan_unset_hooks();
  return printk(&unk_DD55, "rmnet_wlan_genl_exit");
}
