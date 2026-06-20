__int64 __fastcall policy_mgr_get_context(__int64 a1)
{
  return wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
}
