__int64 __fastcall cont_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v3; // x20
  void (__fastcall *v5)(_QWORD); // x8

  v3 = *(_QWORD *)(a1 + 152);
  v5 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v3 + 1312) + 16LL);
  if ( *((_DWORD *)v5 - 1) != 1361900016 )
    __break(0x8228u);
  v5(v3 - 168);
  return snprintf(a3, 0x1000u, "cont_f0 = %d\n", *(_DWORD *)(v3 - 56));
}
