__int64 __fastcall reset_reg_dma_buffer_v1(__int64 a1)
{
  if ( !a1 )
    return 4294967274LL;
  *(_DWORD *)(a1 + 20) = 0;
  *(_QWORD *)(a1 + 40) = 1;
  *(_DWORD *)(a1 + 48) = 0;
  return 0;
}
