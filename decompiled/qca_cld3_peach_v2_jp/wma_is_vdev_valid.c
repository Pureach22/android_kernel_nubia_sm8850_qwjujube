__int64 __fastcall wma_is_vdev_valid(
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
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  char v19; // w8

  context = _cds_get_context(54, (__int64)"wma_is_vdev_valid", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    goto LABEL_5;
  if ( *((unsigned __int16 *)context + 81) <= a1 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: vdev_id: %d is invalid, max_bssid: %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wma_is_vdev_valid",
      a1);
LABEL_5:
    v19 = 0;
    return v19 & 1;
  }
  v19 = *(_BYTE *)(context[65] + 488LL * a1 + 184);
  return v19 & 1;
}
