unsigned __int64 __fastcall mem_buf_dma_buf_export(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v3)(__int64); // x8
  unsigned __int64 result; // x0
  __int64 v5; // x8
  __int64 (*v6)(void); // x8
  unsigned __int64 v7; // x19
  unsigned __int64 v8; // x8

  v3 = *(__int64 (__fastcall **)(__int64))(a2 + 24);
  if ( v3 != mem_buf_dma_buf_attach )
  {
    if ( v3 )
    {
      printk(&unk_136F8, *(_QWORD *)(a1 + 16), a3);
      return -22;
    }
    *(_QWORD *)(a2 + 24) = mem_buf_dma_buf_attach;
  }
  *(_QWORD *)(a1 + 16) = a2 + 16;
  result = dma_buf_export();
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    v5 = *(_QWORD *)(result + 32);
    if ( *(__int64 (__fastcall **)(__int64))(v5 + 8) != mem_buf_dma_buf_attach )
      goto LABEL_6;
    v6 = *(__int64 (**)(void))(v5 - 16);
    v7 = result;
    if ( *((_DWORD *)v6 - 1) != -1540668827 )
      __break(0x8228u);
    v8 = v6();
    result = v7;
    if ( v8 < 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)(v8 + 56) = v7;
    }
    else
    {
LABEL_6:
      __break(0x800u);
      dma_buf_put();
      return -22;
    }
  }
  return result;
}
