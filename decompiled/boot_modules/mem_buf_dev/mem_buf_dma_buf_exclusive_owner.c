bool __fastcall mem_buf_dma_buf_exclusive_owner(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v3)(void); // x8
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x19
  _BOOL4 v6; // w20

  v1 = *(_QWORD *)(a1 + 32);
  if ( *(__int64 (__fastcall **)(__int64))(v1 + 8) != mem_buf_dma_buf_attach )
    goto LABEL_2;
  v3 = *(__int64 (**)(void))(v1 - 16);
  if ( *((_DWORD *)v3 - 1) != -1540668827 )
    __break(0x8228u);
  v4 = v3();
  if ( v4 < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = v4;
    mutex_lock(v4 + 88);
    v6 = (*(_DWORD *)(v5 + 16) & 7) == 0;
    mutex_unlock(v5 + 88);
    return v6;
  }
  else
  {
LABEL_2:
    __break(0x800u);
    return 0;
  }
}
