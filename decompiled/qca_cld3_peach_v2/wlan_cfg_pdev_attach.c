__int64 __fastcall wlan_cfg_pdev_attach(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _DWORD *v11; // x20
  __int64 values; // x8

  result = _qdf_mem_malloc(0x28u, "wlan_cfg_pdev_attach", 4988);
  if ( result )
  {
    v11 = (_DWORD *)result;
    wlan_minidump_log(v3, v4, v5, v6, v7, v8, v9, v10, result, 40, a1);
    *v11 = *(_DWORD *)(cfg_psoc_get_values(a1) + 492);
    v11[1] = *(_DWORD *)(cfg_psoc_get_values(a1) + 536);
    v11[2] = *(_DWORD *)(cfg_psoc_get_values(a1) + 540);
    v11[3] = *(_DWORD *)(cfg_psoc_get_values(a1) + 672);
    v11[4] = *(_DWORD *)(cfg_psoc_get_values(a1) + 544);
    v11[5] = *(_DWORD *)(cfg_psoc_get_values(a1) + 548);
    v11[6] = 2;
    values = cfg_psoc_get_values(a1);
    v11[9] = *(_DWORD *)(values + 724);
    return (__int64)v11;
  }
  return result;
}
