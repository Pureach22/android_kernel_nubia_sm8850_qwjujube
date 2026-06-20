__int64 __fastcall sub_432EAC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _WORD *v11; // x20
  __int64 v12; // d8

  *v11 = HIWORD(a9);
  v11[1] = HIWORD(a10);
  v11[2] = HIWORD(a11);
  v11[3] = HIWORD(v12);
  return sme_set_roam_rescan_rssi_diff(a1, a2, a3);
}
