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
  int v22; // w8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w8
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 result; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w20

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v11 = context;
    values = cfg_psoc_get_values(a1);
    v21 = (unsigned __int8)*(_DWORD *)(values + 2612);
    *(_BYTE *)(v11 + 2200) = *(_DWORD *)(values + 2612);
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
    *(_BYTE *)(v11 + 2201) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2616);
    v22 = *(_DWORD *)(cfg_psoc_get_values(a1) + 2620);
    *(_BYTE *)(v11 + 2202) = v22;
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: max_conc_cxns %d non-nan",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "policy_mgr_init_cfg",
      (unsigned __int8)v22);
    v31 = *(unsigned __int8 *)(v11 + 2202);
    if ( v31 >= 4 )
      LOBYTE(v31) = 4;
    *(_BYTE *)(v11 + 2202) = v31;
    *(_BYTE *)(v11 + 2203) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2636);
    *(_BYTE *)(v11 + 2204) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2640);
    *(_DWORD *)(v11 + 2236) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2696);
    *(_DWORD *)(v11 + 2220) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2624);
    *(_DWORD *)(v11 + 2224) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2628);
    *(_DWORD *)(v11 + 2228) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2632);
    *(_BYTE *)(v11 + 2205) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2644);
    *(_BYTE *)(v11 + 2218) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2648);
    *(_BYTE *)(v11 + 2206) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2688);
    *(_BYTE *)(v11 + 2207) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2652);
    *(_BYTE *)(v11 + 2240) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2656);
    *(_DWORD *)(v11 + 2208) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2668);
    *(_BYTE *)(v11 + 2212) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2660);
    *(_BYTE *)(v11 + 2214) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2664);
    if ( *(_BYTE *)(cfg_psoc_get_values(a1) + 9228) == 1 )
      *(_BYTE *)(v11 + 2214) = 1;
    if ( (*(_BYTE *)(cfg_psoc_get_values(a1) + 4997) & 1) == 0 )
      *(_BYTE *)(v11 + 2212) = 0;
    *(_BYTE *)(v11 + 2215) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2680);
    *(_BYTE *)(v11 + 2213) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2676);
    *(_BYTE *)(v11 + 2216) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2672);
    *(_BYTE *)(v11 + 2217) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2684);
    *(_BYTE *)(v11 + 2232) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2692);
    *(_BYTE *)(v11 + 2241) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2700);
    v32 = policy_mgr_get_context(a1);
    if ( v32 )
      *(_BYTE *)(v32 + 2242) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2701);
    else
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid Context",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "policy_mgr_init_same_mac_conc_sr_status");
    *(_BYTE *)(v11 + 2243) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2702);
    *(_BYTE *)(v11 + 2244) = *(_BYTE *)(cfg_psoc_get_values(a1) + 2703);
    result = policy_mgr_psoc_open(a1);
    if ( (_DWORD)result )
    {
      v58 = result;
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: psoc open fail",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "ucfg_policy_mgr_psoc_open");
      policy_mgr_psoc_close(a1);
      return v58;
    }
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: pm_ctx is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_init_cfg");
    qdf_trace_msg(0x4Fu, 2u, "%s: pm_ctx is NULL", v41, v42, v43, v44, v45, v46, v47, v48, "ucfg_policy_mgr_psoc_open");
    return 16;
  }
  return result;
}
