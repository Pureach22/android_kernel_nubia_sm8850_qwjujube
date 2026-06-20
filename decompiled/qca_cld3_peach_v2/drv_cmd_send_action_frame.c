__int64 __fastcall drv_cmd_send_action_frame(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  int v13; // w4
  const char *v14; // x2
  const char *v15; // x3
  __int64 result; // x0
  __int64 v17; // x19
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x3
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w8
  unsigned int v30; // w19
  int v31; // w9
  const char *v32; // x2
  size_t v33; // x0
  char *v34; // x0
  int v35; // w4
  __int64 v37; // x20
  unsigned int v38; // w4
  int v39; // w0
  unsigned int v40; // w20
  size_t v41; // x0
  char *v42; // x0
  char *i; // x8
  __int64 v44; // x22
  int v45; // w9
  int v46; // w10
  unsigned __int8 v47; // w24
  __int64 v48; // x0
  __int64 v49; // x21
  __int64 v50; // x23
  _BYTE *v51; // x26
  unsigned __int64 v52; // x24
  __int64 v53; // x25
  char v54; // w22
  __int64 v55; // x4
  unsigned int v56; // w19
  __int64 v57; // [xsp+0h] [xbp-40h] BYREF
  char *s; // [xsp+8h] [xbp-38h] BYREF
  int v59; // [xsp+10h] [xbp-30h] BYREF
  __int16 v60; // [xsp+14h] [xbp-2Ch]
  _QWORD v61[5]; // [xsp+18h] [xbp-28h] BYREF

  v61[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_DWORD *)(a13 + 12);
  if ( v13 <= 33 )
  {
    v14 = "%s: Invalid command (total_len=%d)";
    v15 = "hdd_parse_sendactionframe";
LABEL_3:
    qdf_trace_msg(0x33u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, v15);
LABEL_4:
    result = 4294967274LL;
    goto LABEL_9;
  }
  v17 = *a1;
  if ( !*(_BYTE *)(a11 + 33) )
  {
    v31 = v13 - 48;
    WORD2(v61[0]) = 0;
    LODWORD(v61[0]) = 0;
    LODWORD(s) = 0;
    if ( (unsigned int)v13 <= 0x30 )
    {
      v32 = "%s: Invalid command len";
LABEL_12:
      qdf_trace_msg(0x33u, 2u, v32, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_parse_sendactionframe_v2");
      goto LABEL_4;
    }
    v35 = *(_DWORD *)(a11 + 44);
    if ( (unsigned int)(v35 - 1041) < 0xFFFFFBF0 || v35 > v31 )
    {
      v14 = "%s: Invalid payload length: %d";
    }
    else
    {
      v37 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v17 + 52832) + 32LL) + 216LL);
      if ( (mac_pton(a11 + 16, v61) & 1) == 0 )
      {
        v32 = "%s: MAC address parsing failed";
        goto LABEL_12;
      }
      v38 = *(_DWORD *)(a11 + 36);
      if ( v38 < 0xAE )
      {
        if ( (*(_DWORD *)(a11 + 40) & 0x80000000) != 0 )
        {
          v14 = "%s: Invalid dwell_time: %d";
          v15 = "hdd_parse_sendactionframe_v2";
          goto LABEL_3;
        }
        if ( (hdd_check_and_fill_freq(v38, &s, v37) & 1) != 0 )
        {
          result = hdd_sendactionframe(
                     v17,
                     v61,
                     (unsigned int)s,
                     *(unsigned int *)(a11 + 40),
                     *(unsigned int *)(a11 + 44),
                     a11 + 48);
          goto LABEL_9;
        }
      }
      v14 = "%s: Invalid channel: %d";
    }
    v15 = "hdd_parse_sendactionframe_v2";
    goto LABEL_3;
  }
  v18 = *(_QWORD *)(v17 + 52832);
  v57 = 0;
  s = (char *)a11;
  v60 = 0;
  v19 = *(_QWORD *)(v18 + 32);
  v59 = 0;
  v20 = *(_QWORD *)(v19 + 216);
  memset(v61, 0, 32);
  if ( (unsigned int)hdd_parse_bssid_and_chan(&s, &v59, &v57, v20) )
    goto LABEL_7;
  v33 = strlen(s);
  v34 = (char *)strnchr(s, v33, 32);
  s = v34;
  if ( !v34 )
    goto LABEL_7;
  while ( *v34 == 32 )
    s = ++v34;
  if ( !*v34 || sscanf(v34, "%31s ", v61) != 1 )
    goto LABEL_7;
  v39 = kstrtoint(v61, 10, (char *)&v57 + 4);
  v29 = -22;
  if ( v39 < 0 )
    goto LABEL_8;
  v40 = HIDWORD(v57);
  if ( v57 < 0 )
    goto LABEL_8;
  v41 = strlen(s);
  v42 = (char *)strnchr(s, v41, 32);
  s = v42;
  if ( !v42 )
    goto LABEL_7;
  for ( i = v42 + 1; *(i - 1) == 32; s = i++ )
    ;
  if ( !*(i - 1) )
    goto LABEL_7;
  v44 = 0;
  v45 = 1;
  do
  {
    v46 = (unsigned __int8)i[v44];
    v47 = v45++;
    ++v44;
  }
  while ( v46 );
  if ( !(_BYTE)v44 )
  {
LABEL_7:
    v29 = -22;
LABEL_8:
    v30 = v29;
    qdf_trace_msg(0x33u, 2u, "Failed to parse send action frame data", v21, v22, v23, v24, v25, v26, v27, v28);
    result = v30;
    goto LABEL_9;
  }
  v48 = _qdf_mem_malloc(((unsigned int)(unsigned __int8)v44 + 1) >> 1, "hdd_parse_send_action_frame_v1_data", 510);
  if ( !v48 )
  {
    v29 = -12;
    goto LABEL_8;
  }
  v49 = v48;
  if ( (_BYTE)v44 )
  {
    v50 = 0;
    v51 = (_BYTE *)v48;
    v52 = v47 - 1LL;
    v53 = (v52 >> 1) + 1;
    do
    {
      v54 = hex_to_bin((unsigned __int8)s[v50]);
      if ( v52 != v50 )
        v54 = hex_to_bin((unsigned __int8)s[v50 + 1]) | (16 * v54);
      --v53;
      v50 += 2;
      *v51++ = v54;
    }
    while ( v53 );
    v55 = (unsigned __int8)(((unsigned int)v52 >> 1) + 1);
  }
  else
  {
    v55 = 0;
  }
  v56 = hdd_sendactionframe(v17, &v59, (unsigned int)v57, v40, v55, v49);
  _qdf_mem_free(v49);
  result = v56;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
