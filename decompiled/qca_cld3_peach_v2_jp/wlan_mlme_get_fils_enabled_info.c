__int64 __fastcall wlan_mlme_get_fils_enabled_info(__int64 a1, _BYTE *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v5; // x8
  __int64 result; // x0
  _BYTE *v7; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    v5 = psoc_ext_obj_fl;
    result = 0;
    v7 = (_BYTE *)(v5 + 3455);
  }
  else
  {
    v7 = (_BYTE *)(cfg_psoc_get_values(a1) + 8540);
    result = 16;
  }
  *a2 = *v7;
  return result;
}
