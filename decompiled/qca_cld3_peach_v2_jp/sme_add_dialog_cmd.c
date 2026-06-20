__int64 __fastcall sme_add_dialog_cmd(
        _QWORD *a1,
        __int64 a2,
        unsigned int *a3,
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
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  void *v41; // x0
  __int64 v42; // x23
  unsigned int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w19
  unsigned int v53; // w21
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v63; // [xsp+8h] [xbp-38h] BYREF
  __int64 v64; // [xsp+10h] [xbp-30h]
  __int64 v65; // [xsp+18h] [xbp-28h]
  __int64 v66; // [xsp+20h] [xbp-20h]
  __int64 v67; // [xsp+28h] [xbp-18h]
  __int64 v68; // [xsp+30h] [xbp-10h]
  __int64 v69; // [xsp+38h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v62 = 0;
  qdf_trace_msg(0x34u, 8u, "%s: enter", a5, a6, a7, a8, a9, a10, a11, a12, "sme_add_dialog_cmd");
  if ( (mlme_get_user_ps(a1[2694], *a3) & 1) != 0 )
  {
    if ( (mlme_is_twt_notify_in_progress(a1[2694], *a3) & 1) != 0 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Waiting for TWT Notify",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "sme_add_dialog_cmd");
      result = 8;
    }
    else if ( (((__int64 (__fastcall *)(_QWORD, unsigned int *, _QWORD, __int64, unsigned int *))mlme_twt_is_command_in_progress)(
                 a1[2694],
                 a3 + 1,
                 a3[3],
                 255,
                 &v62)
             & 1) != 0 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Already TWT command:%d is in progress",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "sme_add_dialog_cmd",
        v62);
      result = 24;
    }
    else if ( _cds_get_context(54, (__int64)"sme_add_dialog_cmd", v33, v34, v35, v36, v37, v38, v39, v40) )
    {
      v41 = (void *)_qdf_mem_malloc(0x50u, "sme_add_dialog_cmd", 14343);
      if ( v41 )
      {
        v42 = (__int64)v41;
        qdf_mem_copy(v41, a3, 0x50u);
        v43 = qdf_mutex_acquire((__int64)(a1 + 1597));
        if ( v43 )
        {
          v52 = v43;
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: failed to register add dialog callback",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "sme_add_dialog_cmd");
          _qdf_mem_free(v42);
          result = v52;
        }
        else
        {
          mlme_add_twt_session(a1[2694], a3 + 1, a3[3]);
          mlme_set_twt_command_in_progress(a1[2694], a3 + 1, a3[3], 1);
          a1[1804] = a2;
          a1[1811] = a4;
          v64 = v42;
          LOWORD(v63) = 4545;
          qdf_mutex_release((__int64)(a1 + 1597));
          v53 = scheduler_post_message_debug(
                  0x34u,
                  0x36u,
                  54,
                  (unsigned __int16 *)&v63,
                  0x3829u,
                  (__int64)"sme_add_dialog_cmd");
          if ( v53 )
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Post twt add dialog msg fail",
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              "sme_add_dialog_cmd");
            mlme_set_twt_command_in_progress(a1[2694], a3 + 1, a3[3], 0);
            ((void (__fastcall *)(_QWORD, unsigned int *, _QWORD))mlme_init_twt_context)(a1[2694], a3 + 1, a3[3]);
            _qdf_mem_free(v42);
          }
          qdf_trace_msg(0x34u, 8u, "%s: exit", v54, v55, v56, v57, v58, v59, v60, v61, "sme_add_dialog_cmd");
          result = v53;
        }
      }
      else
      {
        result = 2;
      }
    }
    else
    {
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Power save mode disable",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "sme_add_dialog_cmd");
    result = 3;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
