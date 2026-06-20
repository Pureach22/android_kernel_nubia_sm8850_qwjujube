__int64 __fastcall wlan_mlme_get_model_name(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 psoc_ext_obj_fl; // x0
  int v6; // w8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v6 = sized_strscpy(a2, psoc_ext_obj_fl + 3072, (unsigned int)*a3);
  *a3 = v6;
  return 0;
}
