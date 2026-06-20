__int64 __fastcall wlan_cm_set_exclude_rm_partial_scan_freq(__int64 a1, char a2)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    *(_BYTE *)(result + 2558) = a2;
  return result;
}
