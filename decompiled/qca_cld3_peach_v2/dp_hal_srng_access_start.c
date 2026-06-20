__int64 __fastcall dp_hal_srng_access_start(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 StatusReg; // x8
  int v13; // w9
  int v14; // w8
  __int64 v15; // x9

  if ( a2 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a2 + 80);
    }
    else
    {
      raw_spin_lock_bh(a2 + 80);
      *(_QWORD *)(a2 + 88) |= 1uLL;
    }
    v13 = *(_DWORD *)(a2 + 116);
    v14 = **(_DWORD **)(a2 + 128);
    *(_DWORD *)(a2 + 136) = v14;
    if ( v13
      && (*(_BYTE *)(a2 + 78) & 4) != 0
      && (v15 = *(unsigned int *)(a2 + 120), (_DWORD)v15 != v14)
      && (_X21 = *(_QWORD *)(a2 + 16) + 4 * v15) != 0 )
    {
      if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL) + 844LL) & 0x40) == 0 )
        _dma_sync_single_for_cpu();
      __asm { PRFM            #0, [X21] }
      return 0;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x38u, 2u, "%s: Error: Invalid hal_ring\n", a3, a4, a5, a6, a7, a8, a9, a10, "hal_srng_access_start");
    return 4294967274LL;
  }
}
