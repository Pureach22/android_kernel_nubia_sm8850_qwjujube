unsigned __int64 __fastcall mem_buf_dma_buf_get_memparcel_hdl(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x8
  unsigned __int64 result; // x0
  __int64 (*v4)(void); // x8
  int v6; // w8

  v2 = *(_QWORD *)(a1 + 32);
  if ( *(__int64 (__fastcall **)(__int64))(v2 + 8) != mem_buf_dma_buf_attach )
    return -22;
  v4 = *(__int64 (**)(void))(v2 - 16);
  if ( *((_DWORD *)v4 - 1) != -1540668827 )
    __break(0x8228u);
  result = v4();
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v6 = *(_DWORD *)(result + 80);
    if ( v6 == -1 )
    {
      return 4294967274LL;
    }
    else
    {
      *a2 = v6;
      return 0;
    }
  }
  return result;
}
