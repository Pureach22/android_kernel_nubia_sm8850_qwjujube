__int64 __fastcall target_if_vdev_mgr_rsp_timer_mgmt_cb(
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
  _QWORD *v10; // x0
  __int64 v11; // x20
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2
  _DWORD v22[2]; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v23; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v24)(__int64, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v25)(); // [xsp+20h] [xbp-20h]
  __int64 v26; // [xsp+28h] [xbp-18h]
  __int64 v27; // [xsp+30h] [xbp-10h]
  __int64 v28; // [xsp+38h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a1;
  v26 = 0;
  v27 = 0;
  if ( !v9 )
  {
    v21 = "%s: PSOC is NULL";
LABEL_7:
    result = qdf_trace_msg(0x68u, 2u, v21, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_rsp_cb_mc_ctx");
    goto LABEL_8;
  }
  v22[0] = -87162880;
  v10 = scheduler_qdf_mc_timer_init((__int64)target_if_vdev_mgr_rsp_timer_cb, (__int64)a1);
  if ( !v10 )
  {
    v21 = "%s: failed to allocate sched_qdf_mc_timer_cb_wrapper";
    goto LABEL_7;
  }
  v11 = (__int64)v10;
  v23 = v10;
  v24 = scheduler_qdf_mc_timer_callback_t_wrapper;
  v22[1] = 0;
  v25 = target_if_vdev_mgr_rsp_flush_cb_mc;
  result = scheduler_post_message_debug(
             0x49u,
             0x49u,
             55,
             (unsigned __int16 *)v22,
             0x167u,
             (__int64)"target_if_vdev_mgr_rsp_cb_mc_ctx");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Could not enqueue timer to timer queue",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_vdev_mgr_rsp_cb_mc_ctx");
    _qdf_mem_free(v11);
    result = wlan_objmgr_psoc_release_ref(v9, 72);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
