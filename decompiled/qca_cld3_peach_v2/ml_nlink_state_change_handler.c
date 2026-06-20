__int64 __fastcall ml_nlink_state_change_handler(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v13; // w21
  unsigned int v14; // w20
  __int64 v17; // x8
  __int64 v18; // x0

  v13 = *(_DWORD *)(a2 + 16);
  v14 = *(unsigned __int8 *)(a2 + 168);
  if ( a1 && (v17 = *(_QWORD *)(a1 + 2800)) != 0 && (v18 = *(_QWORD *)(v17 + 16)) != 0 )
  {
    if ( (wmi_service_enabled(v18, 0x129u, a6, a7, a8, a9, a10, a11, a12, a13) & 1) != 0 )
      return ml_nlink_state_change(a1, a3, a4, a5);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Invalid WMI handle",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "ml_is_nlink_service_supported");
  }
  if ( a3 == 1 )
    policy_mgr_handle_ml_sta_links_on_vdev_up_csa(a1, v13, v14);
  else
    policy_mgr_handle_ml_sta_links_on_vdev_down(a1, v13, v14);
  return 0;
}
