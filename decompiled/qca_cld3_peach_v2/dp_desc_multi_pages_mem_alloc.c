__int64 __fastcall dp_desc_multi_pages_mem_alloc(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned __int64 a4,
        unsigned int a5,
        __int64 a6,
        char a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  _DWORD *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x4

  if ( !*(_QWORD *)(*(_QWORD *)(a1 + 8) + 248LL) )
  {
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: dp_get_multi_pages is null!",
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      "dp_desc_multi_pages_mem_alloc");
LABEL_7:
    qdf_mem_multi_pages_alloc(*(_QWORD *)(a1 + 24), a3, a4, a5, a6, a7 & 1);
    goto LABEL_8;
  }
  *(_WORD *)(a3 + 2) = 0;
  *(_BYTE *)(a3 + 32) = 0;
  v22 = *(_DWORD **)(*(_QWORD *)(a1 + 8) + 248LL);
  if ( *(v22 - 1) != 477180142 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD, unsigned __int64, _QWORD, __int64, _QWORD))v22)(a2, a4, a5, a3, a7 & 1);
  if ( !*(_WORD *)(a3 + 2) )
    goto LABEL_7;
LABEL_8:
  if ( *(_BYTE *)(a3 + 32) )
    v31 = "pre-alloc";
  else
    v31 = "dynamic-alloc";
  return qdf_trace_msg(
           0x45u,
           5u,
           "%s: %s desc_type %d element_size %d element_num %d cacheable %d",
           v23,
           v24,
           v25,
           v26,
           v27,
           v28,
           v29,
           v30,
           "dp_desc_multi_pages_mem_alloc",
           v31,
           a2,
           (unsigned int)a4,
           a5,
           a7 & 1);
}
