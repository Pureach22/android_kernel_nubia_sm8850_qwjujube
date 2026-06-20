__int64 __fastcall ipa3_mhi_start_channel_internal(__int64 a1)
{
  unsigned int v1; // w19
  __int64 ipc_logbuf; // x0
  __int64 v3; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  unsigned int ep_mapping; // w0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int v17; // w19
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0

  v1 = a1;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v3 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(v3, "ipa_mhi %s:%d ENTRY\n", "ipa3_mhi_start_channel_internal", 157);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v5, "ipa_mhi %s:%d ENTRY\n", "ipa3_mhi_start_channel_internal", 157);
  }
  ep_mapping = ipa_get_ep_mapping(v1);
  if ( (ep_mapping & 0x80000000) != 0 )
  {
    v12 = printk(&unk_3F550C, "ipa3_mhi_start_channel_internal");
    v13 = ipa3_get_ipc_logbuf(v12);
    if ( v13 )
    {
      v14 = ipa3_get_ipc_logbuf(v13);
      v13 = ipc_log_string(v14, "ipa_mhi %s:%d Invalid client %d\n", "ipa3_mhi_start_channel_internal", 161, v1);
    }
    v15 = ipa3_get_ipc_logbuf_low(v13);
    if ( v15 )
    {
      v16 = ipa3_get_ipc_logbuf_low(v15);
      ipc_log_string(v16, "ipa_mhi %s:%d Invalid client %d\n", "ipa3_mhi_start_channel_internal", 161, v1);
    }
    return 4294967274LL;
  }
  else
  {
    v7 = ipa3_enable_data_path(ep_mapping);
    if ( (_DWORD)v7 )
    {
      v17 = v7;
      v18 = printk(&unk_3C7096, "ipa3_mhi_start_channel_internal");
      v19 = ipa3_get_ipc_logbuf(v18);
      if ( v19 )
      {
        v20 = ipa3_get_ipc_logbuf(v19);
        v19 = ipc_log_string(
                v20,
                "ipa_mhi %s:%d ipa3_enable_data_path failed %d\n",
                "ipa3_mhi_start_channel_internal",
                166,
                v17);
      }
      v21 = ipa3_get_ipc_logbuf_low(v19);
      if ( v21 )
      {
        v22 = ipa3_get_ipc_logbuf_low(v21);
        ipc_log_string(
          v22,
          "ipa_mhi %s:%d ipa3_enable_data_path failed %d\n",
          "ipa3_mhi_start_channel_internal",
          166,
          v17);
      }
      return v17;
    }
    else
    {
      v8 = ipa3_get_ipc_logbuf(v7);
      if ( v8 )
      {
        v9 = ipa3_get_ipc_logbuf(v8);
        v8 = ipc_log_string(v9, "ipa_mhi %s:%d EXIT\n", "ipa3_mhi_start_channel_internal", 169);
      }
      result = ipa3_get_ipc_logbuf_low(v8);
      if ( result )
      {
        v11 = ipa3_get_ipc_logbuf_low(result);
        ipc_log_string(v11, "ipa_mhi %s:%d EXIT\n", "ipa3_mhi_start_channel_internal", 169);
        return 0;
      }
    }
  }
  return result;
}
