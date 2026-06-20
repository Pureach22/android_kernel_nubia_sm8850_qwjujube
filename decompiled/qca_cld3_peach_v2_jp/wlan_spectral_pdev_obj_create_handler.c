__int64 __fastcall wlan_spectral_pdev_obj_create_handler(
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
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _QWORD *v29; // x20
  __int64 v30; // x0
  __int64 comp_private_obj; // x0
  __int64 v32; // x21
  __int64 (__fastcall *v33)(_QWORD); // x8
  __int64 v34; // x0
  const char *v35; // x2

  if ( !a1 )
  {
    v10 = "%s: PDEV is NULL";
    goto LABEL_5;
  }
  if ( !(unsigned int)wlan_spectral_init_pdev_feature_caps() )
  {
    if ( (wlan_spectral_is_feature_disabled_pdev(a1) & 1) != 0 )
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
        "wlan_spectral_pdev_obj_create_handler");
      return 39;
    }
    v20 = _qdf_mem_malloc(0x38u, "wlan_spectral_pdev_obj_create_handler", 628);
    if ( !v20 )
      return 2;
    v29 = (_QWORD *)v20;
    v30 = *(_QWORD *)(a1 + 80);
    if ( v30 && (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v30, 0x13u)) != 0 )
    {
      v32 = comp_private_obj;
      qdf_mem_set(v29, 0x38u, 0);
      *v29 = a1;
      v33 = *(__int64 (__fastcall **)(_QWORD))(v32 + 64);
      if ( !v33 )
      {
LABEL_18:
        wlan_objmgr_pdev_component_obj_attach(a1, 0x13u, (__int64)v29, 0, v21, v22, v23, v24, v25, v26, v27, v28);
        return 0;
      }
      if ( *((_DWORD *)v33 - 1) != 1565325861 )
        __break(0x8228u);
      v34 = v33(a1);
      if ( v34 )
      {
        v29[2] = v34;
        goto LABEL_18;
      }
      v35 = "%s: Spectral lmac object is NULL!";
    }
    else
    {
      v35 = "%s: Spectral context is NULL!";
    }
    qdf_trace_msg(0x56u, 2u, v35, v21, v22, v23, v24, v25, v26, v27, v28, "wlan_spectral_pdev_obj_create_handler");
    _qdf_mem_free((__int64)v29);
    return 16;
  }
  v10 = "%s: Failed to initialize spectral pdev feature caps";
LABEL_5:
  qdf_trace_msg(0x56u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_spectral_pdev_obj_create_handler");
  return 16;
}
