__int64 __fastcall qdf_ini_parse(
        char *s2,
        __int64 a2,
        unsigned int (__fastcall *a3)(__int64, const char *, __int64),
        __int64 a4,
        void (__fastcall *a5)(__int64, __int64, __int64))
{
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w22
  __int64 v18; // x1
  __int64 v19; // x2
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const char *v36; // x2
  unsigned int v37; // w22
  const char *v38; // x26
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x2
  unsigned int v49; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v50; // [xsp+10h] [xbp-30h] BYREF
  __int64 v51; // [xsp+18h] [xbp-28h] BYREF
  _BYTE v52[4]; // [xsp+24h] [xbp-1Ch] BYREF
  __int64 v53; // [xsp+28h] [xbp-18h] BYREF
  const char *v54[2]; // [xsp+30h] [xbp-10h] BYREF

  v54[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v51 = 0;
  v49 = 0;
  if ( !strcmp("wifi_module_param.ini", s2) )
  {
    v17 = 4;
    goto LABEL_9;
  }
  v17 = qdf_file_read(s2, &v51, &v49);
  if ( !a5 || v17 )
  {
    if ( !v17 )
      goto LABEL_10;
LABEL_9:
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Failed to read *.ini file @ %s",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "qdf_ini_parse",
      s2);
    goto LABEL_27;
  }
  v18 = v51;
  v19 = v49;
  if ( *((_DWORD *)a5 - 1) != 1357656746 )
    __break(0x8237u);
  a5(a2, v18, v19);
LABEL_10:
  v53 = 0;
  v54[0] = nullptr;
  v52[0] = 0;
  v50 = v51;
  if ( (unsigned int)qdf_ini_read_values(&v50, v54, &v53, v52) )
  {
    qdf_trace_msg(0x38u, 4u, "%s: INI values read: %d", v20, v21, v22, v23, v24, v25, v26, v27, "qdf_ini_parse", 0);
LABEL_12:
    v17 = 4;
    v36 = "%s: INI file parse fail: invalid file format";
    goto LABEL_25;
  }
  v37 = 0;
  do
  {
    v38 = v54[0];
    if ( !strcmp(v54[0], "END") )
      break;
    if ( (v52[0] & 1) != 0 )
    {
      qdf_trace_msg(
        0x38u,
        8u,
        "%s: Section started in global file",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "qdf_ini_parse");
    }
    else
    {
      v47 = v53;
      if ( *((_DWORD *)a3 - 1) != -269852048 )
        __break(0x8234u);
      if ( a3(a2, v38, v47) )
        break;
      ++v37;
    }
  }
  while ( !(unsigned int)qdf_ini_read_values(&v50, v54, &v53, v52) );
  qdf_trace_msg(0x38u, 4u, "%s: INI values read: %d", v39, v40, v41, v42, v43, v44, v45, v46, "qdf_ini_parse", v37);
  if ( !v37 )
    goto LABEL_12;
  v17 = 0;
  v36 = "%s: INI file parse successful";
LABEL_25:
  qdf_trace_msg(0x38u, 4u, v36, v28, v29, v30, v31, v32, v33, v34, v35, "qdf_ini_parse");
  if ( strcmp("wifi_module_param.ini", s2) )
    qdf_file_buf_free(v51);
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return v17;
}
