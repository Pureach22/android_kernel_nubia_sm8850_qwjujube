__int64 __fastcall wlan_mlme_get_power_usage(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
    return psoc_ext_obj_fl + 4400;
  else
    return 0;
}
