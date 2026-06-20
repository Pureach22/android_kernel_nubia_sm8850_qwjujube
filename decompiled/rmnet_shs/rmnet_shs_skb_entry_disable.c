__int64 rmnet_shs_skb_entry_disable()
{
  return rmnet_module_hook_unregister_no_sync(&rmnet_shs_skb_entry_hook, 1);
}
