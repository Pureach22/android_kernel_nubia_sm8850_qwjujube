__int64 __fastcall ucfg_tdls_set_operating_mode(
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
  __int64 *v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  unsigned int ref; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w20
  __int64 result; // x0
  unsigned int *v31; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // [xsp+8h] [xbp-38h] BYREF
  __int64 v41; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v42)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v43)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-20h]
  __int64 v44; // [xsp+28h] [xbp-18h]
  __int64 v45; // [xsp+30h] [xbp-10h]
  __int64 v46; // [xsp+38h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  v45 = 0;
  v42 = nullptr;
  v43 = nullptr;
  v40 = 0;
  v41 = 0;
  if ( !a1 || !*(_QWORD *)a1 )
  {
    qdf_trace_msg(0, 2u, "%s: set_mode_params %pK", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_tdls_set_operating_mode", a1);
    goto LABEL_7;
  }
  qdf_trace_msg(0, 8u, "%s: Enter ", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_tdls_set_operating_mode");
  v10 = (__int64 *)_qdf_mem_malloc(0x18u, "ucfg_tdls_set_operating_mode", 1054);
  if ( !v10 )
  {
LABEL_7:
    result = 29;
    goto LABEL_8;
  }
  v19 = (__int64)v10;
  ref = wlan_objmgr_vdev_try_get_ref(*v10, 0x11u, v11, v12, v13, v14, v15, v16, v17, v18);
  if ( ref )
  {
    v29 = ref;
    qdf_trace_msg(
      0,
      2u,
      "%s: failed to get vdev ref",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "ucfg_tdls_set_operating_mode");
    _qdf_mem_free(v19);
    result = v29;
  }
  else
  {
    *(_DWORD *)(v19 + 16) = *(_DWORD *)(a1 + 16);
    *(_DWORD *)(v19 + 8) = *(_DWORD *)(a1 + 8);
    *(_BYTE *)(v19 + 12) = *(_BYTE *)(a1 + 12);
    *(_QWORD *)v19 = *(_QWORD *)a1;
    v41 = v19;
    v42 = tdls_process_cmd;
    LOWORD(v40) = 14;
    v43 = ucfg_tdls_post_msg_flush_cb;
    if ( (unsigned int)scheduler_post_message_debug(
                         0x33u,
                         0,
                         72,
                         (unsigned __int16 *)&v40,
                         0x434u,
                         (__int64)"ucfg_tdls_set_operating_mode") )
    {
      wlan_objmgr_vdev_release_ref(*(_QWORD *)v19, 0x11u, v31, v32, v33, v34, v35, v36, v37, v38, v39);
      _qdf_mem_free(v19);
    }
    qdf_trace_msg(0, 8u, "%s: Exit ", v32, v33, v34, v35, v36, v37, v38, v39, "ucfg_tdls_set_operating_mode");
    result = 0;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
