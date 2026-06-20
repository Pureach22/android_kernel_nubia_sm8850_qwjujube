__int64 __fastcall lim_process_probe_rsp_frame(
        __int64 a1,
        int *a2,
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
  __int64 v14; // x0
  __int64 v15; // x19
  __int16 *v16; // x23
  __int64 v17; // x4
  __int64 result; // x0
  const char *v19; // x2
  unsigned int v20; // w24
  __int64 v21; // x1
  int v22; // w4
  int v23; // w5
  __int64 v24; // x8
  int v25; // w9
  __int64 v26; // x0
  size_t v27; // x0
  void *v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x3
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int16 v46; // w9
  int v47; // w8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x1
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  int v65; // w1
  _DWORD v66[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v67; // [xsp+18h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v66, 0, 6);
  if ( !a3 )
  {
    v19 = "%s: session_entry is NULL";
LABEL_10:
    result = qdf_trace_msg(0x35u, 2u, v19, a4, a5, a6, a7, a8, a9, a10, a11, "lim_process_probe_rsp_frame");
    goto LABEL_11;
  }
  v14 = _qdf_mem_malloc(0xD80u, "lim_process_probe_rsp_frame", 349);
  if ( !v14 )
  {
    v19 = "%s: Unable to allocate memory";
    goto LABEL_10;
  }
  *(_BYTE *)(v14 + 12) = 0;
  v15 = v14;
  *(_BYTE *)(v14 + 620) = 0;
  v16 = *((__int16 **)a2 + 2);
  *(_BYTE *)(a1 + 12208) = a2[2];
  if ( (unsigned int)a2[10] >= 0xE && !(unsigned int)sir_validate_and_rectify_ies(a1, *((_QWORD *)a2 + 3)) )
  {
    v20 = a2[10];
    v21 = *((_QWORD *)a2 + 3);
    a2[8] = a2[8];
    if ( (unsigned int)sir_convert_probe_frame2_struct(a1, v21, v20, v15) == 16 || !*(_BYTE *)(v15 + 2460) )
    {
      v17 = v20;
      goto LABEL_6;
    }
    v22 = *(_DWORD *)(v15 + 72);
    v23 = *a2;
    if ( v22 )
    {
      v24 = a3;
      if ( v22 == v23
        || (qdf_trace_msg(
              0x35u,
              8u,
              "%s: mismatch freq %d rx %d op %d",
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              "lim_process_probe_rsp_frame"),
            v23 = *a2,
            v24 = a3,
            *a2 != *(_DWORD *)(a3 + 284)) )
      {
LABEL_21:
        v25 = *(_DWORD *)(v24 + 72);
        if ( v25 == 14 )
        {
          v46 = *(_WORD *)(v24 + 24);
          v47 = *(_DWORD *)(v24 + 26);
          LOWORD(v66[0]) = v46;
          *(_DWORD *)((char *)v66 + 2) = v47;
          if ( !(unsigned int)qdf_mem_cmp(v66, v16 + 8, 6u) )
          {
            v56 = a3;
            if ( !*(_BYTE *)(a3 + 292) )
            {
              qdf_trace_msg(
                0x35u,
                3u,
                "%s: Recved Probe Resp from AP,AP-alive",
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                "lim_process_probe_rsp_frame");
              if ( *(_BYTE *)(v15 + 1260) )
                v65 = wlan_reg_legacy_chan_to_freq(
                        *(_QWORD *)(a1 + 21560),
                        *(unsigned __int8 *)(v15 + 1261),
                        v57,
                        v58,
                        v59,
                        v60,
                        v61,
                        v62,
                        v63,
                        v64);
              else
                v65 = *(_DWORD *)(v15 + 72);
              lim_received_hb_handler(a1, v65, a3);
              v56 = a3;
            }
            lim_process_updated_ies_in_probe_rsp(a1, v56, (_BYTE *)v15);
          }
        }
        else if ( v25 == 2 )
        {
          v26 = *(_QWORD *)(v24 + 320);
          if ( v26 )
          {
            _qdf_mem_free(v26);
            v24 = a3;
            *(_QWORD *)(a3 + 320) = 0;
            *(_DWORD *)(a3 + 312) = 0;
          }
          v27 = (unsigned int)a2[8];
          *(_DWORD *)(v24 + 312) = v27;
          v28 = (void *)_qdf_mem_malloc(v27, "lim_process_probe_rsp_frame", 448);
          *(_QWORD *)(a3 + 320) = v28;
          if ( v28 )
            qdf_mem_copy(v28, *((const void **)a2 + 2), *(unsigned int *)(a3 + 312));
          else
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: No Memory to store beacon",
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "lim_process_probe_rsp_frame");
          mgmt_txrx_frame_hex_dump((__int64)v16, a2[8], 0, v37, v38, v39, v40, v41, v42, v43, v44, v45);
          lim_check_and_announce_join_success(a1, v15, v16, a3);
        }
        goto LABEL_7;
      }
    }
    else
    {
      v24 = a3;
    }
    *(_DWORD *)(v15 + 72) = v23;
    goto LABEL_21;
  }
  v17 = 0;
LABEL_6:
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Parse error ProbeResponse, length=%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "lim_process_probe_rsp_frame",
    v17);
LABEL_7:
  result = _qdf_mem_free(v15);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
