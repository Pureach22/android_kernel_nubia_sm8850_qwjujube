unsigned int *__fastcall zram_compress_success_handler(__int64 a1, int a2)
{
  _QWORD *v2; // x20
  __int64 v3; // x19
  unsigned int *result; // x0
  __int64 v5; // x20
  unsigned __int64 v6; // x8
  __int64 v7; // x24
  unsigned int v8; // w8
  _QWORD *v9; // x0
  __int64 v10; // x1
  unsigned __int64 v11; // x2
  __int64 v12; // x3
  size_t v13; // x21
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x22
  unsigned __int64 total_pages; // x0
  _QWORD *v17; // x8
  unsigned __int64 v18; // x9
  unsigned __int64 v22; // x10
  unsigned __int64 v23; // x9
  __int64 v24; // x8
  void *v25; // x0
  int v30; // w8
  unsigned __int64 v33; // x11
  unsigned __int64 v36; // x9
  unsigned __int64 v39; // x9
  unsigned __int64 v42; // x9

  v2 = (_QWORD *)((char *)comp_out_queue + 40 * a2);
  v3 = *v2;
  if ( *(_BYTE *)(*(_QWORD *)(*v2 + 8LL) + 25LL) != 10 )
  {
    v6 = *(_QWORD *)(a1 + 16);
    if ( (v6 & 0x80000000) == 0 )
    {
      if ( (v6 & 0xFFFFF) >= huge_class_size )
      {
        v7 = ((v2[1] - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL;
        v8 = 4096;
      }
      else
      {
        v7 = *(_QWORD *)(a1 + 8);
        v8 = v6 & 0xFFFFF;
      }
      v13 = v8;
      v14 = zs_malloc(*(_QWORD *)(*(_QWORD *)v3 + 8LL), v8, 10250);
      if ( v14 >= 0xFFFFFFFFFFFFF001LL )
      {
        zram_abandon_requests();
        _X8 = (unsigned __int64 *)(*(_QWORD *)v3 + 176LL);
        __asm { PRFM            #0x11, [X8] }
        do
          v42 = __ldxr(_X8);
        while ( __stxr(v42 + 1, _X8) );
      }
      else
      {
        v2[3] = v14;
        v15 = v14;
        total_pages = zs_get_total_pages(*(_QWORD *)(*(_QWORD *)v3 + 8LL));
        v17 = *(_QWORD **)v3;
        v18 = *(_QWORD *)(*(_QWORD *)v3 + 168LL);
        if ( v18 < total_pages )
        {
          do
          {
            _X11 = v17 + 21;
            __asm { PRFM            #0x11, [X11] }
            while ( 1 )
            {
              v22 = __ldxr(_X11);
              if ( v22 != v18 )
                break;
              if ( !__stlxr(total_pages, _X11) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v22 == v18;
            v18 = v22;
          }
          while ( !_ZF && v22 < total_pages );
          v17 = *(_QWORD **)v3;
        }
        v23 = v17[12];
        v24 = v17[1];
        if ( !v23 || total_pages <= v23 )
        {
          v25 = (void *)zs_map_object(v24, v15, 2);
          memcpy(v25, (const void *)((v7 - memstart_addr) | 0xFFFFFF8000000000LL), v13);
          zs_unmap_object(*(_QWORD *)(*(_QWORD *)v3 + 8LL), v15);
          _X8 = (unsigned __int64 *)(*(_QWORD *)v3 + 104LL);
          __asm { PRFM            #0x11, [X8] }
          do
            v36 = __ldxr(_X8);
          while ( __stxr(v36 + v13, _X8) );
          v9 = v2;
          v10 = (unsigned int)v13;
          v11 = 0;
          v12 = 0;
          return (unsigned int *)zram_write_finish(v9, v10, v11, v12);
        }
        zs_free(v24, v15);
        printk(&unk_B27B);
      }
      *(_BYTE *)(*(_QWORD *)(v3 + 8) + 25LL) = 10;
      return kref_put((unsigned int *)(v3 + 24));
    }
    _X10 = (unsigned __int64 *)(*(_QWORD *)v3 + 136LL);
    __asm { PRFM            #0x11, [X10] }
    do
      v33 = __ldxr(_X10);
    while ( __stxr(v33 + 1, _X10) );
    v9 = v2;
    v10 = 0;
    v11 = v6 & 0xFFFFFFFF00000000LL | HIDWORD(v6);
    v12 = 13;
    return (unsigned int *)zram_write_finish(v9, v10, v11, v12);
  }
  result = (unsigned int *)(v3 + 24);
  __asm { PRFM            #0x11, [X0] }
  do
    v30 = __ldxr(result);
  while ( __stlxr(v30 - 1, result) );
  if ( v30 == 1 )
  {
    __dmb(9u);
    if ( *(_BYTE *)(*(_QWORD *)(v3 + 8) + 25LL) == 10 )
    {
      _X8 = (unsigned __int64 *)(*(_QWORD *)v3 + 120LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v39 = __ldxr(_X8);
      while ( __stxr(v39 + 1, _X8) );
    }
    v5 = *(_QWORD *)(v3 + 8);
    bio_end_io_acct_remapped(v5, *(_QWORD *)(v3 + 16), *(_QWORD *)(v5 + 8));
    bio_endio(v5);
    return (unsigned int *)kfree(v3);
  }
  else if ( v30 <= 0 )
  {
    return (unsigned int *)refcount_warn_saturate(result, 3);
  }
  return result;
}
