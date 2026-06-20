__int64 __fastcall sme_del_dialog_cmd(
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
  __int64 result; // x0
  void *v25; // x0
  __int64 v26; // x23
  unsigned int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w19
  unsigned int v37; // w21
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v47; // [xsp+8h] [xbp-38h] BYREF
  __int64 v48; // [xsp+10h] [xbp-30h]
  __int64 v49; // [xsp+18h] [xbp-28h]
  __int64 v50; // [xsp+20h] [xbp-20h]
  __int64 v51; // [xsp+28h] [xbp-18h]
  __int64 v52; // [xsp+30h] [xbp-10h]
  __int64 v53; // [xsp+38h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v46 = 0;
  qdf_trace_msg(0x34u, 8u, "%s: enter", a5, a6, a7, a8, a9, a10, a11, a12, "sme_del_dialog_cmd");
  if ( (((__int64 (__fastcall *)(_QWORD, unsigned int *, _QWORD, __int64, unsigned int *))mlme_twt_is_command_in_progress)(
          a1[2703],
          a3 + 1,
          a3[3],
          1,
          &v46)
      & 1) != 0
    || (((__int64 (__fastcall *)(_QWORD, unsigned int *, _QWORD, __int64, unsigned int *))mlme_twt_is_command_in_progress)(
          a1[2703],
          a3 + 1,
          a3[3],
          2,
          &v46)
      & 1) != 0 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Already TWT command:%d is in progress",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "sme_del_dialog_cmd",
      v46);
    result = 24;
  }
  else if ( _cds_get_context(54, (__int64)"sme_del_dialog_cmd", v16, v17, v18, v19, v20, v21, v22, v23) )
  {
    v25 = (void *)_qdf_mem_malloc(0x10u, "sme_del_dialog_cmd", 14429);
    if ( v25 )
    {
      v26 = (__int64)v25;
      qdf_mem_copy(v25, a3, 0x10u);
      v27 = qdf_mutex_acquire((__int64)(a1 + 1606));
      if ( v27 )
      {
        v36 = v27;
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Failed to acquire SME global lock",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "sme_del_dialog_cmd");
        _qdf_mem_free(v26);
        result = v36;
      }
      else
      {
        mlme_set_twt_command_in_progress(a1[2703], a3 + 1, a3[3], 2);
        a1[1814] = a2;
        a1[1820] = a4;
        v48 = v26;
        LOWORD(v47) = 4546;
        qdf_mutex_release((__int64)(a1 + 1606));
        v37 = scheduler_post_message_debug(
                0x34u,
                0x36u,
                54,
                (unsigned __int16 *)&v47,
                0x3877u,
                (__int64)"sme_del_dialog_cmd");
        if ( v37 )
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: Post twt del dialog msg fail",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "sme_del_dialog_cmd");
          mlme_set_twt_command_in_progress(a1[2703], a3 + 1, a3[3], 0);
          _qdf_mem_free(v26);
        }
        qdf_trace_msg(0x34u, 8u, "%s: exit", v38, v39, v40, v41, v42, v43, v44, v45, "sme_del_dialog_cmd");
        result = v37;
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
  _ReadStatusReg(SP_EL0);
  return result;
}
