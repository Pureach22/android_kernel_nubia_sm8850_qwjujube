__int64 __fastcall geni_gsi_disconnect_doorbell_stop_ch(__int64 a1, char a2)
{
  __int64 v2; // x19
  __int64 v5; // x4
  __int64 v6; // x5
  __int64 v7; // x6
  unsigned int v8; // w21
  _BOOL4 v9; // w23
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned int v12; // w0
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x8
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x0
  unsigned int v20; // w0
  __int64 v21; // x5
  __int64 v22; // x6
  __int64 v23; // x8
  unsigned int v25; // w21
  unsigned int v26; // w21

  v2 = *(_QWORD *)(a1 + 280);
  v8 = ((__int64 (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v2, a1, 9);
  v9 = v8 != 0;
  if ( v8 )
  {
    if ( *(_DWORD *)(v2 + 1068) >= 2u )
    {
      printk(&unk_14904, v2 + 1076, *(unsigned int *)(a1 + 256), "geni_gsi_disconnect_doorbell_stop_ch", v8, v6, v7);
      v10 = *(_QWORD *)(v2 + 1056);
      if ( v10 )
      {
LABEL_4:
        if ( *(_DWORD *)(v2 + 1064) >= 2u )
          ipc_log_string(
            v10,
            "ch:%u %s: Error disable Chan:%d HID interrupt\n",
            *(_DWORD *)(a1 + 256),
            "geni_gsi_disconnect_doorbell_stop_ch",
            v8);
      }
    }
    else
    {
      v10 = *(_QWORD *)(v2 + 1056);
      if ( v10 )
        goto LABEL_4;
    }
    gpi_dump_debug_reg((unsigned int *)v2);
  }
  if ( (a2 & 1) != 0 )
  {
    if ( *(_DWORD *)(v2 + 1068) >= 3u )
    {
      printk(&unk_11B11, v2 + 1076, *(unsigned int *)(a1 + 256), "geni_gsi_disconnect_doorbell_stop_ch", v5, v6, v7);
      v11 = *(_QWORD *)(v2 + 1056);
      if ( !v11 )
        goto LABEL_12;
    }
    else
    {
      v11 = *(_QWORD *)(v2 + 1056);
      if ( !v11 )
        goto LABEL_12;
    }
    if ( *(_DWORD *)(v2 + 1064) >= 3u )
      ipc_log_string(v11, "ch:%u %s: Stop RX chan\n", *(_DWORD *)(a1 + 256), "geni_gsi_disconnect_doorbell_stop_ch");
LABEL_12:
    v12 = gpi_terminate_channel(v2 + 400);
    if ( !v12 )
      goto LABEL_18;
    if ( *(_DWORD *)(v2 + 1068) >= 2u )
    {
      v25 = v12;
      printk(&unk_14B93, v2 + 1076, *(unsigned int *)(a1 + 256), "geni_gsi_disconnect_doorbell_stop_ch", v12, v13, v14);
      v12 = v25;
      v15 = *(_QWORD *)(v2 + 1056);
      if ( v15 )
      {
LABEL_15:
        if ( *(_DWORD *)(v2 + 1064) >= 2u )
          ipc_log_string(
            v15,
            "ch:%u %s: Error Stopping RX Chan:%d\n",
            *(_DWORD *)(a1 + 256),
            "geni_gsi_disconnect_doorbell_stop_ch",
            v12);
      }
    }
    else
    {
      v15 = *(_QWORD *)(v2 + 1056);
      if ( v15 )
        goto LABEL_15;
    }
    gpi_dump_debug_reg((unsigned int *)v2);
    v9 = 1;
LABEL_18:
    gpi_free_chan_desc(v2 + 400);
    if ( *(_DWORD *)(v2 + 1068) >= 3u )
    {
      printk(&unk_129EA, v2 + 1076, *(unsigned int *)(a1 + 256), "geni_gsi_disconnect_doorbell_stop_ch", v16, v17, v18);
      v19 = *(_QWORD *)(v2 + 1056);
      if ( !v19 )
        goto LABEL_22;
    }
    else
    {
      v19 = *(_QWORD *)(v2 + 1056);
      if ( !v19 )
        goto LABEL_22;
    }
    if ( *(_DWORD *)(v2 + 1064) >= 3u )
      ipc_log_string(v19, "ch:%u %s: Stop TX chan\n", *(_DWORD *)(a1 + 256), "geni_gsi_disconnect_doorbell_stop_ch");
LABEL_22:
    v20 = gpi_terminate_channel(v2 + 8);
    if ( !v20 )
    {
      if ( !v9 )
        return 0;
      return (unsigned int)-16;
    }
    if ( *(_DWORD *)(v2 + 1068) >= 2u )
    {
      v26 = v20;
      printk(&unk_11960, v2 + 1076, *(unsigned int *)(a1 + 256), "geni_gsi_disconnect_doorbell_stop_ch", v20, v21, v22);
      v20 = v26;
      v23 = *(_QWORD *)(v2 + 1056);
      if ( v23 )
      {
LABEL_25:
        if ( *(_DWORD *)(v2 + 1064) >= 2u )
          ipc_log_string(
            v23,
            "ch:%u %s: Error Stopping TX Chan:%d\n",
            *(_DWORD *)(a1 + 256),
            "geni_gsi_disconnect_doorbell_stop_ch",
            v20);
      }
    }
    else
    {
      v23 = *(_QWORD *)(v2 + 1056);
      if ( v23 )
        goto LABEL_25;
    }
    gpi_dump_debug_reg((unsigned int *)v2);
    return (unsigned int)-16;
  }
  gpi_free_chan_desc(v2 + 400);
  return v8;
}
