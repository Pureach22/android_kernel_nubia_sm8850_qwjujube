__int64 __fastcall hdd_stop_ap_link(
        _DWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  hdd_deinit_ap_mode(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  hdd_vdev_destroy((__int64)a1, v10, v11, v12, v13, v14, v15, v16, v17);
  return 0;
}
