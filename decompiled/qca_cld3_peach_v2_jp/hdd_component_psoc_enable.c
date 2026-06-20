__int64 __fastcall hdd_component_psoc_enable(__int64 a1)
{
  disa_psoc_enable();
  nan_psoc_enable(a1);
  p2p_psoc_enable(a1);
  ucfg_interop_issues_ap_psoc_enable(a1);
  policy_mgr_psoc_enable(a1);
  ucfg_tdls_psoc_enable(a1);
  ucfg_fwol_psoc_enable(a1);
  ucfg_action_oui_psoc_enable(a1);
  return ucfg_ll_sap_psoc_enable(a1);
}
