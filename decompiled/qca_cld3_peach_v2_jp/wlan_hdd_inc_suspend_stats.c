__int64 __fastcall wlan_hdd_inc_suspend_stats(
        unsigned int *a1,
        unsigned int a2,
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
  unsigned int v21; // [xsp+0h] [xbp-10h]
  __int64 v22; // [xsp+0h] [xbp-10h]

  v21 = a1[413];
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: ipa:%d, radar:%d, roam:%d, scan:%d, initial_wakeup:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_hdd_print_suspend_fail_stats",
    a1[409],
    a1[410],
    a1[411],
    a1[412],
    v21);
  if ( a2 >= 6 )
  {
    __break(0x5512u);
    JUMPOUT(0x35224C);
  }
  ++a1[a2 + 409];
  LODWORD(v22) = a1[413];
  return qdf_trace_msg(
           0x33u,
           2u,
           "%s: ipa:%d, radar:%d, roam:%d, scan:%d, initial_wakeup:%d",
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           "wlan_hdd_print_suspend_fail_stats",
           a1[409],
           a1[410],
           a1[411],
           a1[412],
           v22);
}
