void __fastcall msm_geni_serial_handle_isr(__int64 a1, __int64 *a2, char a3)
{
  __int64 v6; // x25
  __int64 v7; // x21
  __int64 v8; // x28
  unsigned __int64 v9; // x20
  __int64 v10; // x8
  unsigned int v11; // w24
  unsigned int v12; // w0
  __int64 v13; // x8
  unsigned int v14; // w21
  int v15; // w8
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 v19; // x11
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  int v23; // w0
  __int64 v24; // x8
  int v25; // w25
  int v26; // w23
  unsigned int v27; // w0
  __int16 v28; // w22
  _BOOL4 v29; // w27
  char v30; // w25
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x26
  unsigned int v34; // w27
  unsigned int v35; // w0
  bool v36; // w21
  __int64 v37; // x22
  int v38; // w0
  unsigned int v39; // w25
  unsigned int v40; // w22
  int v41; // w0
  unsigned int v42; // w23
  unsigned int v43; // w28
  __int64 v44; // x2
  int v45; // w25
  int v46; // w9
  bool v47; // zf
  char v48; // w28
  __int64 v49; // x24
  int v50; // w4
  const char *v51; // x25
  __int64 v52; // x0
  __int64 v53; // x0
  int v54; // w4
  __int64 v55; // x21
  __int64 v56; // x1
  _DWORD *v57; // x8
  __int64 v58; // x1
  __int64 v59; // x0
  __int64 *v60; // [xsp+0h] [xbp-20h]
  char v61; // [xsp+8h] [xbp-18h]
  char v62[4]; // [xsp+Ch] [xbp-14h] BYREF
  char v63[4]; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v64; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v65; // [xsp+18h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 208);
  v7 = *(_QWORD *)(a1 + 968);
  v8 = *(_QWORD *)(v6 + 152);
  if ( v7 )
  {
    if ( *(_DWORD *)(a1 + 916) )
    {
      v9 = sched_clock(a1);
      ipc_log_string(v7, "%s:start at %llu nsec(%llu usec)\n", "msm_geni_serial_handle_isr", v9, v9 / 0x3E8);
      v10 = *(_QWORD *)(a1 + 264);
      if ( !v10 )
        goto LABEL_11;
    }
    else
    {
      v9 = 0;
      v10 = *(_QWORD *)(a1 + 264);
      if ( !v10 )
        goto LABEL_11;
    }
  }
  else
  {
    v9 = -22;
    v10 = *(_QWORD *)(a1 + 264);
    if ( !v10 )
      goto LABEL_11;
  }
  if ( *(_DWORD *)(a1 + 316) == *(__int16 *)(v10 + 74) && *(_DWORD *)(a1 + 1116) )
  {
    ipc_log_string(*(_QWORD *)(a1 + 984), "%s. Console in suspend state\n", "msm_geni_serial_handle_isr");
    goto LABEL_109;
  }
LABEL_11:
  v11 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1552LL));
  v12 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1600LL));
  v13 = *(_QWORD *)(a1 + 264);
  v14 = v12;
  if ( v13 && *(_DWORD *)(a1 + 316) == *(__int16 *)(v13 + 74) )
    ipc_log_string(*(_QWORD *)(a1 + 984), "%s. sirq 0x%x mirq:0x%x\n", "msm_geni_serial_handle_isr", v12, v11);
  writel_relaxed(v11, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1560LL));
  writel_relaxed(v14, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1608LL));
  if ( (v11 & 4) == 0 )
  {
    if ( (v11 & 0xC00000) != 0 )
      ++*(_DWORD *)(a1 + 216);
    if ( (v14 & 0x2000000) != 0 )
    {
      v15 = *(_DWORD *)(a1 + 244);
      v63[0] = 0;
      v62[0] = 4;
      *(_DWORD *)(a1 + 244) = v15 + 1;
      v16 = *(_QWORD *)(v6 + 144);
      if ( *(_BYTE *)(v16 + 28) == 1
        && (v17 = *(unsigned int *)(v16 + 8), v18 = *(unsigned int *)(v16 + 12), (unsigned int)v17 < (unsigned int)v18) )
      {
        v19 = v16 + v17;
        *(_BYTE *)(v19 + 32) = 0;
        *(_BYTE *)(v19 + 32 + v18) = 4;
        *(_DWORD *)(v16 + 8) = v17 + 1;
      }
      else
      {
        _tty_insert_flip_string_flags(v6, v63, v62, 0, 1);
      }
      ipc_log_string(
        *(_QWORD *)(a1 + 960),
        "%s.sirq 0x%x buf_overrun:%d\n",
        "msm_geni_serial_handle_isr",
        v14,
        *(_DWORD *)(a1 + 256));
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s.sirq 0x%x buf_overrun:%d\n");
      if ( (*(_BYTE *)(a1 + 1036) & 1) == 0 )
      {
        v22 = *(_QWORD *)(a1 + 960);
        *(_DWORD *)(a1 + 1120) = 16;
        ipc_log_string(v22, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 16);
        _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
      }
    }
    v23 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 600LL));
    v24 = *(_QWORD *)(a1 + 16);
    if ( v23 )
    {
      v25 = readl_relaxed((unsigned int *)(v24 + 3136));
      v26 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3392LL));
      if ( v11 || v14 || v25 || v26 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 992),
          "%s: sirq:0x%x mirq:0x%x dma_txirq:0x%x\n",
          "msm_geni_serial_handle_isr",
          v14,
          v11,
          v25);
        _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: sirq:0x%x mirq:0x%x dma_txirq:0x%x\n");
        ipc_log_string(
          *(_QWORD *)(a1 + 992),
          "%s: dma_rxirq:0x%x is_irq_masked:%d cts_count:%d\n",
          "msm_geni_serial_handle_isr",
          v26,
          a3 & 1,
          *(_DWORD *)(a1 + 216));
        _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: dma_rxirq:0x%x is_irq_masked:%d cts_count:%d\n");
        if ( v8 )
        {
LABEL_36:
          v27 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3136LL));
          if ( v27 )
          {
            v28 = v27;
            writel_relaxed(v27, (unsigned int *)(*(_QWORD *)(a1 + 16) + 3140LL));
            if ( (v28 & 0x4008) != 0 )
            {
              v29 = 1;
              goto LABEL_100;
            }
            if ( (v28 & 1) != 0 )
            {
              msm_geni_serial_handle_dma_tx(a1);
              if ( *(_DWORD *)(a1 + 1120) == 20 )
                msm_geni_update_uart_error_code(a1, 0);
            }
          }
          v29 = (v11 & 0x30) != 0;
LABEL_100:
          v31 = handle_rx_dma_xfer(v14, a1);
          v36 = v31;
          v37 = *(_QWORD *)(a1 + 968);
          if ( !v37 )
            goto LABEL_105;
LABEL_101:
          if ( v9 && *(_DWORD *)(a1 + 916) )
          {
            v59 = sched_clock(v31);
            ipc_log_string(
              v37,
              "%s:took %llu nsec(%llu usec)\n",
              "msm_geni_serial_handle_isr",
              v59 - v9,
              (v59 - v9) / 0x3E8);
            if ( !v29 )
            {
LABEL_107:
              if ( v36 )
              {
                *(_BYTE *)(a1 + 1039) = 1;
                complete(a1 + 1080);
              }
              goto LABEL_109;
            }
LABEL_106:
            *(_BYTE *)(a1 + 1038) = 1;
            complete(a1 + 1048);
            goto LABEL_107;
          }
LABEL_105:
          if ( !v29 )
            goto LABEL_107;
          goto LABEL_106;
        }
      }
      else if ( v8 )
      {
        goto LABEL_36;
      }
      ipc_log_string(*(_QWORD *)(a1 + 992), "Port is closed!\n");
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "Port is closed!\n");
      v35 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3136LL));
      if ( v35 )
        writel_relaxed(v35, (unsigned int *)(*(_QWORD *)(a1 + 16) + 3140LL));
      v31 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3392LL));
      if ( (_DWORD)v31 )
        v31 = writel_relaxed(v31, (unsigned int *)(*(_QWORD *)(a1 + 16) + 3396LL));
      v36 = 0;
      v29 = 0;
      v37 = *(_QWORD *)(a1 + 968);
      if ( !v37 )
        goto LABEL_105;
      goto LABEL_101;
    }
    v30 = readl_relaxed((unsigned int *)(v24 + 64));
    v31 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1556LL));
    if ( (v11 & (unsigned int)v31 & 0x40000001) == 0 )
    {
LABEL_74:
      v47 = (v11 & 0x30) == 0;
      v48 = v14;
      v49 = *(_QWORD *)(a1 + 208);
      v29 = !v47;
      if ( (v14 & 0x600) != 0 )
      {
        v50 = *(_DWORD *)(a1 + 248);
        if ( (v14 & 0x200) != 0 )
          *(_DWORD *)(a1 + 248) = ++v50;
        v51 = "%s.sirq 0x%x parity:%d\n";
        ipc_log_string(*(_QWORD *)(a1 + 960), "%s.sirq 0x%x parity:%d\n", "handle_rx_fifo_xfer", v14, v50);
        v52 = *(_QWORD *)(a1 + 344);
      }
      else
      {
        if ( (v14 & 0x1800) == 0 )
          goto LABEL_84;
        v53 = *(_QWORD *)(a1 + 960);
        v51 = "%s.sirq 0x%x break:%d\n";
        v54 = *(_DWORD *)(a1 + 252) + 1;
        *(_DWORD *)(a1 + 252) = v54;
        ipc_log_string(v53, "%s.sirq 0x%x break:%d\n", "handle_rx_fifo_xfer", v14, v54);
        v52 = *(_QWORD *)(a1 + 344);
      }
      _ftrace_dbg(v52, v51);
LABEL_84:
      if ( (v14 & 0xC000000) != 0 )
      {
        v55 = v14 & 0x630;
        v31 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 2052LL));
        v56 = v31 & 0x1FFFFFF;
        if ( (v31 & 0x1FFFFFF) != 0 )
        {
          v57 = *(_DWORD **)(a1 + 616);
          if ( *(v57 - 1) != -842200017 )
            __break(0x8228u);
          v31 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, bool))v57)(
                  a1,
                  v56,
                  ((unsigned int)v31 >> 28) & 7,
                  (unsigned int)v31 & 0x80000000,
                  v55 != 0);
        }
        if ( v55 || (a3 & 1) != 0 )
        {
          if ( !v55 )
            v31 = tty_flip_buffer_push(v49, v56);
        }
        else
        {
          raw_spin_unlock_irqrestore(a1, *a2);
          tty_flip_buffer_push(v49, v58);
          v31 = raw_spin_lock_irqsave(a1);
          *a2 = v31;
        }
      }
      v36 = (v48 & 0x30) != 0;
      v37 = *(_QWORD *)(a1 + 968);
      if ( !v37 )
        goto LABEL_105;
      goto LABEL_101;
    }
    v32 = *(_QWORD *)(a1 + 264);
    v33 = *(_QWORD *)(a1 + 208);
    if ( v32 && *(_DWORD *)(a1 + 316) == *(__int16 *)(v32 + 74) )
      v34 = 1;
    else
      v34 = *(_DWORD *)(a1 + 556) >> 3;
    v38 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 2048LL));
    v61 = a3;
    if ( (v30 & 1) != 0 )
    {
      v39 = *(_DWORD *)(a1 + 1032);
      if ( (v11 & 1) == 0 )
        goto LABEL_57;
    }
    else
    {
      v39 = *(_DWORD *)(v33 + 376) - *(_DWORD *)(v33 + 380);
      if ( (v11 & 1) == 0 )
        goto LABEL_57;
    }
    if ( !v39 && !v38 )
    {
LABEL_70:
      v31 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1556LL));
      if ( !*(_DWORD *)(a1 + 1032) )
        v31 = writel_relaxed((unsigned int)v31 & 0xBFFFFFFF, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1556LL));
      a3 = v61;
      if ( (unsigned int)(*(_DWORD *)(v33 + 376) - *(_DWORD *)(v33 + 380)) <= 0xFF )
        v31 = uart_write_wakeup(a1);
      goto LABEL_74;
    }
LABEL_57:
    if ( (((*(_DWORD *)(a1 + 552) - (v38 & 0xFFFFFFF)) * v34)
        & ~((int)((*(_DWORD *)(a1 + 552) - (v38 & 0xFFFFFFF)) * v34) >> 31)) >= v39 )
      v40 = v39;
    else
      v40 = ((*(_DWORD *)(a1 + 552) - (v38 & 0xFFFFFFF)) * v34)
          & ~((int)((*(_DWORD *)(a1 + 552) - (v38 & 0xFFFFFFF)) * v34) >> 31);
    if ( v40 )
    {
      v60 = a2;
      if ( !*(_DWORD *)(a1 + 1032) )
      {
        writel_relaxed(v39, (unsigned int *)(*(_QWORD *)(a1 + 16) + 624LL));
        writel_relaxed(0x8000000u, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1536LL));
        __dsb(0xFu);
        *(_DWORD *)(a1 + 1032) = v39;
        v41 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1556LL));
        if ( (v41 & 0x40000000) == 0 )
          writel_relaxed(v41 | 0x40000000, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1556LL));
      }
      v42 = 0;
      v43 = v40;
      do
      {
        if ( v43 >= v34 )
          v44 = v34;
        else
          v44 = v43;
        v64 = 0;
        v45 = _kfifo_out(v33 + 376, &v64, v44);
        writel_relaxed(v64, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1792LL));
        v42 += v45;
        v43 -= v45;
        v46 = *(_DWORD *)(a1 + 1032) - v45;
        *(_DWORD *)(a1 + 236) += v45;
        *(_DWORD *)(a1 + 1032) = v46;
        __dsb(0xEu);
      }
      while ( v42 < v40 );
      writel_relaxed(0x40000000u, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1560LL));
      a2 = v60;
    }
    goto LABEL_70;
  }
  v20 = *(_QWORD *)(a1 + 264);
  if ( v20 && *(_DWORD *)(a1 + 316) == *(__int16 *)(v20 + 74) )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 984),
      "%s Illegal interrupt sirq:0x%x mirq:0x%x\n",
      "msm_geni_serial_handle_isr",
      v14,
      v11);
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 1036) & 1) == 0 )
    {
      v21 = *(_QWORD *)(a1 + 960);
      *(_DWORD *)(a1 + 1120) = 15;
      ipc_log_string(v21, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 15);
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
    }
    ipc_log_string(
      *(_QWORD *)(a1 + 960),
      "%s Illegal interrupt sirq:0x%x mirq:0x%x\n",
      "msm_geni_serial_handle_isr",
      v14,
      v11);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s Illegal interrupt sirq:0x%x mirq:0x%x\n");
  }
LABEL_109:
  _ReadStatusReg(SP_EL0);
}
