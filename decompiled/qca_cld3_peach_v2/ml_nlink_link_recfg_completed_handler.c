__int64 __fastcall ml_nlink_link_recfg_completed_handler(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x21
  unsigned int v15; // w21
  unsigned int v16; // w22
  __int64 v17; // x8
  __int64 v18; // x0

  v11 = *(_QWORD *)(a2 + 1360);
  if ( v11 && *(_QWORD *)(v11 + 2224) )
  {
    qdf_mutex_acquire(v11 + 1656);
    mlo_sta_reset_requested_emlsr_mode(v11);
    qdf_mutex_release(v11 + 1656);
  }
  v15 = *(_DWORD *)(a2 + 16);
  v16 = *(unsigned __int8 *)(a2 + 168);
  if ( a1 && (v17 = *(_QWORD *)(a1 + 2800)) != 0 && (v18 = *(_QWORD *)(v17 + 16)) != 0 )
  {
    if ( (wmi_service_enabled(v18, 0x129u, a4, a5, a6, a7, a8, a9, a10, a11) & 1) != 0 )
      return ml_nlink_state_change(a1, 1, 28, a3);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Invalid WMI handle",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "ml_is_nlink_service_supported");
  }
  policy_mgr_handle_ml_sta_links_on_vdev_up_csa(a1, v15, v16);
  return 0;
}
