__int64 __fastcall wlan_mlme_override_bmps_imps(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v2; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v2 = psoc_ext_obj_fl;
  *(_WORD *)(v2 + 5632) = 0;
  return 0;
}
