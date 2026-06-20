__int64 __fastcall gpi_q2spi_terminate_all(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x19
  __int64 v9; // x0
  __int64 started; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  int v17; // w8
  unsigned int v18; // w24
  int v19; // w25
  unsigned int v20; // w27
  __int64 v21; // x9
  char v22; // w22
  __int64 v23; // x28
  unsigned int *v24; // x20
  __int64 v25; // x8
  unsigned int v26; // w23
  unsigned int v27; // w23
  unsigned int v28; // w23
  __int64 v29; // x9
  __int64 v30; // x22
  unsigned int *v31; // x21
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x4
  __int64 v35; // x5
  __int64 v36; // x6
  __int64 v37; // x20
  __int64 v38; // x8
  __int64 v39; // x2
  const char *v40; // x1
  __int64 v41; // x8
  int v42; // w20
  int v43; // w20
  int v44; // w20
  unsigned int v45; // w20
  int v47; // w21
  int v48; // w20
  int v49; // w20

  v7 = *(_QWORD *)(a1 + 280);
  if ( *(_DWORD *)(v7 + 1068) >= 3u )
  {
    printk(&unk_123DE, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_q2spi_terminate_all", a5, a6, a7);
    v9 = *(_QWORD *)(v7 + 1056);
    if ( v9 )
    {
LABEL_3:
      if ( *(_DWORD *)(v7 + 1064) >= 3u )
        ipc_log_string(v9, "ch:%u %s: Enter\n", *(_DWORD *)(a1 + 256), "gpi_q2spi_terminate_all");
    }
  }
  else
  {
    v9 = *(_QWORD *)(v7 + 1056);
    if ( v9 )
      goto LABEL_3;
  }
  started = mutex_lock(v7 + 888);
  v17 = *(_DWORD *)(v7 + 804);
  if ( v17 == 2 )
    v18 = *(_DWORD *)(a1 + 256);
  else
    v18 = 0;
  if ( v17 == 2 )
    v19 = v18 + 1;
  else
    v19 = 2;
  v20 = v19 - v18;
  if ( v19 <= (int)v18 )
  {
LABEL_35:
    started = 0;
    goto LABEL_36;
  }
  if ( v18 <= 3 )
    v21 = 3;
  else
    v21 = v18;
  v22 = 0;
  v23 = v21 - v18;
  v24 = (unsigned int *)(v7 + 392LL * v18 + 264);
  do
  {
    if ( !v23 )
      goto LABEL_65;
    raw_write_lock_irq(v7 + 948);
    v24[9] = 4;
    raw_write_unlock_irq(v7 + 948);
    started = ((__int64 (__fastcall *)(__int64, unsigned int *, __int64))gpi_send_cmd)(v7, v24 - 64, 2);
    if ( (_DWORD)started )
    {
      if ( *(_DWORD *)(v7 + 1068) >= 2u )
      {
        v27 = started;
        printk(&unk_12E37, v7 + 1076, *v24, "gpi_q2spi_terminate_all", (unsigned int)started, v15, v16);
        started = v27;
        v25 = *(_QWORD *)(v7 + 1056);
        if ( v25 )
        {
LABEL_22:
          if ( *(_DWORD *)(v7 + 1064) >= 2u )
          {
            v26 = started;
            ipc_log_string(
              v25,
              "ch:%u %s: Error Stopping Chan:%d resetting\n",
              *v24,
              "gpi_q2spi_terminate_all",
              started);
            started = v26;
          }
        }
      }
      else
      {
        v25 = *(_QWORD *)(v7 + 1056);
        if ( v25 )
          goto LABEL_22;
      }
      v22 = 1;
    }
    --v20;
    --v23;
    v24 += 98;
  }
  while ( v20 );
  v28 = v19 - v18;
  if ( v19 <= (int)v18 || (v22 & 1) == 0 )
  {
LABEL_36:
    if ( v19 - 1 < (int)v18 )
      goto LABEL_56;
    while ( (unsigned int)--v19 <= 2 )
    {
      v37 = v7 + 8 + 392LL * (unsigned int)v19;
      started = gpi_start_chan(v37, v11, v12, v13, v14, v15, v16);
      if ( (_DWORD)started )
      {
        if ( *(_DWORD *)(v7 + 1068) >= 2u )
        {
          v47 = started;
          printk(
            &unk_11ED1,
            v7 + 1076,
            *(unsigned int *)(v37 + 256),
            "gpi_q2spi_terminate_all",
            (unsigned int)started,
            v15,
            v16);
          LODWORD(started) = v47;
          v38 = *(_QWORD *)(v7 + 1056);
          if ( !v38 )
            goto LABEL_56;
        }
        else
        {
          v38 = *(_QWORD *)(v7 + 1056);
          if ( !v38 )
            goto LABEL_56;
        }
        if ( *(_DWORD *)(v7 + 1064) < 2u )
          goto LABEL_56;
        v39 = *(unsigned int *)(v37 + 256);
        v40 = "ch:%u %s: Error Starting Channel ret:%d\n";
        goto LABEL_55;
      }
      if ( v19 <= (int)v18 )
      {
        LODWORD(started) = 0;
        goto LABEL_56;
      }
    }
LABEL_65:
    __break(0x5512u);
    return gpi_desc_free(started);
  }
  if ( v18 <= 3 )
    v29 = 3;
  else
    v29 = v18;
  v30 = v29 - v18;
  v31 = (unsigned int *)(v7 + 392LL * v18 + 264);
  while ( 1 )
  {
    if ( !v30 )
      goto LABEL_65;
    LODWORD(started) = gpi_reset_chan((__int64)(v31 - 64), 3u, v12, v13, v14, v15, v16);
    if ( (_DWORD)started )
    {
      if ( *(_DWORD *)(v7 + 1068) >= 2u )
      {
        v48 = started;
        printk(&unk_11B2B, v7 + 1076, *v31, "gpi_q2spi_terminate_all", (unsigned int)started, v35, v36);
        LODWORD(started) = v48;
        v41 = *(_QWORD *)(v7 + 1056);
        if ( v41 )
        {
LABEL_47:
          if ( *(_DWORD *)(v7 + 1064) >= 2u )
          {
            v42 = started;
            ipc_log_string(v41, "ch:%u %s: Error resetting channel ret:%d\n", *v31, "gpi_q2spi_terminate_all", started);
            LODWORD(started) = v42;
          }
        }
      }
      else
      {
        v41 = *(_QWORD *)(v7 + 1056);
        if ( v41 )
          goto LABEL_47;
      }
      if ( (*(_BYTE *)(v7 + 1464) & 1) == 0 )
      {
        v43 = started;
        gpi_dump_debug_reg((unsigned int *)v7);
        LODWORD(started) = v43;
        *(_BYTE *)(v7 + 1464) = 1;
      }
      goto LABEL_56;
    }
    started = gpi_alloc_chan((__int64)(v31 - 64), 0, v32, v33, v34, v35, v36);
    if ( (_DWORD)started )
      break;
    --v28;
    --v30;
    v31 += 98;
    if ( !v28 )
      goto LABEL_35;
  }
  if ( *(_DWORD *)(v7 + 1068) >= 2u )
  {
    v49 = started;
    printk(&unk_13D95, v7 + 1076, *v31, "gpi_q2spi_terminate_all", (unsigned int)started, v15, v16);
    LODWORD(started) = v49;
    v38 = *(_QWORD *)(v7 + 1056);
    if ( !v38 )
      goto LABEL_56;
  }
  else
  {
    v38 = *(_QWORD *)(v7 + 1056);
    if ( !v38 )
      goto LABEL_56;
  }
  if ( *(_DWORD *)(v7 + 1064) >= 2u )
  {
    v39 = *v31;
    v40 = "ch:%u %s: Error alloc_channel ret:%d\n";
LABEL_55:
    v44 = started;
    ipc_log_string(v38, v40, v39, "gpi_q2spi_terminate_all", (unsigned int)started);
    LODWORD(started) = v44;
  }
LABEL_56:
  v45 = started;
  mutex_unlock(v7 + 888);
  return v45;
}
