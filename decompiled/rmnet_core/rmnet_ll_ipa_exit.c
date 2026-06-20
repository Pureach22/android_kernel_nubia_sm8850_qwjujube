__int64 rmnet_ll_ipa_exit()
{
  if ( rmnet_ll_ipa_ep )
  {
    ipa_unregister_rmnet_ll_cb();
    rmnet_ll_ipa_ep = 0;
  }
  return 0;
}
