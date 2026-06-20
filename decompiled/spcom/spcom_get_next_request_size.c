__int64 __fastcall spcom_get_next_request_size(__int64 a1)
{
  __int64 v2; // x5
  __int64 v3; // x20
  int v4; // w0
  unsigned int v5; // w20

  mutex_lock(a1 + 32);
  if ( *(_BYTE *)(a1 + 85) == 1 )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: server [%s] reading it's first request\n",
      "spcom_get_next_request_size",
      (const char *)&unk_F80E,
      (const char *)a1);
    *(_WORD *)(a1 + 84) = 1;
  }
  *(_DWORD *)(a1 + 168) = 0;
  v2 = *(_QWORD *)(a1 + 320);
  if ( v2 )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: next-req-size already ready ch [%s] size [%zu]\n",
      "spcom_get_next_request_size",
      (const char *)&unk_F80E,
      (const char *)a1,
      v2);
    v3 = *(_QWORD *)(a1 + 320);
  }
  else
  {
    mutex_unlock(a1 + 32);
    v4 = wait_for_completion_interruptible(a1 + 168);
    if ( v4 < 0 )
    {
      v5 = v4;
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s]:interrupted wait ret=%d\n",
        "spcom_get_next_request_size",
        (const char *)&unk_F80E,
        (const char *)a1,
        v4);
      return v5;
    }
    mutex_lock(a1 + 32);
    v3 = *(_QWORD *)(a1 + 320);
    if ( !v3 )
    {
      printk(&unk_1085A, "spcom_get_next_request_size", 0);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: invalid rx size [%zu] ch [%s]\n",
        "spcom_get_next_request_size",
        (const char *)&unk_F80E,
        *(_QWORD *)(a1 + 320),
        (const char *)a1);
      goto LABEL_13;
    }
  }
  if ( (unsigned int)v3 < 9 )
  {
    printk(&unk_10885, "spcom_get_next_request_size", (unsigned int)v3);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: rx size [%d] too small\n",
      "spcom_get_next_request_size",
      (const char *)&unk_F80E,
      v3);
LABEL_13:
    mutex_unlock(a1 + 32);
    return (unsigned int)-14;
  }
  v5 = v3 - 8;
  mutex_unlock(a1 + 32);
  return v5;
}
