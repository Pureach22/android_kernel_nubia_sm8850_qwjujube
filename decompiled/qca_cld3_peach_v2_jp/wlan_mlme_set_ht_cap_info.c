__int64 __fastcall wlan_mlme_set_ht_cap_info(__int64 a1, __int16 a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v4; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v4 = psoc_ext_obj_fl;
  *(_WORD *)(v4 + 1268) = a2;
  return 0;
}
