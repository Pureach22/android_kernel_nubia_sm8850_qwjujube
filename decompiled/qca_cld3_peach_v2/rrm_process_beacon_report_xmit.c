__int64 __fastcall rrm_process_beacon_report_xmit(
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
  __int64 v10; // x4
  __int64 result; // x0
  __int64 v13; // x28
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w8
  __int64 session_by_bssid; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x22
  __int64 v34; // x21
  __int64 v35; // x25
  __int64 v36; // x23
  unsigned int v37; // w24
  __int64 v38; // x19
  char v39; // w9
  __int64 v40; // x8
  unsigned __int16 *v41; // x26
  __int64 v42; // x19
  char v43; // w8
  int v44; // w8
  char v45; // w8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x2
  __int64 v55; // x6
  __int64 v56; // x4
  __int64 v57; // x3
  __int64 v58; // x0
  __int64 v59; // x1
  __int64 v60; // x5
  __int64 v61; // x8
  __int64 v62; // x8
  __int64 v63; // x8
  unsigned int v64; // w26
  unsigned int v65; // w22
  char v66; // w3
  unsigned int v67; // w19
  bool v68; // zf
  unsigned __int8 v69; // w24
  bool v70; // zf
  char v71; // w3
  unsigned __int8 v72; // w24
  unsigned __int8 v73; // w22
  bool v74; // zf
  char v75; // w3
  unsigned __int8 v76; // w2
  bool v77; // zf
  char v78; // w3
  __int64 v79; // [xsp+8h] [xbp-38h]
  __int64 v80; // [xsp+18h] [xbp-28h]
  int v81; // [xsp+20h] [xbp-20h]
  unsigned int v82; // [xsp+24h] [xbp-1Ch]
  unsigned __int8 v84; // [xsp+30h] [xbp-10h]
  unsigned __int8 v85[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v86; // [xsp+38h] [xbp-8h]

  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v85[0] = 0;
  if ( !a2 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Received beacon_xmit_ind is NULL in PE",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "rrm_process_beacon_report_xmit");
    result = 16;
    goto LABEL_112;
  }
  v10 = *(unsigned __int8 *)(a2 + 4);
  if ( (unsigned int)v10 >= 5 )
  {
    qdf_trace_msg(
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
      "rrm_process_beacon_report_xmit");
    result = 16;
    goto LABEL_112;
  }
  v13 = *(_QWORD *)(a1 + 8 * v10 + 20232);
  if ( !v13 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Received report xmit while there is no request pending in PE",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "rrm_process_beacon_report_xmit");
LABEL_50:
    v34 = 0;
    v67 = 16;
    goto LABEL_100;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Received beacon report xmit indication on idx:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "rrm_process_beacon_report_xmit");
  v23 = *(unsigned __int8 *)(a2 + 19);
  if ( !*(_BYTE *)(a2 + 19)
    && !*(_BYTE *)(v13 + 296)
    && (!*(_BYTE *)(a2 + 14) || !*(_BYTE *)(v13 + 9) || *(_BYTE *)(a1 + 20230) != 1) )
  {
    v67 = 0;
    v34 = 0;
    goto LABEL_100;
  }
  if ( v23 <= 1 )
    LOBYTE(v23) = 1;
  *(_BYTE *)(a2 + 19) = v23;
  session_by_bssid = pe_find_session_by_bssid(a1, (unsigned __int8 *)(a2 + 5), v85);
  if ( !session_by_bssid )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: TX: [802.11 BCN_RPT] Session does not exist for bssId:%02x:%02x:%02x:**:**:%02x",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "rrm_process_beacon_report_xmit",
      *(unsigned __int8 *)(a2 + 5),
      *(unsigned __int8 *)(a2 + 6),
      *(unsigned __int8 *)(a2 + 7),
      *(unsigned __int8 *)(a2 + 10));
    goto LABEL_50;
  }
  v33 = session_by_bssid;
  v34 = _qdf_mem_malloc(0x2100u, "rrm_process_beacon_report_xmit", 1721);
  if ( !v34 )
  {
    v67 = 2;
    goto LABEL_100;
  }
  v79 = v33;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = a2 + 24;
  v84 = 0;
  v82 = 0;
  v81 = 0;
  v80 = v13;
  while ( v37 < *(unsigned __int8 *)(a2 + 19) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: TX: [802.11 BCN_RPT] report %d bss %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "rrm_process_beacon_report_xmit",
      (unsigned int)v36,
      v37);
    if ( v37 > 7 )
      goto LABEL_113;
    v39 = *(_BYTE *)(a2 + 12);
    v40 = v34 + v35;
    v41 = *(unsigned __int16 **)(v38 + 8LL * v37);
    *(_WORD *)(v40 + 1) = 0;
    *(_BYTE *)v40 = v39;
    *(_BYTE *)(v40 + 3) = 5;
    if ( *(unsigned __int16 *)(a2 + 2) < 0x58u )
      goto LABEL_13;
    *(_BYTE *)(v40 + 8) = *(_BYTE *)(a2 + 18);
    if ( v41 )
    {
      v42 = v34 + v35;
      *(_BYTE *)(v34 + v35 + 9) = wlan_reg_freq_to_chan(
                                    *(_QWORD *)(a1 + 21632),
                                    *((_DWORD *)v41 + 7),
                                    v15,
                                    v16,
                                    v17,
                                    v18,
                                    v19,
                                    v20,
                                    v21,
                                    v22);
      qdf_mem_copy((void *)(v34 + v35 + 10), v41 + 18, 8u);
      *(_BYTE *)(v42 + 18) = *(_BYTE *)(a2 + 16);
      v43 = *((_DWORD *)v41 + 5);
      *(_WORD *)(v42 + 20) = 1;
      *(_BYTE *)(v42 + 19) = v43;
      v44 = *((char *)v41 + 24);
      if ( v44 >= -109 )
      {
        if ( v44 <= 0 )
          v45 = 2 * v44 - 36;
        else
          v45 = -36;
      }
      else
      {
        v45 = 0;
      }
      *(_BYTE *)(v42 + 22) = v45;
      *(_BYTE *)(v42 + 29) = 0;
      *(_DWORD *)(v42 + 32) = *((_DWORD *)v41 + 8);
      qdf_mem_copy((void *)(v42 + 23), v41 + 1, 6u);
      v38 = a2 + 24;
      v13 = v80;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: TX: [802.11 BCN_RPT] reporting detail requested %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "rrm_process_beacon_report_xmit",
      *(unsigned __int8 *)(v13 + 8));
    if ( !*(_BYTE *)(v13 + 8) )
      goto LABEL_31;
    if ( *(_BYTE *)(v13 + 8) == 1 )
    {
      if ( v41 )
      {
        v54 = *(_QWORD *)(v13 + 24);
        v55 = *(unsigned __int8 *)(v13 + 33);
        v56 = *(unsigned __int8 *)(v13 + 32);
        v57 = *(unsigned __int8 *)(v13 + 16);
        v58 = v34 + v35 + 42;
        v59 = v34 + v35 + 36;
        v60 = v13 + 34;
LABEL_30:
        v81 = rrm_fill_beacon_ies(v58, v59, v54, v57, v56, v60, v55, v82, v41, v79);
LABEL_31:
        v61 = v34 + v35;
        *(_BYTE *)(v61 + 39) = v37;
        *(_BYTE *)(v61 + 40) = v84;
        if ( v41 && (_WORD)v81 && *(_BYTE *)(v13 + 9) )
        {
          v62 = *v41;
          v82 = v62 - 102 - v81;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: TX: [802.11 BCN_RPT] offset %d ie_len %lu rem_len %d frag_id %d",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "rrm_process_beacon_report_xmit",
            (unsigned __int16)(v62 - 102 - v81),
            v62 - 102,
            (unsigned __int16)v81,
            v84++);
          *(_BYTE *)(v34 + v35 + 41) = 1;
          if ( !*(_BYTE *)(v13 + 9) )
            goto LABEL_13;
LABEL_38:
          *(_BYTE *)(v34 + v35 + 37) = 1;
          goto LABEL_13;
        }
        goto LABEL_37;
      }
    }
    else if ( v41 )
    {
      v54 = 0;
      v57 = 0;
      v58 = v34 + v35 + 42;
      v59 = v34 + v35 + 36;
      v56 = 0;
      v60 = 0;
      v55 = 0;
      goto LABEL_30;
    }
    v63 = v34 + v35;
    *(_BYTE *)(v63 + 39) = v37;
    *(_BYTE *)(v63 + 40) = v84;
LABEL_37:
    *(_BYTE *)(v34 + v35 + 41) = 0;
    ++v37;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: TX: [802.11 BCN_RPT] No remaining IEs",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "rrm_process_beacon_report_xmit");
    v82 = 0;
    v84 = 0;
    if ( *(_BYTE *)(v13 + 9) )
      goto LABEL_38;
LABEL_13:
    ++v36;
    v35 += 264;
    if ( v36 == 32 )
      break;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: TX: [802.11 BCN_RPT] Total reports filled %d, last bcn_rpt ind:%d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "rrm_process_beacon_report_xmit",
    (unsigned int)v36,
    *(unsigned __int8 *)(v13 + 9));
  if ( 264 * (int)v36 % 0x900u )
    v64 = 264 * (int)v36 / 0x900u + 1;
  else
    v64 = 264 * (int)v36 / 0x900u;
  if ( v64 )
  {
    v65 = (unsigned int)v36 >= 8 ? 8 : v36;
    if ( v64 == 1 )
    {
      v68 = *(_BYTE *)(a2 + 14) && *(_BYTE *)(a1 + 20230) == 1;
      v66 = v68;
    }
    else
    {
      v66 = 0;
    }
    lim_send_radio_measure_report_action_frame(a1, *(_BYTE *)(v13 + 1), v65, v66, v34, (unsigned __int8 *)(a2 + 5), v79);
    if ( v64 != 1 )
    {
      v69 = (unsigned int)v36 - v65 >= 8 ? 8 : v36 - v65;
      if ( v64 == 2 )
      {
        v70 = *(_BYTE *)(a2 + 14) && *(_BYTE *)(a1 + 20230) == 1;
        v71 = v70;
      }
      else
      {
        v71 = 0;
      }
      lim_send_radio_measure_report_action_frame(
        a1,
        *(_BYTE *)(v13 + 1),
        v69,
        v71,
        v34 + 264LL * v65,
        (unsigned __int8 *)(a2 + 5),
        v79);
      if ( v64 != 2 )
      {
        v72 = v65 + v69;
        v73 = (unsigned int)v36 - v72 >= 8 ? 8 : v36 - v72;
        if ( v64 == 3 )
        {
          v74 = *(_BYTE *)(a2 + 14) && *(_BYTE *)(a1 + 20230) == 1;
          v75 = v74;
        }
        else
        {
          v75 = 0;
        }
        lim_send_radio_measure_report_action_frame(
          a1,
          *(_BYTE *)(v13 + 1),
          v73,
          v75,
          v34 + 264LL * v72,
          (unsigned __int8 *)(a2 + 5),
          v79);
        if ( v64 != 3 )
        {
          if ( (unsigned int)v36 - (unsigned __int8)(v72 + v73) >= 8 )
            v76 = 8;
          else
            v76 = v36 - (v72 + v73);
          if ( v64 == 4 )
          {
            if ( *(_BYTE *)(a2 + 14) )
              v77 = *(_BYTE *)(a1 + 20230) == 1;
            else
              v77 = 0;
            v78 = v77;
          }
          else
          {
            v78 = 0;
          }
          lim_send_radio_measure_report_action_frame(
            a1,
            *(_BYTE *)(v13 + 1),
            v76,
            v78,
            v34 + 264LL * (unsigned __int8)(v72 + v73),
            (unsigned __int8 *)(a2 + 5),
            v79);
        }
      }
    }
  }
  v67 = 0;
  *(_BYTE *)(v13 + 296) = 0;
LABEL_100:
  if ( *(_BYTE *)(a2 + 19) )
  {
    _qdf_mem_free(*(_QWORD *)(a2 + 24));
    if ( *(unsigned __int8 *)(a2 + 19) >= 2u )
    {
      _qdf_mem_free(*(_QWORD *)(a2 + 32));
      if ( *(unsigned __int8 *)(a2 + 19) >= 3u )
      {
        _qdf_mem_free(*(_QWORD *)(a2 + 40));
        if ( *(unsigned __int8 *)(a2 + 19) >= 4u )
        {
          _qdf_mem_free(*(_QWORD *)(a2 + 48));
          if ( *(unsigned __int8 *)(a2 + 19) >= 5u )
          {
            _qdf_mem_free(*(_QWORD *)(a2 + 56));
            if ( *(unsigned __int8 *)(a2 + 19) >= 6u )
            {
              _qdf_mem_free(*(_QWORD *)(a2 + 64));
              if ( *(unsigned __int8 *)(a2 + 19) >= 7u )
              {
                _qdf_mem_free(*(_QWORD *)(a2 + 72));
                if ( *(unsigned __int8 *)(a2 + 19) >= 8u )
                {
                  _qdf_mem_free(*(_QWORD *)(a2 + 80));
                  if ( *(unsigned __int8 *)(a2 + 19) > 8u )
LABEL_113:
                    __break(0x5512u);
                }
              }
            }
          }
        }
      }
    }
  }
  if ( *(_BYTE *)(a2 + 14) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Measurement done idx:%d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "rrm_process_beacon_report_xmit",
      *(unsigned __int8 *)(a2 + 4));
    rrm_cleanup(a1, *(unsigned __int8 *)(a2 + 4));
  }
  _qdf_mem_free(v34);
  result = v67;
LABEL_112:
  _ReadStatusReg(SP_EL0);
  return result;
}
