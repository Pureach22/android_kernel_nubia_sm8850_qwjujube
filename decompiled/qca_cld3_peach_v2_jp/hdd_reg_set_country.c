__int64 __fastcall hdd_reg_set_country(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int v37; // w24
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 result; // x0
  const char *v47; // x2
  int cc_and_src; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // [xsp+0h] [xbp-10h] BYREF
  __int64 v58; // [xsp+8h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE6(v57) = 0;
  WORD2(v57) = 0;
  BYTE2(v57) = 0;
  LOWORD(v57) = 0;
  if ( !a2 )
  {
    v47 = "%s: country_code is null";
LABEL_12:
    qdf_trace_msg(0x33u, 2u, v47, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_reg_set_country", v57, v58);
    result = 4294967274LL;
    goto LABEL_13;
  }
  if ( (ucfg_reg_is_user_country_set_allowed(*(_QWORD *)a1, a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
  {
    v47 = "%s: user_country is not allowed";
    goto LABEL_12;
  }
  qdf_mem_copy((char *)&v57 + 4, a2, 2u);
  BYTE6(v57) = 0;
  if ( !(unsigned int)qdf_mem_cmp(a2, (const void *)(a1 + 618), 2u)
    && ((cc_and_src = ucfg_reg_get_cc_and_src(*(_QWORD *)a1, &v57, v12, v13, v14, v15, v16, v17, v18, v19),
         cc_and_src == 4)
     || cc_and_src == 2) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: country code is the same",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "hdd_reg_set_country",
      v57,
      v58);
    result = 0;
  }
  else
  {
    qdf_event_reset(a1 + 6928);
    qdf_mutex_acquire(a1 + 6968);
    *(_BYTE *)(a1 + 6924) = 1;
    qdf_mutex_release(a1 + 6968);
    v28 = ucfg_reg_set_country(*(_QWORD *)(a1 + 8), (_BYTE *)&v57 + 4, v20, v21, v22, v23, v24, v25, v26, v27);
    if ( v28 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to set country",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "hdd_reg_set_country",
        v57,
        v58);
      qdf_mutex_acquire(a1 + 6968);
      *(_BYTE *)(a1 + 6924) = 0;
      qdf_mutex_release(a1 + 6968);
    }
    if ( (cds_get_driver_state(v29, v30, v31, v32, v33, v34, v35, v36) & 2) == 0 )
    {
      qdf_mutex_acquire(a1 + 6968);
      v37 = *(unsigned __int8 *)(a1 + 6924);
      qdf_mutex_release(a1 + 6968);
      if ( v37 == 1 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: waiting for channel list to update",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "hdd_reg_wait_for_country_change");
        qdf_wait_for_event_completion(a1 + 6928, 0x1194u);
        qdf_mutex_acquire(a1 + 6968);
        *(_BYTE *)(a1 + 6924) = 0;
        qdf_mutex_release(a1 + 6968);
      }
    }
    result = qdf_status_to_os_return(v28);
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
