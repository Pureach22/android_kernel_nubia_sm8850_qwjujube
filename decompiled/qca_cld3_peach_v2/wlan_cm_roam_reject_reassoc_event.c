__int64 __fastcall wlan_cm_roam_reject_reassoc_event(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x0

  v11 = *(_QWORD *)(a1 + 80);
  if ( v11 )
    return cm_roam_reject_reassoc_event(v11, a2, a3);
  else
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: Invalid psoc",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wlan_cm_roam_reject_reassoc_event");
}
