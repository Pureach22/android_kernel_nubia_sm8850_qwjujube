__int64 __fastcall wma_stop(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  _QWORD *context; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w19
  __int64 v26; // x8
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x24
  unsigned __int64 v37; // x20
  _QWORD *v38; // x0
  __int64 v39; // x8
  void (*v40)(void); // x8

  context = _cds_get_context(54, (__int64)"wma_stop", a1, a2, a3, a4, a5, a6, a7, a8);
  qdf_trace_msg(0x36u, 8u, "%s: Enter", v9, v10, v11, v12, v13, v14, v15, v16, "wma_stop");
  if ( context )
  {
    if ( _cds_get_context(53, (__int64)"wma_stop", v17, v18, v19, v20, v21, v22, v23, v24)
      && (unsigned int)cds_get_conparam() != 5 )
    {
      v26 = context[78];
      if ( v26 )
      {
        cds_flush_work(v26 + 16);
        v27 = context[78];
        if ( *(_QWORD *)(v27 + 64) )
        {
          _qdf_nbuf_free(*(_QWORD *)(v27 + 64));
          v27 = context[78];
        }
        _qdf_mem_free(v27);
        context[78] = 0;
      }
      if ( (unsigned int)qdf_mc_timer_destroy((__int64)(context + 343)) )
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Failed to destroy the log completion timer",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "wma_stop");
      if ( *((_WORD *)context + 81) )
      {
        v36 = 0;
        v37 = 0;
        do
        {
          if ( *(_QWORD *)(context[65] + v36) && (wma_is_vdev_up((unsigned int)v37) & 1) != 0 )
          {
            v38 = _cds_get_context(71, (__int64)"wma_stop", v28, v29, v30, v31, v32, v33, v34, v35);
            if ( v38 && *v38 )
            {
              v39 = *(_QWORD *)(*v38 + 120LL);
              if ( v39 )
              {
                v40 = *(void (**)(void))(v39 + 40);
                if ( v40 )
                {
                  if ( *((_DWORD *)v40 - 1) != -251540498 )
                    __break(0x8228u);
                  v40();
                }
              }
            }
            else
            {
              qdf_trace_msg(
                0x89u,
                8u,
                "%s: invalid instance",
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                "cdp_fc_vdev_flush");
            }
          }
          ++v37;
          v36 += 488;
        }
        while ( v37 < *((unsigned __int16 *)context + 81) );
      }
      v25 = wma_tx_detach(context, v28, v29, v30, v31, v32, v33, v34, v35);
      if ( v25 )
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Failed to deregister tx management",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "wma_stop");
    }
    else
    {
      v25 = 0;
    }
  }
  else
  {
    v25 = 4;
  }
  qdf_trace_msg(0x36u, 8u, "%s: Exit", v17, v18, v19, v20, v21, v22, v23, v24, "wma_stop");
  return v25;
}
