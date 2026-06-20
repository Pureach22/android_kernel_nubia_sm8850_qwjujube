__int64 __fastcall ucfg_tdls_send_mgmt_frame(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned __int8 *v10; // x0
  unsigned __int8 *v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const void *v20; // x1
  unsigned __int8 v21; // w8
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int ref; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w21
  unsigned int *v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int8 *v51; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v52)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v53)(); // [xsp+20h] [xbp-20h]
  __int64 v54; // [xsp+28h] [xbp-18h]
  __int64 v55; // [xsp+30h] [xbp-10h]
  __int64 v56; // [xsp+38h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54 = 0;
  v55 = 0;
  v52 = nullptr;
  v53 = nullptr;
  v50 = 0;
  v51 = nullptr;
  if ( a1 && *(_QWORD *)a1 )
  {
    v10 = (unsigned __int8 *)_qdf_mem_malloc(a1[56] + 80LL, "ucfg_tdls_send_mgmt_frame", 934);
    if ( v10 )
    {
      v11 = v10;
      qdf_mem_copy(v10, a1, 0x50u);
      if ( a1[56] && (v20 = *((const void **)a1 + 6)) != nullptr )
      {
        qdf_mem_copy(v11 + 77, v20, a1[56]);
        v21 = a1[56];
      }
      else
      {
        v21 = 0;
      }
      v11[76] = v21;
      qdf_trace_msg(
        0,
        8u,
        "%s: vdev id: %d, session id : %d, action %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "ucfg_tdls_send_mgmt_frame",
        v11[42],
        v11[40],
        a1[8]);
      ref = wlan_objmgr_vdev_try_get_ref(*(_QWORD *)a1, 0x11u, v23, v24, v25, v26, v27, v28, v29, v30);
      if ( ref )
      {
        v40 = ref;
        qdf_trace_msg(
          0,
          2u,
          "%s: Unable to get vdev reference for tdls module",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "ucfg_tdls_send_mgmt_frame");
LABEL_14:
        _qdf_mem_free((__int64)v11);
        result = v40;
        goto LABEL_15;
      }
      v51 = v11;
      v52 = tdls_process_cmd;
      v53 = tdls_send_mgmt_frame_flush_callback;
      LOWORD(v50) = 1;
      result = scheduler_post_message_debug(
                 0x33u,
                 0,
                 72,
                 (unsigned __int16 *)&v50,
                 0x3C4u,
                 (__int64)"ucfg_tdls_send_mgmt_frame");
      if ( (_DWORD)result )
      {
        v40 = result;
        wlan_objmgr_vdev_release_ref(*(_QWORD *)a1, 0x11u, v41, v42, v43, v44, v45, v46, v47, v48, v49);
        goto LABEL_14;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: Invalid mgmt req params %pK",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "ucfg_tdls_send_mgmt_frame",
      a1);
    result = 29;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
