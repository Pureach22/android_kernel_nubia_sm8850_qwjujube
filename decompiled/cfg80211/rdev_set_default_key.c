__int64 __fastcall rdev_set_default_key(__int64 a1, __int64 a2, __int64 a3, __int64 a4, char a5, char a6)
{
  __int64 v7; // x0
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 (__fastcall *v10)(__int64, __int64, __int64, __int64, __int64, __int64); // x8

  v7 = a1 + 992;
  v8 = a5 & 1;
  v9 = a6 & 1;
  v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))(*(_QWORD *)a1 + 88LL);
  if ( *((_DWORD *)v10 - 1) != -1768624129 )
    __break(0x8228u);
  return v10(v7, a2, a3, a4, v8, v9);
}
