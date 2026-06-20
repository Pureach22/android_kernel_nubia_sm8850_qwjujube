__int64 __fastcall wlan_mlme_set_ft_over_ds(__int64 a1, char a2)
{
  __int64 psoc_ext_obj_fl; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  *(_BYTE *)(psoc_ext_obj_fl + 2756) = a2 != 0;
  return 0;
}
