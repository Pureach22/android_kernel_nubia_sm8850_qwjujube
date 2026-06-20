__int64 __fastcall ipa_get_client_cb_type(int a1)
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0

  if ( (a1 & 0xFFFFFFFE) == 0x2A )
  {
    v4 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 1;
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d MHI Client registered\n", "ipa_get_client_cb_type", 517);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d MHI Client registered\n", "ipa_get_client_cb_type", 517);
      return 1;
    }
    else
    {
      return 1;
    }
  }
  else if ( (a1 & 0xFFFFFFFE) == 0x12 )
  {
    v1 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v2 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v2 )
      {
        ipc_log_string(v2, "ipa %s:%d USB Client registered\n", "ipa_get_client_cb_type", 513);
        v1 = ipa3_ctx;
      }
      result = *(_QWORD *)(v1 + 34160);
      if ( result )
      {
        ipc_log_string(result, "ipa %s:%d USB Client registered\n", "ipa_get_client_cb_type", 513);
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    printk(&unk_3BD94D, "ipa_get_client_cb_type");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d Invalid IPA client\n", "ipa_get_client_cb_type", 520);
        v7 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v7 + 34160);
      if ( v9 )
        ipc_log_string(v9, "ipa %s:%d Invalid IPA client\n", "ipa_get_client_cb_type", 520);
    }
    return 2;
  }
  return result;
}
