__int64 __fastcall wlan_mlme_get_status_ring_buffer(__int64 a1, char *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  char v4; // w8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    v4 = *(_BYTE *)(psoc_ext_obj_fl + 1076);
    result = 0;
  }
  else
  {
    result = 16;
    v4 = 1;
  }
  *a2 = v4;
  return result;
}
