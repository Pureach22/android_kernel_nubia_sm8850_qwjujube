__int64 __fastcall _fastrpc_dma_buf_free(_QWORD *a1)
{
  __int64 v1; // x8
  int v2; // w9

  v1 = a1[5];
  if ( v1 )
    v2 = *(_DWORD *)(v1 + 140);
  else
    LOBYTE(v2) = 32;
  return dma_free_attrs(a1[4], a1[9], a1[6], a1[8] & ~(-1LL << v2), 0);
}
