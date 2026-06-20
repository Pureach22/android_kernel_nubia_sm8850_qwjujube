__int64 __fastcall hdd_clean_up_interface(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  wlan_hdd_release_intf_addr((__int64)a1, (unsigned __int8 *)(a2 + 1617), a3, a4, a5, a6, a7, a8, a9, a10);
  hdd_stop_adapter(a1, a2);
  hdd_deinit_adapter(v12, v13, v14, v15, v16, v17, v18, v19, (__int64)a1, a2);
  return hdd_close_adapter(a1, a2, 1, v20, v21, v22, v23, v24, v25, v26, v27);
}
