__int64 __fastcall wlan_mlme_get_ts_info_ack_policy(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  int v4; // w8

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    v4 = *(_DWORD *)(result + 5472);
  else
    v4 = 0;
  *a2 = v4;
  return result;
}
