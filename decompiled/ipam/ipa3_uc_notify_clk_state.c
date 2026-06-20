__int64 __fastcall ipa3_uc_notify_clk_state(char a1)
{
  __int64 result; // x0
  int v3; // w0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  const char *v7; // x4
  __int64 v8; // x0
  const char *v9; // x4
  int v10; // w2

  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0xFu )
  {
    if ( ipa3_ctx )
    {
      result = *(_QWORD *)(ipa3_ctx + 34160);
      if ( !result )
        return result;
      ipc_log_string(result, "ipa %s:%d not supported past IPA v4.0\n", "ipa3_uc_notify_clk_state", 1433);
    }
    return 0;
  }
  v3 = ipa3_uc_state_check();
  v4 = ipa3_ctx;
  if ( v3 )
  {
    if ( !ipa3_ctx )
      return 0;
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(
        v5,
        "ipa %s:%d uC interface will not notify the UC on clock state\n",
        "ipa3_uc_notify_clk_state",
        1442);
      v4 = ipa3_ctx;
    }
    result = *(_QWORD *)(v4 + 34160);
    if ( result )
    {
      ipc_log_string(
        result,
        "ipa %s:%d uC interface will not notify the UC on clock state\n",
        "ipa3_uc_notify_clk_state",
        1442);
      return 0;
    }
  }
  else
  {
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        if ( (a1 & 1) != 0 )
          v7 = "UNGATE";
        else
          v7 = "GATE";
        ipc_log_string(v6, "ipa %s:%d uC clock %s notification\n", "ipa3_uc_notify_clk_state", 1446, v7);
        v4 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v4 + 34160);
      if ( v8 )
      {
        if ( (a1 & 1) != 0 )
          v9 = "UNGATE";
        else
          v9 = "GATE";
        ipc_log_string(v8, "ipa %s:%d uC clock %s notification\n", "ipa3_uc_notify_clk_state", 1446, v9);
      }
    }
    if ( (a1 & 1) != 0 )
      v10 = 6;
    else
      v10 = 5;
    return ipa3_uc_send_cmd_64b_param(0, 0, v10, 0, 1, 0);
  }
  return result;
}
