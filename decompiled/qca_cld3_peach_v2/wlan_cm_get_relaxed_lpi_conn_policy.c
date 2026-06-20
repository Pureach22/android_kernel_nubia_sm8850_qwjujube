__int64 __fastcall wlan_cm_get_relaxed_lpi_conn_policy(__int64 a1)
{
  __int64 result; // x0

  result = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( result )
    return (*(unsigned __int8 *)(result + 2048) >> 5) & 1;
  return result;
}
