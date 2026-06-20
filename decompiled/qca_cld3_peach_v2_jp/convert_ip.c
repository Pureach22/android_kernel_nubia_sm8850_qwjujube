__int64 __fastcall convert_ip(char *a1)
{
  char *v1; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v10; // w19
  char *v11; // x0
  char *v12; // x0
  char *v13; // x0
  char *v14; // x0
  char *v15; // x0
  __int64 v16; // x1
  char *stringp; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v19; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+18h] [xbp-8h] BYREF

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  stringp = a1;
  v19 = 0;
  v1 = strsep(&stringp, ".");
  if ( !v1 )
  {
    v10 = 0;
LABEL_15:
    qdf_trace_msg(0x61u, 8u, "%s: ip %u", v2, v3, v4, v5, v6, v7, v8, v9, "convert_ip", v10);
    goto LABEL_16;
  }
  if ( (unsigned int)kstrtou8(v1, 0, &v19) )
  {
LABEL_3:
    v10 = -22;
LABEL_16:
    _ReadStatusReg(SP_EL0);
    return v10;
  }
  v11 = strsep(&stringp, ".");
  if ( !v11 )
    goto LABEL_14;
  if ( (unsigned int)kstrtou8(v11, 0, (char *)&v19 + 1) )
    goto LABEL_3;
  v12 = strsep(&stringp, ".");
  if ( !v12 )
    goto LABEL_14;
  if ( (unsigned int)kstrtou8(v12, 0, (char *)&v19 + 2) )
    goto LABEL_3;
  v13 = strsep(&stringp, ".");
  if ( !v13 )
    goto LABEL_14;
  if ( (unsigned int)kstrtou8(v13, 0, (char *)&v19 + 3) )
    goto LABEL_3;
  v14 = strsep(&stringp, ".");
  if ( !v14 )
    goto LABEL_14;
  if ( (unsigned int)kstrtou8(v14, 0, &v20) )
    goto LABEL_3;
  v15 = strsep(&stringp, ".");
  if ( !v15 )
  {
LABEL_14:
    v10 = bswap32(v19);
    goto LABEL_15;
  }
  __break(0x5512u);
  return parse_ipv6(v15, v16);
}
