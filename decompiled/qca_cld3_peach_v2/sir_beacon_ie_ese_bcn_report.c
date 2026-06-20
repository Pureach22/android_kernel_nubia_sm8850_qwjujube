__int64 __fastcall sir_beacon_ie_ese_bcn_report(
        __int64 a1,
        unsigned int *a2,
        unsigned int a3,
        __int64 *a4,
        unsigned int *a5)
{
  unsigned int v10; // w24
  void *v11; // x0
  __int64 v12; // x19
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x7
  unsigned int v16; // w0
  __int64 v17; // x3
  __int64 v18; // x5
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x4
  unsigned int v28; // w26
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w25
  const char *v39; // x2
  __int64 v40; // x10
  __int64 v41; // x11
  __int64 v42; // x9
  __int64 v43; // x9
  __int64 v44; // x8
  __int64 v45; // x11
  unsigned int v46; // w0
  __int64 v47; // x3
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w23
  __int64 v66; // x25
  __int16 v67; // w9
  _BYTE *v68; // x0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  int v77; // w8
  const char *v78; // x2
  _BYTE *v79; // x21
  size_t v80; // x2
  _BYTE *v81; // x21
  size_t v82; // x2
  _BYTE *v83; // x21
  _BYTE *v84; // x21
  _BYTE *v85; // x21
  _QWORD v86[7]; // [xsp+0h] [xbp-190h] BYREF
  int v87; // [xsp+38h] [xbp-158h]
  _WORD s[166]; // [xsp+3Ch] [xbp-154h] BYREF
  __int64 v89; // [xsp+188h] [xbp-8h]

  v89 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v10 = *a2;
  qdf_mem_set(s, 0x14Cu, 0);
  v11 = (void *)_qdf_mem_malloc(0x1490u, "sir_beacon_ie_ese_bcn_report", 5169);
  if ( v11 )
  {
    v12 = (__int64)v11;
    qdf_mem_set(v11, 0x1490u, 0);
    v16 = dot11f_unpack_beacon_i_es(a1, (__int64)a2, a3, v12, 0, v13, v14, v15);
    v27 = v16;
    if ( (v16 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to parse Beacon IEs (0x%08x, %d bytes):",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "sir_beacon_ie_ese_bcn_report",
        v16,
        a3);
LABEL_9:
      v38 = 16;
LABEL_13:
      _qdf_mem_free(v12);
      goto LABEL_14;
    }
    if ( v16 )
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: There were warnings while unpacking Beacon IEs (0x%08x, %d bytes):",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "sir_beacon_ie_ese_bcn_report",
        v16,
        a3);
    v28 = a3 - 12;
    v29 = lim_strip_and_decode_eht_op(a2 + 3, a3 - 12, v12 + 2588, v17, v27, v18);
    if ( v29 )
    {
      v38 = v29;
      v39 = "%s: Failed to extract eht op";
LABEL_12:
      qdf_trace_msg(0x35u, 2u, v39, v30, v31, v32, v33, v34, v35, v36, v37, "sir_beacon_ie_ese_bcn_report");
      goto LABEL_13;
    }
    v40 = *(_QWORD *)(v12 + 2284);
    v41 = *(_QWORD *)(v12 + 2292);
    v87 = *(_DWORD *)(v12 + 2308);
    v42 = *(_QWORD *)(v12 + 2300);
    v86[4] = v40;
    v86[5] = v41;
    v86[6] = v42;
    v43 = *(_QWORD *)(v12 + 2260);
    v45 = *(_QWORD *)(v12 + 2268);
    v44 = *(_QWORD *)(v12 + 2276);
    v86[0] = *(_QWORD *)(v12 + 2252);
    v86[1] = v43;
    v86[2] = v45;
    v86[3] = v44;
    v46 = lim_strip_and_decode_eht_cap(a2 + 3, v28, v12 + 2496, v86, v10, 0);
    if ( v46 )
    {
      v38 = v46;
      v39 = "%s: Failed to extract eht cap";
      goto LABEL_12;
    }
    if ( (unsigned int)lim_strip_and_decode_tpe_ie(a2 + 3, v28, v12 + 1432, v47) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to extract tpe IE",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "sir_beacon_ie_ese_bcn_report");
      goto LABEL_9;
    }
    if ( *(_BYTE *)v12 )
    {
      LOBYTE(s[162]) = 1;
      convert_ssid(a1, s, v12);
      v65 = LOBYTE(s[0]) + 2;
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Mandatory IE SSID not present!",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "sir_beacon_ie_ese_bcn_report");
      v65 = 0;
    }
    if ( *(_BYTE *)(v12 + 34) )
    {
      HIBYTE(s[162]) = 1;
      convert_supp_rates(a1, &s[17], v12 + 34);
      v65 += LOBYTE(s[17]) + 2;
    }
    else
    {
      v66 = jiffies;
      if ( sir_beacon_ie_ese_bcn_report___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Mandatory IE Supported Rates not present!",
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          "sir_beacon_ie_ese_bcn_report");
        sir_beacon_ie_ese_bcn_report___last_ticks = v66;
      }
    }
    if ( *(_BYTE *)(v12 + 48) )
    {
      LOBYTE(s[163]) = 1;
      convert_fh_params(a1, &s[24], v12 + 48);
      v65 += 7;
    }
    if ( *(_BYTE *)(v12 + 56) )
    {
      v65 += 3;
      HIBYTE(s[163]) = 1;
      LOBYTE(s[28]) = *(_BYTE *)(v12 + 57);
    }
    if ( *(_BYTE *)(v12 + 58) )
    {
      LOBYTE(s[164]) = 1;
      convert_cf_params(a1, (char *)&s[28] + 1, v12 + 58);
      v65 += 8;
    }
    if ( *(_BYTE *)(v12 + 66) )
    {
      v65 += 5;
      HIBYTE(s[164]) = 1;
      v67 = *(_WORD *)(v12 + 68);
      HIBYTE(s[31]) = *(_BYTE *)(v12 + 67);
      s[32] = v67;
    }
    if ( *(_BYTE *)(v12 + 1201) )
    {
      LOBYTE(s[165]) = 1;
      qdf_mem_copy(&s[159], (const void *)(v12 + 1201), 6u);
      v65 += 7;
    }
    v68 = (_BYTE *)_qdf_mem_malloc(v65, "sir_beacon_ie_ese_bcn_report", 5277);
    *a4 = (__int64)v68;
    if ( !v68 )
    {
      v38 = 2;
      goto LABEL_13;
    }
    v77 = LOBYTE(s[162]);
    *a5 = v65;
    if ( v77 )
    {
      if ( (unsigned int)LOBYTE(s[0]) + 2 > v65 )
      {
        v78 = "%s: Insufficient memory to copy SSID";
LABEL_67:
        qdf_trace_msg(0x35u, 2u, v78, v69, v70, v71, v72, v73, v74, v75, v76, "sir_beacon_ie_ese_bcn_report");
        _qdf_mem_free(*a4);
        *a4 = 0;
        goto LABEL_9;
      }
      *v68 = 0;
      v79 = v68 + 2;
      v80 = LOBYTE(s[0]);
      v68[1] = s[0];
      qdf_mem_copy(v68 + 2, (char *)s + 1, v80);
      v68 = &v79[LOBYTE(s[0])];
      LOWORD(v65) = v65 - LOBYTE(s[0]) - 2;
    }
    if ( HIBYTE(s[162]) )
    {
      if ( (unsigned int)LOBYTE(s[17]) + 2 > (unsigned __int16)v65 )
      {
        v78 = "%s: Insufficient memory to copy Rates IE";
        goto LABEL_67;
      }
      if ( LOBYTE(s[17]) <= 0xCu )
      {
        v81 = v68 + 2;
        *v68 = 1;
        v82 = LOBYTE(s[17]);
        v68[1] = s[17];
        qdf_mem_copy(v68 + 2, (char *)&s[17] + 1, v82);
        v68 = &v81[LOBYTE(s[17])];
        LOWORD(v65) = v65 - LOBYTE(s[17]) - 2;
      }
    }
    if ( LOBYTE(s[163]) )
    {
      if ( (unsigned __int16)v65 < 7u )
      {
        v78 = "%s: Insufficient memory to copy FHIE";
        goto LABEL_67;
      }
      v83 = v68;
      *(_WORD *)v68 = 1282;
      qdf_mem_copy(v68 + 2, &s[24], 5u);
      LOWORD(v65) = v65 - 7;
      v68 = v83 + 7;
    }
    if ( HIBYTE(s[163]) )
    {
      if ( (unsigned __int16)v65 < 3u )
      {
        v78 = "%s: Insufficient memory to copy DS IE";
        goto LABEL_67;
      }
      LOWORD(v65) = v65 - 3;
      *(_WORD *)v68 = 259;
      v68[2] = s[28];
      v68 += 3;
    }
    if ( LOBYTE(s[164]) )
    {
      if ( (unsigned __int16)v65 < 8u )
      {
        v78 = "%s: Insufficient memory to copy CF IE";
        goto LABEL_67;
      }
      v84 = v68;
      *(_WORD *)v68 = 1540;
      qdf_mem_copy(v68 + 2, (char *)&s[28] + 1, 6u);
      LOWORD(v65) = v65 - 8;
      v68 = v84 + 8;
    }
    if ( HIBYTE(s[164]) )
    {
      if ( (unsigned __int16)v65 < 5u )
      {
        v78 = "%s: Insufficient memory to copy TIM IE";
        goto LABEL_67;
      }
      v85 = v68;
      *(_WORD *)v68 = 773;
      qdf_mem_copy(v68 + 2, (char *)&s[31] + 1, 3u);
      LOWORD(v65) = v65 - 5;
      v68 = v85 + 5;
    }
    if ( LOBYTE(s[165]) )
    {
      if ( (unsigned __int16)v65 < 7u )
      {
        v78 = "%s: Insufficient memory to copy RRM IE";
        goto LABEL_67;
      }
      *(_WORD *)v68 = 1350;
      qdf_mem_copy(v68 + 2, &s[159], 5u);
      LOWORD(v65) = v65 - 7;
    }
    if ( !(_WORD)v65 )
    {
      v38 = 0;
      goto LABEL_13;
    }
    v78 = "%s: Mismatch in allocation and copying of IE in Bcn Rep";
    goto LABEL_67;
  }
  v38 = 2;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v38;
}
