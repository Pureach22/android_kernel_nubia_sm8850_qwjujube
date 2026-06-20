__int64 ipa_restore_suspend_handler()
{
  unsigned int v0; // w19
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0

  if ( (unsigned int)((__int64 (__fastcall *)(__int64))ipa3_remove_interrupt_handler)(13) )
  {
    printk(&unk_3EE358, "ipa_restore_suspend_handler");
    v5 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(
          v6,
          "ipa %s:%d remove handler for suspend interrupt failed\n",
          "ipa_restore_suspend_handler",
          7474);
        v5 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v5 + 34160);
      if ( v7 )
      {
        ipc_log_string(
          v7,
          "ipa %s:%d remove handler for suspend interrupt failed\n",
          "ipa_restore_suspend_handler",
          7474);
        return (unsigned int)-1;
      }
    }
    return (unsigned int)-1;
  }
  v0 = 0;
  if ( !(unsigned int)ipa_add_interrupt_handler(13, &ipa3_suspend_handler, 0, 0) )
    goto LABEL_3;
  printk(&unk_3D7AEB, "ipa_restore_suspend_handler");
  v1 = ipa3_ctx;
  if ( !ipa3_ctx )
    return (unsigned int)-1;
  v8 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v8 )
  {
    ipc_log_string(v8, "ipa %s:%d register handler for suspend interrupt failed\n", "ipa_restore_suspend_handler", 7481);
    v1 = ipa3_ctx;
  }
  v9 = *(_QWORD *)(v1 + 34160);
  if ( v9 )
  {
    ipc_log_string(v9, "ipa %s:%d register handler for suspend interrupt failed\n", "ipa_restore_suspend_handler", 7481);
    v0 = -1;
LABEL_3:
    v1 = ipa3_ctx;
    if ( !ipa3_ctx )
      return v0;
    goto LABEL_4;
  }
  v0 = -1;
  if ( !v1 )
    return v0;
LABEL_4:
  v2 = *(_QWORD *)(v1 + 34152);
  if ( v2 )
  {
    ipc_log_string(v2, "ipa %s:%d suspend handler successfully restored\n", "ipa_restore_suspend_handler", 7485);
    v1 = ipa3_ctx;
  }
  v3 = *(_QWORD *)(v1 + 34160);
  if ( v3 )
    ipc_log_string(v3, "ipa %s:%d suspend handler successfully restored\n", "ipa_restore_suspend_handler", 7485);
  return v0;
}
