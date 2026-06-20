__int64 __fastcall mlme_mlo_is_reconfig_reassoc_enable(__int64 result)
{
  if ( result )
  {
    result = wlan_psoc_mlme_get_cmpt_obj(result);
    if ( result )
      return *(_BYTE *)(result + 2020) != 0;
  }
  return result;
}
