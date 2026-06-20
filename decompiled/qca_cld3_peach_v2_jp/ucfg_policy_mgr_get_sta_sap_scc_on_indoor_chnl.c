__int64 __fastcall ucfg_policy_mgr_get_sta_sap_scc_on_indoor_chnl(__int64 a1)
{
  return policy_mgr_get_sta_sap_scc_allowed_on_indoor_chnl(a1) & 1;
}
