__int64 init_module()
{
  __int64 v0; // x1
  unsigned int v1; // w19
  __int64 v2; // x0
  void *v4; // x0

  printk(&unk_91ED, "1.4");
  v1 = rmnet_aps_genl_init();
  if ( v1 )
  {
    v4 = &unk_90EE;
LABEL_8:
    printk(v4, v0);
    return v1;
  }
  register_netdevice_notifier(&rmnet_aps_notifier);
  rmnet_module_hook_register(&rmnet_aps_module_hooks, 2);
  rmnet_module_hook_register(&aps_data_report_hooks, 1);
  mutex_lock(&rmnet_aps_mutex);
  rmnet_aps_active = 1;
  mutex_unlock(&rmnet_aps_mutex);
  v2 = proc_mkdir("aps", 0);
  aps_proc_dir = v2;
  if ( !v2 )
  {
    v4 = &unk_904F;
    goto LABEL_8;
  }
  aps_activity_file = proc_create_single_data("dl_activity", 292, v2, aps_activity_show, 0);
  if ( !aps_activity_file )
  {
    v4 = &unk_914A;
    goto LABEL_8;
  }
  return v1;
}
