__int64 __fastcall msm_geni_serial_prep_dma_tx(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x23
  unsigned __int64 v4; // x20
  unsigned int v5; // w21
  unsigned int v7; // w0
  __int64 v8; // x21
  int v9; // w24
  unsigned int v10; // w22
  int v11; // w23
  __int64 v12; // x8
  int v13; // w9
  __int64 v14; // x23
  __int64 v15; // x21
  __int64 v16; // x0
  void *v17; // x1
  size_t v18; // x2
  unsigned int v19; // w8
  unsigned int v20; // w8
  __int64 v21; // x9
  unsigned int v22; // w8
  const char **v23; // x23
  char v24; // w0
  __int64 *v25; // x24
  __int64 inited; // x0
  __int64 v27; // x22
  unsigned int v28; // w0
  unsigned int *v29; // x1
  __int64 v30; // x0
  bool v31; // w22
  __int64 v32; // x23
  int v33; // w0
  __int64 v34; // x23
  int v35; // w0
  __int64 v36; // x23
  __int64 v37; // x0
  __int64 v38; // x8
  __int64 v39; // x23
  int v40; // w0
  __int64 v41; // x23
  int v42; // w0
  __int64 v43; // x23
  __int64 v44; // x0
  __int64 v45; // x0
  int v46; // w0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x1
  int v51; // w23
  int v52; // w19
  unsigned __int64 v53; // x3
  unsigned __int64 v54; // x4
  char v55; // w24
  const char *v56; // x0
  const char *v57; // x2
  char v58; // w0
  __int64 v59; // x22
  __int64 v60; // x0
  unsigned int v61; // w0
  _QWORD v62[12]; // [xsp+8h] [xbp-A8h] BYREF
  _QWORD v63[9]; // [xsp+68h] [xbp-48h] BYREF

  v63[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 968);
  v3 = *(_QWORD *)(a1 + 208);
  if ( v2 )
  {
    if ( *(_DWORD *)(a1 + 916) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "msm_geni_serial_prep_dma_tx", v4, v4 / 0x3E8);
      if ( !*(_DWORD *)(a1 + 1496) )
        goto LABEL_9;
LABEL_6:
      v5 = -5;
      goto LABEL_7;
    }
    v4 = 0;
    if ( *(_DWORD *)(a1 + 1496) )
      goto LABEL_6;
  }
  else
  {
    v4 = -22;
    if ( *(_DWORD *)(a1 + 1496) )
      goto LABEL_6;
  }
LABEL_9:
  LODWORD(v62[0]) = 0;
  v7 = _kfifo_out_linear(v3 + 376, v62, 4096);
  v8 = *(_QWORD *)(v3 + 392);
  v9 = v62[0];
  v10 = v7;
  v11 = *(_DWORD *)(v3 + 388);
  if ( v7 <= 0xFF )
  {
    uart_write_wakeup(a1);
    if ( !v10 )
    {
      v5 = -1;
      goto LABEL_7;
    }
  }
  v12 = (unsigned int)(v11 * v9);
  if ( (int)v10 >= 32 )
    v13 = 32;
  else
    v13 = v10;
  v14 = *(_QWORD *)(a1 + 936);
  v15 = v8 + v12;
  memset(v63, 0, 64);
  memset(v62, 0, sizeof(v62));
  hex_dump_to_buffer(v15, v13, 32, 1, v63, 64, 0);
  scnprintf(v62, 96, "%s[0x%.10x:%d] : %s", "DMA Tx", 0, v10, (const char *)v63);
  ipc_log_string(v14, "%s : %s\n", "dump_ipc", (const char *)v62);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s : %s\n");
  ipc_log_string(*(_QWORD *)(a1 + 960), "%s: cts_count:%d\n", "msm_geni_serial_prep_dma_tx", *(_DWORD *)(a1 + 216));
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: cts_count:%d\n");
  if ( !*(_DWORD *)(a1 + 916) )
  {
LABEL_21:
    if ( *(_BYTE *)(a1 + 2000) == 1 )
    {
      if ( v10 < 0x10 )
      {
        if ( v10 >= 8 )
          v28 = 8;
        else
          v28 = v10;
        v29 = (unsigned int *)(*(_QWORD *)(a1 + 16) + 624LL);
        *(_DWORD *)(a1 + 816) = v28;
        *(_BYTE *)(a1 + 2001) = 1;
        writel_relaxed(v28, v29);
        writel_relaxed(0x8000000u, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1536LL));
        __dsb(0xFu);
        inited = msm_geni_serial_tx_immediate_dma((_QWORD *)(a1 + 712), v15, *(unsigned int *)(a1 + 816));
        v5 = 0;
        v27 = *(_QWORD *)(a1 + 968);
        if ( !v27 )
          goto LABEL_7;
        goto LABEL_63;
      }
      v23 = *(const char ***)(a1 + 624);
      if ( !v23 )
      {
        v5 = -22;
        goto LABEL_39;
      }
      v24 = is_vmalloc_addr(v15);
      if ( (v24 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
      {
        v55 = v24;
        dma_map_single_attrs___already_done = 1;
        v56 = (const char *)dev_driver_string(v23);
        v57 = v23[14];
        if ( !v57 )
          v57 = *v23;
        _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v56, v57);
        v58 = v55;
        __break(0x800u);
        v25 = (__int64 *)(a1 + 808);
        if ( (v58 & 1) != 0 )
          goto LABEL_27;
      }
      else
      {
        v25 = (__int64 *)(a1 + 808);
        if ( (v24 & 1) != 0 )
        {
LABEL_27:
          *v25 = -1;
LABEL_28:
          v5 = -5;
LABEL_39:
          ipc_log_string(*(_QWORD *)(a1 + 960), "Error %d Failed to map tx buffer\n", v5);
          _ftrace_dbg(*(_QWORD *)(a1 + 344), "Error %d Failed to map tx buffer\n");
          goto LABEL_40;
        }
      }
      v59 = v10 & 0xFFFFFFF0;
      v60 = dma_map_page_attrs(
              v23,
              ((unsigned __int64)((v15 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
              v15 & 0xFFF,
              v59,
              1,
              0);
      *v25 = v60;
      if ( v60 == -1 )
        goto LABEL_28;
      if ( (v60 & 0xF) != 0 )
      {
        dma_unmap_page_attrs(*(_QWORD *)(a1 + 624), v60, v59, 1, 0);
        v61 = msm_geni_serial_align_tx_buf(a1, (void *)v15, (unsigned int)v59);
        if ( v61 )
        {
          v5 = v61;
          ipc_log_string(*(_QWORD *)(a1 + 960), "Error Failed to obtain aligned tx buffers\n");
          _ftrace_dbg(*(_QWORD *)(a1 + 344), "Error Failed to obtain aligned tx buffers\n");
          goto LABEL_40;
        }
        writel_relaxed(v59, (unsigned int *)(*(_QWORD *)(a1 + 16) + 624LL));
        writel_relaxed(0x8000000u, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1536LL));
        __dsb(0xFu);
        inited = geni_se_tx_init_dma(a1 + 712, *(_QWORD *)(a1 + 2024), v59);
      }
      else
      {
        writel_relaxed(v59, (unsigned int *)(*(_QWORD *)(a1 + 16) + 624LL));
        writel_relaxed(0x8000000u, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1536LL));
        __dsb(0xFu);
        inited = geni_se_tx_dma_prep(a1 + 712, v15, v59, v25);
        v5 = inited;
        if ( (_DWORD)inited )
        {
LABEL_40:
          ipc_log_string(*(_QWORD *)(a1 + 960), "%s: TX DMA map Fail %d\n", "msm_geni_serial_prep_dma_tx", v5);
          _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: TX DMA map Fail %d\n");
          if ( (*(_BYTE *)(a1 + 1036) & 1) == 0 )
          {
            v30 = *(_QWORD *)(a1 + 960);
            *(_DWORD *)(a1 + 1120) = 7;
            ipc_log_string(v30, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 7);
            _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
          }
          writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a1 + 16) + 624LL));
          *(_BYTE *)(a1 + 1038) = 0;
          *(_BYTE *)(a1 + 1040) = 1;
          *(_DWORD *)(a1 + 1048) = 0;
          v31 = msm_serial_try_disable_interrupts(a1);
          writel_relaxed(4u, (unsigned int *)(*(_QWORD *)(a1 + 712) + 1540LL));
          if ( geni_wait_for_cmd_done(a1, v31) )
          {
            v32 = *(_QWORD *)(a1 + 984);
            v33 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
            ipc_log_string(v32, "%s: tx_cancel fail 0x%x\n", "msm_geni_serial_prep_dma_tx", v33);
            v34 = *(_QWORD *)(a1 + 960);
            v35 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
            ipc_log_string(v34, "%s: tx_cancel failed 0x%x\n", "msm_geni_serial_prep_dma_tx", v35);
            v36 = *(_QWORD *)(a1 + 344);
            readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
            _ftrace_dbg(v36, "%s: tx_cancel failed 0x%x\n");
            if ( (*(_BYTE *)(a1 + 1036) & 1) == 0 )
            {
              v37 = *(_QWORD *)(a1 + 960);
              *(_DWORD *)(a1 + 1120) = 8;
              ipc_log_string(v37, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 8);
              _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
            }
            geni_se_dump_dbg_regs((_QWORD *)a1);
            v38 = *(_QWORD *)(a1 + 712);
            *(_BYTE *)(a1 + 1038) = 0;
            *(_DWORD *)(a1 + 1048) = 0;
            writel_relaxed(2u, (unsigned int *)(v38 + 1540));
            if ( geni_wait_for_cmd_done(a1, v31) )
            {
              v39 = *(_QWORD *)(a1 + 984);
              v40 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
              ipc_log_string(v39, "%s: tx abort failed 0x%x\n", "msm_geni_serial_prep_dma_tx", v40);
              v41 = *(_QWORD *)(a1 + 960);
              v42 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
              ipc_log_string(v41, "%s: tx abort failed 0x%x\n", "msm_geni_serial_prep_dma_tx", v42);
              v43 = *(_QWORD *)(a1 + 344);
              readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
              _ftrace_dbg(v43, "%s: tx abort failed 0x%x\n");
              if ( (*(_BYTE *)(a1 + 1036) & 1) == 0 )
              {
                v44 = *(_QWORD *)(a1 + 960);
                *(_DWORD *)(a1 + 1120) = 9;
                ipc_log_string(v44, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 9);
                _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
              }
              geni_se_dump_dbg_regs((_QWORD *)a1);
            }
            else if ( (*(_BYTE *)(a1 + 1036) & 1) == 0 )
            {
              v45 = *(_QWORD *)(a1 + 960);
              *(_DWORD *)(a1 + 1120) = 0;
              ipc_log_string(v45, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 0);
              _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
            }
            writel_relaxed(0x80000001, (unsigned int *)(*(_QWORD *)(a1 + 16) + 684LL));
            __dsb(0xFu);
            v46 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 684LL));
            ipc_log_string(*(_QWORD *)(a1 + 960), "%s(): rfr = 0x%x\n", "msm_geni_serial_allow_rx", v46);
            _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s(): rfr = 0x%x\n");
            msm_geni_serial_set_manual_flow(1, a1);
            writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a1 + 16) + 32LL));
          }
          if ( *(_DWORD *)(a1 + 584) == 2 )
          {
            if ( (readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3648LL)) & 1) != 0 )
            {
              v47 = *(_QWORD *)(a1 + 16);
              *(_BYTE *)(a1 + 1038) = 0;
              *(_DWORD *)(a1 + 1048) = 0;
              writel_relaxed(1u, (unsigned int *)(v47 + 3160));
              if ( geni_wait_for_cmd_done(a1, v31) )
              {
                ipc_log_string(*(_QWORD *)(a1 + 960), "%s: tx fsm reset failed\n", "msm_geni_serial_prep_dma_tx");
                _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: tx fsm reset failed\n");
                if ( (*(_BYTE *)(a1 + 1036) & 1) == 0 )
                {
                  v48 = *(_QWORD *)(a1 + 960);
                  *(_DWORD *)(a1 + 1120) = 10;
                  ipc_log_string(v48, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 10);
                  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
                }
                geni_se_dump_dbg_regs((_QWORD *)a1);
              }
              else if ( (*(_BYTE *)(a1 + 1036) & 1) == 0 )
              {
                v49 = *(_QWORD *)(a1 + 960);
                *(_DWORD *)(a1 + 1120) = 0;
                ipc_log_string(v49, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 0);
                _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
              }
            }
            v50 = *(_QWORD *)(a1 + 808);
            if ( v50 )
            {
              geni_se_tx_dma_unprep(a1 + 712, v50, *(unsigned int *)(a1 + 816));
              *(_QWORD *)(a1 + 808) = 0;
            }
          }
          *(_DWORD *)(a1 + 816) = 0;
          msm_geni_serial_enable_interrupts(a1);
          *(_BYTE *)(a1 + 1040) = 0;
          v27 = *(_QWORD *)(a1 + 968);
          if ( !v27 )
            goto LABEL_7;
          goto LABEL_63;
        }
      }
      v5 = 0;
      *(_DWORD *)(a1 + 816) = v59;
      v27 = *(_QWORD *)(a1 + 968);
      if ( !v27 )
      {
LABEL_7:
        _ReadStatusReg(SP_EL0);
        return v5;
      }
    }
    else
    {
      writel_relaxed(v10, (unsigned int *)(*(_QWORD *)(a1 + 16) + 624LL));
      writel_relaxed(0x8000000u, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1536LL));
      __dsb(0xFu);
      inited = geni_se_tx_dma_prep(a1 + 712, v15, v10, a1 + 808);
      v5 = inited;
      if ( (_DWORD)inited )
        goto LABEL_40;
      *(_DWORD *)(a1 + 816) = v10;
      v27 = *(_QWORD *)(a1 + 968);
      if ( !v27 )
        goto LABEL_7;
    }
LABEL_63:
    if ( v4 && *(_DWORD *)(a1 + 916) )
    {
      v51 = *(_DWORD *)(a1 + 816);
      v52 = *(_DWORD *)(a1 + 1000);
      v53 = sched_clock(inited) - v4;
      v54 = v53 / 0x3E8;
      if ( v51 )
      {
        if ( v52 )
          ipc_log_string(
            v27,
            "%s:took %llu nsec(%llu usec) for %u bytes with freq %u\n",
            "msm_geni_serial_prep_dma_tx",
            v53,
            v54,
            v51,
            v52);
        else
          ipc_log_string(
            v27,
            "%s:took %llu nsec(%llu usec) for %u bytes\n",
            "msm_geni_serial_prep_dma_tx",
            v53,
            v54,
            v51);
      }
      else
      {
        ipc_log_string(v27, "%s:took %llu nsec(%llu usec)\n", "msm_geni_serial_prep_dma_tx", v53, v54);
      }
    }
    goto LABEL_7;
  }
  v19 = *(_DWORD *)(a1 + 576);
  if ( v19 < 5 )
  {
    *(_DWORD *)(a1 + 1520 + 48LL * v19 + 16) = *(_DWORD *)(a1 + 816);
    v16 = sched_clock(v16);
    v20 = *(_DWORD *)(a1 + 576);
    if ( v20 <= 4 )
    {
      v21 = a1 + 1520 + 48LL * v20;
      if ( v20 == 4 )
        v22 = 0;
      else
        v22 = v20 + 1;
      *(_DWORD *)(a1 + 576) = v22;
      *(_QWORD *)(v21 + 24) = v16;
      goto LABEL_21;
    }
  }
  __break(0x5512u);
  return msm_geni_serial_align_tx_buf(v16, v17, v18);
}
