__int64 __fastcall cm_roam_mlo_config(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x4

  *(_BYTE *)(a3 + 4964) = *(_BYTE *)(a2 + 168);
  *(_DWORD *)(a3 + 4972) = (unsigned __int8)wlan_mlme_get_sta_mlo_conn_max_num(a1);
  *(_DWORD *)(a3 + 4976) = (unsigned __int8)wlan_mlme_get_sta_mlo_conn_band_bmp(a1);
  *(_DWORD *)(a3 + 4980) = wlan_mlme_is_5gl_5gh_mlsr_supported(a1) & 1;
  result = wlan_cm_get_rso_config_fl(a2, "cm_roam_mlo_config", 3501);
  if ( result )
  {
    v15 = *(unsigned int *)(a3 + 4972);
    *(_DWORD *)(a3 + 4976) &= *(_DWORD *)(result + 944);
    return qdf_trace_msg(
             0x68u,
             8u,
             "%s: max num links: %d",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "cm_roam_mlo_config",
             v15);
  }
  return result;
}
