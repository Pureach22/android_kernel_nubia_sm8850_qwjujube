__int64 __fastcall wlan_cm_roam_get_roam_score_algo(
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
  __int64 v9; // x0
  __int64 result; // x0

  v9 = *(_QWORD *)(a1 + 80);
  if ( v9 )
  {
    result = wlan_psoc_mlme_get_cmpt_obj(v9);
    if ( result )
      return (*(unsigned __int8 *)(result + 2000) >> 2) & 1;
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: Invalid psoc", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cm_roam_get_roam_score_algo");
    return 0;
  }
  return result;
}
