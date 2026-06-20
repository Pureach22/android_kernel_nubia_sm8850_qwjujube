__int64 __fastcall wlan_mlme_set_emlsr_mode_enabled(__int64 a1, char a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v4; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v4 = psoc_ext_obj_fl;
  *(_BYTE *)(v4 + 1120) = a2 & 1;
  return 0;
}
