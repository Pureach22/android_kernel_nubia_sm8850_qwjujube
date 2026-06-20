__int64 __fastcall dma_fence_is_signaled(__int64 a1)
{
  __int64 (*v1)(void); // x8

  if ( (*(_QWORD *)(a1 + 48) & 1) != 0 )
    return 1;
  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 8) + 32LL);
  if ( !v1 )
    return 0;
  if ( *((_DWORD *)v1 - 1) != 1879296680 )
    __break(0x8228u);
  if ( (v1() & 1) == 0 )
    return 0;
  dma_fence_signal(a1);
  return 1;
}
