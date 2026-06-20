__int64 __fastcall lim_deactivate_and_change_timer(__int64 result, int a2)
{
  __int64 v2; // x19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 session_by_session_id; // x0
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
  const char *v28; // x2
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
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
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x0

  v2 = result;
  if ( a2 <= 16 )
  {
    if ( a2 <= 4 )
    {
      if ( a2 == 2 )
      {
        if ( (unsigned int)tx_timer_deactivate(result + 1072) )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Unable to deactivate Join Failure timer",
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            "lim_deactivate_and_change_timer");
        result = tx_timer_change(v2 + 1072, *(unsigned int *)(*(_QWORD *)(v2 + 8) + 3468LL) / 0xAuLL, 0);
        if ( !(_DWORD)result )
          return result;
        v28 = "%s: Unable to change Join Failure timer";
      }
      else
      {
        if ( a2 != 3 )
          return result;
        if ( (unsigned int)tx_timer_deactivate(result + 808) )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Unable to deactivate auth failure timer",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "lim_deactivate_and_change_timer");
        result = tx_timer_change(v2 + 808, *(unsigned int *)(*(_QWORD *)(v2 + 8) + 3480LL) / 0xAuLL, 0);
        if ( !(_DWORD)result )
          return result;
        v28 = "%s: unable to change Auth failure timer";
      }
    }
    else
    {
      if ( a2 == 5 )
      {
        if ( (unsigned int)tx_timer_deactivate(result + 280) )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: unable to deactivate Association failure timer",
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            "lim_deactivate_and_change_timer");
        result = tx_timer_change(v2 + 280, *(unsigned int *)(*(_QWORD *)(v2 + 8) + 3492LL) / 0xAuLL, 0);
        if ( (_DWORD)result )
        {
          v28 = "%s: unable to change Assoc failure timer";
          return qdf_trace_msg(
                   0x35u,
                   2u,
                   v28,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   v25,
                   v26,
                   v27,
                   "lim_deactivate_and_change_timer");
        }
        return result;
      }
      if ( a2 == 11 )
      {
        ++*(_BYTE *)(result + 8877);
        result = tx_timer_deactivate(result + 1344);
        if ( !(_DWORD)result )
          return result;
        v28 = "%s: Unable to deactivate AddtsRsp timer";
        return qdf_trace_msg(0x35u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "lim_deactivate_and_change_timer");
      }
      if ( a2 != 16 )
        return result;
      if ( !(unsigned int)tx_timer_deactivate(result + 2400) )
      {
        v85 = v2 + 2400;
        goto LABEL_57;
      }
      v28 = "%s: Unable to deactivate Disassoc ack timer";
    }
    return qdf_trace_msg(0x35u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "lim_deactivate_and_change_timer");
  }
  if ( a2 > 20 )
  {
    if ( a2 == 21 )
    {
      if ( (unsigned int)tx_timer_deactivate(result + 3192) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Unable to deactivate SAE auth timer",
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          "lim_deactivate_and_change_timer");
      result = tx_timer_change(v2 + 3192, 500, 0);
      if ( (_DWORD)result )
      {
        v28 = "%s: unable to change SAE auth timer";
        return qdf_trace_msg(0x35u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "lim_deactivate_and_change_timer");
      }
      return result;
    }
    if ( a2 == 22 )
    {
      if ( (unsigned int)tx_timer_deactivate(result + 3456) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Unable to deactivate STA STATS RSP timer",
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          "lim_deactivate_and_change_timer");
      result = tx_timer_change(v2 + 3456, 1000, 0);
      if ( (_DWORD)result )
      {
        v28 = "%s: unable to change STA STATS RSP timer";
        return qdf_trace_msg(0x35u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "lim_deactivate_and_change_timer");
      }
      return result;
    }
    if ( a2 != 23 )
      return result;
    if ( (unsigned int)tx_timer_deactivate(result + 3720) )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Unable to deactivate channel vacate timer",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "lim_deactivate_and_change_timer");
    result = tx_timer_change(v2 + 3720, 500, 0);
    if ( !(_DWORD)result )
      return result;
    v28 = "%s: unable to change channel vacate timer";
    return qdf_trace_msg(0x35u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "lim_deactivate_and_change_timer");
  }
  if ( a2 == 17 )
  {
    if ( (unsigned int)tx_timer_deactivate(result + 2664) )
    {
      v28 = "%s: Unable to deactivate Deauth ack timer";
      return qdf_trace_msg(0x35u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "lim_deactivate_and_change_timer");
    }
    v85 = v2 + 2664;
LABEL_57:
    result = tx_timer_change(v85, 100, 0);
    if ( !(_DWORD)result )
      return result;
    v28 = "%s: Unable to change timer";
    return qdf_trace_msg(0x35u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "lim_deactivate_and_change_timer");
  }
  if ( a2 != 18 )
  {
    if ( a2 != 20 )
      return result;
    if ( (unsigned int)tx_timer_deactivate(result + 2928) )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Unable to deactivate Auth Retry timer",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "lim_deactivate_and_change_timer");
    session_by_session_id = pe_find_session_by_session_id(v2, *(_BYTE *)(v2 + 2978), v3, v4, v5, v6, v7, v8, v9, v10);
    if ( !session_by_session_id )
      return qdf_trace_msg(
               0x35u,
               8u,
               "%s: session does not exist for given SessionId : %d",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "lim_deactivate_and_change_timer",
               *(unsigned __int8 *)(v2 + 2978));
    result = tx_timer_change(
               v2 + 2928,
               (85899346 * (unsigned __int64)(3 * (unsigned int)*(unsigned __int16 *)(session_by_session_id + 7158))) >> 32,
               0);
    if ( !(_DWORD)result )
      return result;
    v28 = "%s: Unable to change Auth Retry timer";
    return qdf_trace_msg(0x35u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "lim_deactivate_and_change_timer");
  }
  if ( (unsigned int)tx_timer_deactivate(result + 2136) )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Unable to deactivate periodic join request timer",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "lim_deactivate_and_change_timer");
  result = tx_timer_change(v2 + 2136, *(unsigned int *)(*(_QWORD *)(v2 + 8) + 3472LL) / 0xAuLL, 0);
  if ( (_DWORD)result )
  {
    v28 = "%s: Unable to change periodic join request timer";
    return qdf_trace_msg(0x35u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "lim_deactivate_and_change_timer");
  }
  return result;
}
