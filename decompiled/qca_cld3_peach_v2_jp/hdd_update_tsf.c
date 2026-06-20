__int64 __fastcall hdd_update_tsf(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x23
  unsigned __int64 StatusReg; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned __int64 v12; // x6
  signed int v13; // w20
  unsigned __int64 v14; // x7
  unsigned __int64 v15; // x4
  unsigned __int64 v16; // x5
  unsigned __int64 v17; // x9
  char v18; // w24
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x10
  bool v21; // cc
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  _QWORD *v32; // x21
  int v33; // w8
  bool v34; // nf
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x8
  __int64 v61; // x4
  __int64 v62; // x5
  __int64 v63; // x6
  __int64 v64; // x7
  __int64 v65; // x1
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x8

  if ( !result )
    return result;
  v1 = result;
  v2 = result + 36864;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(result + 39160);
  }
  else
  {
    raw_spin_lock_bh(result + 39160);
    *(_QWORD *)(v2 + 2304) |= 1uLL;
  }
  v12 = *(_QWORD *)(v2 + 2072);
  v13 = 0;
  if ( v12 )
  {
    v14 = *(_QWORD *)(v2 + 2080);
    if ( v14 )
    {
      v15 = *(_QWORD *)(v2 + 2504);
      v16 = *(_QWORD *)(v2 + 2088);
      if ( !(v16 | v15) )
      {
        v13 = 1;
        goto LABEL_22;
      }
      if ( v12 <= v15 || (v17 = v14 - v16, v14 <= v16) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid timestamps!last_target_time: %llu;last_sync_time: %llu; cur_target_time: %llu;cur_sync_time: %llu",
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          "hdd_check_timestamp_status");
LABEL_19:
        if ( *(_DWORD *)(v2 + 2520) )
          v13 = 2;
        else
          v13 = 1;
        goto LABEL_22;
      }
      v18 = *(_BYTE *)(v2 + 2481);
      v19 = 1000 * (v12 - v15);
      v20 = v17 - v19;
      v21 = v19 > v17;
      v22 = v19 - v17;
      if ( v21 )
        v23 = v22;
      else
        v23 = v20;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: timestamps deviation - delta: %llu ns",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "hdd_check_timestamp_status",
        v23);
      v13 = 1;
      if ( v23 >= 0x186A1 && (v18 & 1) == 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Invalid timestamps - delta: %llu ns",
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          "hdd_check_timestamp_status",
          v23);
        goto LABEL_19;
      }
    }
  }
LABEL_22:
  if ( *(_BYTE *)(v2 + 2481) == 1 )
    *(_BYTE *)(v2 + 2481) = 0;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: sync_status %d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "hdd_update_timestamp",
    (unsigned int)v13);
  if ( v13 )
  {
    v32 = (_QWORD *)(v2 + 2072);
    if ( v13 != 1 )
    {
      v33 = *(_DWORD *)(v2 + 2512) + 1;
      v34 = *(_DWORD *)(v2 + 2512) - 1 < 0;
      *(_DWORD *)(v2 + 2512) = v33;
      if ( v34 ^ __OFSUB__(v33, 2) | (v33 == 2) )
      {
        if ( (unsigned int)qdf_mc_timer_get_current_state(v1 + 38976) == 18 )
          qdf_trace_msg(
            0x33u,
            3u,
            "%s: invalid timer status",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "hdd_update_timestamp");
        else
          qdf_mc_timer_stop(v1 + 38976);
        v74 = *(_QWORD *)(v1 + 24);
        v13 = 100;
        *(_QWORD *)(v74 + 3240) = 0;
        *(_DWORD *)(v74 + 3236) = 0;
        *(_QWORD *)(v2 + 2488) = 0;
        *v32 = 0;
        *(_QWORD *)(v2 + 2080) = 0;
        v43 = *(_QWORD *)(v2 + 2304);
        if ( (v43 & 1) == 0 )
        {
LABEL_41:
          result = raw_spin_unlock(v1 + 39160);
          if ( v13 < 1 )
            return result;
          return qdf_mc_timer_start(v1 + 39176, v13);
        }
        goto LABEL_46;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Reach the max continuous error count",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "hdd_update_timestamp");
    }
    if ( (unsigned int)qdf_mc_timer_get_current_state(v1 + 38976) == 18 )
      qdf_trace_msg(
        0x33u,
        3u,
        "%s: invalid timer status",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "hdd_update_timestamp");
    else
      qdf_mc_timer_stop(v1 + 38976);
    v60 = *(_QWORD *)(v1 + 24);
    *(_QWORD *)(v60 + 3240) = 0;
    *(_DWORD *)(v60 + 3236) = 0;
    v61 = *(_QWORD *)(v2 + 2072);
    v62 = *(_QWORD *)(v2 + 2096);
    v63 = *(_QWORD *)(v2 + 2080);
    v64 = *(_QWORD *)(v2 + 2488);
    *(_QWORD *)(v2 + 2488) = 0;
    *(_QWORD *)(v2 + 2504) = v61;
    *(_QWORD *)(v2 + 2104) = v62;
    *(_QWORD *)(v2 + 2088) = v63;
    *(_QWORD *)(v2 + 2496) = v64;
    *(_QWORD *)(v2 + 2096) = 0;
    *v32 = 0;
    *(_QWORD *)(v2 + 2080) = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: ts-pair updated: target: %llu; g_target:%llu, Qtime: %llu, hosttime:%llu",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "hdd_update_timestamp");
    qdf_event_set((__int64)&tsf_sync_get_completion_evt, v65);
    if ( *(_DWORD *)(v2 + 2520) )
    {
      if ( *(_DWORD *)(v2 + 2484) )
        v13 = *(_DWORD *)(v2 + 2484);
      else
        v13 = 3000;
    }
    else
    {
      v13 = 0;
    }
    *(_QWORD *)(v2 + 2512) = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: ts-pair updated: interval: %d",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "hdd_update_timestamp",
      (unsigned int)v13);
    v43 = *(_QWORD *)(v2 + 2304);
    if ( (v43 & 1) == 0 )
      goto LABEL_41;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: TS status is waiting due to one or more pair not updated",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "hdd_update_timestamp");
    v43 = *(_QWORD *)(v2 + 2304);
    if ( (v43 & 1) == 0 )
      goto LABEL_41;
  }
LABEL_46:
  *(_QWORD *)(v2 + 2304) = v43 & 0xFFFFFFFFFFFFFFFELL;
  result = raw_spin_unlock_bh(v1 + 39160);
  if ( v13 >= 1 )
    return qdf_mc_timer_start(v1 + 39176, v13);
  return result;
}
