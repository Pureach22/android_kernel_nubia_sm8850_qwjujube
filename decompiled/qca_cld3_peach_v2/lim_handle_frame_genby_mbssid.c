__int64 __fastcall lim_handle_frame_genby_mbssid(
        __int64 a1,
        int a2,
        unsigned __int8 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x19
  __int64 session_by_bssid; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x20
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w8
  __int64 result; // x0
  __int64 v46; // [xsp+0h] [xbp-50h] BYREF
  __int64 v47; // [xsp+8h] [xbp-48h]
  __int64 v48; // [xsp+10h] [xbp-40h]
  __int64 v49; // [xsp+18h] [xbp-38h]
  __int64 v50; // [xsp+20h] [xbp-30h]
  __int64 v51; // [xsp+28h] [xbp-28h]
  __int64 v52; // [xsp+30h] [xbp-20h]
  __int64 v53; // [xsp+38h] [xbp-18h]
  _BYTE v54[4]; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v55; // [xsp+48h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54[0] = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  context = _cds_get_context(53, (__int64)"lim_handle_frame_genby_mbssid", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !context )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: mac ctx is null",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "lim_handle_frame_genby_mbssid",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53);
    goto LABEL_9;
  }
  v25 = (__int64)context;
  session_by_bssid = pe_find_session_by_bssid(context, a4, v54);
  if ( !session_by_bssid )
  {
LABEL_9:
    result = 4;
    goto LABEL_13;
  }
  v35 = session_by_bssid;
  v48 = a1;
  v49 = a1 + 24;
  LODWORD(v50) = a2;
  LODWORD(v51) = a2 - 24;
  if ( a3 == 80 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Gen Probe rsp frame for critical update feature",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "lim_handle_frame_genby_mbssid",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53);
    lim_process_probe_rsp_frame(v25, &v46, v35);
  }
  else if ( a3 == 128 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Gen beacon frame for critical update feature",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "lim_handle_frame_genby_mbssid",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53);
    v44 = *(_DWORD *)(v35 + 80);
    if ( v44 == 16 || v44 == 10 )
      sch_beacon_process(v25, &v46, v35);
    else
      lim_process_beacon_frame(v25, (__int64)&v46, v35, v36, v37, v38, v39, v40, v41, v42, v43);
  }
  result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
