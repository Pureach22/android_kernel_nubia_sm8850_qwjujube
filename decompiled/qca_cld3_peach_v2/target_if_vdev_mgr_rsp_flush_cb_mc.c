__int64 __fastcall target_if_vdev_mgr_rsp_flush_cb_mc(
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
  _QWORD *v10; // x0
  const char *v12; // x2

  v9 = *(_QWORD *)(a1 + 8);
  if ( !v9 )
  {
    v12 = "%s: Message bodyptr is NULL";
LABEL_10:
    qdf_trace_msg(0x68u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_rsp_flush_cb_mc");
    return 4;
  }
  v10 = (_QWORD *)scheduler_qdf_mc_timer_deinit_return_data_ptr(v9, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !v10 )
  {
    v12 = "%s: vdev response timer is NULL";
    goto LABEL_10;
  }
  if ( !*v10 )
  {
    v12 = "%s: PSOC is NULL";
    goto LABEL_10;
  }
  if ( v10[8] )
    wlan_objmgr_psoc_release_ref(*v10, 72);
  return 0;
}
