__int64 __fastcall wlan_cm_free_connect_req_param(__int64 result)
{
  if ( result )
    return cm_free_connect_req_param(result);
  return result;
}
