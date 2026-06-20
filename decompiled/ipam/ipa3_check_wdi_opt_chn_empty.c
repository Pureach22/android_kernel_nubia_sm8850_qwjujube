__int64 __fastcall ipa3_check_wdi_opt_chn_empty(unsigned int a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  if ( a1 >= 0x24 )
    __break(0x5512u);
  v2 = *(int *)(ipa3_ctx + 480LL * a1 + 176);
  gsi_is_teth_channel_empty(v2, v11);
  if ( (v11[0] & 1) != 0 )
    goto LABEL_19;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v3 )
      ipc_log_string(v3, "ipa %s:%d Sleep and check again channel empty or not\n", "ipa3_check_wdi_opt_chn_empty", 1588);
  }
  usleep_range_state(1000, 2000, 2);
  gsi_is_teth_channel_empty(v2, v11);
  if ( (v11[0] & 1) != 0 )
    goto LABEL_19;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d Sleep and check again channel empty or not\n", "ipa3_check_wdi_opt_chn_empty", 1588);
  }
  usleep_range_state(1000, 2000, 2);
  gsi_is_teth_channel_empty(v2, v11);
  if ( (v11[0] & 1) != 0 )
    goto LABEL_19;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d Sleep and check again channel empty or not\n", "ipa3_check_wdi_opt_chn_empty", 1588);
  }
  usleep_range_state(1000, 2000, 2);
  gsi_is_teth_channel_empty(v2, v11);
  if ( (v11[0] & 1) != 0 )
    goto LABEL_19;
  if ( ipa3_ctx )
  {
    v6 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d Sleep and check again channel empty or not\n", "ipa3_check_wdi_opt_chn_empty", 1588);
  }
  usleep_range_state(1000, 2000, 2);
  gsi_is_teth_channel_empty(v2, v11);
  if ( (v11[0] & 1) != 0 )
  {
LABEL_19:
    result = 1;
    goto LABEL_20;
  }
  if ( ipa3_ctx )
  {
    v8 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d Sleep and check again channel empty or not\n", "ipa3_check_wdi_opt_chn_empty", 1588);
  }
  usleep_range_state(1000, 2000, 2);
  v9 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_29:
    result = 0;
    goto LABEL_20;
  }
  v10 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v10 )
  {
    ipc_log_string(v10, "ipa %s:%d WDI RX Pipe=%d not empty.\n", "ipa3_check_wdi_opt_chn_empty", 1595, a1);
    v9 = ipa3_ctx;
  }
  result = *(_QWORD *)(v9 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d WDI RX Pipe=%d not empty.\n", "ipa3_check_wdi_opt_chn_empty", 1595, a1);
    goto LABEL_29;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
