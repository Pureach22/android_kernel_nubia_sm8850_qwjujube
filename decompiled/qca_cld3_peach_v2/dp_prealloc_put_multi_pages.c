unsigned __int16 *__fastcall dp_prealloc_put_multi_pages(
        unsigned int a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x4
  char *i; // x19
  char v13; // w1

  v10 = 0;
  for ( i = (char *)&unk_16B3C; ; i += 64 )
  {
    if ( *((_DWORD *)i - 5) != a1 )
      goto LABEL_7;
    if ( i[1] == 1 )
      break;
    if ( *(_QWORD *)(i + 12) == *(_QWORD *)(a2 + 8) )
      goto LABEL_9;
LABEL_7:
    if ( ++v10 == 33 )
      return (unsigned __int16 *)qdf_trace_msg(
                                   0x45u,
                                   3u,
                                   "%s: Not prealloc pages %pK desc_type %d cacheable_pages %pK dma_pages %pK",
                                   a3,
                                   a4,
                                   a5,
                                   a6,
                                   a7,
                                   a8,
                                   a9,
                                   a10,
                                   "dp_prealloc_put_multi_pages",
                                   a2,
                                   a1,
                                   *(_QWORD *)(a2 + 16),
                                   *(_QWORD *)(a2 + 8));
  }
  if ( *(_QWORD *)(i + 20) != *(_QWORD *)(a2 + 16) )
    goto LABEL_7;
LABEL_9:
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: i %d: desc_type %d returned",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_prealloc_put_multi_pages",
    v10);
  v13 = i[1];
  *i = 0;
  return qdf_mem_multi_pages_zero((unsigned __int16 *)i + 2, v13);
}
