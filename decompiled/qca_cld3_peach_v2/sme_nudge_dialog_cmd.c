__int64 __fastcall sme_nudge_dialog_cmd(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  void *v31; // x0
  __int64 v32; // x22
  unsigned int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w19
  unsigned int v43; // w21
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v53; // [xsp+8h] [xbp-38h] BYREF
  __int64 v54; // [xsp+10h] [xbp-30h]
  __int64 v55; // [xsp+18h] [xbp-28h]
  __int64 v56; // [xsp+20h] [xbp-20h]
  __int64 v57; // [xsp+28h] [xbp-18h]
  __int64 v58; // [xsp+30h] [xbp-10h]
  __int64 v59; // [xsp+38h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v52 = 0;
  qdf_trace_msg(0x34u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "sme_nudge_dialog_cmd");
  if ( (((__int64 (__fastcall *)(_QWORD, unsigned int *, _QWORD, __int64, unsigned int *))mlme_twt_is_command_in_progress)(
          *(_QWORD *)(a1 + 21624),
          a2 + 1,
          a2[3],
          255,
          &v52)
      & 1) != 0 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Already TWT command:%d is in progress",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "sme_nudge_dialog_cmd",
      v52);
    result = 24;
  }
  else if ( _cds_get_context(54, (__int64)"sme_nudge_dialog_cmd", v14, v15, v16, v17, v18, v19, v20, v21) )
  {
    v31 = (void *)_qdf_mem_malloc(0x18u, "sme_nudge_dialog_cmd", 14651);
    if ( v31 )
    {
      v32 = (__int64)v31;
      qdf_mem_copy(v31, a2, 0x18u);
      v33 = qdf_mutex_acquire(a1 + 12848);
      if ( v33 )
      {
        v42 = v33;
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: failed to register nudge dialog callback",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "sme_nudge_dialog_cmd");
        _qdf_mem_free(v32);
        result = v42;
      }
      else
      {
        mlme_set_twt_command_in_progress(*(_QWORD *)(a1 + 21624), a2 + 1, a2[3], 16);
        *(_QWORD *)(a1 + 14560) = a3;
        v54 = v32;
        LOWORD(v53) = 4550;
        qdf_mutex_release(a1 + 12848);
        v43 = scheduler_post_message_debug(
                0x34u,
                0x36u,
                54,
                (unsigned __int16 *)&v53,
                0x3954u,
                (__int64)"sme_nudge_dialog_cmd");
        if ( v43 )
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: Post twt nudge dialog msg fail",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "sme_nudge_dialog_cmd");
          mlme_set_twt_command_in_progress(*(_QWORD *)(a1 + 21624), a2 + 1, a2[3], 0);
          _qdf_mem_free(v32);
        }
        qdf_trace_msg(0x34u, 8u, "%s: exit", v44, v45, v46, v47, v48, v49, v50, v51, "sme_nudge_dialog_cmd");
        result = v43;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: wma_handle is NULL", v23, v24, v25, v26, v27, v28, v29, v30, "sme_nudge_dialog_cmd");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
