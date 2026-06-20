__int64 __fastcall ipa3_uc_del_holb_monitor(unsigned __int16 a1, unsigned __int8 a2)
{
  int v3; // w20
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w19

  v3 = a1;
  _ReadStatusReg(SP_EL0);
  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(
        v5,
        "ipa %s:%d Sending uc IPA_CPU_2_HW_CMD_DEL_HOLB_MONITOR for gsi_ch %d\n",
        "ipa3_uc_del_holb_monitor",
        1389,
        v3);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(
        v6,
        "ipa %s:%d Sending uc IPA_CPU_2_HW_CMD_DEL_HOLB_MONITOR for gsi_ch %d\n",
        "ipa3_uc_del_holb_monitor",
        1389,
        v3);
  }
  ipa3_inc_client_enable_clks();
  v7 = ipa3_uc_send_cmd_64b_param((unsigned __int8)v3 | (a2 << 8), 0, 19, 0, 0, 2500);
  ipa3_dec_client_disable_clks();
  _ReadStatusReg(SP_EL0);
  return v7;
}
