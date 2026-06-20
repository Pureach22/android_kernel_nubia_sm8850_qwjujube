int *__fastcall sde_encoder_phys_cmd_te_rd_ptr_irq(int *result)
{
  int *v1; // x19
  unsigned int disp_op; // w22
  unsigned __int64 StatusReg; // x20
  __int64 v4; // x21
  __int64 v5; // x23
  __int64 v6; // x27
  __int64 (__fastcall *v7)(_QWORD); // x8
  int v8; // w22
  __int64 v9; // x0
  int *v10; // x25
  _QWORD *v11; // x26
  __int64 v12; // x24
  int **v13; // x8
  __int64 v14; // x9
  int *v15; // x1
  __int64 (__fastcall *v16)(_QWORD); // x8
  int v17; // w23
  int v18; // w4
  __int64 status; // x0
  __int64 v20; // x8
  __int64 v21; // x9
  int v22; // w21
  int v23; // w22
  int v24; // w23
  __int64 v25; // x8
  int v26; // w0
  unsigned int v27; // w22
  void (__fastcall *v28)(__int64, int *); // x8
  __int64 v29; // x0
  unsigned int v30; // w8
  unsigned int v37; // w10
  __int64 v38; // x0
  __int64 v39; // x8
  _QWORD v40[2]; // [xsp+58h] [xbp-88h] BYREF
  _QWORD v41[15]; // [xsp+68h] [xbp-78h] BYREF

  v41[14] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v41, 0, 112);
  v40[0] = 0;
  v40[1] = 0;
  if ( !result )
    goto LABEL_62;
  v1 = result;
  result = *(int **)result;
  if ( !result || !*((_QWORD *)v1 + 62) || !*((_QWORD *)v1 + 53) || !*((_QWORD *)v1 + 52) )
    goto LABEL_62;
  disp_op = sde_encoder_get_disp_op((__int64)result);
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v4 = *(_QWORD *)v1;
    v5 = *((_QWORD *)v1 + 52);
    if ( *(_QWORD *)v1 )
    {
      if ( (((__int64 (__fastcall *)(_QWORD))sde_encoder_in_clone_mode)(*(_QWORD *)v1) & 1) != 0 )
        v4 = 0;
      else
        v4 = *(_QWORD *)(v4 + 4960);
    }
    if ( disp_op < 3 )
      break;
    __break(0x5512u);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v38 = _traceiter_tracing_mark_write(0, 66, StatusReg, "rd_ptr_irq", 0);
      v39 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v39;
      if ( !v39 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v38);
    }
  }
  v6 = v5 + 8LL * disp_op;
  v7 = *(__int64 (__fastcall **)(_QWORD))(v6 + 976);
  if ( v7 )
  {
    if ( *((_DWORD *)v7 - 1) != 1814623283 )
      __break(0x8228u);
    v8 = v7(v5);
  }
  else
  {
    v8 = -1906;
  }
  v9 = raw_spin_lock_irqsave(*((_QWORD *)v1 + 103));
  v10 = *((int **)v1 + 346);
  v11 = v1 + 692;
  v12 = v9;
  if ( v10 != v1 + 692 && v10 )
  {
    v13 = *((int ***)v10 + 1);
    if ( *v13 == v10 && (v14 = *(_QWORD *)v10, *(int **)(*(_QWORD *)v10 + 8LL) == v10) )
    {
      *(_QWORD *)(v14 + 8) = v13;
      *v13 = (int *)v14;
    }
    else
    {
      v9 = _list_del_entry_valid_or_report(*((_QWORD *)v1 + 346));
    }
    *(_QWORD *)v10 = v10;
    *((_QWORD *)v10 + 1) = v10;
    *((_QWORD *)v10 + 2) = ktime_get(v9);
    v15 = *((int **)v1 + 347);
    if ( v15 == v10 || *(_QWORD **)v15 != v11 )
    {
      _list_add_valid_or_report(v10, v15);
    }
    else
    {
      *((_QWORD *)v1 + 347) = v10;
      *(_QWORD *)v10 = v11;
      *((_QWORD *)v10 + 1) = v15;
      *(_QWORD *)v15 = v10;
    }
  }
  raw_spin_unlock_irqrestore(*((_QWORD *)v1 + 103), v12);
  if ( v8 == 1 || (v16 = *(__int64 (__fastcall **)(_QWORD))(v6 + 448)) == nullptr )
  {
    v17 = 0;
  }
  else
  {
    if ( *((_DWORD *)v16 - 1) != 1800103338 )
      __break(0x8228u);
    v17 = v16(v5);
  }
  ((void (__fastcall *)(_QWORD, _QWORD *))sde_encoder_helper_get_pp_line_count)(*(_QWORD *)v1, v41);
  if ( *(_QWORD *)v1 )
    v18 = *(_DWORD *)(*(_QWORD *)v1 + 24LL);
  else
    v18 = -1;
  status = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_encoder_phys_cmd_te_rd_ptr_irq",
             582,
             2,
             v18,
             v8,
             v17,
             v41[0],
             SBYTE4(v41[0]));
  if ( v4 )
    status = sde_cesta_get_status(v4, v40);
  v20 = *(_QWORD *)v1;
  if ( *(_BYTE *)(*(_QWORD *)v1 + 700LL) == 1 && *(_DWORD *)(v20 + 4808) )
  {
    v21 = *((_QWORD *)v1 + 1);
    if ( v21 )
      v22 = *(_DWORD *)(v21 + 4676);
    else
      v22 = 0;
    v23 = sde_dbg_base_evtlog;
    if ( v20 )
      v24 = *(_DWORD *)(v20 + 24);
    else
      v24 = -1;
    v25 = (unsigned __int128)(ktime_get(status) * (__int128)0x20C49BA5E353F7CFLL) >> 64;
    v26 = v23;
    v27 = 2;
    sde_evtlog_log(
      v26,
      "_sde_encoder_phys_cmd_process_sim_qsync_event",
      405,
      2,
      v24,
      *((_QWORD *)v1 + 108) / -1000LL + (v25 >> 7) + ((unsigned __int64)v25 >> 63),
      v22,
      v1[585],
      1);
    if ( !v22 )
    {
      if ( !v1[585] )
        goto LABEL_48;
      v27 = 0;
    }
    ((void (__fastcall *)(int *, _QWORD))sde_encoder_phys_cmd_setup_sim_qsync_frame)(v1, v27);
  }
LABEL_48:
  v28 = *((void (__fastcall **)(__int64, int *))v1 + 46);
  if ( v28 )
  {
    v29 = *(_QWORD *)v1;
    if ( *((_DWORD *)v28 - 1) != 468003652 )
      __break(0x8228u);
    v28(v29, v1);
  }
  v30 = v1[682];
  do
  {
    if ( !v30 )
      break;
    _X12 = (unsigned int *)(v1 + 682);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v37 = __ldxr(_X12);
      if ( v37 != v30 )
        break;
      if ( !__stlxr(v30 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v37 == v30;
    v30 = v37;
  }
  while ( !_ZF );
  result = (int *)_wake_up(v1 + 684, 3, 0, 0);
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}
