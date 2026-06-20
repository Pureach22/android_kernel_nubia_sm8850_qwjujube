__int64 __fastcall dp_lapb_tcl_hp_update_timer_handler(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x29
  __int64 v3; // x30
  __int64 v4; // x23
  __int64 v6; // x24
  __int64 v7; // x25
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned __int64 StatusReg; // x26
  __int64 v17; // x0
  __int64 v18; // x0
  int v19; // w9
  int v20; // w8
  __int64 v21; // x9
  __int64 v23; // x0
  __int64 v24; // x8
  unsigned __int64 v25; // x13
  __int64 v26; // x10
  __int64 v27; // x8
  __int64 v28; // x1
  __int64 v34; // x8
  __int64 v35; // x0
  _DWORD *v37; // x2
  __int64 v38; // x8
  unsigned __int64 v41; // x9
  __int64 v42; // [xsp+0h] [xbp-50h]
  __int64 v43; // [xsp+8h] [xbp-48h]

  if ( *(unsigned __int8 *)(a1 - 23) >= 5uLL )
  {
    __break(0x5512u);
    goto LABEL_34;
  }
  v42 = v2;
  v43 = v3;
  v4 = *(_QWORD *)(a1 - 8);
  v6 = *(_QWORD *)(v4 + 1128);
  v1 = *(_QWORD *)(v4 + 80LL * *(unsigned __int8 *)(a1 - 23) + 6800);
  v7 = ktime_get(a1) + 20000;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( !v1 )
    {
      v17 = qdf_trace_msg(
              0x38u,
              2u,
              "%s: Error: Invalid hal_ring\n",
              v8,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              "hal_srng_try_access_start",
              v42,
              v43);
      goto LABEL_8;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0
      && (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0
      && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      break;
    }
    v17 = raw_spin_trylock(v1 + 80);
    if ( (_DWORD)v17 )
      goto LABEL_13;
LABEL_8:
    v18 = ktime_get(v17);
    if ( v18 >= v7 )
    {
      v35 = ktime_get(v18);
      hrtimer_forward(a1, v35, 200000);
      return 1;
    }
  }
  v17 = raw_spin_trylock_bh(v1 + 80);
  if ( !(_DWORD)v17 )
    goto LABEL_8;
  *(_QWORD *)(v1 + 88) |= 1uLL;
LABEL_13:
  v19 = *(_DWORD *)(v1 + 116);
  v20 = **(_DWORD **)(v1 + 128);
  *(_DWORD *)(v1 + 136) = v20;
  if ( v19 )
  {
    if ( (*(_BYTE *)(v1 + 78) & 4) != 0 )
    {
      v21 = *(unsigned int *)(v1 + 120);
      if ( (_DWORD)v21 != v20 )
      {
        _X21 = *(_QWORD *)(v1 + 16) + 4 * v21;
        if ( _X21 )
        {
          v23 = *(_QWORD *)(*(_QWORD *)(v6 + 8) + 40LL);
          if ( (*(_BYTE *)(v23 + 844) & 0x40) == 0 )
          {
            v24 = _X21 << 8 >> 8;
            v25 = (unsigned __int64)(v24 + 0x8000000000LL) >> 38;
            v26 = memstart_addr + v24 + 0x8000000000LL;
            v27 = v24 - kimage_voffset;
            if ( v25 )
              v28 = v27;
            else
              v28 = v26;
            _dma_sync_single_for_cpu(v23, v28);
          }
          __asm { PRFM            #0, [X21] }
        }
      }
    }
  }
  if ( !(unsigned int)hif_rtpm_get(0, 4u) )
  {
    v37 = *(_DWORD **)(v1 + 144);
    if ( (*(_DWORD *)(v1 + 76) & 0x80000000) != 0 )
    {
      *v37 = *(_DWORD *)(v1 + 120);
      v38 = *(_QWORD *)(v1 + 88);
      if ( (v38 & 1) == 0 )
        goto LABEL_28;
    }
    else
    {
      hal_delayed_reg_write(*(_QWORD *)(v4 + 1128), (unsigned __int8 *)v1, (__int64)v37, *(_DWORD *)(v1 + 120));
      v38 = *(_QWORD *)(v1 + 88);
      if ( (v38 & 1) == 0 )
      {
LABEL_28:
        raw_spin_unlock(v1 + 80);
LABEL_29:
        hif_rtpm_put(4, 4u);
        ++*(_DWORD *)(a1 + 92);
        return 0;
      }
    }
    *(_QWORD *)(v1 + 88) = v38 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v1 + 80);
    goto LABEL_29;
  }
  v34 = *(_QWORD *)(v1 + 88);
  if ( (v34 & 1) != 0 )
  {
    *(_QWORD *)(v1 + 88) = v34 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v1 + 80);
  }
  else
  {
    raw_spin_unlock(v1 + 80);
  }
LABEL_34:
  _X8 = (unsigned __int64 *)(v1 + 176);
  __asm { PRFM            #0x11, [X8] }
  do
    v41 = __ldxr(_X8);
  while ( __stxr(v41 | 2, _X8) );
  ++*(_DWORD *)(v1 + 168);
  return 0;
}
