__int64 __fastcall kgsl_get_fence_name(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x22
  __int64 (*v7)(void); // x8
  const char *v8; // x23
  __int64 (__fastcall *v9)(_QWORD); // x8
  const char *v10; // x0
  __int64 result; // x0
  int v12; // w9
  _DWORD *v13; // x8

  v6 = a3;
  v7 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 8) + 8LL);
  if ( *((_DWORD *)v7 - 1) != -352706110 )
    __break(0x8228u);
  v8 = (const char *)v7();
  v9 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 16LL);
  if ( *((_DWORD *)v9 - 1) != -352706110 )
    __break(0x8228u);
  v10 = (const char *)v9(a1);
  result = scnprintf(a2, v6, "%s %s", v8, v10);
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 8) + 56LL) )
  {
    v12 = scnprintf(a2 + (int)result, a3 - (unsigned int)result, ": ") + result;
    v13 = *(_DWORD **)(*(_QWORD *)(a1 + 8) + 56LL);
    if ( *(v13 - 1) != -938580849 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v13)(a1, a2 + v12, a3 - v12);
  }
  return result;
}
