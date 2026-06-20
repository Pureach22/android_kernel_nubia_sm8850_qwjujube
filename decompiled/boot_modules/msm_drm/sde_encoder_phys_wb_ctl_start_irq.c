size_t __fastcall sde_encoder_phys_wb_ctl_start_irq(size_t result)
{
  size_t v1; // x19
  __int64 StatusReg; // x20
  unsigned int disp_op; // w0
  unsigned int v4; // w9
  unsigned int v5; // w21
  unsigned int v12; // w11
  __int64 v13; // x22
  __int64 v14; // x23
  __int64 (__fastcall *v15)(_QWORD); // x8
  __int64 v16; // x0
  int v17; // w21
  __int64 (__fastcall *v18)(_QWORD); // x8
  int v19; // w7
  _DWORD *v20; // x8
  int v21; // w4
  __int64 v22; // x9
  int v23; // w5
  __int64 v24; // x0
  __int64 v25; // x8

  if ( result )
  {
    v1 = result;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      disp_op = sde_encoder_get_disp_op(*(_QWORD *)v1);
      v4 = *(_DWORD *)(v1 + 884);
      v5 = disp_op;
      _X8 = (unsigned int *)(v1 + 884);
      while ( v4 )
      {
        __asm { PRFM            #0x11, [X8] }
        while ( 1 )
        {
          v12 = __ldxr(_X8);
          if ( v12 != v4 )
            break;
          if ( !__stlxr(v4 - 1, _X8) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v12 == v4;
        v4 = v12;
        if ( _ZF )
        {
          _wake_up(v1 + 896, 3, 0, 0);
          break;
        }
      }
      if ( v5 < 3 )
        break;
      __break(0x5512u);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        ++*(_DWORD *)(StatusReg + 16);
        v24 = _traceiter_tracing_mark_write(0, 0x42u, StatusReg, (__int64)"ctl_start_irq", 0);
        v25 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v25;
        if ( !v25 || !*(_QWORD *)(StatusReg + 16) )
          preempt_schedule_notrace(v24);
      }
    }
    v13 = *(_QWORD *)(v1 + 2680);
    v14 = v13 + 8LL * v5;
    v15 = *(__int64 (__fastcall **)(_QWORD))(v14 + 472);
    if ( v15 )
    {
      v16 = *(_QWORD *)(v1 + 2680);
      if ( *((_DWORD *)v15 - 1) != -403367322 )
        __break(0x8228u);
      v17 = v15(v16);
      v18 = *(__int64 (__fastcall **)(_QWORD))(v14 + 568);
      if ( v18 )
        goto LABEL_18;
    }
    else
    {
      v17 = 0;
      v18 = *(__int64 (__fastcall **)(_QWORD))(v14 + 568);
      if ( v18 )
      {
LABEL_18:
        if ( *((_DWORD *)v18 - 1) != -403367322 )
          __break(0x8228u);
        v19 = v18(v13);
LABEL_23:
        v20 = *(_DWORD **)v1;
        if ( *(_QWORD *)v1 )
        {
          v21 = v20[6];
          v22 = *(_QWORD *)(v1 + 2864);
          if ( v22 )
          {
LABEL_25:
            v23 = *(_DWORD *)(v22 + 12) - 1;
            return sde_evtlog_log(
                     sde_dbg_base_evtlog,
                     "sde_encoder_phys_wb_ctl_start_irq",
                     2022,
                     2,
                     v21,
                     v23,
                     v17,
                     v19,
                     **(_DWORD **)(*(_QWORD *)v20 + 64LL));
          }
        }
        else
        {
          v21 = -1;
          v22 = *(_QWORD *)(v1 + 2864);
          if ( v22 )
            goto LABEL_25;
        }
        v23 = -1;
        return sde_evtlog_log(
                 sde_dbg_base_evtlog,
                 "sde_encoder_phys_wb_ctl_start_irq",
                 2022,
                 2,
                 v21,
                 v23,
                 v17,
                 v19,
                 **(_DWORD **)(*(_QWORD *)v20 + 64LL));
      }
    }
    v19 = 0;
    goto LABEL_23;
  }
  return result;
}
