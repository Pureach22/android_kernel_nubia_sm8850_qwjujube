_QWORD *__fastcall dp_rx_refill_thread_schedule(
        _QWORD *result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 (*v9)(void); // x8

  if ( result )
  {
    if ( *result )
    {
      v9 = *(__int64 (**)(void))(*(_QWORD *)*result + 624LL);
      if ( v9 )
      {
        if ( *((_DWORD *)v9 - 1) != -1355198606 )
          __break(0x8228u);
        result = (_QWORD *)v9();
        if ( result )
        {
          result[28] |= 2uLL;
          return (_QWORD *)_wake_up(result + 29, 1, 1, 0);
        }
      }
    }
    else
    {
      return (_QWORD *)qdf_trace_msg(
                         0x89u,
                         8u,
                         "%s: Invalid Instance:",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "cdp_soc_get_dp_txrx_handle");
    }
  }
  return result;
}
