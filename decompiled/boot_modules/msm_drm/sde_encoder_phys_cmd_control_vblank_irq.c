__int64 __fastcall sde_encoder_phys_cmd_control_vblank_irq(__int64 a1, char a2)
{
  const void *v2; // x30
  const void *v4; // x22
  int v6; // w21
  int v7; // w4
  int v9; // w4
  unsigned int v10; // w0
  unsigned int v11; // w22
  int v12; // w4
  unsigned int v19; // w8
  unsigned int v20; // w8
  unsigned int v23; // w8
  unsigned int v24; // w8
  unsigned int v27; // w10
  unsigned int v30; // w9

  if ( !a1 || !*(_QWORD *)(a1 + 496) )
  {
    printk(&unk_26FCAB, "sde_encoder_phys_cmd_control_vblank_irq");
    return 4294967274LL;
  }
  v4 = v2;
  mutex_lock(*(_QWORD *)(a1 + 840));
  if ( *(_DWORD *)(a1 + 664) == 3 )
    goto LABEL_21;
  v6 = *(_DWORD *)(a1 + 848);
  if ( (a2 & 1) != 0 || v6 )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      if ( *(_QWORD *)a1 )
        v7 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      else
        v7 = -1;
      _drm_dev_dbg(0, 0, 0, "enc%d intf%d [%pS] enable=%d/%d\n", v7, *(_DWORD *)(a1 + 672) - 1, v4, a2 & 1, v6);
    }
    if ( *(_QWORD *)a1 )
      v9 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    else
      v9 = -1;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_phys_cmd_control_vblank_irq",
      1220,
      -1,
      v9,
      *(_DWORD *)(*(_QWORD *)(a1 + 496) + 32LL) - 1,
      a2 & 1,
      v6,
      239);
    if ( (a2 & 1) != 0 )
    {
      _X9 = (unsigned int *)(a1 + 848);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v19 = __ldxr(_X9);
        v20 = v19 + 1;
      }
      while ( __stlxr(v20, _X9) );
      __dmb(0xBu);
      if ( v20 == 1 )
      {
        v10 = sde_encoder_helper_register_irq(a1, 8u);
        if ( v10 )
        {
          _X8 = (unsigned int *)(a1 + 848);
          __asm { PRFM            #0x11, [X8] }
          do
            v27 = __ldxr(_X8);
          while ( __stlxr(v27 - 1, _X8) );
LABEL_35:
          __dmb(0xBu);
          v11 = v10;
          goto LABEL_23;
        }
      }
    }
    else
    {
      _X9 = (unsigned int *)(a1 + 848);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v23 = __ldxr(_X9);
        v24 = v23 - 1;
      }
      while ( __stlxr(v24, _X9) );
      __dmb(0xBu);
      if ( !v24 )
      {
        v10 = sde_encoder_helper_unregister_irq(a1, 8u);
        if ( v10 )
        {
          _X8 = (unsigned int *)(a1 + 848);
          __asm { PRFM            #0x11, [X8] }
          do
            v30 = __ldxr(_X8);
          while ( __stlxr(v30 + 1, _X8) );
          goto LABEL_35;
        }
      }
    }
LABEL_21:
    mutex_unlock(*(_QWORD *)(a1 + 840));
    return 0;
  }
  v11 = -22;
LABEL_23:
  mutex_unlock(*(_QWORD *)(a1 + 840));
  printk(&unk_25AE05, "sde_encoder_phys_cmd_control_vblank_irq");
  if ( *(_QWORD *)a1 )
    v12 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
  else
    v12 = -1;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_phys_cmd_control_vblank_irq",
    1242,
    -1,
    v12,
    *(_DWORD *)(*(_QWORD *)(a1 + 496) + 32LL) - 1,
    a2 & 1,
    v6,
    173);
  return v11;
}
