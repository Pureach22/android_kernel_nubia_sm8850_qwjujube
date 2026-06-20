__int64 __fastcall sir_beacon_ie_ese_bcn_report(__int64 a1, __int64 a2, unsigned int a3, __int64 *a4, unsigned int *a5)
{
  void *v10; // x0
  __int64 v11; // x19
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x7
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w23
  unsigned int v33; // w20
  __int64 v34; // x25
  __int16 v35; // w9
  _BYTE *v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // w8
  const char *v46; // x2
  _BYTE *v47; // x21
  size_t v48; // x2
  _BYTE *v49; // x21
  size_t v50; // x2
  _BYTE *v51; // x21
  _BYTE *v52; // x21
  _BYTE *v53; // x21
  _WORD s[166]; // [xsp+Ch] [xbp-154h] BYREF
  __int64 v56; // [xsp+158h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  qdf_mem_set(s, 0x14Cu, 0);
  v10 = (void *)_qdf_mem_malloc(0x1490u, "sir_beacon_ie_ese_bcn_report", 5169);
  if ( v10 )
  {
    v11 = (__int64)v10;
    qdf_mem_set(v10, 0x1490u, 0);
    v15 = dot11f_unpack_beacon_i_es(a1, a2, a3, v11, 0, v12, v13, v14);
    if ( (v15 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to parse Beacon IEs (0x%08x, %d bytes):",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sir_beacon_ie_ese_bcn_report",
        v15,
        a3);
LABEL_58:
      v33 = 16;
      goto LABEL_59;
    }
    if ( v15 )
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: There were warnings while unpacking Beacon IEs (0x%08x, %d bytes):",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sir_beacon_ie_ese_bcn_report",
        v15,
        a3);
    if ( *(_BYTE *)v11 )
    {
      LOBYTE(s[162]) = 1;
      convert_ssid(a1, s, v11);
      v32 = LOBYTE(s[0]) + 2;
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Mandatory IE SSID not present!",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sir_beacon_ie_ese_bcn_report");
      v32 = 0;
    }
    if ( *(_BYTE *)(v11 + 34) )
    {
      HIBYTE(s[162]) = 1;
      convert_supp_rates(a1, &s[17], v11 + 34);
      v32 += LOBYTE(s[17]) + 2;
    }
    else
    {
      v34 = jiffies;
      if ( sir_beacon_ie_ese_bcn_report___last_ticks - jiffies + 125 < 0 )
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
          "sir_beacon_ie_ese_bcn_report");
        sir_beacon_ie_ese_bcn_report___last_ticks = v34;
      }
    }
    if ( *(_BYTE *)(v11 + 48) )
    {
      LOBYTE(s[163]) = 1;
      convert_fh_params(a1, &s[24], v11 + 48);
      v32 += 7;
    }
    if ( *(_BYTE *)(v11 + 56) )
    {
      v32 += 3;
      HIBYTE(s[163]) = 1;
      LOBYTE(s[28]) = *(_BYTE *)(v11 + 57);
    }
    if ( *(_BYTE *)(v11 + 58) )
    {
      LOBYTE(s[164]) = 1;
      convert_cf_params(a1, (char *)&s[28] + 1, v11 + 58);
      v32 += 8;
    }
    if ( *(_BYTE *)(v11 + 66) )
    {
      v32 += 5;
      HIBYTE(s[164]) = 1;
      v35 = *(_WORD *)(v11 + 68);
      HIBYTE(s[31]) = *(_BYTE *)(v11 + 67);
      s[32] = v35;
    }
    if ( *(_BYTE *)(v11 + 1201) )
    {
      LOBYTE(s[165]) = 1;
      qdf_mem_copy(&s[159], (const void *)(v11 + 1201), 6u);
      v32 += 7;
    }
    v36 = (_BYTE *)_qdf_mem_malloc(v32, "sir_beacon_ie_ese_bcn_report", 5277);
    *a4 = (__int64)v36;
    if ( !v36 )
    {
      v33 = 2;
LABEL_59:
      _qdf_mem_free(v11);
      goto LABEL_60;
    }
    v45 = LOBYTE(s[162]);
    *a5 = v32;
    if ( v45 )
    {
      if ( (unsigned int)LOBYTE(s[0]) + 2 > v32 )
      {
        v46 = "%s: Insufficient memory to copy SSID";
LABEL_57:
        qdf_trace_msg(0x35u, 2u, v46, v37, v38, v39, v40, v41, v42, v43, v44, "sir_beacon_ie_ese_bcn_report");
        _qdf_mem_free(*a4);
        *a4 = 0;
        goto LABEL_58;
      }
      *v36 = 0;
      v47 = v36 + 2;
      v48 = LOBYTE(s[0]);
      v36[1] = s[0];
      qdf_mem_copy(v36 + 2, (char *)s + 1, v48);
      v36 = &v47[LOBYTE(s[0])];
      LOWORD(v32) = v32 - LOBYTE(s[0]) - 2;
    }
    if ( HIBYTE(s[162]) )
    {
      if ( (unsigned int)LOBYTE(s[17]) + 2 > (unsigned __int16)v32 )
      {
        v46 = "%s: Insufficient memory to copy Rates IE";
        goto LABEL_57;
      }
      if ( LOBYTE(s[17]) <= 0xCu )
      {
        v49 = v36 + 2;
        *v36 = 1;
        v50 = LOBYTE(s[17]);
        v36[1] = s[17];
        qdf_mem_copy(v36 + 2, (char *)&s[17] + 1, v50);
        v36 = &v49[LOBYTE(s[17])];
        LOWORD(v32) = v32 - LOBYTE(s[17]) - 2;
      }
    }
    if ( LOBYTE(s[163]) )
    {
      if ( (unsigned __int16)v32 < 7u )
      {
        v46 = "%s: Insufficient memory to copy FHIE";
        goto LABEL_57;
      }
      v51 = v36;
      *(_WORD *)v36 = 1282;
      qdf_mem_copy(v36 + 2, &s[24], 5u);
      LOWORD(v32) = v32 - 7;
      v36 = v51 + 7;
    }
    if ( HIBYTE(s[163]) )
    {
      if ( (unsigned __int16)v32 < 3u )
      {
        v46 = "%s: Insufficient memory to copy DS IE";
        goto LABEL_57;
      }
      LOWORD(v32) = v32 - 3;
      *(_WORD *)v36 = 259;
      v36[2] = s[28];
      v36 += 3;
    }
    if ( LOBYTE(s[164]) )
    {
      if ( (unsigned __int16)v32 < 8u )
      {
        v46 = "%s: Insufficient memory to copy CF IE";
        goto LABEL_57;
      }
      v52 = v36;
      *(_WORD *)v36 = 1540;
      qdf_mem_copy(v36 + 2, (char *)&s[28] + 1, 6u);
      LOWORD(v32) = v32 - 8;
      v36 = v52 + 8;
    }
    if ( HIBYTE(s[164]) )
    {
      if ( (unsigned __int16)v32 < 5u )
      {
        v46 = "%s: Insufficient memory to copy TIM IE";
        goto LABEL_57;
      }
      v53 = v36;
      *(_WORD *)v36 = 773;
      qdf_mem_copy(v36 + 2, (char *)&s[31] + 1, 3u);
      LOWORD(v32) = v32 - 5;
      v36 = v53 + 5;
    }
    if ( LOBYTE(s[165]) )
    {
      if ( (unsigned __int16)v32 < 7u )
      {
        v46 = "%s: Insufficient memory to copy RRM IE";
        goto LABEL_57;
      }
      *(_WORD *)v36 = 1350;
      qdf_mem_copy(v36 + 2, &s[159], 5u);
      LOWORD(v32) = v32 - 7;
    }
    if ( !(_WORD)v32 )
    {
      v33 = 0;
      goto LABEL_59;
    }
    v46 = "%s: Mismatch in allocation and copying of IE in Bcn Rep";
    goto LABEL_57;
  }
  v33 = 2;
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return v33;
}
