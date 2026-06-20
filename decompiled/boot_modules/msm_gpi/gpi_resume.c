__int64 __fastcall gpi_resume(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x25
  _DWORD *v8; // x20
  __int64 v10; // x0
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x0
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x0
  __int64 v19; // x21
  __int64 v20; // x0
  unsigned int v21; // w0
  __int64 v22; // x5
  __int64 v23; // x6
  unsigned int v24; // w20
  __int64 v25; // x0
  unsigned int v26; // w0
  __int64 v27; // x2
  __int64 v28; // x3
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x0
  __int64 v33; // x22
  __int64 v34; // x2
  __int64 v35; // x3
  unsigned int v36; // w23
  unsigned int v37; // w0
  __int64 v38; // x1
  __int64 v39; // x0
  int v40; // w22
  __int64 v41; // x1
  unsigned int started; // w23
  int v43; // w26
  unsigned int v44; // w0
  __int64 v45; // x0
  __int64 v46; // x2
  __int64 v47; // x3
  __int64 v48; // x4
  __int64 v49; // x5
  __int64 v50; // x6
  __int64 v51; // x0
  __int64 v52; // x0

  v7 = *(_QWORD *)(a1 + 280);
  v8 = *(_DWORD **)(a1 + 104);
  if ( *(_DWORD *)(v7 + 1068) >= 3u )
  {
    printk(&unk_128D8, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_resume", a5, a6, a7);
    v10 = *(_QWORD *)(v7 + 1056);
    if ( !v10 )
      goto LABEL_5;
  }
  else
  {
    v10 = *(_QWORD *)(v7 + 1056);
    if ( !v10 )
      goto LABEL_5;
  }
  if ( *(_DWORD *)(v7 + 1064) >= 3u )
    ipc_log_string(v10, "ch:%u %s: enter\n", *(_DWORD *)(a1 + 256), "gpi_resume");
LABEL_5:
  mutex_lock(v7 + 888);
  if ( *(_BYTE *)(v7 + 1474) == 1 )
  {
    if ( *(_DWORD *)(v7 + 1068) >= 2u )
    {
      printk(&unk_14753, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_resume", v11, v12, v13);
      v14 = *(_QWORD *)(v7 + 1056);
      if ( v14 )
      {
LABEL_8:
        if ( *(_DWORD *)(v7 + 1064) >= 2u )
          ipc_log_string(v14, "ch:%u %s: Already resumed\n", *(unsigned int *)(a1 + 256), "gpi_resume");
      }
    }
    else
    {
      v14 = *(_QWORD *)(v7 + 1056);
      if ( v14 )
        goto LABEL_8;
    }
LABEL_75:
    v24 = 0;
    goto LABEL_76;
  }
  enable_irq(*(unsigned int *)(v7 + 808));
  *(_BYTE *)(v7 + 1474) = 1;
  if ( *v8 != 5 )
    goto LABEL_69;
  if ( *(_DWORD *)(v7 + 1068) >= 3u )
  {
    printk(&unk_11C9F, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_resume", v15, v16, v17);
    v18 = *(_QWORD *)(v7 + 1056);
    if ( !v18 )
      goto LABEL_15;
  }
  else
  {
    v18 = *(_QWORD *)(v7 + 1056);
    if ( !v18 )
      goto LABEL_15;
  }
  if ( *(_DWORD *)(v7 + 1064) >= 3u )
    ipc_log_string(v18, "ch:%u %s: deep sleep config\n", *(_DWORD *)(a1 + 256), "gpi_resume");
LABEL_15:
  v19 = *(_QWORD *)(a1 + 280);
  if ( *(_DWORD *)(v19 + 1068) >= 3u )
  {
    printk(&unk_128D8, v19 + 1076, *(unsigned int *)(a1 + 256), "gpi_deep_sleep_exit_config", v15, v16, v17);
    v20 = *(_QWORD *)(v19 + 1056);
    if ( !v20 )
      goto LABEL_19;
  }
  else
  {
    v20 = *(_QWORD *)(v19 + 1056);
    if ( !v20 )
      goto LABEL_19;
  }
  if ( *(_DWORD *)(v19 + 1064) >= 3u )
    ipc_log_string(v20, "ch:%u %s: enter\n", *(_DWORD *)(a1 + 256), "gpi_deep_sleep_exit_config");
LABEL_19:
  v21 = gpi_config_interrupts(v19, 0, 0);
  if ( !v21 )
  {
    v26 = gpi_alloc_ev_chan(v19);
    if ( v26 )
    {
      v24 = v26;
      if ( *(_DWORD *)(v19 + 1068) >= 2u )
      {
        printk(&unk_13729, v19 + 1076, *(unsigned int *)(a1 + 256), "gpi_deep_sleep_exit_config", v26, v30, v31);
        v32 = *(_QWORD *)(v19 + 1056);
        if ( v32 )
        {
LABEL_27:
          if ( *(_DWORD *)(v19 + 1064) >= 2u )
            ipc_log_string(
              v32,
              "ch:%u %s: error alloc_ev_chan:%d\n",
              *(_DWORD *)(a1 + 256),
              "gpi_deep_sleep_exit_config",
              v24);
        }
      }
      else
      {
        v32 = *(_QWORD *)(v19 + 1056);
        if ( v32 )
          goto LABEL_27;
      }
LABEL_64:
      gpi_disable_interrupts(v19);
      goto LABEL_65;
    }
    v33 = v19 + 8;
    v36 = gpi_alloc_chan(v19 + 8, 1, v27, v28, v29, v30, v31);
    if ( v36 )
    {
      v24 = v36;
      goto LABEL_41;
    }
    v37 = gpi_alloc_chan(v19 + 400, 1, v34, v35, v15, v16, v17);
    if ( v37 )
    {
      v24 = v37;
      v33 = v19 + 400;
LABEL_41:
      if ( *(_DWORD *)(v19 + 1068) >= 2u )
      {
        printk(&unk_1284E, v19 + 1076, *(unsigned int *)(v33 + 256), "gpi_deep_sleep_exit_config", v24, v16, v17);
        v39 = *(_QWORD *)(v19 + 1056);
        if ( v39 )
        {
LABEL_43:
          if ( *(_DWORD *)(v19 + 1064) >= 2u )
            ipc_log_string(
              v39,
              "ch:%u %s: Error allocating chan:%d\n",
              *(_DWORD *)(v33 + 256),
              "gpi_deep_sleep_exit_config",
              v24);
        }
      }
      else
      {
        v39 = *(_QWORD *)(v19 + 1056);
        if ( v39 )
          goto LABEL_43;
      }
      if ( v36 )
        goto LABEL_64;
      v40 = 0;
LABEL_62:
      gpi_reset_chan(a1, 4u, v34, v35, v15, v16, v17);
      if ( v40 )
        gpi_reset_chan(a1, 4u, v46, v47, v48, v49, v50);
      goto LABEL_64;
    }
    started = gpi_start_chan(v19 + 8, v38, v34, v35, v15, v16, v17);
    if ( started )
    {
      v43 = -1;
      v24 = started;
      goto LABEL_55;
    }
    v44 = gpi_start_chan(v19 + 400, v41, v34, v35, v15, v16, v17);
    if ( v44 )
    {
      v24 = v44;
      v43 = 0;
      v33 = v19 + 400;
LABEL_55:
      if ( *(_DWORD *)(v19 + 1068) >= 2u )
      {
        printk(&unk_1352B, v19 + 1076, *(unsigned int *)(v33 + 256), "gpi_deep_sleep_exit_config", v24, v16, v17);
        v45 = *(_QWORD *)(v19 + 1056);
        if ( v45 )
        {
LABEL_57:
          if ( *(_DWORD *)(v19 + 1064) >= 2u )
            ipc_log_string(
              v45,
              "ch:%u %s: Error start chan:%d\n",
              *(_DWORD *)(v33 + 256),
              "gpi_deep_sleep_exit_config",
              v24);
        }
      }
      else
      {
        v45 = *(_QWORD *)(v19 + 1056);
        if ( v45 )
          goto LABEL_57;
      }
      if ( !started )
      {
        do
        {
          ((void (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v19, a1, 2);
          ((void (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v19, a1, 3);
          ++v43;
        }
        while ( v43 >= 0 );
      }
      v40 = 1;
      goto LABEL_62;
    }
LABEL_69:
    if ( *(_DWORD *)(v7 + 944) != 3 )
    {
      raw_write_lock_irq(v7 + 948);
      *(_DWORD *)(v7 + 944) = 3;
      raw_write_unlock_irq(v7 + 948);
      goto LABEL_75;
    }
    if ( *(_DWORD *)(v7 + 1068) >= 3u )
    {
      printk(&unk_11CBE, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_resume", v15, v16, v17);
      v52 = *(_QWORD *)(v7 + 1056);
      if ( !v52 )
        goto LABEL_75;
    }
    else
    {
      v52 = *(_QWORD *)(v7 + 1056);
      if ( !v52 )
        goto LABEL_75;
    }
    if ( *(_DWORD *)(v7 + 1064) >= 3u )
      ipc_log_string(v52, "ch:%u %s: channel is already active\n", *(unsigned int *)(a1 + 256), "gpi_resume");
    goto LABEL_75;
  }
  v24 = v21;
  if ( *(_DWORD *)(v19 + 1068) >= 2u )
  {
    printk(&unk_131BB, v19 + 1076, *(unsigned int *)(a1 + 256), "gpi_deep_sleep_exit_config", v21, v22, v23);
    v25 = *(_QWORD *)(v19 + 1056);
    if ( !v25 )
      goto LABEL_65;
  }
  else
  {
    v25 = *(_QWORD *)(v19 + 1056);
    if ( !v25 )
      goto LABEL_65;
  }
  if ( *(_DWORD *)(v19 + 1064) >= 2u )
    ipc_log_string(
      v25,
      "ch:%u %s: error config. interrupts, ret:%d\n",
      *(_DWORD *)(a1 + 256),
      "gpi_deep_sleep_exit_config",
      v24);
LABEL_65:
  if ( *(_DWORD *)(v7 + 1068) >= 2u )
  {
    printk(&unk_14447, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_resume", v24, v22, v23);
    v51 = *(_QWORD *)(v7 + 1056);
    if ( !v51 )
      goto LABEL_76;
  }
  else
  {
    v51 = *(_QWORD *)(v7 + 1056);
    if ( !v51 )
      goto LABEL_76;
  }
  if ( *(_DWORD *)(v7 + 1064) >= 2u )
    ipc_log_string(v51, "ch:%u %s: Err deep sleep config, ret:%d\n", *(_DWORD *)(a1 + 256), "gpi_resume", v24);
LABEL_76:
  mutex_unlock(v7 + 888);
  return v24;
}
