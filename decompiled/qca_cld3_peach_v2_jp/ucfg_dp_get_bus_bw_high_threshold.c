__int64 __fastcall ucfg_dp_get_bus_bw_high_threshold(__int64 a1)
{
  __int64 result; // x0

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( result )
    return *(unsigned int *)(result + 76);
  return result;
}
