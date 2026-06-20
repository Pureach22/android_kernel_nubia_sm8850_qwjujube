__int64 __fastcall icnss_sysfs_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v5; // x20
  __int64 v7; // x8
  __int64 v8; // x0

  result = a4;
  v5 = penv;
  if ( !penv )
    return result;
  printk("%sicnss2: Received shutdown indication", byte_13289B);
  ipc_log_string(icnss_ipc_log_context, "%sicnss2: Received shutdown indication", (const char *)&unk_12DBF3);
  *(_DWORD *)(v5 + 3272) = 1;
  if ( (*(_BYTE *)(v5 + 5968) & 1) == 0 && (*(_BYTE *)(v5 + 6112) & 1) == 0 )
  {
    v7 = *(_QWORD *)(v5 + 304);
    result = a4;
LABEL_8:
    if ( v7 != 30544 )
      return result;
    goto LABEL_9;
  }
  v7 = *(_QWORD *)(v5 + 304);
  result = a4;
  if ( v7 != 43981 )
    goto LABEL_8;
LABEL_9:
  mutex_lock(v5 + 5592);
  v8 = *(_QWORD *)(v5 + 3264);
  if ( v8 )
  {
    rproc_shutdown(v8);
    rproc_put(*(_QWORD *)(v5 + 3264));
    *(_QWORD *)(v5 + 3264) = 0;
  }
  mutex_unlock(v5 + 5592);
  return a4;
}
