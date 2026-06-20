__int64 __fastcall sme_resume_dialog_cmd(
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
  void *v23; // x0
  __int64 v24; // x21
  unsigned int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w19
  unsigned int v35; // w22
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v45; // [xsp+8h] [xbp-38h] BYREF
  __int64 v46; // [xsp+10h] [xbp-30h]
  __int64 v47; // [xsp+18h] [xbp-28h]
  __int64 v48; // [xsp+20h] [xbp-20h]
  __int64 v49; // [xsp+28h] [xbp-18h]
  __int64 v50; // [xsp+30h] [xbp-10h]
  __int64 v51; // [xsp+38h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v44 = 0;
  qdf_trace_msg(0x34u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "sme_resume_dialog_cmd");
  if ( (((__int64 (__fastcall *)(_QWORD, unsigned int *, _QWORD, __int64, unsigned int *))mlme_twt_is_command_in_progress)(
          *(_QWORD *)(a1 + 21552),
          a2 + 1,
          a2[3],
          255,
          &v44)
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
      "sme_resume_dialog_cmd",
      v44);
    result = 24;
  }
  else if ( _cds_get_context(54, (__int64)"sme_resume_dialog_cmd", v14, v15, v16, v17, v18, v19, v20, v21) )
  {
    v23 = (void *)_qdf_mem_malloc(0x18u, "sme_resume_dialog_cmd", 14720);
    if ( v23 )
    {
      v24 = (__int64)v23;
      qdf_mem_copy(v23, a2, 0x18u);
      v25 = qdf_mutex_acquire(a1 + 12776);
      if ( v25 )
      {
        v34 = v25;
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: failed to register resume dialog callback",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "sme_resume_dialog_cmd");
        _qdf_mem_free(v24);
        result = v34;
      }
      else
      {
        mlme_set_twt_command_in_progress(*(_QWORD *)(a1 + 21552), a2 + 1, a2[3], 8);
        *(_QWORD *)(a1 + 14488) = a3;
        v46 = v24;
        LOWORD(v45) = 4548;
        qdf_mutex_release(a1 + 12776);
        v35 = scheduler_post_message_debug(
                0x34u,
                0x36u,
                54,
                (unsigned __int16 *)&v45,
                0x3999u,
                (__int64)"sme_resume_dialog_cmd");
        if ( v35 )
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: Post twt resume dialog msg fail",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "sme_resume_dialog_cmd");
          mlme_set_twt_command_in_progress(*(_QWORD *)(a1 + 21552), a2 + 1, a2[3], 0);
          _qdf_mem_free(v24);
        }
        qdf_trace_msg(0x34u, 8u, "%s: exit", v36, v37, v38, v39, v40, v41, v42, v43, "sme_resume_dialog_cmd");
        result = v35;
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
