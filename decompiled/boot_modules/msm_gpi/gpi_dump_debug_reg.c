_QWORD *__fastcall gpi_dump_debug_reg(unsigned int *a1)
{
  unsigned int v2; // w21
  unsigned int v3; // w20
  unsigned int v4; // w20
  unsigned int v5; // w20
  unsigned int v6; // w20
  unsigned int v7; // w20
  unsigned int v8; // w20
  unsigned int v9; // w20
  unsigned int v10; // w20
  unsigned int v11; // w20
  unsigned int v12; // w20
  unsigned int v13; // w20
  unsigned int v14; // w20
  unsigned int v15; // w20
  unsigned int v16; // w20
  unsigned int v17; // w20
  unsigned int v18; // w20
  unsigned int v19; // w20
  unsigned int v20; // w20
  __int64 v21; // x0
  unsigned int v22; // w20
  unsigned int v23; // w20
  __int64 v24; // x0
  _QWORD *v25; // x8
  _QWORD *v26; // x22
  _QWORD *v27; // x22
  _QWORD *v28; // x22
  _QWORD *v29; // x22
  _QWORD *v30; // x20
  _QWORD *result; // x0
  unsigned int *v32; // x25
  __int64 v33; // x8
  unsigned int v34; // w0
  unsigned int *v35; // x25
  __int64 v36; // x8
  unsigned int v37; // w0
  unsigned int *v38; // x25
  __int64 v39; // x8
  unsigned int *v40; // x25
  __int64 v41; // x8
  unsigned int *v42; // x25
  __int64 v43; // x8
  unsigned int v44; // w0
  _QWORD *v45; // x20
  int v46; // w0
  __int64 v47; // x8
  unsigned int v48; // w0
  __int64 v49; // x6
  unsigned int v50; // w8
  unsigned int v51; // w0
  __int64 v52; // x6
  unsigned int v53; // w8
  unsigned int v54; // w0
  __int64 v55; // x6
  unsigned int v56; // w8
  __int64 v57; // x6
  __int64 v58; // x6
  unsigned int v59; // w0
  __int64 v60; // x4
  __int64 v61; // x5
  __int64 v62; // x6
  unsigned int v63; // w8

  v2 = *a1 << 14;
  v3 = readl_relaxed(*((_QWORD *)a1 + 102) + v2 + (a1[66] << 7) + 0x20000);
  if ( a1[267] >= 2 )
  {
    printk(&unk_126D7, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 0, v3);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_5;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_5;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_5:
  v4 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + (a1[164] << 7) + 0x20000);
  if ( a1[267] >= 2 )
  {
    printk(&unk_126D7, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 1, v4);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_9;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_9;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_9:
  v5 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + (a1[66] << 7) + 131080);
  if ( a1[267] >= 2 )
  {
    printk(&unk_13C46, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 0, v5);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_13;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_13;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_13:
  v6 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 131168 + (a1[164] << 7) - 88);
  if ( a1[267] >= 2 )
  {
    printk(&unk_13C46, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 1, v6);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_17;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_17;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_17:
  v7 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 131168 + (a1[66] << 7) - 80);
  if ( a1[267] >= 2 )
  {
    printk(&unk_13DBD, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 0, v7);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_21;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_21;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_21:
  v8 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 131168 + (a1[164] << 7) - 80);
  if ( a1[267] >= 2 )
  {
    printk(&unk_13DBD, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 1, v8);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_25;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_25;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_25:
  v9 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 131168 + (a1[66] << 7) - 72);
  if ( a1[267] >= 2 )
  {
    printk(&unk_1360D, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 0, v9);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_29;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_29;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_29:
  v10 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 131168 + (a1[164] << 7) - 72);
  if ( a1[267] >= 2 )
  {
    printk(&unk_1360D, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 1, v10);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_33;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_33;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_33:
  v11 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 131168 + (a1[66] << 7) + 4000);
  if ( a1[267] >= 2 )
  {
    printk(&unk_14488, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 0, v11);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_37;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_37;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_37:
  v12 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 131168 + (a1[164] << 7) + 4000);
  if ( a1[267] >= 2 )
  {
    printk(&unk_14488, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 1, v12);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_41;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_41;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_41:
  v13 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 131168 + (a1[66] << 7) + 4008);
  if ( a1[267] >= 2 )
  {
    printk(&unk_1270B, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 0, v13);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_45;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_45;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_45:
  v14 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 131168 + (a1[164] << 7) + 4008);
  if ( a1[267] >= 2 )
  {
    printk(&unk_1270B, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 1, v14);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_49;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_49;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_49:
  v15 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + (a1[66] << 7) + 135184);
  if ( a1[267] >= 2 )
  {
    printk(&unk_11F39, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 0, v15);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_53;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_53;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_53:
  v16 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 135184 + (a1[164] << 7));
  if ( a1[267] >= 2 )
  {
    printk(&unk_11F39, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 1, v16);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_57;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_57;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_57:
  v17 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 135184 + (a1[66] << 7) + 8);
  if ( a1[267] >= 2 )
  {
    printk(&unk_12290, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 0, v17);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_61;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_61;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_61:
  v18 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 135184 + (a1[164] << 7) + 8);
  if ( a1[267] >= 2 )
  {
    printk(&unk_12290, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 1, v18);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_65;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_65;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_65:
  v19 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 131168 + (a1[66] << 7) - 12);
  if ( a1[267] >= 2 )
  {
    printk(&unk_1322B, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 0, v19);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_69;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_69;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_69:
  v20 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 131168 + (a1[164] << 7) - 12);
  if ( a1[267] >= 2 )
  {
    printk(&unk_1322B, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 1, v20);
    v21 = *((_QWORD *)a1 + 132);
    if ( !v21 )
      goto LABEL_73;
  }
  else
  {
    v21 = *((_QWORD *)a1 + 132);
    if ( !v21 )
      goto LABEL_73;
  }
  if ( a1[266] >= 2 )
    v21 = ipc_log_string();
LABEL_73:
  if ( (*(_BYTE *)(*((_QWORD *)a1 + 99) + 496LL) & 1) != 0 )
    goto LABEL_82;
  v22 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 7) + 4 * a1[66] + 96256);
  if ( a1[267] >= 2 )
  {
    printk(&unk_13266, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 0, v22);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_78;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_78;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_78:
  v23 = readl_relaxed(*((_QWORD *)a1 + 102) + 4 * a1[164] + 96256 + (*a1 << 7));
  if ( a1[267] >= 2 )
  {
    printk(&unk_13266, a1 + 269, 99, "gpi_dump_cntxt_regs", *a1, 1, v23);
    v21 = *((_QWORD *)a1 + 132);
    if ( !v21 )
      goto LABEL_82;
  }
  else
  {
    v21 = *((_QWORD *)a1 + 132);
    if ( !v21 )
      goto LABEL_82;
  }
  if ( a1[266] >= 2 )
    v21 = ipc_log_string();
LABEL_82:
  v24 = sched_clock(v21);
  v25 = *((_QWORD **)a1 + 173);
  *((_QWORD *)a1 + 168) = v24;
  if ( !v25 )
  {
    result = (_QWORD *)_kmalloc_cache_noprof(dev_err, 2336, 208);
    v25 = result;
    *((_QWORD *)a1 + 173) = result;
    if ( !result )
      return result;
    *result = "TYPE_IRQ";
    *((_DWORD *)result + 2) = v2 + 143488;
    *((_DWORD *)result + 3) = 0;
    *((_DWORD *)result + 6) = v2 + 143496;
    *((_DWORD *)result + 7) = 0;
    result[2] = "TYPE_IRQ_MSK";
    *((_DWORD *)result + 10) = v2 + 143504;
    *((_DWORD *)result + 11) = 0;
    result[4] = "CH_IRQ";
    *((_DWORD *)result + 14) = v2 + 143508;
    *((_DWORD *)result + 15) = 0;
    result[6] = "EV_IRQ";
    *((_DWORD *)result + 18) = v2 + 143512;
    *((_DWORD *)result + 19) = 0;
    result[8] = "CH_IRQ_MSK";
    *((_DWORD *)result + 22) = v2 + 143516;
    *((_DWORD *)result + 23) = 0;
    result[10] = "EV_IRQ_MSK";
    *((_DWORD *)result + 26) = v2 + 143536;
    *((_DWORD *)result + 27) = 0;
    result[12] = "IEOB_IRQ";
    *((_DWORD *)result + 30) = v2 + 143544;
    *((_DWORD *)result + 31) = 0;
    result[14] = "IEOB_IRQ_MSK";
    *((_DWORD *)result + 34) = v2 + 143616;
    *((_DWORD *)result + 35) = 0;
    result[16] = "GLOB_IRQ";
    *((_DWORD *)result + 38) = v2 + 143624;
    *((_DWORD *)result + 39) = 0;
    result[18] = "GLOB_IRQ_EN";
    *((_DWORD *)result + 42) = v2 + 143640;
    *((_DWORD *)result + 43) = 0;
    result[20] = "GPII_IRQ_STTS";
    result[22] = "GPII_IRQ_EN";
    *((_DWORD *)result + 46) = v2 + 143648;
    *((_DWORD *)result + 51) = 0;
    *(_QWORD *)((char *)result + 196) = 0;
    *(_QWORD *)((char *)result + 188) = 0;
    goto LABEL_98;
  }
  if ( *v25 )
  {
LABEL_98:
    v32 = (unsigned int *)(v25 + 1);
    do
    {
      v34 = readl_relaxed(*((_QWORD *)a1 + 102) + *v32);
      v32[1] = v34;
      if ( a1[267] >= 2 )
      {
        printk(&unk_1308E, a1 + 269, 99, "gpi_dump_debug_reg", *((_QWORD *)v32 - 1), *v32, v34);
        if ( *((_QWORD *)a1 + 132) )
        {
LABEL_102:
          if ( a1[266] >= 2 )
            ipc_log_string();
        }
      }
      else if ( *((_QWORD *)a1 + 132) )
      {
        goto LABEL_102;
      }
      v33 = *((_QWORD *)v32 + 1);
      v32 += 4;
    }
    while ( v33 );
  }
  v26 = *((_QWORD **)a1 + 169);
  if ( !v26 )
  {
    result = (_QWORD *)_kmalloc_cache_noprof(dev_err, 2336, 240);
    v26 = result;
    *((_QWORD *)a1 + 169) = result;
    if ( !result )
      return result;
    memcpy(result, &gpi_debug_ev_cntxt, 0xF0u);
    goto LABEL_108;
  }
  if ( *v26 )
  {
LABEL_108:
    v35 = (unsigned int *)(v26 + 1);
    do
    {
      v37 = readl_relaxed(*((_QWORD *)a1 + 103) + *v35);
      v35[1] = v37;
      if ( a1[267] >= 2 )
      {
        printk(&unk_142E7, a1 + 269, 99, "gpi_dump_debug_reg", *((_QWORD *)v35 - 1), *v35, v37);
        if ( *((_QWORD *)a1 + 132) )
        {
LABEL_112:
          if ( a1[266] >= 2 )
            ipc_log_string();
        }
      }
      else if ( *((_QWORD *)a1 + 132) )
      {
        goto LABEL_112;
      }
      v36 = *((_QWORD *)v35 + 1);
      v35 += 4;
    }
    while ( v36 );
  }
  v27 = *((_QWORD **)a1 + 170);
  if ( !v27 )
  {
    result = (_QWORD *)_kmalloc_cache_noprof(printk, 2336, 144);
    v27 = result;
    *((_QWORD *)a1 + 170) = result;
    if ( !result )
      return result;
    memcpy(result, &gpi_debug_ch_cntxt, 0x90u);
    goto LABEL_118;
  }
  if ( *v27 )
  {
LABEL_118:
    v38 = (unsigned int *)(v27 + 1);
    do
    {
      v38[1] = readl_relaxed(*((_QWORD *)a1 + 38) + *v38);
      if ( a1[267] >= 2 )
      {
        printk(&unk_130C0, a1 + 269, 99, "gpi_dump_debug_reg", 0, *((_QWORD *)v38 - 1), *v38);
        if ( *((_QWORD *)a1 + 132) )
        {
LABEL_122:
          if ( a1[266] >= 2 )
            ipc_log_string();
        }
      }
      else if ( *((_QWORD *)a1 + 132) )
      {
        goto LABEL_122;
      }
      v39 = *((_QWORD *)v38 + 1);
      v38 += 4;
    }
    while ( v39 );
  }
  v28 = *((_QWORD **)a1 + 171);
  if ( !v28 )
  {
    result = (_QWORD *)_kmalloc_cache_noprof(printk, 2336, 144);
    v28 = result;
    *((_QWORD *)a1 + 171) = result;
    if ( !result )
      return result;
    memcpy(result, &gpi_debug_ch_cntxt, 0x90u);
    goto LABEL_128;
  }
  if ( *v28 )
  {
LABEL_128:
    v40 = (unsigned int *)(v28 + 1);
    do
    {
      v40[1] = readl_relaxed(*((_QWORD *)a1 + 87) + *v40);
      if ( a1[267] >= 2 )
      {
        printk(&unk_130C0, a1 + 269, 99, "gpi_dump_debug_reg", 1, *((_QWORD *)v40 - 1), *v40);
        if ( *((_QWORD *)a1 + 132) )
        {
LABEL_132:
          if ( a1[266] >= 2 )
            ipc_log_string();
        }
      }
      else if ( *((_QWORD *)a1 + 132) )
      {
        goto LABEL_132;
      }
      v41 = *((_QWORD *)v40 + 1);
      v40 += 4;
    }
    while ( v41 );
  }
  if ( (*(_BYTE *)(*((_QWORD *)a1 + 99) + 496LL) & 1) != 0 )
    goto LABEL_150;
  v29 = *((_QWORD **)a1 + 172);
  if ( !v29 )
  {
    result = (_QWORD *)_kmalloc_cache_noprof(dma_release_channel, 2336, 560);
    v29 = result;
    *((_QWORD *)a1 + 172) = result;
    if ( !result )
      return result;
    memcpy(result, &gpi_debug_regs, 0x230u);
    goto LABEL_138;
  }
  if ( *v29 )
  {
LABEL_138:
    v42 = (unsigned int *)(v29 + 1);
    do
    {
      v44 = readl_relaxed(*(_QWORD *)(*((_QWORD *)a1 + 99) + 408LL) + *v42);
      v42[1] = v44;
      if ( a1[267] >= 2 )
      {
        printk(&unk_12E65, a1 + 269, 99, "gpi_dump_debug_reg", *((_QWORD *)v42 - 1), *v42, v44);
        if ( *((_QWORD *)a1 + 132) )
        {
LABEL_142:
          if ( a1[266] >= 2 )
            ipc_log_string();
        }
      }
      else if ( *((_QWORD *)a1 + 132) )
      {
        goto LABEL_142;
      }
      v43 = *((_QWORD *)v42 + 1);
      v42 += 4;
    }
    while ( v43 );
  }
  v30 = *((_QWORD **)a1 + 174);
  if ( v30 )
  {
    if ( !*v30 )
      goto LABEL_150;
  }
  else
  {
    result = (_QWORD *)_kmalloc_cache_noprof(printk, 2336, 176);
    v30 = result;
    *((_QWORD *)a1 + 174) = result;
    if ( !result )
      return result;
    memcpy(result, &gpi_debug_qsb_regs, 0xB0u);
  }
  v45 = v30 + 2;
  do
  {
    v46 = readl_relaxed(*(_QWORD *)(*((_QWORD *)a1 + 99) + 408LL) + *((unsigned int *)v45 - 2));
    v47 = *v45;
    *((_DWORD *)v45 - 1) = v46;
    v45 += 2;
  }
  while ( v47 );
LABEL_150:
  v48 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 144384);
  v50 = a1[267];
  a1[350] = v48;
  if ( v50 >= 2 )
  {
    printk(&unk_12A3D, a1 + 269, 99, "gpi_dump_debug_reg", (*a1 << 14) + 144384, v48, v49);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_154;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_154;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_154:
  v51 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 131168 + (a1[66] << 7));
  v53 = a1[267];
  a1[351] = v51;
  if ( v53 >= 2 )
  {
    printk(&unk_1225C, a1 + 269, 99, "gpi_dump_debug_reg", (*a1 << 14) + 131168 + (a1[66] << 7), v51, v52);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_158;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_158;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_158:
  v54 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 131168 + (a1[164] << 7));
  v56 = a1[267];
  a1[352] = v54;
  if ( v56 >= 2 )
  {
    printk(&unk_1225C, a1 + 269, 99, "gpi_dump_debug_reg", (*a1 << 14) + 131168 + (a1[164] << 7), v54, v55);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_162;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_162;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_162:
  if ( !*((_QWORD *)a1 + 177) )
  {
    a1[356] = *(_DWORD *)(*((_QWORD *)a1 + 120) + 56LL);
    result = (_QWORD *)_kmalloc_noprof(a1[356], 2336);
    *((_QWORD *)a1 + 177) = result;
    if ( !result )
      return result;
  }
  memcpy(*((void **)a1 + 177), *(const void **)(*((_QWORD *)a1 + 120) + 32LL), a1[356]);
  if ( !*((_QWORD *)a1 + 179) )
  {
    a1[362] = *(_DWORD *)(*((_QWORD *)a1 + 45) + 56LL);
    result = (_QWORD *)_kmalloc_noprof(a1[362], 2336);
    *((_QWORD *)a1 + 179) = result;
    if ( !result )
      return result;
  }
  memcpy(*((void **)a1 + 179), *(const void **)(*((_QWORD *)a1 + 45) + 32LL), a1[362]);
  if ( a1[267] >= 2 )
  {
    printk(&unk_12CEF, a1 + 269, 99, "gpi_dump_debug_reg", 0, *(_QWORD *)(*((_QWORD *)a1 + 45) + 32LL), v57);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_170;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_170;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_170:
  if ( !*((_QWORD *)a1 + 180) )
  {
    a1[363] = *(_DWORD *)(*((_QWORD *)a1 + 94) + 56LL);
    result = (_QWORD *)_kmalloc_noprof(a1[363], 2336);
    *((_QWORD *)a1 + 180) = result;
    if ( !result )
      return result;
  }
  memcpy(*((void **)a1 + 180), *(const void **)(*((_QWORD *)a1 + 94) + 32LL), a1[363]);
  if ( a1[267] >= 2 )
  {
    printk(&unk_12CEF, a1 + 269, 99, "gpi_dump_debug_reg", 1, *(_QWORD *)(*((_QWORD *)a1 + 94) + 32LL), v58);
    if ( !*((_QWORD *)a1 + 132) )
      goto LABEL_176;
  }
  else if ( !*((_QWORD *)a1 + 132) )
  {
    goto LABEL_176;
  }
  if ( a1[266] >= 2 )
    ipc_log_string();
LABEL_176:
  v59 = readl_relaxed(*((_QWORD *)a1 + 102) + (*a1 << 14) + 143872);
  v63 = a1[267];
  a1[364] = v59;
  if ( v63 >= 2 )
  {
    printk(&unk_1208E, a1 + 269, 99, "gpi_dump_debug_reg", (*a1 << 14) + 143872, v59, v62);
    if ( *((_QWORD *)a1 + 132) )
    {
LABEL_178:
      if ( a1[266] >= 2 )
        ipc_log_string();
    }
  }
  else if ( *((_QWORD *)a1 + 132) )
  {
    goto LABEL_178;
  }
  if ( a1[267] >= 2 )
  {
    printk(&unk_12476, a1 + 269, 99, "gpi_dump_debug_reg", v60, v61, v62);
    result = *((_QWORD **)a1 + 132);
    if ( !result )
      return result;
  }
  else
  {
    result = *((_QWORD **)a1 + 132);
    if ( !result )
      return result;
  }
  if ( a1[266] >= 2 )
    return (_QWORD *)ipc_log_string();
  return result;
}
