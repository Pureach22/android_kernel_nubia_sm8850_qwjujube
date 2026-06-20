__int64 __fastcall wlan_mlme_get_listen_interval(__int64 a1, _DWORD *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v4; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v4 = psoc_ext_obj_fl;
  *a2 = *(unsigned __int16 *)(v4 + 3204);
  return 0;
}
