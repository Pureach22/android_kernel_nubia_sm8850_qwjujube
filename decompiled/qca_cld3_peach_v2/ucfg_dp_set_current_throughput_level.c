__int64 __fastcall ucfg_dp_set_current_throughput_level(__int64 a1, int a2)
{
  __int64 result; // x0

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  *(_DWORD *)(result + 1024) = a2;
  return result;
}
