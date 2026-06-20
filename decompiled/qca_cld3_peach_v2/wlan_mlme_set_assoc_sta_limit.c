__int64 __fastcall wlan_mlme_set_assoc_sta_limit(__int64 a1, unsigned int a2)
{
  __int64 psoc_ext_obj_fl; // x8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  result = 16;
  if ( a2 - 1 <= 0x3F && psoc_ext_obj_fl && *(unsigned __int8 *)(psoc_ext_obj_fl + 3416) >= a2 )
  {
    *(_BYTE *)(psoc_ext_obj_fl + 3407) = a2;
    return 0;
  }
  return result;
}
