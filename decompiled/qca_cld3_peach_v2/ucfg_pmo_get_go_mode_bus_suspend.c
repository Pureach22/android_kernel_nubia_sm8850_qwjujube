__int64 __fastcall ucfg_pmo_get_go_mode_bus_suspend(__int64 a1)
{
  return *(unsigned __int8 *)(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 84);
}
