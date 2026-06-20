__int64 __fastcall ucfg_policy_mgr_acs_completed(__int64 a1, unsigned int a2)
{
  if ( (wlan_mlme_is_aux_emlsr_support(a1) & 1) != 0 )
    return ml_nlink_conn_change_notify(a1, a2, 25, 0);
  else
    return 0;
}
