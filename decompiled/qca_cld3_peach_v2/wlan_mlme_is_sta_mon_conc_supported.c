__int64 __fastcall wlan_mlme_is_sta_mon_conc_supported(__int64 a1)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    return *(_DWORD *)(result + 1092) == 1;
  return result;
}
