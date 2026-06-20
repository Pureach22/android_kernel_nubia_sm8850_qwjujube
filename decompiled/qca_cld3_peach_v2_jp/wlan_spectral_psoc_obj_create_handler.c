__int64 __fastcall wlan_spectral_psoc_obj_create_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *v10; // x2
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 *v20; // x0
  __int64 *v21; // x20

  if ( !a1 )
  {
    v10 = "%s: PSOC is NULL";
    goto LABEL_5;
  }
  if ( (unsigned int)wlan_spectral_init_psoc_feature_cap() )
  {
    v10 = "%s: Failed to initialize spectral pdev feature caps";
LABEL_5:
    qdf_trace_msg(0x56u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_spectral_psoc_obj_create_handler");
    return 16;
  }
  if ( (wlan_spectral_is_feature_disabled_psoc(a1) & 1) != 0 )
  {
    qdf_trace_msg(
      0x56u,
      4u,
      "%s: Spectral feature is disabled",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_spectral_psoc_obj_create_handler");
    return 39;
  }
  else
  {
    v20 = (__int64 *)_qdf_mem_malloc(0xF0u, "wlan_spectral_psoc_obj_create_handler", 559);
    if ( v20 )
    {
      v21 = v20;
      qdf_mem_set(v20, 0xF0u, 0);
      *v21 = a1;
      if ( *(_DWORD *)(a1 + 12) == 1 )
        spectral_ctx_init_ol(v21);
      wlan_objmgr_psoc_component_obj_attach(a1, 0x13u, (__int64)v21, 0);
      return 0;
    }
    else
    {
      return 2;
    }
  }
}
