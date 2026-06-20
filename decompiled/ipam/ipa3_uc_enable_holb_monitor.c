__int64 __fastcall ipa3_uc_enable_holb_monitor(int a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  unsigned int v5; // w19

  _ReadStatusReg(SP_EL0);
  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(
        v3,
        "ipa %s:%d Sending uc CMD ENABLE_HOLB_MONITOR with polling_period (%d)\n",
        "ipa3_uc_enable_holb_monitor",
        1336,
        a1);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(
        v4,
        "ipa %s:%d Sending uc CMD ENABLE_HOLB_MONITOR with polling_period (%d)\n",
        "ipa3_uc_enable_holb_monitor",
        1336,
        a1);
  }
  ipa3_inc_client_enable_clks();
  v5 = ipa3_uc_send_cmd_64b_param(a1, 0, 17, 0, 0, 2500);
  ipa3_dec_client_disable_clks();
  _ReadStatusReg(SP_EL0);
  return v5;
}
