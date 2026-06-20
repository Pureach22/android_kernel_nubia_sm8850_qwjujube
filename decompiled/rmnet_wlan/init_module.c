__int64 init_module()
{
  unsigned int v0; // w0
  unsigned int v1; // w0
  unsigned int v2; // w19

  printk(&unk_DA90, "rmnet_wlan_genl_init");
  v0 = genl_register_family(&rmnet_wlan_genl_family);
  if ( v0 )
  {
    v2 = v0;
    printk(&unk_DE90, "rmnet_wlan_genl_init");
    return v2;
  }
  v1 = rmnet_wlan_connection_init();
  if ( v1 )
  {
    v2 = v1;
    printk(&unk_DD1D, "rmnet_wlan_genl_init");
LABEL_8:
    genl_unregister_family(&rmnet_wlan_genl_family);
    return v2;
  }
  v2 = rmnet_wlan_fragment_init();
  if ( v2 )
  {
    printk(&unk_DBB0, "rmnet_wlan_genl_init");
    rmnet_wlan_connection_deinit();
    goto LABEL_8;
  }
  rmnet_wlan_set_hooks();
  printk(&unk_DD7B, "rmnet_wlan_genl_init");
  return v2;
}
