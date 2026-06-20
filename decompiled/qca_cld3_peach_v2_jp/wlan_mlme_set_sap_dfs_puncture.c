__int64 __fastcall wlan_mlme_set_sap_dfs_puncture(__int64 a1, char a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v4; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 4;
  v4 = psoc_ext_obj_fl;
  *(_BYTE *)(v4 + 3175) = a2 & 1;
  return 0;
}
