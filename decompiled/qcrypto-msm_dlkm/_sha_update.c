__int64 __fastcall sha_update(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x23
  __int64 v3; // x25
  __int64 v4; // x21
  size_t v5; // x2
  unsigned int v7; // w24
  __int64 v8; // x0
  int v9; // w23
  int v10; // w22
  __int64 v11; // x20
  __int64 v12; // x22
  __int64 v13; // x0
  unsigned int v15; // w8
  __int64 v16; // x0
  int v17; // w22
  unsigned int v18; // w22
  size_t v19; // x22
  __int64 v20; // x0
  size_t v21; // x2
  __int64 v22; // x8
  __int64 v23; // x11
  __int64 v24; // x10
  int v25; // w11
  unsigned __int64 StatusReg; // x26
  __int64 v27; // x27
  __int64 v28; // x0

  v4 = *(unsigned int *)(a1 + 48);
  v5 = *(unsigned int *)(a1 + 292);
  v7 = v5 + v4;
  if ( (unsigned int)(v5 + v4) > 0x40 )
  {
    v2 = *(_QWORD *)(a1 + 32);
    v3 = a1 + 359;
    v1 = *(_QWORD *)(v2 + 56);
    *(_QWORD *)(a1 + 128) = *(_QWORD *)(a1 + 56);
    *(_DWORD *)(a1 + 136) = v4;
    memcpy((void *)((a1 + 359) & 0xFFFFFFFFFFFFFFC0LL), (const void *)(a1 + 226), v5);
    v15 = v7 - ((v7 + 63) & 0xFFFFFFC0);
    LODWORD(v4) = v15 + 64;
    if ( v15 != -64 )
      scatterwalk_map_and_copy(
        a1 + 226,
        *(_QWORD *)(a1 + 56),
        (unsigned int)(*(_DWORD *)(a1 + 48) - v4),
        (unsigned int)v4,
        0);
    v16 = *(_QWORD *)(a1 + 56);
    v7 -= v4;
    if ( v16 )
    {
      v17 = *(_DWORD *)(a1 + 48);
      if ( v17 >= 1 )
      {
        do
        {
          v17 -= *(_DWORD *)(v16 + 12);
          v16 = sg_next(v16);
        }
        while ( v17 >= 1 && v16 );
        v16 = *(_QWORD *)(a1 + 56);
      }
    }
    v18 = *(_DWORD *)(a1 + 292);
    if ( v18 < v7 )
    {
      do
      {
        v18 += *(_DWORD *)(v16 + 12);
        if ( v18 > v7 )
          break;
        v16 = sg_next(v16);
      }
      while ( v18 < v7 );
      v18 = *(_DWORD *)(a1 + 292);
    }
    if ( v18 )
    {
      if ( *(_BYTE *)(v1 + 25) == 1 )
      {
        v19 = (unsigned int)(*(_DWORD *)(a1 + 48) + 64);
        v20 = _kmalloc_noprof(v19, 2336);
        *(_QWORD *)(a1 + 192) = v20;
        if ( v20 )
          goto LABEL_26;
        return 4294967284LL;
      }
      *(_QWORD *)v16 = *(_QWORD *)v16 & 0xFFFFFFFFFFFFFFFCLL | 2;
      *(_DWORD *)(a1 + 496) = v3 & 0xFC0;
      v24 = *(_QWORD *)(a1 + 56);
      v25 = *(_DWORD *)(a1 + 292);
      *(_QWORD *)(a1 + 528) = 0;
      *(_QWORD *)(a1 + 544) = 0;
      *(_QWORD *)(a1 + 536) = 0;
      *(_QWORD *)(a1 + 504) = 0;
      *(_QWORD *)(a1 + 512) = 0;
      *(_QWORD *)(a1 + 488) = ((unsigned __int64)((v3 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
      *(_DWORD *)(a1 + 500) = v25;
      *(_DWORD *)(a1 + 528) = 0;
      *(_QWORD *)(a1 + 520) = v24 & 0xFFFFFFFFFFFFFFFCLL | 1;
      *(_QWORD *)(a1 + 56) = a1 + 488;
    }
    else
    {
      *(_QWORD *)v16 = *(_QWORD *)v16 & 0xFFFFFFFFFFFFFFFCLL | 2;
    }
LABEL_30:
    *(_DWORD *)(a1 + 48) = v7;
    *(_DWORD *)(a1 + 292) = v4;
    return qcrypto_queue_req(v1, *(_QWORD *)(v2 + 48), a1);
  }
  if ( (unsigned int)v5 >= 0x41 )
  {
    __break(0x5512u);
    while ( 1 )
    {
      _fortify_panic(17);
      StatusReg = _ReadStatusReg(SP_EL0);
      v27 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &sha_update__alloc_tag;
      v19 = (unsigned int)(*(_DWORD *)(a1 + 48) + 64);
      v28 = _kmalloc_noprof(v19, 2336);
      *(_QWORD *)(StatusReg + 80) = v27;
      *(_QWORD *)(a1 + 192) = v28;
      if ( !v28 )
        return 4294967284LL;
LABEL_26:
      v21 = *(unsigned int *)(a1 + 292);
      if ( v19 >= v21 )
      {
        memcpy(*(void **)(a1 + 192), (const void *)(v3 & 0xFFFFFFFFFFFFFFC0LL), v21);
        memcpy(
          (void *)(*(_QWORD *)(a1 + 192) + *(unsigned int *)(a1 + 292)),
          *(const void **)(a1 + 184),
          *(unsigned int *)(*(_QWORD *)(a1 + 56) + 12LL));
        kfree_sensitive(*(_QWORD *)(a1 + 184));
        v22 = *(_QWORD *)(a1 + 192);
        v23 = *(_QWORD *)(a1 + 56);
        *(_QWORD *)(a1 + 184) = v22;
        LODWORD(v23) = *(_DWORD *)(v23 + 12);
        *(_DWORD *)(a1 + 496) = v22 & 0xFFF;
        *(_DWORD *)(a1 + 500) = v23 + *(_DWORD *)(a1 + 292);
        *(_QWORD *)(a1 + 56) = a1 + 488;
        *(_QWORD *)(a1 + 488) = (((unsigned __int64)((v22 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL) | 2;
        goto LABEL_30;
      }
    }
  }
  if ( (int)v4 >= 1 )
  {
    v8 = *(_QWORD *)(a1 + 56);
    if ( v8 )
    {
      v9 = 0;
      v10 = v4;
      v11 = a1 + v5 + 226;
      do
      {
        ++v9;
        v10 -= *(_DWORD *)(v8 + 12);
        v8 = sg_next(v8);
      }
      while ( v10 >= 1 && v8 );
      if ( v9 )
      {
        v12 = *(_QWORD *)(a1 + 56);
        do
        {
          v13 = sg_copy_to_buffer(v12, 1, v11, v4);
          v11 += v13;
          v4 -= v13;
          --v9;
          v12 = sg_next(v12);
        }
        while ( v9 );
      }
    }
  }
  *(_DWORD *)(a1 + 292) = v7;
  return 0;
}
