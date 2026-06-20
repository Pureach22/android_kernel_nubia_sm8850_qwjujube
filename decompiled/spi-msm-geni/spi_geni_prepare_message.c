__int64 __fastcall spi_geni_prepare_message(__int64 a1, _QWORD *a2)
{
  __int64 v4; // x20
  __int64 v5; // x23
  unsigned __int64 v6; // x27
  __int64 v7; // x0
  unsigned int v8; // w0
  int v9; // w23
  unsigned int v10; // w0
  __int64 v11; // x0
  __int64 result; // x0
  _QWORD *v13; // x19
  char v14; // w0
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  bool v17; // cf
  char v18; // w8
  _QWORD *v19; // x26
  __int64 v20; // x23
  const char **v21; // x24
  __int64 v22; // x25
  char v23; // w0
  __int64 v24; // x0
  __int64 v25; // x23
  const char **v26; // x24
  __int64 v27; // x25
  char v28; // w0
  __int64 v29; // x0
  const char *v30; // x0
  const char *v31; // x2
  const char *v32; // x0
  const char *v33; // x2
  unsigned int v34; // w21
  int v35; // w8
  int v36; // w9
  __int64 v37; // x28
  __int64 v38; // x21
  int v39; // w20
  int v40; // w23
  int v41; // w26
  int v42; // w0
  unsigned int v43; // w22
  int v44; // w25
  unsigned int v45; // w23
  int v46; // w0
  _DWORD *v47; // x8
  int v48; // w24
  int v49; // w19
  int spi_clk_cfg; // w0
  char v51; // w10
  __int64 v52; // x1
  __int64 v53; // x2
  char v54; // w12
  unsigned int v55; // w20
  unsigned int v56; // w19
  unsigned int v57; // w23
  unsigned int v58; // w25
  int v59; // w28
  unsigned int v60; // w26
  int v61; // w24
  __int64 v62; // x21
  unsigned int v63; // w19
  __int64 v64; // x0
  __int64 v65; // x8
  int v66; // w3
  unsigned int v67; // w21
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  char v71; // [xsp+18h] [xbp-18h]
  char v72; // [xsp+18h] [xbp-18h]
  __int64 v73; // [xsp+18h] [xbp-18h]

  _ReadStatusReg(SP_EL0);
  v4 = *(_QWORD *)(a1 + 152);
  v5 = *(_QWORD *)(v4 + 488);
  if ( v5 )
  {
    if ( *(_DWORD *)(v4 + 496) )
    {
      v6 = sched_clock(a1);
      ipc_log_string(v5, "%s:start at %llu nsec(%llu usec)\n", "spi_geni_prepare_message", v6, v6 / 0x3E8);
    }
    else
    {
      v6 = 0;
    }
  }
  else
  {
    v6 = -22;
  }
  if ( *(_BYTE *)(v4 + 501) == 1 )
  {
    if ( *(_BYTE *)(v4 + 224) == 1 )
    {
      v7 = *(_QWORD *)(v4 + 200);
      if ( (*(_WORD *)(v7 + 488) & 7) != 0 )
      {
LABEL_20:
        ipc_log_string(*(_QWORD *)(v4 + 472), "%s: System suspended\n", "spi_geni_prepare_message");
        if ( *(_QWORD *)(v4 + 200) )
          spi_trace_log();
        result = 4294967283LL;
        goto LABEL_83;
      }
      v8 = _pm_runtime_resume(v7, 4);
      if ( (v8 & 0x80000000) != 0 )
        goto LABEL_103;
      if ( *(_BYTE *)(v4 + 505) == 1 )
      {
        v9 = *(_DWORD *)(*(_QWORD *)(v4 + 200) + 480LL);
        if ( v9 <= 0 )
        {
          ipc_log_string(*(_QWORD *)(v4 + 472), "resume usage count mismatch:%d", v9);
          if ( *(_QWORD *)(v4 + 200) )
            spi_trace_log();
        }
      }
    }
    else
    {
      *(_BYTE *)(v4 + 224) = 1;
    }
    if ( *(_BYTE *)(v4 + 502) == 1 )
    {
      v10 = spi_geni_lock_bus(a1);
      if ( v10 )
      {
        v34 = v10;
        ipc_log_string(*(_QWORD *)(v4 + 472), "%s failed: %d\n", "spi_geni_prepare_message", v10);
        v68 = *(_QWORD *)(v4 + 200);
        if ( v68 )
          dev_err(v68, "%s failed: %d\n", "spi_geni_prepare_message", v34);
        else
          printk(&unk_E23C);
        if ( *(_QWORD *)(v4 + 200) )
          goto LABEL_118;
        goto LABEL_104;
      }
    }
  }
  v11 = *(_QWORD *)(v4 + 200);
  if ( *(_DWORD *)(v11 + 500) == 2 && (*(_BYTE *)(v4 + 503) & 1) == 0 )
  {
    if ( (*(_WORD *)(v11 + 488) & 7) != 0 )
      goto LABEL_20;
    v8 = _pm_runtime_resume(v11, 4);
    if ( (v8 & 0x80000000) != 0 )
    {
LABEL_103:
      v34 = v8;
      dev_err(*(_QWORD *)(v4 + 200), "%s:pm_runtime_get_sync failed %d\n", "spi_geni_prepare_message", v8);
      __break(0x800u);
      pm_runtime_put_noidle(*(_QWORD *)(v4 + 200));
      _pm_runtime_set_status(*(_QWORD *)(v4 + 200), 2);
LABEL_104:
      result = v34;
      goto LABEL_83;
    }
  }
  v13 = *(_QWORD **)(a1 + 152);
  v14 = readl_relaxed((unsigned int *)(v13[23] + 100LL));
  v15 = v13[40];
  if ( !v15 || v15 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (v14 & 1) == 0 )
    {
      *(_DWORD *)(v4 + 452) = 2;
      goto LABEL_66;
    }
    *(_DWORD *)(v4 + 452) = -22;
LABEL_95:
    dev_err(*(_QWORD *)(v4 + 200), "%s: Couldn't select mode %d\n", "spi_geni_prepare_message", -22);
    result = 4294967274LL;
    goto LABEL_83;
  }
  v16 = v13[41];
  if ( v16 )
    v17 = v16 >= 0xFFFFFFFFFFFFF001LL;
  else
    v17 = 1;
  v18 = !v17;
  if ( (v14 & 1) != 0 && (v18 & 1) != 0 )
  {
    *(_DWORD *)(v4 + 452) = 3;
    memset(*(void **)(v4 + 304), 0, 0x11D0u);
    geni_se_select_mode(v4, 3);
    v19 = (_QWORD *)*a2;
    if ( (_QWORD *)*a2 == a2 )
    {
      result = 0;
      goto LABEL_83;
    }
    while ( 1 )
    {
      v20 = *(v19 - 13);
      if ( v20 )
      {
        v21 = *(const char ***)(v4 + 288);
        if ( !v21 )
        {
          v34 = -22;
          goto LABEL_108;
        }
        v22 = *((unsigned int *)v19 - 24);
        v23 = is_vmalloc_addr(*(v19 - 13));
        if ( (v23 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
        {
          v71 = v23;
          dma_map_single_attrs___already_done = 1;
          v30 = (const char *)dev_driver_string(v21);
          v31 = v21[14];
          if ( !v31 )
            v31 = *v21;
          _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v30, v31);
          __break(0x800u);
          if ( (v71 & 1) != 0 )
          {
LABEL_106:
            *(v19 - 6) = -1;
LABEL_107:
            v34 = -5;
LABEL_108:
            ipc_log_string(*(_QWORD *)(v4 + 472), "%s: Mapping Rx buffer %d\n", "spi_geni_map_buf", v34);
            v69 = *(_QWORD *)(v4 + 200);
            if ( v69 )
              dev_err(v69, "%s: Mapping Rx buffer %d\n", "spi_geni_map_buf", v34);
            else
              printk(&unk_F13A);
            if ( !*(_QWORD *)(v4 + 200) )
              goto LABEL_104;
LABEL_118:
            spi_trace_log();
            result = v34;
            goto LABEL_83;
          }
        }
        else if ( (v23 & 1) != 0 )
        {
          goto LABEL_106;
        }
        v24 = dma_map_page_attrs(
                v21,
                ((unsigned __int64)((v20 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                v20 & 0xFFF,
                v22,
                2,
                0);
        *(v19 - 6) = v24;
        if ( v24 == -1 )
          goto LABEL_107;
      }
      v25 = *(v19 - 14);
      if ( v25 )
      {
        v26 = *(const char ***)(v4 + 288);
        if ( !v26 )
        {
          v34 = -22;
          goto LABEL_114;
        }
        v27 = *((unsigned int *)v19 - 24);
        v28 = is_vmalloc_addr(*(v19 - 14));
        if ( (v28 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
        {
          v72 = v28;
          dma_map_single_attrs___already_done = 1;
          v32 = (const char *)dev_driver_string(v26);
          v33 = v26[14];
          if ( !v33 )
            v33 = *v26;
          _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v32, v33);
          __break(0x800u);
          if ( (v72 & 1) != 0 )
          {
LABEL_58:
            *(v19 - 7) = -1;
LABEL_59:
            v34 = -5;
LABEL_114:
            ipc_log_string(*(_QWORD *)(v4 + 472), "%s: Mapping Tx buffer %d\n", "spi_geni_map_buf", v34);
            v70 = *(_QWORD *)(v4 + 200);
            if ( v70 )
              dev_err(v70, "%s: Mapping Tx buffer %d\n", "spi_geni_map_buf", v34);
            else
              printk(&unk_E48E);
            if ( !*(_QWORD *)(v4 + 200) )
              goto LABEL_104;
            goto LABEL_118;
          }
        }
        else if ( (v28 & 1) != 0 )
        {
          goto LABEL_58;
        }
        v29 = dma_map_page_attrs(
                v26,
                ((unsigned __int64)((v25 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                v25 & 0xFFF,
                v27,
                1,
                0);
        *(v19 - 7) = v29;
        if ( v29 == -1 )
          goto LABEL_59;
      }
      v19 = (_QWORD *)*v19;
      if ( v19 == a2 )
      {
        result = 0;
        goto LABEL_83;
      }
    }
  }
  v35 = ((v14 & 1) == 0) | v18 & 1;
  if ( v35 )
    v36 = 2;
  else
    v36 = -22;
  *(_DWORD *)(v4 + 452) = v36;
  if ( !v35 )
    goto LABEL_95;
LABEL_66:
  v73 = v4;
  geni_se_select_mode(v4, 2);
  v37 = a2[2];
  v38 = *(_QWORD *)(a1 + 152);
  v39 = *(_DWORD *)(v37 + 944);
  v40 = readl_relaxed((unsigned int *)(*(_QWORD *)(v38 + 184) + 556LL));
  v41 = readl_relaxed((unsigned int *)(*(_QWORD *)(v38 + 184) + 560LL));
  v42 = readl_relaxed((unsigned int *)(*(_QWORD *)(v38 + 184) + 548LL));
  v43 = *(unsigned __int8 *)(v37 + 924);
  v44 = v42;
  if ( v43 >= 0x10
    && (v43 = *(unsigned __int8 *)(v37 + 925), v43 >= 0x10)
    && (v43 = *(unsigned __int8 *)(v37 + 926), v43 >= 0x10)
    && (v43 = *(unsigned __int8 *)(v37 + 927), v43 >= 0x10) )
  {
    ipc_log_string(*(_QWORD *)(v38 + 472), "%s Failed to get the chip select number\n", "setup_fifo_params");
    if ( *(_QWORD *)(v38 + 200) )
      spi_trace_log();
    result = 0xFFFFFFFFLL;
  }
  else
  {
    v45 = v40 & 0xFFFFFFFC;
    if ( (v39 & 0x20) != 0 )
    {
      v45 |= 1u;
      if ( *(_DWORD *)(v38 + 576) == 10 )
      {
        v46 = readl_relaxed((unsigned int *)(*(_QWORD *)(v38 + 184) + 688LL));
        writel_relaxed(v46 | 0x80000000, *(_QWORD *)(v38 + 184) + 688LL);
      }
    }
    v47 = *(_DWORD **)(v37 + 960);
    if ( v47 )
      v48 = v47[1] & 0x3FF | ((*v47 & 0x3FF) << 10);
    else
      v48 = 0;
    v49 = *(unsigned __int8 *)(v37 + 944);
    *(_DWORD *)(v38 + 228) = *(_DWORD *)(v37 + 920);
    *(_DWORD *)(v38 + 232) = *(unsigned __int8 *)(v37 + 940);
    spi_clk_cfg = get_spi_clk_cfg();
    if ( spi_clk_cfg )
    {
      v65 = *(_QWORD *)(v38 + 200);
      v66 = *(_DWORD *)(v38 + 228);
      v67 = spi_clk_cfg;
      dev_err(v65, "Err setting clks ret(%d) for %d\n", spi_clk_cfg, v66);
      v4 = v73;
      result = v67;
      goto LABEL_83;
    }
    v51 = 2 * v39;
    v52 = *(unsigned int *)(v37 + 944);
    v53 = *(unsigned __int8 *)(v37 + 940);
    v54 = v39;
    v55 = (1 << v43) & (v49 << 29 >> 31);
    v56 = v45;
    v57 = v41 & 0xFFFFFFFB;
    v58 = v44 & 0xFFFFFFFE;
    v59 = v51 & 4;
    v60 = v48;
    v61 = v54 & 1;
    spi_setup_word_len(v38, v52, v53);
    writel_relaxed(v56, *(_QWORD *)(v38 + 184) + 556LL);
    writel_relaxed(v43, *(_QWORD *)(v38 + 184) + 592LL);
    writel_relaxed(v58 | v61, *(_QWORD *)(v38 + 184) + 548LL);
    writel_relaxed(v57 | v59, *(_QWORD *)(v38 + 184) + 560LL);
    writel_relaxed(v55, *(_QWORD *)(v38 + 184) + 588LL);
    writel_relaxed(0, *(_QWORD *)(v38 + 184) + 124LL);
    writel_relaxed(1, *(_QWORD *)(v38 + 184) + 72LL);
    writel_relaxed(v60, *(_QWORD *)(v38 + 184) + 632LL);
    ipc_log_string(
      *(_QWORD *)(v38 + 472),
      "%s:Loopback%d demux_sel0x%x demux_op_inv 0x%x clk_cfg 0x%x\n",
      "setup_fifo_params",
      v56,
      v43,
      v55,
      1);
    if ( *(_QWORD *)(v38 + 200) )
      spi_trace_log();
    ipc_log_string(
      *(_QWORD *)(v38 + 472),
      "%s:clk_sel 0x%x cpol %d cpha %d delay 0x%x\n",
      "setup_fifo_params",
      0,
      v57 | v59,
      v58 | v61,
      v60);
    if ( *(_QWORD *)(v38 + 200) )
      spi_trace_log();
    __dsb(0xFu);
    result = 0;
  }
  v4 = v73;
LABEL_83:
  v62 = *(_QWORD *)(v4 + 488);
  if ( v62 && v6 && *(_DWORD *)(v4 + 496) )
  {
    v63 = result;
    v64 = sched_clock(result);
    ipc_log_string(v62, "%s:took %llu nsec(%llu usec)\n", "spi_geni_prepare_message", v64 - v6, (v64 - v6) / 0x3E8);
    result = v63;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
