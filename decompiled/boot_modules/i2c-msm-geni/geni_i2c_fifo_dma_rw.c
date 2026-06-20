__int64 __fastcall geni_i2c_fifo_dma_rw(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        int *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x22
  __int64 v9; // x8
  __int64 v12; // x0
  int v13; // w3
  __int64 v16; // x27
  int v18; // w0
  __int64 result; // x0
  int v20; // w8
  int v22; // w0
  __int64 v23; // x8
  __int64 v24; // x8

  v8 = a2 + 16LL * a3;
  v9 = *(_QWORD *)(a1 + 1336);
  v12 = *(_QWORD *)(a1 + 5096);
  v13 = *(unsigned __int16 *)(v9 + 4);
  v16 = a3;
  if ( (*(_WORD *)(v8 + 2) & 1) != 0 )
  {
    ipc_log_string(v12, "msgs[%d].len:%d R\n", a3, v13);
    if ( *(_QWORD *)a1 )
      i2c_trace_log();
    writel_relaxed(*(unsigned __int16 *)(v8 + 4), *(_QWORD *)(a1 + 8) + 624LL);
    if ( *(_DWORD *)(a1 + 8956) == 3400000 )
      v22 = 1476395008;
    else
      v22 = 0x10000000;
    result = writel(v22 & 0xF8000000 | a8 & 0x7FFFFFF, *(_QWORD *)(a1 + 4960) + 1536LL);
    if ( *a4 == 2 )
    {
      result = geni_se_rx_dma_prep(a1 + 4960, a7, *(unsigned __int16 *)(v8 + 4), a5);
      if ( (_DWORD)result )
      {
        i2c_put_dma_safe_msg_buf(a7, v8, 0);
        *a4 = 1;
        geni_se_select_mode(a1 + 4960, 1);
        result = geni_i2c_stop_on_bus(a1);
      }
      else
      {
        v24 = *(_QWORD *)(a1 + 9096);
        if ( v24 )
        {
          *(_QWORD *)(v24 + 16 * v16) = a7;
          *(_QWORD *)(*(_QWORD *)(a1 + 9096) + 16 * v16 + 8) = a5;
        }
      }
    }
  }
  else
  {
    ipc_log_string(v12, "msgs[%d].len:%d W\n", a3, v13);
    if ( *(_QWORD *)a1 )
      i2c_trace_log();
    writel_relaxed(*(unsigned __int16 *)(v8 + 4), *(_QWORD *)(a1 + 8) + 620LL);
    if ( *(_DWORD *)(a1 + 8956) == 3400000 )
      v18 = 1342177280;
    else
      v18 = 0x8000000;
    result = writel(v18 & 0xF8000000 | a8 & 0x7FFFFFF, *(_QWORD *)(a1 + 4960) + 1536LL);
    v20 = *a4;
    if ( *a4 == 2 )
    {
      result = geni_se_tx_dma_prep(a1 + 4960, a7, *(unsigned __int16 *)(v8 + 4), a6);
      if ( (_DWORD)result )
      {
        i2c_put_dma_safe_msg_buf(a7, v8, 0);
        *a4 = 1;
        geni_se_select_mode(a1 + 4960, 1);
        result = geni_i2c_stop_on_bus(a1);
      }
      else
      {
        v23 = *(_QWORD *)(a1 + 9096);
        if ( v23 )
        {
          *(_QWORD *)(v23 + 16 * v16) = a7;
          *(_QWORD *)(*(_QWORD *)(a1 + 9096) + 16 * v16 + 8) = a6;
        }
      }
      v20 = *a4;
    }
    if ( v20 == 1 )
      result = writel_relaxed(1, *(_QWORD *)(a1 + 8) + 2060LL);
  }
  __dsb(0xFu);
  return result;
}
