__int64 __fastcall lim_process_addba_req(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 **context; // x21
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  unsigned int v25; // w23
  __int64 v26; // x24
  unsigned __int8 *v27; // x25
  __int64 v28; // x19
  __int64 v29; // x19
  unsigned int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _BYTE *v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  _BYTE *v48; // x23
  char is_addba_request_allowed; // w8
  char v50; // w9
  int v51; // w10
  char v52; // w11
  unsigned int v53; // w8
  unsigned int v54; // w9
  int v55; // w8
  unsigned int v56; // w10
  int v57; // w11
  __int64 v58; // x7
  unsigned int v59; // w23
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x8
  _DWORD *v69; // x8
  __int64 v70; // x2
  __int64 v71; // x3
  __int64 v72; // x4
  __int64 v73; // x5
  __int64 v74; // x7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x21
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 v100; // x8
  void (__fastcall *v101)(__int64 **, unsigned __int8 *, __int64, __int64, __int64); // x8
  __int64 v102; // x2
  __int64 v103; // x3
  __int16 v104; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v105; // [xsp+28h] [xbp-8h]

  v105 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = (__int64 **)_cds_get_context(71, (__int64)"lim_process_addba_req", a4, a5, a6, a7, a8, a9, a10, a11);
  v15 = *(_QWORD *)(a3 + 16);
  v104 = 0;
  if ( (mlo_is_any_link_disconnecting(v15) & 1) != 0 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Ignore ADDBA, vdev:%d is in not in conncted state",
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               "lim_process_addba_req",
               *(unsigned __int8 *)(*(_QWORD *)(a3 + 16) + 168LL));
    goto LABEL_64;
  }
  v25 = *(_DWORD *)(a2 + 40);
  v27 = *(unsigned __int8 **)(a2 + 16);
  v26 = *(_QWORD *)(a2 + 24);
  v28 = jiffies;
  if ( lim_process_addba_req___last_ticks - jiffies + 125 < 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 8, v26, v25);
    lim_process_addba_req___last_ticks = v28;
  }
  result = _qdf_mem_malloc(0xCu, "lim_process_addba_req", 1766);
  if ( result )
  {
    v29 = result;
    v30 = dot11f_unpack_addba_req(a1, v26, v25, result, 0);
    if ( (v30 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to unpack and parse (0x%08x, %d bytes)",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "lim_process_addba_req",
        v30,
        v25);
    }
    else
    {
      if ( v30 )
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: warning: unpack addba Req(0x%08x, %d bytes)",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "lim_process_addba_req",
          v30,
          v25);
      v39 = (_BYTE *)dph_lookup_hash_entry(v31, v32, v33, v34, v35, v36, v37, v38, a1, v27 + 10, &v104, a3 + 360);
      if ( !v39 )
        goto LABEL_20;
      if ( v39[356] != 4
        || (v48 = v39,
            is_addba_request_allowed = wlan_tdls_is_addba_request_allowed(*(_QWORD *)(a3 + 16), v39 + 350),
            v39 = v48,
            (is_addba_request_allowed & 1) != 0) )
      {
        if ( (*(_BYTE *)(a3 + 8676) & 1) != 0 || v39[356] == 4 )
        {
          v50 = v39[38];
          if ( a3 )
          {
LABEL_15:
            v51 = (unsigned __int8)v39[356];
            if ( (*(_BYTE *)(a3 + 10071) & 1) != 0 || v51 == 4 )
            {
LABEL_17:
              v52 = v39[68];
              if ( v51 == 5 )
                goto LABEL_18;
              goto LABEL_26;
            }
LABEL_25:
            v52 = 0;
            if ( v51 == 5 )
            {
LABEL_18:
              if ( (*(_BYTE *)(a3 + 8676) & 1) == 0 )
                goto LABEL_19;
              goto LABEL_27;
            }
LABEL_26:
            if ( (v50 & 1) == 0 )
            {
LABEL_19:
              if ( (v52 & 1) == 0 )
              {
LABEL_20:
                v53 = 64;
LABEL_30:
                v54 = *(unsigned __int16 *)(a1 + 21694);
                if ( !*(_WORD *)(a1 + 21694) )
                {
                  v54 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 2912LL);
                  if ( v53 < v54 )
                    v54 = v53;
                }
                v55 = *(unsigned __int8 *)(v29 + 10);
                if ( *(_BYTE *)(v29 + 10) )
                  v55 = *(unsigned __int8 *)(v29 + 11) >> 5;
                v56 = *(unsigned __int16 *)(v29 + 4);
                if ( v56 >= 0x40 )
                {
                  v58 = v56 >> 6;
                  if ( (unsigned __int16)v54 >= (unsigned int)v58 )
                    v59 = v56 >> 6;
                  else
                    v59 = (unsigned __int16)v54;
                }
                else
                {
                  v57 = (unsigned __int16)v54;
                  if ( (v54 & 0xFC00) != 0 )
                    v57 = 1024;
                  v58 = 0;
                  if ( v55 )
                    v59 = v57;
                  else
                    v59 = v54;
                }
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: token %d tid %d timeout %d buff_size in frame %d buf_size calculated %d ssn %d, extd buff size %d",
                  v40,
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  v46,
                  v47,
                  "lim_process_addba_req",
                  *(unsigned __int8 *)(v29 + 2),
                  (v56 >> 2) & 0xF,
                  *(unsigned __int16 *)(v29 + 6),
                  v58,
                  (unsigned __int16)v59,
                  *(unsigned __int16 *)(v29 + 8) >> 4,
                  v55);
                if ( context && *context )
                {
                  v68 = **context;
                  if ( v68 )
                  {
                    v69 = *(_DWORD **)(v68 + 440);
                    if ( v69 )
                    {
                      v70 = *(unsigned __int8 *)(a3 + 10);
                      v71 = *(unsigned __int8 *)(v29 + 2);
                      v72 = (*(unsigned __int16 *)(v29 + 4) >> 2) & 0xF;
                      v73 = *(unsigned __int16 *)(v29 + 6);
                      v74 = *(unsigned __int16 *)(v29 + 8) >> 4;
                      if ( *(v69 - 1) != 828807234 )
                        __break(0x8228u);
                      if ( ((unsigned int (__fastcall *)(__int64 **, unsigned __int8 *, __int64, __int64, __int64, __int64, _QWORD, __int64))v69)(
                             context,
                             v27 + 10,
                             v70,
                             v71,
                             v72,
                             v73,
                             v59,
                             v74) )
                      {
                        v83 = jiffies;
                        if ( lim_process_addba_req___last_ticks_126 - jiffies + 125 < 0 )
                        {
                          qdf_trace_msg(
                            0x35u,
                            8u,
                            "%s: Failed to process addba request",
                            v75,
                            v76,
                            v77,
                            v78,
                            v79,
                            v80,
                            v81,
                            v82,
                            "lim_process_addba_req");
                          lim_process_addba_req___last_ticks_126 = v83;
                        }
                        goto LABEL_63;
                      }
                    }
                  }
                }
                else
                {
                  qdf_trace_msg(
                    0x89u,
                    8u,
                    "%s: Invalid Instance:",
                    v60,
                    v61,
                    v62,
                    v63,
                    v64,
                    v65,
                    v66,
                    v67,
                    "cdp_addba_requestprocess");
                }
                if ( (unsigned int)lim_send_addba_response_frame(
                                     a1,
                                     v27 + 10,
                                     (*(unsigned __int16 *)(v29 + 4) >> 2) & 0xF,
                                     a3,
                                     *(unsigned __int8 *)(v29 + 10),
                                     *(_WORD *)(v29 + 4) & 1,
                                     (*(unsigned __int16 *)v27 >> 14) & 1,
                                     v59,
                                     v27 + 16) )
                {
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: Failed to send addba response frame",
                    v84,
                    v85,
                    v86,
                    v87,
                    v88,
                    v89,
                    v90,
                    v91,
                    "lim_process_addba_req");
                  if ( context && *context )
                  {
                    v100 = **context;
                    if ( v100 )
                    {
                      v101 = *(void (__fastcall **)(__int64 **, unsigned __int8 *, __int64, __int64, __int64))(v100 + 432);
                      if ( v101 )
                      {
                        v102 = *(unsigned __int8 *)(a3 + 10);
                        v103 = (*(unsigned __int8 *)(v29 + 4) >> 2) & 0xF;
                        if ( *((_DWORD *)v101 - 1) != 75369535 )
                          __break(0x8228u);
                        v101(context, v27 + 10, v102, v103, 1);
                      }
                    }
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x89u,
                      8u,
                      "%s: Invalid Instance:",
                      v92,
                      v93,
                      v94,
                      v95,
                      v96,
                      v97,
                      v98,
                      v99,
                      "cdp_addba_resp_tx_completion");
                  }
                }
                goto LABEL_63;
              }
LABEL_28:
              v53 = 1024;
              goto LABEL_30;
            }
LABEL_27:
            if ( (v52 & 1) == 0 )
            {
              v53 = 256;
              goto LABEL_30;
            }
            goto LABEL_28;
          }
        }
        else
        {
          v50 = 0;
          if ( a3 )
            goto LABEL_15;
        }
        v51 = (unsigned __int8)v39[356];
        if ( v51 == 4 )
          goto LABEL_17;
        goto LABEL_25;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: vdev:%d Dropping TDLS peer addba req received before change_sta",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "lim_process_addba_req",
        *(unsigned __int8 *)(*(_QWORD *)(a3 + 16) + 168LL));
    }
LABEL_63:
    result = _qdf_mem_free(v29);
  }
LABEL_64:
  _ReadStatusReg(SP_EL0);
  return result;
}
