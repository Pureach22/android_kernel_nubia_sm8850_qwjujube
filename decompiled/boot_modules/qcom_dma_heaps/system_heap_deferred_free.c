__int64 __fastcall system_heap_deferred_free(__int64 a1, int a2)
{
  __int64 v4; // x19
  __int64 drvdata; // x21
  __int64 v6; // x1
  __int64 v7; // x2
  unsigned int v8; // w8
  unsigned int i; // w22
  __int64 v11; // x3
  void *v12; // x0
  void *v13; // x22
  __int64 v14; // x3
  void *v15; // x0
  size_t v16; // x2
  void *v17; // x22
  _QWORD *v18; // x24
  unsigned int j; // w26
  __int64 v20; // x1
  unsigned __int64 v21; // x25
  __int64 v22; // x8
  unsigned __int64 v23; // x0
  __int64 v24; // x8
  unsigned int v31; // w28
  unsigned int v32; // w28
  __int64 result; // x0
  _QWORD *v34; // [xsp+8h] [xbp-128h] BYREF
  __int64 v35; // [xsp+10h] [xbp-120h]
  __int64 v36; // [xsp+18h] [xbp-118h]
  _QWORD v37[34]; // [xsp+20h] [xbp-110h] BYREF

  v37[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1 - 128;
  drvdata = dma_heap_get_drvdata(*(_QWORD *)(a1 - 128));
  if ( a2 )
    goto LABEL_20;
  v6 = *(_QWORD *)(a1 - 48);
  v7 = *(unsigned int *)(a1 - 36);
  v35 = 0;
  v36 = 0;
  v34 = nullptr;
  memset(v37, 0, 256);
  _sg_page_iter_start(&v34, v6, v7, 0);
  if ( (_sg_page_iter_next(&v34) & 1) == 0 )
  {
LABEL_18:
    a2 = 0;
    goto LABEL_20;
  }
  v8 = 0;
  for ( i = 1; ; ++i )
  {
    v37[v8] = (*v34 & 0xFFFFFFFFFFFFFFFCLL) + ((unsigned __int64)(unsigned int)v35 << 6);
    if ( i != 32 )
      break;
    if ( arm64_use_ng_mappings )
      v11 = 0x68000000000F03LL;
    else
      v11 = 0x68000000000703LL;
    v12 = (void *)vmap(v37, 32, 4, v11);
    if ( !v12 )
      goto LABEL_19;
    v13 = v12;
    memset(v12, 0, 0x20000u);
    vunmap(v13);
    i = 0;
    if ( (_sg_page_iter_next(&v34) & 1) == 0 )
      goto LABEL_18;
LABEL_5:
    v8 = i;
    if ( i > 0x20 )
      __break(1u);
  }
  if ( (_sg_page_iter_next(&v34) & 1) != 0 )
    goto LABEL_5;
  if ( arm64_use_ng_mappings )
    v14 = 0x68000000000F03LL;
  else
    v14 = 0x68000000000703LL;
  v15 = (void *)vmap(v37, i, 4, v14);
  if ( v15 )
  {
    v16 = i << 12;
    v17 = v15;
    memset(v15, 0, v16);
    vunmap(v17);
    goto LABEL_18;
  }
LABEL_19:
  a2 = 1;
LABEL_20:
  if ( *(_DWORD *)(a1 - 40) )
  {
    v18 = *(_QWORD **)(a1 - 48);
    for ( j = 0; j < *(_DWORD *)(a1 - 40); ++j )
    {
      v21 = *v18 & 0xFFFFFFFFFFFFFFFCLL;
      if ( *(_QWORD *)v21 >> 62 == 2 )
      {
        v22 = *(_QWORD *)(v21 + 8);
        v23 = *v18 & 0xFFFFFFFFFFFFFFFCLL;
        if ( (v22 & 1) != 0 )
          v23 = v22 - 1;
        _X8 = (unsigned int *)(v23 + 52);
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v31 = __ldxr(_X8);
          v32 = v31 - 1;
        }
        while ( __stlxr(v32, _X8) );
        __dmb(0xBu);
        if ( !v32 )
        {
          _folio_put();
          if ( (*(_QWORD *)v21 & 0x40) == 0 )
            goto LABEL_34;
          goto LABEL_22;
        }
      }
      else if ( a2 != 1 )
      {
        if ( (*(_QWORD *)v21 & 0x40) != 0 && *(_BYTE *)(v21 + 64) == 9 )
        {
          v24 = 0;
        }
        else if ( (*(_QWORD *)v21 & 0x40) != 0 && *(_BYTE *)(v21 + 64) == 4 )
        {
          v24 = 1;
        }
        else if ( (*(_QWORD *)v21 & 0x40) != 0 )
        {
          v24 = 2;
          if ( *(_BYTE *)(v21 + 64) )
            v24 = 3;
        }
        else
        {
          v24 = 2;
        }
        dynamic_page_pool_free(*(_QWORD *)(*(_QWORD *)(drvdata + 8) + 8 * v24), *v18 & 0xFFFFFFFFFFFFFFFCLL);
        goto LABEL_24;
      }
      if ( (*(_QWORD *)v21 & 0x40) == 0 )
      {
LABEL_34:
        v20 = 0;
        goto LABEL_23;
      }
LABEL_22:
      v20 = *(unsigned __int8 *)(v21 + 64);
LABEL_23:
      _free_pages(v21, v20);
LABEL_24:
      v18 = (_QWORD *)sg_next(v18);
    }
  }
  sg_free_table(a1 - 48);
  result = kfree(v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
