__int64 __fastcall sde_core_irq_disable(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  unsigned int v11; // w24
  __int64 v12; // x9
  __int64 v13; // x8
  __int64 v14; // x26
  __int64 v15; // x0
  __int64 v17; // x27
  unsigned int v18; // w9
  unsigned int v24; // w11
  __int64 v25; // x0
  unsigned int v26; // w28
  __int64 v27; // x8
  __int64 (*v28)(void); // x8
  const char *v29; // x1
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 || !a2 || !a3 )
  {
    v29 = "sde_core_irq_disable";
    goto LABEL_39;
  }
  v11 = 0;
  do
  {
    v12 = *(_QWORD *)(a1 + 1896);
    if ( !v12 || (v13 = *(_QWORD *)(a1 + 1920)) == 0 )
    {
      v29 = "_sde_core_irq_disable";
LABEL_39:
      printk(&unk_223EAA, v29);
      return (unsigned int)-22;
    }
    v14 = *(unsigned int *)(a2 + 4LL * (int)v11);
    if ( (v14 & 0x80000000) != 0 || *(_DWORD *)(v12 + 328) <= (unsigned int)v14 )
    {
      printk(&unk_27D8FF, "_sde_core_irq_disable");
      return (unsigned int)-22;
    }
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "irq_idx=%d enable_count=%d\n", v14, *(_DWORD *)(v13 + 4 * v14));
      v13 = *(_QWORD *)(a1 + 1920);
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_core_irq_disable",
      183,
      -1,
      v14,
      *(_DWORD *)(v13 + 4 * v14),
      -1059143953,
      a8,
      vars0);
    v15 = raw_spin_lock_irqsave(*(_QWORD *)(a1 + 1896) + 344LL);
    _X8 = (unsigned int *)(*(_QWORD *)(a1 + 1920) + 4 * v14);
    v17 = v15;
    v18 = *_X8;
    do
    {
      if ( !v18 )
      {
        v25 = *(_QWORD *)(a1 + 1896);
LABEL_21:
        raw_spin_unlock_irqrestore(v25 + 344, v17);
        v26 = 0;
        if ( (_drm_debug & 4) == 0 )
          goto LABEL_30;
LABEL_29:
        _drm_dev_dbg(0, 0, 0, "irq_idx=%d ret=%d\n", v14, v26);
        goto LABEL_30;
      }
      __asm { PRFM            #0x11, [X8] }
      while ( 1 )
      {
        v24 = __ldxr(_X8);
        if ( v24 != v18 )
          break;
        if ( !__stlxr(v18 - 1, _X8) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v24 == v18;
      v18 = v24;
    }
    while ( !_ZF );
    v25 = *(_QWORD *)(a1 + 1896);
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 1920) + 4 * v14) )
      goto LABEL_21;
    v27 = *(unsigned int *)(v25 + 28);
    if ( (unsigned int)v27 >= 3 )
    {
      __break(0x5512u);
      JUMPOUT(0x1014DC);
    }
    v28 = *(__int64 (**)(void))(v25 + 8 * v27 + 80);
    if ( !v28 )
      goto LABEL_21;
    if ( *((_DWORD *)v28 - 1) != -364294940 )
      __break(0x8228u);
    v26 = v28();
    raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 1896) + 344LL, v17);
    if ( !v26 )
    {
      if ( (_drm_debug & 4) == 0 )
        goto LABEL_30;
      goto LABEL_29;
    }
    printk(&unk_253A74, "_sde_core_irq_disable");
    if ( (_drm_debug & 4) != 0 )
      goto LABEL_29;
LABEL_30:
    ++v11;
  }
  while ( v11 < a3 && !v26 );
  return v26;
}
