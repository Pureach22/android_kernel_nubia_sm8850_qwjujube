__int64 __fastcall dp_rx_refill_thread_init(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned __int64 thread; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _QWORD v28[2]; // [xsp+0h] [xbp-20h] BYREF
  int v29; // [xsp+10h] [xbp-10h]
  __int64 v30; // [xsp+18h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v28[0] = 0;
  v28[1] = 0;
  v2 = scnprintf(v28, 20, "dp_refill_thread");
  qdf_trace_msg(0x45u, 5u, "%s: Initializing %s", v2, v3, v4, v5, v6, v7, v8, v9, "dp_rx_refill_thread_init", v28);
  *(_DWORD *)(a1 + 216) = 0;
  *(_QWORD *)(a1 + 168) = 0;
  qdf_event_create((_DWORD *)(a1 + 8));
  qdf_event_create((_DWORD *)(a1 + 48));
  qdf_event_create((_DWORD *)(a1 + 88));
  qdf_event_create((_DWORD *)(a1 + 128));
  _init_waitqueue_head(a1 + 176, "&refill_thread->wait_q", &dp_rx_refill_thread_init___key);
  thread = qdf_create_thread((__int64)dp_rx_refill_thread_loop, a1, (__int64)v28);
  *(_QWORD *)a1 = thread;
  if ( thread )
  {
    qdf_wake_up_process(thread);
    result = qdf_wait_single_event(a1 + 8, 0);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: failed waiting for refill thread creation status: %d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "dp_rx_refill_thread_init",
        (unsigned int)result);
      result = 16;
    }
    else
    {
      *(_DWORD *)(a1 + 216) = 1;
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: could not create dp_rx_refill_thread",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "dp_rx_refill_thread_init");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
