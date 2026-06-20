__int64 __fastcall sde_encoder_phys_vid_control_vblank_irq(__int64 a1, char a2)
{
  const void *v2; // x30
  const void *v4; // x22
  int v6; // w21
  __int64 v7; // x25
  __int64 v8; // x8
  int v9; // w4
  __int64 v10; // x8
  int v11; // w5
  int v12; // w4
  unsigned int v13; // w22
  unsigned int v20; // w8
  unsigned int v21; // w8
  unsigned int v24; // w8
  unsigned int v25; // w8
  int v27; // w4
  unsigned int v30; // w10
  unsigned int v33; // w9
  char v34; // [xsp+0h] [xbp-10h]

  if ( a1 )
  {
    v4 = v2;
    mutex_lock(*(_QWORD *)(a1 + 840));
    v6 = *(_DWORD *)(a1 + 848);
    if ( *(_DWORD *)(a1 + 664) == 3 )
      goto LABEL_22;
    v7 = *(_QWORD *)a1;
    if ( (a2 & 1) == 0 && !v6 )
    {
      v13 = -22;
      goto LABEL_37;
    }
    v8 = *(_QWORD *)a1;
    if ( (_drm_debug & 4) == 0 )
    {
LABEL_12:
      if ( v8 )
        v12 = *(_DWORD *)(v8 + 24);
      else
        v12 = -1;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_encoder_phys_vid_control_vblank_irq",
        1507,
        -1,
        v12,
        a2 & 1,
        *(_DWORD *)(a1 + 848),
        -1059143953,
        v34);
      if ( (a2 & 1) != 0 )
      {
        _X9 = (unsigned int *)(a1 + 848);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v20 = __ldxr(_X9);
          v21 = v20 + 1;
        }
        while ( __stlxr(v21, _X9) );
        __dmb(0xBu);
        if ( v21 == 1 )
        {
          v13 = sde_encoder_helper_register_irq(a1, 0);
          if ( v13 )
          {
            _X8 = (unsigned int *)(a1 + 848);
            __asm { PRFM            #0x11, [X8] }
            do
              v30 = __ldxr(_X8);
            while ( __stlxr(v30 - 1, _X8) );
            __dmb(0xBu);
            if ( !v7 )
              goto LABEL_34;
          }
          else if ( !v7 )
          {
            goto LABEL_34;
          }
          if ( *(_BYTE *)(v7 + 748) == 1 )
          {
            sde_encoder_helper_register_irq(a1, 0x16u);
            sde_encoder_helper_register_irq(a1, 3u);
          }
          goto LABEL_34;
        }
      }
      else
      {
        _X9 = (unsigned int *)(a1 + 848);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v24 = __ldxr(_X9);
          v25 = v24 - 1;
        }
        while ( __stlxr(v25, _X9) );
        __dmb(0xBu);
        if ( !v25 )
        {
          v13 = sde_encoder_helper_unregister_irq(a1, 0);
          if ( v13 )
          {
            _X8 = (unsigned int *)(a1 + 848);
            __asm { PRFM            #0x11, [X8] }
            do
              v33 = __ldxr(_X8);
            while ( __stlxr(v33 + 1, _X8) );
            __dmb(0xBu);
            if ( !v7 )
              goto LABEL_34;
          }
          else if ( !v7 )
          {
            goto LABEL_34;
          }
          if ( *(_BYTE *)(v7 + 748) == 1 )
          {
            sde_encoder_helper_unregister_irq(a1, 0x16u);
            sde_encoder_helper_unregister_irq(a1, 3u);
          }
LABEL_34:
          if ( !v13 )
            goto LABEL_35;
LABEL_37:
          printk(&unk_215E91, "sde_encoder_phys_vid_control_vblank_irq");
          if ( *(_QWORD *)a1 )
            v27 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
          else
            v27 = -1;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_encoder_phys_vid_control_vblank_irq",
            1536,
            -1,
            v27,
            *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
            a2 & 1,
            v6,
            173);
          goto LABEL_35;
        }
      }
LABEL_22:
      v13 = 0;
LABEL_35:
      mutex_unlock(*(_QWORD *)(a1 + 840));
      return v13;
    }
    if ( v7 )
    {
      v9 = *(_DWORD *)(v7 + 24);
      v10 = *(_QWORD *)(a1 + 424);
      if ( v10 )
      {
LABEL_8:
        v11 = *(_DWORD *)(v10 + 32) - 1;
LABEL_11:
        _drm_dev_dbg(0, 0, 0, "enc%d intf%d [%pS] enable=%d/%d\n", v9, v11, v4, a2 & 1, *(_DWORD *)(a1 + 848));
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
  printk(&unk_26FCAB, "sde_encoder_phys_vid_control_vblank_irq");
  return (unsigned int)-22;
}
