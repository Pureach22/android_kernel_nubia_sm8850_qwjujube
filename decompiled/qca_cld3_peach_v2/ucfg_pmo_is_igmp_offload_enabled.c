__int64 __fastcall ucfg_pmo_is_igmp_offload_enabled(__int64 a1)
{
  return *(unsigned __int8 *)(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 96);
}
