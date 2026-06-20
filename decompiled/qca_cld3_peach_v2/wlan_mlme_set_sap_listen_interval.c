__int64 __fastcall wlan_mlme_set_sap_listen_interval(__int64 a1, unsigned int a2)
{
  __int64 psoc_ext_obj_fl; // x8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  result = 16;
  if ( !HIWORD(a2) )
  {
    if ( psoc_ext_obj_fl )
    {
      *(_WORD *)(psoc_ext_obj_fl + 3404) = a2;
      return 0;
    }
  }
  return result;
}
