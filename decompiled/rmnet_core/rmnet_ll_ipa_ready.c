__int64 rmnet_ll_ipa_ready()
{
  _DWORD *ipa_ready_status; // x19
  __int64 result; // x0
  int v2; // w8
  int v3; // w20

  ipa_ready_status = rmnet_ll_get_ipa_ready_status();
  result = ipa_register_rmnet_ll_cb(
             rmnet_ll_ipa_probe,
             &rmnet_ll_ipa_ep,
             rmnet_ll_ipa_remove,
             &rmnet_ll_ipa_ep,
             rmnet_ll_ipa_rx,
             &rmnet_ll_ipa_ep);
  if ( (_DWORD)result )
  {
    v3 = result;
    result = printk(&unk_2D26A, "rmnet_ll_ipa_ready");
    if ( v3 == -6 )
      v2 = -6;
    else
      v2 = -1;
  }
  else
  {
    v2 = 0;
  }
  *ipa_ready_status = v2;
  return result;
}
