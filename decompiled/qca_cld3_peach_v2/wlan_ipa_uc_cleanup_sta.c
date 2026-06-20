__int64 __fastcall wlan_ipa_uc_cleanup_sta(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v13; // w22
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v13 = a3;
  qdf_trace_msg(0x61u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_ipa_uc_cleanup_sta");
  if ( a1 != -1064 && !*(_DWORD *)(a1 + 1096) && *(_QWORD *)(a1 + 1088) == a2 && *(unsigned __int8 *)(a1 + 1116) == v13 )
  {
    wlan_ipa_uc_send_evt(a2, 5, *(_QWORD *)(a2 + 1008), a1);
    wlan_ipa_cleanup_iface(a1 + 1064, 0);
  }
  if ( a1 != -1192 && !*(_DWORD *)(a1 + 1224) && *(_QWORD *)(a1 + 1216) == a2 && *(unsigned __int8 *)(a1 + 1244) == v13 )
  {
    wlan_ipa_uc_send_evt(a2, 5, *(_QWORD *)(a2 + 1008), a1);
    wlan_ipa_cleanup_iface(a1 + 1192, 0);
  }
  if ( a1 != -1320 && !*(_DWORD *)(a1 + 1352) && *(_QWORD *)(a1 + 1344) == a2 && *(unsigned __int8 *)(a1 + 1372) == v13 )
  {
    wlan_ipa_uc_send_evt(a2, 5, *(_QWORD *)(a2 + 1008), a1);
    wlan_ipa_cleanup_iface(a1 + 1320, 0);
  }
  return qdf_trace_msg(0x61u, 8u, "%s: exit", v14, v15, v16, v17, v18, v19, v20, v21, "wlan_ipa_uc_cleanup_sta");
}
