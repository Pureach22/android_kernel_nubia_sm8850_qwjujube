__int64 __fastcall wlan_tdls_notify_sta_disconnect(
        char a1,
        char a2,
        char a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  const char *v16; // x2
  const char *v17; // x3
  unsigned int v18; // w1
  __int64 result; // x0
  __int64 v20; // x0
  unsigned int *v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 *v30; // x22
  unsigned int *v31; // x8
  __int64 v32; // [xsp+8h] [xbp-38h] BYREF
  __int64 v33; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v34)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v35)(); // [xsp+20h] [xbp-20h]
  __int64 v36; // [xsp+28h] [xbp-18h]
  __int64 v37; // [xsp+30h] [xbp-10h]
  __int64 v38; // [xsp+38h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a4 )
  {
    v16 = "%s: vdev is NULL";
    goto LABEL_5;
  }
  if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(a4, 0x11u, a5, a6, a7, a8, a9, a10, a11, a12) )
  {
    v16 = "%s: can't get vdev";
LABEL_5:
    v17 = "wlan_tdls_notify_sta_disconnect";
    v18 = 2;
    goto LABEL_6;
  }
  v36 = 0;
  v37 = 0;
  v34 = nullptr;
  v35 = nullptr;
  v32 = 0;
  v33 = 0;
  qdf_trace_msg(0, 8u, "%s: Enter ", a5, a6, a7, a8, a9, a10, a11, a12, "tdls_notify_disconnect");
  v20 = _qdf_mem_malloc(0x10u, "tdls_notify_disconnect", 395);
  if ( !v20 )
  {
    result = wlan_objmgr_vdev_release_ref(a4, 0x11u, v21, v22, v23, v24, v25, v26, v27, v28, v29);
    goto LABEL_7;
  }
  *(_QWORD *)v20 = a4;
  *(_BYTE *)(v20 + 10) = a2 & 1;
  *(_WORD *)(v20 + 8) = 0;
  v30 = (__int64 *)v20;
  *(_BYTE *)(v20 + 11) = a3 & 1;
  *(_BYTE *)(v20 + 12) = a1;
  *(_WORD *)(v20 + 13) = 0;
  *(_BYTE *)(v20 + 15) = 0;
  v33 = v20;
  v34 = tdls_process_cmd;
  LOWORD(v32) = 13;
  v35 = tdls_notify_flush_cb;
  if ( (unsigned int)scheduler_post_message_debug(
                       0x33u,
                       0,
                       73,
                       (unsigned __int16 *)&v32,
                       0x199u,
                       (__int64)"tdls_notify_disconnect") )
  {
    wlan_objmgr_vdev_release_ref(*v30, 0x11u, v31, a5, a6, a7, a8, a9, a10, a11, a12);
    _qdf_mem_free((__int64)v30);
  }
  v16 = "%s: Exit ";
  v17 = "tdls_notify_disconnect";
  v18 = 8;
LABEL_6:
  result = qdf_trace_msg(0, v18, v16, a5, a6, a7, a8, a9, a10, a11, a12, v17);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
