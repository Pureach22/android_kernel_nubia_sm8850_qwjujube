__int64 ipa_mhi_wait_for_ul_empty_timeout()
{
  __int64 v0; // x19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned __int64 v3; // x25
  int v4; // w28
  int v5; // w8
  int v6; // w23
  __int64 v7; // x28
  __int64 v8; // x28
  int v9; // t1
  __int64 v10; // x0
  long double v11; // q0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  const char *v18; // x4
  __int64 v19; // x0
  const char *v20; // x4
  __int64 v21; // x0
  __int64 v22; // x0

  v0 = jiffies;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_wait_for_ul_empty_timeout", 976);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_wait_for_ul_empty_timeout", 976);
  }
  v3 = 0;
  v4 = 1;
  while ( 1 )
  {
    while ( 1 )
    {
      v6 = v4;
      if ( v3 > 1 )
        break;
      v7 = ipa_mhi_client_ctx + 200 * v3;
      v9 = *(unsigned __int8 *)(v7 + 40);
      v8 = v7 + 40;
      if ( v9 == 1 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v10 = ipa3_get_ipc_logbuf();
          ipc_log_string(v10, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_gsi_channel_empty", 944);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v12 = ipa3_get_ipc_logbuf_low();
          v11 = ipc_log_string(v12, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_gsi_channel_empty", 944);
        }
        if ( (*(_BYTE *)(v8 + 12) & 1) != 0 )
        {
          if ( (((__int64 (__fastcall *)(_QWORD, long double))ipa3_mhi_stop_gsi_channel)(*(unsigned int *)(v8 + 4), v11)
              & 1) == 0 )
          {
            v5 = 0;
            goto LABEL_8;
          }
          *(_BYTE *)(v8 + 12) = 0;
        }
        else
        {
          if ( ipa3_get_ipc_logbuf() )
          {
            v13 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v13,
              "ipa_mhi_client %s:%d Channel is not in STOP_IN_PROC\n",
              "ipa_mhi_gsi_channel_empty",
              947);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v14 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v14,
              "ipa_mhi_client %s:%d Channel is not in STOP_IN_PROC\n",
              "ipa_mhi_gsi_channel_empty",
              947);
          }
        }
        v5 = 1;
LABEL_8:
        v6 &= v5;
      }
      ++v3;
      v4 = v6;
    }
    if ( v0 + 3 - jiffies < 0 )
      break;
    v3 = 0;
    v4 = 1;
    if ( (v6 & 1) != 0 )
      goto LABEL_30;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v15 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v15,
      "ipa_mhi_client %s:%d finished waiting for UL empty\n",
      "ipa_mhi_wait_for_ul_empty_timeout",
      987);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v16 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v16,
      "ipa_mhi_client %s:%d finished waiting for UL empty\n",
      "ipa_mhi_wait_for_ul_empty_timeout",
      987);
  }
LABEL_30:
  if ( ipa3_get_ipc_logbuf() )
  {
    v17 = ipa3_get_ipc_logbuf();
    if ( (v4 & 1) != 0 )
      v18 = "empty";
    else
      v18 = "not empty";
    ipc_log_string(v17, "ipa_mhi_client %s:%d IPA UL is %s\n", "ipa_mhi_wait_for_ul_empty_timeout", 996, v18);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v19 = ipa3_get_ipc_logbuf_low();
    if ( (v4 & 1) != 0 )
      v20 = "empty";
    else
      v20 = "not empty";
    ipc_log_string(v19, "ipa_mhi_client %s:%d IPA UL is %s\n", "ipa_mhi_wait_for_ul_empty_timeout", 996, v20);
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v21 = ipa3_get_ipc_logbuf();
    ipc_log_string(v21, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_wait_for_ul_empty_timeout", 998);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v22 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v22, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_wait_for_ul_empty_timeout", 998);
  }
  return v4 & 1;
}
