__int64 __fastcall _qdf_defer_func(__int64 a1)
{
  __int64 (__fastcall *v1)(_QWORD); // x8
  __int64 v2; // x0

  v1 = *(__int64 (__fastcall **)(_QWORD))(a1 + 32);
  if ( !v1 )
    return qdf_trace_msg(56, 2, "No callback registered !!");
  v2 = *(_QWORD *)(a1 + 40);
  if ( *((_DWORD *)v1 - 1) != 251140989 )
    __break(0x8228u);
  return v1(v2);
}
