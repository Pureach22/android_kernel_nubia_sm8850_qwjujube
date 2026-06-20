__int64 __fastcall dispatcher_sysfs_show(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v2)(_QWORD); // x8
  __int64 v3; // x0

  v2 = *(__int64 (__fastcall **)(_QWORD))(a2 + 16);
  if ( !v2 )
    return -5;
  v3 = a1 - 400;
  if ( *((_DWORD *)v2 - 1) != 1126239000 )
    __break(0x8228u);
  return v2(v3);
}
