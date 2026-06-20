__int64 __fastcall ipa3_enable_force_clear(_QWORD *a1, char a2, int a3, unsigned int a4)
{
  __int64 v4; // x13
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 result; // x0
  unsigned int v8; // w19
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  _DWORD v12[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v13[2]; // [xsp+10h] [xbp-20h]
  int v14; // [xsp+20h] [xbp-10h]
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 32256) == 2 )
  {
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d APQ platform - ignore force clear\n", "ipa3_enable_force_clear", 1062);
        v5 = ipa3_ctx;
      }
      result = *(_QWORD *)(v5 + 34160);
      if ( !result )
        goto LABEL_13;
      ipc_log_string(result, "ipa %s:%d APQ platform - ignore force clear\n", "ipa3_enable_force_clear", 1062);
    }
    result = 0;
LABEL_13:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v14 = 0;
  v13[0] = 0;
  v13[1] = 0;
  v12[0] = 0;
  v12[1] = (_DWORD)a1;
  if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x14u )
  {
    if ( !a4 )
    {
      v12[0] = a3;
      if ( (a2 & 1) == 0 )
        goto LABEL_12;
      goto LABEL_11;
    }
    __break(0x800u);
    v12[0] = a3;
    if ( (a2 & 1) != 0 )
LABEL_11:
      LOWORD(v13[0]) = 257;
LABEL_12:
    result = ipa3_qmi_enable_force_clear_datapath_send(v12);
    if ( (_DWORD)result )
    {
      v8 = result;
      printk(&unk_3CF59F, "ipa3_enable_force_clear");
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(
            v10,
            "ipa %s:%d ipa3_qmi_enable_force_clear_datapath_send failed %d\n",
            "ipa3_enable_force_clear",
            1083,
            v8);
          v9 = ipa3_ctx;
        }
        v11 = *(_QWORD *)(v9 + 34160);
        if ( v11 )
          ipc_log_string(
            v11,
            "ipa %s:%d ipa3_qmi_enable_force_clear_datapath_send failed %d\n",
            "ipa3_enable_force_clear",
            1083,
            v8);
      }
      result = v8;
    }
    goto LABEL_13;
  }
  BYTE2(v13[0]) = 1;
  if ( a4 < 4 )
  {
    *((_DWORD *)v13 + a4 + 1) = a3;
    if ( (a2 & 1) != 0 )
      goto LABEL_11;
    goto LABEL_12;
  }
  __break(0x5512u);
  *a1 = v4;
  return ipa3_disable_force_clear((char *)a1 + 217);
}
