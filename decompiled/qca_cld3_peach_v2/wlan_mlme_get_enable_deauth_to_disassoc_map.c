__int64 __fastcall wlan_mlme_get_enable_deauth_to_disassoc_map(__int64 a1, _BYTE *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v4; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 4;
  v4 = psoc_ext_obj_fl;
  *a2 = *(_BYTE *)(v4 + 1063);
  return 0;
}
