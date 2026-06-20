__int64 __fastcall adreno_sysfs_show_bool(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x0
  __int64 (__fastcall *v4)(_QWORD); // x8
  char v6; // w0

  v3 = *(_QWORD *)(a1 + 152);
  v4 = *(__int64 (__fastcall **)(_QWORD))(a2 + 32);
  if ( *((_DWORD *)v4 - 1) != -1780529452 )
    __break(0x8228u);
  v6 = v4(v3);
  return (int)scnprintf(a3, 4096, "%d\n", v6 & 1);
}
