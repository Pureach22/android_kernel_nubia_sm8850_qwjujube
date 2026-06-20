__int64 __fastcall sub_2FCFFC(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x30

  if ( v3 )
    JUMPOUT(0x3417B4);
  return wlan_cm_sta_mlme_vdev_roam_notify(a1, a2, a3);
}
