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
  __int64 **context; // x0
  __int64 v15; // x24
  unsigned __int8 *v16; // x25
  unsigned int v17; // w23
  __int64 v18; // x19
  __int64 **v19; // x21
  __int64 result; // x0
  __int64 v21; // x19
  unsigned int v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w8
  __int64 v41; // x23
  unsigned int v42; // w8
  unsigned int v43; // w9
  int v44; // w8
  unsigned int v45; // w10
  int v46; // w11
  __int64 v47; // x7
  unsigned int v48; // w23
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x8
  _DWORD *v58; // x8
  __int64 v59; // x2
  __int64 v60; // x3
  __int64 v61; // x4
  __int64 v62; // x5
  __int64 v63; // x7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x21
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // x8
  void (__fastcall *v90)(__int64 **, unsigned __int8 *, __int64, __int64, __int64); // x8
  __int64 v91; // x2
  __int64 v92; // x3
  __int16 v93; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v94; // [xsp+28h] [xbp-8h]

  v94 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = (__int64 **)_cds_get_context(71, (__int64)"lim_process_addba_req", a4, a5, a6, a7, a8, a9, a10, a11);
  v93 = 0;
  v16 = *(unsigned __int8 **)(a2 + 16);
  v15 = *(_QWORD *)(a2 + 24);
  v17 = *(_DWORD *)(a2 + 40);
  v18 = jiffies;
  v19 = context;
  if ( lim_process_addba_req___last_ticks - jiffies + 125 < 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 8, v15, v17);
    lim_process_addba_req___last_ticks = v18;
  }
  result = _qdf_mem_malloc(0xCu, "lim_process_addba_req", 1766);
  if ( result )
  {
    v21 = result;
    v22 = dot11f_unpack_addba_req(a1, v15, v17, result, 0);
    if ( (v22 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to unpack and parse (0x%08x, %d bytes)",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "lim_process_addba_req",
        v22,
        v17);
    }
    else
    {
      if ( v22 )
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: warning: unpack addba Req(0x%08x, %d bytes)",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "lim_process_addba_req",
          v22,
          v17);
      v31 = dph_lookup_hash_entry(v23, v24, v25, v26, v27, v28, v29, v30, a1, v16 + 10, &v93, a3 + 360);
      if ( !v31 )
        goto LABEL_19;
      v40 = *(unsigned __int8 *)(v31 + 344);
      if ( v40 != 4 )
      {
LABEL_11:
        if ( (*(_BYTE *)(a3 + 8676) & 1) != 0 )
        {
          if ( v40 == 5 || (*(_BYTE *)(v31 + 38) & 1) != 0 )
          {
LABEL_18:
            v42 = 256;
LABEL_20:
            v43 = *(unsigned __int16 *)(a1 + 21622);
            if ( !*(_WORD *)(a1 + 21622) )
            {
              v43 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 2708LL);
              if ( v42 < v43 )
                v43 = v42;
            }
            v44 = *(unsigned __int8 *)(v21 + 10);
            if ( *(_BYTE *)(v21 + 10) )
              v44 = *(unsigned __int8 *)(v21 + 11) >> 5;
            v45 = *(unsigned __int16 *)(v21 + 4);
            if ( v45 >= 0x40 )
            {
              v47 = v45 >> 6;
              if ( (unsigned __int16)v43 >= (unsigned int)v47 )
                v48 = v45 >> 6;
              else
                v48 = (unsigned __int16)v43;
            }
            else
            {
              v46 = (unsigned __int16)v43;
              if ( (v43 & 0xFC00) != 0 )
                v46 = 1024;
              v47 = 0;
              if ( v44 )
                v48 = v46;
              else
                v48 = v43;
            }
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: token %d tid %d timeout %d buff_size in frame %d buf_size calculated %d ssn %d, extd buff size %d",
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              "lim_process_addba_req",
              *(unsigned __int8 *)(v21 + 2),
              (v45 >> 2) & 0xF,
              *(unsigned __int16 *)(v21 + 6),
              v47,
              (unsigned __int16)v48,
              *(unsigned __int16 *)(v21 + 8) >> 4,
              v44);
            if ( v19 && *v19 )
            {
              v57 = **v19;
              if ( v57 )
              {
                v58 = *(_DWORD **)(v57 + 440);
                if ( v58 )
                {
                  v59 = *(unsigned __int8 *)(a3 + 10);
                  v60 = *(unsigned __int8 *)(v21 + 2);
                  v61 = (*(unsigned __int16 *)(v21 + 4) >> 2) & 0xF;
                  v62 = *(unsigned __int16 *)(v21 + 6);
                  v63 = *(unsigned __int16 *)(v21 + 8) >> 4;
                  if ( *(v58 - 1) != 828807234 )
                    __break(0x8228u);
                  if ( ((unsigned int (__fastcall *)(__int64 **, unsigned __int8 *, __int64, __int64, __int64, __int64, _QWORD, __int64))v58)(
                         v19,
                         v16 + 10,
                         v59,
                         v60,
                         v61,
                         v62,
                         v48,
                         v63) )
                  {
                    v72 = jiffies;
                    if ( lim_process_addba_req___last_ticks_126 - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: Failed to process addba request",
                        v64,
                        v65,
                        v66,
                        v67,
                        v68,
                        v69,
                        v70,
                        v71,
                        "lim_process_addba_req");
                      lim_process_addba_req___last_ticks_126 = v72;
                    }
                    goto LABEL_54;
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
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                "cdp_addba_requestprocess");
            }
            if ( (unsigned int)lim_send_addba_response_frame(
                                 a1,
                                 v16 + 10,
                                 (*(unsigned __int16 *)(v21 + 4) >> 2) & 0xF,
                                 a3,
                                 *(unsigned __int8 *)(v21 + 10),
                                 *(_WORD *)(v21 + 4) & 1,
                                 (*(unsigned __int16 *)v16 >> 14) & 1,
                                 v48,
                                 v16 + 16) )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: Failed to send addba response frame",
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                "lim_process_addba_req");
              if ( v19 && *v19 )
              {
                v89 = **v19;
                if ( v89 )
                {
                  v90 = *(void (__fastcall **)(__int64 **, unsigned __int8 *, __int64, __int64, __int64))(v89 + 432);
                  if ( v90 )
                  {
                    v91 = *(unsigned __int8 *)(a3 + 10);
                    v92 = (*(unsigned __int8 *)(v21 + 4) >> 2) & 0xF;
                    if ( *((_DWORD *)v90 - 1) != 75369535 )
                      __break(0x8228u);
                    v90(v19, v16 + 10, v91, v92, 1);
                  }
                }
              }
              else
              {
                qdf_trace_msg(
                  0x89u,
                  8u,
                  "%s: Invalid Instance:",
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  v86,
                  v87,
                  v88,
                  "cdp_addba_resp_tx_completion");
              }
            }
            goto LABEL_54;
          }
        }
        else if ( v40 == 4 && (*(_BYTE *)(v31 + 38) & 1) != 0 )
        {
          goto LABEL_18;
        }
LABEL_19:
        v42 = 64;
        goto LABEL_20;
      }
      v41 = v31;
      if ( (wlan_tdls_is_addba_request_allowed(*(_QWORD *)(a3 + 16), v31 + 338) & 1) != 0 )
      {
        v40 = *(unsigned __int8 *)(v41 + 344);
        v31 = v41;
        goto LABEL_11;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: vdev:%d Dropping TDLS peer addba req received before change_sta",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "lim_process_addba_req",
        *(unsigned __int8 *)(*(_QWORD *)(a3 + 16) + 104LL));
    }
LABEL_54:
    result = _qdf_mem_free(v21);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
