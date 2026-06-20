bool __fastcall is_mem_buf_dma_buf(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 (__fastcall *v4)(__int64, __int64); // x8

  v2 = *(_QWORD *)(a1 + 32);
  if ( *(__int64 (__fastcall **)(__int64))(v2 + 8) != mem_buf_dma_buf_attach )
    return 0;
  v4 = *(__int64 (__fastcall **)(__int64, __int64))(v2 - 16);
  if ( *((_DWORD *)v4 - 1) != -1540668827 )
    __break(0x8228u);
  return (unsigned __int64)v4(a1, a2) < 0xFFFFFFFFFFFFF001LL;
}
