__int64 rmnet_ll_ipa_init()
{
  __int64 result; // x0
  _DWORD *ipa_ready_status; // x19
  int v2; // w0
  int v3; // w8
  int v4; // w20

  tx_pending_list = (__int64)&tx_pending_list;
  qword_2FE18 = (__int64)&tx_pending_list;
  dword_2FE20 = 0;
  result = ipa_register_ipa_ready_cb(rmnet_ll_ipa_ready, 0);
  if ( (_DWORD)result == -17 )
  {
    ipa_ready_status = rmnet_ll_get_ipa_ready_status();
    v2 = ipa_register_rmnet_ll_cb(
           rmnet_ll_ipa_probe,
           &rmnet_ll_ipa_ep,
           rmnet_ll_ipa_remove,
           &rmnet_ll_ipa_ep,
           rmnet_ll_ipa_rx,
           &rmnet_ll_ipa_ep);
    if ( v2 )
    {
      v4 = v2;
      printk(&unk_2D26A, "rmnet_ll_ipa_ready");
      if ( v4 == -6 )
        v3 = -6;
      else
        v3 = -1;
    }
    else
    {
      v3 = 0;
    }
    result = 0;
    *ipa_ready_status = v3;
  }
  return result;
}
