__int64 cleanup_module()
{
  unregister_netdevice_notifier(&rmnet_dev_notifier);
  rtnl_link_unregister(&rmnet_link_ops);
  rmnet_ll_exit();
  rmnet_core_genl_deinit();
  ipa_unregister_notifier(rmnet_ipa_notify_cb);
  qmi_reset_pm_notifier_state(0);
  return module_put(&_this_module);
}
