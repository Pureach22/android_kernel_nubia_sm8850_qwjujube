__int64 __fastcall dp_rx_desc_pool_is_allocated(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w19

  if ( *((_WORD *)a1 + 5) )
  {
    return 0;
  }
  else
  {
    v9 = 2;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Multi page alloc fail, size=%d, elem=%d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dp_rx_desc_pool_is_allocated",
      *((unsigned __int16 *)a1 + 2),
      *a1);
  }
  return v9;
}
