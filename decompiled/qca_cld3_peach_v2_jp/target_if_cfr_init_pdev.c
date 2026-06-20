__int64 __fastcall target_if_cfr_init_pdev(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 (*v12)(void); // x8
  unsigned int v14; // w0
  int v15; // w24
  __int64 comp_private_obj; // x0
  __int64 v17; // x19
  __int64 v18; // x0
  __int64 v19; // x22
  __int64 pdev_wmi_handle; // x0
  __int64 v21; // x23
  const char *v22; // x2
  const char *v23; // x3
  unsigned int v24; // w1
  __int64 result; // x0
  const char *v26; // x2
  char v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  char v36; // w8

  if ( !a1 || (v10 = *(_QWORD *)(a1 + 2128)) == 0 )
  {
    qdf_trace_msg(0x6Au, 2u, "%s: tx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cfr_get_target_type");
LABEL_15:
    v22 = "%s: unsupported chip";
    v23 = "target_if_cfr_init_pdev";
    goto LABEL_16;
  }
  v12 = *(__int64 (**)(void))(v10 + 1736);
  if ( !v12 )
    goto LABEL_15;
  if ( *((_DWORD *)v12 - 1) != 1468042957 )
    __break(0x8228u);
  v14 = v12();
  if ( v14 > 0x2B )
    goto LABEL_15;
  if ( ((1LL << v14) & 0xD6498000000LL) == 0 )
  {
    if ( v14 == 19 )
      return 0;
    goto LABEL_15;
  }
  if ( !a2 )
  {
    v26 = "%s: null pdev or psoc";
LABEL_26:
    qdf_trace_msg(0x6Au, 2u, v26, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cfr_init_target");
    return 16;
  }
  v15 = v14;
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a2, 0x1Eu);
  if ( !comp_private_obj )
  {
    v26 = "%s: null pdev cfr";
    goto LABEL_26;
  }
  v17 = comp_private_obj;
  v18 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Eu);
  if ( !v18 )
  {
    v26 = "%s: null psoc cfr";
    goto LABEL_26;
  }
  v19 = v18;
  pdev_wmi_handle = lmac_get_pdev_wmi_handle(a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_wmi_handle )
  {
    v26 = "%s: null wmi handle";
    goto LABEL_26;
  }
  v21 = pdev_wmi_handle;
  if ( (wlan_cfr_is_feature_disabled(a2) & 1) != 0 )
  {
    *(_BYTE *)(v17 + 8) = 0;
    v22 = "%s: cfr disabled";
    *(_BYTE *)(v19 + 8) = 0;
    v23 = "target_if_cfr_init_target";
LABEL_16:
    v24 = 4;
LABEL_17:
    qdf_trace_msg(0x6Au, v24, v22, a3, a4, a5, a6, a7, a8, a9, a10, v23);
    return 0;
  }
  v27 = wmi_service_enabled(v21, 0xAFu, a3, a4, a5, a6, a7, a8, a9, a10);
  *(_BYTE *)(v17 + 8) = v27 & 1;
  *(_BYTE *)(v19 + 8) = v27 & 1;
  if ( (v27 & 1) == 0 )
  {
    v22 = "%s: FW doesn't support CFR";
    v23 = "target_if_cfr_init_target";
    v24 = 2;
    goto LABEL_17;
  }
  *(_BYTE *)(v19 + 9) = wmi_service_enabled(v21, 0x120u, a3, a4, a5, a6, a7, a8, a9, a10) & 1;
  qdf_trace_msg(
    0x6Au,
    8u,
    "%s: is_cfr_pdev_id_soc %d",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "target_if_cfr_init_target");
  result = cfr_enh_init_pdev(a1, a2);
  if ( v15 <= 36 )
  {
    if ( v15 > 30 )
    {
      if ( v15 == 31 )
      {
        v36 = 33;
        goto LABEL_50;
      }
      if ( v15 == 34 )
      {
        v36 = 34;
        goto LABEL_50;
      }
    }
    else
    {
      if ( v15 == 27 )
      {
        v36 = 25;
        goto LABEL_50;
      }
      if ( v15 == 28 )
      {
        v36 = 29;
        goto LABEL_50;
      }
    }
  }
  else if ( v15 <= 39 )
  {
    if ( v15 == 37 )
    {
      v36 = 37;
      goto LABEL_50;
    }
    if ( v15 == 38 )
    {
      v36 = 39;
      goto LABEL_50;
    }
  }
  else
  {
    switch ( v15 )
    {
      case '(':
        v36 = 40;
        goto LABEL_50;
      case '*':
        v36 = 41;
        goto LABEL_50;
      case '+':
        v36 = 42;
LABEL_50:
        *(_BYTE *)(v17 + 10) = v36;
        break;
    }
  }
  return result;
}
