__int64 __fastcall lim_deactivate_timers_for_vdev(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 session_by_vdev_id; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x21
  const char *v23; // x4
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7

  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !session_by_vdev_id )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: pe session invalid for vdev %d",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "lim_deactivate_timers_for_vdev",
             a2);
  v21 = *(unsigned int *)(session_by_vdev_id + 72);
  v22 = session_by_vdev_id;
  if ( (unsigned int)v21 > 0x1C )
    v23 = "INVALID MLM state";
  else
    v23 = off_A0A578[v21];
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: pe limMlmState %s vdev %d",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "lim_deactivate_timers_for_vdev",
             v23,
             a2);
  v33 = *(_DWORD *)(v22 + 72);
  if ( v33 > 9 )
  {
    switch ( v33 )
    {
      case 10:
        result = tx_timer_running(a1 + 280);
        if ( (result & 1) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Trigger Assoc failure timeout for vdev %d",
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            "lim_deactivate_timers_for_vdev",
            a2);
          tx_timer_deactivate(a1 + 280);
          return lim_process_assoc_failure_timeout(a1, 0);
        }
        break;
      case 14:
        if ( *(_BYTE *)(v22 + 7856) == 1 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: pre-auth in progress",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "lim_deactivate_timers_for_vdev");
          result = tx_timer_running(a1 + 1872);
          if ( (result & 1) != 0 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Trigger pre auth timeout for vdev %d",
              v66,
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              "lim_deactivate_timers_for_vdev",
              a2);
            return tx_timer_deactivate(a1 + 1872);
          }
        }
        break;
      case 29:
        result = tx_timer_running(a1 + 3192);
        if ( (result & 1) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Trigger SAE Auth failure timeout for vdev %d",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "lim_deactivate_timers_for_vdev",
            a2);
          tx_timer_deactivate(a1 + 3192);
          return lim_process_sae_auth_timeout(a1);
        }
        break;
    }
  }
  else if ( v33 == 2 )
  {
    result = tx_timer_running(a1 + 1072);
    if ( (result & 1) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Trigger Join failure timeout for vdev %d",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "lim_deactivate_timers_for_vdev",
        a2);
      tx_timer_deactivate(a1 + 1072);
      return lim_process_join_failure_timeout(a1);
    }
  }
  else if ( v33 == 5 || v33 == 7 )
  {
    result = tx_timer_running(a1 + 808);
    if ( (result & 1) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Trigger Auth failure timeout for vdev %d",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "lim_deactivate_timers_for_vdev",
        a2);
      tx_timer_deactivate(a1 + 808);
      return lim_process_auth_failure_timeout(a1);
    }
  }
  return result;
}
