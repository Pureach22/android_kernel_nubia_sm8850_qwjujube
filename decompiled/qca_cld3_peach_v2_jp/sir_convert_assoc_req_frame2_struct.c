__int64 __fastcall sir_convert_assoc_req_frame2_struct(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        unsigned __int8 *a6)
{
  __int64 v12; // x0
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x7
  _BYTE *v16; // x19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w8
  unsigned int v35; // w8
  unsigned int v36; // w8
  unsigned int v37; // w8
  unsigned int v38; // w8
  unsigned int v39; // w8
  unsigned int v40; // w8
  unsigned int v41; // w8
  unsigned int v42; // w8
  unsigned int v43; // w8
  unsigned int v44; // w8
  unsigned int v45; // w8
  unsigned int v46; // w8
  unsigned int v47; // w8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w8
  int v57; // w8
  unsigned int v58; // w20

  v12 = _qdf_mem_malloc(0x16CCu, "sir_convert_assoc_req_frame2_struct", 3779);
  if ( v12 )
  {
    v16 = (_BYTE *)v12;
    if ( a6 && *(_DWORD *)(a2 + 88) == 1 && !lim_search_pre_auth_list(*(_QWORD *)(a2 + 8608), a6) )
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: No preauth node created for %02x:%02x:%02x:**:**:%02x",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "lim_get_fils_info",
        *a6,
        a6[1],
        a6[2],
        a6[5]);
    v25 = dot11f_unpack_assoc_request(a1, a3, a4, (__int64)v16, 0, v13, v14, v15);
    if ( (v25 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to parse an Association Request (0x%08x, %d bytes):",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "sir_convert_assoc_req_frame2_struct",
        v25,
        a4);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 2, a3, a4);
    }
    else
    {
      if ( v25 )
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: There were warnings while unpacking an Association Request (0x%08x, %d bytes):",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "sir_convert_assoc_req_frame2_struct",
          v25,
          a4);
      *(_BYTE *)(a5 + 3257) = 0;
      v34 = *(_WORD *)a5 & 0xFFFE | *(_WORD *)v16 & 1;
      *(_WORD *)a5 = *(_WORD *)a5 & 0xFFFE | *(_WORD *)v16 & 1;
      v35 = v34 & 0xFFFFFFFD | (2 * ((*(unsigned __int16 *)v16 >> 1) & 1));
      *(_WORD *)a5 = v35;
      v36 = v35 & 0xFFFFFFFB | (4 * ((*(unsigned __int16 *)v16 >> 2) & 1));
      *(_WORD *)a5 = v36;
      v37 = v36 & 0xFFFFFFF7 | (8 * ((*(unsigned __int16 *)v16 >> 3) & 1));
      *(_WORD *)a5 = v37;
      v38 = v37 & 0xFFFFFFEF | (16 * ((*(unsigned __int16 *)v16 >> 4) & 1));
      *(_WORD *)a5 = v38;
      v39 = v38 & 0xFFFFFFDF | (32 * ((*(unsigned __int16 *)v16 >> 5) & 1));
      *(_WORD *)a5 = v39;
      v40 = v39 & 0xFFFFFFBF | (((*(unsigned __int16 *)v16 >> 6) & 1) << 6);
      *(_WORD *)a5 = v40;
      v41 = v40 & 0xFFFFFF7F | (((*(unsigned __int16 *)v16 >> 7) & 1) << 7);
      *(_WORD *)a5 = v41;
      v42 = v41 & 0xFFFFFEFF | ((HIBYTE(*(unsigned __int16 *)v16) & 1) << 8);
      *(_WORD *)a5 = v42;
      v43 = v42 & 0xFFFFFDFF | (((*(unsigned __int16 *)v16 >> 9) & 1) << 9);
      *(_WORD *)a5 = v43;
      v44 = v43 & 0xFFFFFBFF | (((*(unsigned __int16 *)v16 >> 10) & 1) << 10);
      *(_WORD *)a5 = v44;
      v45 = v44 & 0xFFFFF7FF | (((*(unsigned __int16 *)v16 >> 11) & 1) << 11);
      *(_WORD *)a5 = v45;
      v46 = v45 & 0xFFFFEFFF | (((*(unsigned __int16 *)v16 >> 12) & 1) << 12);
      *(_WORD *)a5 = v46;
      v47 = v46 & 0xFFFFDFFF | (((*(unsigned __int16 *)v16 >> 13) & 1) << 13);
      *(_WORD *)a5 = v47;
      LOWORD(v47) = v47 & 0xBFFF | (((*(_WORD *)v16 >> 14) & 1) << 14);
      *(_WORD *)a5 = v47;
      *(_WORD *)a5 = *(_WORD *)v16 & 0x8000 | v47 & 0x7FFF;
      *(_WORD *)(a5 + 2) = *((_WORD *)v16 + 1);
      if ( v16[4] )
      {
        *(_BYTE *)(a5 + 3258) = 1;
        convert_ssid(a1, a5 + 10, v16 + 4);
      }
      if ( v16[38] )
      {
        *(_BYTE *)(a5 + 3259) = 1;
        convert_supp_rates(a1, a5 + 44, v16 + 38);
      }
      if ( v16[52] )
      {
        *(_BYTE *)(a5 + 3260) = 1;
        convert_ext_supp_rates(a1, a5 + 57, v16 + 52);
      }
      if ( v16[422] )
      {
        *(_BYTE *)(a5 + 3262) = 1;
        convert_qos_caps_station(a1, a5 + 233, v16 + 422);
      }
      if ( v16[3976] )
      {
        *(_BYTE *)(a5 + 3266) = 1;
        convert_wpa_opaque(a1, a5 + 492, v16 + 3976);
      }
      if ( v16[2164] )
      {
        *(_BYTE *)(a5 + 3265) = 1;
        convert_wapi_opaque(a1, a5 + 236, v16 + 2164);
      }
      if ( v16[167] )
      {
        *(_BYTE *)(a5 + 3267) = 1;
        convert_rsn_opaque(a1, a5 + 748, v16 + 167);
      }
      if ( v16[4233] )
      {
        *(_BYTE *)(a5 + 3268) = 1;
        ((void (__fastcall *)(__int64, __int64, _BYTE *))convert_wsc_opaque)(a1, a5 + 1004, v16 + 4233);
      }
      if ( v16[4489] )
      {
        *(_BYTE *)(a5 + 3268) = 1;
        ((void (__fastcall *)(__int64, __int64, _BYTE *))convert_p2p_opaque)(a1, a5 + 1004, v16 + 4489);
      }
      if ( v16[4740] )
      {
        *(_BYTE *)(a5 + 3268) = 1;
        ((void (__fastcall *)(__int64, __int64, _BYTE *))convert_p2p2_opaque)(a1, a5 + 1004, v16 + 4740);
      }
      if ( v16[4991] )
      {
        *(_BYTE *)(a5 + 3268) = 1;
        ((void (__fastcall *)(__int64, __int64, _BYTE *))convert_wfd_opaque)(a1, a5 + 1004, v16 + 4991);
      }
      if ( v16[66] )
      {
        *(_BYTE *)(a5 + 3269) = 1;
        convert_power_caps(a1, a5 + 3056, v16 + 66);
      }
      if ( v16[69] )
      {
        *(_BYTE *)(a5 + 3270) = 1;
        convert_supp_channels(a1, a5 + 3060, v16 + 69);
      }
      if ( v16[472] )
        qdf_mem_copy((void *)(a5 + 3160), v16 + 472, 0x3Cu);
      if ( v16[4230] )
      {
        *(_BYTE *)(a5 + 3261) = 1;
        qdf_mem_copy((void *)(a5 + 3220), v16 + 4230, 3u);
      }
      if ( v16[4227] )
        *(_BYTE *)(a5 + 3264) = 1;
      if ( *(_BYTE *)(a5 + 3258) )
      {
        if ( *(_BYTE *)(a5 + 3259) || *(_BYTE *)(a5 + 3260) )
        {
          if ( v16[552] )
            qdf_mem_copy((void *)(a5 + 3296), v16 + 552, 0x10u);
          if ( v16[568] )
            qdf_mem_copy((void *)(a5 + 3312), v16 + 568, 2u);
          if ( v16[532] )
          {
            qdf_mem_copy((void *)(a5 + 3314), v16 + 532, 0x11u);
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: timingMeas: %d, finetimingMeas Init: %d, Resp: %d",
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              "sir_convert_assoc_req_frame2_struct",
              (*(_DWORD *)(a5 + 3316) >> 23) & 1,
              (*(unsigned __int16 *)(a5 + 3324) >> 7) & 1,
              (*(unsigned __int16 *)(a5 + 3324) >> 6) & 1);
          }
          if ( v16[436] )
            qdf_mem_copy((void *)(a5 + 3223), v16 + 436, 0x22u);
          v56 = (unsigned __int8)v16[5244];
          *(_BYTE *)(a5 + 3340) = v56;
          if ( v56 )
          {
            *(_BYTE *)(a5 + 3341) = v16[5245];
            if ( v16[5248] )
              qdf_mem_copy((void *)(a5 + 3344), v16 + 5248, 0x10u);
          }
          if ( v16[5276] )
            qdf_mem_copy((void *)(a5 + 3436), v16 + 5276, 0x2Cu);
          if ( v16[1364] )
            qdf_mem_copy((void *)(a5 + 3332), v16 + 1364, 6u);
          if ( v16[2100] )
            qdf_mem_copy((void *)(a5 + 3372), v16 + 2100, 0x3Cu);
          v57 = (unsigned __int8)v16[2160];
          if ( v16[2160] )
          {
            qdf_mem_copy((void *)(a5 + 3432), v16 + 2160, 4u);
            v57 = (unsigned __int8)v16[2160];
          }
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: ht %d vht %d opmode %d vendor vht %d he %d he 6ghband %d eht %d",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "sir_convert_assoc_req_frame2_struct",
            (unsigned __int8)v16[472],
            (unsigned __int8)v16[552],
            (unsigned __int8)v16[568],
            (unsigned __int8)v16[5248],
            (unsigned __int8)v16[2100],
            v57,
            (unsigned __int8)v16[3108]);
          v58 = 0;
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Received Assoc without supp rate IE",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "sir_convert_assoc_req_frame2_struct");
          v58 = 18;
        }
        goto LABEL_68;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Received Assoc without SSID IE",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "sir_convert_assoc_req_frame2_struct");
    }
    v58 = 1;
LABEL_68:
    _qdf_mem_free((__int64)v16);
    return v58;
  }
  return 1;
}
