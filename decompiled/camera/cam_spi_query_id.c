__int64 __fastcall cam_spi_query_id(__int64 a1, int a2, int a3, void *a4, unsigned int a5)
{
  __int64 v9; // x22
  void *v10; // x23

  if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
  {
    v9 = a1;
    v10 = a4;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000000000LL,
      4,
      "cam_spi_query_id",
      308,
      "SPI Queryid : 0x%x, addr: 0x%x",
      *(_DWORD *)(*(_QWORD *)(a1 + 24) + 18LL),
      a2);
    a1 = v9;
    a4 = v10;
  }
  return cam_spi_tx_helper(a1, (_BYTE *)(*(_QWORD *)(a1 + 24) + 18LL), a2, a4, a3, a5);
}
