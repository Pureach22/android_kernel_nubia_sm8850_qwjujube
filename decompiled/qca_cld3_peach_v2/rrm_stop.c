__int64 __fastcall rrm_stop(
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
  _WORD *v9; // x8
  __int64 v10; // x0
  int v11; // w1

  v9 = (_WORD *)(a1 + 0x4000);
  v10 = *(_QWORD *)(a1 + 21624);
  v11 = (unsigned __int16)v9[1910];
  v9[822] = 0;
  v9[1094] = 0;
  v9[1366] = 0;
  v9[1638] = 0;
  v9[1910] = 0;
  wlan_scan_unregister_requester(v10, v11, a2, a3, a4, a5, a6, a7, a8, a9);
  return 0;
}
