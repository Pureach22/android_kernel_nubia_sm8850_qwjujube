__int64 __fastcall dp_bus_suspend(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 (__fastcall *v32)(__int64, __int64); // x8
  __int64 v33; // x8
  __int64 v34; // x8
  void (__fastcall *v35)(__int64, __int64); // x8
  const char *v36; // x2
  const char *v37; // x3

  if ( a2 || (v10 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: pdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "dp_bus_suspend");
    return 4;
  }
  if ( *(_DWORD *)(v10 + 93500) )
  {
    qdf_sleep();
    if ( *(_DWORD *)(v10 + 93500) )
    {
      qdf_sleep();
      if ( *(_DWORD *)(v10 + 93500) )
      {
        qdf_sleep();
        if ( *(_DWORD *)(v10 + 93500) )
        {
          qdf_sleep();
          if ( *(_DWORD *)(v10 + 93500) )
          {
            qdf_sleep();
            if ( *(_DWORD *)(v10 + 93500) )
            {
              qdf_sleep();
              if ( *(_DWORD *)(v10 + 93500) )
              {
                qdf_sleep();
                if ( *(_DWORD *)(v10 + 93500) )
                {
                  qdf_sleep();
                  if ( *(_DWORD *)(v10 + 93500) )
                  {
                    qdf_sleep();
                    if ( *(_DWORD *)(v10 + 93500) )
                    {
                      qdf_sleep();
                      v12 = *(_DWORD *)(v10 + 93500);
                      if ( v12 )
                      {
                        qdf_sleep();
                        qdf_trace_msg(
                          0x45u,
                          5u,
                          "%s: TX frames are pending %d, abort suspend",
                          v13,
                          v14,
                          v15,
                          v16,
                          v17,
                          v18,
                          v19,
                          v20,
                          "dp_bus_suspend",
                          v12);
                        dp_find_missing_tx_comp(a1, v21, v22, v23, v24, v25, v26, v27, v28);
                        return 15;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( *(_BYTE *)(a1 + 17784) == 2 )
    timer_delete((timer_t)(a1 + 17728));
  v30 = *(_QWORD *)(a1 + 20056);
  if ( !v30 )
  {
    v36 = "%s: monitor soc is NULL";
    goto LABEL_31;
  }
  v31 = *(_QWORD *)(v30 + 416);
  if ( !v31 || (v32 = *(__int64 (__fastcall **)(__int64, __int64))(v31 + 536)) == nullptr )
  {
    v36 = "%s: callback not registered";
LABEL_31:
    v37 = "dp_monitor_reap_timer_stop";
    goto LABEL_32;
  }
  if ( *((_DWORD *)v32 - 1) != 460609471 )
    __break(0x8228u);
  if ( (v32(a1, 4) & 1) == 0 )
    return 0;
  v33 = *(_QWORD *)(a1 + 20056);
  if ( v33 )
  {
    v34 = *(_QWORD *)(v33 + 416);
    if ( v34 )
    {
      v35 = *(void (__fastcall **)(__int64, __int64))(v34 + 240);
      if ( v35 )
      {
        if ( *((_DWORD *)v35 - 1) != -1990423103 )
          __break(0x8228u);
        v35(a1, 1024);
        return 0;
      }
    }
    v36 = "%s: callback not registered";
  }
  else
  {
    v36 = "%s: monitor soc is NULL";
  }
  v37 = "dp_monitor_service_mon_rings";
LABEL_32:
  qdf_trace_msg(0x92u, 8u, v36, a3, a4, a5, a6, a7, a8, a9, a10, v37);
  return 0;
}
