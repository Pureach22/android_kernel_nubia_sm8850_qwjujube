__int64 __fastcall rdev_add_key(__int64 a1, __int64 a2, __int64 a3, __int64 a4, char a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x7
  __int64 v9; // x0
  __int64 v10; // x4
  __int64 (__fastcall *v11)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // x8

  v7 = *(unsigned int *)(a7 + 32);
  v9 = a1 + 992;
  v10 = a5 & 1;
  v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(*(_QWORD *)a1 + 64LL);
  if ( *((_DWORD *)v11 - 1) != 270112075 )
    __break(0x8228u);
  return v11(v9, a2, a3, a4, v10, a6, a7, v7);
}
