__int64 __fastcall dbglog_printf(
        unsigned int a1,
        unsigned __int16 a2,
        const char *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        char a17)
{
  const char *v17; // x20
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _QWORD arg[4]; // [xsp+28h] [xbp-C8h] BYREF
  char *v28; // [xsp+48h] [xbp-A8h]
  _QWORD *v29; // [xsp+50h] [xbp-A0h]
  __int64 v30; // [xsp+58h] [xbp-98h]
  __int64 v31; // [xsp+60h] [xbp-90h]
  char s[8]; // [xsp+68h] [xbp-88h] BYREF
  __int64 v33; // [xsp+70h] [xbp-80h]
  __int64 v34; // [xsp+78h] [xbp-78h]
  __int64 v35; // [xsp+80h] [xbp-70h]
  __int64 v36; // [xsp+88h] [xbp-68h]
  __int64 v37; // [xsp+90h] [xbp-60h]
  __int64 v38; // [xsp+98h] [xbp-58h]
  __int64 v39; // [xsp+A0h] [xbp-50h]
  __int64 v40; // [xsp+A8h] [xbp-48h]
  __int64 v41; // [xsp+B0h] [xbp-40h]
  __int64 v42; // [xsp+B8h] [xbp-38h]
  __int64 v43; // [xsp+C0h] [xbp-30h]
  __int64 v44; // [xsp+C8h] [xbp-28h]
  __int64 v45; // [xsp+D0h] [xbp-20h]
  __int64 v46; // [xsp+D8h] [xbp-18h]
  __int64 v47; // [xsp+E0h] [xbp-10h]
  __int64 v48; // [xsp+E8h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  *(_QWORD *)s = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = nullptr;
  v29 = nullptr;
  if ( a2 > 0xEu )
  {
    if ( (dword_183E4 & 4) == 0 )
      goto LABEL_7;
    v17 = a3;
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: FWLOG: [%u] ",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      "dbglog_printf",
      a1,
      a4,
      a5,
      a6,
      a7,
      a8);
  }
  else
  {
    if ( (dword_183E4 & 4) == 0 )
      goto LABEL_7;
    v17 = a3;
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: FWLOG: [%u] vap-%u ",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      "dbglog_printf",
      a1,
      a4,
      a5,
      a6,
      a7,
      a8);
  }
  a3 = v17;
LABEL_7:
  v31 = 4294967256LL;
  v28 = &a17;
  v29 = arg;
  arg[0] = &a17;
  arg[1] = arg;
  arg[2] = v30;
  arg[3] = 4294967256LL;
  result = vsnprintf(s, 0x80u, a3, arg);
  if ( (dword_183E4 & 4) != 0 )
    result = qdf_trace_msg(0x38u, 2u, "%s: %s\n", v19, v20, v21, v22, v23, v24, v25, v26, "dbglog_printf", s);
  _ReadStatusReg(SP_EL0);
  return result;
}
