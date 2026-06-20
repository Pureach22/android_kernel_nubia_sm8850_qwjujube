__int64 __fastcall ucfg_pmo_get_runtime_pm_delay(__int64 a1)
{
  __int64 result; // x0

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( result )
    return *(unsigned int *)(result + 56);
  return result;
}
