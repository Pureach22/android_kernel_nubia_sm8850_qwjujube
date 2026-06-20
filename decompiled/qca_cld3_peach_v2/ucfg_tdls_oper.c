__int64 __fastcall ucfg_tdls_oper(
        __int64 a1,
        unsigned __int8 *a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v13; // w22
  __int16 v14; // w23
  const char *v15; // x4
  __int64 result; // x0
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _QWORD *v26; // x20
  unsigned int ref; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w21
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  const char *v45; // x4
  unsigned int *v46; // x8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  int v55; // [xsp+0h] [xbp-40h]
  __int64 v56; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v57; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v58)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v59)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-20h]
  __int64 v60; // [xsp+28h] [xbp-18h]
  __int64 v61; // [xsp+30h] [xbp-10h]
  __int64 v62; // [xsp+38h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v60 = 0;
  v61 = 0;
  v58 = nullptr;
  v59 = nullptr;
  v56 = 0;
  v57 = nullptr;
  if ( a1 && a2 )
  {
    v13 = a3 - 4;
    v14 = a3;
    if ( (unsigned int)(a3 - 4) > 3 )
      v15 = "ERR:UNKNOWN OPER";
    else
      v15 = off_B2DF38[v13];
    v55 = a2[5];
    qdf_trace_msg(
      0,
      8u,
      "%s: %s for peer %02x:%02x:%02x:**:**:%02x",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "ucfg_tdls_oper",
      v15,
      *a2,
      a2[1],
      a2[2],
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62);
    v17 = _qdf_mem_malloc(0x10u, "ucfg_tdls_oper", 844);
    if ( v17 )
    {
      v26 = (_QWORD *)v17;
      ref = wlan_objmgr_vdev_try_get_ref(a1, 0x11u, v18, v19, v20, v21, v22, v23, v24, v25);
      if ( ref )
      {
        v36 = ref;
        qdf_trace_msg(0, 2u, "%s: can't get vdev", v28, v29, v30, v31, v32, v33, v34, v35, "ucfg_tdls_oper");
LABEL_16:
        _qdf_mem_free((__int64)v26);
        result = v36;
        goto LABEL_17;
      }
      qdf_mem_copy(v26 + 1, a2, 6u);
      *v26 = a1;
      v57 = v26;
      v58 = tdls_process_cmd;
      LOWORD(v56) = v14;
      v59 = ucfg_tdls_post_msg_flush_cb;
      result = scheduler_post_message_debug(0x33u, 0, 72, (unsigned __int16 *)&v56, 0x35Fu, (__int64)"ucfg_tdls_oper");
      if ( (_DWORD)result )
      {
        v36 = result;
        if ( v13 > 3 )
          v45 = "ERR:UNKNOWN OPER";
        else
          v45 = off_B2DF38[v13];
        qdf_trace_msg(0, 2u, "%s: post msg for %s fail", v37, v38, v39, v40, v41, v42, v43, v44, "ucfg_tdls_oper", v45);
        wlan_objmgr_vdev_release_ref(a1, 0x11u, v46, v47, v48, v49, v50, v51, v52, v53, v54);
        goto LABEL_16;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: vdev: %pK, mac %pK", a4, a5, a6, a7, a8, a9, a10, a11, "ucfg_tdls_oper", a1, a2);
    result = 29;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
