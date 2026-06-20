__int64 __fastcall ucfg_pmo_set_igmp_offload_enabled(__int64 a1, char a2)
{
  __int64 result; // x0

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  *(_BYTE *)(result + 96) = a2;
  return result;
}
