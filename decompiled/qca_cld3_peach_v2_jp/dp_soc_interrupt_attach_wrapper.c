__int64 __fastcall dp_soc_interrupt_attach_wrapper(
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
  const char *v10; // x2
  __int64 v11; // x20
  __int64 (__fastcall *v12)(_QWORD); // x8

  if ( *(_BYTE *)(*(_QWORD *)(a1 + 40) + 545LL) )
    v10 = "%s: Interrupt  mode";
  else
    v10 = "%s: Poll mode";
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 40) + 545LL) )
    v11 = 1800;
  else
    v11 = 1808;
  qdf_trace_msg(0x45u, 5u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "dp_soc_interrupt_attach_wrapper");
  v12 = *(__int64 (__fastcall **)(_QWORD))(a1 + v11);
  if ( *((_DWORD *)v12 - 1) != 504489773 )
    __break(0x8228u);
  return v12(a1);
}
