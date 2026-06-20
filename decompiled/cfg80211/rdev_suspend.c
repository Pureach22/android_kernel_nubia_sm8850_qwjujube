__int64 __fastcall rdev_suspend(__int64 (__fastcall ***a1)(_QWORD))
{
  __int64 (__fastcall ***v2)(_QWORD); // x0
  __int64 (__fastcall *v3)(_QWORD); // x8

  v2 = a1 + 124;
  v3 = **a1;
  if ( *((_DWORD *)v3 - 1) != -858810588 )
    __break(0x8228u);
  return v3(v2);
}
