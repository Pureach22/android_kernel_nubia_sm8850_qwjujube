__int64 __fastcall sde_encoder_phys_vid_control_empulse_irq(__int64 a1, char a2)
{
  const void *v2; // x30
  const void *v4; // x22
  int v6; // w21
  __int64 v7; // x25
  __int64 v8; // x8
  int v9; // w4
  __int64 v10; // x8
  int v11; // w5
  int v13; // w4
  __int64 v14; // x0
  unsigned int v15; // w22
  unsigned int v17; // w20
  __int64 v18; // x0
  int v19; // w4
  unsigned int v25; // w8
  unsigned int v26; // w8
  unsigned int v28; // w8
  unsigned int v29; // w8
  unsigned int v31; // w9
  unsigned int v33; // w8
  char v34; // [xsp+0h] [xbp-10h]

  if ( !a1 )
  {
    printk(&unk_26FCAB, "sde_encoder_phys_vid_control_empulse_irq");
    return (unsigned int)-22;
  }
  v4 = v2;
  mutex_lock(*(_QWORD *)(a1 + 840));
  v6 = *(_DWORD *)(a1 + 852);
  if ( *(_DWORD *)(a1 + 664) == 3 )
    goto LABEL_21;
  v7 = *(_QWORD *)a1;
  if ( (a2 & 1) == 0 && v6 < 1 )
  {
    v15 = -22;
    goto LABEL_30;
  }
  v8 = *(_QWORD *)a1;
  if ( (_drm_debug & 4) != 0 )
  {
    if ( v7 )
    {
      v9 = *(_DWORD *)(v7 + 24);
      v10 = *(_QWORD *)(a1 + 424);
      if ( v10 )
      {
LABEL_8:
        v11 = *(_DWORD *)(v10 + 32) - 1;
LABEL_11:
        _drm_dev_dbg(0, 0, 0, "enc%d intf%d [%pS] enable=%d/%d\n", v9, v11, v4, a2 & 1, *(_DWORD *)(a1 + 852));
        v8 = *(_QWORD *)a1;
        goto LABEL_12;
      }
    }
    else
    {
      v9 = -1;
      v10 = *(_QWORD *)(a1 + 424);
      if ( v10 )
        goto LABEL_8;
    }
    v11 = -1;
    goto LABEL_11;
  }
LABEL_12:
  _X26 = (unsigned int *)(a1 + 852);
  if ( v8 )
    v13 = *(_DWORD *)(v8 + 24);
  else
    v13 = -1;
  v14 = sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_phys_vid_control_empulse_irq",
          1610,
          -1,
          v13,
          a2 & 1,
          *(_DWORD *)(a1 + 852),
          -1059143953,
          v34);
  if ( (a2 & 1) == 0 )
  {
    __asm { PRFM            #0x11, [X26] }
    do
    {
      v28 = __ldxr(_X26);
      v29 = v28 - 1;
    }
    while ( __stlxr(v29, _X26) );
    __dmb(0xBu);
    if ( !v29 )
    {
      if ( *(_BYTE *)(a1 + 984) == 1 )
      {
        hrtimer_cancel(a1 + 920);
        v15 = 0;
        goto LABEL_22;
      }
      v15 = sde_encoder_helper_unregister_irq(a1, 4u);
      if ( !v15 )
        goto LABEL_22;
      __asm { PRFM            #0x11, [X26] }
      do
        v33 = __ldxr(_X26);
      while ( __stxr(v33 + 1, _X26) );
LABEL_30:
      printk(&unk_26C9CC, "sde_encoder_phys_vid_control_empulse_irq");
      if ( *(_QWORD *)a1 )
        v19 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      else
        v19 = -1;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_encoder_phys_vid_control_empulse_irq",
        1640,
        -1,
        v19,
        *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
        a2 & 1,
        v6,
        173);
      goto LABEL_22;
    }
LABEL_21:
    v15 = 0;
    goto LABEL_22;
  }
  __asm { PRFM            #0x11, [X26] }
  do
  {
    v25 = __ldxr(_X26);
    v26 = v25 + 1;
  }
  while ( __stlxr(v26, _X26) );
  __dmb(0xBu);
  if ( v26 != 1 )
    goto LABEL_21;
  if ( *(_DWORD *)(v7 + 888) != 2 )
  {
    if ( *(_BYTE *)(*(_QWORD *)a1 + 750LL) == 1 )
    {
      v14 = drm_mode_vrefresh(a1 + 520);
      v17 = v14;
    }
    else
    {
      v17 = *(_DWORD *)(*(_QWORD *)a1 + 764LL);
    }
    v18 = ktime_get(v14);
    hrtimer_start_range_ns(
      a1 + 920,
      ((unsigned __int64)v17 + 999999999) / v17
    + (v18 - *(_QWORD *)(a1 + 864))
    / (((unsigned __int64)v17 + 999999999)
     / v17)
    * (((unsigned __int64)v17 + 999999999)
     / v17)
    - (v18
     - *(_QWORD *)(a1 + 864)),
      0,
      1);
    v15 = 0;
    *(_BYTE *)(a1 + 984) = 1;
    goto LABEL_22;
  }
  v15 = sde_encoder_helper_register_irq(a1, 4u);
  if ( v15 )
  {
    __asm { PRFM            #0x11, [X26] }
    do
      v31 = __ldxr(_X26);
    while ( __stxr(v31 - 1, _X26) );
    *(_BYTE *)(a1 + 984) = 0;
    goto LABEL_30;
  }
  *(_BYTE *)(a1 + 984) = 0;
LABEL_22:
  mutex_unlock(*(_QWORD *)(a1 + 840));
  return v15;
}
