__int64 __fastcall wlan_cfg_soc_update_tgt_params(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = cfg_psoc_get_values(a2);
  *(_DWORD *)(a1 + 720) = *(_DWORD *)(result + 616);
  return result;
}
