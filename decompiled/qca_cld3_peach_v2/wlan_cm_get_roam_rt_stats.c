__int64 __fastcall wlan_cm_get_roam_rt_stats(__int64 a1, int a2)
{
  __int64 psoc_ext_obj_fl; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    if ( a2 == 1 )
    {
      return *(unsigned __int8 *)(psoc_ext_obj_fl + 1713);
    }
    else if ( a2 )
    {
      return 0;
    }
    else
    {
      return *(unsigned __int8 *)(psoc_ext_obj_fl + 1712);
    }
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: Failed to get MLME Obj",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_cm_get_roam_rt_stats");
    return 16;
  }
}
