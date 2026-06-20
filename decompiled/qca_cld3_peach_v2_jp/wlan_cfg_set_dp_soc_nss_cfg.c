_DWORD *__fastcall wlan_cfg_set_dp_soc_nss_cfg(_DWORD *result, int a2)
{
  result[138] = a2;
  if ( a2 )
    result[35] = result[37];
  return result;
}
