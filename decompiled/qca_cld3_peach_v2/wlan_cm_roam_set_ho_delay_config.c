__int64 __fastcall wlan_cm_roam_set_ho_delay_config(__int64 a1, __int16 a2)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    *(_WORD *)(result + 2760) = a2;
  return result;
}
