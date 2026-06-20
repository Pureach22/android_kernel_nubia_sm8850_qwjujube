__int64 __fastcall rdev_set_pmk(__int64 a1)
{
  __int64 (__fastcall *v1)(_QWORD); // x8
  __int64 v2; // x0

  v1 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)a1 + 840LL);
  if ( !v1 )
    return 4294967201LL;
  v2 = a1 + 992;
  if ( *((_DWORD *)v1 - 1) != 299075161 )
    __break(0x8228u);
  return v1(v2);
}
