void __fastcall msm_geni_uart_gsi_xfer_tx(__int64 a1)
{
  const char ***v2; // x20
  __int64 v3; // x28
  __int64 v4; // x25
  const char **v5; // x26
  _QWORD *v6; // x27
  unsigned int v7; // w0
  __int64 v8; // x23
  int v9; // w24
  unsigned int v10; // w21
  int v11; // w25
  __int64 v12; // x8
  __int64 v13; // x24
  int v14; // w9
  void *v15; // x23
  int chan; // w0
  __int64 v17; // x8
  unsigned __int64 v18; // x10
  __int64 v19; // x8
  __int64 v20; // x10
  _DWORD *v21; // x28
  const char **v22; // x25
  char v23; // w0
  int v24; // w22
  char v25; // w0
  __int64 v26; // x0
  __int64 v27; // x9
  int v28; // w8
  int v29; // w9
  __int64 v30; // x10
  int v31; // w8
  size_t v32; // x2
  __int64 v33; // x8
  __int64 *v34; // x8
  __int64 v35; // x0
  const char **v36; // x20
  __int64 (*v37)(void); // x9
  __int64 v38; // x8
  __int64 (*v39)(void); // x8
  unsigned int v40; // w0
  __int64 v41; // x19
  void (*v42)(void); // x8
  _QWORD *v43; // x8
  const char *v44; // x19
  __int64 v45; // x0
  void (*v46)(void); // x8
  char v47; // w20
  const char *v48; // x0
  const char *v49; // x2
  size_t v50; // x20
  char v51; // w28
  const char *v52; // x0
  const char *v53; // x2
  __int64 v54; // x0
  int v55; // w0
  int v56; // w9
  __int64 *v57; // [xsp+0h] [xbp-C0h]
  _QWORD v58[12]; // [xsp+10h] [xbp-B0h] BYREF
  _QWORD v59[10]; // [xsp+70h] [xbp-50h] BYREF

  v2 = (const char ***)(a1 - 528);
  v59[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 - 8);
  v4 = *(_QWORD *)(a1 - 944);
  v5 = *(const char ***)(a1 - 528);
  ipc_log_string(*(_QWORD *)(a1 - 192), "%s: Start\n", "msm_geni_uart_gsi_xfer_tx");
  v6 = (_QWORD *)(a1 - 808);
  _ftrace_dbg(*(_QWORD *)(a1 - 808), "%s: Start\n");
  LODWORD(v58[0]) = 0;
  v7 = _kfifo_out_linear(v4 + 376, v58, 4096);
  v8 = *(_QWORD *)(v4 + 392);
  v9 = v58[0];
  v10 = v7;
  v11 = *(_DWORD *)(v4 + 388);
  if ( v7 <= 0xFF )
  {
    uart_write_wakeup(a1 - 1152);
    if ( !v10 )
      goto LABEL_52;
  }
  if ( *(_QWORD *)(a1 - 344) )
    goto LABEL_52;
  v12 = (unsigned int)(v11 * v9);
  v57 = (__int64 *)(a1 - 344);
  v13 = *(_QWORD *)(a1 - 216);
  if ( (int)v10 >= 32 )
    v14 = 32;
  else
    v14 = v10;
  v15 = (void *)(v8 + v12);
  memset(v59, 0, 64);
  memset(v58, 0, sizeof(v58));
  hex_dump_to_buffer(v15, v14, 32, 1, v59, 64, 0);
  scnprintf(v58, 96, "%s[0x%.10x:%d] : %s", "DMA Tx", 0, v10, (const char *)v59);
  ipc_log_string(v13, "%s : %s\n", "dump_ipc", (const char *)v58);
  _ftrace_dbg(*v6, "%s : %s\n");
  chan = msm_geni_allocate_chan((_QWORD *)(a1 - 1152));
  if ( chan )
  {
    dev_err(*v6, "%s: Allocation of Channel failed:%d\n", "msm_geni_uart_gsi_xfer_tx", chan);
    goto LABEL_52;
  }
  sg_init_table(*(_QWORD *)(a1 - 8) + 240LL, 3);
  v17 = *(_QWORD *)(a1 - 8);
  v18 = *(_QWORD *)(v17 + 240) & 3LL | ((unsigned __int64)(((v17 + 16) << 8 >> 8) + 0x8000000000LL) >> 12 << 6);
  *(_DWORD *)(v17 + 248) = (v17 + 16) & 0xFFF;
  *(_DWORD *)(v17 + 252) = 16;
  *(_QWORD *)(v17 + 240) = v18 - 0x140000000LL;
  *(_QWORD *)(v3 + 48) = 1;
  *(_QWORD *)(v3 + 56) = 0x20000100000000LL;
  v19 = *(_QWORD *)(a1 - 8);
  v20 = *(_QWORD *)(v19 + 272);
  *(_DWORD *)(v19 + 284) = 16;
  *(_DWORD *)(v19 + 280) = (v3 + 48) & 0xFFF;
  *(_QWORD *)(v19 + 272) = (v20 & 3 | ((unsigned __int64)(((v3 + 48) << 8 >> 8) + 0x8000000000LL) >> 12 << 6))
                         - 0x140000000LL;
  if ( *(_BYTE *)(a1 + 848) == 1 )
  {
    v21 = (_DWORD *)(a1 - 336);
    if ( v10 < 0x10 )
    {
      v30 = *(_QWORD *)(a1 - 8);
      if ( v10 >= 8 )
        v31 = 8;
      else
        v31 = v10;
      *(_BYTE *)(a1 + 849) = 1;
      *v21 = v31;
      *(_DWORD *)(v30 + 80) = 0;
      *(_DWORD *)(*(_QWORD *)(a1 - 8) + 84LL) = 0;
      v32 = (unsigned int)*v21;
      if ( (unsigned int)v32 >= 0x11 && (msm_geni_serial_gsi_xfer_split_tx___already_done & 1) == 0 )
      {
        msm_geni_serial_gsi_xfer_split_tx___already_done = 1;
        v50 = v32;
        _warn_printk(
          "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
          v32,
          "field \"(u8 *)&msm_port->gsi->tx_t.dword[0]\" at ../soc-repo/drivers/tty/serial/msm_geni_serial.c:2317",
          0x10u);
        v32 = v50;
        __break(0x800u);
      }
      memcpy((void *)(*(_QWORD *)(a1 - 8) + 80LL), v15, v32);
      v29 = *v21 & 0xF;
      v28 = 1114624;
    }
    else
    {
      v22 = *v2;
      *(_BYTE *)(a1 + 849) = 0;
      *v21 = v10 & 0xFFFFFFF0;
      if ( !v22 )
      {
        v24 = -22;
        goto LABEL_45;
      }
      v23 = is_vmalloc_addr(v15);
      if ( (v23 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
      {
        v51 = v23;
        dma_map_single_attrs___already_done = 1;
        v52 = (const char *)dev_driver_string(v22);
        v53 = v22[14];
        if ( !v53 )
          v53 = *v22;
        _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v52, v53);
        __break(0x800u);
        if ( (v51 & 1) != 0 )
          goto LABEL_14;
      }
      else if ( (v23 & 1) != 0 )
      {
LABEL_14:
        *v57 = -1;
LABEL_15:
        v24 = -5;
LABEL_45:
        ipc_log_string(*(_QWORD *)(a1 - 192), "Error %d Failed to map tx buffer\n", v24);
        _ftrace_dbg(*v6, "Error %d Failed to map tx buffer\n");
        dma_release_channel(*(_QWORD *)(*(_QWORD *)(a1 - 8) + 8LL));
        dma_release_channel(**(_QWORD **)(a1 - 8));
        *(_QWORD *)(*(_QWORD *)(a1 - 8) + 8LL) = 0;
        **(_QWORD **)(a1 - 8) = 0;
LABEL_46:
        v36 = v5;
        ipc_log_string(*(_QWORD *)(a1 - 192), "Error %d Split gsi transfer failed\n", v24);
        _ftrace_dbg(*v6, "Error %d Split gsi transfer failed\n");
        goto LABEL_47;
      }
      v54 = dma_map_page_attrs(
              v22,
              ((unsigned __int64)(((__int64)((_QWORD)v15 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
              (unsigned __int16)v15 & 0xFFF,
              v10 & 0xFFFFFFF0,
              1,
              0);
      *v57 = v54;
      if ( v54 == -1 )
        goto LABEL_15;
      if ( (v54 & 0xF) != 0 )
      {
        dma_unmap_page_attrs(*v2, v54, v10 & 0xFFFFFFF0, 1, 0);
        v55 = msm_geni_serial_align_tx_buf(a1 - 1152, v15, v10 & 0xFFFFFFF0);
        if ( v55 )
        {
          v24 = v55;
          ipc_log_string(*(_QWORD *)(a1 - 192), "Error Failed to obtain aligned tx buffers\n");
          _ftrace_dbg(*v6, "Error Failed to obtain aligned tx buffers\n");
          goto LABEL_46;
        }
        *(_DWORD *)(*(_QWORD *)(a1 - 8) + 80LL) = *(_QWORD *)(a1 + 872);
        v56 = *(_DWORD *)(a1 + 876);
      }
      else
      {
        *(_DWORD *)(*(_QWORD *)(a1 - 8) + 80LL) = v54;
        v56 = *(_DWORD *)(a1 - 340);
      }
      v28 = 1049088;
      *(_DWORD *)(*(_QWORD *)(a1 - 8) + 84LL) = v56;
      v29 = v10 & 0xFFFFF0;
    }
    goto LABEL_29;
  }
  if ( !v5 )
  {
LABEL_63:
    dev_err(*v6, "%s:Failed to allocate memory\n", "msm_geni_uart_gsi_xfer_tx");
    msm_geni_deallocate_chan(a1 - 1152);
    goto LABEL_52;
  }
  v25 = is_vmalloc_addr(v15);
  if ( (v25 & 1) == 0 || (dma_map_single_attrs___already_done & 1) != 0 )
  {
    if ( (v25 & 1) == 0 )
      goto LABEL_20;
LABEL_62:
    *v57 = -1;
    goto LABEL_63;
  }
  v47 = v25;
  dma_map_single_attrs___already_done = 1;
  v48 = (const char *)dev_driver_string(v5);
  v49 = v5[14];
  if ( !v49 )
    v49 = *v5;
  _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v48, v49);
  __break(0x800u);
  if ( (v47 & 1) != 0 )
    goto LABEL_62;
LABEL_20:
  v26 = dma_map_page_attrs(
          v5,
          ((unsigned __int64)(((__int64)((_QWORD)v15 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
          (unsigned __int16)v15 & 0xFFF,
          v10,
          1,
          0);
  *v57 = v26;
  if ( v26 == -1 )
    goto LABEL_63;
  v27 = *(_QWORD *)(a1 - 8);
  *(_DWORD *)(a1 - 336) = v10;
  *(_DWORD *)(v27 + 80) = v26;
  v28 = 1049088;
  *(_DWORD *)(*(_QWORD *)(a1 - 8) + 84LL) = *(_DWORD *)(a1 - 340);
  v29 = v10 & 0xFFFFFF;
LABEL_29:
  *(_DWORD *)(*(_QWORD *)(a1 - 8) + 88LL) = v29;
  *(_DWORD *)(*(_QWORD *)(a1 - 8) + 92LL) = v28;
  v33 = *(_QWORD *)(a1 - 8);
  *(_DWORD *)(v33 + 312) = (v33 + 80) & 0xFFF;
  *(_QWORD *)(v33 + 304) = (((unsigned __int64)(((v33 + 80) << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL)
                         | *(_QWORD *)(v33 + 304) & 3LL;
  *(_DWORD *)(v33 + 316) = 16;
  v34 = *(__int64 **)(a1 - 8);
  v35 = *v34;
  if ( *v34 )
  {
    v36 = v5;
    if ( *(_QWORD *)v35 && (v37 = *(__int64 (**)(void))(*(_QWORD *)v35 + 272LL)) != nullptr )
    {
      if ( *((_DWORD *)v37 - 1) != -1221891457 )
        __break(0x8229u);
      v35 = v37();
      v34 = *(__int64 **)(a1 - 8);
    }
    else
    {
      v35 = 0;
    }
  }
  else
  {
    v36 = v5;
  }
  v34[74] = v35;
  v38 = *(_QWORD *)(*(_QWORD *)(a1 - 8) + 592LL);
  if ( !v38 )
  {
    dev_err(*v6, "%s:TX descriptor prep failed\n", "msm_geni_uart_gsi_xfer_tx");
LABEL_47:
    if ( (*(_BYTE *)(a1 + 849) & 1) == 0 && *v57 != -1 )
      dma_unmap_page_attrs(v36, *v57, *(unsigned int *)(a1 - 336), 1, 0);
    dma_release_channel(*(_QWORD *)(*(_QWORD *)(a1 - 8) + 8LL));
    dma_release_channel(**(_QWORD **)(a1 - 8));
    *(_QWORD *)(*(_QWORD *)(a1 - 8) + 8LL) = 0;
    **(_QWORD **)(a1 - 8) = 0;
    v45 = *(_QWORD *)(a1 - 192);
    v44 = "%s: Failed to prep Tx descriptor";
    ipc_log_string(v45, "%s: Failed to prep Tx descriptor", "msm_geni_uart_gsi_xfer_tx");
LABEL_51:
    _ftrace_dbg(*v6, v44);
    goto LABEL_52;
  }
  *(_QWORD *)(v38 + 40) = msm_geni_uart_gsi_tx_cb;
  *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 - 8) + 592LL) + 56LL) = *(_QWORD *)(a1 - 8) + 608LL;
  v39 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 - 8) + 592LL) + 24LL);
  if ( *((_DWORD *)v39 - 1) != 1188179853 )
    __break(0x8228u);
  v40 = v39();
  if ( (v40 & 0x80000000) == 0 )
  {
    *(_DWORD *)(a1 + 144) = 0;
    v41 = a1 + 144;
    v42 = *(void (**)(void))(***(_QWORD ***)(v41 - 152) + 360LL);
    if ( *((_DWORD *)v42 - 1) != 905352215 )
      __break(0x8228u);
    v42();
    wait_for_completion_timeout(v41, 25);
    v43 = (_QWORD *)(v41 - 336);
    v44 = "%s: End\n";
    ipc_log_string(*v43, "%s: End\n", "msm_geni_uart_gsi_xfer_tx");
    goto LABEL_51;
  }
  printk(&unk_14AEE, "msm_geni_uart_gsi_xfer_tx", v40);
  v46 = *(void (**)(void))(***(_QWORD ***)(a1 - 8) + 336LL);
  if ( v46 )
  {
    if ( *((_DWORD *)v46 - 1) != -403578064 )
      __break(0x8228u);
    v46();
  }
LABEL_52:
  _ReadStatusReg(SP_EL0);
}
