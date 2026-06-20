__int64 __fastcall system_heap_free(__int64 a1)
{
  __int64 drvdata; // x0
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x4
  _QWORD *v6; // x21
  _QWORD *v7; // x20
  unsigned int v8; // w22
  __int64 v9; // x8
  unsigned __int64 v10; // x1

  drvdata = dma_heap_get_drvdata(*(_QWORD *)a1);
  if ( *(_DWORD *)(a1 + 88) )
  {
    v6 = *(_QWORD **)(a1 + 80);
    v7 = (_QWORD *)drvdata;
    v8 = 0;
    do
    {
      v10 = *v6 & 0xFFFFFFFFFFFFFFFCLL;
      if ( (*(_QWORD *)v10 & 0x40) != 0 && *(_BYTE *)(v10 + 64) == 9 )
      {
        v9 = 0;
      }
      else if ( (*(_QWORD *)v10 & 0x40) != 0 && *(_BYTE *)(v10 + 64) == 4 )
      {
        v9 = 1;
      }
      else if ( (*(_QWORD *)v10 & 0x40) != 0 )
      {
        if ( *(_BYTE *)(v10 + 64) )
          v9 = 3;
        else
          v9 = 2;
      }
      else
      {
        v9 = 2;
      }
      dynamic_page_pool_free(*(_QWORD *)(*v7 + 8 * v9), v10, v3, v4, v5);
      ++v8;
      v6 = (_QWORD *)sg_next(v6);
    }
    while ( v8 < *(_DWORD *)(a1 + 88) );
  }
  sg_free_table(a1 + 80);
  return kfree(a1);
}
