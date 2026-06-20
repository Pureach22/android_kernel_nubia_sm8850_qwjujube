__int64 __fastcall wlan_mlme_is_channel_valid(__int64 a1, unsigned int a2)
{
  __int64 psoc_ext_obj_fl; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
    LOBYTE(psoc_ext_obj_fl) = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_roam_is_channel_valid)(
                                psoc_ext_obj_fl + 5756,
                                a2);
  return psoc_ext_obj_fl & 1;
}
