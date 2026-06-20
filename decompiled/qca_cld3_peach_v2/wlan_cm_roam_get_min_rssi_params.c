__int64 __fastcall wlan_cm_roam_get_min_rssi_params(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    a2[5] = *(_QWORD *)(result + 6772);
    a2[6] = *(_QWORD *)(result + 6780);
    a2[7] = *(_QWORD *)(result + 6788);
  }
  return result;
}
