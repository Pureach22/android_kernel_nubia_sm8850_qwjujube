__int64 __fastcall rdev_get_antenna(__int64 a1)
{
  __int64 v2; // x0
  __int64 (__fastcall *v3)(_QWORD); // x8

  v2 = a1 + 992;
  v3 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)a1 + 584LL);
  if ( *((_DWORD *)v3 - 1) != -702805087 )
    __break(0x8228u);
  return v3(v2);
}
