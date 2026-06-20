__int64 __fastcall wlan_twt_get_feature_info(__int64 a1, _BYTE *a2)
{
  __int64 result; // x0

  result = wlan_twt_cfg_is_twt_enabled(a1);
  *a2 = result & 1;
  if ( (result & 1) != 0 )
  {
    wlan_twt_cfg_get_bcast_requestor(a1, a2 + 2);
    result = wlan_twt_cfg_get_requestor(a1, a2 + 1);
    a2[3] = 1;
  }
  return result;
}
