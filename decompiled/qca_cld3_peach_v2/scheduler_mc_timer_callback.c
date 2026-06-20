__int64 __fastcall scheduler_mc_timer_callback(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  int v3; // w8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  unsigned int v13; // w1
  __int64 v14; // x21
  __int64 v15; // x22
  unsigned int v16; // w20
  _QWORD *v17; // x0
  __int64 v18; // x19
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _QWORD v35[7]; // [xsp+8h] [xbp-38h] BYREF

  v35[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35[4] = 0;
  v35[5] = 0;
  if ( result )
  {
    v1 = result;
    *(_QWORD *)(result + 160) = jiffies;
    v2 = raw_spin_lock_irqsave(result + 48);
    v3 = *(_DWORD *)(v1 + 148);
    *(_QWORD *)(v1 + 56) = v2;
    if ( v3 != 21 )
    {
      if ( v3 == 20 )
        *(_DWORD *)(v1 + 148) = 19;
      raw_spin_unlock_irqrestore(v1 + 48, v2);
      v12 = "%s: MC timer fired but is not running; skip callback";
      v13 = 8;
      goto LABEL_6;
    }
    v14 = *(_QWORD *)(v1 + 64);
    v15 = *(_QWORD *)(v1 + 72);
    v16 = *(_DWORD *)(v1 + 144);
    *(_DWORD *)(v1 + 148) = 19;
    raw_spin_unlock_irqrestore(v1 + 48, v2);
    result = qdf_try_allowing_sleep(v16);
    if ( !v14 )
      goto LABEL_7;
    v17 = (_QWORD *)_qdf_mem_malloc(0x10u, "scheduler_qdf_mc_timer_init", 469);
    if ( !v17 )
    {
      v12 = "%s: failed to allocate sched_qdf_mc_timer_cb_wrapper";
      v13 = 2;
LABEL_6:
      result = qdf_trace_msg(0x4Au, v13, v12, v4, v5, v6, v7, v8, v9, v10, v11, "scheduler_mc_timer_callback");
      goto LABEL_7;
    }
    *v17 = v14;
    v17[1] = v15;
    v18 = (__int64)v17;
    v35[0] = 4207804416LL;
    v35[1] = v17;
    v35[2] = scheduler_qdf_mc_timer_callback_t_wrapper;
    v35[3] = scheduler_msg_flush_mc;
    result = scheduler_post_msg_by_priority(77670455, v35, 0);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x4Au,
        2u,
        "%s: couldn't post from %d to %d - called from %d, %s",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "scheduler_post_message_debug",
        74,
        74,
        726,
        "scheduler_mc_timer_callback");
      qdf_trace_msg(
        0x4Au,
        2u,
        "%s: Could not enqueue timer to timer queue",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "scheduler_mc_timer_callback");
      result = _qdf_mem_free(v18);
    }
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
