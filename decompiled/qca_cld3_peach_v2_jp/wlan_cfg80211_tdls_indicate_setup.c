__int64 __fastcall wlan_cfg80211_tdls_indicate_setup(
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
  __int64 v9; // x19
  __int64 v10; // x20

  v9 = a1 + 10;
  v10 = *(_QWORD *)(*(_QWORD *)a1 + 608LL);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Indication to request TDLS setup",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_cfg80211_tdls_indicate_setup");
  return cfg80211_tdls_oper_request(*(_QWORD *)(*(_QWORD *)v10 + 32LL), v9, 1, 0, 3264);
}
