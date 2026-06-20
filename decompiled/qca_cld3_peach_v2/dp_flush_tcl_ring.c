__int64 __fastcall dp_flush_tcl_ring(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  unsigned int v11; // w20
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 v14; // x20
  __int64 v15; // x21
  unsigned __int64 StatusReg; // x8
  int v17; // w9
  int v18; // w8
  __int64 v19; // x9
  __int64 v21; // x0
  __int64 v22; // x8
  unsigned __int64 v23; // x13
  __int64 v24; // x10
  __int64 v25; // x8
  __int64 v26; // x1
  unsigned int v32; // w0
  __int64 v33; // x8
  _DWORD *v34; // x2
  __int64 v35; // x8
  unsigned __int64 v39; // x9

  if ( a2 < 5 )
  {
    v14 = *(_QWORD *)(a1 + 8);
    v10 = *(_QWORD *)(v14 + 80LL * a2 + 6800);
    if ( !v10 )
    {
      qdf_trace_msg(
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
        "hal_srng_try_access_start",
        v12,
        v13);
      return 4294967274LL;
    }
    v15 = *(_QWORD *)(v14 + 1128);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      if ( (unsigned int)raw_spin_trylock(v10 + 80) )
      {
LABEL_7:
        v17 = *(_DWORD *)(v10 + 116);
        v18 = **(_DWORD **)(v10 + 128);
        *(_DWORD *)(v10 + 136) = v18;
        if ( v17 )
        {
          if ( (*(_BYTE *)(v10 + 78) & 4) != 0 )
          {
            v19 = *(unsigned int *)(v10 + 120);
            if ( (_DWORD)v19 != v18 )
            {
              _X22 = *(_QWORD *)(v10 + 16) + 4 * v19;
              if ( _X22 )
              {
                v21 = *(_QWORD *)(*(_QWORD *)(v15 + 8) + 40LL);
                if ( (*(_BYTE *)(v21 + 844) & 0x40) == 0 )
                {
                  v22 = _X22 << 8 >> 8;
                  v23 = (unsigned __int64)(v22 + 0x8000000000LL) >> 38;
                  v24 = memstart_addr + v22 + 0x8000000000LL;
                  v25 = v22 - kimage_voffset;
                  if ( v23 )
                    v26 = v25;
                  else
                    v26 = v24;
                  _dma_sync_single_for_cpu(v21, v26);
                }
                __asm { PRFM            #0, [X22] }
              }
            }
          }
        }
        v32 = hif_rtpm_get(0, 4u);
        if ( v32 )
        {
          v33 = *(_QWORD *)(v10 + 88);
          v11 = v32;
          if ( (v33 & 1) != 0 )
          {
            *(_QWORD *)(v10 + 88) = v33 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v10 + 80);
          }
          else
          {
            raw_spin_unlock(v10 + 80);
          }
          goto LABEL_32;
        }
        v34 = *(_DWORD **)(v10 + 144);
        if ( (*(_DWORD *)(v10 + 76) & 0x80000000) != 0 )
        {
          *v34 = *(_DWORD *)(v10 + 120);
          v35 = *(_QWORD *)(v10 + 88);
          if ( (v35 & 1) == 0 )
            goto LABEL_22;
        }
        else
        {
          hal_delayed_reg_write(*(_QWORD *)(v14 + 1128), v10, v34, *(unsigned int *)(v10 + 120));
          v35 = *(_QWORD *)(v10 + 88);
          if ( (v35 & 1) == 0 )
          {
LABEL_22:
            raw_spin_unlock(v10 + 80);
LABEL_23:
            hif_rtpm_put(4, 4u);
            return 0;
          }
        }
        *(_QWORD *)(v10 + 88) = v35 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v10 + 80);
        goto LABEL_23;
      }
    }
    else if ( (unsigned int)raw_spin_trylock_bh(v10 + 80) )
    {
      *(_QWORD *)(v10 + 88) |= 1uLL;
      goto LABEL_7;
    }
    return 4294967274LL;
  }
  __break(0x5512u);
LABEL_32:
  _X8 = (unsigned __int64 *)(v10 + 176);
  __asm { PRFM            #0x11, [X8] }
  do
    v39 = __ldxr(_X8);
  while ( __stxr(v39 | 2, _X8) );
  ++*(_DWORD *)(v10 + 168);
  return v11;
}
