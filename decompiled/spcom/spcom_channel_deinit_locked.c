__int64 __fastcall spcom_channel_deinit_locked(__int64 a1, int a2)
{
  int v3; // w8
  __int64 v5; // x22
  int v6; // w8
  char v7; // w8
  __int64 v8; // x9

  if ( !*(_QWORD *)(a1 + 152) )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch [%s] already closed\n",
      "spcom_channel_deinit_locked",
      (const char *)&unk_F80E,
      (const char *)a1);
    return 0;
  }
  v3 = *(_DWORD *)(a1 + 236);
  if ( !v3 )
    goto LABEL_12;
  if ( *(_DWORD *)(a1 + 296) != a2 )
  {
    if ( v3 != 1 )
    {
      if ( *(_DWORD *)(a1 + 300) == a2 )
      {
        v5 = 1;
        goto LABEL_5;
      }
      if ( v3 != 2 )
      {
        if ( *(_DWORD *)(a1 + 304) == a2 )
        {
          v5 = 2;
          goto LABEL_5;
        }
        if ( v3 != 3 )
        {
          if ( *(_DWORD *)(a1 + 308) == a2 )
          {
            v5 = 3;
            goto LABEL_5;
          }
          if ( v3 != 4 )
          {
            if ( *(_DWORD *)(a1 + 312) == a2 )
            {
              v5 = 4;
              goto LABEL_5;
            }
            if ( v3 != 5 )
            {
              __break(0x5512u);
              return spcom_destroy_channel_chardev(a1);
            }
          }
        }
      }
    }
LABEL_12:
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: pid [%d] is not a client of ch [%s]\n",
      "spcom_channel_deinit_locked",
      (const char *)&unk_F80E,
      a2,
      (const char *)a1);
    return 4294967282LL;
  }
  v5 = 0;
LABEL_5:
  ipc_log_string(
    spcom_ipc_log_context,
    "%sspcom:%s: pid [%x] is releasing ch [%s]\n",
    "spcom_channel_deinit_locked",
    (const char *)&unk_F80E,
    a2,
    (const char *)a1);
  v6 = *(_DWORD *)(a1 + 240);
  *(_DWORD *)(a1 + 296 + 4 * v5) = 0;
  if ( v6 == a2 )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: active_pid [%d] is releasing ch [%s] sync lock\n",
      "spcom_channel_deinit_locked",
      (const char *)&unk_F80E,
      a2,
      (const char *)a1);
    *(_DWORD *)(a1 + 240) = 0;
    mutex_unlock(a1 + 248);
  }
  v7 = *(_BYTE *)(a1 + 244);
  v8 = *(_QWORD *)(a1 + 328);
  *(_BYTE *)(a1 + 232) = 0;
  *(_BYTE *)(a1 + 244) = v7 - 1;
  if ( v8 )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch [%s] discarding unconsumed rx packet actual_rx_size=%zd\n",
      "spcom_channel_deinit_locked",
      (const char *)&unk_F80E,
      (const char *)a1,
      *(_QWORD *)(a1 + 320));
    kfree(*(_QWORD *)(a1 + 328));
    *(_QWORD *)(a1 + 328) = 0;
  }
  *(_QWORD *)(a1 + 320) = 0;
  return 0;
}
