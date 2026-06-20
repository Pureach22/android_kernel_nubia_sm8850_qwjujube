__int64 __fastcall wlan_tdls_get_features_info(__int64 a1, _BYTE *a2)
{
  __int64 result; // x0

  result = cfg_tdls_get_support_enable();
  if ( *a2 == 1 )
  {
    cfg_tdls_get_off_channel_enable(a1, a2 + 1);
    result = cfg_tdls_get_max_peer_count(a1);
    a2[2] = result;
    a2[3] = 1;
  }
  return result;
}
