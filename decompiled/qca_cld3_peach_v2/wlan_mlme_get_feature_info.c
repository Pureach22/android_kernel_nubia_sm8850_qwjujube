__int64 __fastcall wlan_mlme_get_feature_info(__int64 a1, __int64 a2)
{
  __int64 psoc_ext_obj_fl; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x0
  char v14; // w8
  __int64 v15; // x0
  int v16; // w21
  __int64 v17; // x0
  char v18; // w8
  __int64 v19; // x0
  char v20; // w8
  __int64 v21; // x0
  char v22; // w8
  int v23; // w21
  __int64 values; // x0
  int v25; // w8
  int v26; // w21
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
    *(_BYTE *)a2 = *(_BYTE *)(psoc_ext_obj_fl + 5900);
  else
    qdf_trace_msg(0x1Fu, 2u, "%s: mlme obj null", v5, v6, v7, v8, v9, v10, v11, v12, "wlan_mlme_get_latency_enable");
  v13 = mlme_get_psoc_ext_obj_fl(a1);
  if ( v13 )
    v14 = *(_BYTE *)(v13 + 3416);
  else
    v14 = 0;
  *(_BYTE *)(a2 + 1) = v14;
  *(_DWORD *)(a2 + 16) = 9;
  v15 = mlme_get_psoc_ext_obj_fl(a1);
  if ( v15 )
    v16 = *(_DWORD *)(v15 + 1744);
  else
    v16 = 0x7FFFF;
  v17 = mlme_get_psoc_ext_obj_fl(a1);
  if ( v17 )
    v18 = *(_BYTE *)(v17 + 2104);
  else
    v18 = 0;
  *(_BYTE *)(a2 + 3) = (v16 & 0x200) != 0;
  *(_BYTE *)(a2 + 2) = v18 & ((unsigned __int16)(v16 & 0x1000) >> 12);
  *(_BYTE *)(a2 + 4) = (v16 & 0x400) != 0;
  v19 = mlme_get_psoc_ext_obj_fl(a1);
  if ( v19 )
    v20 = *(_BYTE *)(v19 + 1719);
  else
    v20 = 0;
  *(_BYTE *)(a2 + 6) = (v16 & 0x20000) != 0;
  *(_BYTE *)(a2 + 7) = (v16 & 0x80000) != 0;
  *(_BYTE *)(a2 + 5) = v20 & ((unsigned __int16)(v16 & 0x4000) >> 14);
  *(_WORD *)(a2 + 8) = 257;
  v21 = mlme_get_psoc_ext_obj_fl(a1);
  if ( v21 )
    v22 = *(_BYTE *)(v21 + 1978);
  else
    v22 = 0;
  *(_BYTE *)(a2 + 10) = v22;
  *(_BYTE *)(a2 + 13) = 1;
  *(_DWORD *)(a2 + 20) = 4;
  *(_WORD *)(a2 + 11) = 257;
  *(_DWORD *)(a2 + 28) = 15;
  if ( (*(_BYTE *)(cfg_psoc_get_values(a1) + 3994) & 1) == 0 )
    *(_DWORD *)(a2 + 28) |= 0x10u;
  v23 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 3994);
  values = cfg_psoc_get_values(a1);
  if ( v23 == 1 && (*(_BYTE *)(values + 3997) & 1) == 0 )
    v25 = *(_DWORD *)(a2 + 28);
  else
    v25 = *(_DWORD *)(a2 + 28) | 0x20;
  *(_DWORD *)(a2 + 28) = v25 | 0x300;
  v26 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 3994);
  v27 = cfg_psoc_get_values(a1);
  if ( v26 != 1 || *(_BYTE *)(v27 + 3997) == 1 )
    *(_DWORD *)(a2 + 28) |= 0x800u;
  if ( (*(_BYTE *)(cfg_psoc_get_values(a1) + 3994) & 1) == 0 )
    *(_DWORD *)(a2 + 28) |= 0x2000u;
  if ( *(_BYTE *)(cfg_psoc_get_values(a1) + 3993) == 1 )
    *(_DWORD *)(a2 + 28) |= 0x40u;
  if ( *(_BYTE *)(cfg_psoc_get_values(a1) + 3995) == 1 )
    *(_DWORD *)(a2 + 28) |= 0x80u;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: iface combinations = %x",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "wlan_mlme_set_iface_combinations");
  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    *(_BYTE *)(a2 + 24) = *(_BYTE *)(result + 2871);
  return result;
}
