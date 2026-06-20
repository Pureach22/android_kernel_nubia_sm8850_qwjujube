__int64 __fastcall ipa3_odl_pipe_cleanup(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int16 v3; // w22
  char v4; // w19
  unsigned int v5; // w0
  __int64 v6; // x8
  __int16 v7; // w9
  __int16 v8; // w11
  __int64 v9; // x9
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0

  v1 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 32240) > 0xEu )
  {
    v3 = *(_WORD *)(ipa3_odl_ctx + 692);
    if ( (v3 & 4) != 0 )
    {
      if ( (v3 & 0x10) != 0 )
      {
        v4 = result;
        v5 = *(_DWORD *)(ipa3_odl_ctx + 688);
        *(_DWORD *)(ipa3_odl_ctx + 692) = 1;
        ipa_teardown_sys_pipe(v5);
        v6 = ipa3_odl_ctx;
        *(_DWORD *)(ipa3_odl_ctx + 688) = -1;
        if ( (v3 & 2) != 0 )
          *(_WORD *)(v6 + 692) |= 2u;
        v7 = *(_WORD *)(v6 + 692);
        *(_BYTE *)(v6 + 696) = 1;
        if ( (v4 & 1) != 0 )
          v8 = 4;
        else
          v8 = 0;
        *(_DWORD *)(v6 + 708) = 0;
        *(_WORD *)(v6 + 692) = v7 & 0xFE63 | v8 | 0x100;
        *(_DWORD *)(v6 + 712) = 0;
        v9 = ipa3_ctx;
        *(_QWORD *)(v6 + 700) = 0;
        if ( v9 )
        {
          v10 = *(_QWORD *)(v9 + 34152);
          if ( v10 )
          {
            ipc_log_string(v10, "ipa %s:%d Wake up odl ctl\n", "ipa3_odl_pipe_cleanup", 539);
            v9 = ipa3_ctx;
          }
          v11 = *(_QWORD *)(v9 + 34160);
          if ( v11 )
            ipc_log_string(v11, "ipa %s:%d Wake up odl ctl\n", "ipa3_odl_pipe_cleanup", 539);
        }
        return _wake_up(&odl_ctl_msg_wq, 1, 1, 0);
      }
      else
      {
        result = printk(&unk_3E1345, "ipa3_odl_pipe_cleanup");
        v14 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v15 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v15 )
          {
            ipc_log_string(v15, "ipa %s:%d adpl pipe setup not done\n", "ipa3_odl_pipe_cleanup", 502);
            v14 = ipa3_ctx;
          }
          result = *(_QWORD *)(v14 + 34160);
          if ( result )
            return ipc_log_string(result, "ipa %s:%d adpl pipe setup not done\n", "ipa3_odl_pipe_cleanup", 502);
        }
      }
    }
    else
    {
      result = printk(&unk_3B853F, "ipa3_odl_pipe_cleanup");
      v12 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v13 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v13 )
        {
          ipc_log_string(v13, "ipa %s:%d adpl pipe not configured\n", "ipa3_odl_pipe_cleanup", 497);
          v12 = ipa3_ctx;
        }
        result = *(_QWORD *)(v12 + 34160);
        if ( result )
          return ipc_log_string(result, "ipa %s:%d adpl pipe not configured\n", "ipa3_odl_pipe_cleanup", 497);
      }
    }
  }
  else if ( ipa3_ctx )
  {
    v2 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d ODL not supported\n", "ipa3_odl_pipe_cleanup", 492);
      v1 = ipa3_ctx;
    }
    result = *(_QWORD *)(v1 + 34160);
    if ( result )
      return ipc_log_string(result, "ipa %s:%d ODL not supported\n", "ipa3_odl_pipe_cleanup", 492);
  }
  return result;
}
