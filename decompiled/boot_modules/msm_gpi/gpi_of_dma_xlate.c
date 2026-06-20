__int64 __fastcall gpi_of_dma_xlate(_DWORD *a1, __int64 a2)
{
  int v2; // w3
  __int64 v3; // x21
  __int64 v4; // x8
  unsigned int v5; // w19
  __int64 result; // x0
  _DWORD *v7; // x20
  int v8; // w10
  int v9; // w8
  int v10; // w3
  __int64 v11; // x12
  __int64 v12; // x22
  __int64 v13; // x0
  int v14; // w10
  unsigned int v15; // w11
  _DWORD *v16; // x14
  int v17; // w7
  int v18; // w5
  int v19; // w6
  __int64 v20; // x0
  __int64 slave_channel; // x19
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x14
  __int64 v28; // x0
  _DWORD *v29; // x19
  int v30; // w20

  v2 = a1[2];
  v3 = *(_QWORD *)(a2 + 48);
  if ( v2 <= 4 )
  {
    if ( *(_DWORD *)(v3 + 484) >= 2u )
    {
      v29 = a1;
      dev_err(*(_QWORD *)(v3 + 392), "%s: gpii require minimum 6 args, client passed:%d args\n", "gpi_of_dma_xlate", v2);
      a1 = v29;
      v4 = *(_QWORD *)(v3 + 472);
      if ( v4 )
      {
LABEL_4:
        if ( *(_DWORD *)(v3 + 480) >= 2u )
          ipc_log_string(
            v4,
            "%s: gpii require minimum 6 args, client passed:%d args\n",
            "gpi_of_dma_xlate",
            (unsigned int)a1[2]);
      }
    }
    else
    {
      v4 = *(_QWORD *)(v3 + 472);
      if ( v4 )
        goto LABEL_4;
    }
    return 0;
  }
  v5 = a1[3];
  if ( v5 < 2 )
  {
    v7 = a1;
    mutex_lock(v3 + 528);
    v8 = (v7[7] >> 1) & 0xF;
    v9 = v7[4];
    if ( v8 )
    {
      v10 = v8 - 1;
      if ( ((*(_DWORD *)(v3 + 432) >> (v8 - 1)) & 1) != 0 )
      {
        v11 = *(_QWORD *)(v3 + 464);
        goto LABEL_14;
      }
    }
    else
    {
      v14 = *(_DWORD *)(v3 + 424);
      if ( v14 )
      {
        v15 = *(_DWORD *)(v3 + 428);
        v10 = 0;
        while ( 1 )
        {
          if ( ((v15 >> v10) & 1) != 0 )
          {
            v11 = *(_QWORD *)(v3 + 464);
            v16 = (_DWORD *)(v11 + 1480LL * v10);
            if ( v16[120] )
            {
              if ( v16[165] == v9 )
                break;
            }
            if ( v16[22] && v16[67] == v9 )
              break;
          }
          if ( v14 == ++v10 )
          {
            v10 = 0;
            while ( 1 )
            {
              if ( ((v15 >> v10) & 1) != 0 )
              {
                v11 = *(_QWORD *)(v3 + 464);
                v27 = v11 + 1480LL * v10;
                if ( !*(_DWORD *)(v27 + 88) && !*(_DWORD *)(v27 + 480) )
                  goto LABEL_48;
              }
              if ( v14 == ++v10 )
                goto LABEL_49;
            }
          }
        }
LABEL_48:
        if ( (v10 & 0x80000000) == 0 )
        {
LABEL_14:
          v12 = v11 + 1480LL * (unsigned int)v10 + 392LL * v5;
          if ( *(_DWORD *)(v12 + 88) )
          {
            if ( *(_DWORD *)(v3 + 484) >= 2u )
            {
              v30 = v10;
              dev_err(
                *(_QWORD *)(v3 + 392),
                "%s: gpii:%d chid:%d seid:%d already configured\n",
                "gpi_of_dma_xlate",
                v10,
                v5,
                *(_DWORD *)(v12 + 268));
              v10 = v30;
              v13 = *(_QWORD *)(v3 + 472);
              if ( v13 )
              {
LABEL_17:
                if ( *(_DWORD *)(v3 + 480) >= 2u )
                  ipc_log_string(
                    v13,
                    "%s: gpii:%d chid:%d seid:%d already configured\n",
                    "gpi_of_dma_xlate",
                    v10,
                    v5,
                    *(_DWORD *)(v12 + 268));
              }
            }
            else
            {
              v13 = *(_QWORD *)(v3 + 472);
              if ( v13 )
                goto LABEL_17;
            }
LABEL_53:
            mutex_unlock(v3 + 528);
            return 0;
          }
          *(_DWORD *)(v12 + 268) = v9;
          v17 = v7[5];
          *(_DWORD *)(v12 + 276) = v17;
          if ( v17 == 14 )
            *(_BYTE *)(v12 + 272) |= 1u;
          v18 = v7[6];
          *(_DWORD *)(v12 + 352) = v18;
          v19 = v7[7] & 1;
          *(_DWORD *)(v12 + 280) = v19;
          v20 = *(_QWORD *)(v3 + 472);
          if ( v20 && *(_DWORD *)(v3 + 480) )
            ipc_log_string(
              v20,
              "%s: client req gpii:%u chid:%u #_tre:%u prio:%u proto:%u SE:%d init_config:%d\n",
              "gpi_of_dma_xlate",
              v10,
              v5,
              v18,
              v19,
              v17,
              v9,
              *(_BYTE *)(v12 + 272) & 1);
          slave_channel = dma_get_slave_channel(v12 + 8);
          if ( *(_BYTE *)(v3 + 496) != 1 || (readl_relaxed(*(unsigned int **)(v12 + 304)) & 0xF00000) == 0 )
            goto LABEL_42;
          if ( !*(_DWORD *)(v12 + 264) )
            gpi_config_interrupts(*(_QWORD *)(v12 + 288), 0, 0);
          if ( !(unsigned int)gpi_cleanup_hw_channel(slave_channel) )
          {
LABEL_42:
            mutex_unlock(v3 + 528);
            return slave_channel;
          }
          v25 = *(_QWORD *)(v12 + 288);
          if ( *(_DWORD *)(v25 + 1068) >= 2u )
          {
            printk(&unk_13AF1, v25 + 1076, *(unsigned int *)(v12 + 264), "gpi_of_dma_xlate", v22, v23, v24);
            v25 = *(_QWORD *)(v12 + 288);
            v26 = *(_QWORD *)(v25 + 1056);
            if ( !v26 )
              goto LABEL_53;
          }
          else
          {
            v26 = *(_QWORD *)(v25 + 1056);
            if ( !v26 )
              goto LABEL_53;
          }
          if ( *(_DWORD *)(v25 + 1064) >= 2u )
            ipc_log_string(v26, "ch:%u %s: gpi_cleanup_hw_channel failed\n", *(_DWORD *)(v12 + 264), "gpi_of_dma_xlate");
          goto LABEL_53;
        }
      }
    }
LABEL_49:
    if ( *(_DWORD *)(v3 + 484) >= 2u )
    {
      dev_err(*(_QWORD *)(v3 + 392), "%s: no available gpii instances\n", "gpi_of_dma_xlate");
      v28 = *(_QWORD *)(v3 + 472);
      if ( !v28 )
        goto LABEL_53;
    }
    else
    {
      v28 = *(_QWORD *)(v3 + 472);
      if ( !v28 )
        goto LABEL_53;
    }
    if ( *(_DWORD *)(v3 + 480) >= 2u )
      ipc_log_string(v28, "%s: no available gpii instances\n", "gpi_of_dma_xlate");
    goto LABEL_53;
  }
  if ( *(_DWORD *)(v3 + 484) < 2u )
  {
    result = *(_QWORD *)(v3 + 472);
    if ( !result )
      return result;
    goto LABEL_9;
  }
  dev_err(*(_QWORD *)(v3 + 392), "%s: gpii channel:%d not valid\n", "gpi_of_dma_xlate", v5);
  result = *(_QWORD *)(v3 + 472);
  if ( result )
  {
LABEL_9:
    if ( *(_DWORD *)(v3 + 480) >= 2u )
      ipc_log_string(result, "%s: gpii channel:%d not valid\n", "gpi_of_dma_xlate", v5);
    return 0;
  }
  return result;
}
