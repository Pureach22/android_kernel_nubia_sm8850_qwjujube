__int64 __fastcall gpi_terminate_channel(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v3; // w0
  __int64 v4; // x5
  __int64 v5; // x6
  __int64 v6; // x8
  __int64 v7; // x5
  __int64 v8; // x6
  unsigned int v9; // w21
  __int64 v10; // x0
  unsigned int v12; // w21

  v1 = *(_QWORD *)(a1 + 280);
  mutex_lock(v1 + 888);
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v1, a1, 2);
  if ( !v3 )
  {
    v9 = 0;
    goto LABEL_12;
  }
  if ( *(_DWORD *)(v1 + 1068) >= 2u )
  {
    v12 = v3;
    printk(&unk_123B0, v1 + 1076, *(unsigned int *)(a1 + 256), "gpi_terminate_channel", v3, v4, v5);
    v3 = v12;
    v6 = *(_QWORD *)(v1 + 1056);
    if ( !v6 )
      goto LABEL_6;
  }
  else
  {
    v6 = *(_QWORD *)(v1 + 1056);
    if ( !v6 )
      goto LABEL_6;
  }
  if ( *(_DWORD *)(v1 + 1064) >= 2u )
    ipc_log_string(
      v6,
      "ch:%u %s: Error Stopping Chan:%d,resetting\n",
      *(_DWORD *)(a1 + 256),
      "gpi_terminate_channel",
      v3);
LABEL_6:
  v9 = ((__int64 (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v1, a1, 3);
  if ( v9 )
  {
    if ( *(_DWORD *)(v1 + 1068) >= 2u )
    {
      printk(&unk_13775, v1 + 1076, *(unsigned int *)(a1 + 256), "gpi_terminate_channel", v9, v7, v8);
      v10 = *(_QWORD *)(v1 + 1056);
      if ( !v10 )
        goto LABEL_12;
    }
    else
    {
      v10 = *(_QWORD *)(v1 + 1056);
      if ( !v10 )
        goto LABEL_12;
    }
    if ( *(_DWORD *)(v1 + 1064) >= 2u )
      ipc_log_string(v10, "ch:%u %s: error resetting channel:%d\n", *(_DWORD *)(a1 + 256), "gpi_terminate_channel", v9);
  }
LABEL_12:
  mutex_unlock(v1 + 888);
  return v9;
}
