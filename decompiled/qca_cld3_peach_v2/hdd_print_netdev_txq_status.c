__int64 __fastcall hdd_print_netdev_txq_status(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  unsigned __int64 v10; // x20
  __int64 v11; // x23

  if ( result )
  {
    v9 = result;
    if ( *(_DWORD *)(result + 1096) )
    {
      v10 = 0;
      v11 = 336;
      do
      {
        result = qdf_trace_msg(
                   0x33u,
                   8u,
                   "%s: netdev tx queue[%u] state:0x%lx",
                   a2,
                   a3,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   "hdd_print_netdev_txq_status",
                   (unsigned int)v10++,
                   *(_QWORD *)(*(_QWORD *)(v9 + 24) + v11));
        v11 += 384;
      }
      while ( v10 < *(unsigned int *)(v9 + 1096) );
    }
  }
  return result;
}
