__int64 __fastcall rrm_start(
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
  _WORD *v9; // x19
  __int16 v10; // w8

  v9 = (_WORD *)(a1 + 0x4000);
  v10 = wlan_scan_register_requester(
          *(_QWORD *)(a1 + 21552),
          "RRM",
          (__int64)sme_rrm_scan_event_callback,
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9);
  v9[786] = v10;
  v9[1058] = v10;
  v9[1330] = v10;
  v9[1602] = v10;
  v9[1874] = v10;
  return 0;
}
