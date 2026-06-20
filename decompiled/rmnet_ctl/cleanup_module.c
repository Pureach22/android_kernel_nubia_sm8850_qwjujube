__int64 cleanup_module()
{
  __int64 result; // x0

  if ( rmnet_ctl_ipa_registered == 1 )
  {
    result = ipa_unregister_rmnet_ctl_cb();
    rmnet_ctl_ipa_registered = 0;
  }
  return result;
}
