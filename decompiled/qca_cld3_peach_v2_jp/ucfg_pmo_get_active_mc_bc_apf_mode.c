__int64 __fastcall ucfg_pmo_get_active_mc_bc_apf_mode(__int64 a1)
{
  return *(unsigned int *)(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 72);
}
