__int64 __fastcall wlan_cm_get_6ghz_key_mgmt_mask(__int64 a1)
{
  __int64 cmpt_obj; // x0

  cmpt_obj = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( cmpt_obj )
    return *(unsigned int *)(cmpt_obj + 2052);
  else
    return 0xFFFFFFFFLL;
}
