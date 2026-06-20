__int64 __fastcall deferred_destroy_0(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 (__fastcall *v3)(_QWORD); // x8

  if ( *(_QWORD *)(a1 - 32) != a1 - 32 )
    __break(0x800u);
  v1 = *(_QWORD *)(a1 + 56);
  v2 = a1 - 40;
  v3 = *(__int64 (__fastcall **)(_QWORD))(v1 + 40);
  if ( *((_DWORD *)v3 - 1) != -1934319042 )
    __break(0x8228u);
  return v3(v2);
}
