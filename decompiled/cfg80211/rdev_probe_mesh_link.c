__int64 __fastcall rdev_probe_mesh_link(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x0
  __int64 (__fastcall *v7)(__int64, __int64, __int64, __int64); // x10

  v6 = a1 + 992;
  v7 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)a1 + 904LL);
  if ( *((_DWORD *)v7 - 1) != 836349774 )
    __break(0x822Au);
  return v7(v6, a2, a4, a5);
}
