__int64 __fastcall mem_buf_dma_buf_copy_vmperm(__int64 a1, __int64 *a2, __int64 *a3, _DWORD *a4)
{
  __int64 v4; // x8
  unsigned __int64 v5; // x19
  __int64 (*v6)(void); // x8
  unsigned __int64 v10; // x0
  __int64 v11; // x20
  __int64 v12; // x21
  __int64 v13; // x0

  v4 = *(_QWORD *)(a1 + 32);
  if ( *(__int64 (__fastcall **)(__int64))(v4 + 8) == mem_buf_dma_buf_attach )
  {
    v6 = *(__int64 (**)(void))(v4 - 16);
    if ( *((_DWORD *)v6 - 1) != -1540668827 )
      __break(0x8228u);
    v10 = v6();
    v5 = v10;
    if ( v10 < 0xFFFFFFFFFFFFF001LL )
    {
      mutex_lock(v10 + 88);
      v11 = 4LL * *(unsigned int *)(v5 + 48);
      v12 = kmemdup_noprof(*(_QWORD *)(v5 + 32), v11, 3264);
      if ( v12 )
      {
        v13 = kmemdup_noprof(*(_QWORD *)(v5 + 40), v11, 3264);
        if ( v13 )
        {
          *a2 = v12;
          *a3 = v13;
          *a4 = *(_DWORD *)(v5 + 48);
          mutex_unlock(v5 + 88);
          LODWORD(v5) = 0;
          return (unsigned int)v5;
        }
        kfree(v12);
      }
      mutex_unlock(v5 + 88);
      LODWORD(v5) = -12;
    }
  }
  else
  {
    LODWORD(v5) = -22;
  }
  return (unsigned int)v5;
}
