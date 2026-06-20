__int64 __fastcall drv_cmd_set_antenna_mode(__int64 *a1, int a2, char *s)
{
  size_t v5; // x0
  const char *v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w8
  const char *v16; // x2
  char v17; // t1
  unsigned int v18; // w20
  unsigned int v20; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v21[5]; // [xsp+8h] [xbp-28h] BYREF

  v21[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  memset(v21, 0, 32);
  v5 = strlen(s);
  v6 = (const char *)strnchr(s, v5, 32);
  if ( !v6 )
  {
    v16 = "%s: No argument after the command";
    goto LABEL_9;
  }
  v15 = *(unsigned __int8 *)v6;
  if ( v15 != 32 )
  {
    v16 = "%s: No space after the command";
LABEL_9:
    qdf_trace_msg(0x33u, 2u, v16, v7, v8, v9, v10, v11, v12, v13, v14, "hdd_parse_setantennamode_command");
    v18 = -22;
    goto LABEL_10;
  }
  while ( (unsigned __int8)v15 == 32 )
  {
    v17 = *++v6;
    LOBYTE(v15) = v17;
  }
  if ( !(_BYTE)v15 )
  {
    v16 = "%s: No argument followed by spaces";
    goto LABEL_9;
  }
  if ( sscanf(v6, "%31s ", v21) != 1 )
  {
    v16 = "%s: argument retrieval from cmd string failed";
    goto LABEL_9;
  }
  if ( (kstrtoint(v21, 10, &v20) & 0x80000000) != 0 )
  {
    v16 = "%s: argument string to int conversion failed";
    goto LABEL_9;
  }
  v18 = v20;
  if ( (v20 & 0x80000000) == 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Processing antenna mode switch to: %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "drv_cmd_set_antenna_mode",
      v20);
    v18 = hdd_set_antenna_mode(a1, v18);
    goto LABEL_11;
  }
LABEL_10:
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Invalid SETANTENNA command",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "drv_cmd_set_antenna_mode");
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v18;
}
