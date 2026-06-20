__int64 __fastcall mlme_max_chan_switch_is_set(__int64 result)
{
  if ( result )
  {
    result = wlan_psoc_mlme_get_cmpt_obj(result);
    if ( result )
      return HIBYTE(*(unsigned __int16 *)(result + 2018)) & 1;
  }
  return result;
}
