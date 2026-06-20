__int64 __fastcall wlan_serialization_mc_flush(
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
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x19

  v9 = scheduler_qdf_mc_timer_deinit_return_data_ptr(*(_QWORD *)(a1 + 8), a2, a3, a4, a5, a6, a7, a8, a9);
  if ( v9 )
  {
    v18 = v9;
    wlan_objmgr_vdev_release_ref(
      *(_QWORD *)(v9 + 32),
      9u,
      *(unsigned int **)(v9 + 32),
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17);
    _qdf_mem_free(v18);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: Error failed to release reference for vdev objmgr",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wlan_serialization_mc_flush");
    return 16;
  }
}
