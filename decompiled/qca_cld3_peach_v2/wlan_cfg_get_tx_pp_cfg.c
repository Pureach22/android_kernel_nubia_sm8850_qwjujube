__int64 __fastcall wlan_cfg_get_tx_pp_cfg(__int64 a1, _BYTE *a2)
{
  __int64 result; // x0

  result = cfg_psoc_get_values(a1);
  *a2 = *(_BYTE *)(result + 763);
  return result;
}
