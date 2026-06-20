__int64 __fastcall cm_roam_get_roam_score_algo(__int64 a1)
{
  __int64 result; // x0

  result = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( result )
    return (*(unsigned __int8 *)(result + 2048) >> 2) & 1;
  return result;
}
