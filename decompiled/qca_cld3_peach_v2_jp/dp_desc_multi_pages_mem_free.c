void *__fastcall dp_desc_multi_pages_mem_free(
        __int64 a1,
        unsigned int a2,
        _BYTE *a3,
        __int64 a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  _DWORD *v13; // x8

  if ( !a3[32] )
    return (void *)qdf_mem_multi_pages_free(*(_QWORD *)(a1 + 24), (__int64)a3, a4, a5 & 1);
  v13 = *(_DWORD **)(*(_QWORD *)(a1 + 8) + 256LL);
  if ( !v13 )
    return (void *)qdf_trace_msg(
                     0x45u,
                     3u,
                     "%s: dp_put_multi_pages is null!",
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     a12,
                     a13,
                     "dp_desc_multi_pages_mem_free");
  if ( *(v13 - 1) != -1324916712 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD, _BYTE *))v13)(a2, a3);
  return qdf_mem_set(a3, 0x28u, 0);
}
