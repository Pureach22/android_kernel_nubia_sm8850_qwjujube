__int64 __fastcall wlan_serialization_get_cmd_from_queue(
        _QWORD *a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *v11; // x1
  unsigned int v12; // w19
  const char *v13; // x2

  if ( !a1 )
  {
    v12 = 16;
    v13 = "%s: input parameters are invalid";
LABEL_8:
    qdf_trace_msg(0x4Cu, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_serialization_get_cmd_from_queue");
    return v12;
  }
  v11 = (_QWORD *)*a2;
  if ( v11 )
  {
    v12 = qdf_list_peek_next(a1, v11, a2);
    if ( !v12 )
      return v12;
    goto LABEL_7;
  }
  v12 = qdf_list_peek_front(a1, a2);
  if ( v12 )
  {
LABEL_7:
    v13 = "%s: can't get next node from queue";
    goto LABEL_8;
  }
  return v12;
}
