__int64 __fastcall mhi_alloc_bhie_table(__int64 a1, __int64 *a2, unsigned __int64 a3)
{
  unsigned __int64 v4; // x24
  __int64 v8; // x26
  unsigned __int64 v9; // x20
  unsigned __int64 v10; // x25
  __int64 v11; // x23
  __int64 v12; // x28
  __int64 v13; // x26
  unsigned __int64 v14; // x22
  unsigned __int64 v15; // x20
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x1
  __int64 v18; // x0
  __int64 v19; // x8
  unsigned __int64 v20; // x22
  int v21; // w25
  unsigned __int64 StatusReg; // x20
  __int64 v23; // x22
  void *(*v24)(void *, const void *, size_t); // x0
  int v25; // [xsp+8h] [xbp-18h]
  __int64 *v26; // [xsp+10h] [xbp-10h]
  __int64 *v27; // [xsp+18h] [xbp-8h]

  if ( (*(_BYTE *)(a1 + 612) & 1) != 0 )
    return 0;
  v4 = *(_QWORD *)(a1 + 136);
  v8 = _kmalloc_cache_noprof(memcpy, 3520, 24);
  if ( v8 )
  {
    while ( 1 )
    {
      v9 = (a3 + v4 - 1) / v4;
      v10 = (unsigned int)(v9 + 1);
      if ( (v10 & 0x80000000) != 0 )
        break;
      a3 = 32LL * (unsigned int)(v9 + 1);
      v11 = _kmalloc_noprof(a3, 3520);
      *(_QWORD *)v8 = v11;
      if ( !v11 )
        goto LABEL_32;
      if ( (unsigned int)v9 > 0x7FFFFFFE )
      {
LABEL_19:
        v19 = *(_QWORD *)(v11 + 32LL * (int)v9);
        *(_DWORD *)(v8 + 16) = v10;
        *a2 = v8;
        *(_QWORD *)(v8 + 8) = v19;
        return 0;
      }
      v27 = (__int64 *)v8;
      v12 = 0;
      v13 = 32 * (v9 & 0x7FFFFFFF);
      v26 = a2;
      v14 = 0;
      a2 = nullptr;
      v25 = v9;
      v15 = 0;
      while ( (v15 & 0x8000000000000000LL) == 0 && a3 >= v15 + 24 && a3 + v12 - 24 >= 8 )
      {
        v16 = v11 + v15;
        v17 = v13 == v15 ? v14 : v4;
        *(_QWORD *)(v16 + 24) = v17;
        v18 = dma_alloc_attrs(*(_QWORD *)(a1 + 8), v17, v16 + 16, 3264, 64);
        if ( a3 < v15 || a3 + v12 < 8 )
          break;
        *(_QWORD *)(v11 + v15) = v18;
        if ( !v18 )
        {
          v8 = (__int64)v27;
          if ( !(_DWORD)a2 )
            goto LABEL_32;
          v20 = a3 - v15 + 16;
          v4 = v15 - 16;
          v21 = (_DWORD)a2 + 1;
          while ( ((v4 + 8) & 0x8000000000000000LL) == 0
               && a3 >= v4 + 8
               && v20 - 8 >= 8
               && ((v4 - 16) & 0x8000000000000000LL) == 0
               && a3 >= v4 - 16
               && v20 + 16 >= 8
               && (v4 & 0x8000000000000000LL) == 0
               && a3 >= v4
               && v20 >= 8 )
          {
            dma_free_attrs(
              *(_QWORD *)(a1 + 8),
              *(_QWORD *)(v11 + v4 + 8),
              *(_QWORD *)(v11 + v4 - 16),
              *(_QWORD *)(v11 + v4),
              64);
            --v21;
            v4 -= 32LL;
            v20 += 32LL;
            if ( v21 <= 1 )
              goto LABEL_32;
          }
          break;
        }
        a2 = (__int64 *)((char *)a2 + 1);
        v15 += 32LL;
        v14 += 16LL;
        v12 -= 32;
        if ( (unsigned __int64)a2 >= v10 )
        {
          v8 = (__int64)v27;
          LODWORD(v9) = v25;
          a2 = v26;
          v11 = *v27;
          goto LABEL_19;
        }
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v23 = *(_QWORD *)(StatusReg + 80);
      v24 = memcpy;
      *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
      v8 = _kmalloc_cache_noprof(v24, 3520, 24);
      *(_QWORD *)(StatusReg + 80) = v23;
      if ( !v8 )
        return 4294967284LL;
    }
    *(_QWORD *)v8 = 0;
LABEL_32:
    kfree(v8);
  }
  return 4294967284LL;
}
