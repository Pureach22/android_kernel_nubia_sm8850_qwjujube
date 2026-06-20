__int64 __fastcall ce_dispatch_interrupt(unsigned int a1, __int64 a2)
{
  int v2; // w4
  __int64 v3; // x19
  __int64 v6; // x8
  __int64 v7; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x22
  __int64 v10; // x9
  unsigned __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x23
  __int64 result; // x0
  int v16; // w8
  __int64 v17; // x19
  unsigned int v20; // w9
  unsigned int v23; // w9
  unsigned __int64 v30; // x8
  unsigned __int64 v33; // x8

  v2 = *(_DWORD *)(a2 + 40);
  v3 = *(_QWORD *)(a2 + 48);
  if ( v2 == a1 )
  {
    if ( (int)a1 >= 12 )
    {
      qdf_trace_msg(61, 2, "%s: ce_id=%d > CE_COUNT_MAX=%d", "ce_dispatch_interrupt", a1, 12);
      return 0;
    }
    else
    {
      if ( a1 >= 0xC )
        goto LABEL_25;
      hif_irq_disable(*(_QWORD *)(a2 + 48), a1);
      v7 = hif_record_ce_desc_event(v3, a1, 16, 0, 0, 0, v6);
      StatusReg = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(StatusReg + 16);
      v9 = *(unsigned int *)(StatusReg + 40);
      v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v10;
      if ( v10 && *(_QWORD *)(StatusReg + 16) )
      {
        if ( (unsigned int)v9 >= 0x21 )
          goto LABEL_25;
      }
      else
      {
        preempt_schedule(v7);
        if ( (unsigned int)v9 >= 0x21 )
          goto LABEL_25;
      }
      v11 = v3 + ((unsigned __int64)a1 << 7) + 4 * v9;
      ++*(_DWORD *)(v11 + 29160);
      while ( 1 )
      {
        _X8 = (unsigned int *)(v3 + 672);
        __asm { PRFM            #0x11, [X8] }
        do
          v20 = __ldxr(_X8);
        while ( __stxr(v20 + 1, _X8) );
        v12 = hif_napi_enabled(v3, a1);
        if ( (_DWORD)v12 )
        {
          hif_napi_schedule(v3, a1);
          return 1;
        }
        if ( (*(_QWORD *)(a2 + 8) & 1) != 0 )
          break;
        v16 = *(_DWORD *)(a2 + 40);
        if ( (unsigned __int8)v16 < 0xCu )
        {
          v17 = *(_QWORD *)(v3 + 480 + 8LL * (v16 & 0xF));
          *(_QWORD *)(v17 + 296) = sched_clock(v12, v13);
          if ( *(_BYTE *)(a2 + 45) == 1 )
          {
            _X9 = (unsigned __int64 *)(a2 + 8);
            __asm { PRFM            #0x11, [X9] }
            do
              v30 = __ldxr(_X9);
            while ( __stlxr(v30 | 1, _X9) );
            __dmb(0xBu);
            if ( (v30 & 1) == 0 )
              _tasklet_hi_schedule(a2);
          }
          else
          {
            _X9 = (unsigned __int64 *)(a2 + 8);
            __asm { PRFM            #0x11, [X9] }
            do
              v33 = __ldxr(_X9);
            while ( __stlxr(v33 | 1, _X9) );
            __dmb(0xBu);
            if ( (v33 & 1) == 0 )
              _tasklet_schedule(a2);
          }
          return 1;
        }
LABEL_25:
        __break(0x5512u);
      }
      qdf_trace_msg(61, 8, "%s: tasklet scheduled, return", "hif_tasklet_schedule");
      _X8 = (unsigned int *)(v3 + 672);
      result = 1;
      __asm { PRFM            #0x11, [X8] }
      do
        v23 = __ldxr(_X8);
      while ( __stxr(v23 - 1, _X8) );
    }
  }
  else
  {
    v14 = jiffies;
    if ( ce_dispatch_interrupt___last_ticks - jiffies + 125 < 0
      && (qdf_trace_msg(
            61,
            2,
            "%s: ce_id (expect %d, received %d) does not match, inited=%d, ce_count=%u",
            "ce_dispatch_interrupt",
            v2,
            a1,
            *(unsigned __int8 *)(a2 + 44),
            *(_DWORD *)(v3 + 656)),
          ce_dispatch_interrupt___last_ticks = v14,
          v3) )
    {
      qdf_trace_msg(
        61,
        5,
        "%s: %02d: ce_id=%d, inited=%d, hi_tasklet_ce=%d hif_ce_state=%pK",
        "ce_tasklet_entry_dump",
        0,
        *(_DWORD *)(v3 + 26488),
        *(unsigned __int8 *)(v3 + 26492),
        *(unsigned __int8 *)(v3 + 26493),
        *(const void **)(v3 + 26496));
      qdf_trace_msg(
        61,
        5,
        "%s: %02d: ce_id=%d, inited=%d, hi_tasklet_ce=%d hif_ce_state=%pK",
        "ce_tasklet_entry_dump",
        1,
        *(_DWORD *)(v3 + 26544),
        *(unsigned __int8 *)(v3 + 26548),
        *(unsigned __int8 *)(v3 + 26549),
        *(const void **)(v3 + 26552));
      qdf_trace_msg(
        61,
        5,
        "%s: %02d: ce_id=%d, inited=%d, hi_tasklet_ce=%d hif_ce_state=%pK",
        "ce_tasklet_entry_dump",
        2,
        *(_DWORD *)(v3 + 26600),
        *(unsigned __int8 *)(v3 + 26604),
        *(unsigned __int8 *)(v3 + 26605),
        *(const void **)(v3 + 26608));
      qdf_trace_msg(
        61,
        5,
        "%s: %02d: ce_id=%d, inited=%d, hi_tasklet_ce=%d hif_ce_state=%pK",
        "ce_tasklet_entry_dump",
        3,
        *(_DWORD *)(v3 + 26656),
        *(unsigned __int8 *)(v3 + 26660),
        *(unsigned __int8 *)(v3 + 26661),
        *(const void **)(v3 + 26664));
      qdf_trace_msg(
        61,
        5,
        "%s: %02d: ce_id=%d, inited=%d, hi_tasklet_ce=%d hif_ce_state=%pK",
        "ce_tasklet_entry_dump",
        4,
        *(_DWORD *)(v3 + 26712),
        *(unsigned __int8 *)(v3 + 26716),
        *(unsigned __int8 *)(v3 + 26717),
        *(const void **)(v3 + 26720));
      qdf_trace_msg(
        61,
        5,
        "%s: %02d: ce_id=%d, inited=%d, hi_tasklet_ce=%d hif_ce_state=%pK",
        "ce_tasklet_entry_dump",
        5,
        *(_DWORD *)(v3 + 26768),
        *(unsigned __int8 *)(v3 + 26772),
        *(unsigned __int8 *)(v3 + 26773),
        *(const void **)(v3 + 26776));
      qdf_trace_msg(
        61,
        5,
        "%s: %02d: ce_id=%d, inited=%d, hi_tasklet_ce=%d hif_ce_state=%pK",
        "ce_tasklet_entry_dump",
        6,
        *(_DWORD *)(v3 + 26824),
        *(unsigned __int8 *)(v3 + 26828),
        *(unsigned __int8 *)(v3 + 26829),
        *(const void **)(v3 + 26832));
      qdf_trace_msg(
        61,
        5,
        "%s: %02d: ce_id=%d, inited=%d, hi_tasklet_ce=%d hif_ce_state=%pK",
        "ce_tasklet_entry_dump",
        7,
        *(_DWORD *)(v3 + 26880),
        *(unsigned __int8 *)(v3 + 26884),
        *(unsigned __int8 *)(v3 + 26885),
        *(const void **)(v3 + 26888));
      qdf_trace_msg(
        61,
        5,
        "%s: %02d: ce_id=%d, inited=%d, hi_tasklet_ce=%d hif_ce_state=%pK",
        "ce_tasklet_entry_dump",
        8,
        *(_DWORD *)(v3 + 26936),
        *(unsigned __int8 *)(v3 + 26940),
        *(unsigned __int8 *)(v3 + 26941),
        *(const void **)(v3 + 26944));
      qdf_trace_msg(
        61,
        5,
        "%s: %02d: ce_id=%d, inited=%d, hi_tasklet_ce=%d hif_ce_state=%pK",
        "ce_tasklet_entry_dump",
        9,
        *(_DWORD *)(v3 + 26992),
        *(unsigned __int8 *)(v3 + 26996),
        *(unsigned __int8 *)(v3 + 26997),
        *(const void **)(v3 + 27000));
      qdf_trace_msg(
        61,
        5,
        "%s: %02d: ce_id=%d, inited=%d, hi_tasklet_ce=%d hif_ce_state=%pK",
        "ce_tasklet_entry_dump",
        10,
        *(_DWORD *)(v3 + 27048),
        *(unsigned __int8 *)(v3 + 27052),
        *(unsigned __int8 *)(v3 + 27053),
        *(const void **)(v3 + 27056));
      qdf_trace_msg(
        61,
        5,
        "%s: %02d: ce_id=%d, inited=%d, hi_tasklet_ce=%d hif_ce_state=%pK",
        "ce_tasklet_entry_dump",
        11,
        *(_DWORD *)(v3 + 27104),
        *(unsigned __int8 *)(v3 + 27108),
        *(unsigned __int8 *)(v3 + 27109),
        *(const void **)(v3 + 27112));
      return 0;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
