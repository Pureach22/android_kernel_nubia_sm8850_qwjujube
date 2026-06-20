__int64 __fastcall lim_ap_mlme_vdev_start_req_failed(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned int *a11)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  context = _cds_get_context(53, (__int64)"lim_ap_mlme_vdev_start_req_failed", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    lim_process_mlm_start_cnf((__int64)context, a11, v13, v14, v15, v16, v17, v18, v19, v20);
    return 0;
  }
  else
  {
    if ( a11 )
      _qdf_mem_free((__int64)a11);
    return 4;
  }
}
