__int64 rmnet_ctl_ipa_ready()
{
  __int64 result; // x0

  result = ipa_register_rmnet_ctl_cb(
             rmnet_ctl_probe,
             &ctl_ipa_dev,
             rmnet_ctl_remove,
             &ctl_ipa_dev,
             rmnet_ctl_dl_callback,
             &ctl_ipa_dev);
  if ( (_DWORD)result )
    return printk(&unk_69F2, "rmnet_ctl_ipa_ready", (unsigned int)result);
  rmnet_ctl_ipa_registered = 1;
  return result;
}
