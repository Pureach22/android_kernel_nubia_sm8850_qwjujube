__int64 __fastcall wlan_mlme_convert_ap_policy_config(__int64 result)
{
  if ( (unsigned int)(result - 1) >= 3 )
    return 0;
  else
    return (unsigned int)result;
}
