__int64 __fastcall gpi_free_chan_resources(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v8; // x19
  __int64 v9; // x0
  int v10; // w21
  unsigned int v11; // w0
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x8
  unsigned int v15; // w0
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x8
  _QWORD *v22; // x21
  __int64 v23; // x1
  __int64 v24; // x9
  _QWORD *v25; // x10
  _QWORD *v26; // x11
  __int64 v27; // x9
  _QWORD *v28; // x10
  _QWORD *v29; // x11
  __int64 v30; // x9
  _QWORD *v31; // x10
  _QWORD *v32; // x11
  __int64 v33; // x9
  _QWORD *v34; // x10
  _QWORD *v35; // x11
  __int64 v36; // x9
  _QWORD *v37; // x10
  _QWORD *v38; // x11
  _QWORD *i; // x8
  __int64 v40; // x4
  __int64 v41; // x5
  __int64 v42; // x6
  __int64 v43; // x0
  int v44; // w20
  _QWORD *v45; // x20
  _QWORD *v46; // x20
  __int64 result; // x0
  unsigned int v48; // w21
  unsigned int v49; // w21
  _QWORD *v50; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v51; // [xsp+10h] [xbp-10h]
  __int64 v52; // [xsp+18h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 280);
  if ( *(_DWORD *)(v8 + 1068) >= 3u )
  {
    printk(&unk_128D8, v8 + 1076, *(unsigned int *)(a1 + 256), "gpi_free_chan_resources", a5, a6, a7);
    v9 = *(_QWORD *)(v8 + 1056);
    if ( !v9 )
      goto LABEL_5;
  }
  else
  {
    v9 = *(_QWORD *)(v8 + 1056);
    if ( !v9 )
      goto LABEL_5;
  }
  if ( *(_DWORD *)(v8 + 1064) >= 3u )
    ipc_log_string(v9, "ch:%u %s: enter\n", *(_DWORD *)(a1 + 256), "gpi_free_chan_resources");
LABEL_5:
  mutex_lock(v8 + 888);
  v10 = *(_DWORD *)(a1 + 292);
  raw_write_lock_irq(v8 + 948);
  *(_DWORD *)(a1 + 292) = 4;
  raw_write_unlock_irq(v8 + 948);
  if ( v10 != 3 )
    goto LABEL_17;
  v11 = ((__int64 (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v8, a1, 2);
  if ( v11 )
  {
    if ( *(_DWORD *)(v8 + 1068) >= 2u )
    {
      v48 = v11;
      printk(&unk_13504, v8 + 1076, *(unsigned int *)(a1 + 256), "gpi_free_chan_resources", v11, v12, v13);
      v11 = v48;
      v14 = *(_QWORD *)(v8 + 1056);
      if ( !v14 )
        goto LABEL_11;
    }
    else
    {
      v14 = *(_QWORD *)(v8 + 1056);
      if ( !v14 )
        goto LABEL_11;
    }
    if ( *(_DWORD *)(v8 + 1064) >= 2u )
      ipc_log_string(
        v14,
        "ch:%u %s: error stopping channel:%d\n",
        *(_DWORD *)(a1 + 256),
        "gpi_free_chan_resources",
        v11);
  }
LABEL_11:
  v15 = ((__int64 (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v8, a1, 3);
  if ( v15 )
  {
    if ( *(_DWORD *)(v8 + 1068) >= 2u )
    {
      v49 = v15;
      printk(&unk_13775, v8 + 1076, *(unsigned int *)(a1 + 256), "gpi_free_chan_resources", v15, v19, v20);
      v15 = v49;
      v21 = *(_QWORD *)(v8 + 1056);
      if ( v21 )
      {
LABEL_14:
        if ( *(_DWORD *)(v8 + 1064) >= 2u )
          ipc_log_string(
            v21,
            "ch:%u %s: error resetting channel:%d\n",
            *(_DWORD *)(a1 + 256),
            "gpi_free_chan_resources",
            v15);
      }
    }
    else
    {
      v21 = *(_QWORD *)(v8 + 1056);
      if ( v21 )
        goto LABEL_14;
    }
  }
  gpi_reset_chan(a1, 4u, v16, v17, v18, v19, v20);
LABEL_17:
  v22 = *(_QWORD **)(a1 + 352);
  dma_free_attrs(*(_QWORD *)(*(_QWORD *)(v8 + 792) + 392LL), v22[1], *v22, v22[3], 0);
  v22[7] = 0;
  v22[8] = 0;
  v22[5] = 0;
  v22[6] = 0;
  v22[3] = 0;
  v22[4] = 0;
  v22[1] = 0;
  v22[2] = 0;
  *v22 = 0;
  v50 = &v50;
  v51 = &v50;
  v23 = raw_spin_lock_irqsave(a1 + 160);
  v24 = *(_QWORD *)(a1 + 168);
  if ( v24 != a1 + 168 )
  {
    v25 = v51;
    v26 = *(_QWORD **)(a1 + 176);
    *(_QWORD *)(v24 + 8) = v51;
    *v25 = v24;
    *v26 = &v50;
    v51 = v26;
    *(_QWORD *)(a1 + 168) = a1 + 168;
    *(_QWORD *)(a1 + 176) = a1 + 168;
  }
  v27 = *(_QWORD *)(a1 + 184);
  if ( v27 != a1 + 184 )
  {
    v28 = v51;
    v29 = *(_QWORD **)(a1 + 192);
    *(_QWORD *)(v27 + 8) = v51;
    *v28 = v27;
    *v29 = &v50;
    v51 = v29;
    *(_QWORD *)(a1 + 184) = a1 + 184;
    *(_QWORD *)(a1 + 192) = a1 + 184;
  }
  v30 = *(_QWORD *)(a1 + 200);
  if ( v30 != a1 + 200 )
  {
    v31 = v51;
    v32 = *(_QWORD **)(a1 + 208);
    *(_QWORD *)(v30 + 8) = v51;
    *v31 = v30;
    *v32 = &v50;
    v51 = v32;
    *(_QWORD *)(a1 + 200) = a1 + 200;
    *(_QWORD *)(a1 + 208) = a1 + 200;
  }
  v33 = *(_QWORD *)(a1 + 216);
  if ( v33 != a1 + 216 )
  {
    v34 = v51;
    v35 = *(_QWORD **)(a1 + 224);
    *(_QWORD *)(v33 + 8) = v51;
    *v34 = v33;
    *v35 = &v50;
    v51 = v35;
    *(_QWORD *)(a1 + 216) = a1 + 216;
    *(_QWORD *)(a1 + 224) = a1 + 216;
  }
  v36 = *(_QWORD *)(a1 + 232);
  if ( v36 != a1 + 232 )
  {
    v37 = v51;
    v38 = *(_QWORD **)(a1 + 240);
    *(_QWORD *)(v36 + 8) = v51;
    *v37 = v36;
    *v38 = &v50;
    v51 = v38;
    *(_QWORD *)(a1 + 232) = a1 + 232;
    *(_QWORD *)(a1 + 240) = a1 + 232;
  }
  for ( i = v50; i != &v50; i = (_QWORD *)*i )
    *((_DWORD *)i - 37) &= ~0x40u;
  raw_spin_unlock_irqrestore(a1 + 160, v23);
  vchan_dma_desc_free_list(a1, &v50);
  raw_write_lock_irq(v8 + 948);
  *(_DWORD *)(a1 + 292) = 0;
  raw_write_unlock_irq(v8 + 948);
  if ( (*(_BYTE *)(*(_QWORD *)(v8 + 360) + 68LL) & 1) == 0 && (*(_BYTE *)(*(_QWORD *)(v8 + 752) + 68LL) & 1) == 0 )
  {
    if ( *(_DWORD *)(v8 + 1068) >= 3u )
    {
      printk(&unk_11E56, v8 + 1076, *(unsigned int *)(a1 + 256), "gpi_free_chan_resources", v40, v41, v42);
      v43 = *(_QWORD *)(v8 + 1056);
      if ( v43 )
      {
LABEL_33:
        if ( *(_DWORD *)(v8 + 1064) >= 3u )
          ipc_log_string(v43, "ch:%u %s: disabling gpii\n", *(_DWORD *)(a1 + 256), "gpi_free_chan_resources");
      }
    }
    else
    {
      v43 = *(_QWORD *)(v8 + 1056);
      if ( v43 )
        goto LABEL_33;
    }
    v44 = *(_DWORD *)(v8 + 944);
    raw_write_lock_irq(v8 + 948);
    *(_DWORD *)(v8 + 944) = 4;
    raw_write_unlock_irq(v8 + 948);
    tasklet_kill(v8 + 976);
    if ( v44 == 3 )
    {
      ((void (__fastcall *)(__int64, _QWORD, __int64))gpi_send_cmd)(v8, 0, 12);
      v45 = *(_QWORD **)(v8 + 960);
      dma_free_attrs(*(_QWORD *)(*(_QWORD *)(v8 + 792) + 392LL), v45[1], *v45, v45[3], 0);
      v45[7] = 0;
      v45[8] = 0;
      v45[5] = 0;
      v45[6] = 0;
      v45[3] = 0;
      v45[4] = 0;
      v45[1] = 0;
      v45[2] = 0;
      *v45 = 0;
      gpi_disable_interrupts(v8);
    }
    else
    {
      v46 = *(_QWORD **)(v8 + 960);
      dma_free_attrs(*(_QWORD *)(*(_QWORD *)(v8 + 792) + 392LL), v46[1], *v46, v46[3], 0);
      v46[7] = 0;
      v46[8] = 0;
      v46[5] = 0;
      v46[6] = 0;
      v46[3] = 0;
      v46[4] = 0;
      v46[1] = 0;
      v46[2] = 0;
      *v46 = 0;
    }
    raw_write_lock_irq(v8 + 948);
    *(_DWORD *)(v8 + 944) = 0;
    raw_write_unlock_irq(v8 + 948);
  }
  result = mutex_unlock(v8 + 888);
  _ReadStatusReg(SP_EL0);
  return result;
}
