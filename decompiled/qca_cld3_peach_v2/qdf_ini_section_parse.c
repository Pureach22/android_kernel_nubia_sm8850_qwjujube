__int64 __fastcall qdf_ini_section_parse(
        char *s2,
        __int64 a2,
        unsigned int (__fastcall *a3)(__int64, const char *, __int64),
        const char *a4)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w23
  char v34; // w26
  bool v35; // w27
  int v36; // w0
  char v37; // w8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  const char *v46; // x25
  __int64 v47; // x2
  _BYTE *v49; // [xsp+0h] [xbp-30h] BYREF
  _BYTE *v50; // [xsp+8h] [xbp-28h] BYREF
  _BYTE v51[4]; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v52; // [xsp+18h] [xbp-18h] BYREF
  const char *v53[2]; // [xsp+20h] [xbp-10h] BYREF

  v53[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v50 = nullptr;
  if ( !strcmp("wifi_module_param.ini", s2) )
  {
    v16 = 4;
    goto LABEL_7;
  }
  v53[0] = nullptr;
  v52 = 0;
  v51[0] = 0;
  v49 = nullptr;
  v16 = qdf_file_read(s2, (__int64 *)&v50, nullptr);
  if ( v16 )
  {
LABEL_7:
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Failed to read *.ini file @ %s",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "qdf_ini_section_parse",
      s2,
      v49);
    goto LABEL_24;
  }
  v49 = v50;
  if ( (unsigned int)qdf_ini_read_values(&v49, v53, &v52, v51) )
  {
    qdf_trace_msg(
      0x38u,
      4u,
      "%s: INI values parse successful read: %d from section %s",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "qdf_ini_section_parse",
      0,
      a4);
  }
  else
  {
    v33 = 0;
    v34 = 0;
    v35 = 0;
    do
    {
      v46 = v53[0];
      if ( !strcmp(v53[0], "END") )
        break;
      if ( v51[0] == 1 )
      {
        v36 = strcmp(v46, a4);
        v37 = v35 | v34;
        v35 = v36 == 0;
        v34 = (v36 != 0) & v37;
      }
      else if ( v35 )
      {
        v47 = v52;
        if ( *((_DWORD *)a3 - 1) != -269852048 )
          __break(0x8235u);
        if ( a3(a2, v46, v47) )
          break;
        ++v33;
        v35 = 1;
      }
      else
      {
        if ( (v34 & 1) != 0 )
          break;
        v35 = 0;
        v34 = 0;
      }
    }
    while ( !(unsigned int)qdf_ini_read_values(&v49, v53, &v52, v51) );
    qdf_trace_msg(
      0x38u,
      4u,
      "%s: INI values parse successful read: %d from section %s",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "qdf_ini_section_parse",
      v33,
      a4);
    if ( v33 )
      goto LABEL_21;
  }
  qdf_trace_msg(
    0x38u,
    8u,
    "%s: INI file parse fail: Section not found %s",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "qdf_ini_section_parse",
    a4);
LABEL_21:
  if ( strcmp("wifi_module_param.ini", s2) )
    qdf_file_buf_free((__int64)v50);
  v16 = 0;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return v16;
}
