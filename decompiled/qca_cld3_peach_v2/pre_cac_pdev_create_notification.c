__int64 __fastcall pre_cac_pdev_create_notification(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v2 = _qdf_mem_malloc(0xF0u, "pre_cac_pdev_create_notification", 556);
  if ( !v2 )
    return 2;
  v11 = v2;
  v12 = wlan_objmgr_pdev_component_obj_attach(a1, 0x2Du, v2, 0, v3, v4, v5, v6, v7, v8, v9, v10);
  if ( v12 )
  {
    v21 = v12;
    qdf_trace_msg(
      0x98u,
      2u,
      "%s: Failed to attach pdev component obj",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "pre_cac_pdev_create_notification");
    _qdf_mem_free(v11);
    return v21;
  }
  else
  {
    *(_QWORD *)v11 = a1;
    v23 = *(_QWORD *)(a1 + 80);
    if ( v23 )
    {
      *(_BYTE *)(v11 + 16) = *(_BYTE *)(cfg_psoc_get_values(v23) + 32612);
      qdf_trace_msg(0x98u, 8u, "%s: DNW enable %d", v24, v25, v26, v27, v28, v29, v30, v31, "dnw_cfg_init");
    }
    else
    {
      qdf_trace_msg(0x98u, 2u, "%s: null psoc", v13, v14, v15, v16, v17, v18, v19, v20, "dnw_cfg_init");
    }
    return 0;
  }
}
