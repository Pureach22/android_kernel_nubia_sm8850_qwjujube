__int64 __fastcall ucfg_pmo_set_wow_enable(__int64 a1, int a2)
{
  __int64 result; // x0

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  *(_DWORD *)(result + 40) = a2;
  return result;
}
