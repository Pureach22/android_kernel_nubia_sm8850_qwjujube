__int64 __fastcall dp_context_free_mem(
        __int64 a1,
        unsigned int a2,
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
  _DWORD *v13; // x8
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v13 = *(_DWORD **)(*(_QWORD *)(a1 + 8) + 224LL);
  if ( !v13 )
  {
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: dp_prealloc_put_context null!",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dp_context_free_mem");
LABEL_7:
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Context type %d not pre-allocated",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "dp_context_free_mem",
      a2);
    return _qdf_mem_free(a3);
  }
  if ( *(v13 - 1) != -754103808 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(_QWORD, __int64))v13)(a2, a3);
  if ( (_DWORD)result )
    goto LABEL_7;
  return result;
}
