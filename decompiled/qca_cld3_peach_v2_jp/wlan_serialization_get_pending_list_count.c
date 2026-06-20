__int64 __fastcall wlan_serialization_get_pending_list_count(
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
  __int64 pdev_by_id; // x0
  __int64 v12; // x21
  __int64 pdev_obj; // x20
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  __int64 v24; // x19
  unsigned int v25; // w20
  const char *v27; // x2
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  if ( !a1 )
  {
    v27 = "%s: invalid psoc";
LABEL_10:
    qdf_trace_msg(0x4Cu, 2u, v27, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_serialization_get_pdev_priv_obj_using_psoc");
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: invalid ser_pdev_obj",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "wlan_serialization_get_pending_list_count");
    return 0;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, 0, 9u);
  if ( !pdev_by_id )
  {
    v27 = "%s: invalid pdev";
    goto LABEL_10;
  }
  v12 = pdev_by_id;
  pdev_obj = wlan_serialization_get_pdev_obj(pdev_by_id);
  wlan_objmgr_pdev_release_ref(v12, 9u, v14, v15, v16, v17, v18, v19, v20, v21, v22);
  if ( !pdev_obj )
  {
    v27 = "%s: invalid ser_pdev_obj";
    goto LABEL_10;
  }
  v23 = 104;
  if ( a2 )
    v23 = 0;
  v24 = pdev_obj + v23;
  wlan_serialization_acquire_lock(pdev_obj + v23 + 88);
  v25 = *(_DWORD *)(v24 + 40);
  wlan_serialization_release_lock(v24 + 88);
  return v25;
}
