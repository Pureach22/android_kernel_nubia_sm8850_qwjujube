__int64 __fastcall scheduler_post_message_debug(
        unsigned int a1,
        unsigned int a2,
        int a3,
        unsigned __int16 *a4,
        unsigned int a5,
        __int64 a6)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w23

  result = scheduler_post_msg_by_priority(a3 | (a1 << 20) | (a2 << 10), a4, 0);
  if ( (_DWORD)result )
  {
    v19 = result;
    qdf_trace_msg(
      0x4Au,
      2u,
      "%s: couldn't post from %d to %d - called from %d, %s",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "scheduler_post_message_debug",
      a1,
      a2,
      a5,
      a6);
    return v19;
  }
  return result;
}
