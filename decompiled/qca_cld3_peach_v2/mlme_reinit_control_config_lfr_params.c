__int64 __fastcall mlme_reinit_control_config_lfr_params(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  *(_DWORD *)(a2 + 272) = *(_DWORD *)(cfg_psoc_get_values(a1) + 8320);
  result = cfg_psoc_get_values(a1);
  *(_BYTE *)(a2 + 86) = *(_BYTE *)(result + 7868);
  return result;
}
