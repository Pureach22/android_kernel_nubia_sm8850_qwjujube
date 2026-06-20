__int64 __fastcall dev_sanity_check(
        __int64 a1,
        __int64 *a2,
        __int64 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x0
  unsigned int ref; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  const char *v25; // x2
  __int64 comp_private_obj; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int *v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int *v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7

  if ( !a1 )
  {
    v25 = "%s: vdev is NULL";
LABEL_7:
    qdf_trace_msg(0x6Au, 2u, v25, a4, a5, a6, a7, a8, a9, a10, a11, "dev_sanity_check");
    return 29;
  }
  v11 = *(_QWORD *)(a1 + 216);
  *a2 = v11;
  if ( !v11 )
  {
    v25 = "%s: pdev is NULL";
    goto LABEL_7;
  }
  ref = wlan_objmgr_pdev_try_get_ref(v11, 0x30u, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( ref )
  {
    v23 = ref;
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Failed to get pdev reference",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "dev_sanity_check");
    return v23;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(*a2, 0x1Eu);
  *a3 = comp_private_obj;
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: pdev object for CFR is null",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "dev_sanity_check");
    wlan_objmgr_pdev_release_ref(*a2, 0x30u, v35, v36, v37, v38, v39, v40, v41, v42, v43);
    return 29;
  }
  if ( *(_BYTE *)(comp_private_obj + 1385) )
    return 0;
  qdf_trace_msg(
    0x6Au,
    2u,
    "%s: cfr is not supported on this chip",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "dev_sanity_check");
  wlan_objmgr_pdev_release_ref(*a2, 0x30u, v44, v45, v46, v47, v48, v49, v50, v51, v52);
  return 11;
}
