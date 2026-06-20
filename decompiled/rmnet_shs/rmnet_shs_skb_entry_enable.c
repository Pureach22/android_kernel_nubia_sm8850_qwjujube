__int64 rmnet_shs_skb_entry_enable()
{
  return rmnet_module_hook_register(&rmnet_shs_skb_entry_hook, 1);
}
