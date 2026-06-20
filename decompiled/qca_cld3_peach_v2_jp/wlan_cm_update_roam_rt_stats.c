__int64 __fastcall wlan_cm_update_roam_rt_stats(__int64 a1, char a2, int a3)
{
  __int64 psoc_ext_obj_fl; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    v14 = psoc_ext_obj_fl;
    if ( a3 == 1 )
    {
      *(_BYTE *)(psoc_ext_obj_fl + 1509) = a2;
      return 0;
    }
    else
    {
      result = 0;
      if ( !a3 )
        *(_BYTE *)(v14 + 1508) = a2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: Failed to get MLME Obj",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_cm_update_roam_rt_stats");
    return 16;
  }
  return result;
}
