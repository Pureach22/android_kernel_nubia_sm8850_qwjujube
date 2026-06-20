__int64 __fastcall p2p_event_flush_callback(
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
  __int64 v13; // x0

  if ( !a1 || !*((_QWORD *)a1 + 1) )
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: invalid msg", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_event_flush_callback");
    return 4;
  }
  qdf_trace_msg(0x4Eu, 8u, "%s: flush event, type:%d", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_event_flush_callback", *a1);
  v10 = *a1;
  v11 = *((_QWORD *)a1 + 1);
  if ( v10 > 2 )
  {
    if ( v10 != 3 && v10 != 4 )
      goto LABEL_13;
    goto LABEL_10;
  }
  if ( v10 == 1 )
  {
    v13 = *(_QWORD *)(v11 + 8);
    if ( v13 )
      _qdf_nbuf_free(v13);
    goto LABEL_13;
  }
  if ( v10 == 2 )
LABEL_10:
    _qdf_mem_free(*(_QWORD *)(v11 + 8));
LABEL_13:
  _qdf_mem_free(v11);
  return 0;
}
