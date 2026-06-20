__int64 __fastcall cam_spi_read_seq(__int64 a1, int a2, __int64 a3, int a4, int a5)
{
  if ( (unsigned int)(a4 - 5) <= 0xFFFFFFFB )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_spi_read_seq",
      287,
      "Failed with addr_type verification");
    return 4294967274LL;
  }
  if ( !a5 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_spi_read_seq",
      292,
      "num_byte: 0x%x",
      0);
    return 4294967274LL;
  }
  if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000000000LL,
      4,
      "cam_spi_read_seq",
      297,
      "Read Seq addr: 0x%x NB:%d",
      a2,
      a5);
  return cam_spi_tx_helper();
}
