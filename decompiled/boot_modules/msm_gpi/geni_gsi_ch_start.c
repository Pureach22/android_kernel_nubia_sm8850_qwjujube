__int64 __fastcall geni_gsi_ch_start(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x5
  __int64 v3; // x6
  __int64 v4; // x19
  __int64 v5; // x0
  unsigned int started; // w0
  __int64 v7; // x5
  __int64 v8; // x6
  __int64 v9; // x0
  __int64 v10; // x8
  unsigned int v11; // w19
  unsigned int v13; // w20

  v1 = *(_QWORD *)(a1 + 280);
  mutex_lock(v1 + 888);
  v4 = v1 + 400;
  if ( *(_DWORD *)(v1 + 1068) > 2u )
  {
    printk(&unk_12C9E, v1 + 1076, *(unsigned int *)(v1 + 656), "geni_gsi_ch_start", 1, v2, v3);
    v5 = *(_QWORD *)(v1 + 1056);
    if ( !v5 )
      goto LABEL_5;
  }
  else
  {
    v5 = *(_QWORD *)(v1 + 1056);
    if ( !v5 )
      goto LABEL_5;
  }
  if ( *(_DWORD *)(v1 + 1064) >= 3u )
    ipc_log_string(v5, "ch:%u %s: Start chan:%d\n", *(_DWORD *)(v1 + 656), "geni_gsi_ch_start", 1);
LABEL_5:
  started = gpi_start_chan(v1 + 400);
  if ( started )
    goto LABEL_11;
  v4 = v1 + 8;
  if ( *(_DWORD *)(v1 + 1068) >= 3u )
  {
    printk(&unk_12C9E, v1 + 1076, *(unsigned int *)(v1 + 264), "geni_gsi_ch_start", 0, v7, v8);
    v9 = *(_QWORD *)(v1 + 1056);
    if ( !v9 )
      goto LABEL_10;
  }
  else
  {
    v9 = *(_QWORD *)(v1 + 1056);
    if ( !v9 )
      goto LABEL_10;
  }
  if ( *(_DWORD *)(v1 + 1064) >= 3u )
    ipc_log_string(v9, "ch:%u %s: Start chan:%d\n", *(_DWORD *)(v1 + 264), "geni_gsi_ch_start", 0);
LABEL_10:
  started = gpi_start_chan(v1 + 8);
  if ( !started )
  {
    v11 = 0;
    goto LABEL_16;
  }
LABEL_11:
  if ( *(_DWORD *)(v1 + 1068) >= 2u )
  {
    v13 = started;
    printk(&unk_11ED1, v1 + 1076, *(unsigned int *)(v4 + 256), "geni_gsi_ch_start", started, v7, v8);
    started = v13;
    v10 = *(_QWORD *)(v1 + 1056);
    if ( v10 )
    {
LABEL_13:
      if ( *(_DWORD *)(v1 + 1064) >= 2u )
        ipc_log_string(
          v10,
          "ch:%u %s: Error Starting Channel ret:%d\n",
          *(_DWORD *)(v4 + 256),
          "geni_gsi_ch_start",
          started);
    }
  }
  else
  {
    v10 = *(_QWORD *)(v1 + 1056);
    if ( v10 )
      goto LABEL_13;
  }
  v11 = -104;
LABEL_16:
  mutex_unlock(v1 + 888);
  return v11;
}
