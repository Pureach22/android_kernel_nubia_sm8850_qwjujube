__int64 __fastcall ipa3_wigig_init_debugfs_i(__int64 a1)
{
  unsigned __int64 dir; // x0
  unsigned __int64 v2; // x19
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0

  dir = debugfs_create_dir("ipa_wigig", a1);
  if ( dir && (v2 = dir, dir < 0xFFFFFFFFFFFFF001LL) )
  {
    wigig_dent = dir;
    debugfs_create_u8("modc", 436, dir, &int_modc);
    debugfs_create_u16("modt", 436, v2, &int_modt);
    debugfs_create_u8("rx_mod_th", 436, v2, &rx_hwtail_mod_threshold);
    debugfs_create_u8("tx_mod_th", 436, v2, &tx_hwtail_mod_threshold);
    return 0;
  }
  else
  {
    printk(&unk_3FE0E1, "ipa3_wigig_init_debugfs_i");
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d fail to create folder in debug_fs\n", "ipa3_wigig_init_debugfs_i", 1980);
        v4 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v4 + 34160);
      if ( v6 )
        ipc_log_string(v6, "ipa %s:%d fail to create folder in debug_fs\n", "ipa3_wigig_init_debugfs_i", 1980);
    }
    return 4294967282LL;
  }
}
