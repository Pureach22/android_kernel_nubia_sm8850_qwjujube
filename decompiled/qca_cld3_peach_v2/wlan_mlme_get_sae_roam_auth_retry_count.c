__int64 __fastcall wlan_mlme_get_sae_roam_auth_retry_count(__int64 a1, bool *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  bool v4; // w8
  __int16 v5; // w8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  v4 = psoc_ext_obj_fl;
  if ( psoc_ext_obj_fl )
  {
    v5 = *(_WORD *)(psoc_ext_obj_fl + 1084);
    result = 0;
    v4 = (v5 & 0x1C0) != 0;
  }
  else
  {
    result = 16;
  }
  *a2 = v4;
  return result;
}
