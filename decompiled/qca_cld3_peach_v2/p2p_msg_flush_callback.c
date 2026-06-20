__int64 __fastcall p2p_msg_flush_callback(
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
  int v10; // w8
  __int64 v11; // x19

  if ( a1 && *((_QWORD *)a1 + 1) )
  {
    qdf_trace_msg(0x4Eu, 8u, "%s: flush msg, type:%d", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_msg_flush_callback", *a1);
    v10 = *a1;
    v11 = *((_QWORD *)a1 + 1);
    if ( v10 == 2 )
      _qdf_mem_free(*(_QWORD *)(v11 + 48));
    _qdf_mem_free(v11);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: invalid msg", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_msg_flush_callback");
    return 4;
  }
}
