__int64 __fastcall policy_mgr_handle_emlsr_sta_concurrency(__int64 a1, char a2, char a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _QWORD *v15; // x22
  char is_mlo_in_mode_emlsr; // w23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x0
  __int64 v35; // x22
  int v36; // w23
  double updated; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  const char *v45; // x3
  __int64 v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x20
  unsigned int v56; // w21
  __int64 v57; // [xsp+0h] [xbp-30h] BYREF
  __int64 v58; // [xsp+8h] [xbp-28h] BYREF
  __int64 v59; // [xsp+10h] [xbp-20h] BYREF
  __int64 v60; // [xsp+18h] [xbp-18h]
  __int64 v61; // [xsp+20h] [xbp-10h]
  __int64 v62; // [xsp+28h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v57) = 0;
  BYTE4(v58) = 0;
  LODWORD(v58) = 0;
  LOBYTE(v57) = 0;
  LODWORD(v61) = 0;
  v59 = 0;
  v60 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v45 = "policy_mgr_handle_emlsr_sta_concurrency";
LABEL_11:
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Invalid Context",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v45,
               v57,
               v58,
               v59,
               v60,
               v61,
               v62);
    goto LABEL_12;
  }
  v15 = (_QWORD *)context;
  is_mlo_in_mode_emlsr = policy_mgr_is_mlo_in_mode_emlsr(a1, (__int64)&v58, (unsigned __int8 *)&v57 + 4);
  result = qdf_trace_msg(
             0x4Fu,
             8u,
             "%s: num_mlo %d is_mlo_emlsr %d conc_con_coming_up: %d",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             "policy_mgr_handle_emlsr_sta_concurrency",
             BYTE4(v57),
             is_mlo_in_mode_emlsr & 1,
             a2 & 1);
  if ( (is_mlo_in_mode_emlsr & 1) == 0 )
    goto LABEL_12;
  if ( BYTE4(v57) > 1u )
    goto LABEL_7;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: conc_con_coming_up %d num mlo sta links %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "policy_mgr_handle_emlsr_sta_concurrency",
    a2 & 1);
  policy_mgr_get_ml_sta_info(v15, (_BYTE *)&v57 + 4, &v57, (__int64)&v58, (__int64)&v59, nullptr, 0, 0);
  v34 = policy_mgr_get_context(a1);
  if ( !v34 )
  {
    v45 = "policy_mgr_get_connection_count";
    goto LABEL_11;
  }
  v35 = v34;
  qdf_mutex_acquire(v34 + 56);
  v36 = BYTE4(qword_8D4F24) + BYTE4(qword_8D4F00) + BYTE4(qword_8D4F48) + BYTE4(qword_8D4F6C) + BYTE4(qword_8D4F90);
  result = qdf_mutex_release(v35 + 56);
  if ( v36 == 1 && (_BYTE)v57 )
  {
LABEL_7:
    if ( (a2 & 1) != 0 )
    {
      policy_mgr_restore_no_force(a1, BYTE4(v57), &v58, 1);
LABEL_9:
      updated = policy_mgr_update_emlsr_inactive_request(a1, BYTE4(v57), &v58, 0);
      result = policy_mgr_mlo_sta_set_link_ext(
                 a1,
                 1u,
                 4u,
                 BYTE4(v57),
                 (unsigned __int8 *)&v58,
                 0,
                 0,
                 updated,
                 v38,
                 v39,
                 v40,
                 v41,
                 v42,
                 v43,
                 v44);
      goto LABEL_12;
    }
    if ( (a3 & 1) == 0 )
      goto LABEL_12;
    v46 = policy_mgr_get_context(a1);
    if ( v46 )
    {
      v55 = v46;
      qdf_mutex_acquire(v46 + 56);
      v56 = BYTE4(qword_8D4F24) + BYTE4(qword_8D4F00) + BYTE4(qword_8D4F48) + BYTE4(qword_8D4F6C) + BYTE4(qword_8D4F90);
      qdf_mutex_release(v55 + 56);
      if ( v56 > 2 )
        goto LABEL_9;
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid Context",
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        "policy_mgr_get_connection_count");
    }
    policy_mgr_update_emlsr_inactive_request(a1, BYTE4(v57), &v58, 1);
    result = policy_mgr_restore_no_force(a1, BYTE4(v57), &v58, 0);
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
