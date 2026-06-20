__int64 __fastcall pmo_vdev_ready(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  result = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    pmo_set_vdev_bridge_addr(a1, a2, v13, v14, v15, v16, v17, v18, v19, v20);
    pmo_register_wow_wakeup_events(a1, v21, v22, v23, v24, v25, v26, v27, v28);
    pmo_register_wow_default_patterns(a1);
    wlan_objmgr_vdev_release_ref(a1, 0xAu, v29, v30, v31, v32, v33, v34, v35, v36, v37);
    return 0;
  }
  return result;
}
