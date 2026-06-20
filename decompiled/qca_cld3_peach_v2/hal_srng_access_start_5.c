__int64 __fastcall hal_srng_access_start_5(
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
  __int64 result; // x0
  int v14; // w9
  int v15; // w8
  __int64 v16; // x9
  __int64 v18; // x8
  unsigned __int64 v19; // x13
  __int64 v20; // x10
  __int64 v21; // x8
  __int64 v22; // x1

  if ( !a2 )
    return qdf_trace_msg(
             0x38u,
             2u,
             "%s: Error: Invalid hal_ring\n",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "hal_srng_access_start");
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    result = raw_spin_lock(a2 + 80);
  }
  else
  {
    result = raw_spin_lock_bh(a2 + 80);
    *(_QWORD *)(a2 + 88) |= 1uLL;
  }
  v14 = *(_DWORD *)(a2 + 116);
  v15 = **(_DWORD **)(a2 + 128);
  *(_DWORD *)(a2 + 136) = v15;
  if ( v14 )
  {
    if ( (*(_BYTE *)(a2 + 78) & 4) != 0 )
    {
      v16 = *(unsigned int *)(a2 + 120);
      if ( (_DWORD)v16 != v15 )
      {
        _X21 = *(_QWORD *)(a2 + 16) + 4 * v16;
        if ( _X21 )
        {
          result = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 40LL);
          if ( (*(_BYTE *)(result + 844) & 0x40) == 0 )
          {
            v18 = _X21 << 8 >> 8;
            v19 = (unsigned __int64)(v18 + 0x8000000000LL) >> 38;
            v20 = memstart_addr + v18 + 0x8000000000LL;
            v21 = v18 - kimage_voffset;
            if ( v19 )
              v22 = v21;
            else
              v22 = v20;
            result = _dma_sync_single_for_cpu(result, v22);
          }
          __asm { PRFM            #0, [X21] }
        }
      }
    }
  }
  return result;
}
