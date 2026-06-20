__int64 __fastcall rdev_set_rekey_data(__int64 a1)
{
  __int64 v2; // x0
  __int64 (__fastcall *v3)(_QWORD); // x8

  v2 = a1 + 992;
  v3 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)a1 + 608LL);
  if ( *((_DWORD *)v3 - 1) != -118481638 )
    __break(0x8228u);
  return v3(v2);
}
