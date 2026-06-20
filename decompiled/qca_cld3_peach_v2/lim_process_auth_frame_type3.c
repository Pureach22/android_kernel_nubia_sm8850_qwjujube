__int64 __fastcall lim_process_auth_frame_type3(
        __int64 result,
        __int64 a2,
        unsigned __int16 *a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v14; // x4
  __int64 v17; // x21
  __int64 v18; // x22
  __int16 v19; // w9
  __int64 v20; // x23
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x25
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  char v43; // w8

  v14 = *a3;
  v17 = result;
  if ( (_DWORD)v14 == 1 )
  {
    if ( *(_DWORD *)(a5 + 88) != 1 )
      return result;
    v18 = a2 + 10;
    if ( (*(_WORD *)a2 & 0x4000) != 0 )
    {
      v25 = lim_search_pre_auth_list(result, a2 + 10);
      if ( v25 )
      {
        if ( *(_DWORD *)(v25 + 20) == 8 )
        {
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: auth response timer timedout for peer %02x:%02x:%02x:**:**:%02x",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "lim_process_auth_frame_type3",
            *(unsigned __int8 *)(a2 + 10),
            *(unsigned __int8 *)(a2 + 11),
            *(unsigned __int8 *)(a2 + 12),
            *(unsigned __int8 *)(a2 + 15));
          *(_DWORD *)a4 = 262145;
          *(_WORD *)(a4 + 4) = 16;
          lim_send_auth_mgmt_frame(v17, a4, a2 + 10, 0, a5);
          return lim_delete_pre_auth_node(v17, a2 + 10);
        }
        if ( a3[2] )
          return qdf_trace_msg(
                   0x35u,
                   2u,
                   "%s: rx Auth frm3 from peer with status code %d %02x:%02x:%02x:**:**:%02x",
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   v32,
                   v33,
                   "lim_process_auth_frame_type3",
                   *(unsigned __int8 *)(a2 + 15));
        v34 = v25;
        if ( (unsigned int)qdf_mem_cmp(a3 + 4, (const void *)(v25 + 25), 0x80u) )
        {
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: Challenge failure for peer %02x:%02x:%02x:**:**:%02x",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "lim_process_auth_frame_type3",
            *(unsigned __int8 *)(a2 + 10),
            *(unsigned __int8 *)(a2 + 11),
            *(unsigned __int8 *)(a2 + 12),
            *(unsigned __int8 *)(a2 + 15));
          *(_WORD *)a4 = *a3;
          *(_DWORD *)(a4 + 2) = 983044;
        }
        else
        {
          lim_deactivate_and_change_per_sta_id_timer(v17, 9, *(unsigned __int8 *)(v34 + 24));
          v43 = *(_BYTE *)(v34 + 278);
          *(_DWORD *)(v34 + 20) = 9;
          *(_BYTE *)(v34 + 278) = v43 & 0xFE;
          *(_DWORD *)a4 = 262145;
          *(_WORD *)(a4 + 4) = 0;
        }
        goto LABEL_11;
      }
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: received AuthFrame3 from peer that has no preauth context %02x:%02x:%02x:**:**:%02x",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "lim_process_auth_frame_type3",
        *(unsigned __int8 *)(a2 + 10),
        *(unsigned __int8 *)(a2 + 11),
        *(unsigned __int8 *)(a2 + 12),
        *(unsigned __int8 *)(a2 + 15));
      v19 = 14;
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: received Auth frame3 from peer with no WEP bit set %02x:%02x:%02x:**:**:%02x",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "lim_process_auth_frame_type3",
        *(unsigned __int8 *)(a2 + 10),
        *(unsigned __int8 *)(a2 + 11),
        *(unsigned __int8 *)(a2 + 12),
        *(unsigned __int8 *)(a2 + 15));
      v19 = 15;
    }
    *(_DWORD *)a4 = 262145;
    *(_WORD *)(a4 + 4) = v19;
LABEL_11:
    v21 = v17;
    v22 = a4;
    v23 = v18;
    return lim_send_auth_mgmt_frame(v21, v22, v23, 0, a5);
  }
  v20 = a2 + 10;
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: rx Auth frame3 from peer with auth algo number %d %02x:%02x:%02x:**:**:%02x",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "lim_process_auth_frame_type3",
    v14,
    *(unsigned __int8 *)(a2 + 10),
    *(unsigned __int8 *)(a2 + 11),
    *(unsigned __int8 *)(a2 + 12),
    *(unsigned __int8 *)(a2 + 15));
  v21 = v17;
  *(_WORD *)(a4 + 4) = 14;
  v22 = a4;
  *(_DWORD *)a4 = 262145;
  v23 = v20;
  return lim_send_auth_mgmt_frame(v21, v22, v23, 0, a5);
}
