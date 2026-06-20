__int64 __fastcall lim_init_pre_auth_timer_table(__int64 result, unsigned int *a2)
{
  __int64 v2; // x25
  __int64 v4; // x21
  unsigned __int64 v5; // x19
  unsigned __int64 v6; // x22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8

  if ( *a2 )
  {
    v2 = *((_QWORD *)a2 + 1);
    v4 = result;
    v5 = 0;
    v6 = *(unsigned int *)(*(_QWORD *)(result + 8) + 3484LL) / 0xAuLL;
    while ( 1 )
    {
      result = ((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(), _QWORD, unsigned __int64, _QWORD, _QWORD))tx_timer_create_intern)(
                 v4,
                 *(_QWORD *)(v2 + 8 * v5) + 280LL,
                 "AUTH RESPONSE TIMEOUT",
                 lim_auth_response_timer_handler,
                 (unsigned int)v5,
                 v6,
                 0,
                 0);
      if ( (_DWORD)result )
        break;
      *(_BYTE *)(*(_QWORD *)(v2 + 8 * v5) + 24LL) = v5;
      v15 = *(_QWORD *)(v2 + 8 * v5++);
      *(_BYTE *)(v15 + 278) |= 4u;
      if ( v5 >= *a2 )
        return result;
    }
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Cannot create Auth Rsp timer of Index: %d",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "lim_init_pre_auth_timer_table",
             (unsigned int)v5);
  }
  return result;
}
