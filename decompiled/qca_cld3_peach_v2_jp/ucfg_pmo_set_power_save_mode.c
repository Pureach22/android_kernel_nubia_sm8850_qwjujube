__int64 __fastcall ucfg_pmo_set_power_save_mode(__int64 a1, int a2)
{
  __int64 result; // x0

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  *(_DWORD *)(result + 44) = a2;
  return result;
}
