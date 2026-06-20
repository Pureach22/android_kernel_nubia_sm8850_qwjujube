__int64 __fastcall _fastrpc_dma_alloc(_QWORD *a1)
{
  __int64 v2; // x8
  __int64 result; // x0

  v2 = dma_alloc_attrs(a1[4], a1[9], a1 + 8, 3264, 0);
  if ( v2 )
    result = 0;
  else
    result = 4294967284LL;
  a1[6] = v2;
  return result;
}
