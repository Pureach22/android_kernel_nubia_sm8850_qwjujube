__int64 __fastcall pe_find_session_by_session_id(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( *(unsigned __int16 *)(a1 + 3992) <= (unsigned int)a2 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid sessionId: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "pe_find_session_by_session_id",
      v10,
      v11);
    return 0;
  }
  else if ( *(_BYTE *)(*(_QWORD *)(a1 + 12264) + 10792LL * a2 + 70) )
  {
    return *(_QWORD *)(a1 + 12264) + 10792LL * a2;
  }
  else
  {
    return 0;
  }
}
