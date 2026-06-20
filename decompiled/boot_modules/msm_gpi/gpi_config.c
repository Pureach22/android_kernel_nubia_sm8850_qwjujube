__int64 __fastcall gpi_config(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x19
  unsigned int *v8; // x21
  int v10; // w22
  __int64 v11; // x0
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x4
  unsigned int v15; // w8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x0
  unsigned int v21; // w21
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  unsigned int v26; // w8
  __int64 v27; // x4
  __int64 v28; // x5
  unsigned int v29; // w8
  __int64 v30; // x0
  unsigned int v31; // w0
  __int64 v32; // x4
  __int64 v33; // x5
  __int64 v34; // x6
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v38; // x0
  unsigned int v39; // w0
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 v42; // x0
  unsigned int v43; // w0
  __int64 v44; // x2
  __int64 v45; // x3
  __int64 v46; // x4
  __int64 v47; // x5
  __int64 v48; // x6
  __int64 v49; // x0
  __int64 v50; // x22
  __int64 v51; // x2
  __int64 v52; // x3
  __int64 v53; // x4
  __int64 v54; // x5
  __int64 v55; // x6
  unsigned int v56; // w23
  unsigned int v57; // w0
  __int64 v58; // x1
  __int64 v59; // x0
  int v60; // w22
  __int64 v61; // x1
  unsigned int started; // w23
  __int64 v63; // x0
  __int64 v64; // x2
  __int64 v65; // x3
  __int64 v66; // x4
  __int64 v67; // x5
  __int64 v68; // x6

  v7 = *(_QWORD *)(a1 + 280);
  v8 = *(unsigned int **)(a1 + 104);
  v10 = *(_DWORD *)(*(_QWORD *)(v7 + 792) + 436LL);
  if ( *(_DWORD *)(v7 + 1068) >= 3u )
  {
    printk(&unk_128D8, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_config", a5, a6, a7);
    v11 = *(_QWORD *)(v7 + 1056);
    if ( !v11 )
      goto LABEL_5;
  }
  else
  {
    v11 = *(_QWORD *)(v7 + 1056);
    if ( !v11 )
      goto LABEL_5;
  }
  if ( *(_DWORD *)(v7 + 1064) >= 3u )
    ipc_log_string(v11, "ch:%u %s: enter\n", *(_DWORD *)(a1 + 256), "gpi_config");
LABEL_5:
  if ( v8 )
  {
    mutex_lock(v7 + 888);
    v14 = *v8;
    v15 = *(_DWORD *)(v7 + 1068);
    if ( (int)v14 <= 2 )
    {
      if ( (_DWORD)v14 != 1 )
      {
        if ( (_DWORD)v14 == 2 )
        {
          if ( v15 >= 3 )
          {
            printk(&unk_13CED, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_config", v14, v12, v13);
            v16 = *(_QWORD *)(v7 + 1056);
            if ( v16 )
            {
LABEL_11:
              if ( *(_DWORD *)(v7 + 1064) >= 3u )
                ipc_log_string(v16, "ch:%u %s: sending UART SW STALE cmd\n", *(_DWORD *)(a1 + 256), "gpi_config");
            }
          }
          else
          {
            v16 = *(_QWORD *)(v7 + 1056);
            if ( v16 )
              goto LABEL_11;
          }
          v17 = v7;
          v18 = a1;
          v19 = 5;
LABEL_51:
          v21 = ((__int64 (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v17, v18, v19);
          goto LABEL_52;
        }
LABEL_25:
        if ( v15 >= 2 )
        {
          printk(&unk_13D14, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_config", v14, v12, v13);
          v23 = *(_QWORD *)(v7 + 1056);
          if ( v23 )
          {
LABEL_27:
            if ( *(_DWORD *)(v7 + 1064) >= 2u )
              ipc_log_string(v23, "ch:%u %s: unsupported ctrl cmd:%d\n", *(_DWORD *)(a1 + 256), "gpi_config", *v8);
          }
        }
        else
        {
          v23 = *(_QWORD *)(v7 + 1056);
          if ( v23 )
            goto LABEL_27;
        }
LABEL_29:
        v21 = -22;
LABEL_52:
        mutex_unlock(v7 + 888);
        return v21;
      }
      if ( v15 >= 3 )
      {
        printk(&unk_14AF1, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_config", v14, v12, v13);
        v24 = *(_QWORD *)(v7 + 1056);
        if ( !v24 )
          goto LABEL_34;
      }
      else
      {
        v24 = *(_QWORD *)(v7 + 1056);
        if ( !v24 )
          goto LABEL_34;
      }
      if ( *(_DWORD *)(v7 + 1064) >= 3u )
        ipc_log_string(v24, "ch:%u %s: cmd: msm_gpi_init\n", *(_DWORD *)(a1 + 256), "gpi_config");
LABEL_34:
      *(_QWORD *)(a1 + 368) = *((_QWORD *)v8 + 1);
      v25 = *((_QWORD *)v8 + 2);
      *(_DWORD *)(a1 + 292) = 1;
      *(_QWORD *)(a1 + 376) = v25;
      if ( *(_DWORD *)(v7 + 300) != 1 || *(_DWORD *)(v7 + 692) != 1 )
      {
        v21 = 0;
        goto LABEL_52;
      }
      v26 = *(_DWORD *)(v7 + 280);
      v27 = *(unsigned int *)(v7 + 276);
      v28 = *(unsigned int *)(v7 + 668);
      if ( v26 >= *(_DWORD *)(v7 + 672) )
        v26 = *(_DWORD *)(v7 + 672);
      *(_DWORD *)(v7 + 800) = v26;
      if ( (_DWORD)v27 != (_DWORD)v28 )
      {
        if ( *(_DWORD *)(v7 + 1068) >= 2u )
        {
          printk(&unk_12945, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_config", v27, v28, v13);
          v38 = *(_QWORD *)(v7 + 1056);
          if ( !v38 )
            goto LABEL_29;
        }
        else
        {
          v38 = *(_QWORD *)(v7 + 1056);
          if ( !v38 )
            goto LABEL_29;
        }
        if ( *(_DWORD *)(v7 + 1064) >= 2u )
          ipc_log_string(
            v38,
            "ch:%u %s: protocol did not match protocol %u != %u\n",
            *(_DWORD *)(a1 + 256),
            "gpi_config",
            *(_DWORD *)(v7 + 276),
            *(_DWORD *)(v7 + 668));
        goto LABEL_29;
      }
      v29 = *(_DWORD *)(v7 + 352);
      v30 = *(_QWORD *)(v7 + 960);
      if ( v29 <= *(_DWORD *)(v7 + 744) )
        v29 = *(_DWORD *)(v7 + 744);
      *(_DWORD *)(v7 + 804) = *(_DWORD *)(a1 + 268);
      v31 = gpi_alloc_ring(v30, v29 << v10, v7);
      if ( v31 )
      {
        v21 = v31;
        if ( *(_DWORD *)(v7 + 1068) >= 2u )
        {
          printk(&unk_136FB, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_config", v32, v33, v34);
          v35 = *(_QWORD *)(v7 + 1056);
          if ( !v35 )
            goto LABEL_52;
        }
        else
        {
          v35 = *(_QWORD *)(v7 + 1056);
          if ( !v35 )
            goto LABEL_52;
        }
        if ( *(_DWORD *)(v7 + 1064) >= 2u )
          ipc_log_string(v35, "ch:%u %s: error allocating mem for ev ring\n", *(_DWORD *)(a1 + 256), "gpi_config");
        goto LABEL_52;
      }
      raw_write_lock_irq(v7 + 948);
      *(_DWORD *)(v7 + 944) = 2;
      raw_write_unlock_irq(v7 + 948);
      v39 = gpi_config_interrupts(v7, 0, 0);
      if ( v39 )
      {
        v21 = v39;
        if ( *(_DWORD *)(v7 + 1068) >= 2u )
        {
          printk(&unk_131BB, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_config", v39, v40, v41);
          v42 = *(_QWORD *)(v7 + 1056);
          if ( v42 )
          {
LABEL_76:
            if ( *(_DWORD *)(v7 + 1064) >= 2u )
              ipc_log_string(
                v42,
                "ch:%u %s: error config. interrupts, ret:%d\n",
                *(_DWORD *)(a1 + 256),
                "gpi_config",
                v21);
          }
        }
        else
        {
          v42 = *(_QWORD *)(v7 + 1056);
          if ( v42 )
            goto LABEL_76;
        }
LABEL_111:
        gpi_free_ring(*(_QWORD *)(v7 + 960), v7);
        goto LABEL_52;
      }
      v43 = gpi_alloc_ev_chan(v7);
      if ( v43 )
      {
        v21 = v43;
        if ( *(_DWORD *)(v7 + 1068) >= 2u )
        {
          printk(&unk_13729, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_config", v43, v47, v48);
          v49 = *(_QWORD *)(v7 + 1056);
          if ( v49 )
          {
LABEL_81:
            if ( *(_DWORD *)(v7 + 1064) >= 2u )
              ipc_log_string(v49, "ch:%u %s: error alloc_ev_chan:%d\n", *(_DWORD *)(a1 + 256), "gpi_config", v21);
          }
        }
        else
        {
          v49 = *(_QWORD *)(v7 + 1056);
          if ( v49 )
            goto LABEL_81;
        }
LABEL_110:
        gpi_disable_interrupts(v7);
        goto LABEL_111;
      }
      v50 = v7 + 8;
      v56 = gpi_alloc_chan(v7 + 8, 1, v44, v45, v46, v47, v48);
      if ( v56 )
      {
        v21 = v56;
        goto LABEL_91;
      }
      v57 = gpi_alloc_chan(v7 + 400, 1, v51, v52, v53, v54, v55);
      if ( v57 )
      {
        v21 = v57;
        v50 = v7 + 400;
LABEL_91:
        if ( *(_DWORD *)(v7 + 1068) >= 2u )
        {
          printk(&unk_1284E, v7 + 1076, *(unsigned int *)(v50 + 256), "gpi_config", v21, v54, v55);
          v59 = *(_QWORD *)(v7 + 1056);
          if ( v59 )
          {
LABEL_93:
            if ( *(_DWORD *)(v7 + 1064) >= 2u )
              ipc_log_string(v59, "ch:%u %s: Error allocating chan:%d\n", *(_DWORD *)(v50 + 256), "gpi_config", v21);
          }
        }
        else
        {
          v59 = *(_QWORD *)(v7 + 1056);
          if ( v59 )
            goto LABEL_93;
        }
        if ( v56 )
          goto LABEL_110;
        v60 = 0;
LABEL_108:
        gpi_reset_chan(a1, 4u, v51, v52, v53, v54, v55);
        if ( v60 )
          gpi_reset_chan(a1, 4u, v64, v65, v66, v67, v68);
        goto LABEL_110;
      }
      started = gpi_start_chan(v7 + 8, v58, v51, v52, v53, v54, v55);
      v21 = started;
      if ( !started )
      {
        v21 = gpi_start_chan(v7 + 400, v61, v51, v52, v53, v54, v55);
        v50 = v7 + 400;
        if ( !v21 )
          goto LABEL_52;
      }
      if ( *(_DWORD *)(v7 + 1068) >= 2u )
      {
        printk(&unk_1352B, v7 + 1076, *(unsigned int *)(v50 + 256), "gpi_config", v21, v54, v55);
        v63 = *(_QWORD *)(v7 + 1056);
        if ( v63 )
        {
LABEL_103:
          if ( *(_DWORD *)(v7 + 1064) >= 2u )
            ipc_log_string(v63, "ch:%u %s: Error start chan:%d\n", *(_DWORD *)(v50 + 256), "gpi_config", v21);
        }
      }
      else
      {
        v63 = *(_QWORD *)(v7 + 1056);
        if ( v63 )
          goto LABEL_103;
      }
      if ( !started )
      {
        ((void (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v7, a1, 2);
        ((void (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v7, a1, 3);
      }
      v60 = 1;
      goto LABEL_108;
    }
    if ( (_DWORD)v14 != 3 )
    {
      if ( (_DWORD)v14 != 4 )
        goto LABEL_25;
      if ( v15 >= 3 )
      {
        printk(&unk_143D3, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_config", v14, v12, v13);
        v22 = *(_QWORD *)(v7 + 1056);
        if ( v22 )
        {
LABEL_22:
          if ( *(_DWORD *)(v7 + 1064) >= 3u )
            ipc_log_string(v22, "ch:%u %s: sending UART RFR READY NOT READY cmd\n", *(_DWORD *)(a1 + 256), "gpi_config");
        }
      }
      else
      {
        v22 = *(_QWORD *)(v7 + 1056);
        if ( v22 )
          goto LABEL_22;
      }
      v17 = v7;
      v18 = a1;
      v19 = 7;
      goto LABEL_51;
    }
    if ( v15 >= 3 )
    {
      printk(&unk_1374D, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_config", v14, v12, v13);
      v36 = *(_QWORD *)(v7 + 1056);
      if ( v36 )
      {
LABEL_48:
        if ( *(_DWORD *)(v7 + 1064) >= 3u )
          ipc_log_string(v36, "ch:%u %s: sending UART RFR READY cmd\n", *(_DWORD *)(a1 + 256), "gpi_config");
      }
    }
    else
    {
      v36 = *(_QWORD *)(v7 + 1056);
      if ( v36 )
        goto LABEL_48;
    }
    v17 = v7;
    v18 = a1;
    v19 = 6;
    goto LABEL_51;
  }
  if ( *(_DWORD *)(v7 + 1068) >= 2u )
  {
    printk(&unk_14C3D, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_config", a5, a6, a7);
    v20 = *(_QWORD *)(v7 + 1056);
    if ( !v20 )
      return (unsigned int)-22;
  }
  else
  {
    v20 = *(_QWORD *)(v7 + 1056);
    if ( !v20 )
      return (unsigned int)-22;
  }
  if ( *(_DWORD *)(v7 + 1064) < 2u )
    return (unsigned int)-22;
  ipc_log_string(v20, "ch:%u %s: no config ctrl data provided", *(_DWORD *)(a1 + 256), "gpi_config");
  return (unsigned int)-22;
}
