__int64 __fastcall sde_core_irq_enable(
        _QWORD *a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  unsigned int i; // w23
  __int64 v13; // x9
  __int64 v14; // x8
  __int64 v15; // x27
  __int64 v17; // x24
  __int64 v18; // x0
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 v22; // x24
  _DWORD *v23; // x9
  __int64 v24; // x0
  unsigned int v25; // w28
  unsigned int v31; // w8
  unsigned int v32; // w8
  const char *v33; // x1
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a1 && a2 && a3 )
  {
    for ( i = 1; ; ++i )
    {
      v13 = a1[237];
      if ( !v13 || (v14 = a1[240]) == 0 || !a1[241] )
      {
        v33 = "_sde_core_irq_enable";
        goto LABEL_36;
      }
      v15 = *(unsigned int *)(a2 + 4LL * (int)(i - 1));
      if ( (v15 & 0x80000000) != 0 || *(_DWORD *)(v13 + 328) <= (unsigned int)v15 )
      {
        printk(&unk_27D8FF, "_sde_core_irq_enable");
        return (unsigned int)-22;
      }
      if ( (_drm_debug & 4) != 0 )
      {
        _drm_dev_dbg(0, 0, 0, "irq_idx=%d enable_count=%d\n", v15, *(_DWORD *)(v14 + 4 * v15));
        v14 = a1[240];
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_core_irq_enable",
        119,
        -1,
        v15,
        *(_DWORD *)(v14 + 4 * v15),
        -1059143953,
        a8,
        vars0);
      _X9 = (unsigned int *)(a1[240] + 4 * v15);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v31 = __ldxr(_X9);
        v32 = v31 + 1;
      }
      while ( __stlxr(v32, _X9) );
      __dmb(0xBu);
      if ( v32 != 1 )
        goto LABEL_24;
      v17 = raw_spin_lock_irqsave(a1 + 242);
      if ( *(_QWORD *)(a1[239] + 16 * v15) == a1[239] + 16 * v15 )
        printk(&unk_2702CB, "_sde_core_irq_enable");
      raw_spin_unlock_irqrestore(a1 + 242, v17);
      v18 = raw_spin_lock_irqsave(a1[237] + 344LL);
      v20 = a1[237];
      v21 = *(unsigned int *)(v20 + 28);
      if ( (unsigned int)v21 >= 3 )
      {
        __break(0x5512u);
        __asm { SM3TT2A         V23.4S, V10.4S, V29.S[2] }
        return sde_core_irq_disable(v18);
      }
      v22 = v18;
      v23 = *(_DWORD **)(v20 + 8 * v21 + 56);
      if ( !v23 )
        break;
      v24 = a1[237];
      if ( *(v23 - 1) != -364294940 )
        __break(0x8229u);
      v25 = ((__int64 (__fastcall *)(__int64, _QWORD))v23)(v24, (unsigned int)v15);
      raw_spin_unlock_irqrestore(a1[237] + 344LL, v22);
      if ( v25 )
      {
        printk(&unk_24CA65, "_sde_core_irq_enable");
        if ( (_drm_debug & 4) != 0 )
        {
LABEL_25:
          _drm_dev_dbg(0, 0, 0, "irq_idx=%d ret=%d\n", v15, v25);
          if ( i >= a3 )
            return v25;
          goto LABEL_26;
        }
      }
      else if ( (_drm_debug & 4) != 0 )
      {
        goto LABEL_25;
      }
LABEL_21:
      if ( i >= a3 )
        return v25;
LABEL_26:
      if ( v25 )
        return v25;
    }
    raw_spin_unlock_irqrestore(v20 + 344, v18);
LABEL_24:
    v25 = 0;
    if ( (_drm_debug & 4) != 0 )
      goto LABEL_25;
    goto LABEL_21;
  }
  v33 = "sde_core_irq_enable";
LABEL_36:
  printk(&unk_223EAA, v33);
  return (unsigned int)-22;
}
