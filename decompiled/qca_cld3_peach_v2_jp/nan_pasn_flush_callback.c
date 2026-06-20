__int64 __fastcall nan_pasn_flush_callback(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( a1 && *((_QWORD *)a1 + 1) )
  {
    if ( *a1 < 3u )
    {
      _qdf_mem_free(*((_QWORD *)a1 + 1));
      return 0;
    }
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Unsupported request type: %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "nan_pasn_flush_callback");
    _qdf_mem_free(*((_QWORD *)a1 + 1));
  }
  else
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Null pointer for NAN Discovery message",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "nan_pasn_flush_callback");
  }
  return 4;
}
