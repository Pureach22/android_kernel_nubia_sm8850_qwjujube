__int64 __fastcall hdd_component_psoc_disable(__int64 a1)
{
  ucfg_ll_sap_psoc_disable();
  ucfg_action_oui_psoc_disable(a1);
  ucfg_fwol_psoc_disable(a1);
  ucfg_tdls_psoc_disable(a1);
  policy_mgr_psoc_disable(a1);
  ucfg_interop_issues_ap_psoc_disable(a1);
  p2p_psoc_disable(a1);
  nan_psoc_disable(a1);
  return disa_psoc_disable(a1);
}
