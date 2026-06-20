__int64 __fastcall rndis_ipa_debugfs_aggr_write(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w0
  __int64 v6; // x1
  int v7; // w19

  if ( !a1 )
    return -14;
  v5 = ipa3_cfg_ep(*(unsigned int *)(*(_QWORD *)(a1 + 32) + 48LL), (__int64)&ipa_to_usb_ep_cfg);
  if ( v5 )
  {
    v7 = v5;
    printk(&unk_3E0285, v6);
    return v7;
  }
  else
  {
    printk(&unk_400245, v6);
    return a3;
  }
}
