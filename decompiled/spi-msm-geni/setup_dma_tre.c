unsigned __int64 *__fastcall setup_dma_tre(
        unsigned __int64 *dest,
        unsigned __int64 a2,
        void *src,
        size_t n,
        __int64 a5,
        char a6,
        unsigned int a7)
{
  int v9; // w21
  int v10; // w8
  unsigned int v12; // w5
  unsigned __int64 v13; // x3

  if ( dest && (unsigned __int64)dest <= 0xFFFFFFFFFFFFF000LL )
  {
    v9 = n;
    v10 = a2;
    if ( (unsigned int)n <= 8 && (a6 & 1) != 0 )
    {
      *dest = 0;
      memcpy(dest, src, (unsigned int)n);
      v12 = (__rbit32(a7 & 0xF) >> 20) & 0xFFFFFFFE | (a7 >> 4) & 1 | 0x110000;
      v10 = *(_DWORD *)dest;
      LODWORD(v13) = *((_DWORD *)dest + 1);
    }
    else
    {
      v13 = HIDWORD(a2);
      v9 &= 0xFFFFFFu;
      *dest = a2;
      v12 = (__rbit32(a7 & 0xF) >> 20) & 0xFFFFFFFE | (a7 >> 4) & 1 | 0x100000;
    }
    *((_DWORD *)dest + 2) = v9;
    *((_DWORD *)dest + 3) = v12;
    ipc_log_string(
      *(_QWORD *)(a5 + 472),
      "dma_tre: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
      v10,
      v13,
      v9,
      v12);
    if ( *(_QWORD *)(a5 + 200) )
      spi_trace_log();
  }
  return dest;
}
