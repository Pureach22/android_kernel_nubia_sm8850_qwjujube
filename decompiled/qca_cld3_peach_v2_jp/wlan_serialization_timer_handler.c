__int64 __fastcall wlan_serialization_timer_handler(
        _QWORD **a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *v9; // x20
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  void *v28; // x0
  unsigned int *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x19
  _QWORD *v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x20
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int *v57; // x8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v67; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v68)(__int64, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v69)(); // [xsp+20h] [xbp-20h]
  __int64 v70; // [xsp+28h] [xbp-18h]
  __int64 v71; // [xsp+30h] [xbp-10h]
  __int64 v72; // [xsp+38h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a1;
  if ( *a1 )
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: Active cmd timeout for cmd_type %d vdev %d cmd id %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_serialization_timer_handler",
      *(unsigned int *)v9,
      *(unsigned __int8 *)(v9[4] + 104LL),
      *((unsigned int *)v9 + 1));
    v70 = 0;
    v71 = 0;
    v10 = v9[4];
    v68 = nullptr;
    v69 = nullptr;
    v66 = 4207804416LL;
    v67 = nullptr;
    if ( !(unsigned int)wlan_objmgr_vdev_try_get_ref(v10, 9u, v11, v12, v13, v14, v15, v16, v17, v18) )
    {
      v28 = (void *)_qdf_mem_malloc(0x30u, "wlan_serialization_timer_cb_mc_ctx", 631);
      if ( !v28 )
      {
        result = wlan_objmgr_vdev_release_ref(v9[4], 9u, v29, v30, v31, v32, v33, v34, v35, v36, v37);
        goto LABEL_12;
      }
      v38 = (__int64)v28;
      qdf_mem_copy(v28, v9, 0x30u);
      v39 = scheduler_qdf_mc_timer_init((__int64)wlan_serialization_generic_timer_cb, v38);
      if ( v39 )
      {
        v48 = (__int64)v39;
        v67 = v39;
        v68 = scheduler_qdf_mc_timer_callback_t_wrapper;
        HIDWORD(v66) = 0;
        v69 = wlan_serialization_mc_flush;
        result = scheduler_post_message_debug(
                   0x4Cu,
                   0x4Cu,
                   55,
                   (unsigned __int16 *)&v66,
                   0x28Fu,
                   (__int64)"wlan_serialization_timer_cb_mc_ctx");
        if ( !(_DWORD)result )
          goto LABEL_12;
        qdf_trace_msg(
          0x4Cu,
          2u,
          "%s: Could not enqueue timer to timer queue",
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          "wlan_serialization_timer_cb_mc_ctx");
        _qdf_mem_free(v48);
      }
      else
      {
        qdf_trace_msg(
          0x4Cu,
          2u,
          "%s: failed to allocate sched_qdf_mc_timer_cb_wrapper",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "wlan_serialization_timer_cb_mc_ctx");
      }
      wlan_objmgr_vdev_release_ref(*(_QWORD *)(v38 + 32), 9u, v57, v58, v59, v60, v61, v62, v63, v64, v65);
      result = _qdf_mem_free(v38);
      goto LABEL_12;
    }
    result = qdf_trace_msg(
               0x4Cu,
               2u,
               "%s: unable to get reference for vdev %d",
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               "wlan_serialization_timer_cb_mc_ctx",
               *(unsigned __int8 *)(v9[4] + 104LL));
  }
  else
  {
    result = qdf_trace_msg(
               0x4Cu,
               2u,
               "%s: Command not found",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "wlan_serialization_timer_handler");
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
