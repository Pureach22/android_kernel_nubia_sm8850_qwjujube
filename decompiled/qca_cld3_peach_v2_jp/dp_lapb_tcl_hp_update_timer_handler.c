__int64 __fastcall dp_lapb_tcl_hp_update_timer_handler(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x20
  __int64 v6; // x29
  __int64 v7; // x30
  __int64 v8; // x23
  __int64 v10; // x24
  __int64 v11; // x25
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int64 StatusReg; // x26
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // x3
  __int64 v25; // x4
  __int64 v26; // x0
  __int64 v27; // x1
  __int64 v28; // x2
  __int64 v29; // x3
  __int64 v30; // x4
  int v31; // w9
  int v32; // w8
  __int64 v33; // x9
  __int64 v35; // x0
  __int64 v36; // x8
  unsigned __int64 v37; // x13
  __int64 v38; // x10
  __int64 v39; // x8
  __int64 v40; // x1
  __int64 v46; // x8
  __int64 v47; // x0
  _DWORD *v49; // x2
  __int64 v50; // x8
  unsigned __int64 v53; // x9
  __int64 v54; // [xsp+0h] [xbp-50h]
  __int64 v55; // [xsp+8h] [xbp-48h]

  if ( *(unsigned __int8 *)(a1 - 23) >= 5uLL )
  {
    __break(0x5512u);
    goto LABEL_34;
  }
  v54 = v6;
  v55 = v7;
  v8 = *(_QWORD *)(a1 - 8);
  v10 = *(_QWORD *)(v8 + 1128);
  v5 = *(_QWORD *)(v8 + 80LL * *(unsigned __int8 *)(a1 - 23) + 6752);
  v11 = ktime_get(a1, a2, a3, a4, a5) + 20000;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( !v5 )
    {
      v21 = qdf_trace_msg(
              0x38u,
              2u,
              "%s: Error: Invalid hal_ring\n",
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              "hal_srng_try_access_start",
              v54,
              v55);
      goto LABEL_8;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0
      && (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0
      && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      break;
    }
    v21 = raw_spin_trylock(v5 + 80);
    if ( (_DWORD)v21 )
      goto LABEL_13;
LABEL_8:
    v26 = ktime_get(v21, v22, v23, v24, v25);
    if ( v26 >= v11 )
    {
      v47 = ktime_get(v26, v27, v28, v29, v30);
      hrtimer_forward(a1, v47, 200000);
      return 1;
    }
  }
  v21 = raw_spin_trylock_bh(v5 + 80);
  if ( !(_DWORD)v21 )
    goto LABEL_8;
  *(_QWORD *)(v5 + 88) |= 1uLL;
LABEL_13:
  v31 = *(_DWORD *)(v5 + 116);
  v32 = **(_DWORD **)(v5 + 128);
  *(_DWORD *)(v5 + 136) = v32;
  if ( v31 )
  {
    if ( (*(_BYTE *)(v5 + 78) & 4) != 0 )
    {
      v33 = *(unsigned int *)(v5 + 120);
      if ( (_DWORD)v33 != v32 )
      {
        _X21 = *(_QWORD *)(v5 + 16) + 4 * v33;
        if ( _X21 )
        {
          v35 = *(_QWORD *)(*(_QWORD *)(v10 + 8) + 40LL);
          if ( (*(_BYTE *)(v35 + 844) & 0x40) == 0 )
          {
            v36 = _X21 << 8 >> 8;
            v37 = (unsigned __int64)(v36 + 0x8000000000LL) >> 38;
            v38 = memstart_addr + v36 + 0x8000000000LL;
            v39 = v36 - kimage_voffset;
            if ( v37 )
              v40 = v39;
            else
              v40 = v38;
            _dma_sync_single_for_cpu(v35, v40);
          }
          __asm { PRFM            #0, [X21] }
        }
      }
    }
  }
  if ( !(unsigned int)hif_rtpm_get(0, 4u) )
  {
    v49 = *(_DWORD **)(v5 + 144);
    if ( (*(_DWORD *)(v5 + 76) & 0x80000000) != 0 )
    {
      *v49 = *(_DWORD *)(v5 + 120);
      v50 = *(_QWORD *)(v5 + 88);
      if ( (v50 & 1) == 0 )
        goto LABEL_28;
    }
    else
    {
      hal_delayed_reg_write(*(_QWORD *)(v8 + 1128), (unsigned __int8 *)v5, (__int64)v49, *(_DWORD *)(v5 + 120));
      v50 = *(_QWORD *)(v5 + 88);
      if ( (v50 & 1) == 0 )
      {
LABEL_28:
        raw_spin_unlock(v5 + 80);
LABEL_29:
        hif_rtpm_put(4, 4u);
        ++*(_DWORD *)(a1 + 92);
        return 0;
      }
    }
    *(_QWORD *)(v5 + 88) = v50 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v5 + 80);
    goto LABEL_29;
  }
  v46 = *(_QWORD *)(v5 + 88);
  if ( (v46 & 1) != 0 )
  {
    *(_QWORD *)(v5 + 88) = v46 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v5 + 80);
  }
  else
  {
    raw_spin_unlock(v5 + 80);
  }
LABEL_34:
  _X8 = (unsigned __int64 *)(v5 + 176);
  __asm { PRFM            #0x11, [X8] }
  do
    v53 = __ldxr(_X8);
  while ( __stxr(v53 | 2, _X8) );
  ++*(_DWORD *)(v5 + 168);
  return 0;
}
