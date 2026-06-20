__int64 __fastcall dp_rx_refill_thread_loop(
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
  __int64 v10; // x1
  unsigned __int64 current_comm; // x20
  unsigned int current_pid; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  __int64 v22; // x1
  unsigned __int64 v23; // x23
  unsigned int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x1
  unsigned __int64 v34; // x23
  unsigned int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned __int64 v50; // x9
  unsigned __int64 v53; // x8
  unsigned __int64 v56; // x8
  unsigned __int64 v59; // x8
  unsigned __int64 v62; // x8
  unsigned __int64 v63; // x20
  unsigned int v64; // w0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned __int64 v73; // x20
  unsigned int v74; // w0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x1
  unsigned __int64 v87; // x8
  _QWORD v88[6]; // [xsp+0h] [xbp-30h] BYREF

  v88[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    qdf_get_current_task();
    qdf_set_user_nice();
    qdf_set_wake_up_idle(1);
    qdf_event_set(a1 + 8, v10);
    current_comm = qdf_get_current_comm();
    current_pid = qdf_get_current_pid();
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: starting rx_refill_thread (%s) pid %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "dp_rx_refill_thread_loop",
      current_comm,
      current_pid);
    while ( 1 )
    {
      if ( (*(_QWORD *)(a1 + 168) & 2) != 0 || (*(_QWORD *)(a1 + 168) & 4) != 0 )
      {
        v21 = 0;
      }
      else
      {
        memset(v88, 0, 40);
        init_wait_entry(v88, 0);
        while ( 1 )
        {
          v21 = prepare_to_wait_event(a1 + 176, v88, 1);
          if ( (*(_QWORD *)(a1 + 168) & 2) != 0 || (*(_QWORD *)(a1 + 168) & 4) != 0 )
            break;
          if ( v21 )
            goto LABEL_11;
          schedule();
        }
        finish_wait(a1 + 176, v88);
        v21 = 0;
      }
LABEL_11:
      if ( (unsigned int)qdf_status_from_os_return(v21) == 48 )
        break;
      _X8 = (unsigned __int64 *)(a1 + 168);
      __asm { PRFM            #0x11, [X8] }
      do
        v50 = __ldxr(_X8);
      while ( __stxr(v50 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
      _X9 = (unsigned __int64 *)(a1 + 168);
      __asm { PRFM            #0x11, [X9] }
      do
        v53 = __ldxr(_X9);
      while ( __stlxr(v53 & 0xFFFFFFFFFFFFFFEFLL, _X9) );
      __dmb(0xBu);
      if ( (v53 & 0x10) != 0 )
      {
        _X9 = (unsigned __int64 *)(a1 + 168);
        __asm { PRFM            #0x11, [X9] }
        do
          v87 = __ldxr(_X9);
        while ( __stlxr(v87 & 0xFFFFFFFFFFFFFFFBLL, _X9) );
        __dmb(0xBu);
        if ( (v87 & 4) != 0 )
          qdf_event_set(a1 + 48, v22);
        v63 = qdf_get_current_comm();
        v64 = qdf_get_current_pid();
        qdf_trace_msg(
          0x45u,
          8u,
          "%s: shutting down (%s) pid %d",
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          "dp_rx_refill_thread_sub_loop",
          v63,
          v64);
        break;
      }
      _X9 = (unsigned __int64 *)(a1 + 168);
      __asm { PRFM            #0x11, [X9] }
      do
        v56 = __ldxr(_X9);
      while ( __stlxr(v56 & 0xFFFFFFFFFFFEFFFFLL, _X9) );
      __dmb(0xBu);
      if ( (v56 & 0x10000) != 0 )
      {
        ((void (__fastcall *)(__int64))wlan_dp_resource_mgr_upscale_resources)(a1);
      }
      else
      {
        _X9 = (unsigned __int64 *)(a1 + 168);
        __asm { PRFM            #0x11, [X9] }
        do
          v59 = __ldxr(_X9);
        while ( __stlxr(v59 & 0xFFFFFFFEFFFFFFFFLL, _X9) );
        __dmb(0xBu);
        if ( (v59 & 0x100000000LL) != 0 )
        {
          ((void (*)(void))wlan_dp_resource_mgr_downscale_resources)();
        }
        else
        {
          dp_rx_refill_buff_pool_enqueue(*(_QWORD *)(a1 + 208));
          _X9 = (unsigned __int64 *)(a1 + 168);
          __asm { PRFM            #0x11, [X9] }
          do
            v62 = __ldxr(_X9);
          while ( __stlxr(v62 & 0xFFFFFFFFFFFFFFFBLL, _X9) );
          __dmb(0xBu);
          if ( (v62 & 4) != 0 )
          {
            v23 = qdf_get_current_comm();
            v24 = qdf_get_current_pid();
            qdf_trace_msg(
              0x45u,
              8u,
              "%s: refill thread received suspend ind (%s) pid %d",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              "dp_rx_refill_thread_sub_loop",
              v23,
              v24);
            qdf_event_set(a1 + 48, v33);
            v34 = qdf_get_current_comm();
            v35 = qdf_get_current_pid();
            qdf_trace_msg(
              0x45u,
              8u,
              "%s: refill thread waiting for resume (%s) pid %d",
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              "dp_rx_refill_thread_sub_loop",
              v34,
              v35);
            qdf_wait_single_event(a1 + 88, 0);
          }
        }
      }
    }
    v73 = qdf_get_current_comm();
    v74 = qdf_get_current_pid();
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: exiting (%s) pid %d",
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      "dp_rx_refill_thread_loop",
      v73,
      v74);
    qdf_event_set(a1 + 128, v83);
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: bad Args passed", a2, a3, a4, a5, a6, a7, a8, a9, "dp_rx_refill_thread_loop");
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
