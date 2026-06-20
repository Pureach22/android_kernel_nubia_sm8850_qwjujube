__int64 __fastcall os_if_nan_parse_security_params(
        _QWORD *a1,
        _DWORD *a2,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5,
        _DWORD *a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v16; // x8
  _WORD *v19; // x8
  unsigned int v21; // w8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  _WORD *v30; // x8
  size_t v31; // x2
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  _WORD *v40; // x8
  size_t v41; // x2
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x8

  if ( a2 && a3 && a4 && a5 )
  {
    v16 = a1[17];
    if ( v16 )
      *a2 = *(_DWORD *)(v16 + 4);
    v19 = (_WORD *)a1[18];
    if ( v19 )
    {
      v21 = (unsigned __int16)(*v19 - 4);
      *a3 = v21;
      qdf_mem_copy(a3 + 1, (const void *)(a1[18] + 4LL), v21);
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: pmk len: %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "os_if_nan_parse_security_params",
        *a3);
      ((void (__fastcall *)(__int64, __int64, unsigned int *, _QWORD))qdf_trace_hex_dump)(51, 2, a3 + 1, *a3);
    }
    v30 = (_WORD *)a1[20];
    if ( v30 )
    {
      v31 = (unsigned __int16)(*v30 - 4);
      *a4 = v31;
      qdf_mem_copy(a4 + 1, (const void *)(a1[20] + 4LL), v31);
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: passphrase len: %d",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "os_if_nan_parse_security_params",
        *a4);
      ((void (__fastcall *)(__int64, __int64, unsigned int *, _QWORD))qdf_trace_hex_dump)(51, 2, a4 + 1, *a4);
    }
    v40 = (_WORD *)a1[21];
    if ( v40 )
    {
      v41 = (unsigned __int16)(*v40 - 4);
      *a5 = v41;
      qdf_mem_copy(a5 + 1, (const void *)(a1[21] + 4LL), v41);
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: service_name len: %d",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "os_if_nan_parse_security_params",
        *a5);
      ((void (__fastcall *)(__int64, __int64, unsigned int *, _QWORD))qdf_trace_hex_dump)(51, 2, a5 + 1, *a5);
    }
    v50 = a1[32];
    if ( v50 )
      *a6 = *(unsigned __int8 *)(v50 + 4);
    a6[1] = a1[33] != 0;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: out buffers for one or more parameters is null",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "os_if_nan_parse_security_params");
    return 4294967274LL;
  }
}
