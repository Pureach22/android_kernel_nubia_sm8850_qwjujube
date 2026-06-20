__int64 ipa3_q6_post_shutdown_cleanup()
{
  __int64 v0; // x0
  __int64 v1; // x0
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 ep_mapping; // x0
  unsigned int i; // w19
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0

  if ( ipa3_ctx )
  {
    v0 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v0 )
      ipc_log_string(v0, "ipa %s:%d ENTER\n", "ipa3_q6_post_shutdown_cleanup", 5536);
  }
  ipa3_inc_client_enable_clks_no_log();
  ipa3_q6_avoid_holb();
  if ( *(_DWORD *)(ipa3_ctx + 32240) < 0xEu )
  {
    ep_mapping = ipa3_halt_q6_gsi_channels(0);
    if ( *(_BYTE *)(ipa3_ctx + 34657) == 1 )
    {
      for ( i = 0; i != 134; ++i )
      {
        if ( i == 84 || i == 114 || i == 74 || i == 122 || (i & 0xFD) == 0x38 || i == 52 || (i & 0xFB) == 0x32 )
        {
          ep_mapping = ipa_get_ep_mapping(i);
          if ( (_DWORD)ep_mapping != -1 )
          {
            ep_mapping = ipa3_uc_is_gsi_channel_empty(i);
            if ( (_DWORD)ep_mapping )
            {
              ep_mapping = printk(&unk_3D7A56, "ipa3_q6_post_shutdown_cleanup");
              v7 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v8 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v8 )
                {
                  ipc_log_string(
                    v8,
                    "ipa %s:%d fail to validate Q6 ch emptiness %d\n",
                    "ipa3_q6_post_shutdown_cleanup",
                    5567,
                    i);
                  v7 = ipa3_ctx;
                }
                ep_mapping = *(_QWORD *)(v7 + 34160);
                if ( ep_mapping )
                  ep_mapping = ipc_log_string(
                                 ep_mapping,
                                 "ipa %s:%d fail to validate Q6 ch emptiness %d\n",
                                 "ipa3_q6_post_shutdown_cleanup",
                                 5567,
                                 i);
              }
            }
          }
        }
      }
      result = _ipa3_dec_client_disable_clks(ep_mapping);
      if ( ipa3_ctx )
      {
        result = *(_QWORD *)(ipa3_ctx + 34160);
        if ( result )
          return ipc_log_string(result, "ipa %s:%d Exit with success\n", "ipa3_q6_post_shutdown_cleanup", 5576);
      }
    }
    else
    {
      result = printk(&unk_3D1DC0, "ipa3_q6_post_shutdown_cleanup");
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(v10, "ipa %s:%d uC is not loaded. Skipping\n", "ipa3_q6_post_shutdown_cleanup", 5555);
          v9 = ipa3_ctx;
        }
        result = *(_QWORD *)(v9 + 34160);
        if ( result )
          return ipc_log_string(result, "ipa %s:%d uC is not loaded. Skipping\n", "ipa3_q6_post_shutdown_cleanup", 5555);
      }
    }
  }
  else
  {
    v1 = ipa3_halt_q6_gsi_channels(1);
    result = _ipa3_dec_client_disable_clks(v1);
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d Exit without consumer check\n", "ipa3_q6_post_shutdown_cleanup", 5548);
        v3 = ipa3_ctx;
      }
      result = *(_QWORD *)(v3 + 34160);
      if ( result )
        return ipc_log_string(result, "ipa %s:%d Exit without consumer check\n", "ipa3_q6_post_shutdown_cleanup", 5548);
    }
  }
  return result;
}
