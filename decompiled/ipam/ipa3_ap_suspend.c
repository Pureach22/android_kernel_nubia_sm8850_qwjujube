__int64 __fastcall ipa3_ap_suspend(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x8
  __int64 v7; // x19
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0

  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d Enter...\n", "ipa3_ap_suspend", 11971);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d Enter...\n", "ipa3_ap_suspend", 11971);
  }
  result = of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,ipa");
  if ( (_DWORD)result )
  {
    v6 = *(unsigned int *)(ipa3_ctx + 34308);
    if ( !(_DWORD)v6 )
    {
LABEL_18:
      ipa_pm_deactivate_all_deferred();
      v12 = ipa3_ctx;
      *(_DWORD *)(ipa3_ctx + 52488) = 1;
      if ( v12 )
      {
        v13 = *(_QWORD *)(v12 + 34152);
        if ( v13 )
        {
          ipc_log_string(v13, "ipa %s:%d Exit\n", "ipa3_ap_suspend", 11994);
          v12 = ipa3_ctx;
        }
        result = *(_QWORD *)(v12 + 34160);
        if ( !result )
          return result;
        ipc_log_string(result, "ipa %s:%d Exit\n", "ipa3_ap_suspend", 11994);
      }
      return 0;
    }
    v7 = 0;
    v8 = ipa3_ctx + 640;
    while ( 1 )
    {
      if ( v7 == 36 )
      {
        __break(0x5512u);
        return ipa3_ap_freeze();
      }
      if ( *(_QWORD *)v8 && *(_DWORD *)(*(_QWORD *)v8 + 4LL) )
        break;
      ++v7;
      v8 += 480;
      if ( v6 == v7 )
        goto LABEL_18;
    }
    printk(&unk_3C3105, "ipa3_ap_suspend");
    v9 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967285LL;
    v10 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d EP %d is in polling state, do not suspend\n", "ipa3_ap_suspend", 11979, v7);
      v9 = ipa3_ctx;
    }
    v11 = *(_QWORD *)(v9 + 34160);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d EP %d is in polling state, do not suspend\n", "ipa3_ap_suspend", 11979, v7);
      return 4294967285LL;
    }
    else
    {
      return 4294967285LL;
    }
  }
  return result;
}
