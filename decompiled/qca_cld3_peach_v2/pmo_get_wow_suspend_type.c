__int64 __fastcall pmo_get_wow_suspend_type(__int64 a1)
{
  return *(unsigned int *)(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 88);
}
