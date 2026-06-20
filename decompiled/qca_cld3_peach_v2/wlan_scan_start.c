__int64 __fastcall wlan_scan_start(
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
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int ref; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 result; // x0
  __int64 v46; // x21
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // [xsp+8h] [xbp-38h] BYREF
  __int64 *v56; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v57)(__int64, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v58)(__int64, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-20h]
  __int64 v59; // [xsp+28h] [xbp-18h]
  __int64 v60; // [xsp+30h] [xbp-10h]
  __int64 v61; // [xsp+38h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v59 = 0;
  v60 = 0;
  v57 = nullptr;
  v58 = nullptr;
  v55 = 0;
  v56 = nullptr;
  if ( a1 && (v10 = *a1) != 0 )
  {
    if ( (scm_is_scan_allowed(v10, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
    {
      ref = wlan_objmgr_vdev_try_get_ref(*a1, 0xCu, v11, v12, v13, v14, v15, v16, v17, v18);
      if ( ref )
      {
        v28 = ref;
        qdf_trace_msg(
          0x15u,
          4u,
          "%s: unable to get reference",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "wlan_scan_start");
LABEL_12:
        scm_scan_free_scan_request_mem((__int64)a1, v29, v30, v31, v32, v33, v34, v35, v36);
        result = v28;
        goto LABEL_13;
      }
      v56 = a1;
      v57 = scm_scan_start_req;
      v58 = scm_scan_start_flush_callback;
      result = scheduler_post_message_debug(
                 0x48u,
                 0x15u,
                 72,
                 (unsigned __int16 *)&v55,
                 0x1CBu,
                 (__int64)"wlan_scan_start");
      if ( (_DWORD)result )
      {
        v28 = result;
        wlan_objmgr_vdev_release_ref(*a1, 0xCu, (unsigned int *)*a1, v47, v48, v49, v50, v51, v52, v53, v54);
        goto LABEL_12;
      }
    }
    else
    {
      v46 = jiffies;
      if ( wlan_scan_start___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x15u,
          2u,
          "%s: scan disabled, rejecting the scan req",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "wlan_scan_start");
        wlan_scan_start___last_ticks = v46;
      }
      scm_scan_free_scan_request_mem((__int64)a1, v11, v12, v13, v14, v15, v16, v17, v18);
      result = 3;
    }
  }
  else
  {
    qdf_trace_msg(0x15u, 2u, "%s: req or vdev within req is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_scan_start");
    scm_scan_free_scan_request_mem((__int64)a1, v37, v38, v39, v40, v41, v42, v43, v44);
    result = 29;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
