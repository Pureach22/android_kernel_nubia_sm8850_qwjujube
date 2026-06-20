__int64 __fastcall rdev_get_key(__int64 a1, __int64 a2, __int64 a3, __int64 a4, char a5, __int64 a6, __int64 a7)
{
  __int64 v8; // x0
  __int64 v9; // x4
  __int64 (__fastcall *v10)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64 (__fastcall *)()); // x8

  v8 = a1 + 992;
  v9 = a5 & 1;
  v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64 (__fastcall *)()))(*(_QWORD *)a1 + 72LL);
  if ( *((_DWORD *)v10 - 1) != 2011336107 )
    __break(0x8228u);
  return v10(v8, a2, a3, a4, v9, a6, a7, get_key_callback);
}
