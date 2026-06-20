__int64 __fastcall spi_geni_mas_setup(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  __int64 v4; // x8
  char v5; // w0
  unsigned int qup_hw_version; // w0
  int v9; // w23
  unsigned int v10; // w0
  int v13; // w20
  unsigned int v14; // w8
  unsigned int *v15; // x0
  unsigned int v16; // w0
  __int64 v17; // x2
  unsigned int v18; // w27
  __int64 v19; // x0
  unsigned __int64 v20; // x8
  __int64 v21; // x0
  unsigned __int64 v22; // x8
  __int64 v23; // x0
  unsigned __int64 v24; // x0
  unsigned __int64 v25; // x0
  __int64 v26; // x10
  __int64 v27; // x8
  __int64 (*v28)(void); // x8
  int v29; // w0
  __int64 (*v30)(void); // x8
  __int64 v31; // x8
  const char *v32; // x1
  unsigned int v33; // w0
  unsigned int v34; // w21
  unsigned int v35; // w20
  _BOOL4 v36; // w9
  unsigned int v37; // w22
  int v38; // w8
  unsigned int *v39; // x0
  _BOOL4 v40; // w28
  unsigned __int8 v41; // w0
  __int64 v42; // x8
  int v43; // w6
  int v44; // w5
  int v45; // w23
  int v46; // w24
  int v47; // w26
  unsigned int v48; // w25
  unsigned int v49; // w0
  bool v50; // zf
  unsigned int v51; // w9
  unsigned int v52; // w0
  int v53; // w20
  int v54; // w21
  int v55; // w0

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(_BYTE *)(v1 + 503) == 1 && (*(_BYTE *)(v1 + 224) & 1) == 0 )
  {
    result = spi_verify_proto(*(_QWORD *)(a1 + 152));
    if ( (_DWORD)result )
      return result;
  }
  if ( (*(_BYTE *)(v1 + 224) & 1) == 0 )
  {
    if ( *(_BYTE *)(a1 + 959) == 1 )
      spi_slv_setup(v1);
    if ( *(_BYTE *)(v1 + 517) == 1 )
      spi_master_setup(v1);
  }
  v4 = *(_QWORD *)(v1 + 184);
  *(_DWORD *)(v1 + 296) = 1;
  v5 = readl_relaxed((unsigned int *)(v4 + 100));
  *(_BYTE *)(v1 + 500) = v5 & 1;
  if ( (v5 & 1) != 0 )
  {
    ipc_log_string(*(_QWORD *)(v1 + 472), "%s:GSI mode\n", "spi_geni_mas_setup");
    v19 = *(_QWORD *)(v1 + 200);
    if ( v19 )
    {
      spi_trace_log();
      v19 = *(_QWORD *)(v1 + 200);
    }
    v20 = dma_request_chan(v19, "tx");
    v21 = *(_QWORD *)(v1 + 200);
    if ( v20 > 0xFFFFFFFFFFFFF000LL )
      v20 = 0;
    *(_QWORD *)(v1 + 320) = v20;
    if ( !v20 )
    {
      dev_info(v21, "Failed to get tx DMA ch %ld\n", 0);
      v18 = 0;
      goto LABEL_55;
    }
    v22 = dma_request_chan(v21, "rx");
    v23 = *(_QWORD *)(v1 + 200);
    if ( v22 > 0xFFFFFFFFFFFFF000LL )
      v22 = 0;
    *(_QWORD *)(v1 + 328) = v22;
    if ( !v22 )
    {
      dev_info(v23, "Failed to get rx DMA ch %ld\n", 0);
      dma_release_channel(*(_QWORD *)(v1 + 320));
      v18 = 0;
      goto LABEL_55;
    }
    v24 = devm_kmalloc(v23, 4560, 3520);
    *(_QWORD *)(v1 + 304) = v24;
    if ( v24 && v24 < 0xFFFFFFFFFFFFF001LL )
    {
      if ( (*(_BYTE *)(v1 + 502) & 1) == 0 && *(_BYTE *)(v1 + 503) != 1
        || (v25 = devm_kmalloc(*(_QWORD *)(v1 + 200), 456, 3520), (*(_QWORD *)(v1 + 312) = v25) != 0)
        && v25 < 0xFFFFFFFFFFFFF001LL )
      {
        v26 = *(_QWORD *)(v1 + 320);
        *(_QWORD *)(v1 + 344) = spi_gsi_ch_cb;
        *(_QWORD *)(v1 + 352) = a1;
        *(_DWORD *)(v1 + 336) = 1;
        *(_QWORD *)(v26 + 104) = v1 + 336;
        *(_QWORD *)(v1 + 368) = spi_gsi_ch_cb;
        *(_QWORD *)(v1 + 376) = a1;
        v27 = *(_QWORD *)(v1 + 328);
        *(_DWORD *)(v1 + 360) = 1;
        *(_QWORD *)(v27 + 104) = v1 + 360;
        v28 = *(__int64 (**)(void))(**(_QWORD **)(v1 + 320) + 312LL);
        if ( v28 )
        {
          if ( *((_DWORD *)v28 - 1) != -1098344795 )
            __break(0x8228u);
          v29 = v28();
          if ( !v29 )
          {
            v30 = *(__int64 (**)(void))(**(_QWORD **)(v1 + 328) + 312LL);
            if ( v30 )
            {
              if ( *((_DWORD *)v30 - 1) != -1098344795 )
                __break(0x8228u);
              v29 = v30();
              if ( !v29 )
                goto LABEL_25;
            }
            else
            {
              v29 = -38;
            }
            v31 = *(_QWORD *)(v1 + 200);
            v32 = "Failed to Config Rx, ret:%d\n";
            goto LABEL_53;
          }
        }
        else
        {
          v29 = -38;
        }
        v31 = *(_QWORD *)(v1 + 200);
        v32 = "Failed to Config Tx, ret:%d\n";
LABEL_53:
        v18 = v29;
        dev_err(v31, v32);
        dma_release_channel(*(_QWORD *)(v1 + 320));
        dma_release_channel(*(_QWORD *)(v1 + 328));
        goto LABEL_54;
      }
      dev_err(*(_QWORD *)(v1 + 200), "Failed to get GSI lock mem\n");
    }
    else
    {
      dev_err(*(_QWORD *)(v1 + 200), "Failed to get GSI mem\n");
    }
    dma_release_channel(*(_QWORD *)(v1 + 320));
    dma_release_channel(*(_QWORD *)(v1 + 328));
    v18 = 0;
LABEL_54:
    *(_QWORD *)(v1 + 320) = 0;
    *(_QWORD *)(v1 + 328) = 0;
    goto LABEL_55;
  }
  qup_hw_version = geni_se_get_qup_hw_version(v1);
  if ( ((qup_hw_version & 0xFFE0000) <= 0x90000 || qup_hw_version >> 28 != 3) && (qup_hw_version & 0xC0000000) == 0 )
    v9 = 4128768;
  else
    v9 = 16711680;
  *(_DWORD *)(v1 + 212) = (v9 & (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)v1 + 3620LL))) >> 16;
  v10 = geni_se_get_qup_hw_version(v1);
  if ( ((v10 & 0xFFE0000) <= 0x90000 || v10 >> 28 != 3) && (v10 & 0xC0000000) == 0 )
    v13 = 4128768;
  else
    v13 = 16711680;
  v14 = (v13 & (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)v1 + 3624LL))) >> 16;
  v15 = (unsigned int *)(*(_QWORD *)v1 + 3620LL);
  *(_DWORD *)(v1 + 208) = v14;
  v16 = readl_relaxed(v15);
  v17 = (unsigned int)(*(_DWORD *)(v1 + 212) - 2);
  *(_DWORD *)(v1 + 216) = HIBYTE(v16) & 0x3F;
  geni_se_init(v1, 0, v17);
  *(_DWORD *)(v1 + 220) = 1;
LABEL_25:
  v18 = 0;
  *(_DWORD *)(v1 + 576) = readl_relaxed(*(unsigned int **)(v1 + 184));
LABEL_55:
  dev_info(
    *(_QWORD *)(v1 + 200),
    "tx_fifo %d rx_fifo %d tx_width %d\n",
    *(_DWORD *)(v1 + 212),
    *(_DWORD *)(v1 + 208),
    *(_DWORD *)(v1 + 216));
  if ( (*(_BYTE *)(v1 + 501) & 1) == 0 )
    *(_BYTE *)(v1 + 224) = 1;
  if ( (*(_BYTE *)(v1 + 503) & 1) != 0 )
    return v18;
  v33 = geni_se_get_qup_hw_version(v1);
  if ( v33 )
  {
    v34 = v33 >> 28;
    v35 = v33;
    v36 = v33 >> 28 == 1;
    v37 = HIWORD(v33) & 0xFFF;
    v38 = (unsigned __int16)v33;
    v39 = (unsigned int *)(*(_QWORD *)(v1 + 184) + 104LL);
    *(_DWORD *)(v1 + 104) = v38;
    if ( v37 )
      v40 = 0;
    else
      v40 = v36;
    *(_DWORD *)(v1 + 96) = v34;
    *(_DWORD *)(v1 + 100) = v37;
    v41 = readl_relaxed(v39);
    v42 = *(_QWORD *)(v1 + 184);
    *(_DWORD *)(v1 + 108) = v41;
    v43 = (unsigned __int8)readl_relaxed((unsigned int *)(v42 + 108));
    *(_DWORD *)(v1 + 112) = v43;
    if ( v40 )
    {
      v44 = 2;
      *(_DWORD *)(v1 + 296) = 2;
    }
    else
    {
      v44 = *(_DWORD *)(v1 + 296);
    }
    ipc_log_string(
      *(_QWORD *)(v1 + 472),
      "%s:Major:%d Minor:%d os%d FW Ver: %d\n",
      "spi_geni_mas_setup",
      v34,
      v37,
      v44,
      v43);
    if ( *(_QWORD *)(v1 + 200) )
      spi_trace_log();
    if ( *(_BYTE *)(v1 + 507) == 1 )
    {
      v45 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 184) + 560LL));
      v46 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 184) + 548LL));
      v47 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 184) + 688LL));
      v48 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 184) + 692LL));
      if ( v40 )
      {
        v49 = v47 & 0xFFFF8FED | 0x1000;
      }
      else if ( v35 >> 29 && (v34 != 2 || v37 > 4) )
      {
        v49 = v47 & 0xFFFFF8FD | (*(_DWORD *)(v1 + 508) << 8);
      }
      else
      {
        v49 = v47 & 0xFFFFF8FD;
      }
      writel_relaxed(v49, (unsigned int *)(*(_QWORD *)(v1 + 184) + 688LL));
      if ( v46 )
        v50 = 0;
      else
        v50 = v45 == 1;
      if ( v50 )
        v51 = 0;
      else
        v51 = v48;
      if ( v45 | v46 )
        v52 = v51;
      else
        v52 = 1;
      writel_relaxed(v52, (unsigned int *)(*(_QWORD *)(v1 + 184) + 692LL));
      if ( !v40 )
        writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(v1 + 184) + 132LL));
      v53 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 184) + 688LL));
      v54 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 184) + 692LL));
      v55 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 184) + 132LL));
      ipc_log_string(
        *(_QWORD *)(v1 + 472),
        "%s cfg108: 0x%x cfg109: 0x%x cfg_seq_start: 0x%x\n",
        "spi_geni_set_sampling_rate",
        v53,
        v54,
        v55);
      if ( *(_QWORD *)(v1 + 200) )
        spi_trace_log();
    }
    if ( *(_BYTE *)(v1 + 505) == 1 )
    {
      ipc_log_string(*(_QWORD *)(v1 + 472), "Auto Suspend is disabled\n");
      if ( *(_QWORD *)(v1 + 200) )
        spi_trace_log();
    }
    return v18;
  }
  dev_err(*(_QWORD *)(v1 + 200), "%s:Err getting HW version %d\n", "spi_geni_mas_setup", 0);
  return 4294967290LL;
}
