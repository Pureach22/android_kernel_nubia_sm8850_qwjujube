__int64 __fastcall dp_rx_tm_resume(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w8
  unsigned __int64 v11; // x20
  __int64 v12; // x8
  __int64 v13; // x1

  if ( (*((_DWORD *)a1 + 4) & 0xFFFFFFFE) == 2 )
  {
    v9 = *a1;
    if ( *a1 )
    {
      v11 = 0;
      do
      {
        if ( *(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * v11) )
        {
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: calling thread %d to resume",
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            "dp_rx_tm_resume",
            (unsigned int)v11);
          v12 = *(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * v11);
          *(_QWORD *)(v12 + 424) &= ~4uLL;
          qdf_event_set(*(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * v11) + 96LL, v13);
          v9 = *a1;
        }
        ++v11;
      }
      while ( v11 < v9 );
    }
    *((_DWORD *)a1 + 4) = 1;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: resume callback received w/o suspend! Ignoring.",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dp_rx_tm_resume");
    return 4;
  }
}
