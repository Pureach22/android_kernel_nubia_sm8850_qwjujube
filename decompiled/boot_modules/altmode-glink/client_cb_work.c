__int64 __fastcall client_cb_work(__int64 a1)
{
  __int64 (__fastcall *v1)(__int64, __int64, __int64); // x9
  __int64 v2; // x1
  __int64 v3; // x0

  v1 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 32);
  v2 = a1 + 32;
  v3 = *(_QWORD *)(a1 - 40);
  if ( *((_DWORD *)v1 - 1) != -469557113 )
    __break(0x8229u);
  return v1(v3, v2, 16);
}
