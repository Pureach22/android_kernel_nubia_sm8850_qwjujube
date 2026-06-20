__int64 __fastcall ucfg_mlme_get_ap_random_bssid_enable(__int64 a1, _BYTE *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v4; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 4;
  v4 = psoc_ext_obj_fl;
  *a2 = *(_BYTE *)(v4 + 3229);
  return 0;
}
