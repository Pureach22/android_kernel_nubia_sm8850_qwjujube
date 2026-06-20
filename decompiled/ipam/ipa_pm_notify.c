__int64 __fastcall ipa_pm_notify(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0

  v3 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d Entry\n", "ipa_pm_notify", 525);
      v3 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v3 + 34160);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d Entry\n", "ipa_pm_notify", 525);
      v3 = ipa3_ctx;
    }
  }
  if ( a2 != 2 || *(_BYTE *)(v3 + 45220) != 1 )
    goto LABEL_28;
  if ( v3 )
  {
    v6 = *(_QWORD *)(v3 + 34152);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d Enter hibernate restore\n", "ipa_pm_notify", 540);
      v3 = ipa3_ctx;
    }
    v7 = *(_QWORD *)(v3 + 34160);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d Enter hibernate restore\n", "ipa_pm_notify", 540);
      v3 = ipa3_ctx;
    }
    if ( v3 )
    {
      v8 = *(_QWORD *)(v3 + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d Entry\n", "ipa3_deepsleep_resume", 12108);
        v3 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v3 + 34160);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d Entry\n", "ipa3_deepsleep_resume", 12108);
        v3 = ipa3_ctx;
      }
    }
  }
  v10 = *(_QWORD *)(v3 + 31952);
  *(_BYTE *)(v3 + 45220) = 0;
  queue_work_on(32, v10, &ipa3_fw_loading_work);
  v3 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v11 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d Exit\n", "ipa3_deepsleep_resume", 12114);
      v3 = ipa3_ctx;
    }
    v12 = *(_QWORD *)(v3 + 34160);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d Exit\n", "ipa3_deepsleep_resume", 12114);
      v3 = ipa3_ctx;
    }
    if ( v3 )
    {
      v13 = *(_QWORD *)(v3 + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d Exit hibernate restore\n", "ipa_pm_notify", 542);
        v3 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v3 + 34160);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d Exit hibernate restore\n", "ipa_pm_notify", 542);
        v3 = ipa3_ctx;
      }
LABEL_28:
      if ( v3 )
      {
        v15 = *(_QWORD *)(v3 + 34152);
        if ( v15 )
        {
          ipc_log_string(v15, "ipa %s:%d Exit\n", "ipa_pm_notify", 547);
          v3 = ipa3_ctx;
        }
        v16 = *(_QWORD *)(v3 + 34160);
        if ( v16 )
          ipc_log_string(v16, "ipa %s:%d Exit\n", "ipa_pm_notify", 547);
      }
    }
  }
  return 0;
}
