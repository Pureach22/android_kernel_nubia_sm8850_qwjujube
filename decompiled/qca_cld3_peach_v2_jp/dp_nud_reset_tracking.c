_DWORD *__fastcall dp_nud_reset_tracking(
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
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Reset the NUD tracking",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "dp_nud_reset_tracking",
        v9,
        v10);
      *((_WORD *)v11 + 1758) = 0;
      v11[878] = 0;
      *((_BYTE *)v11 + 3569) = 0;
      result = qdf_mem_set(v11 + 871, 0x1Cu, 0);
      *((_BYTE *)v11 + 3480) = 0;
      v11[877] = 0;
    }
  }
  return result;
}
