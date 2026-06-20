__int64 __fastcall scheduler_thread(__int64 a1)
{
  unsigned __int64 StatusReg; // x20
  __int64 v3; // x1
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x28
  __int64 v21; // x0
  unsigned __int64 v22; // x20
  __int64 v23; // x22
  __int64 v24; // x24
  int v25; // w26
  __int64 v26; // x8
  unsigned __int64 v27; // x25
  unsigned int v29; // w26
  __int64 v30; // x21
  unsigned int multiplier; // w27
  __int64 (__fastcall *v32)(_QWORD); // x8
  int v33; // w26
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v44; // w8
  void (*v45)(void); // x8
  __int64 v46; // x0
  void (__fastcall *v47)(_QWORD); // x8
  unsigned __int64 v53; // x9
  unsigned __int64 v56; // x8
  unsigned __int64 v59; // x8
  __int64 v60; // x1
  _QWORD v62[6]; // [xsp+0h] [xbp-30h] BYREF

  v62[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    qdf_set_user_nice();
    qdf_event_set(a1 + 504, v3);
    qdf_trace_msg(
      0x4Au,
      8u,
      "%s: scheduler thread %d (%s) starting up",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "scheduler_thread",
      *(unsigned int *)(StatusReg + 1800),
      StatusReg + 2320);
    v20 = a1 + 456;
    do
    {
      if ( (*(_QWORD *)(a1 + 616) & 2) == 0 && (*(_QWORD *)(a1 + 616) & 4) == 0 )
      {
        memset(v62, 0, 40);
        init_wait_entry(v62, 0);
        while ( 1 )
        {
          v21 = prepare_to_wait_event(a1 + 592, v62, 1);
          if ( (*(_QWORD *)(a1 + 616) & 2) != 0 || (*(_QWORD *)(a1 + 616) & 4) != 0 )
            break;
          if ( v21 )
            goto LABEL_13;
          schedule();
        }
        finish_wait(a1 + 592, v62);
      }
LABEL_13:
      _X8 = (unsigned __int64 *)(a1 + 616);
      __asm { PRFM            #0x11, [X8] }
      do
        v53 = __ldxr(_X8);
      while ( __stxr(v53 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
      v22 = 0;
      while ( 1 )
      {
        v23 = *(_QWORD *)(a1 + 616);
        if ( (v23 & 0x10000) != 0 )
          break;
        v24 = a1 + 48 * v22;
        v62[0] = 0;
        *(_QWORD *)(v24 + 8) = raw_spin_lock_irqsave(v24);
        v25 = qdf_list_remove_front((_DWORD *)(v24 + 16), v62);
        raw_spin_unlock_irqrestore(v24, *(_QWORD *)(v24 + 8));
        v26 = v62[0];
        v27 = v62[0] - 32LL;
        if ( v25 )
          _ZF = 1;
        else
          _ZF = v62[0] == 32;
        if ( _ZF )
        {
          ++v22;
        }
        else if ( *(_QWORD *)(v20 + 8 * v22) )
        {
          v29 = *(_DWORD *)(a1 + 712);
          *(_WORD *)(a1 + 682) = *(_WORD *)(v62[0] - 32LL);
          *(_QWORD *)(a1 + 776) = *(_QWORD *)(v26 - 16);
          v30 = jiffies;
          multiplier = qdf_timer_get_multiplier();
          *(_QWORD *)(a1 + 736) = v30 + _msecs_to_jiffies(v29) * multiplier;
          add_timer(a1 + 720);
          v32 = *(__int64 (__fastcall **)(_QWORD))(v20 + 8 * v22);
          if ( *((_DWORD *)v32 - 1) != 1685785071 )
            __break(0x8228u);
          v33 = v32(v27);
          timer_delete((timer_t)(a1 + 720));
          if ( v33 )
            qdf_trace_msg(
              0x4Au,
              2u,
              "%s: Failed processing Qid[%d] message",
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              "scheduler_thread_process_queues",
              *(unsigned int *)(v24 + 40));
          qdf_flex_mem_free((__int64)sched_pool, v27);
          _X11 = &_sched_queue_depth;
          __asm { PRFM            #0x11, [X11] }
          do
            v44 = __ldxr((unsigned int *)&_sched_queue_depth);
          while ( __stxr(v44 - 1, (unsigned int *)&_sched_queue_depth) );
          v22 = 0;
        }
        else
        {
          v22 = 0;
        }
        if ( v22 >= 6 )
          goto LABEL_42;
      }
      qdf_trace_msg(
        0x4Au,
        8u,
        "%s: scheduler thread signaled to shutdown",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "scheduler_thread_process_queues");
      _X9 = (unsigned __int64 *)(a1 + 616);
      __asm { PRFM            #0x11, [X9] }
      do
        v59 = __ldxr(_X9);
      while ( __stlxr(v59 & 0xFFFFFFFFFFFFFFFBLL, _X9) );
      __dmb(0xBu);
      if ( (v59 & 4) != 0 )
      {
        v45 = *(void (**)(void))(gp_sched_ctx + 688);
        if ( v45 )
        {
          if ( *((_DWORD *)v45 - 1) != -440107680 )
            __break(0x8228u);
          v45();
        }
      }
LABEL_42:
      _X9 = (unsigned __int64 *)(a1 + 616);
      __asm { PRFM            #0x11, [X9] }
      do
        v56 = __ldxr(_X9);
      while ( __stlxr(v56 & 0xFFFFFFFFFFFFFFFBLL, _X9) );
      __dmb(0xBu);
      if ( (v56 & 4) != 0 )
      {
        raw_spin_lock(a1 + 664);
        v46 = qdf_event_reset(a1 + 624);
        v47 = *(void (__fastcall **)(_QWORD))(gp_sched_ctx + 688);
        if ( v47 )
        {
          if ( *((_DWORD *)v47 - 1) != -440107680 )
            __break(0x8228u);
          v47(v46);
        }
        raw_spin_unlock(a1 + 664);
        qdf_wait_single_event(a1 + 624, 0);
      }
    }
    while ( (v23 & 0x10000) == 0 );
    qdf_trace_msg(0x4Au, 8u, "%s: Scheduler thread exiting", v12, v13, v14, v15, v16, v17, v18, v19, "scheduler_thread");
    qdf_event_set(a1 + 552, v60);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
