__int64 __fastcall wma_is_roam_in_progress(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x20
  char is_vdev_valid; // w8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0

  context = _cds_get_context(54, (__int64)"wma_is_roam_in_progress", a2, a3, a4, a5, a6, a7, a8, a9);
  is_vdev_valid = wma_is_vdev_valid(a1);
  LOBYTE(v20) = 0;
  if ( (is_vdev_valid & 1) != 0 )
  {
    if ( context )
    {
      v20 = *(_QWORD *)(context[65] + 488LL * a1);
      if ( v20 )
        LOBYTE(v20) = (*(_DWORD *)(v20 + 16) & 0xFFFFFFFD) == 0
                   && wlan_cm_is_vdev_roam_started(v20, v12, v13, v14, v15, v16, v17, v18, v19);
    }
  }
  return v20 & 1;
}
