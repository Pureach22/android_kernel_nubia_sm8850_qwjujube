__int64 __fastcall target_if_spectral_hexdump(unsigned __int8 *a1, int a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  int v12; // w0
  int v13; // w8
  unsigned int v14; // w19
  __int64 v15; // x27
  const char *v16; // x2
  __int64 v17; // x4
  __int64 v18; // x22
  int v19; // w0
  int v20; // w8
  __int64 v21; // x10
  int v22; // w20
  __int64 v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w21
  int v33; // w0
  bool v34; // zf
  __int64 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  char v44; // [xsp+Ch] [xbp-74h]
  char s[8]; // [xsp+10h] [xbp-70h] BYREF
  __int64 v46; // [xsp+18h] [xbp-68h]
  __int64 v47; // [xsp+20h] [xbp-60h]
  __int64 v48; // [xsp+28h] [xbp-58h]
  __int64 v49; // [xsp+30h] [xbp-50h]
  __int64 v50; // [xsp+38h] [xbp-48h]
  __int64 v51; // [xsp+40h] [xbp-40h]
  __int64 v52; // [xsp+48h] [xbp-38h]
  __int64 v53; // [xsp+50h] [xbp-30h]
  __int64 v54; // [xsp+58h] [xbp-28h]
  char v55; // [xsp+60h] [xbp-20h]
  char v56[20]; // [xsp+64h] [xbp-1Ch] BYREF
  __int64 v57; // [xsp+78h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v56[2], 0, 15);
  v55 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  *(_QWORD *)s = 0;
  v46 = 0;
  qdf_mem_set(s, 0x51u, 0);
  if ( a2 >= 1 )
  {
    v12 = snprintf(s, 0x51u, " %02x", *a1);
    v13 = *a1;
    v14 = v12;
    v56[1] = 0;
    if ( (unsigned int)(v13 - 127) < 0xFFFFFFA1 )
      LOBYTE(v13) = 46;
    v56[0] = v13;
    if ( a2 == 1 )
    {
      LODWORD(v15) = 1;
    }
    else
    {
      v15 = (unsigned int)a2;
      v18 = 1;
      v44 = a2;
      do
      {
        v22 = v18 & 0xF;
        if ( (v18 & 0xF) != 0 )
        {
          if ( v14 >= 0x51 )
            goto LABEL_22;
          v23 = v14;
        }
        else
        {
          if ( v14 >= 0x51 )
            goto LABEL_22;
          snprintf(&s[v14], 81LL - v14, "  %s", v56);
          qdf_trace_msg(0x56u, 8u, "%s: %s", v24, v25, v26, v27, v28, v29, v30, v31, "target_if_spectral_hexdump", s);
          qdf_mem_set(s, 0x51u, 0);
          v23 = 0;
          v14 = 0;
        }
        v19 = snprintf(&s[v23], 81 - v23, " %02x", a1[v18]);
        v20 = a1[v18];
        v21 = v18++ & 0xF;
        v14 += v19;
        if ( (unsigned int)(v20 - 127) < 0xFFFFFFA1 )
          LOBYTE(v20) = 46;
        v56[v21] = v20;
        v56[v22 + 1] = 0;
      }
      while ( v15 != v18 );
      if ( (v44 & 0xF) == 0 )
      {
LABEL_21:
        if ( v14 < 0x51 )
        {
          snprintf(&s[v14], 81LL - v14, "  %s", v56);
          result = qdf_trace_msg(
                     0x56u,
                     8u,
                     "%s: %s",
                     v36,
                     v37,
                     v38,
                     v39,
                     v40,
                     v41,
                     v42,
                     v43,
                     "target_if_spectral_hexdump",
                     s);
          goto LABEL_24;
        }
        goto LABEL_22;
      }
    }
    v32 = v15 + 1;
    while ( v14 < 0x51 )
    {
      v33 = snprintf(&s[v14], 81LL - v14, "   ");
      v34 = (v32++ & 0xF) == 0;
      v14 += v33;
      if ( v34 )
        goto LABEL_21;
    }
LABEL_22:
    v16 = "%s: loc index is %u, greater than hexdump_line array size";
    v17 = v14;
    goto LABEL_23;
  }
  v16 = "%s: buffer len is %d, too short";
  v17 = (unsigned int)a2;
LABEL_23:
  result = qdf_trace_msg(0x56u, 2u, v16, v4, v5, v6, v7, v8, v9, v10, v11, "target_if_spectral_hexdump", v17);
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
