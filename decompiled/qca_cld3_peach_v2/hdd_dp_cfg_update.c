__int64 __fastcall hdd_dp_cfg_update(__int64 a1, __int64 a2)
{
  _DWORD *v2; // x20
  __int64 result; // x0

  v2 = *(_DWORD **)(a2 + 104);
  v2[14] = *(_DWORD *)(cfg_psoc_get_values(a1) + 4024);
  v2[34] = *(_DWORD *)(cfg_psoc_get_values(a1) + 4028);
  v2[12] = *(_DWORD *)(cfg_psoc_get_values(a1) + 4032);
  result = cfg_psoc_get_values(a1);
  v2[13] = *(_DWORD *)(result + 4036);
  return result;
}
