bool __fastcall dbglog_data_txrx_print_handler(__int64 a1, __int64 a2, int a3, unsigned int a4, __int64 a5, _DWORD *a6)
{
  if ( a3 == 1 )
    dbglog_printf(
      a4,
      a2,
      "DATA RX seq=0x%x, len=0x%x, stored=0x%x, duperr=0x%x",
      *a6,
      a6[1],
      HIWORD(a6[2]),
      (unsigned __int16)a6[2]);
  return a3 == 1;
}
