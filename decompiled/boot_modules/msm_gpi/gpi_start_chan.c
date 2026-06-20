__int64 __fastcall gpi_start_chan(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x20
  __int64 v9; // x0
  __int64 v10; // x6
  unsigned int v11; // w21
  __int64 v12; // x0

  v7 = *(_QWORD *)(a1 + 280);
  if ( *(_DWORD *)(v7 + 1068) >= 3u )
  {
    printk(&unk_123DE, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_start_chan", a5, a6, a7);
    v9 = *(_QWORD *)(v7 + 1056);
    if ( !v9 )
      goto LABEL_5;
  }
  else
  {
    v9 = *(_QWORD *)(v7 + 1056);
    if ( !v9 )
      goto LABEL_5;
  }
  if ( *(_DWORD *)(v7 + 1064) >= 3u )
    ipc_log_string(v9, "ch:%u %s: Enter\n", *(_DWORD *)(a1 + 256), "gpi_start_chan");
LABEL_5:
  v11 = ((__int64 (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v7, a1, 1);
  if ( !v11 )
  {
    raw_write_lock_irq(v7 + 948);
    *(_DWORD *)(a1 + 292) = 3;
    raw_write_unlock_irq(v7 + 948);
    return v11;
  }
  if ( *(_DWORD *)(v7 + 1068) >= 2u )
  {
    printk(&unk_147A5, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_start_chan", "CH START", v11, v10);
    v12 = *(_QWORD *)(v7 + 1056);
    if ( !v12 )
      return v11;
  }
  else
  {
    v12 = *(_QWORD *)(v7 + 1056);
    if ( !v12 )
      return v11;
  }
  if ( *(_DWORD *)(v7 + 1064) >= 2u )
    ipc_log_string(
      v12,
      "ch:%u %s: Error with cmd:%s ret:%d\n",
      *(_DWORD *)(a1 + 256),
      "gpi_start_chan",
      "CH START",
      v11);
  return v11;
}
