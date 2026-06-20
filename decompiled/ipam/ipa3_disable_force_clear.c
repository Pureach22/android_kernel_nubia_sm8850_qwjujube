__int64 __fastcall ipa3_disable_force_clear(int a1)
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 result; // x0
  unsigned int v4; // w19
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 32256) == 2 )
  {
    if ( !ipa3_ctx )
    {
LABEL_7:
      result = 0;
      goto LABEL_9;
    }
    v2 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d APQ platform - ignore force clear\n", "ipa3_disable_force_clear", 1096);
      v1 = ipa3_ctx;
    }
    result = *(_QWORD *)(v1 + 34160);
    if ( result )
    {
      ipc_log_string(result, "ipa %s:%d APQ platform - ignore force clear\n", "ipa3_disable_force_clear", 1096);
      goto LABEL_7;
    }
  }
  else
  {
    v8 = a1;
    result = ipa3_qmi_disable_force_clear_datapath_send(&v8);
    if ( (_DWORD)result )
    {
      v4 = result;
      printk(&unk_3F75A3, "ipa3_disable_force_clear");
      v5 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v6 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v6 )
        {
          ipc_log_string(
            v6,
            "ipa %s:%d ipa3_qmi_disable_force_clear_datapath_send failed %d\n",
            "ipa3_disable_force_clear",
            1105,
            v4);
          v5 = ipa3_ctx;
        }
        v7 = *(_QWORD *)(v5 + 34160);
        if ( v7 )
          ipc_log_string(
            v7,
            "ipa %s:%d ipa3_qmi_disable_force_clear_datapath_send failed %d\n",
            "ipa3_disable_force_clear",
            1105,
            v4);
      }
      result = v4;
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
