__int64 __fastcall ipa3_uc_is_gsi_channel_empty(unsigned int a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 result; // x0
  int v7; // w19
  int v8; // w21
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0

  v2 = ((__int64 (*)(void))ipa_get_gsi_ep_info)();
  if ( v2 )
  {
    v3 = v2;
    if ( (unsigned int)ipa3_uc_state_check() )
    {
      v4 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 0;
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(
          v5,
          "ipa %s:%d uC cannot be used to validate ch emptiness clnt=%d\n",
          "ipa3_uc_is_gsi_channel_empty",
          1307,
          a1);
        v4 = ipa3_ctx;
      }
      result = *(_QWORD *)(v4 + 34160);
      if ( result )
      {
        ipc_log_string(
          result,
          "ipa %s:%d uC cannot be used to validate ch emptiness clnt=%d\n",
          "ipa3_uc_is_gsi_channel_empty",
          1307,
          a1);
        return 0;
      }
    }
    else
    {
      v7 = *(unsigned __int8 *)(v3 + 16);
      v8 = *(_DWORD *)(v3 + 4);
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(
            v10,
            "ipa %s:%d uC emptiness check for IPA GSI Channel %d\n",
            "ipa3_uc_is_gsi_channel_empty",
            1315,
            v8);
          v9 = ipa3_ctx;
        }
        v11 = *(_QWORD *)(v9 + 34160);
        if ( v11 )
          ipc_log_string(
            v11,
            "ipa %s:%d uC emptiness check for IPA GSI Channel %d\n",
            "ipa3_uc_is_gsi_channel_empty",
            1315,
            *(_DWORD *)(v3 + 4));
      }
      return ipa3_uc_send_cmd_64b_param(v7 & 0xFFFF00FF | ((unsigned __int8)v8 << 8), 0, 10, 0, 0, 2500);
    }
  }
  else
  {
    printk(&unk_3CC819, "ipa3_uc_is_gsi_channel_empty");
    v12 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 0;
    v13 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v13 )
    {
      ipc_log_string(
        v13,
        "ipa %s:%d Failed getting GSI EP info for client=%d\n",
        "ipa3_uc_is_gsi_channel_empty",
        1301,
        a1);
      v12 = ipa3_ctx;
    }
    result = *(_QWORD *)(v12 + 34160);
    if ( result )
    {
      ipc_log_string(
        result,
        "ipa %s:%d Failed getting GSI EP info for client=%d\n",
        "ipa3_uc_is_gsi_channel_empty",
        1301,
        a1);
      return 0;
    }
  }
  return result;
}
