__int64 __fastcall qcom_dma_alloc_contiguous(__int64 a1, unsigned __int64 a2, unsigned int a3)
{
  __int64 v4; // x0
  unsigned __int64 v5; // x8
  unsigned int v6; // w8
  __int64 v7; // x3
  unsigned __int64 v8; // x1
  __int64 v9; // x3
  __int64 v10; // x2

  if ( (a3 & 0x400) == 0 )
    return 0;
  v4 = *(_QWORD *)(a1 + 704);
  if ( v4 )
  {
    v5 = a2 - 1;
    if ( a2 - 1 < 0x1000 )
    {
      v6 = 0;
LABEL_10:
      v8 = a2 >> 12;
      v9 = (a3 >> 13) & 1;
      if ( v6 >= 8 )
        v10 = 8;
      else
        v10 = v6;
      return cma_alloc(v4, v8, v10, v9);
    }
LABEL_9:
    v6 = 64 - __clz(v5 >> 12);
    goto LABEL_10;
  }
  v7 = 0;
  if ( a2 > 0x1000 )
  {
    v4 = qcom_dma_contiguous_default_area;
    if ( qcom_dma_contiguous_default_area )
    {
      v5 = a2 - 1;
      goto LABEL_9;
    }
  }
  return v7;
}
