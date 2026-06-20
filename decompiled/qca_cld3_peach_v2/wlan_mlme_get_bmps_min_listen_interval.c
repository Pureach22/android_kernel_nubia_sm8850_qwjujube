__int64 __fastcall wlan_mlme_get_bmps_min_listen_interval(__int64 a1, int *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  int v4; // w8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    v4 = *(_DWORD *)(psoc_ext_obj_fl + 5640);
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
