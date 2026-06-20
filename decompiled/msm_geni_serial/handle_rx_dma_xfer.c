__int64 __fastcall handle_rx_dma_xfer(__int64 a1, __int64 a2)
{
  char v3; // w28
  __int64 v4; // x19
  unsigned __int64 v5; // x27
  __int64 v6; // x26
  unsigned int v7; // w0
  unsigned int v8; // w23
  __int64 v9; // x0
  _BOOL4 v10; // w21
  char v11; // w9
  int v12; // w4
  __int64 v13; // x0
  char v14; // w9
  int v15; // w4
  __int64 v16; // x0
  __int64 v17; // x0
  int v18; // w4
  __int64 v19; // x0
  __int64 v20; // x19
  unsigned __int64 v21; // x21
  int v22; // w0
  int v23; // w0
  _DWORD *v24; // x8
  unsigned int v25; // w24
  unsigned __int8 *v26; // x1
  __int64 v27; // x26
  __int64 v28; // x0
  __int64 v29; // x1
  int inserted; // w26
  int v31; // w21
  __int64 v32; // x27
  __int64 v33; // x25
  int v34; // w8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  int v38; // w8
  __int64 v39; // x19
  void *v40; // x0
  unsigned int v41; // w8
  __int64 v42; // x0
  __int64 v43; // x19
  int v44; // w25
  unsigned __int64 v45; // x3
  unsigned __int64 v46; // x4
  __int64 v47; // x0
  unsigned int *v48; // x19
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x19
  __int64 v52; // x0
  unsigned __int64 v54; // [xsp+10h] [xbp-D0h]
  unsigned __int64 v55; // [xsp+18h] [xbp-C8h]
  __int64 v56; // [xsp+20h] [xbp-C0h]
  __int64 v57; // [xsp+28h] [xbp-B8h]
  __int64 v58; // [xsp+30h] [xbp-B0h] BYREF
  __int64 v59; // [xsp+38h] [xbp-A8h]
  __int64 v60; // [xsp+40h] [xbp-A0h]
  __int64 v61; // [xsp+48h] [xbp-98h]
  __int64 v62; // [xsp+50h] [xbp-90h]
  __int64 v63; // [xsp+58h] [xbp-88h]
  __int64 v64; // [xsp+60h] [xbp-80h]
  __int64 v65; // [xsp+68h] [xbp-78h]
  __int64 v66; // [xsp+70h] [xbp-70h]
  __int64 v67; // [xsp+78h] [xbp-68h]
  __int64 v68; // [xsp+80h] [xbp-60h]
  __int64 v69; // [xsp+88h] [xbp-58h]
  __int64 v70; // [xsp+90h] [xbp-50h] BYREF
  __int64 v71; // [xsp+98h] [xbp-48h]
  __int64 v72; // [xsp+A0h] [xbp-40h]
  __int64 v73; // [xsp+A8h] [xbp-38h]
  __int64 v74; // [xsp+B0h] [xbp-30h]
  __int64 v75; // [xsp+B8h] [xbp-28h]
  __int64 v76; // [xsp+C0h] [xbp-20h]
  __int64 v77; // [xsp+C8h] [xbp-18h]
  __int64 v78; // [xsp+D0h] [xbp-10h]

  v3 = a1;
  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 968);
  if ( v4 )
  {
    if ( *(_DWORD *)(a2 + 916) )
    {
      v5 = sched_clock(a1);
      ipc_log_string(v4, "%s:start at %llu nsec(%llu usec)\n", "handle_rx_dma_xfer", v5, v5 / 0x3E8);
    }
    else
    {
      v5 = 0;
    }
  }
  else
  {
    v5 = -22;
  }
  v6 = raw_spin_lock_irqsave(a2 + 1112);
  v7 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 16) + 3392LL));
  if ( !v7 )
  {
    v10 = 0;
    goto LABEL_81;
  }
  v8 = v7;
  v9 = writel_relaxed(v7, (unsigned int *)(*(_QWORD *)(a2 + 16) + 3396LL));
  if ( (v8 & 8) != 0 )
  {
    ipc_log_string(*(_QWORD *)(a2 + 960), "%s Rx Reset done dma_rx_status=0x%x\n", "handle_rx_dma_xfer", v8);
    _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s Rx Reset done dma_rx_status=0x%x\n");
    if ( (v8 & 0x20) == 0 )
    {
LABEL_9:
      if ( (v8 & 0x40) == 0 )
        goto LABEL_10;
      goto LABEL_18;
    }
  }
  else if ( (v8 & 0x20) == 0 )
  {
    goto LABEL_9;
  }
  v11 = *(_BYTE *)(a2 + 1036);
  v12 = *(_DWORD *)(a2 + 248) + 1;
  *(_DWORD *)(a2 + 248) = v12;
  if ( (v11 & 1) == 0 )
  {
    v13 = *(_QWORD *)(a2 + 960);
    *(_DWORD *)(a2 + 1120) = 17;
    ipc_log_string(v13, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 17);
    _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s uart_error_code %d");
    v12 = *(_DWORD *)(a2 + 248);
  }
  ipc_log_string(*(_QWORD *)(a2 + 960), "%s dma_rx_status:0x%x Rx Parity error:%d\n", "handle_rx_dma_xfer", v8, v12);
  _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s dma_rx_status:0x%x Rx Parity error:%d\n");
  if ( (v8 & 0x40) == 0 )
  {
LABEL_10:
    if ( (v8 & 0x180) == 0 )
      goto LABEL_11;
LABEL_21:
    v17 = *(_QWORD *)(a2 + 960);
    v18 = *(_DWORD *)(a2 + 252) + 1;
    *(_DWORD *)(a2 + 252) = v18;
    ipc_log_string(v17, "%s dma_rx_status:0x%x Rx Break error:%d\n", "handle_rx_dma_xfer", v8, v18);
    _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s dma_rx_status:0x%x Rx Break error:%d\n");
    if ( (*(_BYTE *)(a2 + 1036) & 1) == 0 )
    {
      v19 = *(_QWORD *)(a2 + 960);
      *(_DWORD *)(a2 + 1120) = 18;
      ipc_log_string(v19, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 18);
      _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s uart_error_code %d");
    }
    v9 = geni_se_dump_dbg_regs((_QWORD *)a2);
    if ( (v8 & 3) == 0 )
      goto LABEL_77;
LABEL_24:
    v20 = *(_QWORD *)(a2 + 968);
    if ( v20 )
    {
      if ( *(_DWORD *)(a2 + 916) )
      {
        v21 = sched_clock(v9);
        ipc_log_string(v20, "%s:start at %llu nsec(%llu usec)\n", "msm_geni_serial_handle_dma_rx", v21, v21 / 0x3E8);
      }
      else
      {
        v21 = 0;
      }
    }
    else
    {
      v21 = -22;
    }
    v22 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 16) + 64LL));
    if ( (v22 & 0x1000) == 0 )
    {
      ipc_log_string(*(_QWORD *)(a2 + 960), "%s: GENI: 0x%x\n", "msm_geni_serial_handle_dma_rx", v22);
      _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s: GENI: 0x%x\n");
      goto LABEL_72;
    }
    if ( *(_QWORD *)(a2 + 824) )
    {
      v23 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 16) + 3412LL));
      if ( v23 )
      {
        v24 = *(_DWORD **)(a2 + 824);
        v25 = v23;
        if ( !*v24 && (v23 < 5 || !*(_DWORD *)((char *)v24 + (unsigned int)v23 - 4)) )
        {
          ipc_log_string(*(_QWORD *)(a2 + 944), "%s RX Invalid packet\n", "check_rx_buf");
          _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s RX Invalid packet\n");
          geni_se_dump_dbg_regs((_QWORD *)a2);
          _const_udelay(8590000);
        }
        if ( (v8 & 0x20) != 0 )
          goto LABEL_72;
        v56 = v6;
        v26 = *(unsigned __int8 **)(a2 + 824);
        if ( !*(_DWORD *)(a2 + 1344) )
        {
LABEL_41:
          v28 = *(_QWORD *)(a2 + 208);
          LOBYTE(v58) = 0;
          v57 = v28;
          inserted = _tty_insert_flip_string_flags(v28, v26, &v58, 0, v25);
          v54 = v21;
          v55 = v5;
          if ( v25 == inserted )
          {
            inserted = v25;
          }
          else
          {
            ipc_log_string(
              *(_QWORD *)(a2 + 944),
              "%s: ret %d rx_bytes %d\n",
              "msm_geni_serial_handle_dma_rx",
              inserted,
              v25);
            _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s: ret %d rx_bytes %d\n");
            v25 -= inserted;
            if ( v25 )
            {
              v31 = 0;
              v32 = *(_QWORD *)(a2 + 824) + inserted;
              while ( 1 )
              {
                v33 = v25 >= 0x100 ? 256LL : v25;
                ipc_log_string(
                  *(_QWORD *)(a2 + 944),
                  "%s: To copy %d, try copying %d\n",
                  "msm_geni_serial_handle_dma_rx",
                  v25,
                  v33);
                _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s: To copy %d, try copying %d\n");
                LOBYTE(v58) = 0;
                if ( (_DWORD)v33 != (unsigned int)_tty_insert_flip_string_flags(v57, v32 + v31, &v58, 0, v33) )
                  break;
                v25 -= v33;
                v31 += v33;
                inserted += v33;
                if ( !v25 )
                  goto LABEL_57;
              }
              ipc_log_string(
                *(_QWORD *)(a2 + 944),
                "%s: Unable to copy %d bytes rx_bytes %d\n",
                "msm_geni_serial_handle_dma_rx",
                v33,
                v25);
              _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s: Unable to copy %d bytes rx_bytes %d\n");
              if ( (*(_BYTE *)(a2 + 1036) & 1) == 0 )
              {
                v36 = *(_QWORD *)(a2 + 960);
                *(_DWORD *)(a2 + 1120) = 14;
                ipc_log_string(v36, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 14);
                _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s uart_error_code %d");
              }
            }
          }
LABEL_57:
          *(_DWORD *)(a2 + 232) += inserted;
          tty_flip_buffer_push(v57, v29);
          v37 = *(_QWORD *)(a2 + 824);
          if ( inserted >= 32 )
            v38 = 32;
          else
            v38 = inserted;
          v39 = *(_QWORD *)(a2 + 944);
          v76 = 0;
          v77 = 0;
          v74 = 0;
          v75 = 0;
          v72 = 0;
          v73 = 0;
          v70 = 0;
          v71 = 0;
          v68 = 0;
          v69 = 0;
          v66 = 0;
          v67 = 0;
          v64 = 0;
          v65 = 0;
          v62 = 0;
          v63 = 0;
          v60 = 0;
          v61 = 0;
          v58 = 0;
          v59 = 0;
          hex_dump_to_buffer(v37, v38, 32, 1, &v70, 64, 0);
          scnprintf(&v58, 96, "%s[0x%.10x:%d] : %s", "DMA Rx", 0, inserted, (const char *)&v70);
          ipc_log_string(v39, "%s : %s\n", "dump_ipc", (const char *)&v58);
          _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s : %s\n");
          v40 = memset(*(void **)(a2 + 824), 0, (unsigned int)inserted);
          v41 = *(_DWORD *)(a2 + 1120);
          if ( v41 <= 0x16 && ((1 << v41) & 0x460000) != 0 && (*(_BYTE *)(a2 + 1036) & 1) == 0 )
          {
            v42 = *(_QWORD *)(a2 + 960);
            *(_DWORD *)(a2 + 1120) = 0;
            ipc_log_string(v42, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 0);
            _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s uart_error_code %d");
          }
          v5 = v55;
          v6 = v56;
          v43 = *(_QWORD *)(a2 + 968);
          if ( v43 && v54 && *(_DWORD *)(a2 + 916) )
          {
            v44 = *(_DWORD *)(a2 + 1000);
            v45 = sched_clock(v40) - v54;
            v46 = v45 / 0x3E8;
            if ( v25 )
            {
              if ( v44 )
                ipc_log_string(
                  v43,
                  "%s:took %llu nsec(%llu usec) for %u bytes with freq %u\n",
                  "msm_geni_serial_handle_dma_rx",
                  v45,
                  v46,
                  v25,
                  v44);
              else
                ipc_log_string(
                  v43,
                  "%s:took %llu nsec(%llu usec) for %u bytes\n",
                  "msm_geni_serial_handle_dma_rx",
                  v45,
                  v46,
                  v25);
            }
            else
            {
              ipc_log_string(v43, "%s:took %llu nsec(%llu usec)\n", "msm_geni_serial_handle_dma_rx", v45, v46);
            }
          }
          goto LABEL_72;
        }
        v27 = *(_QWORD *)(a2 + 944);
        if ( *v26 == *(unsigned __int8 *)(a2 + 924) )
        {
          ipc_log_string(*(_QWORD *)(a2 + 944), "%s Found wakeup byte\n", "msm_geni_find_wakeup_byte");
          _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s Found wakeup byte\n");
          *(_DWORD *)(a2 + 1344) = 0;
          v26 = *(unsigned __int8 **)(a2 + 824);
          goto LABEL_41;
        }
        if ( (int)v25 >= 32 )
          v34 = 32;
        else
          v34 = v25;
        v35 = *(_QWORD *)(a2 + 824);
        v76 = 0;
        v77 = 0;
        v74 = 0;
        v75 = 0;
        v72 = 0;
        v73 = 0;
        v70 = 0;
        v71 = 0;
        v68 = 0;
        v69 = 0;
        v66 = 0;
        v67 = 0;
        v64 = 0;
        v65 = 0;
        v62 = 0;
        v63 = 0;
        v60 = 0;
        v61 = 0;
        v58 = 0;
        v59 = 0;
        hex_dump_to_buffer(v35, v34, 32, 1, &v70, 64, 0);
        scnprintf(&v58, 96, "%s[0x%.10x:%d] : %s", "Dropped Rx", 0, v25, (const char *)&v70);
        ipc_log_string(v27, "%s : %s\n", "dump_ipc", (const char *)&v58);
        _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s : %s\n");
        ipc_log_string(
          *(_QWORD *)(a2 + 944),
          "%s dropping Rx data as wakeup byte not found in %d bytes\n",
          "msm_geni_serial_handle_dma_rx",
          v25);
        _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s dropping Rx data as wakeup byte not found in %d bytes\n");
        memset(*(void **)(a2 + 824), 0, v25);
        v6 = v56;
      }
      else
      {
        ipc_log_string(*(_QWORD *)(a2 + 944), "%s: Size %d\n", "msm_geni_serial_handle_dma_rx", 0);
        _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s: Size %d\n");
      }
    }
    else
    {
      ipc_log_string(*(_QWORD *)(a2 + 944), "%s: NULL Rx_buf\n", "msm_geni_serial_handle_dma_rx");
      _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s: NULL Rx_buf\n");
    }
LABEL_72:
    v47 = *(_QWORD *)(a2 + 960);
    if ( (v8 & 0x4000) != 0 )
    {
      ipc_log_string(v47, "%s not mapping rx dma\n", "handle_rx_dma_xfer");
      _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s not mapping rx dma\n");
    }
    else
    {
      ipc_log_string(v47, "%s mapping rx dma\n", "handle_rx_dma_xfer");
      _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s mapping rx dma\n");
      v48 = *(unsigned int **)(a2 + 16);
      if ( v48 && *(_QWORD *)(a2 + 872) )
      {
        writel_relaxed(7u, v48 + 851);
        writel_relaxed(*(_DWORD *)(a2 + 872), v48 + 844);
        writel_relaxed(*(_DWORD *)(a2 + 876), v48 + 845);
        writel_relaxed(0, v48 + 846);
        __dsb(0xFu);
        writel_relaxed(0x800u, v48 + 847);
      }
    }
    goto LABEL_77;
  }
LABEL_18:
  v14 = *(_BYTE *)(a2 + 1036);
  v15 = *(_DWORD *)(a2 + 240) + 1;
  *(_DWORD *)(a2 + 240) = v15;
  if ( (v14 & 1) == 0 )
  {
    v16 = *(_QWORD *)(a2 + 960);
    *(_DWORD *)(a2 + 1120) = 22;
    ipc_log_string(v16, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 22);
    _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s uart_error_code %d");
    v15 = *(_DWORD *)(a2 + 240);
  }
  ipc_log_string(*(_QWORD *)(a2 + 960), "%s dma_rx_status:0x%x Rx Framing error:%d\n", "handle_rx_dma_xfer", v8, v15);
  _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s dma_rx_status:0x%x Rx Framing error:%d\n");
  v9 = geni_se_dump_dbg_regs((_QWORD *)a2);
  if ( (v8 & 0x180) != 0 )
    goto LABEL_21;
LABEL_11:
  if ( (v8 & 3) != 0 )
    goto LABEL_24;
LABEL_77:
  if ( (v8 & 4) != 0 )
  {
    ipc_log_string(*(_QWORD *)(a2 + 960), "%s dma_rx_status:0x%x\n", "handle_rx_dma_xfer", v8);
    _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s dma_rx_status:0x%x\n");
    if ( (*(_BYTE *)(a2 + 1036) & 1) == 0 )
    {
      v49 = *(_QWORD *)(a2 + 960);
      *(_DWORD *)(a2 + 1120) = 19;
      ipc_log_string(v49, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 19);
      _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s uart_error_code %d");
    }
  }
  v10 = (v8 & 0x400B) != 0;
LABEL_81:
  v50 = raw_spin_unlock_irqrestore(a2 + 1112, v6);
  v51 = *(_QWORD *)(a2 + 968);
  if ( v51 && v5 && *(_DWORD *)(a2 + 916) )
  {
    v52 = sched_clock(v50);
    ipc_log_string(v51, "%s:took %llu nsec(%llu usec)\n", "handle_rx_dma_xfer", v52 - v5, (v52 - v5) / 0x3E8);
  }
  _ReadStatusReg(SP_EL0);
  return (v3 & 0x30) != 0 || v10;
}
