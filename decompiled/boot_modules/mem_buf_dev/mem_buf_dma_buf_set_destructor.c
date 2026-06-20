unsigned __int64 __fastcall mem_buf_dma_buf_set_destructor(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  unsigned __int64 result; // x0
  __int64 (*v5)(void); // x8
  unsigned __int64 v8; // x21

  v3 = *(_QWORD *)(a1 + 32);
  if ( *(__int64 (__fastcall **)(__int64))(v3 + 8) != mem_buf_dma_buf_attach )
    return -22;
  v5 = *(__int64 (**)(void))(v3 - 16);
  if ( *((_DWORD *)v5 - 1) != -1540668827 )
    __break(0x8228u);
  result = v5();
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v8 = result;
    mutex_lock(result + 88);
    *(_QWORD *)(v8 + 136) = a2;
    *(_QWORD *)(v8 + 144) = a3;
    mutex_unlock(v8 + 88);
    return 0;
  }
  return result;
}
