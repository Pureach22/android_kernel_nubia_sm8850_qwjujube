__int64 __fastcall sme_sap_del_dialog_cmd(
        __int64 a1,
        __int64 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x0
  __int64 v15; // x2
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  void *v26; // x0
  __int64 v27; // x22
  unsigned int v28; // w0
  unsigned int v29; // w19
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v39; // x0
  __int64 v40; // x2
  unsigned int v42; // w23
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x0
  __int64 v52; // x2
  __int64 v54; // x0
  __int64 v55; // x2
  __int64 v57; // [xsp+8h] [xbp-38h] BYREF
  __int64 v58; // [xsp+10h] [xbp-30h]
  __int64 v59; // [xsp+18h] [xbp-28h]
  __int64 v60; // [xsp+20h] [xbp-20h]
  __int64 v61; // [xsp+28h] [xbp-18h]
  __int64 v62; // [xsp+30h] [xbp-10h]
  __int64 v63; // [xsp+38h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  qdf_trace_msg(0x34u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "sme_sap_del_dialog_cmd");
  v14 = *(_QWORD *)(a1 + 21552);
  v15 = a3[3];
  if ( a3[1] == -1 && *((__int16 *)a3 + 4) == -1 )
  {
    if ( (mlme_twt_any_peer_cmd_in_progress(v14, *a3, v15, 2) & 1) != 0 )
      goto LABEL_6;
  }
  else if ( (mlme_sap_twt_peer_is_cmd_in_progress(v14, a3 + 1, v15, 2) & 1) != 0 )
  {
LABEL_6:
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Already TWT teardown command is in progress",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "sme_sap_del_dialog_cmd");
    result = 24;
    goto LABEL_40;
  }
  if ( _cds_get_context(54, (__int64)"sme_sap_del_dialog_cmd", v17, v18, v19, v20, v21, v22, v23, v24) )
  {
    v26 = (void *)_qdf_mem_malloc(0x10u, "sme_sap_del_dialog_cmd", 14499);
    if ( v26 )
    {
      v27 = (__int64)v26;
      qdf_mem_copy(v26, a3, 0x10u);
      v28 = qdf_mutex_acquire(a1 + 12776);
      if ( v28 )
      {
        v29 = v28;
        _qdf_mem_free(v27);
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Failed to acquire SME global lock",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "sme_sap_del_dialog_cmd");
        result = v29;
      }
      else
      {
        if ( a3[1] != -1 || *((__int16 *)a3 + 4) != -1 )
          mlme_add_twt_session(*(_QWORD *)(a1 + 21552), a3 + 1, a3[3]);
        v39 = *(_QWORD *)(a1 + 21552);
        v40 = a3[3];
        if ( a3[1] == -1 && *((__int16 *)a3 + 4) == -1 )
          mlme_sap_set_twt_all_peers_cmd_in_progress(v39, *a3, v40, 2);
        else
          mlme_set_twt_command_in_progress(v39, a3 + 1, v40, 2);
        *(_QWORD *)(a1 + 14440) = a2;
        v58 = v27;
        LOWORD(v57) = 4546;
        qdf_mutex_release(a1 + 12776);
        v42 = scheduler_post_message_debug(
                0x34u,
                0x36u,
                54,
                (unsigned __int16 *)&v57,
                0x38C4u,
                (__int64)"sme_sap_del_dialog_cmd");
        if ( v42 )
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: Post twt del dialog msg fail",
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            "sme_sap_del_dialog_cmd");
          v51 = *(_QWORD *)(a1 + 21552);
          v52 = a3[3];
          if ( a3[1] == -1 && *((__int16 *)a3 + 4) == -1 )
            mlme_sap_set_twt_all_peers_cmd_in_progress(v51, *a3, v52, 0);
          else
            mlme_set_twt_command_in_progress(v51, a3 + 1, v52, 0);
          v54 = *(_QWORD *)(a1 + 21552);
          v55 = a3[3];
          if ( a3[1] == -1 && *((__int16 *)a3 + 4) == -1 )
            mlme_init_all_peers_twt_context(v54, *a3, v55);
          else
            ((void (__fastcall *)(__int64, unsigned int *, __int64))mlme_init_twt_context)(v54, a3 + 1, v55);
          _qdf_mem_free(v27);
        }
        qdf_trace_msg(0x34u, 8u, "%s: exit", v43, v44, v45, v46, v47, v48, v49, v50, "sme_sap_del_dialog_cmd");
        result = v42;
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
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
