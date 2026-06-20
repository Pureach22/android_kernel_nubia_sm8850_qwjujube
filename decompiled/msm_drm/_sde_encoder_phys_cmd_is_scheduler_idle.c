__int64 __fastcall sde_encoder_phys_cmd_is_scheduler_idle(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w21
  __int64 disp_op; // x0
  __int64 (__fastcall *v5)(_QWORD); // x8
  unsigned int v7; // w9
  unsigned int v14; // w11
  __int64 v15; // x0
  void (__fastcall *v16)(__int64, __int64, __int64); // x9
  __int64 v17; // x20
  __int64 v18; // x0
  int v19; // w4

  v2 = *(_QWORD *)(a1 + 416);
  v3 = *(_DWORD *)(a1 + 2332);
  disp_op = sde_encoder_get_disp_op(*(_QWORD *)a1);
  if ( *(_DWORD *)(a1 + 664) == 3 )
  {
    LODWORD(v5) = 0;
  }
  else
  {
    LODWORD(v5) = 0;
    if ( (*(_BYTE *)(a1 + 2760) & 1) == 0 )
      return (unsigned int)v5;
  }
  if ( v3 != 2 )
    return (unsigned int)v5;
  if ( (unsigned int)disp_op < 3 )
  {
    v5 = *(__int64 (__fastcall **)(_QWORD))(v2 + 8LL * (unsigned int)disp_op + 976);
    if ( v5 )
    {
      if ( *(_QWORD *)(a1 + 392) && *(int *)(a1 + 876) >= 1 )
      {
        if ( *((_DWORD *)v5 - 1) != 1814623283 )
          __break(0x8228u);
        if ( (v5(v2) & 1) != 0 )
        {
          v7 = *(_DWORD *)(a1 + 876);
          _X8 = (unsigned int *)(a1 + 876);
          while ( v7 )
          {
            __asm { PRFM            #0x11, [X8] }
            while ( 1 )
            {
              v14 = __ldxr(_X8);
              if ( v14 != v7 )
                break;
              if ( !__stlxr(v7 - 1, _X8) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v14 == v7;
            v7 = v14;
            if ( _ZF )
            {
              v15 = raw_spin_lock_irqsave(*(_QWORD *)(a1 + 824));
              v16 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 392);
              v17 = v15;
              v18 = *(_QWORD *)a1;
              if ( *((_DWORD *)v16 - 1) != -570463643 )
                __break(0x8229u);
              v16(v18, a1, 9);
              raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 824), v17);
              if ( *(_QWORD *)a1 )
                v19 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
              else
                v19 = -1;
              sde_evtlog_log(
                sde_dbg_base_evtlog,
                "_sde_encoder_phys_cmd_is_scheduler_idle",
                1101,
                -1,
                v19,
                *(_DWORD *)(*(_QWORD *)(a1 + 496) + 32LL) - 1,
                *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
                *(_DWORD *)(a1 + 876),
                239);
              LODWORD(v5) = 1;
              return (unsigned int)v5;
            }
          }
        }
      }
      LODWORD(v5) = 0;
    }
    return (unsigned int)v5;
  }
  __break(0x5512u);
  return sde_kms_is_secure_session_inprogress_0(disp_op);
}
