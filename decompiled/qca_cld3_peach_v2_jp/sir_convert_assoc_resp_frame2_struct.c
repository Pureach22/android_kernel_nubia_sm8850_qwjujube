// bad sp value at call has been detected, the output may be wrong!
void __fastcall sir_convert_assoc_resp_frame2_struct(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, __int64 a5)
{
  __int64 v9; // x0
  __int64 v10; // x5
  __int64 v11; // x6
  __int64 v12; // x7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _BYTE *v21; // x19
  unsigned int v22; // w22
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w8
  unsigned int v33; // w8
  unsigned int v34; // w8
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
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x25
  __int64 v55; // x4
  __int64 v56; // x5
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned int v81; // w8
  char v82; // w9
  __int16 v83; // w8
  unsigned int v84; // [xsp+A4h] [xbp-Ch] BYREF
  __int64 v85; // [xsp+A8h] [xbp-8h]

  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v84 = a4;
  v9 = _qdf_mem_malloc(0x1310u, "sir_convert_assoc_resp_frame2_struct", 4565);
  if ( !v9 )
    JUMPOUT(0x4071D0);
  v21 = (_BYTE *)v9;
  if ( **(_BYTE **)(a2 + 9976) == 1 && *(_WORD *)(a3 + 2) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: FILS: assoc reject Status code:%d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "sir_convert_assoc_resp_frame2_struct");
  }
  else if ( **(_BYTE **)(a2 + 9976) && !*(_WORD *)(a3 + 2) && (unsigned int)aead_decrypt_assoc_rsp(a1, a2, v9, a3, &v84) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: FILS assoc rsp AEAD decrypt fails",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "sir_convert_assoc_resp_frame2_struct");
    goto LABEL_54;
  }
  v22 = v84;
  v23 = dot11f_unpack_assoc_response(a1, a3, v84, (__int64)v21, 0, v10, v11, v12);
  if ( (v23 & 0x10000000) == 0 )
  {
    v32 = *(_WORD *)a5 & 0xFFFE | *(_WORD *)v21 & 1;
    *(_WORD *)a5 = *(_WORD *)a5 & 0xFFFE | *(_WORD *)v21 & 1;
    v33 = v32 & 0xFFFFFFFD | (2 * ((*(unsigned __int16 *)v21 >> 1) & 1));
    *(_WORD *)a5 = v33;
    v34 = v33 & 0xFFFFFFFB | (4 * ((*(unsigned __int16 *)v21 >> 2) & 1));
    *(_WORD *)a5 = v34;
    v35 = v34 & 0xFFFFFFF7 | (8 * ((*(unsigned __int16 *)v21 >> 3) & 1));
    *(_WORD *)a5 = v35;
    v36 = v35 & 0xFFFFFFEF | (16 * ((*(unsigned __int16 *)v21 >> 4) & 1));
    *(_WORD *)a5 = v36;
    v37 = v36 & 0xFFFFFFDF | (32 * ((*(unsigned __int16 *)v21 >> 5) & 1));
    *(_WORD *)a5 = v37;
    v38 = v37 & 0xFFFFFFBF | (((*(unsigned __int16 *)v21 >> 6) & 1) << 6);
    *(_WORD *)a5 = v38;
    v39 = v38 & 0xFFFFFF7F | (((*(unsigned __int16 *)v21 >> 7) & 1) << 7);
    *(_WORD *)a5 = v39;
    v40 = v39 & 0xFFFFFEFF | ((HIBYTE(*(unsigned __int16 *)v21) & 1) << 8);
    *(_WORD *)a5 = v40;
    v41 = v40 & 0xFFFFFDFF | (((*(unsigned __int16 *)v21 >> 9) & 1) << 9);
    *(_WORD *)a5 = v41;
    v42 = v41 & 0xFFFFFBFF | (((*(unsigned __int16 *)v21 >> 10) & 1) << 10);
    *(_WORD *)a5 = v42;
    v43 = v42 & 0xFFFFF7FF | (((*(unsigned __int16 *)v21 >> 11) & 1) << 11);
    *(_WORD *)a5 = v43;
    v44 = v43 & 0xFFFFEFFF | (((*(unsigned __int16 *)v21 >> 12) & 1) << 12);
    *(_WORD *)a5 = v44;
    v45 = v44 & 0xFFFFDFFF | (((*(unsigned __int16 *)v21 >> 13) & 1) << 13);
    *(_WORD *)a5 = v45;
    LOWORD(v45) = v45 & 0xBFFF | (((*(_WORD *)v21 >> 14) & 1) << 14);
    *(_WORD *)a5 = v45;
    *(_WORD *)a5 = *(_WORD *)v21 & 0x8000 | v45 & 0x7FFF;
    *(_WORD *)(a5 + 4) = *((_WORD *)v21 + 1);
    *(_WORD *)(a5 + 2) = *((_WORD *)v21 + 2);
    if ( v21[292] )
    {
      *(_BYTE *)(a5 + 2400) = 1;
      *(_BYTE *)(a5 + 2401) = v21[293];
      *(_DWORD *)(a5 + 2404) = *((_DWORD *)v21 + 74);
    }
    if ( v21[6] )
    {
      *(_BYTE *)(a5 + 2284) = 1;
      convert_supp_rates(a1, a5 + 6, v21 + 6);
    }
    else
    {
      *(_BYTE *)(a5 + 2284) = 0;
      v54 = jiffies;
      if ( sir_convert_assoc_resp_frame2_struct___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Mandatory IE Supported Rates not present!",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "sir_convert_assoc_resp_frame2_struct");
        sir_convert_assoc_resp_frame2_struct___last_ticks = v54;
      }
    }
    if ( v21[20] )
    {
      *(_BYTE *)(a5 + 2285) = 1;
      convert_ext_supp_rates(a1, a5 + 19, v21 + 20);
    }
    if ( v21[34] )
    {
      *(_BYTE *)(a5 + 2286) = 1;
      convert_edca_param(a1, a5 + 32, v21 + 34);
    }
    if ( v21[4190] )
    {
      *(_BYTE *)(a5 + 2287) = 1;
      convert_wmm_params(a1, a5 + 32, v21 + 4190);
    }
    if ( v21[300] )
      qdf_mem_copy((void *)(a5 + 244), v21 + 300, 0x3Cu);
    if ( v21[360] )
      qdf_mem_copy((void *)(a5 + 304), v21 + 360, 0x3Au);
    if ( v21[58] )
      qdf_mem_copy((void *)(a5 + 2408), v21 + 58, 6u);
    if ( v21[64] )
    {
      *(_BYTE *)(a5 + 2291) = 1;
      qdf_mem_copy((void *)(a5 + 760), v21 + 66, 2u);
      v55 = *(unsigned __int8 *)(a5 + 760);
      v56 = *(unsigned __int8 *)(a5 + 761);
      *(_BYTE *)(a5 + 762) = v21[68] & 3;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: new mdie=%02x%02x%02x",
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        "sir_convert_assoc_resp_frame2_struct",
        v55,
        v56);
    }
    if ( (lim_is_sha384_akm(*(_DWORD *)(a2 + 156)) & 1) != 0 )
    {
      if ( (unsigned int)wlan_parse_ftie_sha384((unsigned __int8 *)(a3 + 6), (unsigned __int16)v84 - 6, a5) )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: FT IE parsing failed status:%d",
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          "sir_convert_assoc_resp_frame2_struct",
          0);
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: FT: R0KH present:%d len:%d R1KH present%d",
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          "sir_convert_assoc_resp_frame2_struct",
          *(unsigned __int8 *)(a5 + 689),
          *(unsigned __int8 *)(a5 + 690),
          *(unsigned __int8 *)(a5 + 672));
        v21[70] = 0;
      }
    }
    else if ( v21[70] )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: FT: R0KH present:%d, len:%d R1KH present:%d",
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        "sir_convert_assoc_resp_frame2_struct",
        (unsigned __int8)v21[206],
        (unsigned __int8)v21[207],
        (unsigned __int8)v21[153]);
      *(_BYTE *)(a5 + 2290) = 1;
      qdf_mem_copy((void *)(a5 + 362), v21 + 70, 0xDCu);
    }
    v81 = *((unsigned __int16 *)v21 + 730);
    if ( v81 - 1 <= 1 )
    {
      if ( v21[1464] )
      {
        qdf_mem_copy((void *)(a5 + 764), v21 + 1464, 0x27Cu);
        v81 = *((unsigned __int16 *)v21 + 730);
      }
      v82 = v81;
      if ( v81 >= 2 )
      {
        if ( v21[2100] )
        {
          qdf_mem_copy((void *)(a5 + 1400), v21 + 2100, 0x27Cu);
          v81 = *((unsigned __int16 *)v21 + 730);
          v82 = *((_WORD *)v21 + 730);
        }
        if ( v81 > 2 )
          JUMPOUT(0x40720C);
      }
      *(_BYTE *)(a5 + 763) = v82;
      *(_BYTE *)(a5 + 2292) = 1;
    }
    v83 = *((_WORD *)v21 + 2111);
    if ( v83 )
    {
      *(_BYTE *)(a5 + 2036) = v83;
      if ( *((_WORD *)v21 + 2111) )
      {
        qdf_mem_copy((void *)(a5 + 2040), v21 + 4224, 0x3Cu);
        if ( *((unsigned __int16 *)v21 + 2111) >= 2u )
        {
          qdf_mem_copy((void *)(a5 + 2100), v21 + 4284, 0x3Cu);
          if ( *((unsigned __int16 *)v21 + 2111) >= 3u )
          {
            qdf_mem_copy((void *)(a5 + 2160), v21 + 4344, 0x3Cu);
            if ( *((unsigned __int16 *)v21 + 2111) >= 4u )
            {
              qdf_mem_copy((void *)(a5 + 2220), v21 + 4404, 0x3Cu);
              JUMPOUT(0x406C30);
            }
          }
        }
      }
      JUMPOUT(0x406C58);
    }
    JUMPOUT(0x406C60);
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Failed to parse an Association Response (0x%08x, %d bytes):",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "dot11f_parse_assoc_response",
    v23,
    v22);
  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 2, a3, v22);
LABEL_54:
  JUMPOUT(0x4071C8);
}
