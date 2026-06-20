__int64 __fastcall wlan_mlme_get_num_max_sap_bss(
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
  __int64 v9; // x29
  __int64 v10; // x30

  if ( a1 && *(_QWORD *)(a1 + 2800) )
    return 0;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: target psoc info is NULL",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_mlme_get_num_max_sap_bss",
    v9,
    v10);
  return 16;
}
