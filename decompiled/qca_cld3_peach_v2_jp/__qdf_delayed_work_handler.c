__int64 __fastcall _qdf_delayed_work_handler(__int64 a1)
{
  __int64 v1; // x0
  __int64 (__fastcall *v2)(_QWORD); // x8

  v2 = *(__int64 (__fastcall **)(_QWORD))(a1 + 104);
  v1 = *(_QWORD *)(a1 + 112);
  if ( *((_DWORD *)v2 - 1) != 251140989 )
    __break(0x8228u);
  return v2(v1);
}
