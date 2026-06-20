__int64 __fastcall lim_sta_mlme_vdev_start_send(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        unsigned __int8 *a11)
{
  _QWORD *context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  unsigned int assoc_type; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  context = _cds_get_context(53, (__int64)"lim_sta_mlme_vdev_start_send", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v22 = (__int64)context;
    assoc_type = mlme_get_assoc_type(*(_QWORD *)(a1 + 520), v14, v15, v16, v17, v18, v19, v20, v21);
    if ( assoc_type - 1 >= 2 )
    {
      if ( assoc_type )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: assoc_type %d is invalid",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "lim_sta_mlme_vdev_start_send",
          assoc_type);
      else
        lim_process_mlm_join_req(v22, a11);
    }
    return 0;
  }
  else
  {
    if ( a11 )
      _qdf_mem_free((__int64)a11);
    return 4;
  }
}
