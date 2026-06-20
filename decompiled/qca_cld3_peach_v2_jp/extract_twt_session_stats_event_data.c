__int64 __fastcall extract_twt_session_stats_event_data(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        unsigned int a13)
{
  __int64 v13; // x8
  int v14; // w10
  unsigned int v16; // w9
  int v17; // w10
  int v18; // w11
  int v19; // w12
  int v20; // w13
  int v21; // w14
  int v22; // w15
  int v23; // w16
  int v24; // w8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v34; // [xsp+0h] [xbp-50h]
  int v35; // [xsp+8h] [xbp-48h]
  int v36; // [xsp+10h] [xbp-40h]
  int v37; // [xsp+18h] [xbp-38h]
  int v38; // [xsp+20h] [xbp-30h]
  int v39; // [xsp+28h] [xbp-28h]
  int v40; // [xsp+30h] [xbp-20h]
  int v41; // [xsp+38h] [xbp-18h]
  int v42; // [xsp+40h] [xbp-10h]

  if ( a10 )
  {
    if ( *(_DWORD *)(a10 + 24) >= a13 )
    {
      v13 = *(_QWORD *)(a10 + 16) + 56LL * a13;
      if ( v13 )
      {
        v14 = *(_DWORD *)(a12 + 16);
        *(_DWORD *)a12 = *(_DWORD *)(v13 + 4);
        *(_WORD *)(a12 + 4) = *(_DWORD *)(v13 + 8);
        *(_BYTE *)(a12 + 6) = *(_WORD *)(v13 + 10);
        *(_BYTE *)(a12 + 7) = *(_BYTE *)(v13 + 11);
        *(_WORD *)(a12 + 8) = *(_DWORD *)(v13 + 12);
        *(_DWORD *)(a12 + 12) = *(_DWORD *)(v13 + 16);
        v16 = *(_DWORD *)(v13 + 20);
        *(_DWORD *)(a12 + 16) = v14 & 0xFF800000 | v16 & 0x7FFFFF;
        v17 = *(_DWORD *)(v13 + 24);
        *(_DWORD *)(a12 + 20) = v17;
        v18 = *(_DWORD *)(v13 + 28);
        *(_DWORD *)(a12 + 24) = v18;
        v19 = *(_DWORD *)(v13 + 32);
        *(_DWORD *)(a12 + 28) = v19;
        v20 = *(_DWORD *)(v13 + 36);
        *(_DWORD *)(a12 + 32) = v20;
        v21 = *(_DWORD *)(v13 + 40);
        *(_DWORD *)(a12 + 36) = v21;
        v22 = *(_DWORD *)(v13 + 44);
        *(_DWORD *)(a12 + 40) = v22;
        v23 = *(_DWORD *)(v13 + 48);
        *(_DWORD *)(a12 + 44) = v23;
        v24 = *(_DWORD *)(v13 + 52);
        *(_DWORD *)(a12 + 48) = v24;
        v42 = v24;
        v41 = v23;
        v40 = v22;
        v39 = v21;
        v38 = v20;
        v37 = v19;
        v36 = v18;
        v35 = v17;
        v34 = (v16 >> 18) & 1;
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: type=%d id=%d bcast=%d trig=%d announ=%d diagid=%d wake_dur=%ul wake_int=%ul offset=%ul sp_tsf_us_lo=%ul s"
          "p_tsf_us_hi=%ul curr_tsf_us_lo=%ul curr_tsf_us_hi=%ul",
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          "extract_twt_session_stats_event_data",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42);
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: resp_pm_valid=%d resp_pm=%d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "extract_twt_session_stats_event_data",
          (*(_DWORD *)(a12 + 16) >> 21) & 1,
          (*(_DWORD *)(a12 + 16) >> 22) & 1);
        return 0;
      }
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: twt_session stats not present for idx %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_twt_session_stats_event_data");
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: wrong idx, idx=%d, num_sessions=%d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_twt_session_stats_event_data");
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: evt_buf is NULL",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_twt_session_stats_event_data");
  }
  return 4;
}
