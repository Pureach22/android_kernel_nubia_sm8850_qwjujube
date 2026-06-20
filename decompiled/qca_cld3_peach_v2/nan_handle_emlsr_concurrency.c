__int64 __fastcall nan_handle_emlsr_concurrency(__int64 a1, char a2)
{
  __int64 result; // x0

  if ( (policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr) & 1) == 0
    || (result = wlan_mlme_is_aux_emlsr_support(a1), (result & 1) == 0) )
  {
    if ( (a2 & 1) != 0 )
    {
      policy_mgr_wait_for_set_link_update(a1);
      wlan_handle_emlsr_sta_concurrency(a1, 1, 0);
      return policy_mgr_wait_for_set_link_update(a1);
    }
    else
    {
      return wlan_handle_emlsr_sta_concurrency(a1, 0, 1);
    }
  }
  return result;
}
