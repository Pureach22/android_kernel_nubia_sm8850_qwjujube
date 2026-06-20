__int64 __fastcall ipa3_q6_pipe_flow_control(__int64 result)
{
  char v1; // w19
  unsigned int v2; // w20
  unsigned int v3; // w26
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x25
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v1 = result;
  v2 = 0;
  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  do
  {
    if ( v2 == 84 || v2 == 114 || v2 == 74 || v2 == 122 || (v2 & 0xFD) == 0x38 || v2 == 52 || (v2 & 0xFB) == 0x32 )
    {
      result = ipa_get_ep_mapping(v2);
      if ( (_DWORD)result != -1 )
      {
        v3 = result;
        v4 = ((__int64 (__fastcall *)(_QWORD))ipa_get_gsi_ep_info)(v2);
        if ( !v4 )
        {
          printk(&unk_3D1F32, "ipa3_q6_pipe_flow_control");
          v13 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v14 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v14 )
            {
              ipc_log_string(v14, "ipa %s:%d failed to get GSI config\n", "ipa3_q6_pipe_flow_control", 4715);
              v13 = ipa3_ctx;
            }
            v15 = *(_QWORD *)(v13 + 34160);
            if ( v15 )
              ipc_log_string(v15, "ipa %s:%d failed to get GSI config\n", "ipa3_q6_pipe_flow_control", 4715);
          }
          printk(&unk_3AED39, v12);
          __break(0x800u);
        }
        v5 = ipa3_ctx;
        v6 = v4;
        if ( ipa3_ctx )
        {
          v7 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v7 )
          {
            ipc_log_string(v7, "ipa %s:%d pipe setting V2 flow control\n", "ipa3_q6_pipe_flow_control", 4719);
            v5 = ipa3_ctx;
          }
          v8 = *(_QWORD *)(v5 + 34160);
          if ( v8 )
            ipc_log_string(v8, "ipa %s:%d pipe setting V2 flow control\n", "ipa3_q6_pipe_flow_control", 4719);
        }
        result = gsi_flow_control_ee(*(unsigned int *)(v6 + 4), v3, *(unsigned int *)(v6 + 16), v1 & 1, 0, &v16);
        v9 = ipa3_ctx;
        if ( (_DWORD)result )
        {
          if ( ipa3_ctx )
          {
            v10 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v10 )
            {
              ipc_log_string(
                v10,
                "ipa %s:%d failed  gsi ch %d code %d\n",
                "ipa3_q6_pipe_flow_control",
                4729,
                *(_DWORD *)(v6 + 4),
                v16);
              v9 = ipa3_ctx;
            }
            result = *(_QWORD *)(v9 + 34160);
            if ( result )
              result = ipc_log_string(result, "ipa %s:%d failed  gsi ch %d code %d\n");
          }
        }
        else if ( ipa3_ctx )
        {
          v11 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v11 )
          {
            ipc_log_string(
              v11,
              "ipa %s:%d sussess gsi ch %d with code %d\n",
              "ipa3_q6_pipe_flow_control",
              4726,
              *(_DWORD *)(v6 + 4),
              v16);
            v9 = ipa3_ctx;
          }
          result = *(_QWORD *)(v9 + 34160);
          if ( result )
            result = ipc_log_string(result, "ipa %s:%d sussess gsi ch %d with code %d\n");
        }
      }
    }
    ++v2;
  }
  while ( v2 != 134 );
  _ReadStatusReg(SP_EL0);
  return result;
}
