__int64 __fastcall dp_nud_failure_work(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x1
  __int64 (__fastcall *v10)(__int64, __int64); // x9
  __int64 v11; // x0

  if ( *(_BYTE *)(a1 + 3480) != 6 )
    return qdf_trace_msg(
             0x45u,
             5u,
             "%s: Not in NUD_FAILED state",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_nud_failure_work");
  v9 = *(_QWORD *)(a1 + 56);
  v10 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)a1 + 696LL);
  v11 = *(_QWORD *)(*(_QWORD *)a1 + 376LL);
  if ( *((_DWORD *)v10 - 1) != 1130147156 )
    __break(0x8229u);
  return v10(v11, v9);
}
