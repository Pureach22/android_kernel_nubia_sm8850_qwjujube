__int64 __fastcall ipa3_remove_secondary_flow_ctrl(__int64 a1)
{
  unsigned int v1; // w19
  __int64 result; // x0
  __int64 v3; // x9
  unsigned int v4; // w21
  unsigned int v5; // w20
  unsigned int ep_mapping_from_gsi; // w0
  __int64 v7; // x9
  unsigned int v8; // w21
  __int64 v9; // x0
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v1 = a1;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  result = gsi_query_flow_control_state_ee(a1, 0, 1, &v10);
  if ( (_DWORD)result )
  {
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      if ( *(_QWORD *)(ipa3_ctx + 34152) )
      {
        v4 = result;
        ipc_log_string(
          *(_QWORD *)(ipa3_ctx + 34152),
          "ipa %s:%d failed to query flow control mode ch %d code %d\n",
          "ipa3_remove_secondary_flow_ctrl",
          1208,
          v1,
          v10);
        v3 = ipa3_ctx;
        result = v4;
      }
      if ( *(_QWORD *)(v3 + 34160) )
      {
        v5 = result;
        ipc_log_string(
          *(_QWORD *)(v3 + 34160),
          "ipa %s:%d failed to query flow control mode ch %d code %d\n",
          "ipa3_remove_secondary_flow_ctrl",
          1208,
          v1,
          v10);
LABEL_13:
        result = v5;
      }
    }
  }
  else
  {
    v10 = 0;
    ep_mapping_from_gsi = ipa_get_ep_mapping_from_gsi(v1);
    result = gsi_flow_control_ee(v1, ep_mapping_from_gsi, 0, 0, 1, &v10);
    v7 = ipa3_ctx;
    if ( !(_DWORD)result )
    {
      if ( ipa3_ctx )
      {
        v9 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v9 )
        {
          ipc_log_string(
            v9,
            "ipa %s:%d flow control sussess ch %d code %d\n",
            "ipa3_remove_secondary_flow_ctrl",
            1201,
            v1,
            v10);
          v7 = ipa3_ctx;
        }
        result = *(_QWORD *)(v7 + 34160);
        if ( !result )
          goto LABEL_20;
        ipc_log_string(
          result,
          "ipa %s:%d flow control sussess ch %d code %d\n",
          "ipa3_remove_secondary_flow_ctrl",
          1201,
          v1,
          v10);
      }
      result = 0;
      goto LABEL_20;
    }
    if ( ipa3_ctx )
    {
      if ( *(_QWORD *)(ipa3_ctx + 34152) )
      {
        v8 = result;
        ipc_log_string(
          *(_QWORD *)(ipa3_ctx + 34152),
          "ipa %s:%d failed to flow control ch %d code %d\n",
          "ipa3_remove_secondary_flow_ctrl",
          1204,
          v1,
          v10);
        v7 = ipa3_ctx;
        result = v8;
      }
      if ( *(_QWORD *)(v7 + 34160) )
      {
        v5 = result;
        ipc_log_string(
          *(_QWORD *)(v7 + 34160),
          "ipa %s:%d failed to flow control ch %d code %d\n",
          "ipa3_remove_secondary_flow_ctrl",
          1204,
          v1,
          v10);
        goto LABEL_13;
      }
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
