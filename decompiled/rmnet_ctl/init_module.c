__int64 init_module()
{
  unsigned int ready; // w0

  ready = ipa_register_ipa_ready_cb(rmnet_ctl_ipa_ready, 0);
  if ( ready )
  {
    if ( ready == -17 )
      rmnet_ctl_ipa_ready();
    else
      printk(&unk_69F2, "rmnet_ctl_init", ready);
  }
  return 0;
}
