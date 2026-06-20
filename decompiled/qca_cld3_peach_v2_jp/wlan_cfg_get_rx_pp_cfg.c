__int64 __fastcall wlan_cfg_get_rx_pp_cfg(__int64 a1, _BYTE *a2, _QWORD *a3)
{
  __int64 result; // x0

  *a2 = *(_BYTE *)(cfg_psoc_get_values(a1) + 757);
  result = cfg_psoc_get_values(a1);
  *a3 = *(unsigned int *)(result + 748);
  return result;
}
