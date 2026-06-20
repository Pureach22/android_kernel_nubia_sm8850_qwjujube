__int64 __fastcall spcom_device_release(__int64 a1, __int64 a2)
{
  const char *v3; // x20
  __int64 v4; // x8
  unsigned int v5; // w19
  __int64 v6; // x2
  __int64 v7; // x2
  __int64 v8; // x22
  __int64 v9; // x24
  __int64 v11; // x8
  __int64 v12; // x5
  int *v13; // x21
  unsigned int v14; // w19
  const char *v15; // x4
  __int64 v16; // x8
  int v17; // w6
  __int64 v18; // x23
  __int64 v19; // x24
  __int64 v20; // x21
  _BYTE *v21; // x20
  unsigned int v22; // w8
  __int64 v23; // x8

  v3 = "unknown";
  if ( a2 )
  {
    v4 = *(_QWORD *)(a2 + 72);
    if ( v4 )
      v3 = (const char *)(v4 + 56);
  }
  v5 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1804);
  if ( !strcmp(v3, "unknown") )
  {
    printk(&unk_118C7, "spcom_device_release", v6);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: name is unknown\n", "spcom_device_release", &unk_F80E);
    return 4294967274LL;
  }
  if ( !strcmp(v3, "sp_ssr") )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: sp_ssr dev node skipped\n",
      "spcom_device_release",
      (const char *)&unk_F80E);
    return 0;
  }
  if ( !v5 )
  {
    printk(&unk_10736, "spcom_device_release", v7);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: unknown PID\n", "spcom_device_release", &unk_F80E);
    return 4294967274LL;
  }
  if ( !strcmp(v3, "spcom") )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: PID [%d] release control channel\n",
      "spcom_device_release",
      (const char *)&unk_F80E,
      v5);
    mutex_lock(spcom_dev + 58344);
    v11 = spcom_dev;
    v12 = 0;
    v13 = (int *)(spcom_dev + 58484);
    while ( *(v13 - 1) != v5 )
    {
      ++v12;
      v13 += 2;
      if ( v12 == 32 )
      {
        v14 = -3;
        goto LABEL_23;
      }
    }
    v17 = *v13 - 1;
    *v13 = v17;
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: Remove pid %u from index %u, ref_cnt=%u\n",
      "spom_control_channel_remove_client",
      (const char *)&unk_F80E,
      v5,
      v12,
      v17);
    v11 = spcom_dev;
    if ( !*v13 )
    {
      v18 = 32;
      v19 = 1512;
      *(v13 - 1) = 0;
      do
      {
        v21 = (_BYTE *)(v11 + v19 - 312);
        if ( *v21
          && (*(_DWORD *)(v11 + v19 - 16) == v5
           || *(_DWORD *)(v11 + v19 - 12) == v5
           || *(_DWORD *)(v11 + v19 - 8) == v5
           || *(_DWORD *)(v11 + v19 - 4) == v5
           || *(_DWORD *)(v11 + v19) == v5) )
        {
          v20 = v11 + v19 - 280;
          mutex_lock(v20);
          spcom_channel_deinit_locked(v21, v5);
          mutex_unlock(v20);
          v11 = spcom_dev;
        }
        --v18;
        v19 += 1784;
      }
      while ( v18 );
    }
    v14 = 0;
LABEL_23:
    mutex_unlock(v11 + 58344);
    return v14;
  }
  v8 = *(_QWORD *)(a2 + 32);
  if ( !v8 )
  {
    v15 = "unknown";
    if ( a2 )
    {
      v16 = *(_QWORD *)(a2 + 72);
      if ( v16 )
        v15 = (const char *)(v16 + 56);
    }
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch is NULL, file name %s\n",
      "spcom_device_release",
      (const char *)&unk_F80E,
      v15);
    return 4294967277LL;
  }
  mutex_lock(v8 + 32);
  if ( !*(_QWORD *)(v8 + 152) )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch [%s] already closed\n",
      "spcom_device_release",
      (const char *)&unk_F80E,
      v3);
LABEL_51:
    mutex_unlock(v8 + 32);
    return 0;
  }
  if ( *(_DWORD *)(v8 + 296) == v5 )
  {
    v9 = 0;
LABEL_46:
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: PID [%x] is releasing ch [%s]\n",
      "spcom_device_release",
      (const char *)&unk_F80E,
      v5,
      v3);
    *(_DWORD *)(v8 + 296 + 4 * v9) = 0;
    goto LABEL_47;
  }
  if ( *(_DWORD *)(v8 + 300) == v5 )
  {
    v9 = 1;
    goto LABEL_46;
  }
  if ( *(_DWORD *)(v8 + 304) == v5 )
  {
    v9 = 2;
    goto LABEL_46;
  }
  if ( *(_DWORD *)(v8 + 308) == v5 )
  {
    v9 = 3;
    goto LABEL_46;
  }
  if ( *(_DWORD *)(v8 + 312) == v5 )
  {
    v9 = 4;
    goto LABEL_46;
  }
LABEL_47:
  v22 = *(unsigned __int8 *)(v8 + 244);
  if ( v22 >= 2 )
  {
    if ( *(_DWORD *)(v8 + 240) == v5 )
    {
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: active_pid [%x] is releasing ch [%s] sync lock\n",
        "spcom_device_release",
        (const char *)&unk_F80E,
        v5,
        v3);
      *(_DWORD *)(v8 + 240) = 0;
      mutex_unlock(v8 + 248);
      LOBYTE(v22) = *(_BYTE *)(v8 + 244);
    }
    *(_BYTE *)(v8 + 232) = 0;
    *(_BYTE *)(v8 + 244) = v22 - 1;
    goto LABEL_51;
  }
  v23 = *(_QWORD *)(v8 + 328);
  *(_BYTE *)(v8 + 232) = 0;
  *(_BYTE *)(v8 + 244) = 0;
  *(_DWORD *)(v8 + 240) = 0;
  if ( v23 )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch [%s] discarding unconsumed rx packet actual_rx_size=%zd\n",
      "spcom_device_release",
      (const char *)&unk_F80E,
      v3,
      *(_QWORD *)(v8 + 320));
    kfree(*(_QWORD *)(v8 + 328));
    *(_QWORD *)(v8 + 328) = 0;
  }
  *(_QWORD *)(v8 + 320) = 0;
  mutex_unlock(v8 + 32);
  *(_QWORD *)(a2 + 32) = 0;
  return 0;
}
