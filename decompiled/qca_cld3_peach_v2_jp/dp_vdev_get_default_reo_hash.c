__int64 __fastcall dp_vdev_get_default_reo_hash(__int64 a1, _DWORD *a2, _BYTE *a3)
{
  __int64 v3; // x21
  __int64 v6; // x22
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 24);
  v6 = *(_QWORD *)(v3 + 8);
  result = wlan_cfg_get_dp_pdev_nss_enabled(*(_QWORD *)(v3 + 288));
  if ( !(_DWORD)result )
  {
    result = wlan_cfg_is_rx_hash_enabled(*(_QWORD *)(v6 + 40));
    *a3 = result & 1;
  }
  *a2 = *(_DWORD *)(v3 + 95028);
  return result;
}
