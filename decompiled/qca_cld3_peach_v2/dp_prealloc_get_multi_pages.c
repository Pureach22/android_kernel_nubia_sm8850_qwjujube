__int64 __fastcall dp_prealloc_get_multi_pages(
        __int64 result,
        __int64 a2,
        unsigned __int16 a3,
        _QWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 v14; // x4
  __int64 v15; // x9
  char *v16; // x11
  __int64 v17; // x9
  __int64 v18; // x8
  __int64 v19; // x10
  __int64 v20; // x12
  __int64 v21; // [xsp+8h] [xbp-18h]

  v14 = 0;
  v15 = -2112;
  while ( 1 )
  {
    if ( *(_DWORD *)((char *)&g_dp_multi_page_allocs + v15 + 2112) == (_DWORD)result
      && (*((_BYTE *)&g_dp_multi_page_allocs + v15 + 2132) & 1) == 0 )
    {
      if ( *(_WORD *)((char *)&g_dp_multi_page_allocs + v15 + 2138) )
      {
        if ( *(_QWORD *)((char *)&g_dp_multi_page_allocs + v15 + 2120) == a2 )
        {
          v16 = (char *)&g_dp_multi_page_allocs + v15;
          if ( *(_DWORD *)((char *)&g_dp_multi_page_allocs + v15 + 2128) >= (unsigned int)a3 )
            break;
        }
      }
    }
    v15 += 64;
    v14 = (unsigned int)(v14 + 1);
    if ( !v15 )
      return result;
  }
  v17 = *((_QWORD *)v16 + 267);
  v16[2132] = 1;
  *a4 = v17;
  v18 = *((_QWORD *)v16 + 271);
  v19 = *((_QWORD *)v16 + 268);
  v20 = *((_QWORD *)v16 + 269);
  a4[3] = *((_QWORD *)v16 + 270);
  a4[4] = v18;
  a4[1] = v19;
  a4[2] = v20;
  return qdf_trace_msg(
           0x45u,
           5u,
           "%s: i %d: desc_type %d cacheable_pages %pK dma_pages %pK num_pages %d",
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           "dp_prealloc_get_multi_pages",
           v14,
           (unsigned int)result,
           *((_QWORD *)v16 + 269),
           *((_QWORD *)v16 + 268),
           *((unsigned __int16 *)v16 + 1069),
           v21,
           v12,
           v13);
}
