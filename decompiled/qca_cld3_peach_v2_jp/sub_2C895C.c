__int64 __fastcall sub_2C895C(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x30

  if ( v3 )
    JUMPOUT(0x30D114);
  return wlan_cm_sta_mlme_vdev_roam_notify(a1, a2, a3);
}
