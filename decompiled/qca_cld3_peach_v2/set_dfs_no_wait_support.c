__int64 __fastcall set_dfs_no_wait_support(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 comp_private_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  char v30; // w21
  __int64 v31; // x5
  __int64 v32; // x20
  unsigned int *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int *v42; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x98u, 2u, "%s: NULL pdev", a3, a4, a5, a6, a7, a8, a9, a10, "set_dfs_no_wait_support");
    return 4;
  }
  if ( (unsigned int)wlan_objmgr_pdev_try_get_ref(a1, 0x60u, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    qdf_trace_msg(0x98u, 2u, "%s: pdev get ref fail", v12, v13, v14, v15, v16, v17, v18, v19, "set_dfs_no_wait_support");
    return 16;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x2Du);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x98u,
      2u,
      "%s: NULL pre cac pdev priv",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "set_dfs_no_wait_support");
    wlan_objmgr_pdev_release_ref(a1, 0x60u, v42, v43, v44, v45, v46, v47, v48, v49, v50);
    return 4;
  }
  v30 = a2 & 1;
  v31 = a2 & 1;
  v32 = comp_private_obj;
  qdf_trace_msg(
    0x98u,
    8u,
    "%s: dnw enabled %d->%d",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "set_dfs_no_wait_support",
    *(unsigned __int8 *)(comp_private_obj + 16),
    v31);
  *(_BYTE *)(v32 + 16) = v30;
  wlan_objmgr_pdev_release_ref(a1, 0x60u, v33, v34, v35, v36, v37, v38, v39, v40, v41);
  return 0;
}
