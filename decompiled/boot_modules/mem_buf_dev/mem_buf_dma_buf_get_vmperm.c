unsigned __int64 __fastcall mem_buf_dma_buf_get_vmperm(__int64 a1, _QWORD *a2, _QWORD *a3, _DWORD *a4)
{
  __int64 v4; // x8
  unsigned __int64 result; // x0
  __int64 (*v6)(void); // x8
  unsigned __int64 v10; // x22

  v4 = *(_QWORD *)(a1 + 32);
  if ( *(__int64 (__fastcall **)(__int64))(v4 + 8) != mem_buf_dma_buf_attach )
    return -22;
  v6 = *(__int64 (**)(void))(v4 - 16);
  if ( *((_DWORD *)v6 - 1) != -1540668827 )
    __break(0x8228u);
  result = v6();
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v10 = result;
    mutex_lock(result + 88);
    *a2 = *(_QWORD *)(v10 + 32);
    *a3 = *(_QWORD *)(v10 + 40);
    *a4 = *(_DWORD *)(v10 + 48);
    mutex_unlock(v10 + 88);
    return 0;
  }
  return result;
}
