__int64 __fastcall sir_convert_reassoc_req_frame2_struct(__int64 a1, __int64 a2, unsigned int a3, unsigned __int16 *a4)
{
  __int64 v8; // x0
  __int64 v9; // x5
  __int64 v10; // x6
  __int64 v11; // x7
  _BYTE *v12; // x19
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w9
  unsigned int v23; // w9
  unsigned int v24; // w9
  unsigned int v25; // w9
  unsigned int v26; // w9
  unsigned int v27; // w9
  unsigned int v28; // w9
  unsigned int v29; // w9
  unsigned int v30; // w9
  unsigned int v31; // w9
  unsigned int v32; // w9
  unsigned int v33; // w9
  unsigned int v34; // w9
  unsigned int v35; // w9
  unsigned int v36; // w9
  unsigned int v37; // w21
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w20

  v8 = _qdf_mem_malloc(0x13C0u, "sir_convert_reassoc_req_frame2_struct", 4944);
  if ( v8 )
  {
    v12 = (_BYTE *)v8;
    v13 = dot11f_unpack_re_assoc_request(a1, a2, a3, v8, 0, v9, v10, v11);
    if ( (v13 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to parse a Re-association Request (0x%08x, %d bytes):",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "sir_convert_reassoc_req_frame2_struct",
        v13,
        a3);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 2, a2, a3);
    }
    else
    {
      if ( v13 )
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: There were warnings while unpacking a Re-association Request (0x%08x, %d bytes):",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "sir_convert_reassoc_req_frame2_struct",
          v13,
          a3);
      v22 = *a4;
      *((_BYTE *)a4 + 3257) = 1;
      v23 = v22 & 0xFFFFFFFE | *(_WORD *)v12 & 1;
      *a4 = v23;
      v24 = v23 & 0xFFFFFFFD | (2 * ((*(unsigned __int16 *)v12 >> 1) & 1));
      *a4 = v24;
      v25 = v24 & 0xFFFFFFFB | (4 * ((*(unsigned __int16 *)v12 >> 2) & 1));
      *a4 = v25;
      v26 = v25 & 0xFFFFFFF7 | (8 * ((*(unsigned __int16 *)v12 >> 3) & 1));
      *a4 = v26;
      v27 = v26 & 0xFFFFFFEF | (16 * ((*(unsigned __int16 *)v12 >> 4) & 1));
      *a4 = v27;
      v28 = v27 & 0xFFFFFFDF | (32 * ((*(unsigned __int16 *)v12 >> 5) & 1));
      *a4 = v28;
      v29 = v28 & 0xFFFFFFBF | (((*(unsigned __int16 *)v12 >> 6) & 1) << 6);
      *a4 = v29;
      v30 = v29 & 0xFFFFFF7F | (((*(unsigned __int16 *)v12 >> 7) & 1) << 7);
      *a4 = v30;
      v31 = v30 & 0xFFFFFEFF | ((HIBYTE(*(unsigned __int16 *)v12) & 1) << 8);
      *a4 = v31;
      v32 = v31 & 0xFFFFFDFF | (((*(unsigned __int16 *)v12 >> 9) & 1) << 9);
      *a4 = v32;
      v33 = v32 & 0xFFFFFBFF | (((*(unsigned __int16 *)v12 >> 10) & 1) << 10);
      *a4 = v33;
      v34 = v33 & 0xFFFFF7FF | (((*(unsigned __int16 *)v12 >> 11) & 1) << 11);
      *a4 = v34;
      v35 = v34 & 0xFFFFEFFF | (((*(unsigned __int16 *)v12 >> 12) & 1) << 12);
      *a4 = v35;
      v36 = v35 & 0xFFFFDFFF | (((*(unsigned __int16 *)v12 >> 13) & 1) << 13);
      *a4 = v36;
      LOWORD(v36) = v36 & 0xBFFF | (((*(_WORD *)v12 >> 14) & 1) << 14);
      *a4 = v36;
      *a4 = *(_WORD *)v12 & 0x8000 | v36 & 0x7FFF;
      a4[1] = *((_WORD *)v12 + 1);
      if ( v12[10] )
      {
        *((_BYTE *)a4 + 3258) = 1;
        convert_ssid(a1, a4 + 5, v12 + 10);
      }
      if ( v12[44] )
      {
        *((_BYTE *)a4 + 3259) = 1;
        convert_supp_rates(a1, a4 + 22, v12 + 44);
      }
      if ( v12[58] )
      {
        *((_BYTE *)a4 + 3260) = 1;
        convert_ext_supp_rates(a1, (char *)a4 + 57, v12 + 58);
      }
      if ( v12[428] )
      {
        *((_BYTE *)a4 + 3262) = 1;
        convert_qos_caps_station(a1, (char *)a4 + 233, v12 + 428);
      }
      if ( v12[3460] )
      {
        *((_BYTE *)a4 + 3266) = 1;
        convert_wpa_opaque(a1, a4 + 246, v12 + 3460);
      }
      if ( v12[173] )
      {
        *((_BYTE *)a4 + 3267) = 1;
        convert_rsn_opaque(a1, a4 + 374, v12 + 173);
      }
      if ( v12[72] )
      {
        *((_BYTE *)a4 + 3269) = 1;
        convert_power_caps(a1, a4 + 1528, v12 + 72);
      }
      if ( v12[75] )
      {
        *((_BYTE *)a4 + 3270) = 1;
        convert_supp_channels(a1, a4 + 1530, v12 + 75);
      }
      if ( v12[1972] )
        qdf_mem_copy(a4 + 1580, v12 + 1972, 0x3Cu);
      if ( v12[3714] )
      {
        *((_BYTE *)a4 + 3261) = 1;
        qdf_mem_copy(a4 + 1610, v12 + 3714, 3u);
      }
      if ( v12[3711] )
        *((_BYTE *)a4 + 3264) = 1;
      if ( *((_BYTE *)a4 + 3258) )
      {
        if ( *((_BYTE *)a4 + 3259) || *((_BYTE *)a4 + 3260) )
        {
          if ( v12[3717] )
          {
            *((_BYTE *)a4 + 3268) = 1;
            ((void (__fastcall *)(__int64, unsigned __int16 *, _BYTE *))convert_wsc_opaque)(a1, a4 + 502, v12 + 3717);
          }
          if ( v12[4227] )
          {
            *((_BYTE *)a4 + 3268) = 1;
            ((void (__fastcall *)(__int64, unsigned __int16 *, _BYTE *))convert_p2p_opaque)(a1, a4 + 502, v12 + 4227);
          }
          if ( v12[4478] )
          {
            *((_BYTE *)a4 + 3268) = 1;
            ((void (__fastcall *)(__int64, unsigned __int16 *, _BYTE *))convert_p2p2_opaque)(a1, a4 + 502, v12 + 4478);
          }
          if ( v12[4729] )
          {
            *((_BYTE *)a4 + 3268) = 1;
            ((void (__fastcall *)(__int64, unsigned __int16 *, _BYTE *))convert_wfd_opaque)(a1, a4 + 502, v12 + 4729);
          }
          if ( v12[1936] )
          {
            if ( (unsigned __int8)v12[1937] >= 0x20u )
              v37 = 32;
            else
              v37 = (unsigned __int8)v12[1937];
            qdf_mem_copy((char *)a4 + 3223, v12 + 1936, 0x22u);
            ((void (__fastcall *)(__int64, __int64, _BYTE *, _QWORD))qdf_trace_hex_dump)(53, 8, v12 + 1938, v37);
          }
          if ( v12[2052] )
            qdf_mem_copy(a4 + 1648, v12 + 2052, 0x10u);
          if ( v12[2068] )
          {
            qdf_mem_copy(a4 + 1656, v12 + 2068, 2u);
            qdf_trace_msg(
              0x35u,
              3u,
              "%s: Received Assoc Req with Operating Mode IE",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "sir_convert_reassoc_req_frame2_struct");
          }
          if ( v12[2032] )
          {
            qdf_mem_copy(a4 + 1657, v12 + 2032, 0x11u);
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: timingMeas: %d, finetimingMeas Init: %d, Resp: %d",
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              "sir_convert_reassoc_req_frame2_struct",
              (*((_DWORD *)a4 + 829) >> 23) & 1,
              (a4[1662] >> 7) & 1,
              (a4[1662] >> 6) & 1);
          }
          if ( v12[2076] )
            qdf_mem_copy(a4 + 1686, v12 + 2076, 0x3Cu);
          if ( v12[2136] )
            qdf_mem_copy(a4 + 1716, v12 + 2136, 4u);
          if ( v12[5012] )
            qdf_mem_copy(a4 + 1718, v12 + 5012, 0x2Cu);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: ht %d vht %d opmode %d vendor vht %d he %d he 6ghband %d eht %d",
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            "sir_convert_reassoc_req_frame2_struct",
            (unsigned __int8)v12[1972],
            (unsigned __int8)v12[2052],
            (unsigned __int8)v12[2068],
            (unsigned __int8)v12[4984],
            (unsigned __int8)v12[2076],
            (unsigned __int8)v12[2136],
            (unsigned __int8)v12[2592]);
          v54 = 0;
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Received Assoc without supp rate IE",
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            "sir_convert_reassoc_req_frame2_struct");
          v54 = 18;
        }
        goto LABEL_60;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Received Assoc without SSID IE",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "sir_convert_reassoc_req_frame2_struct");
    }
    v54 = 1;
LABEL_60:
    _qdf_mem_free((__int64)v12);
    return v54;
  }
  return 1;
}
