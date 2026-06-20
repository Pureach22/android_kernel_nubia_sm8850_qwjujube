__int64 __fastcall pmo_core_enhanced_mc_filter_enable(
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
  __int64 result; // x0
  double v11; // d0
  unsigned int *v12; // x8
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  result = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !(_DWORD)result )
  {
    v11 = pmo_tgt_send_enhance_multicast_offload_req(a1, 1);
    wlan_objmgr_vdev_release_ref(a1, 0xAu, v12, v11, v13, v14, v15, v16, v17, v18, v19);
    return 0;
  }
  return result;
}
