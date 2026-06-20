__int64 __fastcall ipa_fw_load_sm_handle_event(int a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x8
  int v6; // w10
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0

  mutex_lock(ipa3_ctx + 45152);
  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(
        v3,
        "ipa %s:%d state=%d event=%d\n",
        "ipa_fw_load_sm_handle_event",
        8627,
        *(_DWORD *)(ipa3_ctx + 45144),
        a1);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(
        v4,
        "ipa %s:%d state=%d event=%d\n",
        "ipa_fw_load_sm_handle_event",
        8627,
        *(_DWORD *)(v2 + 45144),
        a1);
  }
  v5 = ipa3_ctx;
  v6 = *(_DWORD *)(ipa3_ctx + 45144);
  if ( !a1 )
  {
    if ( v6 != 2 )
    {
      if ( v6 )
      {
        printk(&unk_3C05CE, "ipa_fw_load_sm_handle_event");
        v13 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v14 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v14 )
          {
            ipc_log_string(v14, "ipa %s:%d ignore multiple requests to load FW\n", "ipa_fw_load_sm_handle_event", 8641);
            v13 = ipa3_ctx;
          }
          v15 = *(_QWORD *)(v13 + 34160);
          if ( v15 )
            ipc_log_string(v15, "ipa %s:%d ignore multiple requests to load FW\n", "ipa_fw_load_sm_handle_event", 8641);
        }
      }
      else
      {
        *(_DWORD *)(ipa3_ctx + 45144) = 1;
      }
      return mutex_unlock(ipa3_ctx + 45152);
    }
LABEL_18:
    *(_DWORD *)(ipa3_ctx + 45144) = 3;
    if ( !v5 )
      goto LABEL_25;
LABEL_21:
    v11 = *(_QWORD *)(v5 + 34152);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d Scheduled a work to load IPA FW\n", "ipa_fw_load_sm_handle_event", 8669);
      v5 = ipa3_ctx;
    }
    v12 = *(_QWORD *)(v5 + 34160);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d Scheduled a work to load IPA FW\n", "ipa_fw_load_sm_handle_event", 8669);
      v5 = ipa3_ctx;
    }
    goto LABEL_25;
  }
  if ( v6 )
  {
    if ( v6 != 1 )
    {
      printk(&unk_3DAE35, "ipa_fw_load_sm_handle_event");
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v8 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v8 )
        {
          ipc_log_string(v8, "ipa %s:%d ignore multiple smmu done events\n", "ipa_fw_load_sm_handle_event", 8656);
          v7 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v7 + 34160);
        if ( v9 )
          ipc_log_string(v9, "ipa %s:%d ignore multiple smmu done events\n", "ipa_fw_load_sm_handle_event", 8656);
      }
      return mutex_unlock(ipa3_ctx + 45152);
    }
    goto LABEL_18;
  }
  *(_DWORD *)(ipa3_ctx + 45144) = 2;
  if ( v5 )
    goto LABEL_21;
LABEL_25:
  mutex_unlock(v5 + 45152);
  return queue_work_on(32, *(_QWORD *)(ipa3_ctx + 31952), &ipa3_fw_loading_work);
}
