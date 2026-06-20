__int64 __fastcall _os_timer_shim_5(__int64 a1)
{
  __int64 v1; // x0
  __int64 (__fastcall *v2)(_QWORD); // x8

  v2 = *(__int64 (__fastcall **)(_QWORD))(a1 + 40);
  v1 = *(_QWORD *)(a1 + 48);
  if ( *((_DWORD *)v2 - 1) != 251140989 )
    __break(0x8228u);
  return v2(v1);
}
