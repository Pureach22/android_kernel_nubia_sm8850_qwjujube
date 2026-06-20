__int64 __fastcall lim_wpspbc_close(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  _QWORD *v10; // x19
  _QWORD *v11; // x23
  __int64 result; // x0

  v10 = *(_QWORD **)(a10 + 1944);
  if ( v10 )
  {
    do
    {
      v11 = (_QWORD *)*v10;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: WPS PBC sessions remove",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "lim_remove_timeout_pbc_sessions");
      ((void (__fastcall *)(__int64, __int64, _QWORD *, __int64))qdf_trace_hex_dump)(53, 8, v10 + 1, 6);
      ((void (__fastcall *)(__int64, __int64, char *, __int64))qdf_trace_hex_dump)(53, 8, (char *)v10 + 14, 16);
      result = _qdf_mem_free((__int64)v10);
      v10 = v11;
    }
    while ( v11 );
  }
  return result;
}
