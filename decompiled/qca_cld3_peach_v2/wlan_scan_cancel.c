__int64 __fastcall wlan_scan_cancel(
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
  unsigned int ref; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w20
  unsigned int *v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v31; // [xsp+8h] [xbp-38h] BYREF
  __int64 *v32; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v33)(__int64, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__usercall *v34)@<X0>(__int64@<X0>, unsigned int *@<X8>, double@<D0>, double@<D1>, double@<D2>, double@<D3>, double@<D4>, double@<D5>, double@<D6>, double@<D7>); // [xsp+20h] [xbp-20h]
  __int64 v35; // [xsp+28h] [xbp-18h]
  __int64 v36; // [xsp+30h] [xbp-10h]
  __int64 v37; // [xsp+38h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36 = 0;
  v33 = nullptr;
  v34 = nullptr;
  v31 = 0;
  v32 = nullptr;
  if ( a1 )
  {
    v10 = *a1;
    if ( v10 )
    {
      ref = wlan_objmgr_vdev_try_get_ref(v10, 0xCu, a2, a3, a4, a5, a6, a7, a8, a9);
      if ( ref )
      {
        v20 = ref;
        qdf_trace_msg(
          0x15u,
          4u,
          "%s: Failed to get vdev ref; status:%d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "wlan_scan_cancel",
          ref);
LABEL_9:
        _qdf_mem_free((__int64)a1);
        goto LABEL_10;
      }
      v32 = a1;
      v33 = scm_scan_cancel_req;
      v34 = scm_scan_cancel_flush_callback;
      v20 = scheduler_post_message_debug(
              0x48u,
              0x15u,
              72,
              (unsigned __int16 *)&v31,
              0x1ECu,
              (__int64)"wlan_scan_cancel");
      if ( v20 )
      {
        wlan_objmgr_vdev_release_ref(*a1, 0xCu, v21, v22, v23, v24, v25, v26, v27, v28, v29);
        goto LABEL_9;
      }
    }
    else
    {
      qdf_trace_msg(0x15u, 2u, "%s: req or vdev within req is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_scan_cancel");
      _qdf_mem_free((__int64)a1);
      v20 = 29;
    }
  }
  else
  {
    qdf_trace_msg(0x15u, 2u, "%s: req or vdev within req is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_scan_cancel");
    v20 = 29;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v20;
}
