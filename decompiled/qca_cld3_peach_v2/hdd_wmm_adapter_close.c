__int64 __fastcall hdd_wmm_adapter_close(
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
  __int64 v10; // x0
  _QWORD *v11; // x19
  _QWORD *v12; // x21
  unsigned int v13; // w8
  __int64 v14; // x9
  __int64 v15; // x26
  int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2
  int v26; // w0

  v10 = qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_wmm_adapter_close");
  v11 = *(_QWORD **)(a1 + 1816);
  v12 = (_QWORD *)(a1 + 1816);
  if ( v11 == (_QWORD *)(a1 + 1816) )
    return 0;
  while ( 1 )
  {
    v13 = *((_DWORD *)v11 + 8);
    if ( v13 >= 5 )
      break;
    v14 = v11[3];
    v15 = v14 + 280LL * v13 + 1880;
    *(_QWORD *)(v14 + 280LL * v13 + 1980) = 0;
    if ( *((_BYTE *)v11 + 76) == 1 )
    {
      *((_BYTE *)v11 + 76) = 0;
      v16 = qdf_mc_timer_stop(v14 + 280LL * v13 + 1992);
      v25 = "%s: Failed to stop inactivity timer";
      if ( v16
        || (v26 = qdf_mc_timer_destroy(v15 + 112), v25 = "%s: Failed to destroy inactivity timer:Timer started", v26) )
      {
        qdf_trace_msg(0x33u, 2u, v25, v17, v18, v19, v20, v21, v22, v23, v24, "hdd_wmm_disable_inactivity_timer");
      }
    }
    if ( *((_DWORD *)v11 + 4) == -1 && *((_DWORD *)v11 + 18) == 1464683864 )
      cds_flush_work((__int64)(v11 + 5));
    v10 = hdd_wmm_free_context(v11);
    v11 = (_QWORD *)*v12;
    if ( (_QWORD *)*v12 == v12 )
      return 0;
  }
  __break(0x5512u);
  return hdd_wmm_free_context(v10);
}
