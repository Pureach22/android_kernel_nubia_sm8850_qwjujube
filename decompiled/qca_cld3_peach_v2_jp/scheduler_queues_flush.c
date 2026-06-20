__int64 __fastcall scheduler_queues_flush(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x10
  const char *v10; // x26
  const char *v12; // x23
  __int64 v13; // x24
  const char *v14; // x21
  const char *v15; // x23
  int v16; // w26
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x20
  unsigned __int16 *v27; // x25
  void (__fastcall *v29)(_QWORD); // x8
  int v30; // w25
  unsigned int v35; // w8
  __int64 v37; // [xsp+8h] [xbp-18h]
  _QWORD v38[2]; // [xsp+10h] [xbp-10h] BYREF

  v38[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x4Au,
    8u,
    "%s: Flushing scheduler message queues",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "scheduler_queues_flush");
  v9 = 0;
  v10 = "%s: Freeing scheduler msg bodyptr; type: %x";
  _X28 = &_sched_queue_depth;
  v12 = "%s: Calling flush callback; type: %x";
  do
  {
    v37 = v9;
    v38[0] = 0;
    v13 = a1 + 48 * v9;
    *(_QWORD *)(v13 + 8) = raw_spin_lock_irqsave(v13);
    v14 = v12;
    v15 = v10;
    v16 = qdf_list_remove_front((_DWORD *)(v13 + 16), v38);
    result = raw_spin_unlock_irqrestore(v13, *(_QWORD *)(v13 + 8));
    v26 = v38[0];
    _ZF = v16 == 0;
    v10 = v15;
    v12 = v14;
    v27 = (unsigned __int16 *)(v38[0] - 32LL);
    _ZF = !_ZF || v38[0] == 32;
    if ( !_ZF )
    {
      do
      {
        if ( *(_QWORD *)(v26 - 8) )
        {
          qdf_trace_msg(0x4Au, 8u, v14, v18, v19, v20, v21, v22, v23, v24, v25, "scheduler_flush_single_queue", *v27);
          v29 = *(void (__fastcall **)(_QWORD))(v26 - 8);
          if ( *((_DWORD *)v29 - 1) != 1685785071 )
            __break(0x8228u);
          v29(v27);
        }
        else if ( *(_QWORD *)(v26 - 24) )
        {
          qdf_trace_msg(0x4Au, 8u, v10, v18, v19, v20, v21, v22, v23, v24, v25, "scheduler_flush_single_queue", *v27);
          _qdf_mem_free(*(_QWORD *)(v26 - 24));
        }
        qdf_flex_mem_free((__int64)sched_pool, (unsigned __int64)v27);
        __asm { PRFM            #0x11, [X28] }
        do
          v35 = __ldxr((unsigned int *)&_sched_queue_depth);
        while ( __stxr(v35 - 1, (unsigned int *)&_sched_queue_depth) );
        v38[0] = 0;
        *(_QWORD *)(v13 + 8) = raw_spin_lock_irqsave(v13);
        v30 = qdf_list_remove_front((_DWORD *)(v13 + 16), v38);
        result = raw_spin_unlock_irqrestore(v13, *(_QWORD *)(v13 + 8));
        if ( v30 )
          break;
        v26 = v38[0];
        v27 = (unsigned __int16 *)(v38[0] - 32LL);
      }
      while ( v38[0] != 32 );
    }
    v9 = v37 + 1;
  }
  while ( v37 != 5 );
  _ReadStatusReg(SP_EL0);
  return result;
}
