__int64 __fastcall ipa3_uc_add_holb_monitor(unsigned __int16 a1, int a2, int a3, unsigned __int8 a4)
{
  int v7; // w22
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w19

  v7 = a1;
  _ReadStatusReg(SP_EL0);
  v8 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d Sending uc CMD ADD_HOLB_MONITOR", "ipa3_uc_add_holb_monitor", 1362);
      v8 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v8 + 34160);
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d Sending uc CMD ADD_HOLB_MONITOR", "ipa3_uc_add_holb_monitor", 1362);
      v8 = ipa3_ctx;
    }
    if ( v8 )
    {
      v11 = *(_QWORD *)(v8 + 34152);
      if ( v11 )
      {
        ipc_log_string(
          v11,
          "ipa %s:%d CMD params gsi_chid (%d), mask (%d), max_stuck_cnt (%d)\n",
          "ipa3_uc_add_holb_monitor",
          1364,
          v7,
          a2,
          a3);
        v8 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v8 + 34160);
      if ( v12 )
        ipc_log_string(
          v12,
          "ipa %s:%d CMD params gsi_chid (%d), mask (%d), max_stuck_cnt (%d)\n",
          "ipa3_uc_add_holb_monitor",
          1364,
          v7,
          a2,
          a3);
    }
  }
  ipa3_inc_client_enable_clks();
  v13 = ipa3_uc_send_cmd_64b_param(
          (unsigned __int8)v7 | (unsigned __int16)(a4 << 8) | ((unsigned __int8)a2 << 16) | (unsigned int)(a3 << 24),
          0,
          18,
          0,
          0,
          2500);
  ipa3_dec_client_disable_clks();
  _ReadStatusReg(SP_EL0);
  return v13;
}
