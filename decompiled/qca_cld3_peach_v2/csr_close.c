__int64 __fastcall csr_close(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  __int64 v12; // x8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(*(_QWORD *)(a1 + 21624));
  if ( psoc_ext_obj_fl )
  {
    v11 = psoc_ext_obj_fl;
    if ( (unsigned int)qdf_mc_timer_get_current_state(psoc_ext_obj_fl + 7664) == 21 )
      qdf_mc_timer_stop(v11 + 7664);
    qdf_mc_timer_destroy(v11 + 7664);
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: NULL mlme psoc object",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "csr_deinit_disconnect_stats_timer");
  }
  csr_purge_pdev_all_ser_cmd_list(a1);
  v12 = *(_QWORD *)(a1 + 17296);
  if ( v12 )
  {
    csr_cleanup_vdev_session(a1, 0);
    v12 = *(_QWORD *)(a1 + 17296);
  }
  if ( v12 != -96 )
  {
    csr_cleanup_vdev_session(a1, 1);
    v12 = *(_QWORD *)(a1 + 17296);
  }
  if ( v12 != -192 )
  {
    csr_cleanup_vdev_session(a1, 2);
    v12 = *(_QWORD *)(a1 + 17296);
  }
  if ( v12 != -288 )
  {
    csr_cleanup_vdev_session(a1, 3);
    v12 = *(_QWORD *)(a1 + 17296);
  }
  if ( v12 != -384 )
  {
    csr_cleanup_vdev_session(a1, 4);
    v12 = *(_QWORD *)(a1 + 17296);
  }
  if ( v12 != -480 )
    csr_cleanup_vdev_session(a1, 5);
  if ( a1 )
  {
    qdf_mc_timer_stop(a1 + 17304);
    qdf_mc_timer_destroy(a1 + 17304);
  }
  csr_scan_close(a1);
  *(_QWORD *)(a1 + 17296) = 0;
  return 0;
}
