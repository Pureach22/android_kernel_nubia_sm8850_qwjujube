__int64 __fastcall vdevmgr_vdev_reconfig_timer_complete(
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
  __int64 v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // [xsp+8h] [xbp-38h] BYREF
  __int64 v37; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v38)(); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v39)(); // [xsp+20h] [xbp-20h]
  __int64 v40; // [xsp+28h] [xbp-18h]
  __int64 v41; // [xsp+30h] [xbp-10h]
  __int64 v42; // [xsp+38h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 520);
  v40 = 0;
  v41 = 0;
  v38 = nullptr;
  v39 = nullptr;
  v36 = 0;
  v37 = 0;
  if ( v9 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d link removal timed out",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "vdevmgr_vdev_reconfig_timer_complete",
      *(unsigned __int8 *)(v9 + 168));
    v37 = v9;
    v38 = vdevmgr_reconfig_req_cb;
    v39 = vdevmgr_reconfig_req_flush_cb;
    result = wlan_objmgr_vdev_try_get_ref(v9, 0x4Du, v10, v11, v12, v13, v14, v15, v16, v17);
    if ( !(_DWORD)result )
    {
      result = scheduler_post_message_debug(
                 0x1Fu,
                 0x49u,
                 73,
                 (unsigned __int16 *)&v36,
                 0x8C3u,
                 (__int64)"vdevmgr_vdev_reconfig_timer_complete");
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d failed to post scheduler_msg",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "vdevmgr_vdev_reconfig_timer_complete",
          *(unsigned __int8 *)(v9 + 168));
        result = wlan_objmgr_vdev_release_ref(v9, 0x4Du, v27, v28, v29, v30, v31, v32, v33, v34, v35);
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x68u,
               2u,
               "%s: invalid vdev",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "vdevmgr_vdev_reconfig_timer_complete");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
