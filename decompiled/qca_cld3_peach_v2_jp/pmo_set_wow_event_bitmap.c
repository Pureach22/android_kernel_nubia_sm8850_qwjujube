__int64 __fastcall pmo_set_wow_event_bitmap(
        __int64 result,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 v13; // x8
  unsigned int v14; // w9

  if ( a2 < 4 || !a3 )
    return qdf_trace_msg(
             0x4Du,
             2u,
             "%s: wow bitmask length shorter than %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "pmo_set_wow_event_bitmap",
             4,
             v11,
             v12);
  if ( (_DWORD)result )
  {
    v13 = (unsigned int)result / (8 * a2);
    v14 = (unsigned int)result % (8 * a2);
  }
  else
  {
    LOBYTE(v14) = 0;
    v13 = 0;
  }
  *(_DWORD *)(a3 + 4 * v13) |= 1 << v14;
  return result;
}
