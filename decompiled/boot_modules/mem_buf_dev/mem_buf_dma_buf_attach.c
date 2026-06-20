__int64 __fastcall mem_buf_dma_buf_attach(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 32) - 8LL);
  if ( *((_DWORD *)v1 - 1) != -766469283 )
    __break(0x8228u);
  return v1();
}
