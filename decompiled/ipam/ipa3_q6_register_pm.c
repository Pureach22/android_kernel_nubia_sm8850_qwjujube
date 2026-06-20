__int64 ipa3_q6_register_pm()
{
  unsigned int v0; // w0
  __int64 result; // x0
  unsigned int v2; // w19
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  _QWORD v9[3]; // [xsp+8h] [xbp-28h] BYREF
  int v10; // [xsp+20h] [xbp-10h]
  int v11; // [xsp+24h] [xbp-Ch]
  __int64 v12; // [xsp+28h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = "EMB MODEM";
  v9[1] = 0;
  v9[2] = 0;
  v10 = 2;
  v11 = 1;
  v0 = ipa_pm_register((__int64)v9, (unsigned int *)(rmnet_ipa3_ctx + 1188));
  if ( v0 )
  {
    v2 = v0;
    printk(&unk_3C6B8B, "ipa3_q6_register_pm");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d failed to create IPA PM client %d\n", "ipa3_q6_register_pm", 3455, v2);
        v3 = ipa3_ctx;
      }
      v5 = *(_QWORD *)(v3 + 34160);
      if ( v5 )
        ipc_log_string(v5, "ipa %s:%d failed to create IPA PM client %d\n", "ipa3_q6_register_pm", 3455, v2);
    }
    goto LABEL_14;
  }
  v9[0] = "TETH MODEM";
  v10 = 2;
  LOBYTE(v11) = 1;
  result = ipa_pm_register((__int64)v9, (unsigned int *)(rmnet_ipa3_ctx + 1192));
  if ( (_DWORD)result )
  {
    v2 = result;
    printk(&unk_3C6B8B, "ipa3_q6_register_pm");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d failed to create IPA PM client %d\n", "ipa3_q6_register_pm", 3464, v2);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d failed to create IPA PM client %d\n", "ipa3_q6_register_pm", 3464, v2);
    }
LABEL_14:
    result = v2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
