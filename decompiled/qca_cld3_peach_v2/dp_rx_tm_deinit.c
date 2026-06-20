__int64 __fastcall dp_rx_tm_deinit(
        unsigned __int8 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w8
  unsigned __int64 v12; // x20
  __int64 v13; // x9
  __int64 v14; // x8
  unsigned __int64 i; // x20
  unsigned __int64 j; // x22
  __int64 v18; // x23
  __int64 v19; // x1
  __int64 v20; // x1
  __int64 v21; // x1
  __int64 v22; // x1
  __int64 v23; // x1
  __int64 v24; // x1
  __int64 v25; // x1
  __int64 v26; // x1
  __int64 v27; // x1
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 **v36; // x0
  __int64 v37; // x8
  unsigned int (*v38)(void); // x8
  __int64 v39; // x0

  if ( *((_QWORD *)a1 + 3) )
  {
    v10 = *a1;
    if ( !*a1 )
      goto LABEL_14;
    v12 = 0;
    do
    {
      v13 = *(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * v12);
      if ( v13 && *((_DWORD *)a1 + 4) )
      {
        *(_QWORD *)(v13 + 424) |= 0x10000uLL;
        v14 = *(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * v12);
        *(_QWORD *)(v14 + 424) |= 2uLL;
        _wake_up(*(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * v12) + 1136LL, 1, 1, 0);
        v10 = *a1;
      }
      ++v12;
    }
    while ( v12 < v10 );
    if ( v10 )
    {
      for ( i = 0; i < v10; ++i )
      {
        if ( *(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * i) && *((_DWORD *)a1 + 4) )
        {
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: waiting for shutdown of thread %d",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            "dp_rx_tm_shutdown",
            (unsigned int)i);
          qdf_wait_single_event(*(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * i) + 136LL, 0);
          v10 = *a1;
        }
      }
      *((_DWORD *)a1 + 4) = 0;
      if ( v10 )
      {
        for ( j = 0; j < v10; ++j )
        {
          v18 = *(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * j);
          if ( v18 )
          {
            qdf_event_destroy(v18 + 16, a2);
            qdf_event_destroy(v18 + 56, v19);
            qdf_event_destroy(v18 + 96, v20);
            qdf_event_destroy(v18 + 136, v21);
            qdf_event_destroy(v18 + 176, v22);
            qdf_event_destroy(v18 + 216, v23);
            qdf_event_destroy(v18 + 256, v24);
            qdf_event_destroy(v18 + 296, v25);
            qdf_event_destroy(v18 + 336, v26);
            qdf_event_destroy(v18 + 376, v27);
            v36 = **(__int64 ****)(*(_QWORD *)(v18 + 696) + 8LL);
            if ( v36 && *v36 )
            {
              v37 = **v36;
              if ( v37 )
              {
                v38 = *(unsigned int (**)(void))(v37 + 264);
                if ( v38 )
                {
                  if ( *((_DWORD *)v38 - 1) != -1095293032 )
                    __break(0x8228u);
                  if ( v38() )
                  {
                    v39 = _netif_napi_del(v18 + 704);
                    synchronize_net(v39);
                  }
                }
              }
            }
            else
            {
              qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v28, v29, v30, v31, v32, v33, v34, v35, "cdp_cfg_get");
            }
            _qdf_mem_free(*(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * j));
            v10 = *a1;
          }
        }
      }
    }
    else
    {
LABEL_14:
      *((_DWORD *)a1 + 4) = 0;
    }
    _qdf_mem_free(*((_QWORD *)a1 + 3));
    *((_QWORD *)a1 + 3) = 0;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: rx_tm_hdl->rx_thread not initialized!",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_rx_tm_deinit");
  }
  return 0;
}
