__int64 __fastcall system_heap_refill_worker(__int64 a1)
{
  __int64 v1; // x26
  unsigned __int64 StatusReg; // x27
  __int64 v3; // x21
  int v4; // w8
  unsigned int v5; // w19
  int v6; // w22
  unsigned int v7; // w22
  char *v8; // x23
  __int64 ok; // x0
  const char **v10; // x8
  char *v11; // x23
  const char **v12; // x8
  char *v13; // x23
  __int64 should_stop; // x0
  __int64 v16; // [xsp+8h] [xbp-8h]

  v1 = 0;
  _ReadStatusReg(SP_EL0);
  v16 = a1;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    do
    {
      v3 = *(_QWORD *)(v16 + 8 * v1);
      v4 = *(_DWORD *)(v3 + 72);
      if ( *(_DWORD *)(v3 + 8) < (int)(0x2800uLL >> v4) && v4 && *(_DWORD *)(v3 + 8) < (int)(0x6400uLL >> v4) )
      {
        v5 = *(_DWORD *)(v3 + 68) & 0xFFFEFFFF;
        while ( 1 )
        {
          v6 = *(_DWORD *)(v3 + 68);
          a1 = ktime_get(a1);
          if ( a1 - *(_QWORD *)(v3 + 48) < 10000000 )
            break;
          v7 = (0x250015uLL >> (2 * (v6 & 0xFu))) & 3;
          v8 = (char *)&contig_page_data + 1664 * v7;
          if ( strcmp(*((const char **)v8 + 21), "DMA32") )
          {
            ok = dynamic_pool_zone_watermark_ok_safe(
                   v8,
                   *(_DWORD *)(v3 + 72),
                   (1 << *(_DWORD *)(v3 + 72)) + *((_DWORD *)v8 + 8) + *((_DWORD *)v8 + 4),
                   v7);
            if ( (ok & 1) == 0 )
              goto LABEL_21;
          }
          if ( v7 )
          {
            if ( (v10 = (const char **)((char *)&contig_page_data + 1664 * v7),
                  v11 = (char *)(v10 - 208),
                  strcmp(*(v10 - 187), "DMA32"))
              && (ok = dynamic_pool_zone_watermark_ok_safe(
                         v11,
                         *(_DWORD *)(v3 + 72),
                         (1 << *(_DWORD *)(v3 + 72)) + *((_DWORD *)v11 + 8) + *((_DWORD *)v11 + 4),
                         v7),
                  (ok & 1) == 0)
              || v7 != 1
              && ((v12 = (const char **)((char *)&contig_page_data + 1664 * v7),
                   v13 = (char *)(v12 - 416),
                   strcmp(*(v12 - 395), "DMA32"))
               && (ok = dynamic_pool_zone_watermark_ok_safe(
                          v13,
                          *(_DWORD *)(v3 + 72),
                          (1 << *(_DWORD *)(v3 + 72)) + *((_DWORD *)v13 + 8) + *((_DWORD *)v13 + 4),
                          v7),
                   (ok & 1) == 0)
               || v7 == 3
               && strcmp(*((const char **)&contig_page_data + 21), "DMA32")
               && (ok = dynamic_pool_zone_watermark_ok_safe(
                          &contig_page_data,
                          *(_DWORD *)(v3 + 72),
                          (1 << *(_DWORD *)(v3 + 72))
                        + *((_DWORD *)&contig_page_data + 8)
                        + *((_DWORD *)&contig_page_data + 4),
                          3u),
                   (ok & 1) == 0)) )
            {
LABEL_21:
              a1 = ktime_get(ok);
              *(_QWORD *)(v3 + 48) = a1;
              break;
            }
          }
          a1 = _alloc_pages_noprof(v5 | 0xC00, *(unsigned int *)(v3 + 72), 0, 0);
          if ( a1 )
          {
            a1 = dynamic_page_pool_add(v3);
            if ( *(_DWORD *)(v3 + 8) < (int)(0x6400uLL >> *(_DWORD *)(v3 + 72)) )
              continue;
          }
          break;
        }
      }
      ++v1;
    }
    while ( v1 != 3 );
    *(_DWORD *)(StatusReg + 48) = 1;
    __dmb(0xBu);
    should_stop = kthread_should_stop(a1);
    if ( (should_stop & 1) != 0 )
      break;
    a1 = schedule(should_stop);
    *(_DWORD *)(StatusReg + 48) = 0;
    v1 = 0;
    __dmb(0xBu);
  }
  *(_DWORD *)(StatusReg + 48) = 0;
  __dmb(0xBu);
  return 0;
}
