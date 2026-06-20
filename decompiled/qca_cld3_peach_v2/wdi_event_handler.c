_QWORD *__fastcall wdi_event_handler(
        unsigned int a1,
        char a2,
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
  _QWORD *result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  __int64 i; // x22
  __int64 (__fastcall *v25)(__int64, _QWORD, __int64, _QWORD, _QWORD); // x8
  const char *v26; // x2

  result = _cds_get_context(71, (__int64)"wdi_event_handler", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !a1 )
  {
    v26 = "%s: Invalid WDI event";
    return (_QWORD *)qdf_trace_msg(0x3Fu, 2u, v26, v15, v16, v17, v18, v19, v20, v21, v22, "wdi_event_handler");
  }
  if ( !result )
    return result;
  if ( a2 )
  {
    __break(0x5512u);
    return (_QWORD *)wdi_event_sub();
  }
  v23 = result[3];
  if ( !v23 )
  {
    v26 = "%s: Invalid pdev";
    return (_QWORD *)qdf_trace_msg(0x3Fu, 2u, v26, v15, v16, v17, v18, v19, v20, v21, v22, "wdi_event_handler");
  }
  for ( i = *(_QWORD *)(*(_QWORD *)(v23 + 56) + 8LL * (a1 - 256)); i; i = *(_QWORD *)(i + 16) )
  {
    v25 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, _QWORD))i;
    if ( *(_DWORD *)(*(_QWORD *)i - 4LL) != 1330779045 )
      __break(0x8228u);
    result = (_QWORD *)v25(v23, a1, a3, 0, 0);
  }
  return result;
}
