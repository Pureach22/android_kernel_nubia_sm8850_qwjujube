__int64 __fastcall rrm_process_chan_load_report_xmit(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 v10; // x19
  __int64 result; // x0
  __int64 v13; // x23
  __int16 v15; // w8
  __int64 session_by_bssid; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x21
  char v36; // w8
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
  unsigned __int8 v53[4]; // [xsp+2Ch] [xbp-14h] BYREF
  int v54; // [xsp+30h] [xbp-10h] BYREF
  __int16 v55; // [xsp+34h] [xbp-Ch]
  __int64 v56; // [xsp+38h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53[0] = 0;
  v55 = 0;
  v54 = 0;
  if ( !a2 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Received chan_load_xmit_ind is NULL in PE",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "rrm_process_chan_load_report_xmit");
    goto LABEL_14;
  }
  v10 = *(unsigned __int8 *)(a2 + 4);
  if ( v10 < 5 )
  {
    v13 = *(_QWORD *)(a1 + 8 * v10 + 20232);
    if ( v13 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Received chan load report xmit indication on idx:%d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "rrm_process_chan_load_report_xmit",
        *(unsigned __int8 *)(a2 + 4));
      v15 = *(_WORD *)(a1 + 544LL * (unsigned int)v10 + 17494);
      v54 = *(_DWORD *)(a1 + 544LL * (unsigned int)v10 + 17490);
      v55 = v15;
      session_by_bssid = pe_find_session_by_bssid(a1, (unsigned __int8 *)&v54, v53);
      if ( session_by_bssid )
      {
        v25 = session_by_bssid;
        if ( (*(_BYTE *)(a2 + 32) & 1) == 0 )
        {
          result = ((__int64 (__fastcall *)(__int64, __int64, int *, __int64, _QWORD))rrm_process_chan_load_request_failure)(
                     a1,
                     session_by_bssid,
                     &v54,
                     2,
                     (unsigned int)v10);
          goto LABEL_14;
        }
        v26 = _qdf_mem_malloc(0x108u, "rrm_process_chan_load_report_xmit", 2289);
        v35 = v26;
        if ( v26 )
        {
          v36 = *(_BYTE *)(a2 + 12);
          *(_WORD *)(v26 + 1) = 0;
          *(_BYTE *)v26 = v36;
          *(_BYTE *)(v26 + 3) = 3;
          *(_BYTE *)(v26 + 8) = *(_BYTE *)(a2 + 14);
          *(_BYTE *)(v26 + 9) = *(_BYTE *)(a2 + 15);
          *(_QWORD *)(v26 + 16) = *(_QWORD *)(a2 + 24);
          *(_WORD *)(v26 + 24) = *(_WORD *)(a2 + 16);
          *(_BYTE *)(v26 + 26) = *(_BYTE *)(a2 + 18);
          qdf_mem_copy((void *)(v26 + 27), (const void *)(a2 + 36), 4u);
          qdf_mem_copy((void *)(v35 + 31), (const void *)(a2 + 44), 4u);
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: send chan load report for bssId:%02x:%02x:%02x:**:**:%02x reg_class:%d, channel:%d, measStartTime:%lu, m"
            "easDuration:%d, chan_load:%d",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "rrm_process_chan_load_report_xmit",
            (unsigned __int8)v54,
            BYTE1(v54),
            BYTE2(v54),
            HIBYTE(v55),
            *(unsigned __int8 *)(v35 + 8),
            *(unsigned __int8 *)(v35 + 9),
            *(_QWORD *)(v35 + 16),
            *(unsigned __int16 *)(v35 + 24),
            *(unsigned __int8 *)(v35 + 26));
          lim_send_radio_measure_report_action_frame(a1, *(_BYTE *)(v13 + 1), 1u, 1, v35, (unsigned __int8 *)&v54, v25);
        }
        goto LABEL_13;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: NULL session for bssId %02x:%02x:%02x:**:**:%02x",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "rrm_process_chan_load_report_xmit",
        (unsigned __int8)v54,
        BYTE1(v54),
        BYTE2(v54),
        HIBYTE(v55));
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: no request pending in PE",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "rrm_process_chan_load_report_xmit");
    }
    v35 = 0;
LABEL_13:
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Measurement done idx:%d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "rrm_process_chan_load_report_xmit",
      (unsigned int)v10);
    rrm_cleanup(a1, (unsigned int)v10, v45, v46, v47, v48, v49, v50, v51, v52);
    result = _qdf_mem_free(v35);
    goto LABEL_14;
  }
  result = qdf_trace_msg(
             0x35u,
             2u,
             "%s: Received measurement_idx is out of range: %u - %zu",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "rrm_process_chan_load_report_xmit",
             *(unsigned __int8 *)(a2 + 4),
             5);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
