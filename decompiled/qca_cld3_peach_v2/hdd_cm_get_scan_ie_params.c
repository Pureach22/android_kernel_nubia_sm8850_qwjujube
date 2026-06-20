__int64 __fastcall hdd_cm_get_scan_ie_params(
        __int64 a1,
        __int64 a2,
        int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x21
  __int64 link_info_by_vdev; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  _WORD *v33; // x8
  __int64 v35; // x10
  int v36; // w8
  int v37; // w8

  context = _cds_get_context(51, (__int64)"hdd_cm_get_scan_ie_params", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
  {
    qdf_trace_msg(0x33u, 2u, "%s: hdd_ctx is NULL", v15, v16, v17, v18, v19, v20, v21, v22, "hdd_cm_get_scan_ie_params");
    return 4;
  }
  v23 = context;
  link_info_by_vdev = hdd_get_link_info_by_vdev(context);
  if ( !link_info_by_vdev )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: adapter is NULL for vdev %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "hdd_cm_get_scan_ie_params",
      *(unsigned __int8 *)(a1 + 168));
    return 4;
  }
  v33 = (_WORD *)(*(_QWORD *)link_info_by_vdev + 39624LL);
  if ( *(_DWORD *)(*(_QWORD *)link_info_by_vdev + 40LL) != 2 )
  {
    v35 = *(_QWORD *)(*(_QWORD *)link_info_by_vdev + 41680LL);
    if ( v35 )
    {
      *(_QWORD *)(a2 + 8) = v35;
      v33 += 1032;
      goto LABEL_9;
    }
    if ( !*v33 )
      goto LABEL_10;
  }
  *(_QWORD *)(a2 + 8) = *(_QWORD *)link_info_by_vdev + 39626LL;
LABEL_9:
  *(_DWORD *)a2 = (unsigned __int16)*v33;
LABEL_10:
  v36 = *(_DWORD *)v23[13];
  switch ( v36 )
  {
    case 6:
      v37 = 1;
      break;
    case 11:
      v37 = 3;
      break;
    case 8:
      v37 = 2;
      break;
    default:
      v37 = 4 * (v36 == 14);
      break;
  }
  *a3 = v37;
  return 0;
}
