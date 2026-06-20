__int64 __fastcall hal_srng_access_start_3(
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
  __int64 v18; // x0
  __int64 v19; // x8
  unsigned __int64 v20; // x13
  __int64 v21; // x10
  __int64 v22; // x8
  __int64 v23; // x1

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
      v18 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL);
      if ( (*(_BYTE *)(v18 + 844) & 0x40) == 0 )
      {
        v19 = _X21 << 8 >> 8;
        v20 = (unsigned __int64)(v19 + 0x8000000000LL) >> 38;
        v21 = memstart_addr + v19 + 0x8000000000LL;
        v22 = v19 - kimage_voffset;
        if ( v20 )
          v23 = v22;
        else
          v23 = v21;
        _dma_sync_single_for_cpu(v18, v23);
      }
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
