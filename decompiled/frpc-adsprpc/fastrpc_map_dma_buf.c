__int64 __fastcall fastrpc_map_dma_buf(__int64 a1, unsigned int a2)
{
  __int64 v2; // x19
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 64) + 8LL;
  LODWORD(result) = dma_map_sgtable(*(_QWORD *)(a1 + 8), v2, a2, 0);
  if ( (_DWORD)result )
    return (int)result;
  else
    return v2;
}
