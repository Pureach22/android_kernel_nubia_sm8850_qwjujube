__int64 __fastcall hif_ext_group_interrupt_handler(int a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v5; // x0
  __int64 v6; // x8
  int v7; // w2
  void (__fastcall *v8)(_QWORD); // x8
  __int64 is_one_msi; // x0
  __int64 v10; // x1
  __int64 v12; // x23
  __int64 (__fastcall *v13)(_QWORD); // x8
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 v16; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v18; // x20
  __int64 v19; // x9
  __int64 v21; // x21
  unsigned int v27; // w8
  _QWORD v28[5]; // [xsp+8h] [xbp-28h] BYREF

  v28[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a2 + 2682) == 1 )
  {
    v2 = *(_QWORD *)(a2 + 8);
    v5 = v2;
    if ( *(_BYTE *)(v2 + 26436) == 1 )
    {
      v6 = sched_clock(v2, a2);
      v5 = *(_QWORD *)(a2 + 8);
      *(_QWORD *)(a2 + 2944) = v6;
    }
    v7 = *(_DWORD *)(a2 + 232);
    memset(v28, 0, 32);
    hif_hist_record_event(v5, (__int64)v28, v7);
    v8 = *(void (__fastcall **)(_QWORD))(a2 + 280);
    if ( *((_DWORD *)v8 - 1) != -836874276 )
      __break(0x8228u);
    v8(a2);
    is_one_msi = pld_is_one_msi(*(_QWORD *)(*(_QWORD *)(v2 + 576) + 40LL));
    if ( (is_one_msi & 1) != 0 )
    {
      is_one_msi = sched_clock(is_one_msi, v10);
      *(_QWORD *)(a2 + 2936) = is_one_msi;
    }
    _X22 = (unsigned int *)(v2 + 676);
    if ( *(_BYTE *)(v2 + 3988) == 1 && *(_DWORD *)(v2 + 712) )
    {
      v12 = jiffies;
      if ( hif_check_and_trigger_sys_resume___last_ticks - jiffies + 125 < 0 )
      {
        is_one_msi = qdf_trace_msg(
                       61,
                       4,
                       "%s: interrupt rcvd:%d trigger sys resume",
                       "hif_check_and_trigger_sys_resume",
                       a1);
        hif_check_and_trigger_sys_resume___last_ticks = v12;
      }
      qdf_pm_system_wakeup(is_one_msi);
    }
    __asm { PRFM            #0x11, [X22] }
    do
      v27 = __ldxr(_X22);
    while ( __stxr(v27 + 1, _X22) );
    v13 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)a2 + 8LL);
    if ( *((_DWORD *)v13 - 1) != -836874276 )
      __break(0x8228u);
    v14 = v13(a2);
    if ( *(_BYTE *)(*(_QWORD *)(a2 + 8) + 26436LL) == 1 )
    {
      v16 = sched_clock(v14, v15);
      StatusReg = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(StatusReg + 16);
      v18 = *(unsigned int *)(StatusReg + 40);
      v19 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v19;
      if ( v19 && *(_QWORD *)(StatusReg + 16) )
      {
        if ( (unsigned int)v18 < 0x20 )
        {
LABEL_20:
          *(_QWORD *)(a2 + 8 * v18 + 2952) += v16 - *(_QWORD *)(a2 + 2944);
          goto LABEL_21;
        }
      }
      else
      {
        v21 = v16;
        preempt_schedule(v16);
        v16 = v21;
        if ( (unsigned int)v18 < 0x20 )
          goto LABEL_20;
      }
      __break(0x5512u);
    }
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return 1;
}
