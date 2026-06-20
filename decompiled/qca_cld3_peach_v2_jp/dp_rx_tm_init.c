__int64 __fastcall dp_rx_tm_init(
        unsigned __int8 *a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x20
  __int64 v15; // x8
  __int64 v16; // x28
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 **v41; // x0
  __int64 v42; // x8
  unsigned int (*v43)(void); // x8
  unsigned __int64 thread; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w20
  const char *v54; // x2
  _QWORD v55[3]; // [xsp+8h] [xbp-18h] BYREF

  v55[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 < 9u )
  {
    *a1 = a2;
    *((_DWORD *)a1 + 4) = 0;
    qdf_trace_msg(0x45u, 5u, "%s: initializing %u threads", a3, a4, a5, a6, a7, a8, a9, a10, "dp_rx_tm_init");
    v13 = _qdf_mem_malloc(8LL * (a2 & 0x1F), "dp_rx_tm_init", 1076);
    *((_QWORD *)a1 + 3) = v13;
    if ( v13 )
    {
      if ( *a1 )
      {
        v14 = 0;
        while ( 1 )
        {
          *(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * v14) = _qdf_mem_malloc(0xF80u, "dp_rx_tm_init", 1086);
          v15 = *(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * v14);
          if ( !v15 )
            goto LABEL_27;
          *(_QWORD *)(v15 + 696) = a1;
          v16 = *(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * v14);
          memset(v55, 0, 15);
          qdf_mem_set(v55, 0xFu, 0);
          if ( !v16 )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: rx_thread is null!",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              "dp_rx_tm_thread_init");
            v53 = 5;
            goto LABEL_25;
          }
          *(_BYTE *)v16 = v14;
          *(_QWORD *)(v16 + 424) = 0;
          *(_QWORD *)(v16 + 440) = v16 + 440;
          *(_QWORD *)(v16 + 448) = v16 + 440;
          *(_QWORD *)(v16 + 456) = 0;
          qdf_event_create((_DWORD *)(v16 + 16));
          qdf_event_create((_DWORD *)(v16 + 56));
          qdf_event_create((_DWORD *)(v16 + 96));
          qdf_event_create((_DWORD *)(v16 + 136));
          qdf_event_create((_DWORD *)(v16 + 176));
          qdf_event_create((_DWORD *)(v16 + 216));
          qdf_event_create((_DWORD *)(v16 + 256));
          qdf_event_create((_DWORD *)(v16 + 296));
          qdf_event_create((_DWORD *)(v16 + 336));
          qdf_event_create((_DWORD *)(v16 + 376));
          *(_DWORD *)(v16 + 416) = 0;
          _init_waitqueue_head(v16 + 1136, "&rx_thread->wait_q", &dp_rx_tm_thread_init___key);
          v25 = scnprintf(v55, 15, "dp_rx_thread_%u", v14);
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: %s %u",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "dp_rx_tm_thread_init",
            v55,
            (unsigned int)v14);
          v41 = **(__int64 ****)(*(_QWORD *)(v16 + 696) + 8LL);
          if ( !v41 )
            goto LABEL_16;
          if ( *v41 )
          {
            v42 = **v41;
            if ( v42 )
            {
              v43 = *(unsigned int (**)(void))(v42 + 264);
              if ( v43 )
              {
                if ( *((_DWORD *)v43 - 1) != -1095293032 )
                  __break(0x8228u);
                if ( v43() )
                {
                  init_dummy_netdev(v16 + 1216);
                  qdf_status_from_os_return(0);
                  netif_napi_add_weight(v16 + 1216, v16 + 704, dp_rx_tm_thread_napi_poll, 64);
                  napi_enable(v16 + 704);
                }
              }
            }
          }
          else
          {
LABEL_16:
            qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v33, v34, v35, v36, v37, v38, v39, v40, "cdp_cfg_get");
          }
          thread = qdf_create_thread((__int64)dp_rx_thread_loop, v16, (__int64)v55);
          *(_QWORD *)(v16 + 8) = thread;
          if ( !thread )
            break;
          qdf_wake_up_process(thread);
          if ( (unsigned int)qdf_wait_single_event(v16 + 16, 0) )
          {
            v54 = "%s: failed waiting for thread creation id %d";
            goto LABEL_24;
          }
          if ( ++v14 >= (unsigned __int64)*a1 )
            goto LABEL_20;
        }
        v54 = "%s: could not create dp_rx_thread %d";
LABEL_24:
        qdf_trace_msg(0x45u, 2u, v54, v45, v46, v47, v48, v49, v50, v51, v52, "dp_rx_tm_thread_init", (unsigned int)v14);
        v53 = 16;
        goto LABEL_25;
      }
LABEL_20:
      result = 0;
      *((_DWORD *)a1 + 4) = 1;
    }
    else
    {
LABEL_27:
      v53 = 2;
LABEL_25:
      dp_rx_tm_deinit(a1);
      result = v53;
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: unable to initialize %u number of threads. MAX %u",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_rx_tm_init");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
