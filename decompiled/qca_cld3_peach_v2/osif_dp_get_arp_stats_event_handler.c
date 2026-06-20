__int64 __fastcall osif_dp_get_arp_stats_event_handler(__int64 a1, unsigned int *a2)
{
  __int64 result; // x0
  __int64 v5; // x21

  result = ucfg_dp_get_arp_request_ctx(a1);
  if ( result )
  {
    result = osif_request_get(result);
    if ( result )
    {
      v5 = result;
      ucfg_dp_get_arp_stats_event_handler(a1, a2);
      osif_request_complete(v5);
      return osif_request_put(v5);
    }
  }
  return result;
}
