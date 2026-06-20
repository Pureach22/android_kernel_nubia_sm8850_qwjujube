__int64 __fastcall hdd_drv_cmd_process(
        _QWORD *a1,
        char *s,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *v12; // x27
  unsigned int v13; // w0
  __int64 v14; // x22
  __int64 v15; // x23
  unsigned int v16; // w28
  _BYTE *i; // x20
  _DWORD *v18; // x21
  int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w24
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  if ( a3 )
  {
    v12 = (_QWORD *)*a1;
    v13 = (unsigned int)strchrnul(s, 32);
    v14 = v12[3];
    v15 = 0;
    v16 = v13 - (_DWORD)s;
    for ( i = &unk_A06340; ; i += 24 )
    {
      v18 = *((_DWORD **)i - 1);
      v19 = strlen(*((const char **)i - 2));
      if ( !v18 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: no. %d handler is NULL",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "hdd_drv_cmd_process",
          (unsigned int)v15);
        return 4294967274LL;
      }
      v28 = v19;
      if ( v19 == v16 && !strncasecmp(s, *((const char **)i - 2), v19) )
        break;
      if ( ++v15 == 91 )
      {
        qdf_mtrace(51, 51, 0x3Bu, *(_BYTE *)(v12[6603] + 8LL), 0);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: %s: Unsupported driver command \"%s\"",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "drv_cmd_invalid",
          v12[4] + 296LL,
          s);
        return 4294966772LL;
      }
    }
    if ( *i == 1 && s[v28] != 32 )
    {
      return 4294967274LL;
    }
    else
    {
      if ( *(v18 - 1) != 1444641385 )
        __break(0x8235u);
      return ((__int64 (__fastcall *)(_QWORD *, __int64, char *, _QWORD, __int64))v18)(a1, v14, s, v28, a3);
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: at least 1 param is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_drv_cmd_process");
    return 4294967274LL;
  }
}
