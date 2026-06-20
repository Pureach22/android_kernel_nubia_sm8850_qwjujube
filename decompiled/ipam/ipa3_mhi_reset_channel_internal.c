__int64 __fastcall ipa3_mhi_reset_channel_internal(__int64 a1)
{
  unsigned int v1; // w19
  __int64 ipc_logbuf; // x0
  __int64 v3; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 ep_mapping; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v16; // w0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 result; // x0
  __int64 v21; // x0
  int v22; // w19
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  unsigned int v31; // w19
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0

  v1 = a1;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v3 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(v3, "ipa_mhi %s:%d ENTRY\n", "ipa3_mhi_reset_channel_internal", 132);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_logbuf_low = ipc_log_string(v5, "ipa_mhi %s:%d ENTRY\n", "ipa3_mhi_reset_channel_internal", 132);
  }
  v6 = ipa3_get_ipc_logbuf(ipc_logbuf_low);
  if ( v6 )
  {
    v7 = ipa3_get_ipc_logbuf(v6);
    v6 = ipc_log_string(v7, "ipa_mhi %s:%d ENTRY\n", "ipa3_mhi_reset_gsi_channel", 112);
  }
  v8 = ipa3_get_ipc_logbuf_low(v6);
  if ( v8 )
  {
    v9 = ipa3_get_ipc_logbuf_low(v8);
    ipc_log_string(v9, "ipa_mhi %s:%d ENTRY\n", "ipa3_mhi_reset_gsi_channel", 112);
  }
  ep_mapping = ipa_get_ep_mapping(v1);
  if ( (ep_mapping & 0x80000000) == 0 )
  {
    v11 = ipa3_reset_gsi_channel((_QWORD *)ep_mapping);
    if ( !(_DWORD)v11 )
    {
      v12 = ipa3_get_ipc_logbuf(v11);
      if ( v12 )
      {
        v13 = ipa3_get_ipc_logbuf(v12);
        v12 = ipc_log_string(v13, "ipa_mhi %s:%d EXIT\n", "ipa3_mhi_reset_gsi_channel", 124);
      }
      v14 = ipa3_get_ipc_logbuf_low(v12);
      if ( v14 )
      {
        v15 = ipa3_get_ipc_logbuf_low(v14);
        ipc_log_string(v15, "ipa_mhi %s:%d EXIT\n", "ipa3_mhi_reset_gsi_channel", 124);
      }
      v16 = ipa_get_ep_mapping(v1);
      v17 = ipa3_disable_data_path(v16);
      if ( (_DWORD)v17 )
      {
        v31 = v17;
        v32 = printk(&unk_3CFD86, "ipa3_mhi_reset_channel_internal");
        v33 = ipa3_get_ipc_logbuf(v32);
        if ( v33 )
        {
          v34 = ipa3_get_ipc_logbuf(v33);
          v33 = ipc_log_string(
                  v34,
                  "ipa_mhi %s:%d ipa3_disable_data_path failed %d\n",
                  "ipa3_mhi_reset_channel_internal",
                  143,
                  v31);
        }
        v35 = ipa3_get_ipc_logbuf_low(v33);
        if ( v35 )
        {
          v36 = ipa3_get_ipc_logbuf_low(v35);
          ipc_log_string(
            v36,
            "ipa_mhi %s:%d ipa3_disable_data_path failed %d\n",
            "ipa3_mhi_reset_channel_internal",
            143,
            v31);
        }
        return v31;
      }
      else
      {
        v18 = ipa3_get_ipc_logbuf(v17);
        if ( v18 )
        {
          v19 = ipa3_get_ipc_logbuf(v18);
          v18 = ipc_log_string(v19, "ipa_mhi %s:%d EXIT\n", "ipa3_mhi_reset_channel_internal", 146);
        }
        result = ipa3_get_ipc_logbuf_low(v18);
        if ( result )
        {
          v21 = ipa3_get_ipc_logbuf_low(result);
          ipc_log_string(v21, "ipa_mhi %s:%d EXIT\n", "ipa3_mhi_reset_channel_internal", 146);
          return 0;
        }
      }
      return result;
    }
    v22 = v11;
    v23 = printk(&unk_3FB671, "ipa3_mhi_reset_gsi_channel");
    v24 = ipa3_get_ipc_logbuf(v23);
    if ( v24 )
    {
      v25 = ipa3_get_ipc_logbuf(v24);
      v24 = ipc_log_string(
              v25,
              "ipa_mhi %s:%d ipa3_reset_gsi_channel failed %d\n",
              "ipa3_mhi_reset_gsi_channel",
              120,
              v22);
    }
    v26 = ipa3_get_ipc_logbuf_low(v24);
    if ( v26 )
    {
      v27 = ipa3_get_ipc_logbuf_low(v26);
      ipc_log_string(v27, "ipa_mhi %s:%d ipa3_reset_gsi_channel failed %d\n", "ipa3_mhi_reset_gsi_channel", 120, v22);
    }
  }
  v28 = printk(&unk_3CCB29, "ipa3_mhi_reset_channel_internal");
  v29 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v30 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v30 )
    {
      ipc_log_string(v30, "ipa %s:%d ipa3_mhi_reset_gsi_channel failed\n", "ipa3_mhi_reset_channel_internal", 136);
      v29 = ipa3_ctx;
    }
    v28 = *(_QWORD *)(v29 + 34160);
    if ( v28 )
      v28 = ipc_log_string(v28, "ipa %s:%d ipa3_mhi_reset_gsi_channel failed\n", "ipa3_mhi_reset_channel_internal", 136);
  }
  ((void (__fastcall *)(__int64))ipa_assert)(v28);
  return 4294967282LL;
}
