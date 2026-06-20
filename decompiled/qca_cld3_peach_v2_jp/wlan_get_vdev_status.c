__int64 __fastcall wlan_get_vdev_status(
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
  unsigned int v9; // w0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  const char *v19; // x2

  if ( !a1 )
  {
    v19 = "%s: null vdev";
LABEL_9:
    qdf_trace_msg(0x4Cu, 2u, v19, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_get_vdev_status");
    return 0;
  }
  if ( !*(_QWORD *)(a1 + 152) )
  {
    v19 = "%s: null pdev";
    goto LABEL_9;
  }
  v9 = wlan_serialization_vdev_scan_status(a1);
  if ( v9 < 5 && ((0x17u >> v9) & 1) != 0 )
    return dword_A30348[v9];
  qdf_trace_msg(
    0x15u,
    3u,
    "%s: invalid serialization status %d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "wlan_get_scan_status_from_serialization_status",
    v9);
  return 0;
}
