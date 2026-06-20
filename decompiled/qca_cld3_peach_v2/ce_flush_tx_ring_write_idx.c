_QWORD *__fastcall ce_flush_tx_ring_write_idx(_QWORD *result, char a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x22
  __int64 v4; // x23
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x8
  int v7; // w9
  unsigned int v8; // w20
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 v11; // x1
  unsigned int v12; // w25
  unsigned int v13; // w21
  __int64 v14; // x8
  int v15; // w0
  __int64 v16; // x8
  unsigned __int64 v23; // x8
  unsigned __int64 v26; // x9
  _QWORD v27[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = result;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = result[17];
  v4 = *result;
  if ( (a2 & 1) != 0 )
  {
    _X8 = (unsigned __int64 *)(v3 + 120);
    __asm { PRFM            #0x11, [X8] }
    do
      v26 = __ldxr(_X8);
    while ( __stxr(v26 | 2, _X8) );
  }
  _X9 = (unsigned __int64 *)(v3 + 120);
  __asm { PRFM            #0x11, [X9] }
  do
    v23 = __ldxr(_X9);
  while ( __stlxr(v23 & 0xFFFFFFFFFFFFFFFDLL, _X9) );
  __dmb(0xBu);
  if ( (v23 & 2) != 0 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 21);
    }
    else
    {
      raw_spin_lock_bh(result + 21);
      v2[22] |= 1uLL;
    }
    v6 = *(_QWORD *)(v4 + 616);
    v7 = *((_DWORD *)v2 + 4);
    v27[0] = 0;
    v8 = *(_DWORD *)(v3 + 12);
    v9 = (unsigned int)(*(_DWORD *)(v6 + 352) + v7);
    v10 = *(_QWORD *)(v4 + 30720);
    v11 = *(_QWORD *)(v4 + 40) + v9;
    if ( *(_BYTE *)(v4 + 31089) == 1 && (v12 = v11 - v10, (unsigned int)(v11 - v10) >> 19) )
    {
      pld_lock_reg_window(*(_QWORD *)(v4 + 30760), v27);
      v13 = (v12 >> 19) & 0x3F | 0x40000000;
      writel_1(v13, *(_QWORD *)(v4 + 30720) + 12920LL);
      v14 = *(_QWORD *)(v4 + 30720);
      *(_DWORD *)(v4 + 31092) = (v12 >> 19) & 0x3F;
      v15 = readl_1(v14 + 12920);
      if ( v15 != v13 )
        qdf_trace_msg(
          61,
          2,
          "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
          "hif_reg_write_result_check",
          v13,
          v15,
          12920);
      writel_1(v8, *(_QWORD *)(v4 + 30720) + (*(_QWORD *)&v12 & 0x7FFFFLL) + 0x80000);
      pld_unlock_reg_window(*(_QWORD *)(v4 + 30760), v27);
    }
    else
    {
      writel_1(v8, v11);
    }
    v16 = v2[22];
    if ( (v16 & 1) != 0 )
    {
      v2[22] = v16 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v2 + 21);
    }
    else
    {
      raw_spin_unlock(v2 + 21);
    }
    __isb(0xFu);
    *(_QWORD *)(v3 + 128) = _ReadStatusReg(CNTVCT_EL0);
    result = (_QWORD *)qdf_trace_msg(61, 8, "%s: flushed", "ce_flush_tx_ring_write_idx");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
