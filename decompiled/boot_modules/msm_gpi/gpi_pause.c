__int64 __fastcall gpi_pause(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v8; // x25
  __int64 v9; // x26
  __int64 v10; // x0
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x23
  __int64 v15; // x22
  unsigned int v16; // w20
  __int64 v17; // x6
  unsigned int v18; // w21
  __int64 v19; // x0
  unsigned int v20; // w20
  __int64 v21; // x6
  unsigned int v22; // w21
  __int64 v23; // x0
  unsigned int v24; // w20
  __int64 v25; // x6
  unsigned int v26; // w21
  __int64 v27; // x0
  __int64 v28; // x20
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x8
  __int64 v33; // x9
  unsigned int *v34; // x27
  unsigned int *v35; // x20
  unsigned int v36; // w10
  __int64 v37; // x0
  __int64 v38; // x0
  unsigned int v39; // w19
  __int64 v40; // x0
  __int64 v41; // x21
  __int64 v42; // x0
  unsigned int *v43; // x28
  __int64 v44; // x4
  __int64 v45; // x0
  int v46; // w23
  unsigned int v47; // w24
  unsigned int v48; // w20
  __int64 v49; // x0
  char *v51; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v52[2]; // [xsp+30h] [xbp-10h] BYREF

  v52[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 280);
  v51 = nullptr;
  v52[0] = 0;
  v9 = *(_QWORD *)(v8 + 960);
  if ( *(_DWORD *)(v8 + 1068) >= 3u )
  {
    printk(&unk_123DE, v8 + 1076, *(unsigned int *)(a1 + 256), "gpi_pause", a5, a6, a7);
    v10 = *(_QWORD *)(v8 + 1056);
    if ( !v10 )
      goto LABEL_5;
  }
  else
  {
    v10 = *(_QWORD *)(v8 + 1056);
    if ( !v10 )
      goto LABEL_5;
  }
  if ( *(_DWORD *)(v8 + 1064) >= 3u )
    ipc_log_string(v10, "ch:%u %s: Enter\n", *(_DWORD *)(a1 + 256), "gpi_pause");
LABEL_5:
  mutex_lock(v8 + 888);
  if ( (*(_BYTE *)(v8 + 1474) & 1) != 0 )
  {
    v14 = (unsigned int)((*(_DWORD *)v8 << 14) + 143488);
    v15 = (unsigned int)v14 | 0x38;
    v16 = readl_relaxed((unsigned int *)(*(_QWORD *)(v8 + 816) + v14));
    v18 = readl_relaxed((unsigned int *)(*(_QWORD *)(v8 + 816) + v15));
    if ( *(_DWORD *)(v8 + 1068) >= 2u )
    {
      printk(&unk_125FF, v8 + 1076, 99, "gpi_pause", v16, v18, v17);
      v19 = *(_QWORD *)(v8 + 1056);
      if ( !v19 )
        goto LABEL_10;
    }
    else
    {
      v19 = *(_QWORD *)(v8 + 1056);
      if ( !v19 )
        goto LABEL_10;
    }
    if ( *(_DWORD *)(v8 + 1064) >= 2u )
      ipc_log_string(v19, "ch:%u %s: CNTXT_TYPE_IRQ:0x%08x IEOB_MASK_OFF:0x%08x\n", 99, "gpi_pause", v16, v18);
LABEL_10:
    v20 = readl_relaxed((unsigned int *)(*(_QWORD *)(v8 + 816) + v14));
    v22 = readl_relaxed((unsigned int *)(*(_QWORD *)(v8 + 816) + v15));
    if ( *(_DWORD *)(v8 + 1068) >= 2u )
    {
      printk(&unk_125FF, v8 + 1076, 99, "gpi_pause", v20, v22, v21);
      v23 = *(_QWORD *)(v8 + 1056);
      if ( !v23 )
        goto LABEL_14;
    }
    else
    {
      v23 = *(_QWORD *)(v8 + 1056);
      if ( !v23 )
        goto LABEL_14;
    }
    if ( *(_DWORD *)(v8 + 1064) >= 2u )
      ipc_log_string(v23, "ch:%u %s: CNTXT_TYPE_IRQ:0x%08x IEOB_MASK_OFF:0x%08x\n", 99, "gpi_pause", v20, v22);
LABEL_14:
    v24 = readl_relaxed((unsigned int *)(*(_QWORD *)(v8 + 816) + v14));
    v26 = readl_relaxed((unsigned int *)(*(_QWORD *)(v8 + 816) + v15));
    if ( *(_DWORD *)(v8 + 1068) >= 2u )
    {
      printk(&unk_125FF, v8 + 1076, 99, "gpi_pause", v24, v26, v25);
      v27 = *(_QWORD *)(v8 + 1056);
      if ( !v27 )
        goto LABEL_18;
    }
    else
    {
      v27 = *(_QWORD *)(v8 + 1056);
      if ( !v27 )
        goto LABEL_18;
    }
    if ( *(_DWORD *)(v8 + 1064) >= 2u )
      ipc_log_string(v27, "ch:%u %s: CNTXT_TYPE_IRQ:0x%08x IEOB_MASK_OFF:0x%08x\n", 99, "gpi_pause", v24, v26);
LABEL_18:
    v28 = (unsigned int)readl_relaxed(*(unsigned int **)(v8 + 848));
    v32 = v28 | (readl_relaxed((unsigned int *)(*(_QWORD *)(v8 + 848) + 4LL)) << 32);
    v52[0] = v32;
    if ( !v32 )
    {
      if ( *(_DWORD *)(v8 + 1068) >= 2u )
      {
        printk(&unk_1320E, v8 + 1076, 99, "gpi_pause", v29, v30, v31);
        v40 = *(_QWORD *)(v8 + 1056);
        if ( !v40 )
          goto LABEL_32;
      }
      else
      {
        v40 = *(_QWORD *)(v8 + 1056);
        if ( !v40 )
          goto LABEL_32;
      }
      if ( *(_DWORD *)(v8 + 1064) >= 2u )
        ipc_log_string(v40, "ch:%u %s: invalid cntxt_rp", 99, "gpi_pause");
      goto LABEL_32;
    }
    v33 = *(_QWORD *)(v9 + 16);
    v34 = *(unsigned int **)(v9 + 48);
    v35 = *(unsigned int **)(v9 + 32);
    v36 = *(_DWORD *)(v8 + 1068);
    v51 = (char *)((char *)v34 + v33 - (char *)v35);
    if ( (unsigned int *)((char *)v34 + v33) == v35 )
    {
      if ( v36 >= 2 )
      {
        printk(&unk_1204A, v8 + 1076, 99, "gpi_pause", v29, v30, v31);
        v37 = *(_QWORD *)(v8 + 1056);
        if ( v37 )
        {
LABEL_22:
          if ( *(_DWORD *)(v8 + 1064) >= 2u )
            ipc_log_string(v37, "ch:%u %s: invalid local_rp", 99, "gpi_pause");
        }
      }
      else
      {
        v37 = *(_QWORD *)(v8 + 1056);
        if ( v37 )
          goto LABEL_22;
      }
LABEL_32:
      v39 = -22;
      goto LABEL_71;
    }
    v41 = v32 - v33;
    if ( v36 >= 2 )
      printk(&unk_12377, v8 + 1076, 99, "gpi_pause", v52, &v51, v31);
    v42 = *(_QWORD *)(v8 + 1056);
    v43 = (unsigned int *)((char *)v35 + v41);
    if ( v42 && *(_DWORD *)(v8 + 1064) >= 2u )
      ipc_log_string(v42, "ch:%u %s: cntxt_rp:%pa local_rp:%pa\n", 99, "gpi_pause", v52, &v51);
    while ( v43 != v34 )
    {
      v44 = *((unsigned __int8 *)v34 + 15);
      v30 = *((unsigned __int8 *)v34 + 14);
      if ( *(_DWORD *)(v8 + 1068) >= 2u )
      {
        v46 = *((unsigned __int8 *)v34 + 15);
        v47 = *((unsigned __int8 *)v34 + 14);
        printk(&unk_14405, v8 + 1076, 99, "gpi_pause", v44, v30, *v34);
        v30 = v47;
        LODWORD(v44) = v46;
        v45 = *(_QWORD *)(v8 + 1056);
        if ( v45 )
        {
LABEL_46:
          if ( *(_DWORD *)(v8 + 1064) >= 2u )
            ipc_log_string(
              v45,
              "ch:%u %s: chid:%u type:0x%x %08x %08x %08x %08x rp:%pK rp1:%pK\n",
              99,
              "gpi_pause",
              v44,
              v30,
              *v34,
              v34[1],
              v34[2],
              v34[3],
              v43,
              v34);
        }
      }
      else
      {
        v45 = *(_QWORD *)(v8 + 1056);
        if ( v45 )
          goto LABEL_46;
      }
      if ( (unsigned __int64)v34 + *(unsigned int *)(v9 + 60) >= *(_QWORD *)(v9 + 32)
                                                               + (unsigned __int64)*(unsigned int *)(v9 + 56) )
        v34 = *(unsigned int **)(v9 + 32);
      else
        v34 = (unsigned int *)((char *)v34 + *(unsigned int *)(v9 + 60));
    }
    if ( *(_BYTE *)(v8 + 1473) == 1 )
    {
      v48 = 1;
      while ( *(_BYTE *)(v8 + 1473) == 1 )
      {
        _const_udelay(42950);
        if ( ++v48 == 1001 )
        {
          v48 = 1000;
          break;
        }
      }
    }
    else
    {
      v48 = 0;
    }
    if ( *(_DWORD *)(v8 + 1068) >= 3u )
    {
      printk(&unk_13ADC, v8 + 1076, *(unsigned int *)(a1 + 256), "gpi_pause", v48, v30, v31);
      v49 = *(_QWORD *)(v8 + 1056);
      if ( v49 )
      {
LABEL_58:
        if ( *(_DWORD *)(v8 + 1064) >= 3u )
          ipc_log_string(v49, "ch:%u %s: iter:%d\n", *(_DWORD *)(a1 + 256), "gpi_pause", v48);
      }
    }
    else
    {
      v49 = *(_QWORD *)(v8 + 1056);
      if ( v49 )
        goto LABEL_58;
    }
    disable_irq(*(unsigned int *)(v8 + 808));
    v39 = 0;
    *(_BYTE *)(v8 + 1474) = 0;
    goto LABEL_71;
  }
  if ( *(_DWORD *)(v8 + 1068) >= 2u )
  {
    printk(&unk_121A3, v8 + 1076, *(unsigned int *)(a1 + 256), "gpi_pause", v11, v12, v13);
    v38 = *(_QWORD *)(v8 + 1056);
    if ( !v38 )
      goto LABEL_70;
  }
  else
  {
    v38 = *(_QWORD *)(v8 + 1056);
    if ( !v38 )
    {
LABEL_70:
      v39 = 0;
      goto LABEL_71;
    }
  }
  if ( *(_DWORD *)(v8 + 1064) < 2u )
    goto LABEL_70;
  ipc_log_string(v38, "ch:%u %s: Already in suspend/pause state\n", *(_DWORD *)(a1 + 256), "gpi_pause");
  v39 = 0;
LABEL_71:
  mutex_unlock(v8 + 888);
  _ReadStatusReg(SP_EL0);
  return v39;
}
