__int64 __fastcall sgl_sync_range(
        __int64 *a1,
        __int64 a2,
        int a3,
        unsigned __int64 a4,
        unsigned __int64 a5,
        unsigned int a6,
        char a7)
{
  __int64 v14; // x0
  unsigned __int64 v16; // x27
  __int64 v17; // x28
  unsigned __int64 v18; // x26
  __int64 v19; // x21
  __int64 v20; // x28
  __int64 v21; // x0
  int v22; // w25
  __int64 v23; // x26
  unsigned int v24; // w8
  unsigned __int64 v25; // x10
  unsigned int v26; // w8
  unsigned __int64 v27; // x24
  __int64 v28; // x28
  __int64 v29; // x1
  unsigned int v30; // [xsp+Ch] [xbp-4h]

  if ( !a3 )
    return 0;
  if ( !*(_DWORD *)(a2 + 24) || (v14 = sg_next(a2), a3 == 1) || !*(_DWORD *)(v14 + 24) )
  {
    v16 = *(unsigned int *)(a2 + 12);
    v17 = *(_QWORD *)(a2 + 16);
    if ( v16 <= a4 )
    {
      v30 = a6;
      v19 = *(_QWORD *)(a2 + 16);
      v20 = *(unsigned int *)(a2 + 12);
    }
    else
    {
      if ( a5 >= (unsigned int)(v16 - a4) )
        v18 = (unsigned int)(v16 - a4);
      else
        v18 = a5;
      if ( (a7 & 1) != 0 )
      {
        if ( (*((_BYTE *)a1 + 844) & 0x40) == 0 )
          _dma_sync_single_for_cpu(a1, v17 + a4, v18, a6);
      }
      else if ( (*((_BYTE *)a1 + 844) & 0x40) == 0 )
      {
        _dma_sync_single_for_device(a1, v17 + a4, v18, a6);
      }
      a5 -= v18;
      if ( !a5 )
        return 0;
      v30 = a6;
      v19 = v17;
      v20 = *(unsigned int *)(a2 + 12);
      a4 += v18;
    }
    v21 = sg_next(a2);
    v22 = a3 - 1;
    if ( a3 == 1 )
      return 0;
    v23 = v19 + v20;
    while ( 1 )
    {
      v24 = *(_DWORD *)(v21 + 12);
      v16 = v24 + (unsigned int)v16;
      if ( a4 >= v16 )
        goto LABEL_24;
      v25 = (unsigned int)(v16 - a4);
      v26 = v24 - v25;
      if ( a5 >= v25 )
        v27 = (unsigned int)(v16 - a4);
      else
        v27 = a5;
      if ( (a7 & 1) != 0 )
      {
        if ( (*((_BYTE *)a1 + 844) & 0x40) == 0 )
        {
          v28 = v21;
          _dma_sync_single_for_cpu(a1, v23 + v26, v27, v30);
LABEL_34:
          v21 = v28;
        }
      }
      else if ( (*((_BYTE *)a1 + 844) & 0x40) == 0 )
      {
        v28 = v21;
        _dma_sync_single_for_device(a1, v23 + v26, v27, v30);
        goto LABEL_34;
      }
      a5 -= v27;
      if ( !a5 )
        return 0;
      v24 = *(_DWORD *)(v21 + 12);
      a4 += v27;
LABEL_24:
      v23 += v24;
      v21 = sg_next(v21);
      if ( !--v22 )
        return 0;
    }
  }
  if ( !a1[79] )
    return 0;
  if ( !(unsigned int)__ratelimit(&sgl_sync_range__rs, "sgl_sync_range") )
    return 4294967274LL;
  v29 = a1[14];
  if ( !v29 )
    v29 = *a1;
  printk(&unk_E0AD, v29);
  return 4294967274LL;
}
