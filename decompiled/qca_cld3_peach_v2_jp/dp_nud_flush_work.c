_DWORD *__fastcall dp_nud_flush_work(
        _DWORD *result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  _DWORD *v11; // x19

  if ( !result[7] )
  {
    if ( *(_BYTE *)(*(_QWORD *)result + 202LL) )
    {
      v11 = result;
      qdf_trace_msg(0x45u, 5u, "%s: Flush the NUD work", a2, a3, a4, a5, a6, a7, a8, a9, "dp_nud_flush_work", v9, v10);
      return (_DWORD *)cancel_work_sync(v11 + 880);
    }
  }
  return result;
}
