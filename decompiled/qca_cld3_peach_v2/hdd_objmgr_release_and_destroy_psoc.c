__int64 __fastcall hdd_objmgr_release_and_destroy_psoc(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  v9 = *a1;
  *a1 = 0;
  if ( !v9 )
    return 4294967274LL;
  wlan_objmgr_print_ref_all_objects_per_psoc(v9, a2, a3, a4, a5, a6, a7, a8, a9);
  v18 = wlan_objmgr_psoc_obj_delete(v9, v10, v11, v12, v13, v14, v15, v16, v17);
  wlan_objmgr_psoc_release_ref(v9, 5u, v19, v20, v21, v22, v23, v24, v25, v26);
  return qdf_status_to_os_return(v18);
}
