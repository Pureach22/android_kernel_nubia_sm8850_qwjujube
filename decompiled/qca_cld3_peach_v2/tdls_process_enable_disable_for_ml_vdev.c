__int64 __fastcall tdls_process_enable_disable_for_ml_vdev(
        __int64 result,
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
  __int64 v10; // x21
  __int64 v11; // x20
  unsigned int *v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int *v31; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  v10 = *(_QWORD *)(result + 1360);
  if ( v10 )
  {
    v11 = *(_QWORD *)(v10 + 24);
    if ( v11 )
    {
      result = wlan_objmgr_vdev_try_get_ref(*(_QWORD *)(v10 + 24), 0x11u, a3, a4, a5, a6, a7, a8, a9, a10);
      if ( !(_DWORD)result )
      {
        if ( (a2 & 1) != 0 )
          tdls_process_enable_for_vdev(v11);
        else
          tdls_disable_offchan_and_teardown_links(v11, a3, a4, a5, a6, a7, a8, a9, a10);
        result = wlan_objmgr_vdev_release_ref(v11, 0x11u, v13, v14, v15, v16, v17, v18, v19, v20, v21);
      }
    }
    v22 = *(_QWORD *)(v10 + 32);
    if ( v22 )
    {
      result = wlan_objmgr_vdev_try_get_ref(*(_QWORD *)(v10 + 32), 0x11u, a3, a4, a5, a6, a7, a8, a9, a10);
      if ( !(_DWORD)result )
      {
        if ( (a2 & 1) != 0 )
          tdls_process_enable_for_vdev(v22);
        else
          tdls_disable_offchan_and_teardown_links(v22, v23, v24, v25, v26, v27, v28, v29, v30);
        return wlan_objmgr_vdev_release_ref(v22, 0x11u, v31, v32, v33, v34, v35, v36, v37, v38, v39);
      }
    }
  }
  return result;
}
