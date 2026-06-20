__int64 __fastcall hal_delayed_reg_write(__int64 a1, unsigned __int8 *a2, __int64 a3, unsigned int a4)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned __int64 v18; // x8
  unsigned int v25; // w9
  unsigned int v28; // w9
  unsigned int v31; // w8
  unsigned int v32; // w8
  unsigned int v35; // w10
  unsigned int v37; // w10
  unsigned int v40; // w9

  if ( (int)hif_get_bandwidth_level(*(_QWORD *)a1) > 2
    || (result = pld_is_device_awake(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL)), (_DWORD)result) )
  {
    _X8 = (unsigned int *)(a1 + 74420);
    __asm { PRFM            #0x11, [X8] }
    do
      v25 = __ldxr(_X8);
    while ( __stxr(v25 + 1, _X8) );
    ++*((_DWORD *)a2 + 55);
    if ( (*(_BYTE *)(a1 + 74224) & 1) != 0 )
      return hal_write32_mb_0(a1, (unsigned int)(a3 - *(_DWORD *)(a1 + 16)), a4);
    else
      return writel_6(a4, a3);
  }
  else if ( a2[192] )
  {
    if ( is_hal_verbose_debug_enabled == 1 )
      result = qdf_trace_msg(
                 0x46u,
                 8u,
                 "%s: Already in progress srng ring id 0x%x addr 0x%pK val %u",
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 "hal_reg_write_enqueue",
                 *a2,
                 a3,
                 a4);
    _X8 = (unsigned int *)(a1 + 74416);
    __asm { PRFM            #0x11, [X8] }
    do
      v28 = __ldxr(_X8);
    while ( __stxr(v28 + 1, _X8) );
    ++*((_DWORD *)a2 + 54);
  }
  else
  {
    _X9 = (unsigned int *)(a1 + 74528);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v31 = __ldxr(_X9);
      v32 = v31 + 1;
    }
    while ( __stlxr(v32, _X9) );
    __dmb(0xBu);
    v18 = *(_QWORD *)(a1 + 74464) + ((unsigned __int64)(v32 & 0x1F) << 6);
    if ( *(_BYTE *)(v18 + 24) )
    {
      return qdf_trace_msg(0x46u, 2u, "%s: queue full", v9, v10, v11, v12, v13, v14, v15, v16, "hal_reg_write_enqueue");
    }
    else
    {
      _X9 = (unsigned int *)(a1 + 74408);
      __asm { PRFM            #0x11, [X9] }
      do
        v35 = __ldxr(_X9);
      while ( __stxr(v35 + 1, _X9) );
      ++*((_DWORD *)a2 + 52);
      _X9 = (unsigned int *)(a1 + 74428);
      __asm { PRFM            #0x11, [X9] }
      do
        v37 = __ldxr(_X9);
      while ( __stxr(v37 + 1, _X9) );
      *(_QWORD *)v18 = a2;
      *(_QWORD *)(v18 + 8) = a3;
      *(_DWORD *)(v18 + 60) = *a2;
      *(_DWORD *)(v18 + 16) = a4;
      __isb(0xFu);
      *(_QWORD *)(v18 + 32) = _ReadStatusReg(CNTVCT_EL0);
      __dsb(0xEu);
      *(_BYTE *)(v18 + 24) = 1;
      __dsb(0xEu);
      a2[192] = 1;
      _X8 = (unsigned int *)(a1 + 74536);
      __asm { PRFM            #0x11, [X8] }
      do
        v40 = __ldxr(_X8);
      while ( __stxr(v40 + 1, _X8) );
      if ( is_hal_verbose_debug_enabled == 1 )
        qdf_trace_msg(
          0x46u,
          8u,
          "%s: write_idx %u srng ring id 0x%x addr 0x%pK val %u",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          "hal_reg_write_enqueue");
      return queue_work_on(32, *(_QWORD *)(a1 + 74520), a1 + 74472);
    }
  }
  return result;
}
