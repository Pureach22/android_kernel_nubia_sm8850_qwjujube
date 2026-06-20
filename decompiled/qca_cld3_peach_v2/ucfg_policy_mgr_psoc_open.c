__int64 __fastcall ucfg_policy_mgr_psoc_open(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  __int64 values; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w4
  char is_mlo_sta_nan_ndi_allowed; // w21
  __int64 v23; // x4
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 result; // x0
  unsigned int v42; // w8
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int v60; // w20

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v11 = context;
    values = cfg_psoc_get_values(a1);
    v21 = (unsigned __int8)*(_DWORD *)(values + 2688);
    *(_BYTE *)(v11 + 2200) = *(_DWORD *)(values + 2688);
    if ( (unsigned int)(v21 - 1) <= 1 )
    {
      qdf_trace_msg(
        0x4Fu,
        4u,
        "%s: User configured mcc_to_scc_switch: %d, overwrite it to: %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "policy_mgr_init_cfg");
      *(_BYTE *)(v11 + 2200) = 3;
    }
    *(_BYTE *)(v11 + 2201) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2692);
    is_mlo_sta_nan_ndi_allowed = wlan_is_mlo_sta_nan_ndi_allowed(a1);
    v23 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 2696);
    if ( (is_mlo_sta_nan_ndi_allowed & 1) != 0 )
    {
      v32 = "%s: max_conc_cxns %d nan";
      *(_BYTE *)(v11 + 2202) = v23 + 1;
      v23 = (unsigned __int8)(v23 + 1);
    }
    else
    {
      v32 = "%s: max_conc_cxns %d non-nan";
      *(_BYTE *)(v11 + 2202) = v23;
    }
    qdf_trace_msg(0x4Fu, 2u, v32, v24, v25, v26, v27, v28, v29, v30, v31, "policy_mgr_init_cfg", v23);
    v42 = *(unsigned __int8 *)(v11 + 2202);
    if ( v42 >= 4 )
      LOBYTE(v42) = 4;
    *(_BYTE *)(v11 + 2202) = v42;
    *(_BYTE *)(v11 + 2203) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2712);
    *(_BYTE *)(v11 + 2204) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2716);
    *(_DWORD *)(v11 + 2236) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2772);
    *(_DWORD *)(v11 + 2220) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2700);
    *(_DWORD *)(v11 + 2224) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2704);
    *(_DWORD *)(v11 + 2228) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2708);
    *(_BYTE *)(v11 + 2205) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2720);
    *(_BYTE *)(v11 + 2218) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2724);
    *(_BYTE *)(v11 + 2206) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2764);
    *(_BYTE *)(v11 + 2207) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2728);
    *(_BYTE *)(v11 + 2240) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2732);
    *(_DWORD *)(v11 + 2208) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2744);
    *(_BYTE *)(v11 + 2212) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2736);
    *(_BYTE *)(v11 + 2214) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2740);
    if ( *(_BYTE *)(cfg_psoc_get_values(a1) + 9320) == 1 )
      *(_BYTE *)(v11 + 2214) = 1;
    if ( (*(_BYTE *)(cfg_psoc_get_values(a1) + 5081) & 1) == 0 )
      *(_BYTE *)(v11 + 2212) = 0;
    *(_BYTE *)(v11 + 2215) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2756);
    *(_BYTE *)(v11 + 2213) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2752);
    *(_BYTE *)(v11 + 2216) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2748);
    *(_BYTE *)(v11 + 2217) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2760);
    *(_BYTE *)(v11 + 2232) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2768);
    *(_BYTE *)(v11 + 2241) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2776);
    v43 = policy_mgr_get_context(a1);
    if ( v43 )
      *(_BYTE *)(v43 + 2242) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2777);
    else
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid Context",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "policy_mgr_init_same_mac_conc_sr_status");
    *(_BYTE *)(v11 + 2243) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2778);
    *(_BYTE *)(v11 + 2244) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2779);
    result = policy_mgr_psoc_open(a1);
    if ( (_DWORD)result )
    {
      v60 = result;
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: psoc open fail",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "ucfg_policy_mgr_psoc_open");
      policy_mgr_psoc_close(a1);
      return v60;
    }
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: pm_ctx is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_init_cfg");
    qdf_trace_msg(0x4Fu, 2u, "%s: pm_ctx is NULL", v33, v34, v35, v36, v37, v38, v39, v40, "ucfg_policy_mgr_psoc_open");
    return 16;
  }
  return result;
}
