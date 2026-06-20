__int64 __fastcall wlan_mlme_get_roaming_triggers(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
    return *(unsigned int *)(psoc_ext_obj_fl + 1744);
  else
    return 0x7FFFF;
}
