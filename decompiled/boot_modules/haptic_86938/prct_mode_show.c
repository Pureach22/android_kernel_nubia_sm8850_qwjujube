__int64 __fastcall prct_mode_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v3; // x8
  __int64 (__fastcall *v5)(_QWORD); // x9
  unsigned __int8 v6; // w0

  v3 = *(_QWORD *)(a1 + 152);
  v5 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v3 + 1312) + 336LL);
  if ( *((_DWORD *)v5 - 1) != 2018195540 )
    __break(0x8229u);
  v6 = v5(v3 - 168);
  return snprintf(a3, 0x1000u, "prctmode = %d\n", v6);
}
