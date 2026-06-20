unsigned __int8 *__fastcall lim_pmf_sa_query_timer_handler(
        __int64 a1,
        unsigned int a2,
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
  __int64 session_by_session_id; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  unsigned __int8 *result; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x19
  unsigned int v40; // w8
  unsigned __int8 v41; // w9
  __int64 v42; // x4
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  char v59; // w8
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7

  qdf_trace_msg(
    0x35u,
    8u,
    "%s: SA Query timer fires",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_pmf_sa_query_timer_handler");
  session_by_session_id = pe_find_session_by_session_id(a1, a2, v12, v13, v14, v15, v16, v17, v18, v19);
  if ( !session_by_session_id )
    return (unsigned __int8 *)qdf_trace_msg(
                                0x35u,
                                2u,
                                "%s: Session does not exist for given session ID: %d",
                                v21,
                                v22,
                                v23,
                                v24,
                                v25,
                                v26,
                                v27,
                                v28,
                                "lim_pmf_sa_query_timer_handler",
                                (unsigned __int8)a2);
  v29 = session_by_session_id;
  result = (unsigned __int8 *)dph_get_hash_entry(a1, HIWORD(a2), session_by_session_id + 360);
  if ( !result )
    return (unsigned __int8 *)qdf_trace_msg(
                                0x35u,
                                2u,
                                "%s: Entry does not exist for given peer index: %d",
                                v31,
                                v32,
                                v33,
                                v34,
                                v35,
                                v36,
                                v37,
                                v38,
                                "lim_pmf_sa_query_timer_handler",
                                HIWORD(a2));
  v39 = (__int64)result;
  if ( result[644] != 2 )
    return result;
  v40 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 1043LL);
  v41 = result[645] + 1;
  result[645] = v41;
  if ( v40 <= v41 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: SA Query timed out,Deleting STA: %02x:%02x:%02x:**:**:%02x",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "lim_pmf_sa_query_timer_handler",
      result[350],
      result[351],
      result[352],
      result[355]);
    lim_send_disassoc_mgmt_frame(a1, 4u, (const void *)(v39 + 350), v29, 0, v60, v61, v62, v63, v64, v65, v66, v67);
    result = (unsigned __int8 *)lim_trigger_sta_deletion(a1, v39, v29, v68, v69, v70, v71, v72, v73, v74, v75);
    v59 = 3;
  }
  else
  {
    lim_send_sa_query_request_frame(a1, result + 640, result + 350, v29);
    v42 = *(unsigned __int8 *)(v39 + 645);
    ++*(_WORD *)(v39 + 640);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Starting SA Query retry: %d",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "lim_pmf_sa_query_timer_handler",
      v42);
    result = (unsigned __int8 *)tx_timer_activate((char *)(v39 + 376));
    if ( !(_DWORD)result )
      return result;
    result = (unsigned __int8 *)qdf_trace_msg(
                                  0x35u,
                                  2u,
                                  "%s: PMF SA Query timer activation failed!",
                                  v51,
                                  v52,
                                  v53,
                                  v54,
                                  v55,
                                  v56,
                                  v57,
                                  v58,
                                  "lim_pmf_sa_query_timer_handler");
    v59 = 1;
  }
  *(_BYTE *)(v39 + 644) = v59;
  return result;
}
