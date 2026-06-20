__int64 ipa_odl_ctl_fops_open()
{
  __int16 v0; // w9
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0

  v0 = *(_WORD *)(ipa3_odl_ctx + 692);
  if ( (v0 & 1) != 0 )
  {
    *(_WORD *)(ipa3_odl_ctx + 692) = v0 | 2;
    return 0;
  }
  else
  {
    printk(&unk_3CCD63, "ipa_odl_ctl_fops_open");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d Before odl init trying to open odl ctl pipe\n", "ipa_odl_ctl_fops_open", 46);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d Before odl init trying to open odl ctl pipe\n", "ipa_odl_ctl_fops_open", 46);
    }
    print_ipa_odl_state_bit_mask();
    return 4294967277LL;
  }
}
