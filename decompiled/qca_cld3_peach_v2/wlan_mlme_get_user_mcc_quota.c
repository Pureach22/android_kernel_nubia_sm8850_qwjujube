__int64 __fastcall wlan_mlme_get_user_mcc_quota(__int64 a1, __int64 a2)
{
  __int64 psoc_ext_obj_fl; // x0

  if ( !a2 )
    return 29;
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  *(_BYTE *)(a2 + 4) = *(_BYTE *)(psoc_ext_obj_fl + 1140);
  *(_DWORD *)a2 = *(_DWORD *)(psoc_ext_obj_fl + 1136);
  *(_BYTE *)(a2 + 5) = *(_BYTE *)(psoc_ext_obj_fl + 1141);
  return 0;
}
