__int64 __fastcall gpi_terminate_all(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x25
  __int64 v9; // x0
  __int64 started; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  int v17; // w8
  unsigned int v18; // w26
  int v19; // w28
  __int64 v20; // x19
  __int64 v21; // x27
  __int64 v22; // x22
  __int64 v23; // x21
  unsigned int v24; // w20
  __int64 v25; // x22
  __int64 v26; // x23
  __int64 v27; // x0
  unsigned int *v28; // x19
  __int64 v29; // x8
  __int64 v30; // x10
  char *v31; // x12
  __int64 v32; // x8
  char *v33; // x25
  char *v34; // x26
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x9
  __int64 v38; // x0
  unsigned int v39; // w19
  unsigned int v40; // w22
  __int64 v41; // x9
  __int64 v42; // x23
  unsigned int *v43; // x19
  unsigned int v44; // w0
  __int64 v45; // x5
  __int64 v46; // x6
  __int64 v47; // x21
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v52; // [xsp+10h] [xbp-30h]
  __int64 v53; // [xsp+18h] [xbp-28h]
  __int64 v54; // [xsp+20h] [xbp-20h]
  unsigned int v55; // [xsp+2Ch] [xbp-14h]
  __int64 v56; // [xsp+30h] [xbp-10h]
  char v57; // [xsp+3Ch] [xbp-4h]

  v7 = *(_QWORD *)(a1 + 280);
  if ( *(_DWORD *)(v7 + 1068) >= 3u )
  {
    printk(&unk_123DE, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_terminate_all", a5, a6, a7);
    v9 = *(_QWORD *)(v7 + 1056);
    if ( v9 )
    {
LABEL_3:
      if ( *(_DWORD *)(v7 + 1064) >= 3u )
        ipc_log_string(v9, "ch:%u %s: Enter\n", *(_DWORD *)(a1 + 256), "gpi_terminate_all");
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
  if ( v19 <= (int)v18 )
  {
LABEL_75:
    v24 = 0;
    goto LABEL_76;
  }
  v20 = v7 + 8;
  v21 = v18;
  if ( v18 <= 3 )
    v22 = 3;
  else
    v22 = v18;
  v57 = 0;
  v52 = v18;
  v56 = v7;
  v55 = v18;
  v53 = v22;
  v54 = v7 + 8;
  while ( 2 )
  {
    if ( v21 == v22 )
      goto LABEL_104;
    v23 = v20 + 392 * v21;
    raw_write_lock_irq(v7 + 948);
    *(_DWORD *)(v23 + 292) = 4;
    raw_write_unlock_irq(v7 + 948);
    v24 = ((__int64 (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v7, v23, 2);
    if ( v24 )
    {
      if ( *(_DWORD *)(v7 + 1068) >= 2u )
      {
        printk(&unk_12E37, v7 + 1076, *(unsigned int *)(v23 + 256), "gpi_terminate_all", v24, v15, v16);
        started = *(_QWORD *)(v7 + 1056);
        if ( started )
        {
LABEL_22:
          if ( *(_DWORD *)(v7 + 1064) >= 2u )
            started = ipc_log_string(
                        started,
                        "ch:%u %s: Error Stopping Chan:%d resetting\n",
                        *(_DWORD *)(v23 + 256),
                        "gpi_terminate_all",
                        v24);
        }
      }
      else
      {
        started = *(_QWORD *)(v7 + 1056);
        if ( started )
          goto LABEL_22;
      }
      v57 = 1;
      goto LABEL_17;
    }
    v25 = *(_QWORD *)(v23 + 280);
    v26 = *(_QWORD *)(v23 + 352);
    if ( *(_DWORD *)(v25 + 1068) >= 3u )
    {
      printk(&unk_123DE, v25 + 1076, *(unsigned int *)(v23 + 256), "gpi_noop_tre", v14, v15, v16);
      v27 = *(_QWORD *)(v25 + 1056);
      if ( v27 )
      {
LABEL_26:
        if ( *(_DWORD *)(v25 + 1064) >= 3u )
          ipc_log_string(v27, "ch:%u %s: Enter\n", *(_DWORD *)(v23 + 256), "gpi_noop_tre");
      }
    }
    else
    {
      v27 = *(_QWORD *)(v25 + 1056);
      if ( v27 )
        goto LABEL_26;
    }
    v28 = *(unsigned int **)(v26 + 48);
    v29 = *(_QWORD *)(v26 + 16);
    v30 = *(_QWORD *)(v26 + 32);
    v31 = (char *)v28 + v29;
    v32 = v29 - v30;
    v33 = &v31[-v30];
    v34 = (char *)(v32 + *(_QWORD *)(v26 + 40));
    if ( *(_DWORD *)(v25 + 1068) >= 3u )
    {
      printk(
        &unk_132AF,
        v25 + 1076,
        *(unsigned int *)(v23 + 256),
        "gpi_noop_tre",
        &v31[-v30],
        v32 + *(_QWORD *)(v26 + 40),
        v16);
      v35 = *(_QWORD *)(v25 + 1056);
      if ( !v35 )
        goto LABEL_52;
    }
    else
    {
      v35 = *(_QWORD *)(v25 + 1056);
      if ( !v35 )
        goto LABEL_52;
    }
    if ( *(_DWORD *)(v25 + 1064) >= 3u )
      ipc_log_string(
        v35,
        "ch:%u %s: local_rp:0x%0llx local_wp:0x%0llx\n",
        *(_DWORD *)(v23 + 256),
        "gpi_noop_tre",
        v33,
        v34);
LABEL_52:
    while ( v33 != v34 )
    {
      if ( *(_DWORD *)(v25 + 1068) >= 2u )
      {
        printk(&unk_13ED2, v25 + 1076, *(unsigned int *)(v23 + 256), "gpi_noop_tre", v33, *v28, v28[1]);
        v36 = *(_QWORD *)(v25 + 1056);
        if ( v36 )
        {
LABEL_40:
          if ( *(_DWORD *)(v25 + 1064) >= 2u )
            ipc_log_string(
              v36,
              "ch:%u %s: local_rp:%llu TRE: %08x %08x %08x %08x\n",
              *(_DWORD *)(v23 + 256),
              "gpi_noop_tre",
              v33,
              *v28,
              v28[1],
              v28[2],
              v28[3]);
        }
      }
      else
      {
        v36 = *(_QWORD *)(v25 + 1056);
        if ( v36 )
          goto LABEL_40;
      }
      v28[3] = v28[3] & 0x801 | 0x10000;
      v37 = *(unsigned int *)(v26 + 60);
      v28 = (unsigned int *)((char *)v28 + v37);
      if ( (unsigned __int64)v28 >= *(_QWORD *)(v26 + 32) + (unsigned __int64)*(unsigned int *)(v26 + 56) )
      {
        v33 = *(char **)(v26 + 16);
        v28 = *(unsigned int **)(v26 + 32);
      }
      else
      {
        v33 += v37;
      }
      if ( *(_DWORD *)(v25 + 1068) >= 3u )
      {
        printk(&unk_12D43, v25 + 1076, *(unsigned int *)(v23 + 256), "gpi_noop_tre", v33, v15, v16);
        v38 = *(_QWORD *)(v25 + 1056);
        if ( v38 )
          goto LABEL_47;
      }
      else
      {
        v38 = *(_QWORD *)(v25 + 1056);
        if ( v38 )
        {
LABEL_47:
          if ( *(_DWORD *)(v25 + 1064) >= 3u )
            ipc_log_string(v38, "ch:%u %s: local_rp:0x%0llx\n", *(_DWORD *)(v23 + 256), "gpi_noop_tre", v33);
        }
      }
    }
    if ( *(_DWORD *)(v25 + 1068) >= 3u )
      printk(&unk_12BDA, v25 + 1076, *(unsigned int *)(v23 + 256), "gpi_noop_tre", v14, v15, v16);
    started = *(_QWORD *)(v25 + 1056);
    v7 = v56;
    v18 = v55;
    v20 = v54;
    if ( started && *(_DWORD *)(v25 + 1064) >= 3u )
      started = ipc_log_string(started, "ch:%u %s: exit\n", *(_DWORD *)(v23 + 256), "gpi_noop_tre");
    v22 = v53;
LABEL_17:
    if ( v19 != (_DWORD)++v21 )
      continue;
    break;
  }
  if ( (v57 & 1) == 0 )
    goto LABEL_76;
  if ( (*(_BYTE *)(v7 + 1464) & 1) == 0 )
  {
    gpi_dump_debug_reg((unsigned int *)v7);
    *(_BYTE *)(v7 + 1464) = 1;
  }
  v39 = ((unsigned int)readl_relaxed(*(_QWORD *)(v23 + 296)) >> 20) & 0xF;
  if ( *(_DWORD *)(v7 + 1068) >= 2u )
  {
    printk(&unk_13B40, v7 + 1076, *(unsigned int *)(v23 + 256), "gpi_terminate_all", gpi_ch_state_str[v39], v15, v16);
    started = *(_QWORD *)(v7 + 1056);
    if ( started )
      goto LABEL_64;
  }
  else
  {
    started = *(_QWORD *)(v7 + 1056);
    if ( started )
    {
LABEL_64:
      if ( *(_DWORD *)(v7 + 1064) >= 2u )
        started = ipc_log_string(
                    started,
                    "ch:%u %s: CH state state:%s\n",
                    *(_DWORD *)(v23 + 256),
                    "gpi_terminate_all",
                    gpi_ch_state_str[v39]);
    }
  }
  v40 = v19 - v18;
  if ( v19 <= (int)v18 )
  {
LABEL_76:
    if ( v19 - 1 < (int)v18 )
      goto LABEL_99;
    while ( (unsigned int)--v19 <= 2 )
    {
      v47 = v7 + 8 + 392LL * (unsigned int)v19;
      started = gpi_start_chan(v47, v11, v12, v13, v14, v15, v16);
      if ( (_DWORD)started )
      {
        v24 = started;
        if ( *(_DWORD *)(v7 + 1068) >= 2u )
        {
          printk(
            &unk_14124,
            v7 + 1076,
            *(unsigned int *)(v47 + 256),
            "gpi_terminate_all",
            (unsigned int)started,
            v15,
            v16);
          v48 = *(_QWORD *)(v7 + 1056);
          if ( !v48 )
            goto LABEL_99;
        }
        else
        {
          v48 = *(_QWORD *)(v7 + 1056);
          if ( !v48 )
            goto LABEL_99;
        }
        if ( *(_DWORD *)(v7 + 1064) >= 2u )
          ipc_log_string(
            v48,
            "ch:%u %s: Error starting channel: %d\n",
            *(unsigned int *)(v47 + 256),
            "gpi_terminate_all",
            v24);
        goto LABEL_99;
      }
      if ( v19 <= (int)v18 )
      {
        v24 = 0;
        goto LABEL_99;
      }
    }
LABEL_104:
    __break(0x5512u);
    return gpi_reset_chan(started, v11);
  }
  if ( v18 <= 3 )
    v41 = 3;
  else
    v41 = v18;
  v42 = v41 - v52;
  v43 = (unsigned int *)(v7 + 392LL * v18 + 264);
  while ( 1 )
  {
    if ( !v42 )
      goto LABEL_104;
    v44 = gpi_reset_chan(v43 - 64, 3);
    if ( v44 )
    {
      v24 = v44;
      if ( *(_DWORD *)(v7 + 1068) >= 2u )
      {
        printk(&unk_140D1, v7 + 1076, *v43, "gpi_terminate_all", v44, v45, v46);
        v49 = *(_QWORD *)(v7 + 1056);
        if ( v49 )
        {
LABEL_89:
          if ( *(_DWORD *)(v7 + 1064) >= 2u )
            ipc_log_string(v49, "ch:%u %s: Error resetting channel: %d\n", *v43, "gpi_terminate_all", v24);
        }
      }
      else
      {
        v49 = *(_QWORD *)(v7 + 1056);
        if ( v49 )
          goto LABEL_89;
      }
      gpi_dump_debug_reg((unsigned int *)v7);
      goto LABEL_99;
    }
    started = gpi_alloc_chan(v43 - 64, 0);
    if ( (_DWORD)started )
      break;
    --v40;
    --v42;
    v43 += 98;
    if ( !v40 )
      goto LABEL_75;
  }
  v24 = started;
  if ( *(_DWORD *)(v7 + 1068) >= 2u )
  {
    printk(&unk_140FA, v7 + 1076, *v43, "gpi_terminate_all", (unsigned int)started, v15, v16);
    v50 = *(_QWORD *)(v7 + 1056);
    if ( v50 )
      goto LABEL_94;
  }
  else
  {
    v50 = *(_QWORD *)(v7 + 1056);
    if ( v50 )
    {
LABEL_94:
      if ( *(_DWORD *)(v7 + 1064) >= 2u )
        ipc_log_string(v50, "ch:%u %s: Error allocating channel: %d\n", *v43, "gpi_terminate_all", v24);
    }
  }
LABEL_99:
  mutex_unlock(v7 + 888);
  return v24;
}
