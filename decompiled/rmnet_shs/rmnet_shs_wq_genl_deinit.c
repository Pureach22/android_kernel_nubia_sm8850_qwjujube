__int64 rmnet_shs_wq_genl_deinit()
{
  rmnet_shs_genl_send_int_to_userspace_no_info(42);
  genl_unregister_family(&rmnet_shs_genl_family);
  rmnet_shs_userspace_connected = 0;
  genl_unregister_family(&rmnet_shs_genl_msg_family);
  return 0;
}
