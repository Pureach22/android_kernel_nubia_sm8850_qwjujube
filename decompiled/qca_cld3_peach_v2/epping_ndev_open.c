__int64 __fastcall epping_ndev_open(
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
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  unsigned __int64 v28; // x9
  __int64 v29; // x10
  unsigned __int64 v36; // x13

  context = _cds_get_context(64, (__int64)"epping_start_adapter", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    if ( (*(_BYTE *)(a1 + 2821) & 1) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        3u,
        "%s: adapter %pK already started\n",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "epping_start_adapter",
        a1 + 2688);
    }
    else
    {
      pld_request_bus_bandwidth(context[5], 4u);
      netif_carrier_on(*(_QWORD *)(a1 + 2704));
      qdf_trace_msg(0x33u, 4u, "%s: Enabling queues", v19, v20, v21, v22, v23, v24, v25, v26, "epping_start_adapter");
      v27 = *(_QWORD *)(a1 + 2704);
      if ( *(_DWORD *)(v27 + 1096) )
      {
        v28 = 0;
        v29 = 336;
        do
        {
          _X12 = (unsigned __int64 *)(*(_QWORD *)(v27 + 24) + v29);
          __asm { PRFM            #0x11, [X12] }
          do
            v36 = __ldxr(_X12);
          while ( __stxr(v36 & 0xFFFFFFFFFFFFFFFELL, _X12) );
          ++v28;
          v29 += 384;
        }
        while ( v28 < *(unsigned int *)(v27 + 1096) );
      }
      *(_BYTE *)(a1 + 2821) = 1;
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 1u, "%s: qdf_ctx is NULL", v11, v12, v13, v14, v15, v16, v17, v18, "epping_start_adapter");
  }
  return 0;
}
