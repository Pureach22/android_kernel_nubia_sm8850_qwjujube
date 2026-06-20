__int64 __fastcall sde_encoder_phys_cmd_wait_for_idle(__int64 a1)
{
  __int64 v2; // x8
  __int64 v4; // x10
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 result; // x0
  unsigned int v8; // w1
  char v9; // w0
  __int64 v10; // x20
  unsigned int v11; // w8
  unsigned int v17; // w10
  char v18; // w21
  int v19; // w6
  int v20; // w4
  int v21; // w7
  int v22; // w4
  __int64 v23; // x4
  __int64 v24; // x0
  void (__fastcall *v25)(__int64 *, __int64, __int64); // x9
  __int64 v26; // x20
  __int64 *v27; // x0
  char v28; // [xsp+0h] [xbp-40h]
  _QWORD v29[2]; // [xsp+18h] [xbp-28h] BYREF
  __int64 v30; // [xsp+28h] [xbp-18h]
  __int64 v31; // [xsp+30h] [xbp-10h]
  __int64 v32; // [xsp+38h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a1;
  v30 = 0;
  if ( v2 && *(_BYTE *)(v2 + 4922) == 1 && *(_DWORD *)(a1 + 664) == 3 )
    goto LABEL_11;
  _X21 = (unsigned int *)(a1 + 876);
  if ( *(int *)(a1 + 876) >= 2 )
    LODWORD(v30) = 1;
  v4 = *(unsigned int *)(a1 + 992);
  v5 = *(_QWORD *)(a1 + 8);
  v29[0] = a1 + 896;
  v29[1] = a1 + 876;
  v31 = v4;
  if ( v5 )
  {
    v6 = *(_QWORD *)(v5 + 2512);
    if ( v6 )
    {
      if ( *(_DWORD *)(v6 + 1376) == 10 && *(_DWORD *)(a1 + 664) == 3 )
        goto LABEL_11;
    }
  }
  if ( (sde_encoder_phys_cmd_is_scheduler_idle(a1) & 1) != 0 )
    goto LABEL_11;
  if ( *(_QWORD *)a1 )
  {
    if ( *(_BYTE *)(*(_QWORD *)a1 + 4922LL) )
      v8 = 7;
    else
      v8 = 1;
  }
  else
  {
    v8 = 1;
  }
  result = sde_encoder_helper_wait_for_irq((__int64 **)a1, v8, v29);
  if ( (_DWORD)result == -110 )
  {
    if ( (sde_encoder_phys_cmd_is_scheduler_idle(a1) & 1) != 0 )
    {
LABEL_11:
      result = 0;
      goto LABEL_52;
    }
    v9 = sde_encoder_recovery_events_enabled(*(_QWORD *)a1);
    if ( !*(_QWORD *)(a1 + 496) || !*(_QWORD *)(a1 + 416) )
    {
LABEL_51:
      result = 4294967186LL;
      goto LABEL_52;
    }
    v10 = *(_QWORD *)(a1 + 8);
    v11 = *(_DWORD *)(a1 + 876);
    do
    {
      if ( !v11 )
        goto LABEL_51;
      __asm { PRFM            #0x11, [X21] }
      while ( 1 )
      {
        v17 = __ldxr(_X21);
        if ( v17 != v11 )
          break;
        if ( !__stlxr(v11 - 1, _X21) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v17 == v11;
      v11 = v17;
    }
    while ( !_ZF );
    v18 = v9;
    v19 = *(_DWORD *)(a1 + 2684) + 1;
    *(_DWORD *)(a1 + 2684) = v19;
    if ( *(_QWORD *)a1 )
      v20 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    else
      v20 = -1;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_encoder_phys_cmd_handle_framedone_timeout",
      893,
      -1,
      v20,
      *(_DWORD *)(*(_QWORD *)(a1 + 496) + 32LL) - 1,
      v19,
      *(_DWORD *)(a1 + 876) + 1,
      10);
    if ( (unsigned int)sde_connector_esd_status(*(_QWORD *)(a1 + 8)) )
    {
LABEL_47:
      if ( *(_QWORD *)(a1 + 392) )
      {
        v24 = raw_spin_lock_irqsave(*(_QWORD *)(a1 + 824));
        v25 = *(void (__fastcall **)(__int64 *, __int64, __int64))(a1 + 392);
        v26 = v24;
        v27 = *(__int64 **)a1;
        if ( *((_DWORD *)v25 - 1) != -570463643 )
          __break(0x8229u);
        v25(v27, a1, 10);
        raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 824), v26);
      }
      goto LABEL_51;
    }
    if ( *(_DWORD *)(a1 + 2684) == 1 )
    {
      printk(&unk_25E929, "_sde_encoder_phys_cmd_handle_framedone_timeout");
      if ( *(_QWORD *)a1 )
        v22 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      else
        v22 = -1;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_encoder_phys_cmd_handle_framedone_timeout",
        907,
        -1,
        v22,
        2989,
        -1059143953,
        v21,
        v28);
      mutex_lock(*(_QWORD *)(a1 + 840));
      sde_encoder_helper_unregister_irq(a1, 8u);
      if ( (sde_kms_is_secure_session_inprogress_0(*(_QWORD *)(a1 + 512)) & 1) != 0 )
        sde_dbg_dump(0, "_sde_encoder_phys_cmd_handle_framedone_timeout", 0xFFFFFF, "secure", 0);
      else
        sde_dbg_dump(0, "_sde_encoder_phys_cmd_handle_framedone_timeout", 0xFFFFFF, 0, v23);
      sde_encoder_helper_register_irq(a1, 8u);
      mutex_unlock(*(_QWORD *)(a1 + 840));
      if ( (v18 & 1) != 0 )
        goto LABEL_36;
    }
    else if ( (v18 & 1) != 0 )
    {
LABEL_36:
      sde_connector_event_notify(v10, 2147483655LL, 1, 1);
LABEL_46:
      *(_DWORD *)(a1 + 832) = 5;
      goto LABEL_47;
    }
    if ( *(_DWORD *)(a1 + 2684) )
      sde_dbg_dump(0, "_sde_encoder_phys_cmd_handle_framedone_timeout", 0, "panic", 0);
    goto LABEL_46;
  }
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
