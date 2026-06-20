__int64 __fastcall ipa_pm_sys_pipe_cb(__int64 result, int a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  int v6; // w4
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0

  _ReadStatusReg(SP_EL0);
  if ( a2 )
  {
    v2 = result;
    if ( a2 == 1 )
    {
      v3 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v4 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v4 )
        {
          ipc_log_string(
            v4,
            "ipa %s:%d calling wakeup for client %d\n",
            "ipa_pm_sys_pipe_cb",
            1294,
            *(_DWORD *)(*(_QWORD *)(v2 + 1624) + 4LL));
          v3 = ipa3_ctx;
        }
        v5 = *(_QWORD *)(v3 + 34160);
        if ( v5 )
          ipc_log_string(
            v5,
            "ipa %s:%d calling wakeup for client %d\n",
            "ipa_pm_sys_pipe_cb",
            1294,
            *(_DWORD *)(*(_QWORD *)(v2 + 1624) + 4LL));
      }
      v6 = *(_DWORD *)(*(_QWORD *)(v2 + 1624) + 4LL);
      if ( v6 <= 94 )
      {
        if ( v6 == 33 || v6 == 35 || v6 == 83 )
          goto LABEL_19;
      }
      else if ( v6 > 120 )
      {
        if ( v6 == 121 || v6 == 127 )
          goto LABEL_19;
      }
      else if ( v6 == 95 || v6 == 105 )
      {
LABEL_19:
        ipa3_inc_client_enable_clks();
        usleep_range_state(1000, 1005, 2);
        result = ipa3_dec_client_disable_clks();
        goto LABEL_20;
      }
      result = printk(&unk_3E0DB6, "ipa_pm_sys_pipe_cb");
      v10 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v11 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v11 )
        {
          ipc_log_string(
            v11,
            "ipa %s:%d Unexpected event %d\n for client %d\n",
            "ipa_pm_sys_pipe_cb",
            1332,
            1,
            *(_DWORD *)(*(_QWORD *)(v2 + 1624) + 4LL));
          v10 = ipa3_ctx;
        }
        result = *(_QWORD *)(v10 + 34160);
        if ( result )
          result = ipc_log_string(
                     result,
                     "ipa %s:%d Unexpected event %d\n for client %d\n",
                     "ipa_pm_sys_pipe_cb",
                     1332,
                     1,
                     *(_DWORD *)(*(_QWORD *)(v2 + 1624) + 4LL));
      }
    }
    else
    {
      result = printk(&unk_3E0DB6, "ipa_pm_sys_pipe_cb");
      v8 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v9 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v9 )
        {
          ipc_log_string(
            v9,
            "ipa %s:%d Unexpected event %d\n for client %d\n",
            "ipa_pm_sys_pipe_cb",
            1336,
            a2,
            *(_DWORD *)(*(_QWORD *)(v2 + 1624) + 4LL));
          v8 = ipa3_ctx;
        }
        result = *(_QWORD *)(v8 + 34160);
        if ( result )
          result = ipc_log_string(
                     result,
                     "ipa %s:%d Unexpected event %d\n for client %d\n",
                     "ipa_pm_sys_pipe_cb",
                     1336,
                     a2,
                     *(_DWORD *)(*(_QWORD *)(v2 + 1624) + 4LL));
      }
      __break(0x800u);
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
