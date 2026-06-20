__int64 __fastcall ml_nlink_t2lm_event_handler(
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
  bool is_mld_sta; // w8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x22
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x23
  unsigned int v44; // w22
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x21
  __int64 v70; // [xsp+0h] [xbp-20h] BYREF
  __int64 v71; // [xsp+8h] [xbp-18h]
  __int64 v72; // [xsp+10h] [xbp-10h]
  __int64 v73; // [xsp+18h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOWORD(v72) = 0;
  v70 = 0;
  v71 = 0;
  is_mld_sta = mlo_is_mld_sta(a2, a4, a5, a6, a7, a8, a9, a10, a11);
  result = 0;
  if ( !is_mld_sta )
    goto LABEL_12;
  if ( !a1 || (v24 = *(_QWORD *)(a1 + 2800)) == 0 || (v25 = *(_QWORD *)(v24 + 16)) == 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Invalid WMI handle",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "ml_is_nlink_service_supported",
      v70,
      v71,
      v72,
      v73);
    goto LABEL_10;
  }
  if ( (wmi_service_enabled(v25, 0x129u, v15, v16, v17, v18, v19, v20, v21, v22) & 1) == 0 )
  {
LABEL_10:
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: nlink srv not supported",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "ml_nlink_t2lm_event_handler",
      v70);
LABEL_11:
    result = 0;
    goto LABEL_12;
  }
  v34 = *(_QWORD *)(a2 + 1360);
  if ( v34 && *(_QWORD *)(v34 + 2224) )
  {
    qdf_mutex_acquire(v34 + 1656);
    qdf_mem_copy(&v70, (const void *)(*(_QWORD *)(v34 + 2224) + 1348LL), 0x12u);
    qdf_mutex_release(v34 + 1656);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_ctx or sta_ctx null",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "ml_nlink_get_curr_force_state",
      v70,
      v71,
      v72,
      v73);
  }
  v43 = *(_QWORD *)(a2 + 1360);
  if ( v43 && *(_QWORD *)(v43 + 2224) )
  {
    qdf_mutex_acquire(v43 + 1656);
    v44 = *(unsigned __int16 *)(*(_QWORD *)(v43 + 2224) + 1418LL);
    qdf_mutex_release(v43 + 1656);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_ctx or sta_ctx null",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "ml_nlink_get_force_link_request",
      v70);
    v44 = 0;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: t2lm mapped link_bitmap 0x%x curr inactive 0x%x vendor cmd inactive 0x%x",
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    "ml_nlink_t2lm_event_handler",
    *a3,
    WORD1(v70),
    v44,
    v70);
  if ( (*a3 & v44) == 0 )
    goto LABEL_11;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: t2lm mapped link_bitmap 0x%x inactive hold by vendor cmd, 0x%x",
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    "ml_nlink_t2lm_event_handler");
  v69 = *(_QWORD *)(a2 + 1360);
  if ( v69 && *(_QWORD *)(v69 + 2224) )
  {
    qdf_mutex_acquire(v69 + 1656);
    qdf_mem_set((void *)(*(_QWORD *)(v69 + 2224) + 1408LL), 0x14u, 0);
    qdf_mutex_release(v69 + 1656);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_ctx or sta_ctx null",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "ml_nlink_clr_force_link_request");
  }
  LODWORD(result) = ml_nlink_state_change(a1, 1, 26, a3);
  if ( (_DWORD)result == 24 )
    result = 0;
  else
    result = (unsigned int)result;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
